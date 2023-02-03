//Binary light simulator
//Stefan Saladino
//Feb 3, 2023



//C++ apparently returns the size of the array in bites (Fun fact: I did not know this and spent too long trying to figure out why the program thought my array contained 8 elements)
//in order for int length to return the appropriate value, I divided the number of bytes by a standard integer length (the variable used in the array)
//this returned a length of 4, which is what I needed for my for loop to function
int lightsensor = A1;
int data = 0;
int ledPin[]= {13, 12, 8, 7};
int length = (sizeof(ledPin))/(sizeof(int); 


// setting up each light to function as a member of an array
// rather than defining a light as a colour, they receive a value of their place in the array
void setup()
{
  pinMode(lightsensor, INPUT);
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);
  pinMode(ledPin[3], OUTPUT);
  Serial.begin(9600);
}


//creating a method to define how I want the lights to behave
void lightsOn(){

//this for loop turns the light on if the "value" of the light is 1
//a mod of 1 (only 1 or 0 is possible) indicates that led should be on
//loop repeats until it has run as many times as the array has elements 

  for (int i=0; i <= length; i++){
    if(data%2==0){
      digitalWrite(ledPin[i], LOW);
      data/=2;}
    else if(data%2!=0){
      digitalWrite(ledPin[i], HIGH);
      data/=2;}
    }
  }

      



void loop()
{
  data = analogRead(lightsensor);//reads the sensor bar input when moving
  data = map(data, 6, 679, 0, 15);// adjusting the scale to a 100 pt scale. Easier too understand in % terms
  
  Serial.print("Binary number= ");//will print light value=
  Serial.println(data);//will print the sensor value and create next line
  delay(500);//1 sec delay
  
//calling the method
  lightsOn();
  
 
  }
  
  
  

