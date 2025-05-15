#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD dengan alamat 0x27
LiquidCrystal_I2C lcd(0x27, 26, 2);

// Pin sensor ultrasonik
const int trigPin = D3;
const int echoPin = D4;

// Variabel untuk perhitungan jarak
long duration;
int distance;

void setup() {
  // Inisialisasi pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Inisialisasi LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SISTEM AKTIF");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Kirim sinyal ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca durasi pantulan
  duration = pulseIn(echoPin, HIGH);

  // Hitung jarak (dalam cm)
  distance = duration * 0.034 / 2;

  // Tampilkan di LCD
  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print(" cm   "); 

  lcd.setCursor(0, 1);
  if (distance < 100) {
    lcd.print("AREA BERBAHAYA");
  } else {
    lcd.print("     AMAN     ");
  }

  delay(300); 
}