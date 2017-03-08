// Declaracion
Ball[] myBallCollection = new Ball [100];
color myBallColor;

void setup(){
  size(800,600);
  smooth();
  noFill();
  
  //Inicializacion
  for (int i = 0; i < myBallCollection.length; i++)
  {
    myBallColor = color(random(255),random(255),random(255));
    myBallCollection[i] = new Ball(random(width),random(height), myBallColor);
  }
}

void draw(){
  background(0);
  // Ejecuta Funcionalidad
  for (int i = 0; i < myBallCollection.length; i++)
  {
    if (i != 50)
    {
      myBallCollection[i].runBall();
    }
    else
    {
      myBallCollection[i].displayBall();
    }
  }
}

