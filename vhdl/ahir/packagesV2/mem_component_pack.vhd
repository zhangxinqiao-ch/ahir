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

package mem_component_pack is
component mem_demux 
  generic ( name: string;
	    g_data_width: natural;
            g_id_width : natural;
            g_number_of_outputs: natural;
	    g_delay_count: natural);
  port(data_in: in std_logic_vector(g_data_width-1 downto 0);  -- data & id & time-stamp
       sel_in : in std_logic_vector(g_id_width-1 downto 0);
       req_in: in std_logic;
       ack_out : out std_logic;
       data_out: out std_logic_vector((g_number_of_outputs*g_data_width)-1 downto 0 );
       req_out: out std_logic_vector(g_number_of_outputs-1 downto 0);
       ack_in : in std_logic_vector(g_number_of_outputs-1 downto 0);
       clk: in std_logic;
       reset: in std_logic);
end component;

component mem_repeater 
    generic(name: string;
	    g_data_width: natural);
    port(clk: in std_logic;
       reset: in std_logic;
       data_in: in std_logic_vector(g_data_width-1 downto 0);
       req_in: in std_logic;
       ack_out : out std_logic;
       data_out: out std_logic_vector(g_data_width-1 downto 0);
       req_out : out std_logic;
       ack_in: in std_logic);
end component mem_repeater;

component mem_shift_repeater
    generic(name: string;
	    g_data_width: natural; g_number_of_stages: natural);
    port(clk: in std_logic;
       reset: in std_logic;
       data_in: in std_logic_vector(g_data_width-1 downto 0);
       req_in: in std_logic;
       ack_out : out std_logic;
       data_out: out std_logic_vector(g_data_width-1 downto 0);
       req_out : out std_logic;
       ack_in: in std_logic);
end component mem_shift_repeater;


component memory_bank 
   generic (
     name: string;
     g_addr_width: natural;
     g_data_width: natural;
     g_write_tag_width : natural;
     g_read_tag_width : natural;
     g_time_stamp_width: natural;
     g_base_bank_addr_width: natural;
     g_base_bank_data_width: natural
	);
   port (
     clk : in std_logic;
     reset: in std_logic;
     write_data     : in  std_logic_vector(g_data_width-1 downto 0);
     write_addr     : in std_logic_vector(g_addr_width-1 downto 0);
     write_tag      : in std_logic_vector(g_write_tag_width-1 downto 0);
     write_tag_out  : out std_logic_vector(g_write_tag_width-1 downto 0);
     write_enable   : in std_logic;
     write_ack   : out std_logic;
     write_result_accept : in std_logic;
     write_result_ready : out std_logic;
     read_data     : out  std_logic_vector(g_data_width-1 downto 0);
     read_addr     : in std_logic_vector(g_addr_width-1 downto 0);
     read_tag      : in std_logic_vector(g_read_tag_width-1 downto 0);
     read_tag_out  : out std_logic_vector(g_read_tag_width-1 downto 0);
     read_enable   : in std_logic;
     read_ack      : out std_logic;
     read_result_accept: in std_logic;
     read_result_ready: out std_logic
     );
end component memory_bank;

component memory_bank_base 
   generic ( name: string;
	g_addr_width: natural; 
	g_data_width : natural;
        g_base_bank_addr_width: natural;
        g_base_bank_data_width: natural);
   port (data_in : in std_logic_vector(g_data_width-1 downto 0);
         data_out: out std_logic_vector(g_data_width-1 downto 0);
         addr_in: in std_logic_vector(g_addr_width-1 downto 0);
         enable: in std_logic;
         write_bar : in std_logic;
         clk: in std_logic;
         reset : in std_logic
	);
end component memory_bank_base;

component base_bank 
   generic ( name: string;
	g_addr_width: natural; g_data_width : natural);
   port (datain : in std_logic_vector(g_data_width-1 downto 0);
         dataout: out std_logic_vector(g_data_width-1 downto 0);
         addrin: in std_logic_vector(g_addr_width-1 downto 0);
         enable: in std_logic;
         writebar : in std_logic;
         clk: in std_logic;
         reset : in std_logic);
