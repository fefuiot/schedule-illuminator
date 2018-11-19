// Using movement sensor HC-SR501

// !!!!!
// Connect VV of LoLin to 5V+ of sensor and VCC of relay
// Connect G (near VV) of LoLin to GND of sensor and GND of relay
// !!!!!

#define LIGHT_TIME 1000 // In milliseconds

#define MOVEMENT_SENSOR_PIN D0 // Connect OUT of senso to D0 on LoLin
#define RELAY_SIGNAL_PIN D1 // Connect IN1 of relay to D1 on LoLin
#define LED_PIN 2

unsigned long long last_movement_time = 0;
bool isLightOn = false;
 
void setup() 
{
  Serial.begin(115200);

  pinMode(MOVEMENT_SENSOR_PIN, INPUT);
  pinMode(RELAY_SIGNAL_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
}

void loop() 
{
  int data = digitalRead(MOVEMENT_SENSOR_PIN);
  if (data == 1)
  {
    digitalWrite(RELAY_SIGNAL_PIN, LOW);
    delay(15000);
  }
  else
    digitalWrite(RELAY_SIGNAL_PIN, HIGH);
   /*if (millis() - last_movement_time >= LIGHT_TIME) 
      setLightOff();*/

   
}

void setLightOn()
{
  digitalWrite(RELAY_SIGNAL_PIN, LOW);
}

void setLightOff()
{
  digitalWrite(RELAY_SIGNAL_PIN, HIGH);
}

