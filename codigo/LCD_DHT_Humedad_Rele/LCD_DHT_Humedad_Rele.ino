#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "DHT.h"

#define Rele_2 D4

LiquidCrystal_I2C lcd(0x27,16,2); // Cambiamos la direccion a 0x27 0x30 o 0x3F
DHT dht16(D6,DHT22);

void setup()
{
  lcd.begin();
  lcd.home();
  lcd.backlight();  // Activamos la iluminacion
  pinMode(Rele_2, OUTPUT);
}


void loop() {
    lcd.display();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print((dht16.readTemperature( )));
    lcd.setCursor(0, 1);  // Ajustamos la posicion
    lcd.print("H:");
    lcd.print((dht16.readHumidity( )));



    int humedad = 1024 - analogRead(A0);

    // Medida de humedad de suelo
    lcd.setCursor(10,0);
    lcd.print(humedad);
    lcd.print("   ");

    int Humedad_GEranio = 512;
    int Humedad_Lechuga = 322;
    
    // Encendido y apagado del rele
    if( humedad  > Humedad_GEranio ) {
      digitalWrite(Rele_2,LOW);
    } else {
      digitalWrite(Rele_2,HIGH);
    }
    delay(1000);

}
