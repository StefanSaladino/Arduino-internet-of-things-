//include wire library
#include <Wire.h>
//include servo library
#include <Servo.h>
Servo myservo;
int data;
int RGBRedPin = 9;//initializing rgb pins
int RGBGreenPin = 11;
int RGBBluePin = 10;
int value;

//the following are functions for the RGB light
void purpleOn()
{
  analogWrite(RGBRedPin, 255);
  analogWrite(RGBGreenPin, 0);
  analogWrite(RGBBluePin, 255);
}

void yellowOn()
{
  analogWrite(RGBRedPin, 255);
  analogWrite(RGBGreenPin, 255);
  analogWrite(RGBBluePin, 0);
}

void redOn()
{
  analogWrite(RGBRedPin, 255);
  analogWrite(RGBGreenPin, 0);
  analogWrite(RGBBluePin, 0);
}

void greenOn()
{
  analogWrite(RGBRedPin, 0);
  analogWrite(RGBGreenPin, 255);
  analogWrite(RGBBluePin, 0);
}

void blueOn()
{
  analogWrite(RGBRedPin, 0);
  analogWrite(RGBGreenPin, 0);
  analogWrite(RGBBluePin, 255);
}

void lightsOut()
{
  analogWrite(RGBRedPin, 0);
  analogWrite(RGBGreenPin, 0);
  analogWrite(RGBBluePin, 0);}

//setup runs once
void setup(){
  pinMode(RGBRedPin, OUTPUT);//setup the Red pin of LED to an OUTPUT pin
  pinMode(RGBGreenPin, OUTPUT);//setup the Green pin of LED to an OUTPUT pin
  pinMode(RGBBluePin, OUTPUT);//setup the blue pin of LED to an OUTPUT pin
  myservo.attach(4);
  myservo.write(0);// initializing servo position
  Wire.begin(2);// join i2c bus with address #2
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);   
}

void loop() {
  Serial.println(value);
  //servo will position itself according to the value variable
  myservo.write(value);
  
  //the value variable determines the colour of the light 
  if(value==0){
  redOn();
  }
  
  else if(value==45){
    purpleOn();	
  }
  
  else if(value==90){
    yellowOn();
  }
  
  else if(value==135){
    blueOn();
  }
  
  else if(value==180){
  	greenOn();
  }

}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  int data = Wire.read();//read the value from input arduino
  value=(data)*45;/*data (sent from the input arduino is taken and multiplied by 45
  this is done to set the position of the servo accordingly*/
  
}