end component base_bank;

component base_bank_dual_port is
   generic ( name: string; g_addr_width: natural := 10; g_data_width : natural := 16);
   port (
	 datain_0 : in std_logic_vector(g_data_width-1 downto 0);
         dataout_0: out std_logic_vector(g_data_width-1 downto 0);
         addrin_0: in std_logic_vector(g_addr_width-1 downto 0);
         enable_0: in std_logic;
         writebar_0 : in std_logic;
	 datain_1 : in std_logic_vector(g_data_width-1 downto 0);
         dataout_1: out std_logic_vector(g_data_width-1 downto 0);
         addrin_1: in std_logic_vector(g_addr_width-1 downto 0);
         enable_1: in std_logic;
         writebar_1 : in std_logic;
         clk: in std_logic;
         reset : in std_logic);
end component base_bank_dual_port;


component merge_box_with_repeater 
  generic (name: string;
	   g_data_width: natural;
           g_number_of_inputs: natural;
           g_number_of_outputs: natural;
           g_time_stamp_width : natural;   -- width of timestamp
           g_tag_width : natural;  -- width of tag
           g_pipeline_flag: integer     -- if 0, dont add pipe-line stage
           );            

  port(data_left: in  std_logic_vector((g_data_width*g_number_of_inputs)-1 downto 0);
       req_in : in std_logic_vector(g_number_of_inputs-1 downto 0);
       ack_out : out std_logic_vector(g_number_of_inputs-1 downto 0);
       data_right: out std_logic_vector((g_data_width*g_number_of_outputs)-1 downto 0);
       req_out : out std_logic_vector(g_number_of_outputs-1 downto 0);
       ack_in : in std_logic_vector(g_number_of_outputs-1 downto 0);
       clock: in std_logic;
       reset: in std_logic);

end component merge_box_with_repeater;


component merge_tree 
  generic (
    name: string;
    g_number_of_inputs: natural;          
    g_data_width: natural;          -- total width of data
                                          -- (= actual-data & timestamp)
    g_time_stamp_width : natural;   -- width of timestamp
    g_tag_width : natural;          -- width of tag
    g_mux_degree :natural;         -- max-indegree of each pipeline-stage
    g_num_stages : natural;
    g_port_id_width: natural
    );       

  port (
    merge_data_in : in std_logic_vector((g_data_width*g_number_of_inputs)-1 downto 0);
    merge_req_in  : in std_logic_vector(g_number_of_inputs-1 downto 0);
    merge_ack_out : out std_logic_vector(g_number_of_inputs-1 downto 0);
    merge_data_out: out std_logic_vector(g_data_width-1 downto 0);
    merge_req_out : out std_logic;
    merge_ack_in  : in std_logic;
    clock: in std_logic;
    reset: in std_logic);
  
end component merge_tree;

component demerge_tree 
  
  generic (
     name: string;
    g_demux_degree: natural;
    g_number_of_outputs: natural;
    g_data_width: natural;              -- total width of data
                                        -- (= data & tag & port-id & timestamp)
    g_id_width: natural;
    g_stage_id: natural
    );       

  port (
    demerge_data_out : out std_logic_vector((g_data_width*g_number_of_outputs)-1 downto 0);
    demerge_ready_out  : out std_logic_vector(g_number_of_outputs-1 downto 0);
    demerge_accept_in   : in std_logic_vector(g_number_of_outputs-1 downto 0);
    demerge_data_in: in std_logic_vector(g_data_width-1 downto 0);
    demerge_ack_out : out std_logic;
    demerge_req_in  : in std_logic;
    demerge_sel_in: in std_logic_vector(g_id_width-1 downto 0);
    clock: in std_logic;
    reset: in std_logic);
  
