// Constantes con los numeros de pin que vamos a utilizar

const int botonPin = 2;     // El boton va en el pin 2
const int ledPin =  13;      // El LED va en el pin 13

// variables que van a cambiar
int botonEstado = 0;         // variable para leer el estado del boton

void setup() {
  // Declarar el pin del LED como salida
  pinMode(ledPin, OUTPUT);
  // Declarar el pin del boton como entrada
  pinMode(botonPin, INPUT);
}

void loop() {
  // Leemos el estado del boton
  botonEstado = digitalRead(botonPin);

  // Preguntamos si se presiono el boton
  if (botonEstado == HIGH) {
    // Encendemos el LED
    digitalWrite(ledPin, HIGH);
  } else {//Si el boton no esta presionado
    // apagamos el LED
    digitalWrite(ledPin, LOW);
  }
}
