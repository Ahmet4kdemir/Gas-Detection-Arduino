#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); // Bu kodu kullanırken ekranda yazı çıkmaz ise 0x27 yerine 0x3f yazınız !!
void setup() {
  lcd.begin();

}

void loop() {
 lcd.setCursor(0,0); // İlk satırın başlangıç noktası
 lcd.print("Robolink");
 lcd.setCursor(0,1); // İkinci satırın başlangıç noktası
 lcd.print("Abone Ol");
 delay(2000);

 lcd.clear();
}
