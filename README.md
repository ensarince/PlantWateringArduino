# PlantWateringArduino

Arduino Plant Watering System for course Interactive Systems'22

#Components 

**Arduino Uno**,
**Breadboard**,
**Jumper Wires**,
**4 Channel Relay**,
**Capacitive Soil Moisture Sensor x 2**,
**Submersible Mini Water Pumps x 2**,
**2 AA Battery Holder**,
**DHT11 Humidity&Temperature Sensor**,

ABOUT

Popular DIY Project for course Interactive Systems

AUTOMATING PLANT WATERING BY MOISTURE CHECK 

Moisture is the presence of water, often in trace amounts. Small amounts of water may be found, for example, in the air (humidity), in foods, and in some commercial products. Moisture also refers to the amount of water vapor present in the air.

CAPACITIVE SENSOR

This sensor can check whether your plant has enough water by checking the soil moisture.
 
HUMIDITY AND TEMPERATURE CHECKING

With DHT11 sensor we also check the temperature and humidity of the air for further observation, i.e. the scarcity changes in the water supplying with the temperature changes.

THE WIRING

![schema](https://user-images.githubusercontent.com/32306029/179405388-20d681fd-ccda-49e6-8ac3-293e654d29f9.png)

THE CODE

```Defining control pins

int IN1 = 4;
int IN2 = 5;```

Defining analog ports

int Pin1 = A0;
int Pin2 = A1;

Defining variables for moisture data

float sensor1Value = 0;
float sensor2Value = 0;

Doing setup by dht sensor, setting relays high and matching pins for moisture sensor.

`void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);


  pinMode(Pin1, INPUT);
  pinMode(Pin2, INPUT);


  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  delay(500);
}`

Reading dht values first, then printing moisture levels from capacitive sensors and controlling relay switch with digitalWrite command. If the moisture data is higher than 400, switch the pumps on. At the end, observation data is printed and whole function loops every 2 seconds.

`void loop() {
  
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
}`
