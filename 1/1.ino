#include <virtuabotixRTC.h>
virtuabotixRTC Saat(6, 7, 8); //CLK -> 6, Data -> 7, RST -> 8
String gunler[] = {"PAZARTESI", "SALI", "CARSAMBA", "PERSEMBE", "CUMA", "CUMARTESI", "PAZAR"};
void setup() {
  Serial.begin(9600);
}
void loop() {
  Saat.updateTime(); //Bu kod ile RTC deki anlık zamanı alıyoruz.
  Serial.print(Saat.hours);  //Saat
  Serial.print( );
  Serial.print(Saat.minutes);  //Dakika
  Serial.print(":");
  Serial.print(Saat.dayofmonth); //Gün
  Serial.print("/");
  Serial.print(Saat.month);  //Ay
  Serial.print("/");
  Serial.print(Saat.year); //Yıl
  Serial.print(" ");
  
  delay(1000); // 1 saniye bekletiyoruz.
}
