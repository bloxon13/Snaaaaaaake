#include <Adafruit_NeoMatrix.h>
#include <gamma.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>


#include <Adafruit_NeoPixel.h>

 
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 6,
      NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
      NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
      NEO_GRB            + NEO_KHZ800);


void setup() {
  matrix.begin();
  matrix.setBrightness(40);
  matrix.setTextColor( matrix.Color(255, 255, 255) );
  matrix.setTextWrap(false);
  
}

void loop() {
  matrix.drawPixel(0, 0, 1);
  

}
// vim:sts=4:sw=4
