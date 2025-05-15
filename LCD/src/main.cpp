#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD I2C
// (alamat LCD biasanya 0x27 atau 0x3F, tergantung hasil scanner kamu)
LiquidCrystal_I2C lcd(0x27, 26, 2);  // Alamat 0x27, 26 karakter x 2 baris
// Tetapkan pin I2C kustom
int SDA_PIN = D5; // GPIO16
int SCL_PIN = D4; // GPIO5


void setup() {
  Wire.begin(SDA_PIN, SCL_PIN);  // Inisialisasi I2C dengan pin custom (SDA, SCL)

  lcd.init();          // Inisialisasi LCD
  lcd.backlight();     // Nyalakan lampu latar LCD

  lcd.setCursor(0, 0); // Kolom 0, Baris 0
  lcd.print("Destian Ardan Alfatanu!");

  lcd.setCursor(0, 1); // Kolom 0, Baris 1
  lcd.print("H1D022045");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(300);
}
