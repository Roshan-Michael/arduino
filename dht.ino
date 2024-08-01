#include "DHT.h"
#include <LiquidCrystal.h>
#define Type DHT11
int rs = 7;
int en = 3;
int d4 = 4;
int d5 = 10;
int d6 = 11;
int d7 = 12;

int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setTime = 500;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  // put your setup code here, to run once:
  pinMode(sensePin, INPUT);
  Serial.begin(9600);
  HT.begin();
  delay(setTime);
  lcd.begin(16, 2);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature C: ");
  lcd.setCursor(0, 1);
  lcd.print(tempC);
  lcd.print(" C");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature F: ");
  lcd.setCursor(0, 1);
  lcd.print(tempF);
  lcd.println(" F");
  delay(1500);
  lcd.clear();

}