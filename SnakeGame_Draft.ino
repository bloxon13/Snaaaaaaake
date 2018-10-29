/*
 * This is SnakeGame_Draft
 *  
 */

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 12
#define UP 3
#define DOWN 4
#define LEFT 5
#define RIGHT 6

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

#define green matrix.Color(0, 255, 0)
#define red matrix.Color(255, 0, 0)
#define purple matrix.Color(255, 0, 255)

int direc = 2;

int snakeArray[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

int snakeHead[2] {2,2};
int snakeLength = 1;

void setup() {
  pinMode(UP, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(UP), goUp, LOW);
  pinMode(DOWN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(DOWN), goDown, LOW);
  pinMode(LEFT, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(LEFT), goLeft, LOW);
  pinMode(RIGHT, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RIGHT), goRight, LOW);
  matrix.begin(); 
  matrix.setBrightness(10);
}

void loop() {
  moveSnakeHead(direc);
  drawSnake();
  delay(900);
  matrix.fillScreen(0);
  matrix.show();
  delay(100);
}

/* moveSnakeHead()
 * takes direc as an input and changes snakeHead[] to the updated coordinates and 
 * moves the dot on snakeArray[][]
 */
void moveSnakeHead(int direc) {
  //up
  if (direc == 0) {
    snakeArray[snakeHead[0]][snakeHead[1]] = 0;
    snakeHead[1]+=1;
    snakeArray[snakeHead[0]][snakeHead[1]] = 1;
  }
  //down
  if (direc == 1) {
    snakeArray[snakeHead[0]][snakeHead[1]] = 0;
    snakeHead[1]-=1;
    snakeArray[snakeHead[0]][snakeHead[1]] = 1;
  }
  //right
  if (direc == 2) {
    snakeArray[snakeHead[0]][snakeHead[1]] = 0;
    snakeHead[0]+=1;
    snakeArray[snakeHead[0]][snakeHead[1]] = 1;
  }
  //left
  if (direc == 3) {
    snakeArray[snakeHead[0]][snakeHead[1]] = 0;
    snakeHead[0]-=1;
    snakeArray[snakeHead[0]][snakeHead[1]] = 1;
  }
}

/* drawSnake()
 * Takes snakeArray[][] and outputs it onto the board.
 */
void drawSnake() {
  matrix.fillScreen(0);
  for(int x = 0; x <= 7; x++){
    for(int y=0; y<=7; y++) {
      if (snakeArray[x][y]==1){
        if (y==1 || y==3 || y==5 || y==7){
          matrix.drawPixel(x,7-y,green);
          matrix.show();          
        }
        else {
          matrix.drawPixel(x,y,green);
          matrix.show();        
        }
      }
    }
  }
}

/* go__()
 * Changes direc to the direction the interrupt affects
 */
void goUp() {
  direc = 0;
}
void goDown() {
  direc = 1;
}
void goRight() {
  direc = 2;
}
void goLeft() {
  direc = 3;
}
