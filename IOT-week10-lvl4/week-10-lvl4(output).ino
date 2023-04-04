#include <Wire.h>
#include <Servo.h>
int btn1=3;
int btn2=2;
int data=0;

void setup() {//setup runs once
  Wire.begin();//initializing sender
  pinMode(btn1, INPUT);// Set buttonPin as input
  pinMode(btn2, INPUT);// Set buttonPin2 as input
  Serial.begin(9600);// join i2c bus (address optional for master)
}

void loop(){
if (digitalRead(btn1)==HIGH){//check to see if button one is pressed
  if(data<4){//the following block of code will execute if btn 1 is pressed while data is less than 4
  data++;//incrementing data by 1
  Serial.println(data);//for reference
  Wire.beginTransmission(2);//transmit the new value to Arduino(2) 
    Wire.write(data);//sending the value of data to arduino 2      
    Wire.endTransmission(); //end transmission   
    delay(500);
  }
  
  else if(data>=4){//the following will all be executed if the button is pressed 
  //data drops by 1 with a delay of .5 seconds
  //the colour will change accordingly with the positions of the servo (this can be seen in arduino 2 code)
  data=3;
  	Wire.beginTransmission(2);
    Wire.write(data);      
    Wire.endTransmission();   
    delay(500);
    
  data=2;
  	Wire.beginTransmission(2);
    Wire.write(data);      
    Wire.endTransmission();    
    delay(500);
    
  data=1;
  	Wire.beginTransmission(2);
    Wire.write(data);      
    Wire.endTransmission();   
    delay(500);  
    
  data=0;
  	Wire.beginTransmission(2); 
    Wire.write(data);      
    Wire.endTransmission();  
    delay(500);
  }  
  }  

//the following is similar to the button 1 code, just done in reverse
else if (digitalRead(btn2)==HIGH){
  if(data>0){
  	data--;
  	Serial.println(data);
  	Wire.beginTransmission(2);
    Wire.write(data);      
    Wire.endTransmission();    
    delay(500);
  }
  
  else if(data==0){
  data=1;
  	Wire.beginTransmission(2);
    Wire.write(data);      
    Wire.endTransmission();  
    delay(500);
    
  data=2;
  	Wire.beginTransmission(2);
    Wire.write(data);      
    Wire.endTransmission();  
    delay(500);
    
  data=3;
  	Wire.beginTransmission(2);
    Wire.write(data);      
    Wire.endTransmission();    
    delay(500);  
    
  data=4;
  	Wire.beginTransmission(2);
    Wire.write(data);      
    Wire.endTransmission(); 
    delay(500);
  }  
}  
}
  

