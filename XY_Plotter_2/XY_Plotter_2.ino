#include <AccelStepper.h>
#include <Servo.h>

Servo myservo; // 建立Servo物件，控制伺服馬達
int constantSpeed=6000;
int a=0;
int X_STEP_PIN = 8;
int X_DIR_PIN = 11;
int X_ENABLE_PIN = 4;
int X_MIN_PIN = A5;
int X_MAX_PIN = A4;

int Y_STEP_PIN = 12;
int Y_DIR_PIN = 13;
int Y_ENABLE_PIN = 4;
int Y_MIN_PIN = A10;
int Y_MAX_PIN = A9;

int Z_STEP_PIN = A2;
int Z_DIR_PIN = A3;
int Z_ENABLE_PIN = 4;
int Z_MIN_PIN = A1;
int Z_MAX_PIN = A0;
int Z_ENABLE_SERVO = 1;

AccelStepper stepperX(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN); // 13-PUL, 12-DIR PORT 3
AccelStepper stepperY(AccelStepper::DRIVER, Y_STEP_PIN, Y_DIR_PIN); // 13-PUL, 12-DIR PORT 3

void initMotor(){
  
  pinMode(X_MIN_PIN,OUTPUT);
  digitalWrite(X_MIN_PIN,HIGH);
  stepperX.setMaxSpeed(6000);stepperX.setAcceleration(6000); // set X stepper speed and acceleration
  stepperX.moveTo(-100000);

  while(digitalRead(X_MIN_PIN)) stepperX.run();
  stepperX.setCurrentPosition(0);
  stepperX.setMaxSpeed(6000);
  
  pinMode(Y_MIN_PIN,OUTPUT);
  digitalWrite(Y_MIN_PIN,HIGH);
  stepperY.setMaxSpeed(6000);stepperY.setAcceleration(6000); // set X stepper speed and acceleration
  stepperY.moveTo(-100000);

  while(digitalRead(Y_MIN_PIN)) stepperY.run();
  stepperY.setCurrentPosition(0);
  stepperY.setMaxSpeed(6000);
}

void circle(int x0, int y0, int r){
  double pi=3.14159;
   //Line(x0,y0);
   Line(x0+r*cos(0),y0+r*sin(0));
   penDown();
   for (int i=1;i<=360;i++)
   {
    Line(round(x0+r*cos(i*pi/180)),round(y0+r*sin(i*pi/180))) ;
   }
   Line(x0+r*cos(0),y0+r*sin(0));
   penUp();
   writeAck();
   
}

void penDown()
{
   myservo.write(0);//pen down
   delay(200);
}

void penUp()
{
   myservo.write(90); //pen up
   delay(200);
}




void Line(int a,int b)
{
  int xChange=a-stepperX.currentPosition();
  int yChange=b-stepperY.currentPosition();
  
  if ((xChange>=0) && (yChange>=0) && ((abs(xChange)-abs(yChange)) >=0))
  {Line1(xChange,yChange);}
  else if  ((xChange>=0) && (yChange>=0) && ((abs(xChange)-abs(yChange)) <0))
  {Line2(xChange,yChange);}
  else if ((xChange<0) && (yChange>=0) && ((abs(xChange)-abs(yChange)) <0))
  {Line3(xChange,yChange);}
  else if ((xChange<0) && (yChange>=0) && ((abs(xChange)-abs(yChange)) >=0))
  {Line4(xChange,yChange);}
  else if ((xChange<0) && (yChange<0) && ((abs(xChange)-abs(yChange)) >=0))
  {Line5(xChange,yChange);}
  else if ((xChange<0) && (yChange<0) && ((abs(xChange)-abs(yChange)) <0))
  {Line6(xChange,yChange);}
  else if ((xChange>=0) && (yChange<0) && ((abs(xChange)-abs(yChange)) <0))
  {Line7(xChange,yChange);}
  else if ((xChange>=0) && (yChange<0) && ((abs(xChange)-abs(yChange)) >=00))
  {Line8(xChange,yChange);}
  
  
}

