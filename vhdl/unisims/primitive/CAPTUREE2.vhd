-- $Header: /devl/xcs/repo/env/Databases/CAEInterfaces/vhdsclibs/data/unisims/fuji/VITAL/CAPTUREE2.vhd,v 1.1 2010/05/27 18:45:51 yanx Exp $
-------------------------------------------------------
--  Copyright (c) 2009 Xilinx Inc.
--  All Right Reserved.
-------------------------------------------------------
--
--   ____  ____
--  /   /\/   / 
-- /___/  \  /     Vendor      : Xilinx 
-- \   \   \/      Version : 11.1
--  \   \          Description : 
--  /   /                      
-- /___/   /\      Filename    : CAPTUREE2.vhd
-- \   \  /  \      
--  \__ \/\__ \                   
--                                 
--  Generated by    : /home/chen/xfoundry/HEAD/env/Databases/CAEInterfaces/LibraryWriters/bin/ltw.pl
--  Revision: 1.0
-------------------------------------------------------

----- CELL CAPTUREE2 -----

library IEEE;
use IEEE.STD_LOGIC_arith.all;
use IEEE.STD_LOGIC_1164.all;

library unisim;
use unisim.VCOMPONENTS.all;
use unisim.vpkg.all;

  entity CAPTUREE2 is
    generic (
      ONESHOT : string := "TRUE"
    );

    port (
      CAP                  : in std_ulogic;
      CLK                  : in std_ulogic      
    );
  end CAPTUREE2;

  architecture CAPTUREE2_V of CAPTUREE2 is
    
    constant IN_DELAY : time := 0 ps;
    constant OUT_DELAY : time := 0 ps;
    constant INCLK_DELAY : time := 0 ps;
    constant OUTCLK_DELAY : time := 0 ps;

    function SUL_TO_STR (sul : std_ulogic)
    return string is
    begin
      if sul = '0' then
        return "0";
      else
        return "1";
      end if;
    end SUL_TO_STR;

    function boolean_to_string(bool: boolean)
    return string is
    begin
      if bool then
        return "TRUE";
      else
        return "FALSE";
      end if;
    end boolean_to_string;

    function getstrlength(in_vec : std_logic_vector)
    return integer is
      variable string_length : integer;
    begin
      if ((in_vec'length mod 4) = 0) then
        string_length := in_vec'length/4;
      elsif ((in_vec'length mod 4) > 0) then
        string_length := in_vec'length/4 + 1;
      end if;
      return string_length;
    end getstrlength;

    signal ONESHOT_BINARY : std_ulogic;
    
    signal CAP_ipd : std_ulogic;
    signal CLK_ipd : std_ulogic;
    
    signal CAP_indelay : std_ulogic;
    signal CLK_indelay : std_ulogic;
    
    begin
    CLK_ipd <= CLK;
    
    CAP_ipd <= CAP;
    
    CLK_indelay <= CLK_ipd after INCLK_DELAY;
    
    CAP_indelay <= CAP_ipd after IN_DELAY;
    
    
    INIPROC : process
    begin
    -- case ONESHOT is
      if((ONESHOT = "TRUE") or (ONESHOT = "true")) then
        ONESHOT_BINARY <= '1';
      elsif((ONESHOT = "FALSE") or (ONESHOT= "false")) then
        ONESHOT_BINARY <= '0';
      else
        assert FALSE report "Error : ONESHOT = is not TRUE, FALSE." severity error;
      end if;
    -- end case;
    wait;
    end process INIPROC;
  end CAPTUREE2_V;
