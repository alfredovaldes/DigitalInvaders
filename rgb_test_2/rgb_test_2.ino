const int redPin = 2;
const int greenPin = 3;
const int bluePin = 4;

void setup() {
  // inicializar serial:
  Serial.begin(9600);
  // declarar los pines como salidas:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  // Si el puerto serial esta disponible:
  while (Serial.available() > 0) {

    // busca el siguiente numero entero dentro de la cadena que va a llegar
    int r = Serial.parseInt();
    // otra vez:
    int g = Serial.parseInt();
    // otra vez:
    int b = Serial.parseInt();

    // buscar el salto de linea, que simboliza el final
    // de la cadena:
    if (Serial.read() == '\n') {
      // mantener los valores entre 0 y 255 e invertirlos
      // si se va a usar un led de catodo comun solo poner 
      //"constrain(color, 0, 255);"
      r = 255 - constrain(r, 0, 255);
      g = 255 - constrain(g, 0, 255);
      b = 255 - constrain(b, 0, 255);
      setColor(r,g,b);
      // imprimir los valores en la termnial serial en formato HEX
      Serial.println("#######################");
      Serial.println("  El led es de color: ");
      Serial.print("      "); 
      Serial.print(r, HEX);
      Serial.print(" ");
      Serial.print(g, HEX);
      Serial.print(" ");
      Serial.print(b, HEX);
      Serial.println("       ");
      Serial.println("#######################");
    }
  }
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
