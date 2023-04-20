//Stefan Saladino 200551988
//C++ Code
//April 20, 2023


//piezo buzzer library
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978


unsigned long previousTime;
int leds[] = {13, 12, 8}; // LEDs connected to pins 13/12/8
int buttons[] = {2, 3, 4}; // buttons connected to pins 2/3/4
int level=0; // starting level
int buzzerPin= 5; //pizeo buzzer at pin 5
int timeLimit = 7500; // starting time limit in milliseconds
int score = 0; // starting score
int rgbRed= 11;
int rgbBlue= 10;
int rgbGreen= 9;
int notes[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };//note array for game winning function
int durations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };

void setup() {
  //previous time being initialized as the running time of the sim
  previousTime = millis();
  pinMode(buzzerPin, OUTPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT); // set LED pin as output
    pinMode(buttons[i], INPUT_PULLUP); // set button pin as input with pull-up resistor
  }
  Serial.begin(9600); // initialize serial communication
  Serial.println("Press any button to begin");
  while (digitalRead(buttons[0])== LOW && digitalRead(buttons[1]) == LOW && digitalRead(buttons[2])==LOW) { // wait for button press
    // do nothing  unless a button is pressed
    if (digitalRead(buttons[0])== HIGH || digitalRead(buttons[1]) == HIGH || digitalRead(buttons[2]) == HIGH){
    	Serial.println("Game Beginning! Get ready!");	
      	level=1;
      	
    }
  }
  
}

void loop() {
  for (int i = 0; i < 3; i++) {
  digitalWrite(leds[i], LOW); // turn off LEDs 
  }
  delay(500);
  int randomLed = random(0, 3); // generate a random number between 0 and 2
  
    while (level>0 && score<10) { // while the time limit hasn't been reached
      digitalWrite(leds[randomLed], HIGH); // turn on LED
      if (digitalRead(buttons[randomLed]) == HIGH) {// if correct button is pressed
      	//calling the elapsed time function, storing it in a variable
        unsigned long timeElapsed = elapsedTime();
        //if you pressed the button within the time limit, you beat the levle
        if (timeElapsed<timeLimit){
        flashGreen();
        ascendingTone();
        score++; // increase the score
        level++; // increase the level
        timeLimit -= 400; // decrease the time limit by 400 milliseconds
        Serial.println("Score: " + String(score) + " | Level: " + String(level));// print the score and level to the serial monitor
        delay(500);
          break;} // exit the while loop
        else if (timeElapsed>timeLimit) { // If the time limit has been reached
        flashRed();
        descendingTone();
        Serial.println("Time expired! Game Over!"); // print "Game Over!" to the serial monitor
        gameOver();
        break; // exit the while loop
      }
      }
      else if (digitalRead(buttons[!randomLed]) == HIGH) {// if wrong button is pressed
        flashRed();
        descendingTone();
        Serial.println("Wrong button! Game Over!"); // print "Game Over!" to the serial monitor
        gameOver();
      }
    }
    
  
if (score >= 10) {// if the player reaches 10 points
  	//you win
	gameWinner();
}
}


//this function will run when the game is over
void gameOver(){
  Serial.println("Press any button to play again");
  Serial.print("Final Score: ");
  Serial.println(score);
  //will run until button is pressed
  while (digitalRead(buttons[0])== LOW && digitalRead(buttons[1]) == LOW && digitalRead(buttons[2]) == LOW){ // wait for button press
      	  for (int i = 0; i < 3; i++) {
  			digitalWrite(leds[i], LOW); // turn off LEDs 
  			}
    //if button is pressed, the following will happen
    if (digitalRead(buttons[0])== HIGH || digitalRead(buttons[1]) == HIGH|| digitalRead(buttons[2]) == HIGH){
    	Serial.println("Game restarting");  
		level = 1; // reset the level to 0
		timeLimit = 7500; // reset the time limit to 5000 milliseconds
		score = 0; // reset the score to 0
		delay(500); // delay for half a second
      	previousTime=millis();	
      	break;
    }
  }
}

