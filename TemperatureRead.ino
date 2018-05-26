#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 sensor;
bool status; // Vai servir para informar se o sensor está funcionando corretamente
void setup() {
 Serial.begin(9600);
 Serial.println(F("OK"));
 pinMode(D4,OUTPUT);
 digitalWrite(D4,LOW);
 status = sensor.begin(); // Inicializar a comunicação entre o microcontrolador e o sensor de temperatura/umidade

 if (status == false) {
  Serial.println ("Erro ao ler sensor");
  return;
 }
 else{
  Serial.println ("Sensor OK");
 }

}

void loop() {
  if (status==false){
    delay(1000);
    return;
  }
  else {
    delay(1000);
    digitalWrite(D4,HIGH);
    float temperatura,umidade;
    temperatura = sensor.readTemperature();
    umidade = sensor.readHumidity();
    Serial.print("Temperatura: ");
    Serial.println(temperatura);
    Serial.print("Umidade: ");
    Serial.println(umidade);
    delay(1000);
    digitalWrite(D4,LOW);
  }

}
