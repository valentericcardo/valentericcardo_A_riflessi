#include <LiquidCrystal.h>
int luce = 12;
int buzzer = 11;
int buttone = 13;
int riflesso;
int riflesso2;
double wait;
String appoggio; String appoggio2;
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
  //per pulire dal test precedente
   accensioneLed();
   riflessione();
   lcd.setCursor(0, 0);
   lcd.print(riflesso);
   lcd.print(" ms");
  /* if(riflesso > 500)
   {
    lcd.setCursor(12, 0);
    lcd.print("male");
   }
   else
   {
    lcd.setCursor(12, 0);
    lcd.print("bene");
   }
   lcd.setCursor(0, 1);
   lcd.print(riflesso2);
   lcd.print(" ms");
   if(riflesso2 > 500)
   {
    lcd.setCursor(12, 1);
    lcd.print("male");
   }
   else
   {
    lcd.setCursor(12, 1);
    lcd.print("bene");
   }*/
}
void accensioneLed()
{
  wait = random(1000, 5000);//faccio un random
  delay(wait); //lo uso come delay
  riflesso =  millis();
  digitalWrite(luce, HIGH);//accendo il led
}
void accensioneBuzzer()
{
  wait =  random(1000, 5000);
  delay(wait);
  riflesso2 =  millis();
  tone(buzzer, 500);
}
void  riflessione()
{
  while(true)
  {
    riflesso =  millis() - riflesso;
    if(digitalRead(buttone) == HIGH)
    {
      digitalWrite(luce, LOW);
      break;
    }
  }
  //adesso devo fare il buzzer
  accensioneBuzzer();
  while(true)
  {
    riflesso2 = millis() -  riflesso2;
    if(digitalRead(buttone) == HIGH)
    {
      tone(buzzer, 500, 1);
      break;
    }
  }
}
