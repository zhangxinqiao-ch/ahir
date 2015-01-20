#include <AaType.h>
#include <AaValue.h>
#include <AaExpression.h>
#include <Aa2C.h>

void Print_C_Declaration(string obj_name, AaType* obj_type, ofstream& ofile)
{
}
void Print_C_Assignment_To_Constant(string tgt_c_ref, AaType* tgt_type, AaValue* v, ofstream& ofile)
{
}
void Print_C_Assignment(string tgt, string src, AaType* t, ofstream& ofile)
{
}
void Print_C_Value_Expression(string cref, AaType* t, ofstream& ofile)
{
}

void Print_C_Pipe_Read(string tgt, AaType* tgt_type, AaPipeObject* p, ofstream& ofile)
{
}
void Print_C_Pipe_Write(string src, AaType* src_type, AaPipeObject* p, ofstream& ofile)
{
}
void Print_C_Type_Cast_Operation(string src, AaType* src_type, string tgt, AaType* tgt_type, ofstream& ofile)
{
}
void Print_C_Unary_Operation(string src, AaType* src_type, string tgt, AaType* tgt_type, AaOperation op, ofstream& ofile)
{
}
void Print_C_Binary_Operation(string src1, AaType* src1_type, string src2,  AaType* src2_type, 
			string tgt, AaType* tgt_type, AaOperation Op, ofstream& ofile)
{
}
void Print_C_Ternary_Operation(string test,
			AaType* test_type, string if_expr,
			AaType* if_expr_type, 
			string else_expr, AaType* else_expr_type, 
			string tgt, AaType* tgt_type, ofstream& ofile)
{
}
void Print_C_Slice_Operation(string src, AaType* src_type, int _low_index, string tgt,
				AaType* tgt_type, ofstream& ofile)
{
}

