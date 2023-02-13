#include <virtuabotixRTC.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h> // SPI kütüphanesi tanımlanıyor
#include <SD.h>  // SD kart kütüphanesi tanımlanıyor 
#define MQ2pin (0)

LiquidCrystal_I2C lcd(0x27,16,2);
File dosya;      // Dosya adında bir File nesnesi oluşturuluyor
int kayit = 0;   // Okunan kayıtların sayısını tutuan değişken
int saat,dakika,gun,ay,yil;
float sensorValue;  //variable to store sensor value

virtuabotixRTC Saat(6, 7, 8); //CLK -> 6, Data -> 7, RST -> 8


void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  
  lcd.begin();
  if (!SD.begin(10))      //SD kartı başlatıp CS pinini 10 belirledik
  {
    Serial.println("SD kart takili degil!");
    Serial.println("Lutfen SD kartinizi takiniz!");
    
  }  else  {
    Serial.println("SD kart kullanima hazir!!!");
  }
  SD.mkdir("TekDosya");                         //Klasör oluşturuluyor
  Serial.println("Klasor olusturuldu");         //Seri port ekranında bilgiyi yazdıryoruz



  

  
}

void loop() {
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  dosya = SD.open("Tekdosya/not.txt", FILE_WRITE);  //Dosya nesnesiyle klasörü açıp not.txt dosyasını yazıyoruz
  Saat.updateTime(); //Bu kod ile RTC deki anlık zamanı alıyoruz.
  saat=Saat.hours;
  dakika=Saat.minutes;
  gun=Saat.dayofmonth;
  ay=Saat.month;
  yil=Saat.year;
  char date[15]; 
  sprintf (date,"%02d/%02d/%02d-%02d:%02d",gun,ay,yil,saat,dakika);
 
  


 
  
  
  if (sensorValue>=230)
  {
              if (dosya)
              {
                dosya.print("  Gaz Degeri: "); //Not.txt dosyasına veri yazıyoruz. 
                dosya.print(sensorValue); //Not.txt dosyasına veri yazıyoruz. 
               
                dosya.println(Saat.hours+":"+Saat.minutes);
                dosya.print(" ");
                dosya.print(Saat.dayofmonth);
                dosya.print("/");
                dosya.print(Saat.month);
                dosya.print("/");
                dosya.print(Saat.year);
                
              }
              dosya.close();                            //Dosyayı kapatıyoruz   
              kayit++;  
               
  } else {
    Serial.print("Duman yok");                              
  }
  Serial.println(sensorValue);           //Seri port ekranına yazdırılan veriyi yazdırıyoruz
  Serial.println(kayit);                          //Kayıt sayısını yazdırıyoruz
  
  delay(2000); 
  if (sensorValue>=280)
  {
        digitalWrite(3, HIGH);
        
       
        
  } else{
        digitalWrite(3, LOW);
       
  }
  
  if (sensorValue>=100)
  {
        lcd.setCursor(0,0); // İlk satırın başlangıç noktası
        lcd.print(sensorValue);
        lcd.print(" PPM");
        
        lcd.setCursor(0,1); // İkinci satırın başlangıç noktası
        lcd.print(date);
        
        
  } else{
        lcd.clear();
  }

 
  
  
  
}
