//Binary light simulator
//Stefan Saladino
//Feb 3, 2023

int lightsensor = A1;
int data = 0;
int ledPin[]= {13, 12, 8, 7};
int length = (sizeof(ledPin))/(sizeof(ledPin[0]));




void setup()
{
  pinMode(lightsensor, INPUT);
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);
  pinMode(ledPin[3], OUTPUT);
  Serial.begin(9600);
}

void lightsOn(){
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
  
  lightsOn();
  
 
  }
  
  
  

