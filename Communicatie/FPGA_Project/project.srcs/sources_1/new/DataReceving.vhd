library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity DataReceving is
    Port (
        sys_clk     : in std_logic;
        clk         : in std_logic;
        data        : in std_logic_vector(7 downto 0);
        test        : out std_logic_vector(7 downto 0)
    );
end DataReceving;

architecture Behavioral of DataReceving is

signal receved_bytes        : std_logic_vector(15 downto 0);
signal flag                 : std_logic;
signal processing_bit       : std_logic;

-- The states machine
TYPE State_type IS (Header, X, Y);  -- Define the states
SIGNAL State : State_Type := Header;    -- Create a signal that uses 
begin

receving : process(sys_clk)
variable flag_second_bit    : std_logic;
begin
    if (rising_edge(sys_clk)) then
        if (clk = '1') then
            if(flag = '0') then
                flag <= '1';
                -- The reseving logic
                if (flag_second_bit = '1') then
                    flag_second_bit := '0';
                    receved_bytes(15 downto 8) <= data;
                    case State is
                        when header =>
                            if (receved_bytes(15 downto 14) = "11") then
                                State <= X;
                            end if;
                            test(1 downto 0) <= "00"; 
                        when X =>
                            if (receved_bytes(15 downto 14) = "01") then
                                State <= Y;
                            end if;
                            test(1) <= '1';
                       when Y =>
                            if (receved_bytes(15 downto 14) = "10") then
                               State <= header;
                           end if;
                           test(0) <= '1';
                    end case;
                else
                    flag_second_bit := '1';
                    receved_bytes(7 downto 0) <= data;
                    processing_bit <= '0';
                end if;
                --------------------
            end if;
        else
            flag <= '0';
        end if;
    end if;
end process;
end Behavioral;
