//     SDA - A4
//     SCl - A5

#include <LiquidCrystal_I2C.h>

//define I2C address......
LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(2,0);
  lcd.print("Hello World");

  lcd.setCursor(2,1);
  lcd.print("Hi, Izumisea");

}

void loop() {


}
