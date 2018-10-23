#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 12

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

#define green matrix.Color(0, 255, 0)
#define red matrix.Color(255, 0, 0)
#define purple matrix.Color(255, 0, 255)

void setup() {
  matrix.begin(); 
  matrix.setBrightness(10);
  
}

void loop() {
  matrix.fillScreen(0);
  for( int x = 0; x < 8; x++){
    matrix.drawPixel(0, x, green);
    matrix.drawPixel(1, 7-x, red);
    matrix.drawPixel(2, x, green);
    matrix.drawPixel(3, 7-x, red);
    matrix.drawPixel(4, x, green);
    matrix.drawPixel(5, 7-x, red);
    matrix.drawPixel(6, x, green);
    matrix.drawPixel(7, 7-x, red);
    matrix.show();
    delay(100);
    matrix.fillScreen(0);
  }
  for(int x=0; x<8; x++){
    matrix.drawPixel(0, x, red);
    matrix.drawPixel(1, 7-x, green);
    matrix.drawPixel(2, x, red);
    matrix.drawPixel(3, 7-x, green);
    matrix.drawPixel(4, x, red);
    matrix.drawPixel(5, 7-x, green);
    matrix.drawPixel(6, x, red);
    matrix.drawPixel(7, 7-x, green);
    matrix.show();
    delay(100);
    matrix.fillScreen(0);
  }
}
