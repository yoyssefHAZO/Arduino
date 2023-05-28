//ultrasonic initializations
int trigFront=11;
int echoFront=12;
int trigLeft=2;
int echoLeft=13;
int trigRight=3;
int echoRight=4;

#define space 26 /////////////////// this value will be changed according to the distance between the robot and the wall in which we want the robot to turn left or right

//Motor initializations
int IN1 = 5;
int IN2 = 6;
int IN3 = 7;
int IN4 = 8;
int en1 = 10;
int en2 = 9;
#define speedd 100      ////////////////////this value must be changed it's the value of the speed of the motor when it turns right or left we must reduce the speed

//Temperature sensor
int temp= A0;
//Flame sensor
int flam= A1; // Here we must change it to a digital pin but there're not enough pins
//Buzzer
//int buz=2;

void setup(){
  Serial.begin(9600);
  pinMode(trigFront,OUTPUT);
  pinMode(echoFront,INPUT);
  pinMode(trigLeft,OUTPUT);
  pinMode(echoLeft,INPUT);
  pinMode(trigRight,OUTPUT);
  pinMode(echoRight,INPUT);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);

  //pinMode(temp,INPUT);
  //pinMode(flam,INPUT);
}
//Ultrasonic code
long FRONT(){
  digitalWrite(trigFront, LOW );
  delayMicroseconds(2);
  digitalWrite(trigFront, HIGH );
  delayMicroseconds(10);
  digitalWrite(trigFront, LOW);
  long duration = pulseIn(echoFront,HIGH);
  long distance = (duration/2) * 0.0343;
  delay(5);
  return distance;
}
long LEFT(){
  digitalWrite(trigLeft, LOW );
  delayMicroseconds(2);
  digitalWrite(trigLeft, HIGH );
  delayMicroseconds(10);
  digitalWrite(trigLeft, LOW);
  long duration = pulseIn(echoLeft,HIGH);
  long distance = (duration/2) * 0.0343;
  delay(5);
  return distance;
}
long RIGHT(){
  digitalWrite(trigRight, LOW );
  delayMicroseconds(2);
  digitalWrite(trigRight, HIGH );
  delayMicroseconds(10);
  digitalWrite(trigRight, LOW);
  long duration = pulseIn(echoRight,HIGH);
  long distance = (duration/2) * 0.0343;
  delay(5);
  return distance;
}

//Motor direction code
void forward() {
  digitalWrite(IN1 , HIGH);
  digitalWrite(IN2 , LOW );
  digitalWrite(IN3 , HIGH );
  digitalWrite(IN4 , LOW );
  analogWrite(en1,250);
  analogWrite(en2,170);
}
void backward(){
  digitalWrite(IN1 , LOW);
  digitalWrite(IN2 , HIGH );
  digitalWrite(IN3 , LOW );
  digitalWrite(IN4 , HIGH );
  analogWrite(en1,250);
  analogWrite(en2,170);
}
void reverse(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(en1,250);
    analogWrite(en2,170);
}
void left(){
  digitalWrite(IN1 , LOW);
  digitalWrite(IN2 , LOW );
  digitalWrite(IN3 , HIGH );
  digitalWrite(IN4 , LOW );
  analogWrite(en1,0);
  analogWrite(en2,150);
}
void right(){
  digitalWrite(IN1 , HIGH);
  digitalWrite(IN2 , LOW );
  digitalWrite(IN3 , LOW );
  digitalWrite(IN4 , LOW );
  analogWrite(en1,200);
  analogWrite(en2,0);
}
void stopp(){
  digitalWrite(IN1 , LOW);
  digitalWrite(IN2 , LOW );
  digitalWrite(IN3 , LOW );
  digitalWrite(IN4 , LOW );
  analogWrite(en1,0);
  analogWrite(en2,0);
}
////////////////////////////////
//temp sensor
void loop(){
  if(FRONT()<space && LEFT()<space && RIGHT()<space) {reverse(); delay(2000);} //obstacle on the 3 sides
  
  else if(FRONT()<space && LEFT()>space && RIGHT()<space) left(); // obstacle on front and right
  else if(FRONT()<space && LEFT()<space && RIGHT()>space) right(); // obstacle on front and left
  else if(FRONT()<space && LEFT()>space && RIGHT()>space) right(); // obstacle on front
  else if(FRONT()>space && LEFT()<space && RIGHT()>space) right(); //obstacle on left
  //else if(FRONT()>space && LEFT()>space && RIGHT()<space) left(); // obstacle on right
  else forward(); 
  
}
