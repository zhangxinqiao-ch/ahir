-------------------------------------------------------------------------------
-- generic ap-int (signed/unsigned operator)
-- modified by Madhav Desai.
-------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library ahir;
use ahir.Subprograms.all;
use ahir.BaseComponents.all;


entity GenericApIntArithOperator is
  generic (op_id: string;
	    tag_width : integer := 8;
	    in_operand_width: integer;
	    num_non_constant_inputs: integer;
            first_operand_is_constant: boolean;
            second_operand_is_constant: boolean;
	    constant_value: std_logic_vector;
	    out_result_width: integer;
           );
  port(
    in_data: in std_logic_vector((num_inputs*in_operand_width)-1 downto 0);
    out_data: out std_logic_vector(out_result_widht-1 downto 0);
    clk,reset: in std_logic;
    tag_in: in std_logic_vector(tag_width-1 downto 0);
    tag_out: out std_logic_vector(tag_width-1 downto 0);
    env_rdy, accept_rdy: in std_logic;
    op_i_rdy, op_o_rdy: out std_logic);
end entity;

architecture rtl of GenericApIntArithOperator is

  signal pipeline_stall : std_logic;
  signal op_o_rdy_sig: std_logic;

begin

  pipeline_stall <= op_o_rdy_sig and (not accept_rdy);
  op_o_rdy <= op_o_rdy_sig;
  op_i_rdy <= (not pipeline_stall);


  -- binary operator.
  arithOp: if ( (op_id = "ApIntAdd") or
		(op_id = "ApIntSub") or
		(op_id = "ApIntMul") or
		(op_id = "ApIntSHL") or
		(op_id = "ApIntLSHR") or
		(op_id = "ApIntLASHR") or
		(op_id = "ApIntROL") or
		(op_id = "ApIntROR"))  generate
       gBlk: block
	signal inA, inB: std_logic_vector(in_operand_width-1 downto 0);
	signal outR: std_logic_vector(out_operand_width-1 downto 0);
       begin
	     firstConstant: if (first_operand_is_constant) generate
	    	inA <= constant_operand;
	     end generate firstConstant;

	     notfirstConstant: if (not first_operand_is_constant) generate
	    	inA <= in_data((2*in_operand_width)-1 downto in_operand_width);
	     end generate notfirstConstant;
	
	     secondConstant: if (second_operand_is_constant) generate
	    	inB <= constant_operand;
	     end generate secondConstant;

	     notsecondConstant: if (not second_operand_is_constant) generate
	    	inB <= in_data(in_operand_width-1 downto 0);
             end generate secondConstant;

	     oprtr: GenericBinaryApIntArithOperatorPipelined
			generic map(op_id => op_id)
			port map (inA => inA, inB => inB, outR => outR,
					pipeline_stall => pipeline_stall,
					tag_in => tag_in, tag_out => tag_out,
					env_rdy => env_rdy,
					env_accept => env_accept,
					clk => clk, reset => reset);
       end block gBlk;
  end generate arithOp;

  notArithOp:if ( (op_id /= "ApIntAdd") and
		(op_id /= "ApIntSub") and
		(op_id /= "ApIntMul") and
		(op_id /= "ApIntSHL") and
		(op_id /= "ApIntLSHR") and
		(op_id /= "ApIntLASHR") and
		(op_id /= "ApIntROL") and
		(op_id /= "ApIntROR"))  generate

 	assert false report op_id & " is not a binary arith operation" severity failure;

  end generate notArithOp;
end rtl;
