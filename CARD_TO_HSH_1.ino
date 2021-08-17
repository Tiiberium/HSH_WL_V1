#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
int leda = 7;
int ledb = 8;
LiquidCrystal_I2C lcd(0x27,16,2); 
int interval1 = 0;
int interval2 = 0;
MFRC522 mfrc522(SS_PIN, RST_PIN);
unsigned long uidDec, uidDecTemp;

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

   Serial.begin(9600);
 // Serial.println("Waiting for card...");
  SPI.begin();  //  инициализация SPI / Init SPI bus.
  mfrc522.PCD_Init();     // инициализация MFRC522 / Init MFRC522 card.


}
void loop() {
  // Ожидание
  if ( ! mfrc522.PICC_IsNewCardPresent())
    return;

  // чтение
  if ( !mfrc522.PICC_ReadCardSerial())
    return;

  // вывод данных
  Serial.print("UID = ");
  view_data(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println();
  Serial.print("type = ");
  byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  Serial.print(mfrc522.PICC_GetTypeName(piccType));
  Serial.println();
  delay(1000);
}

// преобразование в HEX
void view_data (byte *buf, byte size) {
  for (byte j = 0; j < size; j++) {
    Serial.print(buf [j]);
    Serial.print(buf [j], HEX);
  }


   lcd.clear ();
 lcd.setCursor(0,0);
 lcd.print ("OK: ");
 lcd.setCursor(3,0);
 lcd.print (uidDec);
     delay (100);
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
