#include <LiquidCrystal.h>
#include <Keypad.h>
boolean ilkkez = true;
int yled = 5;
int kled = 6;
int buzzer = 4;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
char sifre[4] = {""};
char sifre1[4];
char tus;
int i = 0;

const byte satir = 4;
const byte sutun = 3;
char tuslar[satir][sutun] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte satirlar[satir] = {10, 9, 8, 7};
byte sutunlar[sutun] = {13, 12, 11};

Keypad keypad = Keypad(makeKeymap(tuslar), satirlar, sutunlar, satir, sutun);

void setup() {
  pinMode(yled, OUTPUT);
  pinMode(kled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("SİFRE GİRİNİZ");

}

void loop() {
  digitalWrite(yled, 0);
  digitalWrite(kled, 0);
  tus = keypad.getKey();
  if(ilkkez){
    
  }
  else if(tus){
    sifre1[i++] = tus;
    lcd.setCursor(i, 1);
    lcd.print("*");
    digitalWrite(buzzer, 1);
    delay(100);
    digitalWrite(buzzer, 0);
    if (i==4){
      delay(200);
      if(strncmp(sifre1, sifre, 4)==0){
        lcd.clear();
        lcd.print("SIFRE DOGRU");
        digitalWrite(kled, 0);
        digitalWrite(yled, 1);
        digitalWrite(buzzer, 1);
        delay(5000);
        digitalWrite(buzzer, 0);
        i = 0;
        lcd.clear();
        lcd.print("SIFRE GIRINIZ");
      }
      else{
        lcd.clear();
        lcd.print("SIFRE HATALI");
        digitalWrite(kled, 1);
        digitalWrite(yled, 0);
        delay(3000);
        digitalWrite(kled, 0);
        i = 0;
        lcd.clear();
        lcd.print("SIFRE GIRINIZ");
      }
    }
  }

}
