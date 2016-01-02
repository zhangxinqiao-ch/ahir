#include <istream>
#include <ostream>
#include <assert.h>
#include <hierSystem.h>
#include <rtlEnums.h>
#include <rtlType.h>
#include <Value.hpp>
#include <rtlValue.h>
#include <rtlObject.h>
#include <rtlStatement.h>
#include <rtlThread.h>

void rtlThread::Print_Vhdl_Port_Declarations(ostream& ofile)
{
	ofile << "port (-- { " << endl;
	for(map<string,rtlObject*>::iterator iter = _objects.begin(), fiter = _objects.end(); iter != fiter; iter++)
	{
		rtlObject* obj = (*iter).second;
		if(obj->Is_InPort())
		{
			if(obj->Is_Pipe())
			{
				ofile << obj->Get_Id() << ": in std_logic_vector("
						<< (obj->Get_Type()->Size()-1) << " downto 0);" << endl;
				ofile << obj->Get_Id() << "_pipe_read_req: out std_logic_vector(0 downto 0);" << endl;
				ofile << obj->Get_Id() << "_pipe_read_ack: in std_logic_vector(0 downto 0);" << endl;
			}
			else
			{
				ofile << obj->Get_Id() << ": in std_logic_vector("
						<< (obj->Get_Type()->Size()-1) << " downto 0);" << endl;
			}
		}
		else if(obj->Is_OutPort())
		{
			if(obj->Is_Pipe())
			{
				ofile << obj->Get_Id() << ": out std_logic_vector("
						<< (obj->Get_Type()->Size()-1) << " downto 0);" << endl;
				ofile << obj->Get_Id() << "_pipe_write_req: out std_logic_vector(0 downto 0);" << endl;
				ofile << obj->Get_Id() << "_pipe_write_ack: in std_logic_vector(0 downto 0);" << endl;
			}
			else
			{
				ofile << obj->Get_Id() << ": out std_logic_vector("
						<< (obj->Get_Type()->Size()-1) << " downto 0);" << endl;
			}
		}
	}	
	ofile << "clk, reset: in std_logic); --} " << endl;
}


void rtlThread::Print_Vhdl_Object_Declarations(bool signal_flag, bool constant_flag, bool variable_flag, ostream& ofile)
{
	for(map<string,rtlObject*>::iterator iter = _objects.begin(), fiter = _objects.end(); iter != fiter; iter++)
	{
		rtlObject* obj = (*iter).second;
		if(signal_flag && obj->Is_Signal()  && !obj->Is_InPort() && !obj->Is_OutPort())
		{
				ofile << "signal " <<  obj->Get_Id() << ": " 
						<< Get_Type_Identifier(obj->Get_Type()) << ";" << endl;
		}
		else if(constant_flag && obj->Is_Constant())
		{
			ofile << "constant " <<  obj->Get_Id() << ": " 
						<< Get_Type_Identifier(obj->Get_Type()) << " := "
						<< obj->Get_Value()->To_Vhdl_String() << ";" << endl;
		
		}
		else if(variable_flag && (obj->Is_Variable() || obj->Needs_Next_Vhdl_Variable()))
		{
			string var_name = obj->Get_Variable_Id();
			ofile << "variable " <<  var_name << ": " 
						<< Get_Type_Identifier(obj->Get_Type()) << ";" << endl;
		
		}
	}
}

void rtlThread::Print_Vhdl_Component(ostream& ofile)
{
	ofile << "component " << this->Get_Id() << " is  -- {" << endl;
	this->Print_Vhdl_Port_Declarations(ofile);
	ofile << "--} " << endl << "end component;" << endl;
}

