#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include "pitches.h"
#define SS_PIN 10
#define RST_PIN 9
int leda = 7;
int ledb = 8;
LiquidCrystal_I2C lcd(0x27,16,2); 
int interval1 = 0;
int interval2 = 0;
MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp;
int piezoPin = 3;
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

  
void setup() {

 

  lcd.init(); // инициализация LCD
  lcd.backlight(); // включаем подсветку
 delay (500);
digitalWrite(leda, HIGH);
  lcd.clear ();
 lcd.setCursor(0,0);
  lcd.setCursor(2,0);
  lcd.print ("Card insert v1.1");
  lcd.setCursor(6,0);
  lcd.setCursor(8,0);
  lcd.setCursor(0,1);
 lcd.print ("New card please:");

 for (int thisNote = 0; thisNote < 8; thisNote++) {

    // чтобы рассчитать время продолжительности ноты, 
    // берем одну секунду и делим ее цифру, соответствующую нужному типу ноты:
    // например, четвертная нота – это 1000/4,
    // а восьмая нота – это 1000/8 и т.д.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(3, melody[thisNote],noteDuration);

    // чтобы выделить ноты, делаем между ними небольшую задержку.
    // в данном примере сделаем ее равной продолжительности ноты
    // плюс еще 30% от продолжительности ноты:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // останавливаем проигрывание мелодии:
    noTone(8);
  }

   Serial.begin(9600);
 // Serial.println("Waiting for card...");
  SPI.begin();  //  инициализация SPI / Init SPI bus.
  mfrc522.PCD_Init();     // инициализация MFRC522 / Init MFRC522 card.


}
void loop() 

{

  
  // Поиск новой метки
  if ( ! mfrc522.PICC_IsNewCardPresent()) {


   return;
  }
  // Выбор метки
  if ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
  }
  uidDec = 0;
  // Выдача серийного номера метки.
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    uidDecTemp = mfrc522.uid.uidByte[i];
    uidDec = uidDec * 256 + uidDecTemp;
  }
  //Serial.println();
  Serial.println(uidDec); // Выводим UID метки в консоль.

   lcd.clear ();
 lcd.setCursor(0,0);
 lcd.print ("OK: ");
 lcd.setCursor(3,0);
 lcd.print (uidDec);
     delay (100);
tone(piezoPin, 1000, 500);
digitalWrite(leda, LOW);
digitalWrite(ledb, HIGH);
delay(500);
digitalWrite(ledb, LOW);
delay(500);
digitalWrite(ledb, HIGH);
delay(500);
digitalWrite(ledb, LOW);
delay(500);
digitalWrite(ledb, HIGH);
delay(500);
digitalWrite(ledb, LOW);
delay(500);
digitalWrite(ledb, HIGH);
delay(500);
digitalWrite(ledb, LOW);
delay(500);
digitalWrite(ledb, HIGH);
delay(500);
digitalWrite(ledb, LOW);
delay(500);
digitalWrite(ledb, HIGH);
delay(500);
digitalWrite(ledb, LOW);
delay(500);



    lcd.clear ();
 lcd.setCursor(0,0);
  lcd.setCursor(2,0);
  lcd.print ("Card insert v1.1");
  lcd.setCursor(6,0);
  lcd.setCursor(8,0);
  lcd.setCursor(0,1);
 lcd.print ("New card please:");
 digitalWrite(leda, HIGH);
}
