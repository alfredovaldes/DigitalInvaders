class Ball {
  // Variables Globales
  float x = 0;
  float y = 0;
  float speedX = 3;
  float speedY = 2;
  color colorBall;
  
  // Constructores
  Ball(float _x, float _y, color _colorBall){
    x = _x;
    y = _y;
    colorBall = _colorBall;
  }
  
  // Funciones
  void runBall(){
    displayBall();
    moveBall();
    bounceBall();
//    gravityBall();
  }    
  
  void displayBall(){
//    fill(colorBall);
    stroke(colorBall);
    ellipse(x,y,random(10,20),random(10,20));
  }
  
  void moveBall(){
    x += speedX;
    y += speedY;
  }

  void bounceBall(){
    if(x > width){
      speedX = speedX * -1;
    }
    if(x < 0){
      speedX = speedX * -1;
    }
    if(y > height){
      speedY = speedY * -1;
    }
    if(y < 0){
      speedY = speedY * -1;
    }
  }
  
  void gravityBall(){
    speedY += 0.2;
  }

}