end component demerge_tree;

component demerge_tree_wrap
  
  generic (
     name: string;
    g_demux_degree: natural;
    g_number_of_outputs: natural;
    g_data_width: natural;              -- total width of data
                                        -- (= data & tag & port-id & timestamp)
    g_id_width: natural;
    g_stage_id: natural
    );       

  port (
    demerge_data_out : out std_logic_vector((g_data_width*g_number_of_outputs)-1 downto 0);
    demerge_ready_out  : out std_logic_vector(g_number_of_outputs-1 downto 0);
    demerge_accept_in   : in std_logic_vector(g_number_of_outputs-1 downto 0);
    demerge_data_in: in std_logic_vector(g_data_width-1 downto 0);
    demerge_ack_out : out std_logic;
    demerge_req_in  : in std_logic;
    demerge_sel_in: in std_logic_vector(g_id_width-1 downto 0);
    clock: in std_logic;
    reset: in std_logic);
  
end component demerge_tree_wrap;

component combinational_merge 
  generic (
     name: string;
    g_data_width       : natural;
    g_number_of_inputs: natural;
    g_time_stamp_width : natural);
  port(
    in_data: in std_logic_vector((g_data_width*g_number_of_inputs)-1 downto 0);
    in_tstamp: in std_logic_vector((g_number_of_inputs*g_time_stamp_width)-1 downto 0);
    out_data: out std_logic_vector(g_data_width-1 downto 0);
    out_tstamp: out std_logic_vector(g_time_stamp_width-1 downto 0);
    in_req: in std_logic_vector(g_number_of_inputs-1 downto 0);
    in_ack: out std_logic_vector(g_number_of_inputs-1 downto 0);
    out_req: out std_logic;
    out_ack: in std_logic);
end component combinational_merge;

component combinational_merge_with_repeater
  generic (
     name: string;
    g_data_width       : natural;
    g_number_of_inputs: natural;
    g_time_stamp_width : natural);
  port(
    clk : in std_logic;
    reset : in std_logic;
    in_data: in std_logic_vector((g_data_width*g_number_of_inputs)-1 downto 0);
    in_tstamp: in std_logic_vector((g_number_of_inputs*g_time_stamp_width)-1 downto 0);
    out_data: out std_logic_vector(g_data_width-1 downto 0);
    out_tstamp: out std_logic_vector(g_time_stamp_width-1 downto 0);
    in_req: in std_logic_vector(g_number_of_inputs-1 downto 0);
    in_ack: out std_logic_vector(g_number_of_inputs-1 downto 0);
    out_req: out std_logic;
    out_ack: in std_logic);
end component combinational_merge_with_repeater;


component memory_subsystem_core
  generic (
    name: string;
    num_loads       : natural;
    num_stores      : natural;
    addr_width      : natural;
    data_width      : natural;
    tag_width       : natural;
    time_stamp_width    : natural;
    number_of_banks : natural;
    mux_degree      : natural;
    demux_degree    : natural;
    base_bank_addr_width: natural;
    base_bank_data_width: natural);
  port (
    lr_addr_in  : in  std_logic_vector((num_loads*addr_width)-1 downto 0);
    lr_req_in   : in  std_logic_vector(num_loads-1 downto 0);
    lr_ack_out  : out std_logic_vector(num_loads-1 downto 0);
    lr_tag_in   : in  std_logic_vector((num_loads*tag_width)-1 downto 0);
    lr_time_stamp_in   : in  std_logic_vector((num_loads*time_stamp_width)-1 downto 0);
    lc_data_out : out std_logic_vector((num_loads*data_width)-1 downto 0);
    lc_req_in   : in  std_logic_vector(num_loads-1 downto 0);
    lc_ack_out  : out std_logic_vector(num_loads-1 downto 0);
    lc_tag_out  : out std_logic_vector((num_loads*tag_width)-1 downto 0);
    sr_addr_in  : in  std_logic_vector((num_stores*addr_width)-1 downto 0);
    sr_data_in  : in  std_logic_vector((num_stores*data_width)-1 downto 0);
    sr_req_in   : in  std_logic_vector(num_stores-1 downto 0);
    sr_ack_out  : out std_logic_vector(num_stores-1 downto 0);
    sr_tag_in   : in  std_logic_vector((num_stores*tag_width)-1 downto 0);
    sr_time_stamp_in   : in  std_logic_vector((num_stores*time_stamp_width)-1 downto 0);
    sc_req_in   : in  std_logic_vector(num_stores-1 downto 0);
    sc_ack_out  : out std_logic_vector(num_stores-1 downto 0);
    sc_tag_out  : out std_logic_vector((num_stores*tag_width)-1 downto 0);
    clock       : in  std_logic;
    reset       : in  std_logic);
