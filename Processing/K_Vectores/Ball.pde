class Ball {
  // Variables Globales
  float rgb1 = 0;
  float rgb2 = 0;
  float rgb3 = 0;
  
  Vec3D loc = new Vec3D (0,0,0);
  Vec3D speed = new Vec3D (2,4,0);  
  Vec3D grav = new Vec3D (0,0.2,0);
  Vec3D lcolor = new Vec3D (0,0,0);  
  
  // Constructores
  Ball(Vec3D _loc, Vec3D _lcolor){
    loc = _loc;
    lcolor = _lcolor;
  }
  
  // Funciones
  void runBall(){
    displayBall();
    moveBall();
    bounceBall();
//    gravityBall();
  }    
  
  void displayBall(){
    fill(lcolor.x, lcolor.y, lcolor.z);
    ellipse(loc.x,loc.y,20,20);
  }
  
  void moveBall(){
    loc.addSelf(speed);
  }

  void bounceBall(){
    if(loc.x > width){
      speed.x = speed.x * -1;
    }
    if(loc.x < 0){
      speed.x = speed.x * -1;
    }
    if(loc.y > height){
      speed.y = speed.y * -1;
    }
    if(loc.y < 0){
      speed.y = speed.y * -1;
    }
  }

  void gravityBall(){
    speed.addSelf(grav);
  }
}
