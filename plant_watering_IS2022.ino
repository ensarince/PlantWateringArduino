
#include <Arduino.h>
#include <SoftwareSerial.h>
#define DEBUG true
#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);
String humidity = " Humidity: %";
String temperature = "   Temperature";
// **************

void setup();
void loop();
// **************

int IN1 = 4;
int IN2 = 5;

int Pin1 = A0;
int Pin2 = A1;

float sensor1Value = 0;
float sensor2Value = 0;


void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);


  pinMode(Pin1, INPUT);
  pinMode(Pin2, INPUT);


  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  delay(500);
}

void loop() {
  
   int h = dht.readHumidity();
  // Read temperature as Celsius
  int t = dht.readTemperature();

//monitoring Moisture levels of two sensors gives
  Serial.print("Plant 1 - Moisture Level:");
  sensor1Value = analogRead(Pin1);
  Serial.println(sensor1Value);

  if (sensor1Value > 400) {
    digitalWrite(IN1, LOW);
  } else {
    digitalWrite(IN1, HIGH);
  }

  Serial.print("Plant 2 - Moisture Level:");
  sensor2Value = analogRead(Pin2);
  Serial.println(sensor2Value);

  if (sensor2Value > 400) {
    digitalWrite(IN2, LOW);
  } else {
    digitalWrite(IN2, HIGH);
  }

//monitoring humidity and temperature
  Serial.print("Humidity: "); 
  Serial.println(h);
  Serial.print("Temperature: "); 
  Serial.println(t);
  Serial.println("*********************************");

  delay(2000); // 2 seconds
}
