class Agent{
  Vec3D loc;
  Vec3D vel = new Vec3D(0,0,0);
  Vec3D acc = new Vec3D(0,0,0);
  
  Agent(Vec3D _loc){
    loc = _loc;
  }
  
  void run(){
    display();
    update();
    followMouse();
  }
  
  void display(){
    stroke(0);
    fill(255);
    ellipse(loc.x,loc.y,20,20);
  }
  
  void update(){
    vel.addSelf(acc);
    vel.limit(5);
    loc.addSelf(vel);
    acc = new Vec3D(0,0,0);
  }
  
  
  void followMouse(){
    Vec3D target = new Vec3D(mouseX, mouseY, 0);
    Vec3D diff = target.sub(loc);
    float distance = diff.magnitude();
    diff.normalize();
    diff.scaleSelf(distance/2);
    acc.addSelf(diff);
  }
}