void rtlThread::Print_Vhdl_Entity_Architecture(ostream& ofile, int map_all_libs_to_work)
{
	//
	// TODO: print library, use clauses
	//       (dont forget the types package for this system).
	//       	
	//
	this->Get_Parent()->Print_Vhdl_Inclusions(ofile, map_all_libs_to_work);

	ofile << "entity " << this->Get_Id() << " is  -- {" << endl;
	this->Print_Vhdl_Port_Declarations(ofile);
	ofile << "--} " << endl << "end entity " << this->Get_Id() << ";"  << endl;

	ofile << "architecture rtlThreadArch of " << this->Get_Id() << " is --{" << endl;
	ofile << "type ThreadState is (";
	for(int I = 0, fI = _statements.size(); I < fI; I++)
	{
		if(I > 0)
			ofile << ", ";
		ofile << "s_" << _statements[I]->Get_Label();
	}	
	ofile << ");" << endl;
	ofile << "signal current_thread_state : ThreadState;" << endl;
	// print all signal declarations.
	this->Print_Vhdl_Object_Declarations(true, true, false, ofile);
	ofile << "--} " << endl;
	ofile << "begin -- { " << endl;
	ofile << "process(clk, reset, current_thread_state ";
	for(map<string,rtlObject*>::iterator iter = _objects.begin(), fiter = _objects.end(); iter != fiter; iter++)
	{
		rtlObject* obj = (*iter).second;
		if(obj->Is_Signal() && !obj->Is_OutPort())
		{
			ofile <<  ", " << obj->Get_Id();
		}
		if(obj->Is_OutPort() && obj->Is_Pipe())
			ofile << ", " << obj->Get_Id() << "_pipe_write_ack";	
		if(obj->Is_InPort() && obj->Is_Pipe())
			ofile << ", " << obj->Get_Id() << "_pipe_read_ack";	
	}
	ofile << ") --{" << endl;
	ofile << "-- declared variables and implied variables " << endl;
	this->Print_Vhdl_Object_Declarations(false, false, true, ofile);
	ofile << "variable next_thread_state : ThreadState;" << endl;
	ofile << "--} " << endl;
	ofile << "begin -- {" << endl;
	ofile << " -- default values " << endl;
	ofile << " next_thread_state := current_thread_state;" << endl;
	for(int I = 0, fI = _default_statements.size(); I < fI; I++)
	{
		_default_statements[I]->Print_Vhdl(ofile);
	}

	for(map<string,rtlObject*>::iterator iter = _objects.begin(), fiter = _objects.end(); iter != fiter; iter++)
	{
		rtlObject* obj = (*iter).second;
		if(obj->Needs_Next_Vhdl_Variable() && !obj->Is_OutPort())
		{
			ofile << obj->Get_Variable_Id() << " := " << obj->Get_Id() << ";" << endl;
		}
	}

	ofile << " -- case statement " << endl;
	ofile << " case current_thread_state is -- {" << endl; 
	for(int I = 0, fI = _statements.size(); I < fI; I++)
	{
		ofile << "when s_" << _statements[I]->Get_Label() << " => -- {" << endl;
		string def_next_label = "s_" + ((I < (fI-1)) ? _statements[I+1]->Get_Label() : _statements[I]->Get_Label());
		ofile << "next_thread_state := " << def_next_label << ";" << endl;
		_statements[I]->Print_Vhdl(ofile);
		ofile << "--}" << endl;
	}
	ofile << " --}" << endl;
	ofile << " end case;" << endl;

	if(_immediate_statements.size() > 0)
		ofile << " -- immediate assignments " << endl;
	for(int I = 0, fI = _immediate_statements.size(); I < fI; I++)
	{
		_immediate_statements[I]->Print_Vhdl(ofile);
	}

	ofile << " if (clk'event and clk = '1') then -- {" << endl;
	ofile << " if (reset = '1') then -- {" << endl;
	ofile << " current_thread_state <= s_" << _statements[0]->Get_Label() << ";" << endl;
	ofile << "-- }" << endl;
	ofile << " else -- {" << endl;
	ofile << " current_thread_state <= next_thread_state; " << endl;
	ofile << " -- objects to be updated under tick." << endl;
	for(map<string,rtlObject*>::iterator iter = _objects.begin(), fiter = _objects.end(); iter != fiter; iter++)
	{
		rtlObject* obj = (*iter).second;
		if(obj->Needs_Next_Vhdl_Variable())
		{
			ofile << obj->Get_Id() << " <= " << obj->Get_Variable_Id() << ";" << endl;
		}
	}
	ofile << " -- specified tick assignments. " << endl;
	for(int I = 0, fI = _tick_statements.size(); I < fI; I++)
	{
		_tick_statements[I]->Print_Vhdl(ofile);
	}
	ofile << "-- }" << endl;
	ofile << " end if; " << endl;
	ofile << "-- }" << endl;
	ofile << " end if; " << endl;
	ofile << "--} " << endl;
	ofile << "end process; " << endl;
	ofile << "--}" << endl;
	ofile << "end rtlThreadArch;" << endl;
}


void rtlString::Print_Vhdl_Instance(ostream& ofile)
{
	ofile << this->Get_Id() << ": " << this->Get_Base_Thread()->Get_Id () << " -- {" << endl;
	hierSystem* base_sys = this->Get_Base_Thread()->Get_Parent();

	ofile << "port map ( -- {" << endl;
	for(map<string, string>::iterator iter = _formal_to_actual_map.begin(), fiter = _formal_to_actual_map.end();
			iter != fiter; iter++)
	{
		rtlObject* formal_obj = this->Get_Base_Thread()->Find_Object((*iter).first);
		if(formal_obj == NULL)
		{
			this->Report_Error("in string " + this->Get_Id() + ", did not find object " + (*iter).second);
			return;
		}
		string pipe_name      = (*iter).second;	
		if(formal_obj->Is_InPort())
		{
			if(((rtlInPort*)formal_obj)->Is_Pipe())
			{
				ofile << formal_obj->Get_Id() << " => " 
						<< base_sys->Get_Pipe_Vhdl_Read_Data_Name(pipe_name) << "," << endl;
				ofile << formal_obj->Get_Id() << "_pipe_read_req => " 
						<< base_sys->Get_Pipe_Vhdl_Read_Req_Name(pipe_name) << "," << endl;
				ofile << formal_obj->Get_Id() << "_pipe_read_ack => " 
						<< base_sys->Get_Pipe_Vhdl_Read_Ack_Name(pipe_name) << "," << endl;
			}
			else
			{
				ofile << formal_obj->Get_Id() << " => " << pipe_name << "," << endl;
			}
		}
		else if(formal_obj->Is_OutPort())
		{
			if(((rtlInPort*)formal_obj)->Is_Pipe())
			{
				ofile << formal_obj->Get_Id() << " => " 
						<< base_sys->Get_Pipe_Vhdl_Write_Data_Name(pipe_name) << "," << endl;
				ofile << formal_obj->Get_Id() << "_pipe_write_req => " 
						<< base_sys->Get_Pipe_Vhdl_Write_Req_Name(pipe_name) << "," << endl;
				ofile << formal_obj->Get_Id() << "_pipe_write_ack => " 
						<< base_sys->Get_Pipe_Vhdl_Write_Ack_Name(pipe_name) << "," << endl;

			}
			else
			{
				ofile << formal_obj->Get_Id() << " => " << pipe_name << "," << endl;
			}
		}
	}
	ofile << "clk => clk, reset => reset";
	ofile << "--} " << endl;
	ofile << "); -- }" << endl;
}
