const int trigPin = 11;
const int echoPin = 12;
const int RedLEDPin = 4;
const int GreenLEDPin = 5;
long duration;
int distanceCm, distanceInch;
long range = 3;
// range = 3 in 

#include <ArduinoBLE.h>
BLEService newService("180A"); // creating the service
BLEByteCharacteristic readChar("2A57", BLERead);
BLEByteCharacteristic writeChar("2A58", BLEWrite);

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(RedLEDPin, OUTPUT);
pinMode(GreenLEDPin, OUTPUT);
Serial.begin(9600);

while(!Serial);
if (!BLE.begin()){
Serial.println("Waiting for ArduinoBLE");
while(1);
}

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);

distanceCm = duration * 0.0172;
distanceInch = duration * 0.00675;
Serial.print("Distance: ");
Serial.print(distanceCm);
Serial.print(" cm/");
Serial.print(distanceInch);
Serial.println(" in");
delay(1000);

if (distanceInch < range) {
  digitalWrite(GreenLEDPin, HIGH);
  digitalWrite(RedLEDPin, LOW);
} else {
  digitalWrite(GreenLEDPin, LOW);
  digitalWrite(RedLEDPin, HIGH);
}
}