void Line1(int xChange,int yChange){
  int delta_a=abs(xChange);
  int delta_b=abs(yChange); 
  
  int partial=2*delta_b-delta_a;
  for(int i=2;i<=delta_a;i=i+1){
    if (partial >=0)
      {partial=partial+2*delta_b-2*delta_a;}
     else
       {partial=partial+2*delta_b;}
       
     if (partial<0)
       Move11();
      else
       Move12();    
  }
}

void Line2(int xChange,int yChange){
  int delta_a=abs(yChange);
  int delta_b=abs(xChange); 
  
  int partial=2*delta_b-delta_a;
  for(int i=2;i<=delta_a;i=i+1){
    if (partial >=0)
      {partial=partial+2*delta_b-2*delta_a;}
     else
       {partial=partial+2*delta_b;}
       
     if (partial< 0)
       {Move21();}
      else
       {Move22();}
  }
}

void Line3(int xChange,int yChange){
  int delta_a=abs(yChange);
  int delta_b=abs(xChange); 
  
  int partial=2*delta_b-delta_a;
  for(int i=2;i<=delta_a;i=i+1){
    if (partial >=0)
      {partial=partial+2*delta_b-2*delta_a;}
     else
       {partial=partial+2*delta_b;}
       
     if (partial<0)
       Move31();
      else
       Move32();    
  }
}

void Line4(int xChange,int yChange){
  int delta_a=abs(xChange);
  int delta_b=abs(yChange); 
  
  int partial=2*delta_b-delta_a;
  for(int i=2;i<=delta_a;i=i+1){
    if (partial >=0)
      {partial=partial+2*delta_b-2*delta_a;}
     else
       {partial=partial+2*delta_b;}
       
     if (partial<0)
       Move41();
      else
       Move42();    
  }
}

void Line5(int xChange,int yChange){
  int delta_a=abs(xChange);
  int delta_b=abs(yChange); 
  
  int partial=2*delta_b-delta_a;
  for(int i=2;i<=delta_a;i=i+1){
    if (partial >=0)
      {partial=partial+2*delta_b-2*delta_a;}
     else
       {partial=partial+2*delta_b;}
       
     if (partial<0)
       Move51();
      else
       Move52();    
  }
}

void Line6(int xChange,int yChange){
  int delta_a=abs(yChange);
  int delta_b=abs(xChange); 
  
  int partial=2*delta_b-delta_a;
  for(int i=2;i<=delta_a;i=i+1){
    if (partial >=0)
      {partial=partial+2*delta_b-2*delta_a;}
     else
       {partial=partial+2*delta_b;}
        
     if (partial<0)
       Move61();
      else
       Move62();    
  }
}

void Line7(int xChange,int yChange){
  int delta_a=abs(yChange);
  int delta_b=abs(xChange); 
  
  int partial=2*delta_b-delta_a;
  for(int i=2;i<=delta_a;i=i+1){
    if (partial >=0)
      {partial=partial+2*delta_b-2*delta_a;}
     else
       {partial=partial+2*delta_b;}
       
     if (partial<0)
       Move71();
      else
       Move72();    
  }
}

void Line8(int xChange,int yChange){
  int delta_a=abs(xChange);
  int delta_b=abs(yChange); 
  
  int partial=2*delta_b-delta_a;
  for(int i=2;i<=delta_a;i=i+1){
    if (partial >=0)
      {partial=partial+2*delta_b-2*delta_a;}
     else
       {partial=partial+2*delta_b;}
       
     if (partial<0)
       Move81();
      else
       Move82();    
  }
}




void Move11() //x-inc
{
  int a=stepperX.currentPosition()+1;
  stepperX.moveTo(a);
  stepperX.setSpeed(constantSpeed);
  
  while (stepperX.currentPosition()<a)
  {
    stepperX.run();
  } 
}


void Move12() //x-inc; y-inc
{
  int a=stepperX.currentPosition()+1;
  int b=stepperY.currentPosition()+1; 
  stepperX.moveTo(a);
  stepperX.setSpeed(constantSpeed);
  stepperY.moveTo(b);
  stepperY.setSpeed(constantSpeed);
  
  while (stepperX.currentPosition()<a)
  {
    stepperX.run();
    stepperY.run();
  } 
}

