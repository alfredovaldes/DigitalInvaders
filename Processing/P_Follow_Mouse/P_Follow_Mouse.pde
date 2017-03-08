import toxi.geom.*;
Agent a;

void setup(){
  size(600,600);
  smooth();
  Vec3D startLoc = new Vec3D (width/2, height/2, 0);
  a = new Agent(startLoc);
}

void draw(){
  background(0);
  a.run();
}

