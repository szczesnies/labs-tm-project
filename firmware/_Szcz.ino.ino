#include <DHT.h>               //dla czujnika dth11
#include <LiquidCrystal_I2C.h> //sterowanie wyswietlaczem
#include <Wire.h>              //komunikacja I2C z arduino SDA(przesylanie danych), 
                               //SCL(synchronizowanie danych za pomoca sygnalu z zegara)
                               
LiquidCrystal_I2C lcd(0x27,16,2);  //0x27 domyslny adres i2c do lcd dla 16 znakow i 2 linii
  
//Polaczenia
#define DHTPIN 7           //pin do danych z sensora
#define DHTTYPE DHT11      //definicja czujnika

DHT dht(DHTPIN, DHTTYPE);  //inicjowanie sensora dht dla arduino

int t;                     //wartosc temperatury
int w;                     //wartosc wilgotnosci

void setup()
{
    Serial.begin(9600);                     //ustawienie predkosci przesylu danych
    dht.begin();                            //inicjacja dht
    lcd.init();                             //inicjacja lcd
    lcd.backlight();                        //wlaczenie podswietlenia
}

void loop()
{ 
    w = dht.readHumidity();         //odczyt i zapisanie zmiennej
    t = dht.readTemperature();

  
    //Wyswietlanie na lcd
    lcd.setCursor(0, 1);
    lcd.print("T:");
    lcd.print(t);
    lcd.print((char)223);
    lcd.print("C   ");
    lcd.print("W: ");
    lcd.print(w);
    lcd.print("%");
    
     lcd.setCursor(0, 0);
     lcd.print("L.Szczesniewski")
    delay(3000);
}
