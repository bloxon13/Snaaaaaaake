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
  int inv;
}

void loop() {
  matrix.fillScreen(0);
  for(int x = 0; x <= 7; x++){
    for(int y=0; y<=7; y++) {
      if (y==1 || y==3 || y==5 || y==7){
        matrix.drawPixel(y, 7-x, red);
        matrix.show();
        delay(50);
      }
      else {
      matrix.drawPixel(y, x, red);
      matrix.show();
      delay(50);
      }
    }
  }
}
