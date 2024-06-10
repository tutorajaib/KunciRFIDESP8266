#define SS_PIN D2
#define RST_PIN D1
#define buzzer D8

#include <SPI.h>
#include <MFRC522.h>

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int statuss = 0;
int out = 0;
bool statusrelay = false;

void setup() 
{
  for(int i=0;i<3;i++){
  digitalWrite(buzzer,1);
  delay(200);
  digitalWrite(buzzer,0);
  delay(200);
  }
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  pinMode(D4,OUTPUT);
  digitalWrite(D4,0);
  pinMode(buzzer,OUTPUT);
}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.println();
  Serial.print(" UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();
  if (content.substring(1) == "D3 E4 33 10" ||
   content.substring(1) == "96 21 7F 5F" ||
   content.substring(1) == "73 63 CB FE" ||
   content.substring(1) == "97 C1 B7 89"
   ) 
  {
    prosesrelay();
    delay(1000);
  }
  
  else   {
    Serial.println(" Access Denied ");
    delay(3000);
  }
} 

void prosesrelay(){
  if(statusrelay){
  digitalWrite(D4,0);
  statusrelay = false;
  for(int i=0;i<1;i++){
      tone(buzzer,2500);
      delay(100);
      noTone(buzzer);
      delay(50);
      tone(buzzer,3000);
      delay(100);
      noTone(buzzer);
      delay(50);
  }
  }
  else{
  digitalWrite(D4,1);
  statusrelay = true;
  tone(buzzer,3000);
      delay(100);
      noTone(buzzer);
      delay(50);
      tone(buzzer,2500);
      delay(100);
      noTone(buzzer);
      delay(50);
  }
}
