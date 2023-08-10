//Set the pin numbers
//#define IN4 4
int ledr = 4;
int ledy = 3;
int ledg = 2;
const int trigPin = 5;
const int echoPin = 6;

//Define the global variables
long time_on;
int distance = 0;


void setup() 
{
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); //Sets trigpin as output
  pinMode(echoPin, INPUT); //Set echo pin as input
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  //Figure out when the LED should come on based on where the car is 
  if((distance < 50) && (distance > 0)) //Right distance away to park
  {
    digitalWrite(ledr, HIGH); //Turn on the LED and stays on
    digitalWrite(ledg, LOW); //LED is off
    digitalWrite(ledy, LOW); //LED is off
    delay(1000);
  }
  else if((distance >= 50) && (distance < 150))  //Getting close to target parking distance
  {
    //Turns the LED on off, basically flashing 
    // digitalWrite(ledr, HIGH); //Turn on the LED
    // delay(10*(distance-50));
    // digitalWrite(ledr, LOW); //Turn on the LED
    // delay(10*(distance-50));
    digitalWrite(ledy, HIGH); //Turn on the LED
    digitalWrite(ledr, LOW); //Turn on the LED and stays on
    digitalWrite(ledg, LOW); //LED is off
    delay(1000);
  }
  else if((distance >= 150) && (distance < 200)) //Still far away from parking distance
  {
    //Big delay between LED flashing meaning still far away
    // digitalWrite(ledr, HIGH); //Turn on the LED
    // delay(1000);
    // digitalWrite(ledr, LOW); //Turn on the LED
    // delay(10000);
    digitalWrite(ledg, HIGH); //Turn on the LED
    digitalWrite(ledy, LOW); //Turn on the LED
    digitalWrite(ledr, LOW); //Turn on the LED and stays ond
    delay(1000);
  }
  else if(distance >= 200) //Basically jsut entered the garage
  {
    digitalWrite(ledr, LOW); //LED is off
    digitalWrite(ledg, HIGH); //LED is off
    digitalWrite(ledy, LOW); //LED is off
  }

  delayMicroseconds(10); 
  
  //Clears trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time_on = pulseIn(echoPin, HIGH);
  distance = time_on * 0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  

}
