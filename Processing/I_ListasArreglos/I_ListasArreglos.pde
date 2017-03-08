// Declaracion
ArrayList myBallCollection;

void setup(){
  frameRate(20);
  size(600,600);
  smooth();
  //Inicializacion
  myBallCollection = new ArrayList();
}

void draw(){
  background(0);
  Ball myBall = new Ball(random(0,width),random(0,150),255,255,255);
  // Se agrega pelotita por pelotita
  myBallCollection.add(myBall);
  // Ejecuta Funcionalidad
  for(int j = 0; j < myBallCollection.size(); j++)
  {
    Ball mB = (Ball)myBallCollection.get(j);
    mB.runBall();
  }
}

