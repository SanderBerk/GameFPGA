#ifndef ssd1306
#define ssd1306
/*
 * Niks boven de guards zetten.
 */
/*
 * Deze header hoort bij een .c bestand dus moet extern "C" gebruikt worden.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l4xx_hal.h"
#include "fonts.h"

// i2c1 is chosen. In case using I2C2, change to hi2c2
#define SSD1306_I2C_PORT			hi2c1
// SSD1306 I2C address 
#define SSD1306_I2C_ADDR        	0x78
// SSD1306 width in pixels
#define SSD1306_WIDTH           	128
// SSD1306 LCD height in pixels
#define SSD1306_HEIGHT          	32



typedef enum {
	Black = 0x00, /*!< Black color, no pixel */
	White = 0x01  /*!< Pixel is set. Color depends on LCD */
} SSD1306_COLOR;


typedef struct {
	uint16_t CurrentX;
	uint16_t CurrentY;
	uint8_t Inverted;
	uint8_t Initialized;
} SSD1306_t;


extern I2C_HandleTypeDef SSD1306_I2C_PORT;

/*
 * niet relevant voor het probleem maar probeer const te gebruiken wanneer je iets niet aan past.
 */

uint8_t ssd1306_Init(void);
void ssd1306_Fill(SSD1306_COLOR color);
void ssd1306_UpdateScreen(void);
void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color);
char ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color);
char ssd1306_WriteString(const char* str, const FontDef Font, const SSD1306_COLOR color);
void ssd1306_SetCursor(uint8_t x, uint8_t y);

void ssd1306_WriteCommand(uint8_t command);

#ifdef __cplusplus
}
#endif //De sluit bracket van extern "C"

#endif