void Move21() //x-inc
{
  int a=stepperY.currentPosition()+1;
  stepperY.moveTo(a);
  stepperY.setSpeed(constantSpeed);
  
  while (stepperY.currentPosition()<a)
  {
    stepperY.run();
  } 
}


void Move22() //x-inc; y-inc
{
  int b=stepperY.currentPosition()+1; 
  int a=stepperX.currentPosition()+1;
  stepperY.moveTo(b);
  stepperY.setSpeed(constantSpeed);
  stepperX.moveTo(a);
  stepperX.setSpeed(constantSpeed);

  while (stepperY.currentPosition()<b)
  {
    stepperY.run();
    stepperX.run();
  } 
}

void Move31() //x-inc
{
  int a=stepperY.currentPosition()+1;
  stepperY.moveTo(a);
  stepperY.setSpeed(constantSpeed);
  
  while (stepperY.currentPosition()<a)
  {
    stepperY.run();
  } 
}


void Move32() //y-inc; x-dec
{
  int b=stepperY.currentPosition()+1; 
  int a=stepperX.currentPosition()-1;
  stepperY.moveTo(b);
  stepperY.setSpeed(constantSpeed);
  stepperX.moveTo(a);
  stepperX.setSpeed(-constantSpeed);

  while (stepperY.currentPosition()<b)
  {
    stepperY.run();
    stepperX.run();
  } 
}

void Move41() //x-inc
{
  int a=stepperX.currentPosition()-1;
  stepperX.moveTo(a);
  stepperX.setSpeed(-constantSpeed);
  
  while (stepperX.currentPosition()>a)
  {
    stepperX.run();
  } 
}


void Move42() //x-inc; y-inc
{
  int a=stepperX.currentPosition()-1;
  int b=stepperY.currentPosition()+1; 
  
  stepperX.moveTo(a);
  stepperX.setSpeed(-constantSpeed);
  stepperY.moveTo(b);
  stepperY.setSpeed(constantSpeed);
  

  while (stepperX.currentPosition()>a)
  {
    stepperX.run();
    stepperY.run();
    
  } 
}

void Move51() //x-inc
{
  int a=stepperX.currentPosition()-1;
  stepperX.moveTo(a);
  stepperX.setSpeed(-constantSpeed);
  
  while (stepperX.currentPosition()>a)
  {
    stepperX.run();
  } 
}


void Move52() //x-inc; y-inc
{
  int a=stepperX.currentPosition()-1;
  int b=stepperY.currentPosition()-1; 
  
  stepperX.moveTo(a);
  stepperX.setSpeed(-constantSpeed);
  stepperY.moveTo(b);
  stepperX.setSpeed(-constantSpeed);
 

  while (stepperX.currentPosition()>a)
  {
    stepperX.run();
    stepperY.run();
  } 
}

void Move61() //x-inc
{
  int a=stepperY.currentPosition()-1;
  stepperY.moveTo(a);
  stepperY.setSpeed(-constantSpeed);
  
  while (stepperY.currentPosition()>a)
  {
    stepperY.run();
  } 
}


void Move62() //x-inc; y-inc
{
  int b=stepperY.currentPosition()-1; 
  int a=stepperX.currentPosition()-1;
  stepperY.moveTo(b);
  stepperY.setSpeed(-constantSpeed);
  stepperX.moveTo(a);
  stepperX.setSpeed(-constantSpeed);

  while (stepperY.currentPosition()>b)
  {
    stepperY.run();
    stepperX.run();
  } 
}

void Move71() //x-inc
{
  int a=stepperY.currentPosition()-1;
  stepperY.moveTo(a);
  stepperY.setSpeed(-constantSpeed);
  
  while (stepperY.currentPosition()>a)
  {
    stepperY.run();
  } 
}


void Move72() //x-inc; y-inc
{
  int b=stepperY.currentPosition()-1; 
  int a=stepperX.currentPosition()+1;
  stepperY.moveTo(b);
  stepperY.setSpeed(-constantSpeed);
  stepperX.moveTo(a);
  stepperX.setSpeed(constantSpeed);

  while (stepperY.currentPosition()>b)
  {
    stepperY.run();
    stepperX.run();
  } 
}

