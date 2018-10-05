#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "DHT.h"

#define Rele_2 D4

LiquidCrystal_I2C lcd(0x27,16,2); // Cambiamos la direccion
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

    // Medida de humedad de suelo
    lcd.setCursor(10,0);
    lcd.print(analogRead(A0));
    lcd.print("   ");

    // Encendido y apagado del rele
    if(analogRead(A0) > 500 ) {
      digitalWrite(Rele_2,LOW);
    } else {
      digitalWrite(Rele_2,HIGH);
    }
    delay(1000);

}
