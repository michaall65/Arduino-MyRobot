#define TrigPin 3
#define EchoPin 2
#define Motor1Backward 7//Right=1
#define Motor1Forward 8
#define Motor2Backward 6//Left=2
#define Motor2Forward 9

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(TrigPin,OUTPUT);
  pinMode(Motor1Backward, OUTPUT);
  pinMode(Motor2Backward, OUTPUT);
  pinMode(Motor1Forward, OUTPUT);
  pinMode(Motor2Forward, OUTPUT);
  pinMode(EchoPin,INPUT);
  Serial.begin(9600);

}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  duration = pulseIn(EchoPin,HIGH);
  distance = duration*0.034/2;// distance = t[s]*0.0001*340[m/s]/2
  if(distance<=10)
  {
    stop_robot();
  }
  else if(distance>=20x )
  {  
    go_forward();
  }
  else if(distance<20)
  {
    avoid_obstacle();
    
  }
}
void go_forward()
{
   digitalWrite(Motor1Forward,HIGH);
   digitalWrite(Motor2Forward,HIGH);
   digitalWrite(Motor1Backward,LOW);
   digitalWrite(Motor2Backward,LOW);
}
void rotate_left()
{
    digitalWrite(Motor1Forward,LOW);
    digitalWrite(Motor2Forward,HIGH);
    digitalWrite(Motor1Backward,HIGH);
    digitalWrite(Motor2Backward,LOW);
}
void rotate_right()
{
    digitalWrite(Motor1Forward,HIGH);
    digitalWrite(Motor2Forward,LOW);
    digitalWrite(Motor1Backward,LOW);
    digitalWrite(Motor2Backward,HIGH);
}
void stop_robot()
{
    digitalWrite(Motor1Forward,LOW);
    digitalWrite(Motor2Forward,LOW);
    digitalWrite(Motor1Backward,LOW);
    digitalWrite(Motor2Backward,LOW);
}
void go_backward()
{
    digitalWrite(Motor1Forward,LOW);
    digitalWrite(Motor2Forward,LOW);
    digitalWrite(Motor1Backward,HIGH);
    digitalWrite(Motor2Backward,HIGH);
}
void avoid_obstacle()
{
    stop_robot();
    delay(1000);
    go_backward();
    delay(500);
    rotate_right();
    delay(500);
    go_forward();
    delay(1000);
    rotate_left();
    delay(500);
    go_forward();
}
