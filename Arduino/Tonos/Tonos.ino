//Incluimos el archivo con los tonos
#include "pitches.h"

// notas que se van a reproducir
int cancion[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// Tipo de notas
int tipoDeNota[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // hacer iteracion en las notas de la cancion
  for (int estaNota = 0; estaNota < 8; estaNota++) {

    // Para calcular la duracion de la nota
    // Dividimos un segundo entre el tipo de nota
    int duracionNota = 1000 / tipoDeNota[estaNota];
    tone(8, cancion[estaNota], duracionNota);

    // Para distinguir entre cada nota, hacemos una pequeña pausa
    // que sea el equivalente al 130% de la duracion de la nota
    int pausaEntreNotas = duracionNota * 1.30;
    delay(pausaEntreNotas);
    // Detenemos la reproduccion de las notas
    noTone(8);
  }
}

void loop() {
  // No hacemos nada aqui
}
