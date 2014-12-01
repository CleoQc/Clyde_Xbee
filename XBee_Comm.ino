/*****************************************************************
XBee_Comm.ino

Set up a software serial port to pass data between an XBee Shield
and the serial monitor.
Based on code found at https://learn.sparkfun.com/tutorials/xbee-shield-hookup-guide/example-communication-test
*****************************************************************/
// utilitarian function
// feel free to change if you want a different blink
void blink()
{
    digitalWrite(11, LOW);
    delay(500);            
    digitalWrite(11, HIGH);
    delay(500);  
}

void setup()
{
  // Set up both ports at 9600 baud. 
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(11, OUTPUT); // setting task lamp as output so we can blink it
  digitalWrite(11,HIGH); // turn off task lamp for now
  delay(5000); // wait 5 seconds, to let user start serial monitor window
  blink();
  Serial.write("Hello\n");   // on the serial monitor
  Serial1.write("How are you?\n");  // on the Xbee
}

void loop()
{
  if (Serial.available())
  { // If data comes in from serial monitor, send it out to XBee
    // if data present, blink
    while (Serial.available())
    {
      Serial1.write(Serial.read());
    }
    blink();    
  }
  if (Serial1.available())
  { // If data comes in from XBee, send it out to serial monitor
    while (Serial1.available())
    {
      //Serial.write(Serial1.read());
      Serial.write(Serial1.read());
    }
    blink();
  }
}
