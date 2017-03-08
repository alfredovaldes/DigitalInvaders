class Ball {
  // Variables Globales
  float xIni = 0;
  float x = 0;
  float y = 0;
  float speedX = 2;
  float speedY = .5;
  float rgb1 = 0;
  float rgb2 = 0;
  float rgb3 = 0;
  float desviacion = 45;
  
  // Constructores
  Ball(float _x, float _y, float _rgb1, float _rgb2, float _rgb3){
    xIni = _x;
    x = _x;
    y = _y;
    rgb1 = _rgb1;
    rgb2 = _rgb2;
    rgb3 = _rgb3;
  }
  
  // Funciones
  void runBall(){
    displayBall();
    moveBall();
    bounceBall();
//    gravityBall();
  }    
  
  void displayBall(){
    fill(rgb1, rgb2, rgb3);
    ellipse(x,y,10,7);
  }
  
  void moveBall(){
    x += speedX;
    y += speedY;
  }

  void bounceBall(){
    if(x > (xIni+desviacion)){
      speedX = speedX * -1;
    }
    if(x < (xIni-desviacion)){
      speedX = speedX * -1;
    }
/*    
    if(y > height){
      speedY = speedY * -1;
    }
    if(y < 0){
      speedY = speedY * -1;
    }
*/
  }
  
  void gravityBall(){
    speedY += 0.2;
  }

}
