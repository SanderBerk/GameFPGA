library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Synchronis is
    Port (
        sys_clk : in std_logic;
        data : in std_logic_vector(7 downto 0);
        dataout : out std_logic_vector(7 downto 0);
        clk : in std_logic;
        clkout : out std_logic
    );
end Synchronis;

architecture Behavioral of Synchronis is
signal flipflops    : STD_LOGIC_VECTOR(17 downto 0);
begin
process(sys_clk)
begin
    if rising_edge(sys_clk) then  
        flipflops(0) <= clk;
        flipflops(1) <= flipflops(0);
        
        flipflops(9 downto 2) <= data;
        flipflops(17 downto 10) <=  flipflops(9 downto 2);
    end if;
end process;

clkout <= flipflops(1);
dataout <= flipflops(17 downto 10);

end Behavioral;