#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereço 0x27
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
  lcd.begin(16,2);
  lcd.setBacklight(HIGH);
}

void loop() {
  lcd.home();
  lcd.print("Hello, World!");
  lcd.setCursor(0, 1);
  lcd.print("NewLiquidCrystal");
}
