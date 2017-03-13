const int redPin = 2;
const int greenPin = 3;
const int bluePin = 4;
#define COMMON_ANODE
void setup() {

  // declarar los pines como salidas:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}
int i = 0;
void loop() {
  /*setColor(255, 0, 0);  // rojo
  delay(1000);
  setColor(0, 255, 0);  // verde
  delay(1000);
  setColor(0, 0, 255);  // azul
  delay(1000);
  setColor(255, 255, 0);  // amarillo
  delay(1000);
  setColor(80, 0, 80);  // morado
  delay(1000);
  setColor(0, 255, 255);  // aqua
  delay(1000);
  setColor(255,255,255);
  delay(2000);
  setColor(0,0,0);
  delay(500);
  setColor(32,32,32);
  delay(1000);*/
  //setColor(255,0,64)
  for (i=0;i<256;i++){
    setColor(i,255,255);
    delay(200);
  }
  setColor(0,0,0);
  delay(500);
}

void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
