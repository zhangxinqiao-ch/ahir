------------------------------------------------------------------------------------------------
--
-- Copyright (C) 2010-: Madhav P. Desai
-- All Rights Reserved.
--  
-- Permission is hereby granted, free of charge, to any person obtaining a
-- copy of this software and associated documentation files (the
-- "Software"), to deal with the Software without restriction, including
-- without limitation the rights to use, copy, modify, merge, publish,
-- distribute, sublicense, and/or sell copies of the Software, and to
-- permit persons to whom the Software is furnished to do so, subject to
-- the following conditions:
-- 
--  * Redistributions of source code must retain the above copyright
--    notice, this list of conditions and the following disclaimers.
--  * Redistributions in binary form must reproduce the above
--    copyright notice, this list of conditions and the following
--    disclaimers in the documentation and/or other materials provided
--    with the distribution.
--  * Neither the names of the AHIR Team, the Indian Institute of
--    Technology Bombay, nor the names of its contributors may be used
--    to endorse or promote products derived from this Software
--    without specific prior written permission.
--
-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
-- OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
-- MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
-- IN NO EVENT SHALL THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR
-- ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
-- TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
-- SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE SOFTWARE.
------------------------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
library ahir;
use ahir.Types.all;
use ahir.Utilities.all;
use ahir.Subprograms.all;

entity BypassRegister  is
	generic (data_width: integer; bypass: boolean);
	port (clk: in std_logic; enable: in boolean; 
			din: in std_logic_vector(data_width-1 downto 0);
			q: out std_logic_vector(data_width-1 downto 0));
end entity;

architecture Behaveee of  BypassRegister is
   signal din_reg: std_logic_vector(data_width-1 downto 0);
begin
	process(clk, enable)
	begin
		if(clk'event and clk = '1') then
			if enable then
				din_reg <= din;
			end if;
		end if;
	end process;
   ifByp: if bypass generate
	q <= din when enable else din_reg;
   end generate ifByp;
   ifNoByp: if not bypass generate
	q <= din_reg;
   end generate ifNoByp;
end Behaveee;
