// Assam Don Bosco University
// Mini Project II
// Capacitance Meter using Arduino (Capacitance Meter for Range 20 pF to 1000 nF)
// Hardware: Arduino UNO(1), 16 x 2 LCD Display(1), 10 KΩ Potentiometer(1), Capacitor under test(as redq.), Connecting wires(as reqd.), Breadboard(1), Power supply(1)

LiquidCrystal lcd(6, 7, 2, 3, 4, 5);
const int analog_charge = A2;
const int analogPin = A0;
float ck=24.42;
int voltage;
float cu;
void setup()
{
Serial.begin(9600);
lcd.begin(16, 2);
lcd.print(" 20pF<to>1000nF ");
lcd.setCursor(0,1);
lcd.print("place capacitor ");
pinMode(analogPin,OUTPUT);
pinMode(analog_charge,OUTPUT);
}

void loop()
{
     abc:
     pinMode(analogPin,INPUT);
     digitalWrite(analog_charge,HIGH);
     voltage=analogRead(analogPin);
     digitalWrite(analog_charge,LOW);
     //analog_charge = 998 || 999 || 1000 || 1001 and ! 1024
     pinMode(analogPin,OUTPUT);
      if(voltage<1000)
     {
      cu=((ck*voltage)/(1024.0-voltage));
      if(cu>20.0)
      {
       lcd.setCursor(0,1);
       lcd.print("                ");
       lcd.setCursor(0,1);
       lcd.print(cu,2);
       lcd.print("pF"); 
      }
      else
      {
       lcd.setCursor(0,1);
       lcd.print("place capacitor ");
       delay(200);
       lcd.setCursor(0,1);
       lcd.print("                ");  
       delay(200);
       goto abc;
      }
     }
    else
    {
      voltage=0;
      pinMode(analogPin,OUTPUT);
      delay(1);
      pinMode(analog_charge,INPUT_PULLUP);
      unsigned long start_time = micros();
      unsigned long final_time=0;
     
      while((voltage < 1) && (final_time < 400000L))
      {
        voltage = digitalRead(analog_charge);
        unsigned long stop_time = micros();
        final_time = stop_time > start_time ? stop_time - start_time : start_time - stop_time;
      }

      pinMode(analog_charge, INPUT);  
      voltage = analogRead(analog_charge);
      digitalWrite(analogPin, HIGH);
      int delay_T = (int)(final_time / 1000L) * 5;
      delay(delay_T);   
      pinMode(analog_charge, OUTPUT);  
      digitalWrite(analog_charge, LOW);
      digitalWrite(analogPin, LOW);

      cu = -(float)final_time / 34.8 ;
      cu /= log(1.0 - (float)voltage / (float)1023);
      if(cu < 1000.0)
      {
       lcd.setCursor(0,1);
       lcd.print("                ");
       lcd.setCursor(0,1);
       lcd.print(cu,2);
       lcd.print("nF"); 
      }
      else
      {
       lcd.setCursor(0,1);
       lcd.print("                ");
       lcd.setCursor(0,1);
       lcd.print("**Out of Range**");
      }
    }
    delay(1000);
}
