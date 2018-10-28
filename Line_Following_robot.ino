const int lMotFwd=12; 
const int rMotFwd=6;
const int lMotRev=13;
const int rMotRev=7; 

const int onblack= 100;  // reading for black line from sensor is less than this
const int onWhite= 700; // reading for white line is greater than this

void setup() {

  Serial.begin(9600);
  
  // pinMode(A0,INPUT);  
  pinMode(A1,INPUT);  //extreme left sensor
  pinMode(A2,INPUT);  //left
  pinMode(A3,INPUT);  // middle sensor
  pinMode(A4,INPUT);   // right
  pinMode(A5,INPUT);  // extreme right sensor
    
  pinMode(lMotFwd,OUTPUT); 
  pinMode(rMotFwd,OUTPUT);
  pinMode(lMotRev,OUTPUT);  
  pinMode(rMotRev,OUTPUT); 

 

}


bool isOnBlack(int sensor){

if( sensor>=onblack)
return true;
else
return false;
}


bool isOnWhite(int sensor){
  if(sensor<=onWhite)
  return true;
  else
  return false;
}




void moveForward()
{
  digitalWrite(lMotFwd,HIGH);
  digitalWrite(rMotFwd,HIGH);
}

void turnLeft()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotFwd,HIGH);
}


void turnRight()
{
  digitalWrite(lMotFwd,HIGH);
  digitalWrite(rMotFwd,LOW);
}

void turnCircle()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotFwd,LOW);
  digitalWrite(lMotRev,HIGH);
  digitalWrite(rMotFwd,HIGH);
}

void Stop()
{

digitalWrite(lMotFwd,LOW);
digitalWrite(rMotFwd,LOW);
digitalWrite(lMotRev,LOW);
digitalWrite(rMotRev,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
int sensor1=analogRead(A1);//sensor1  Extreme Left
int sensor2=analogRead(A2);//sensor2 
int sensor3=analogRead(A3);//sensor3  middle
int sensor4=analogRead(A4);//sensor4  
int sensor5=analogRead(A5);//sensor5   Extreme right
Serial.print("extreme Left: ");
Serial.print(sensor1);
Serial.print("\t lower left: ");
Serial.print(sensor2);
Serial.print("\t middle: ");
Serial.print(sensor3);
Serial.print("\t lowerRight: ");
Serial.print(sensor4);
Serial.print("\t Extreme Right: ");
Serial.println(sensor5);


if( isOnBlack(sensor1)){
  turnLeft();
}else{

  if(isOnBlack(sensor3)&&isOnWhite(sensor1)){
    moveForward();
  }else

  if( isOnWhite(sensor1)&& isOnWhite(sensor3)&& isOnBlack(sensor5)  ){
    turnRight();
  }else
  
  if(isOnBlack(sensor2)){
    turnLeft();
  }else
  if(isOnBlack(sensor4)){
    turnRight();
  }else
  if( isOnWhite(sensor1) && isOnWhite(sensor2) && isOnWhite(sensor3) && isOnWhite(sensor4) && isOnWhite(sensor5) ){
    turnCircle();   
  }


}


}
