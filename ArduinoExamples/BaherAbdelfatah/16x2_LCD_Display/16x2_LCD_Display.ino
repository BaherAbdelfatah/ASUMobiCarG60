
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  lcd.begin(16, 2);
}
void loop() {
    lcd.print("BaherAbdelfatah");
  delay(1000);
  lcd.clear();
  lcd.print("ASUMobiCarG60");
  delay(1000);
  lcd.clear();
}

