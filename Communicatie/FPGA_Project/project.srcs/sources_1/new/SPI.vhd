library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity SPI is
    Port (
        sys_clk : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        MOSI : IN STD_LOGIC;
        data_out : OUT STD_LOGIC_VECTOR(15 downto 0)
    );
end SPI;

architecture Behavioral of SPI is
TYPE State_type IS (IDLE, READING);  -- Define the states
SIGNAL State : State_Type;    -- Create a signal that uses 
signal flag : STD_LOGIC := '0';
SIGNAL data : STD_LOGIC_VECTOR(15 downto 0) := (OTHERS => '0');
begin

data_out <= data;
process (sys_clk)
begin
    if(State = IDLE and clk =  '1') then
        State <= Reading;
    elsif (State = Reading and clk = '0' and flag = '0') then
        flag <= '1';
        data <= data(14 downto 0) & MOSI;
    elsif (State = Reading AND clk = '1') then
        flag <= '0';
    end if;
end process;
end Behavioral;
