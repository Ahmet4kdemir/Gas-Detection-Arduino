#include <SPI.h> // SPI kütüphanesi tanımlanıyor
#include <SD.h>  // SD kart kütüphanesi tanımlanıyor 
File dosya;      // Dosya adında bir File nesnesi oluşturuluyor
int kayit = 0;   // Okunan kayıtların sayısını tutuan değişken

void setup() {
Serial.begin(115200);   // 115200 bant hızında seri iletişim başlatılıyor
Serial.println("SD KART DATALOGGER UYGULAMASI");
Serial.println("SD kart hazirlaniyor...");
if (!SD.begin(10))      //SD kartı başlatıp CS pinini 10 belirledik
  {
    Serial.println("SD kart takili degil!");
    Serial.println("Lutfen SD kartinizi takiniz!");
    while (!SD.begin(10));                    //SD kart takılasıya kadar bekle
    Serial.println("SD kart kullanima hazir!!!");
  }  else  {
    Serial.println("SD kart kullanima hazir!!!");
  }
SD.mkdir("TekDosya");                         //Klasör oluşturuluyor
Serial.println("Klasor olusturuldu");         //Seri port ekranında bilgiyi yazdıryoruz
}

void loop() {     
dosya = SD.open("Tekdosya/not.txt", FILE_WRITE);  //Dosya nesnesiyle klasörü açıp not.txt dosyasını yazıyoruz
    if (dosya)
    {
      dosya.println("Teknoloji ve Hayat");    //Not.txt dosyasına veri yazıyoruz. 
    }
    dosya.close();                            //Dosyayı kapatıyoruz   
kayit++;                                      //Kayıt değişkenini bir arttırıyoruz                     
Serial.print("Teknoloji ve Hayat");           //Seri port ekranına yazdırılan veriyi yazdırıyoruz
Serial.print(kayit);                          //Kayıt sayısını yazdırıyoruz
Serial.println(". Veri Kaydedildi.");         //Veri kaydedildi bilgisini yazdırıyoruz
delay(2000);                                  //2 sn bekleme 
}
