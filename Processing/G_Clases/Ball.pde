class Ball {
  // Variables Globales
  float x = 0;
  float y = 0;
  color cColorPelota;
  float speedX = 2;
  float speedY = 3;
  float ancho = 0;
  float alto = 0;
  
  // Constructores
  Ball(float _x, float _y, color _color, float _ancho, float _alto){
    x = _x;
    y = _y;
    cColorPelota = _color;
    ancho = _ancho;
    alto = _alto;
  }
  
  // Funciones
  void runBall(){
    displayBall();
    moveBall();
    bounceBall();
//    gravityBall();
  }    
  
  void displayBall(){
    fill(cColorPelota);
    ellipse(x,y,ancho,alto);
  }

  void moveBall(){
    x += speedX;
    y += speedY;
    if (y > height+5)
    {
      y = limiteBottom;
    }
  }

  void bounceBall(){
    if(x < limiteLeft || x > limiteRight){
      speedX = speedX * -1;
    }
    if(y < limiteTop || y > limiteBottom){
      speedY = speedY * -1;
    }
  }
  
  void gravityBall(){
    speedY += 0.3;
  }
}
