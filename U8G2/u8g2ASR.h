#include "../U8G2/u8g2.h"

/////my init 
  void ssd1306_spi_init()
  {
  pinMode(CS,output);
	pinMode(DC,output);
	//pinMode(ST7735_RST_PIN,output);
	pinMode(SCK,output);
	pinMode(MOSI,output);
  }
  
uint8_t u8x8_avr_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
  {
	// Re-use library for delays

	switch(msg)
	{
	  //ms
	  	case U8X8_MSG_DELAY_MILLI:
        delay(1);
      break;
      
      //10 us
      case U8X8_MSG_DELAY_10MICRO:
        delay10us();
      break;
      
      //1 ns
	   case U8X8_MSG_DELAY_NANO:
        delay1us();
      break;
      
    case U8X8_MSG_DELAY_100NANO:
      delay1us();
      break;
      
		case U8X8_MSG_GPIO_AND_DELAY_INIT:  // called once during init phase of u8g2/u8x8
        ssd1306_spi_init();
			break;              // can be used to setup pins
		case U8X8_MSG_GPIO_SPI_CLOCK:        // Clock pin: Output level in arg_int
			if(arg_int)
				digitalWrite(SCK,1);
			else
				digitalWrite(SCK,0);
			break;
		case U8X8_MSG_GPIO_SPI_DATA:        // MOSI pin: Output level in arg_int
			if(arg_int)
				digitalWrite(MOSI,1);
			else
				digitalWrite(MOSI,0);
			break;
		case U8X8_MSG_GPIO_CS:        // CS (chip select) pin: Output level in arg_int
			if(arg_int)
				digitalWrite(CS,1);
			else
				digitalWrite(CS,0);
			break;
		case U8X8_MSG_GPIO_DC:        // DC (data/cmd, A0, register select) pin: Output level in arg_int
      if(arg_int)
				digitalWrite(DC,1);
			else
				digitalWrite(DC,0);
			break;
		
		case U8X8_MSG_GPIO_RESET:     // Reset pin: Output level in arg_int

		default:
		  break;

	}
	return 1;
}


// void u8g2Init(u8g2_t *u8g2)
// {

//   u8g2_Setup_ssd1306_128x64_noname_f(u8g2, U8G2_R0, u8x8_byte_4wire_sw_spi, u8x8_avr_gpio_and_delay);
// 	u8g2_InitDisplay(u8g2);
// 	u8g2_SetPowerSave(u8g2, 0);
// 	u8g2_ClearBuffer(u8g2);
// } 

class u8g2_class
{
  public:
  u8g2_t u8g2;
  void u8g2_init()
  {
    u8g2_Setup_ssd1306_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_4wire_sw_spi, u8x8_avr_gpio_and_delay);
  	u8g2_InitDisplay(&u8g2);
  	u8g2_SetPowerSave(&u8g2, 0);
  	u8g2_ClearBuffer(&u8g2);
  }
  void sendBuffer(void) { u8g2_SendBuffer(&u8g2); }
  void clearBuffer(void) { u8g2_ClearBuffer(&u8g2); }    

  u8g2_uint_t drawGlyph(u8g2_uint_t x, u8g2_uint_t y, uint16_t encoding) { return u8g2_DrawGlyph(&u8g2, x, y, encoding); }    
  u8g2_uint_t drawGlyphX2(u8g2_uint_t x, u8g2_uint_t y, uint16_t encoding) { return u8g2_DrawGlyphX2(&u8g2, x, y, encoding); }    

  void setColorIndex(uint8_t color_index) { u8g2_SetDrawColor(&u8g2, color_index); }
  void setFont(const uint8_t  *font) {u8g2_SetFont(&u8g2, font); }
  void setFontMode(uint8_t  is_transparent) {u8g2_SetFontMode(&u8g2, is_transparent); }
  
      void setBitmapMode(uint8_t is_transparent) 
      { u8g2_SetBitmapMode(&u8g2, is_transparent); }
    void drawBitmap(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t cnt, u8g2_uint_t h, const uint8_t *bitmap)
      { u8g2_DrawBitmap(&u8g2, x, y, cnt, h, bitmap); }
    void drawXBM(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w, u8g2_uint_t h, const uint8_t *bitmap)
      { u8g2_DrawXBM(&u8g2, x, y, w, h, bitmap); }
    void drawXBMP(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w, u8g2_uint_t h, const uint8_t *bitmap)
      { u8g2_DrawXBMP(&u8g2, x, y, w, h, bitmap); }
  
  
};