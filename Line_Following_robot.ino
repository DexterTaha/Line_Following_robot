int lMotFwd=12; 
int rMotFwd=6;
int lMotRev=13;
int rMotRev=7; 

int onblack= 100;  // reading for black line from sensor is less than this
int onWhite= 700; // reading for white line is greater than this

void setup() {

  // pinMode(A0,INPUT); 
  pinMode(A1,INPUT);  //extreme left sensor
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);  // middle sensor
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);  // extreme right sensor
    
  pinMode(lMotFwd,OUTPUT); 
  pinMode(rMotFwd,OUTPUT);
  pinMode(lMotRev,OUTPUT);  
  pinMode(rMotRev,OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

}
