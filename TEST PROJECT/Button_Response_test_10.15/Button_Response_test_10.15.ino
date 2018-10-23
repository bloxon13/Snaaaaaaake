#define UP 3
#define DOWN 4
#define LEFT 5
#define RIGHT 6
#define DIGI 12

int direction = 3;

void setup() {
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(UP) != 1)
    Serial.println("UP");
  if (digitalRead(DOWN) != 1)
    Serial.println("DOWN");
  if (digitalRead(LEFT) != 1)
    Serial.println("LEFT");
  if (digitalRead(RIGHT) != 1)
    Serial.println("RIGHT");

  delay(10);

}

void checkButton(){
  if (digitalRead(UP) != 1)
    direction = 0;
  if (digitalRead(DOWN) != 1)
    direction = 1;
  if (digitalRead(LEFT) != 1)
    direction = 2;
  if (digitalRead(RIGHT) != 1)
    direction = 3;
}

