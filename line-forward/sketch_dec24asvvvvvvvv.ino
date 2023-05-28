//////////////////////////////////////////////////////////////////////////////******/*****//\\******/*****//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////******/*****//***\\******/*****//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////******/*****//******\\******/*****//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////******/*****//*********\\******/*****//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////******/*****//************\\******/*****//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////******/*****//***************\\******/*****//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////******/*****//by youssef team //******/*****//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////******/*****\\***************//******/*****///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////******/*****\\************//******/*****/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////******/*****\\*********//******/*****//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////******/*****\\******//******/*****///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////******/*****\\***//******/*****////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////******/*****\\//******/*****/////////////////////////////////////////////////////////////////////
int M_A1 = 2; //motor a = +
int M_A2 = 3; //motor a = -

int M_B1 = 4; //motor b = -
int M_B2 = 5; //motor b = +
char state='n';
char a='a';
int R_S = 8; //sincer R
int S_S = 7; //sincer S
int L_S = 6; //sincer L

void setup() 
{
Serial.begin(9600);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);

pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT);
pinMode(M_A2, OUTPUT);
pinMode(12,OUTPUT);//puzer
pinMode(9,INPUT);//fire
pinMode(L_S, INPUT);
pinMode(S_S, INPUT);
pinMode(R_S, INPUT);
}
void loop()
{ 
     if(digitalRead(9)==1)
   {
    Stop();
    tone(12,1000,1000);
   }

   analogWrite(10,150);
   analogWrite(11,150);
////////////////////////////////////////////////////////////////state n
   if(state=='n'){
    
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();}

if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();}
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) ==0)&&(digitalRead(R_S) == 0)) {turnLeft();}

if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();state='m';}
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}
//if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){ state='c';  forword();}

//if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){
//  state='c';
//
//  }
}
//////////////////////////////////////////////////////////////////////////state c
if (state=='c')
{
  if(digitalRead(R_S)==0&&digitalRead(S_S)==0&&digitalRead(L_S)==0)
  {
    a='b';
    forword();
  } 
    if(digitalRead(R_S)==1&&digitalRead(S_S)==1&&digitalRead(R_S)==1&&a=='b')
  {
    forword();
    state='e';
  }
}
///////////////////////////////////////////////////////////////////state e
if (state=='e')
{

      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();}
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();}
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) ==0)&&(digitalRead(R_S) == 0)) {turnLeft();}
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();}
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){ Stop();}
}
///////////////////////////////////////////////////////////////////state m
if (state=='m')
{
  if((digitalRead(L_S) == 0))
  {
    forword();
   }
   else
   {
    turnRight();
    state='y';
    }
}
///////////////////////////////////////////////////////////////////state y
if (state=='y')
{

      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();}
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();}
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) ==0)&&(digitalRead(R_S) == 0)) {turnLeft();}
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();}
      if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}
      if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){ state='c';  forword();}
}

}




void forword(){
digitalWrite(M_A1, HIGH);
digitalWrite(M_A2,LOW );
digitalWrite(M_B1, LOW);
digitalWrite(M_B2,HIGH );  
}


void turnRight(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, HIGH);  
}

void turnLeft(){
digitalWrite(M_A1, HIGH);
digitalWrite(M_A2,LOW );
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}

void Stop(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}
