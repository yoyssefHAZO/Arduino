//ultrasonic initializations
int trigFront=A0;
int echoFront=A1;
int trigLeft=A2;
int echoLeft=A3;
int trigRight=A4;
int echoRight=A5;
bool flag = 0;
int counter = 0;
#define space 20 /////////////////// this value will be changed according to the distance between the robot and the wall in which we want the robot to turn left or right

//Motor initializations
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;
int en1 = 10;
int en2 = 11;
#define speedd 100      ////////////////////this value must be changed it's the value of the speed of the motor when it turns right or left we must reduce the speed

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
  delay(1000);
  
  digitalWrite(IN1 , HIGH);
  digitalWrite(IN2 , LOW );
  digitalWrite(IN3 , HIGH );
  digitalWrite(IN4 , LOW );
  analogWrite(en1,200);
  analogWrite(en2,100);
  delay(1000);
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
  analogWrite(en1,255);
  analogWrite(en2,50);
}
void backward(){
  digitalWrite(IN1 , LOW);
  digitalWrite(IN2 , HIGH );
  digitalWrite(IN3 , LOW );
  digitalWrite(IN4 , HIGH );
  analogWrite(en1,170);
  analogWrite(en2,170);
}
void reverse(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(en1,250);
    analogWrite(en2,100);
}
void left(){
  digitalWrite(IN1 , LOW);
  digitalWrite(IN2 , LOW );
  digitalWrite(IN3 , HIGH );
  digitalWrite(IN4 , LOW );
  analogWrite(en1,80);
  analogWrite(en2,200);
}
void right(){
  digitalWrite(IN1 , HIGH);
  digitalWrite(IN2 , LOW );
  digitalWrite(IN3 , LOW );
  digitalWrite(IN4 , LOW );
  analogWrite(en1,250);
  analogWrite(en2,60);
}
void stopp(){
  digitalWrite(IN1 , LOW);
  digitalWrite(IN2 , LOW );
  digitalWrite(IN3 , LOW );
  digitalWrite(IN4 , LOW );
  analogWrite(en1,0);
  analogWrite(en2,0);
}

void loop(){
  if(FRONT()<space && LEFT()<space && RIGHT()<space) {
    reverse();
    delay(1000);
    while (1){
      if (FRONT()<5) {backward(); delay(500);}
      else if(FRONT()<space && LEFT()>space && RIGHT()<space) left(); // obstacle on front and right
      else if(FRONT()<space && LEFT()<space && RIGHT()>space) right(); // obstacle on front and left
      else if(FRONT()<space && LEFT()>space && RIGHT()>space) right(); // obstacle on front
      else if(FRONT()>space && LEFT()<space && RIGHT()>space) right(); //obstacle on left
     // else if(FRONT()>space && LEFT()>space && RIGHT()<space) left(); // obstacle on right
      else forward(); 
  }}
  //else if (FRONT()<10) {backward(); delay(500);}
  else if(FRONT()<space && LEFT()>space && RIGHT()<space) left(); // obstacle on front and right
  else if(FRONT()<space && LEFT()<space && RIGHT()>space) {right();delay(100);}// obstacle on front and left
  else if(FRONT()<space && LEFT()>space && RIGHT()>space)          // obstacle on front
  { flag=!flag; 
   if (flag == 1) {
    backward();
    delay(200);
    left();
   delay(500);}
   else
   {
    right();
   delay(500);}
   }
  else if(FRONT()>space && LEFT()>space && RIGHT()<space){      //obstacle on right
    counter++;
    if (counter ==1){
      left();
      delay(500);
    }
    else forward();
     
  }
  else if(FRONT()>space && LEFT()<space && RIGHT()>space) {right();delay(100);} //obstacle on left
  
  else forward();
}