void gameWinner(){
Serial.println("You Win!"); // print "You Win!" to the serial monitor 
//will run until a button is pressed
while (digitalRead(buttons[0])== LOW && digitalRead(buttons[1]) == LOW && digitalRead(buttons[2]) == LOW) {
lightShow();
winningTune();
//game restarts when button is pressed
if (digitalRead(buttons[0])== HIGH || digitalRead(buttons[1]) == HIGH|| digitalRead(buttons[2]) == HIGH){
lightsOut();  
Serial.println("Game restarting");  
level = 1; // reset the level to 0
timeLimit = 7500; // reset the time limit to 5000 milliseconds
score = 0; // reset the score to 0
delay(500); // delay for half a second 
previousTime=millis();
break;
}
}
}

//flash green rgb if level passed
//red if failed
void flashGreen(){
analogWrite(rgbGreen, 255);
analogWrite(rgbRed, 0);
analogWrite(rgbBlue, 0);
delay(500);
analogWrite(rgbGreen, 0);
analogWrite(rgbRed, 0);
analogWrite(rgbBlue, 0);  
}

void flashRed(){
analogWrite(rgbGreen, 0);
analogWrite(rgbRed, 255);
analogWrite(rgbBlue, 0);
delay(500);
analogWrite(rgbGreen, 0);
analogWrite(rgbRed, 0);
analogWrite(rgbBlue, 0);  
}

//get a light show for winning
void lightShow(){
for (int i = 0; i < 3; i++) {
  			digitalWrite(leds[i], LOW); // turn off LEDs 
  			}
int randomRGB= random(100, 199);
turquoise();
delay(500);
lightsOut();
blue();
delay(500);
lightsOut();
fuschia();
delay(500);
lightsOut();  
white();
delay(500);
lightsOut();  
red();
delay(500);
lightsOut();  
green();
delay(500);
lightsOut();
}

void lightsOut(){
analogWrite(rgbGreen, 0);
analogWrite(rgbRed, 0);
analogWrite(rgbBlue, 0);
}

//level passed tone
void ascendingTone(){
	for (int i = 200; i <= 1000; i += 50) {
    	tone(buzzerPin, i);
    	delay(50);
  		}
  	noTone(buzzerPin);
 	delay(500); 
}

//losing tone
void descendingTone(){
	for (int i = 1000; i >= 200; i -= 50) {
    	tone(buzzerPin, i);
    	delay(50);
  		}
  	noTone(buzzerPin);
 	delay(500); 
}

//elapsed time function will determine elapsed time since function was called 
unsigned long elapsedTime() {
  unsigned long currentTime = millis();// taking current run time
  unsigned long timeElapsed = currentTime - previousTime;// time elapsed since function was last called
  previousTime = currentTime;// Update the "previousTime" variable with the current time for the next function call
  return timeElapsed;
}

void turquoise(){
  analogWrite(rgbRed, 48);
  analogWrite(rgbGreen, 213);
  analogWrite(rgbBlue, 200);
}

void blue(){
  analogWrite(rgbRed, 0);
  analogWrite(rgbGreen, 0);
  analogWrite(rgbBlue, 255);
}

void red(){
  analogWrite(rgbRed, 255);
  analogWrite(rgbGreen, 0);
  analogWrite(rgbBlue, 0);
}

void green(){
  analogWrite(rgbRed, 0);
  analogWrite(rgbGreen, 255);
  analogWrite(rgbBlue, 0);
}

void fuschia(){
  analogWrite(rgbRed, 255);
  analogWrite(rgbGreen, 0);
  analogWrite(rgbBlue, 255);
}

void white(){
  analogWrite(rgbRed, 255);
  analogWrite(rgbGreen, 255);
  analogWrite(rgbBlue, 255);
}

void winningTune(){
for (int i = 0; i < 8; i++) {
  tone(buzzerPin, notes[i]);
  delay(durations[i] * 125);
  noTone(buzzerPin);
}
}