void Move81() //x-inc
{
  int a=stepperX.currentPosition()+1;
  stepperX.moveTo(a);
  stepperX.setSpeed(constantSpeed);
  
  while (stepperX.currentPosition()<a)
  {
    stepperX.run();
  } 
}


void Move82() //x-inc; y-inc
{
  int b=stepperX.currentPosition()+1; 
  int a=stepperY.currentPosition()-1;
  stepperX.moveTo(b);
  stepperX.setSpeed(constantSpeed);
  stepperY.moveTo(a);
  stepperY.setSpeed(-constantSpeed);

  while (stepperX.currentPosition()<b)
  {
    stepperX.run();
    stepperY.run();
  } 
}


void setup() {
  myservo.attach(Z_STEP_PIN,1000,1500); // 連接數位腳位9，伺服馬達的訊號線
  penUp();
  pinMode(X_STEP_PIN , OUTPUT);
  pinMode(X_DIR_PIN , OUTPUT);
  pinMode(X_ENABLE_PIN , OUTPUT);
  
  pinMode(Y_STEP_PIN , OUTPUT);
  pinMode(Y_DIR_PIN , OUTPUT);
  pinMode(Y_ENABLE_PIN , OUTPUT);
  
  pinMode(Z_STEP_PIN , OUTPUT);
  pinMode(Z_DIR_PIN , OUTPUT);
  pinMode(Z_ENABLE_PIN , OUTPUT);
  
  digitalWrite(X_ENABLE_PIN , LOW);
  digitalWrite(Y_ENABLE_PIN , LOW);
  digitalWrite(Z_ENABLE_PIN , LOW);
//  digitalWrite(A10,HIGH);
//  digitalWrite(A9,HIGH);
//  digitalWrite(A4,HIGH);
//  digitalWrite(A5,HIGH);
//  digitalWrite(A2,HIGH);
//  digitalWrite(A3,HIGH);
//  digitalWrite(A4,HIGH);
//  digitalWrite(A5,HIGH);
  Serial.begin(9600);
  Serial.println('a');
  initMotor();
  
  
}


void loop () {
//  int a=6000;
//  stepperX.moveTo(a);
//  while (stepperX.currentPosition()<a)
//  { 
//    stepperX.run();
//  }
//  stepperX.moveTo(0);
//  while (stepperX.currentPosition()>0)
//  {
//    stepperX.run();
//  }

//  int a=30000;
//  stepperY.moveTo(a);
//  while (stepperY.currentPosition()<a)
//  { 
//    stepperY.run();
//  }
//  stepperY.moveTo(0);
//  while (stepperY.currentPosition()>0)
//  {
//    stepperY.run();
//  }

//  for(int i = 0; i <= 90; i+=1){
//    myservo.write(i); // 使用write，傳入角度，從0度轉到180度
//    delay(20);
//  }
//  for(int i = 90; i >= 0; i-=1){
//    myservo.write(i);// 使用write，傳入角度，從180度轉到0度
//    delay(20);
//  }

//myservo.write(90);
//delay(2000);
//myservo.write(0);
//delay(2000);
  readComand();
  //circle(10000,10000,5000);
}


void readComand(){
  char a='b';
  int xPos=0;
  int yPos=0;
  int radius=0;
  while (a!='a')
  {
    a=Serial.read();
    
    if (a=='D')
    {
      penDown();
      writeAck();
    }
    if (a=='U')
    {
      penUp();
      writeAck();
    }
    if (a=='L')
    {
        Serial.read();
        xPos=Serial.parseInt();
        Serial.read();
        yPos=Serial.parseInt();
        Line(xPos,yPos);
        writeAck();
    }
    if (a=='C')
    {
        Serial.read();
        xPos=Serial.parseInt();
        Serial.read();
        yPos=Serial.parseInt();
        Serial.read();
        radius=Serial.parseInt();
        circle(xPos,yPos,radius);
    }
  }
}

void writeAck(){
    Serial.println('x');
}

