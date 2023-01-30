//**************************************************************************************************
// ttgo-tm.h                                                                                       *
//**************************************************************************************************
// Separated from the main sketch to allow several display types.                                  *
// Includes for various ST7789 displays.  Size is 320 x 240.                                       *
// Modified for Lilygo TTGO TM Music Albums with 320 x 240 display.                                *
//**************************************************************************************************
#ifndef ST7789_H
#define ST7789_H
#include <Adafruit_ST7789.h>

#define TIMEPOS     -104                         // Position (column) of time in topline relative to end
#define INIPARS     ini_block.tft_cs_pin, ini_block.tft_dc_pin  // Prameters for dsp_begin
#define DISPLAYTYPE "ST7789"

// Color definitions for the TFT screen (if used)
// TFT has bits 6 bits (0..5) for RED, 6 bits (6..11) for GREEN and 4 bits (12..15) for BLUE.
#define BLACK   ST77XX_BLACK
#define BLUE    ST77XX_BLUE
#define RED     ST77XX_RED
#define GREEN   ST77XX_GREEN
#define CYAN    GREEN | BLUE
#define MAGENTA RED | BLUE
#define YELLOW  RED | GREEN
#define WHITE   RED | BLUE | GREEN
#define GRAY    0x7bf0

#define DEFTXTSIZ  2                                  // Default text size


struct scrseg_struct                                  // For screen segments
{
  bool     update_req ;                               // Request update of screen
  uint16_t color ;                                    // Textcolor
  uint16_t y ;                                        // Begin of segment row
  uint16_t height ;                                   // Height of segment
  String   str ;                                      // String to be displayed
} ;


// Data to display.  There are TFTSECS sections
#define TFTSECS 4

#define tftdata             TTGOTM_tftdata
#define displaybattery      TTGOTM_displaybattery
#define displayvolume       TTGOTM_displayvolume
#define displaytime         TTGOTM_displaytime

extern Adafruit_ST7789*     TTGOTM_tft ;                                 // For instance of display driver

// Various macro's to mimic the ST7789 version of display functions
#define dsp_setRotation()       TTGOTM_tft->setRotation ( 1 )            // Use landscape format (3 for upside down) DGH
#define dsp_print(a)            TTGOTM_tft->print ( a )                  // Print a string 
#define dsp_println(b)          TTGOTM_tft->println ( b )                // Print a string followed by newline 
#define dsp_fillRect(a,b,c,d,e) TTGOTM_tft->fillRect ( a, b, c, d, e ) ; // Fill a rectange
#define dsp_setTextSize(a)      TTGOTM_tft->setTextSize(a)               // Set the text size
#define dsp_setTextColor(a)     TTGOTM_tft->setTextColor(a)              // Set the text color
#define dsp_setCursor(a,b)      TTGOTM_tft->setCursor ( a, b )           // Position the cursor
#define dsp_erase()             TTGOTM_tft->fillScreen ( BLACK ) ;       // Clear the screen
#define dsp_getwidth()          320                                      // Adjust to your display DGH
#define dsp_getheight()         240                                      // Get height of screen
#define dsp_update(a)                                                    // Updates to the physical screen
#define dsp_usesSPI()           true                                     // Does use SPI
#define dsp_begin               TTGOTM_dsp_begin                         // Init driver
#define dsp_init()              TTGOTM_tft->init ( 240, 320 ) ;          // DGH
#define dsp_invert()            TTGOTM_tft-> invertDisplay(0);

extern scrseg_struct     TTGOTM_tftdata[TFTSECS] ;                   // Screen divided in segments
//void TTGOTM_dsp_fillRect   ( int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color ) ;
void TTGOTM_displaybattery ( uint16_t bat0, uint16_t bat100, uint16_t adcval ) ;
void TTGOTM_displayvolume  ( uint8_t vol ) ;
void TTGOTM_displaytime    ( const char* str, uint16_t color = BLUE ) ; // DGH
bool TTGOTM_dsp_begin      ( int8_t cs, int8_t dc ) ;
#endif
