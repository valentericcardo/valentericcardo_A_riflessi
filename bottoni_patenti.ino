#include <LiquidCrystal.h>

int luce = 13;
int buzzer = 11;
int buttone = 9;
int riflesso;
int riflesso2;
double wait;
String appoggio;
LiquidCrystal lcd(2, 3, 7, 6, 5, 4);

void setup() {
  // put your setup code here, to run once:
 pinMode(luce, OUTPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(buttone, INPUT);
 lcd.begin(16, 2);

 lcd.setCursor(0, 0);
 lcd.print("PETALOSO");
}

void loop() {
  // put your main code here, to run repeatedly:
   accensioneLed();
   riflessione();
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
