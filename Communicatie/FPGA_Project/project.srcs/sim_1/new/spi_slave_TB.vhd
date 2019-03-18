library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity spi_slave_TB is
--  Port ( );
end spi_slave_TB;

architecture Behavioral of spi_slave_TB is
component spi_slave IS
  GENERIC(
    cpol    : STD_LOGIC := '0';  --spi clock polarity mode
    cpha    : STD_LOGIC := '0';  --spi clock phase mode
    d_width : INTEGER := 16);     --data width in bits
  PORT(
    sclk         : IN     STD_LOGIC;  --spi clk from master
    reset_n      : IN     STD_LOGIC;  --active low reset
    ss_n         : IN     STD_LOGIC;  --active low slave select
    mosi         : IN     STD_LOGIC;  --master out, slave in
    rx_req       : IN     STD_LOGIC;  --'1' while busy = '0' moves data to the rx_data output
    st_load_en   : IN     STD_LOGIC;  --asynchronous load enable
    st_load_trdy : IN     STD_LOGIC;  --asynchronous trdy load input
    st_load_rrdy : IN     STD_LOGIC;  --asynchronous rrdy load input
    st_load_roe  : IN     STD_LOGIC;  --asynchronous roe load input
    tx_load_en   : IN     STD_LOGIC;  --asynchronous transmit buffer load enable
    tx_load_data : IN     STD_LOGIC_VECTOR(d_width-1 DOWNTO 0);  --asynchronous tx data to load
    trdy         : BUFFER STD_LOGIC := '0';  --transmit ready bit
    rrdy         : BUFFER STD_LOGIC := '0';  --receive ready bit
    roe          : BUFFER STD_LOGIC := '0';  --receive overrun error bit
    rx_data      : OUT    STD_LOGIC_VECTOR(d_width-1 DOWNTO 0) := (OTHERS => '0');  --receive register output to logic
    busy         : OUT    STD_LOGIC := '0';  --busy signal to logic ('1' during transaction)
    miso         : OUT    STD_LOGIC := 'Z'); --master in, slave out
END component;


constant width          : INTEGER := 16;
-- Signals
signal clk : STD_LOGIC := '0';
signal mosi : STD_LOGIC;
signal data_out : STD_LOGIC_VECTOR(width - 1 downto 0);
signal reset_n : STD_LOGIC := '0';


-- Test signalen
signal st_load_en_tb    : STD_LOGIC := '0';
signal st_load_trdy_tb  : STD_LOGIC := '0';
signal tx_load_data_tb  : STD_LOGIC_VECTOR(width -1 downto 0);
signal tx_load_en_tb    : STD_LOGIC := '0';
signal ss_n_tb          : STD_LOGIC := '1';
signal busy_tb          : STD_LOGIC;

signal rrdy_tb          : STD_LOGIC;
begin

UUT : spi_slave port map(
    sclk => clk,
    ss_n => ss_n_tb,
    reset_n => reset_n,
    mosi => mosi,
    rx_req => '1',
    st_load_en => st_load_en_tb,
    st_load_trdy => st_load_trdy_tb,
    st_load_rrdy => '0',
    st_load_roe => '0',
    tx_load_en => tx_load_en_tb,
    tx_load_data => tx_load_data_tb,
    rx_data => data_out,
    busy => busy_tb,
    rrdy => rrdy_tb
);

TEST : process
begin
    wait for 100ns;
    -- Pre eerste lijn
    reset_n <= '1';
    tx_load_en_tb <= '1';
    wait for 10ns;
    
    ss_n_tb <= '0';
    mosi <= '0';
    wait for 1ns;
    
    -- Eerste lijn
    clk <= '1';
    wait for 1ns;
    clk <= '0';
    wait for 1ns;
    
    -- Tweede lijn
    clk <= '1';
    wait for 1ns;
    clk <= '0';
    wait for 1ns;
    
    -- Derde lijn
    clk <= '1';
    wait for 1ns;
    clk <= '0';
    wait for 1ns;
    
    -- Vierde lijn
    clk <= '1';
    wait for 1ns;
    clk <= '0';
    wait for 1ns;
    
    -- Vijfde lijn
    clk <= '1';
    wait for 1ns;
    clk <= '0';
    wait for 1ns;
    
    -- Zesde lijn
    clk <= '1';
    wait for 1ns;
    clk <= '0';
    wait for 1ns;
    
    -- Zevende lijn
    clk <= '1';
    wait for 1ns;
    clk <= '0';
    wait for 1ns;
    
    -- achteste lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '1';
    clk <= '0';
    wait for 1ns;
    
    -- negende lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '0';
    clk <= '0';
    wait for 1ns;
    
    -- tiende lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '1';
    clk <= '0';
    wait for 1ns;
    
    -- elfde lijn
    clk <= '1';
    wait for 1ns;
    clk <= '0';
    wait for 1ns;
    
    -- twaalfde lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '0';
    clk <= '0';
    wait for 1ns;
    
    -- dertiende lijn
    clk <= '1';
    wait for 1ns;
    clk <= '0';
    wait for 1ns;
    
    -- viertiende lijn
    clk <= '1';
    wait for 1ns;
    clk <= '0';
    wait for 1ns;
    
    -- vijftiende lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '1';
    clk <= '0';
    wait for 1ns;
    
    -- zestiende lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '1';
    clk <= '0';
    wait for 1ns;
    
    -- Zeventiende lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '0';
    clk <= '0';
    wait for 1ns;
    
    -- Achtiende lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '1';
    clk <= '0';
    wait for 1ns;
    
    -- negentiende lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '0';
    clk <= '0';
    wait for 1ns;
        
    -- twintigste lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '1';
    clk <= '0';
    wait for 1ns;
        
    -- eenentwintigste lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '0';
    clk <= '0';
    wait for 1ns;
        
    -- tweeentwintigest lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '1';
    clk <= '0';
    wait for 1ns;
        
    -- drieentwintigste lijn
    clk <= '1';
    wait for 1ns;
    mosi <= '0';
    clk <= '0';
    wait for 1ns;
        
    -- vierentwintigste lijn
    clk <= '1';
    wait for 1ns;
    mosi <= 'Z';
    clk <= '0';
    wait for 1ns;
    
    ss_n_tb <= '1';
    
end process;
end Behavioral;
