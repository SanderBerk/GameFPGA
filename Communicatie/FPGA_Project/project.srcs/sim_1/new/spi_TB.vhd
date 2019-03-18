library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity spi_TB is
--  Port ( );
end spi_TB;

architecture Behavioral of spi_TB is
component SPI is
    Port (
        sys_clk : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        MOSI : IN STD_LOGIC;
        data_out : OUT STD_LOGIC_VECTOR(15 downto 0)
    );
end component;

-- sim signal
signal clk_tb           : STD_LOGIC;
signal MOSI_tb          : STD_LOGIC; 
signal data_out_tb      : STD_LOGIC_VECTOR(15 downto 0);   

-- system clk sim
constant clk_time          : TIME := 10ns;
signal sys_clk_tb       : STD_LOGIC;
begin
clk_process : process
begin
    sys_clk_tb <= '0';
    wait for clk_time /2;
    sys_clk_tb <= '1';
    wait for clk_time /2;
end process;

UUT : SPI port map(
    sys_clk => sys_clk_tb,
    clk => clk_tb,
    MOSI => MOSI_tb,
    data_out => data_out_tb
);

test : process
begin
    MOSI_tb <= '0';
    clk_tb <= '0';
    wait for 50ns;
    
    -- first bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '0';
    clk_tb <= '0';
    wait for 50ns;
    
    -- tweede bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '1';
    clk_tb <= '0';
    wait for 50ns;
    
    -- derde bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '0';
    clk_tb <= '0';
    wait for 50ns;
    
    -- vierde bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '1';
    clk_tb <= '0';
    wait for 50ns;
    
    -- vijfde bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '0';
    clk_tb <= '0';
    wait for 50ns;
    
    -- zesde bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '1';
    clk_tb <= '0';
    wait for 50ns;
    
    -- zevende bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '0';
    clk_tb <= '0';
    wait for 50ns;
    
    -- achtste bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '1';
    clk_tb <= '0';
    wait for 50ns;
    
    -- negende bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '0';
    clk_tb <= '0';
    wait for 50ns;
    
    -- tiende bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '1';
    clk_tb <= '0';
    wait for 50ns;
    
    -- elfde bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '0';
    clk_tb <= '0';
    wait for 50ns;
    
    -- twaalfde bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '1';
    clk_tb <= '0';
    wait for 50ns;
    
    -- dertiende bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '0';
    clk_tb <= '0';
    wait for 50ns;
    
    -- veertiende bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '1';
    clk_tb <= '0';
    wait for 50ns;
    
    -- vijftiende bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '0';
    clk_tb <= '0';
    wait for 50ns;
    
    -- zestiende bit
    clk_tb <= '1';
    wait for 50ns;
    mosi_tb <= '1';
    clk_tb <= '0';
    wait for 50ns;
    
    wait for 400ns;
end process;

end Behavioral;
