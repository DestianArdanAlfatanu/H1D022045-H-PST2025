#include <Arduino.h>

int echoPin = D0;
int trigPin = D1;
int ledPin1 = D4;
int ledPin2 = D3;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;
    
    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.print(" cm");

    if (distance < 10) { 
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, LOW);
    } else if (distance >= 10 && distance <40) { 
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, HIGH);
    } else {
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
    }
    
    delay(500);
}
