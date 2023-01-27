// C++ code
//Lab 3 level 1

int rotationPin= A0;// A0-> it is now an analog pin
int data = 0;// reads position of rotation pin
int RGBRedPin = 11;
int RGBGreenPin = 9;
int RGBBluePin = 10;
char incomingByte;
int i=1;



void setup()
{
  Serial.begin(9600);
  pinMode(rotationPin, INPUT);
  pinMode(RGBRedPin, OUTPUT);
  pinMode(RGBGreenPin, OUTPUT);
  pinMode(RGBBluePin, OUTPUT);
  Serial.println("Input colour selection: ");
}

/*rather than resetting each RGB value to zero each time you want
to turn the lights off, this function will allow a shortcut to turn
the lights off 
*/
void lightOff()
{
  analogWrite(RGBRedPin, 0);
  analogWrite(RGBGreenPin, 0);
  analogWrite(RGBBluePin, 0);
}  
/*the following functions [colour]On(), allows for a quicker way to
set the RGB light to the colour of your choosing
*/

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

void yellowOn()
{
  analogWrite(RGBRedPin, 255);
  analogWrite(RGBGreenPin, 255);
  analogWrite(RGBBluePin, 0);
}

void cyanOn()
{
  analogWrite(RGBRedPin, 0);
  analogWrite(RGBGreenPin, 255);
  analogWrite(RGBBluePin, 255);
}

void whiteOn()
{
  analogWrite(RGBRedPin, 255);
  analogWrite(RGBGreenPin, 255);
  analogWrite(RGBBluePin, 255);
}

void magentaOn()
{
  analogWrite(RGBRedPin, 255);
  analogWrite(RGBGreenPin, 0);
  analogWrite(RGBBluePin, 255);
}

//blink functions are a quicker way of turning the light on and off
/*Rather than telling the RGB to reset, the blink function will reset
it automatically
*/
/*When the user inputs their light choice, the light will reset rather 
than get stuck on
*/
void blinkRed()
{
  redOn();
  delay(500);
  lightOff();
} 

void blinkBlue()
{
  blueOn();
  delay(500);
  lightOff();
} 

void blinkGreen()
{
  greenOn();
  delay(500);
  lightOff();
} 

void blinkCyan()
{
  cyanOn();
  delay(500);
  lightOff();
} 

void blinkWhite()
{
  whiteOn();
  delay(500);
  lightOff();
} 

void blinkMagenta()
{
  magentaOn();
  delay(500);
  lightOff();
} 

void blinkYellow()
{
  yellowOn();
  delay(500);
  lightOff();
} 













 


void loop()
{
//telling the monitor to read the user input
  Serial.available();
    incomingByte = Serial.read();
  
  /*when the user enters the corresponding input, the blink 
  function will run
  */
  // using a switch with breaks
  switch (incomingByte)
  {           
  case 'R':
  {
   blinkRed();
    break;
  } 
  
  case 'B':
  {
   blinkBlue();
    break;
  }
  
  case 'G':
  {
    blinkGreen();
    break;
  }  
  
  case 'W':
  {
    blinkWhite();
    break;
  }
  
  case 'M':
  {
    blinkMagenta();
    break;
  }
  
  case 'Y':
  {
    blinkYellow();
    break;
  }
  
  case 'C':
  {
    blinkCyan();
    break;
  }
  
  default:
  {
  	Serial.println("Invalid character selected.");
  	break;
  }  

  }
   delay(100);
}
  



  
