#include <Arduino.h>

int ALED = D0; // Merah
int BLED = D1; // Kuning
int CLED = D3; // Hijau

void setup() {
  pinMode(ALED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(CLED, OUTPUT);
}

void loop() {
  // 1. Efek Spiral (Menyalakan lampu satu per satu lalu mematikannya kembali)
  digitalWrite(ALED, HIGH);
  delay(300);
  digitalWrite(BLED, HIGH);
  delay(300);
  digitalWrite(CLED, HIGH);
  delay(300);
  digitalWrite(ALED, LOW);
  delay(300);
  digitalWrite(BLED, LOW);
  delay(300);
  digitalWrite(CLED, LOW);
  delay(500);

  // 2. Efek Kedip Cepat (Semua lampu berkedip 3 kali)
  for (int i = 0; i < 3; i++) {
    digitalWrite(ALED, HIGH);
    digitalWrite(BLED, HIGH);
    digitalWrite(CLED, HIGH);
    delay(200);
    digitalWrite(ALED, LOW);
    digitalWrite(BLED, LOW);
    digitalWrite(CLED, LOW);
    delay(200);
  }

  // 3. Efek Gelombang (Lampu menyala dan mati secara bertahap)
  for (int i = 0; i < 3; i++) {
    digitalWrite(ALED, HIGH);
    delay(100);
    digitalWrite(ALED, LOW);
    digitalWrite(BLED, HIGH);
    delay(100);
    digitalWrite(BLED, LOW);
    digitalWrite(CLED, HIGH);
    delay(100);
    digitalWrite(CLED, LOW);
  }
  delay(500);

  // 4. Efek Strobe (Lampu berkedip sangat cepat)
  for (int i = 0; i < 5; i++) {
    digitalWrite(ALED, HIGH);
    digitalWrite(BLED, HIGH);
    digitalWrite(CLED, HIGH);
    delay(50);
    digitalWrite(ALED, LOW);
    digitalWrite(BLED, LOW);
    digitalWrite(CLED, LOW);
    delay(50);
  }

  // 5. Efek Flashing Cepat (Pola tidak beraturan)
  digitalWrite(ALED, HIGH);
  delay(150);
  digitalWrite(ALED, LOW);
  digitalWrite(BLED, HIGH);
  delay(250);
  digitalWrite(BLED, LOW);
  digitalWrite(CLED, HIGH);
  delay(100);
  digitalWrite(CLED, LOW);
  digitalWrite(ALED, HIGH);
  digitalWrite(CLED, HIGH);
  delay(200);
  digitalWrite(ALED, LOW);
  digitalWrite(CLED, LOW);
  delay(300);
  
  // Mode Bergantian Cepat
  digitalWrite(ALED, HIGH);
  delay(500);
  digitalWrite(ALED, LOW);
  digitalWrite(BLED, HIGH);
  delay(500);
  digitalWrite(BLED, LOW);
  digitalWrite(CLED, HIGH);
  delay(500);
  digitalWrite(CLED, LOW);
  
  // Mode Berkedip Cepat
  for (int i = 0; i < 3; i++) {
    digitalWrite(ALED, HIGH);
    delay(200);
    digitalWrite(ALED, LOW);
    delay(200);
  }
  
  for (int i = 0; i < 3; i++) {
    digitalWrite(BLED, HIGH);
    delay(200);
    digitalWrite(BLED, LOW);
    delay(200);
  }
  
  for (int i = 0; i < 3; i++) {
    digitalWrite(CLED, HIGH);
    delay(200);
    digitalWrite(CLED, LOW);
    delay(200);
  }

  // Mode Efek Berjalan
  digitalWrite(ALED, HIGH);
  delay(300);
  digitalWrite(BLED, HIGH);
  delay(300);
  digitalWrite(CLED, HIGH);
  delay(1000);
  
  digitalWrite(ALED, LOW);
  digitalWrite(BLED, LOW);
  digitalWrite(CLED, LOW);
  delay(500);
}
