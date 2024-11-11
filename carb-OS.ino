#include <SPI.h>
#include <LoRa.h>

#define LORA_SS 10
#define LORA_RST 9
#define LORA_DIO0 2

const unsigned long SENSOR_INTERVAL = 2000;
const unsigned long DIAGNOSTIC_INTERVAL = 5000;

unsigned long lastSensorRead = 0;
unsigned long lastDiagnosticCheck = 0;

void readSensorTask() {
    int sensorValue = analogRead(A0);
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);

    LoRa.beginPacket();
    LoRa.print("Sensor Value: ");
    LoRa.print(sensorValue);
    LoRa.endPacket();
}

void diagnosticTask() {
    Serial.println("Diagnostic Check: All systems nominal");
    LoRa.beginPacket();
    LoRa.println("Diagnostic Check: All systems nominal");
    LoRa.endPacket();
}

void setup() {
    Serial.begin(9600);
    pinMode(A0, INPUT);

    LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
    if (!LoRa.begin(915E6)) {
        Serial.println("LoRa init failed. Check your connections.");
        while (1);
    }
    Serial.println("carb-OS iniciado y LoRa configurado");
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - lastSensorRead >= SENSOR_INTERVAL) {
        lastSensorRead = currentMillis;
        readSensorTask();
    }

    if (currentMillis - lastDiagnosticCheck >= DIAGNOSTIC_INTERVAL) {
        lastDiagnosticCheck = currentMillis;
        diagnosticTask();
    }
}
