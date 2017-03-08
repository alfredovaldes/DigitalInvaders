import toxi.geom.*;

// Declaracion
ArrayList myBallCollection;

void setup(){
  size(600,600);
  smooth();
  
  //Inicializacion
  myBallCollection = new ArrayList();
  // Se agregan el total de pelotas
  for(int i = 0; i < 1000; i++)
  {  
    Vec3D origin = new Vec3D (random(width),random(200),0);
    Vec3D bcolor = new Vec3D (random(0,255),random(0,255),random(0,255));
    Ball myBall = new Ball(origin, bcolor);
    myBallCollection.add(myBall);
  }
}

void draw(){
  background(0);
  // Ejecuta Funcionalidad
  for(int j = 0; j < myBallCollection.size(); j++)
  {
    Ball mB = (Ball)myBallCollection.get(j);
    mB.runBall();
//    println(mB.loc.x);
  }
}

