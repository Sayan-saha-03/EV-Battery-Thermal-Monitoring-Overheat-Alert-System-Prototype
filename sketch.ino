#include <math.h>

// Pin configuration
const int TEMP_PIN = A0;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;

// NTC parameters
const float BETA = 3950;
const float R0 = 10000;
const float T0 = 298.15;

// Over-temperature threshold
const float OVERHEAT_LIMIT = 40.0;

// Read temperature from NTC sensor
float readTemperature(){
  int adcValue = analogRead(TEMP_PIN);

  if(adcValue <= 0 || adcValue >= 1023){
    return NAN;
  }

  float resistance = R0 / (1023.0 / adcValue - 1.0);
  float temperatureK = 1.0 / (1.0 / T0 + log(resistance / R0) / BETA);
  return temperatureK - 273.15;
}

// Control the over-temperature alarm
void controlAlarm(float temperature){

  if(temperature >= OVERHEAT_LIMIT){

    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);

    Serial.println("STATUS: OVERHEAT!");
    Serial.println("LED: ON");
    Serial.println("BUZZER: ON");

  } else{

    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);

    Serial.println("STATUS: NORMAL");
    Serial.println("LED: OFF");
    Serial.println("BUZZER: OFF");
  }
}

void setup(){

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);

  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);
}

// void loop(){
//   float temperature = readTemperature();
//   Serial.print("Temperature: ");
//   Serial.print(temperature);
//   Serial.println(" C");
//   controlAlarm(temperature);
//   Serial.println("--------------------");
//   delay(1000);
// }

void loop(){

  float temperature = readTemperature();

  if(isnan(temperature)){
    Serial.println("ERROR: Invalid temperature sensor reading");
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 2000);
  }
  else{
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
    controlAlarm(temperature);
  }

  Serial.println("--------------------");
  delay(1000);
}