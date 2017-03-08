// Declaracion
int limiteTop, limiteBottom, limiteLeft, limiteRight;
color colorPelota;

int diametro = 20;
Ball miPelota1;

void setup(){
  size(600,400);
  limiteTop = diametro/2; limiteBottom = height - (diametro/2); limiteLeft = diametro/2; limiteRight = width - (diametro/2); 
  smooth(); noStroke();
  colorPelota = color(255,255,0);
  miPelota1 = new Ball(random(limiteLeft+diametro, limiteRight-diametro),
                       random(limiteTop+diametro, limiteBottom/5),colorPelota,diametro,diametro);
}

void draw(){
  background(0);
  miPelota1.runBall();
}