end component;

component CombinationalMux is
  generic (
     name: string;
    g_data_width       : integer := 32;
    g_number_of_inputs: integer := 2);
  port(
    in_data: in std_logic_vector((g_data_width*g_number_of_inputs)-1 downto 0);
    out_data: out std_logic_vector(g_data_width-1 downto 0);
    in_req: in std_logic_vector(g_number_of_inputs-1 downto 0);
    in_ack: out std_logic_vector(g_number_of_inputs-1 downto 0);
    out_req: out std_logic;
    out_ack: in std_logic);
end component CombinationalMux;

component PipelinedMux is
  generic (
     name: string;
    g_number_of_inputs: natural;          
    g_data_width: natural;          -- total width of data
                                        -- (= actual-data & tag & port_id)
    g_mux_degree :natural;         -- max-indegree of each pipeline-stage
    g_port_id_width: natural
    );       

  port (
    merge_data_in : in std_logic_vector((g_data_width*g_number_of_inputs)-1 downto 0);
    merge_req_in  : in std_logic_vector(g_number_of_inputs-1 downto 0);
    merge_ack_out : out std_logic_vector(g_number_of_inputs-1 downto 0);
    merge_data_out: out std_logic_vector(g_data_width-1 downto 0);
    merge_req_out : out std_logic;
    merge_ack_in  : in std_logic;
    clock: in std_logic;
    reset: in std_logic);
  
end component PipelinedMux;

component PipelinedMuxStage is 
  generic (name: string;
	   g_data_width: integer := 10;
           g_number_of_inputs: integer := 8;
           g_number_of_outputs: integer := 1;
           g_tag_width : integer := 3  -- width of tag
           );            

  port(data_left: in  std_logic_vector((g_data_width*g_number_of_inputs)-1 downto 0);
       req_in : in std_logic_vector(g_number_of_inputs-1 downto 0);
       ack_out : out std_logic_vector(g_number_of_inputs-1 downto 0);
       data_right: out std_logic_vector((g_data_width*g_number_of_outputs)-1 downto 0);
       req_out : out std_logic_vector(g_number_of_outputs-1 downto 0);
       ack_in : in std_logic_vector(g_number_of_outputs-1 downto 0);
       clock: in std_logic;
       reset: in std_logic);

end component PipelinedMuxStage;

component PipelinedDemux is
  generic ( name: string;
	    g_data_width: natural := 10;
            g_destination_id_width : natural := 3;
            g_number_of_outputs: natural := 8);
  port(data_in: in std_logic_vector(g_data_width-1 downto 0);  -- data & destination-id 
       sel_in : in std_logic_vector(g_destination_id_width-1 downto 0);
       req_in: in std_logic;
       ack_out : out std_logic;
       data_out: out std_logic_vector((g_number_of_outputs*g_data_width)-1 downto 0 );
       req_out: out std_logic_vector(g_number_of_outputs-1 downto 0);
       ack_in : in std_logic_vector(g_number_of_outputs-1 downto 0);
       clk: in std_logic;
       reset: in std_logic);
end component;

end package mem_component_pack;

