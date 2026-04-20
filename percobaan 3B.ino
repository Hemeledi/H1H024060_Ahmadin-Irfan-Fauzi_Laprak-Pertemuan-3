#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

// Ganti alamat jika perlu (0x27 / 0x20)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinPot = A0;

void setup() {
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
}

void loop() {
  int nilai = analogRead(pinPot);

  // Mapping ke bar (0-16)
  int panjangBar = map(nilai, 0, 1023, 0, 16);

  // Tampilan ke Serial
  Serial.print("Nilai ADC : ");
  Serial.println(nilai);

  // Baris 1: Nilai ADC
  lcd.setCursor(0, 0);
  lcd.print("ADC: ");
  lcd.print(nilai);
  lcd.print("   "); // clear sisa

  // Baris 2: Bar
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    if (i < panjangBar) {
      lcd.print((char)255);
    } else {
      lcd.print(" ");
    }
  }

  delay(200);
}