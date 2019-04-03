/*
   -Arduino 433MHz RF Tester
   -Based on an example from the RCSwitch Library
   -https://github.com/sui77/rc-switch/
   -Hardware: Arduino Nano & Generic 433MHz RF Receiver
   -Theo GLEIZES/2018
*/
#include <RCSwitch.h>

RCSwitch receiver = RCSwitch();
RCSwitch transmitter = RCSwitch();
void setup() 
{
  Serial.begin(9600);
  receiver.enableReceive(0);  // Receiver input on interrupt 0 (D2)
  transmitter.enableTransmit(10);
  pinMode(13, OUTPUT); // D13 as output- Optional
  digitalWrite(13, HIGH);
  Serial.print("Beginning ");
}

void loop() 
{
  
  transmitter.send(2153, 24);
  if (receiver.available())
  {
    Serial.print("Received ");
    Serial.print( receiver.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( receiver.getReceivedBitlength() );
    Serial.print("Bit ");
    Serial.print(" // ");
    Serial.print("Protocol: ");
    Serial.println( receiver.getReceivedProtocol() );

    //digitalWrite(13, LOW);
    receiver.resetAvailable();
  }
  //delay(1000);
}
