// Assam Don Bosco University
// Mini Project III
// Energy Effecient Lighting System using Temperature Sensor Module
// Hardware: LDR Module(1), 12V 1A Adapter(1), Arduino Uno With USB Cable(1), Relay Module(1), 220 V AC Bulb(1), Jumper wire (as reqd.), Bulb holder(1), Breadboard(1)

int sensorPin = A0;   // select the input pin for ldr
int sensorValue = 0;  // variable to store the value coming from the sensor

/* The setup() function is called when a sketch starts. It is used to initialize variables, pin modes, start using libraries, etc. This function will only run once, after each power up or reset of the Arduino board. */
void setup()
{
  pinMode(2, OUTPUT); //pin connected to the relay
  Serial.begin(9600); //sets serial port for communication
}
/* The loop() function executes the program repeatedly until specified. */
void loop()
{
  // Read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue); //prints the values coming from the sensor on the screen
  if(sensorValue > 600) //setting a threshold value
  digitalWrite(2,HIGH); //turn relay ON
  else digitalWrite(2,LOW); //turn relay OFF
  delay(100);                 

}
