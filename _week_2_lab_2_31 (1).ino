//Stefan Saladino
//Jan 19 2023

// C++ code

//Red pin in 9, green pin in 10, blue pin in 11
//onTime == 143, will take ~ 1 second to complete all 7 colours
int RGBRedPin = 9;
int RGBGreenPin = 10;
int RGBBluePin = 11;
int onTime= 143;
int i = 1;


void setup()
{
 Serial.begin(9600);
 pinMode(RGBRedPin, OUTPUT);
 pinMode(RGBGreenPin, OUTPUT);
 pinMode(RGBBluePin, OUTPUT);
}

//cycle through loop 10 times
//onTime*i ensures consistent progression from cycle 1 to 10
//i.e. 143*7*1 = 1001 OR ~ 1 second on the first loop
//i.e. 143*10*7=10010 OR ~ 10 seconds on the final loop 
void loop()
{  
for (int i=1; i<=10; i++)
{
//Display Red
digitalWrite(RGBRedPin, HIGH); //Turn on RED
delay(onTime*i); //wait 143 milliseconds * value of i in loop
digitalWrite(RGBRedPin, LOW); //Turn off Red
//Display Green
digitalWrite(RGBGreenPin, HIGH); //Turn on green
delay(onTime*i); //wait 143 milliseconds * value of i in loop
digitalWrite(RGBGreenPin, LOW); //Turn off green
//Display Blue
digitalWrite(RGBBluePin, HIGH); //Turn on blue
delay(onTime*i);//wait 143 milliseconds * value of i in loop 
digitalWrite(RGBBluePin, LOW); //Turn off blue
//Display Magenta (Red + Blue)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBBluePin, HIGH); //Turn on blue
delay(onTime*i);//wait 143 milliseconds * value of i in loop 
digitalWrite(RGBRedPin, LOW); //Turn off Red
digitalWrite(RGBBluePin, LOW); //Turn on RED
//Display Yellow (Red + Green)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBGreenPin, HIGH); //Turn on green
delay(onTime*i);//wait 143 milliseconds * value of i in loop
digitalWrite(RGBRedPin, LOW); //Turn off Red
digitalWrite(RGBGreenPin, LOW); //Turn off green
//Display Cyan (Blue + Green)
digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
delay(onTime*i);//wait 143 milliseconds * value of i in loop
digitalWrite(RGBBluePin, LOW); //Turn off BLUE
digitalWrite(RGBGreenPin, LOW); //Turn off GREEN
//Display White (Red + Blue + Green)
digitalWrite(RGBRedPin, HIGH); //Turn on RED
digitalWrite(RGBBluePin, HIGH); //Turn on BLUE
digitalWrite(RGBGreenPin, HIGH); //Turn on GREEN
delay(onTime*i);//wait 143 milliseconds * value of i in loop
digitalWrite(RGBRedPin, LOW); //Turn off RED
digitalWrite(RGBBluePin, LOW); //Turn off BLUE
digitalWrite(RGBGreenPin, LOW); //Turn off GREEN
  
//if-else loop will return the if condition if it is true
//if condition is not met, the else statement will be returned
//if elapsed time is more or less than one second long, the monitor will print "seconds" (plural)
//if elapsed time is between 1000-1999 milliseconds, an integer of 1 will be returned, which requires the singular "second"  
Serial.print("Elapsed time this loop: ");
Serial.print((onTime*i*7)/1000);
if
(onTime*i*7>1999 || onTime*i*7<999)
Serial.println(" seconds");
else
Serial.println(" second");
}
 

delay(5000);//once cycle is completed 10 times, there is a 5 second delay before loop repeats
}

  
