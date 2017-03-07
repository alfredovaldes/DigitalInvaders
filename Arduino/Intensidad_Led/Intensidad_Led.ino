// Terminal central del potenciometro al pin 3
// terminales de las orillas a 5V y GND
const int analogPin = 3;
//LED en el pin 10
const int ledPin = 10;
// variable para guardar el valor de la lectura
int val = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  val = analogRead(analogPin);    // Leemos el pin de entrada
  analogWrite(ledPin, val);       // Y le asignamos el valor al LED
}
