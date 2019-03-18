library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity TOP is
  Port (
        sys_clk : IN STD_LOGIC;
        clk_in : IN STD_LOGIC;
        data_in : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
        data_out : OUT STD_LOGIC_VECTOR(7 downto 0);
        testing : out STD_LOGIC_VECTOR(7 DOWNTO 0)
  );
end TOP;
architecture Behavioral of TOP is

component Synchronis is
    Port (
        sys_clk : in std_logic;
        data : in std_logic_vector(7 downto 0);
        dataout : out std_logic_vector(7 downto 0);
        clk : in std_logic;
        clkout : out std_logic
    );
end component;

component DataReceving is
    Port (
        sys_clk     : in std_logic;
        clk         : in std_logic;
        data        : in std_logic_vector(7 downto 0);
        test        : out std_logic_vector(7 downto 0)
    );
end component;

signal clk : std_logic;
signal data : std_logic_vector(7 downto 0);

begin

data_out <= data;

sync : Synchronis port map(
    sys_clk => sys_clk,
    data => data_in,
    dataout => data,
    clk => clk_in,
    clkout => clk
);

drec : DataReceving port map(
    sys_clk => sys_clk,
    clk => clk_in,
    data => data,
    test => testing
);
end Behavioral;
