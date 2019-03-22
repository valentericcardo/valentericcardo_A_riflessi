#include <LiquidCrystal.h>
int luce = 12;
int buzzer = 11;
int buttone = 13;
int riflesso;
int riflesso2;
double wait;
String appoggio;
LiquidCrystal lcd(0, 1,4, 5, 6, 7);
void setup() {
  // put your setup code here, to run once:
 pinMode(luce, OUTPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(buttone, INPUT);
 lcd.begin(16, 2);
}
void loop() {
  // put your main code here, to run repeatedly:
 wait = random(1000, 5000);//faccio un random
  delay(wait); //lo uso come delay
  riflesso =  millis();
  digitalWrite(luce, HIGH);//accendo il led
   while(true)
  {
    if(digitalRead(buttone) == HIGH)
    {
      riflesso =  millis() - riflesso;
      digitalWrite(luce, LOW);
      break;
    }
  }
  //adesso devo fare il buzzer
 wait =  random(1000, 5000);
  delay(wait);
  riflesso2 =  millis();
  tone(buzzer, 500);
  while(true)
  {
    if(digitalRead(buttone) == HIGH)
    {
      riflesso2 = millis() -  riflesso2;
      tone(buzzer, 500, 1);
      break;
    }
  }
   lcd.setCursor(0, 0);
   lcd.print(riflesso);
   lcd.print(" ms");
      lcd.setCursor(0, 1);
   lcd.print(riflesso2);
   lcd.print(" ms");
   if(riflesso > 500)
   {
    lcd.setCursor(12, 0);
    lcd.print("male");
   }
   else
   {
    lcd.setCursor(12, 0);
    lcd.print("bene");
   }
   if(riflesso2 > 500)
   {
    lcd.setCursor(12, 1);
    lcd.print("male");
   }
   else
   {
    lcd.setCursor(12, 1);
    lcd.print("bene");
   }
   delay(2000);
   lcd.clear();  //per pulire i risultati del test
}
