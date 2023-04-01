#include <Adafruit_Fingerprint.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
char input[12];
int count = 0;
int a = 0;

SoftwareSerial mySerial(2,3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
void setup()
{
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  Serial.begin(9600);
   mySerial.begin(9600);
   finger.begin(57600);
    delay(5);
     if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);

  finger.getTemplateCount();

  if (finger.templateCount == 0) {
    Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  }
  else {
    Serial.println("Waiting for valid finger...");
      Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  }
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  Fingerprint  ");
  lcd.setCursor(0, 1);
  lcd.print("     based     ");
  delay(1000);
  lcd.clear();
   lcd.setCursor(0, 0);
  lcd.print("  Car Ignition  ");
  lcd.setCursor(0, 1);
  lcd.print("     System     ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Please swipe           ");
  lcd.setCursor(0, 1);
  lcd.print("Your License          ");
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
          
}
void loop()
{
  if (Serial.available())
  {
    count = 0;
    while (Serial.available() && count < 12)
    {
      input[count] = Serial.read();
      count++;
      delay(5);
    }
    if (count == 12)
    {
      Serial.println(input);
      if ((strncmp(input, "2F0035FCF214", 12) == 0) && (a == 0))
      {
        lcd.setCursor(0, 0);
        lcd.print("License Valid         ");
        lcd.setCursor(0, 1);
        lcd.print("Welcome               ");
        delay(1000);
        a = 1;
        fingerprint();
      }
      else if ((strncmp(input, "0B0028883E95", 12) == 0) && (a == 0))
      {
        lcd.setCursor(0, 0);
        lcd.print("License Valid         ");
        lcd.setCursor(0, 1);
        lcd.print("Welcome                ");
        digitalWrite(13,HIGH);
           delay(1000);
          digitalWrite(13,LOW);
      
        a = 1;
        fingerprint();
      }
      else
      {
        if (a != 1)
        {
          lcd.setCursor(0, 0);
          lcd.print("License Invalid         ");
          lcd.setCursor(0, 1);
          lcd.print("Try Again!!!            ");
          digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Please swipe           ");
          lcd.setCursor(0, 1);
          lcd.print("Your License          ");
        }
      }
    }
  }
}
int getFingerprintID()
{
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;
  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  return finger.fingerID;
}
void fingerprint()
{
  
        while(a==1)
        {
        int fingerprintID = getFingerprintID();
        delay(50);
        if (fingerprintID == 1)
        {
          lcd.setCursor(0, 0);
          lcd.print("Access Granted        ");
          lcd.setCursor(0, 1);
          lcd.print("Vehicle Started       ");
          digitalWrite(9,HIGH);
          digitalWrite(10,LOW);
           digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          while(1);
        }
        else if (fingerprintID == 2)
        {
          lcd.setCursor(0, 0);
          lcd.print("Access Granted        ");
          lcd.setCursor(0, 1);
          lcd.print("Vehicle Started       ");
          digitalWrite(9,HIGH);
          digitalWrite(10,LOW);
          while(1);
        }
         else if (fingerprintID == 3)
        {
          lcd.setCursor(0, 0);
          lcd.print("Access Granted        ");
          lcd.setCursor(0, 1);
          lcd.print("Vehicle Started       ");
          digitalWrite(9,HIGH);
          digitalWrite(10,LOW);
           digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          while(1);
        }
         else if (fingerprintID == 4)
        {
          lcd.setCursor(0, 0);
          lcd.print("Access Granted        ");
          lcd.setCursor(0, 1);
          lcd.print("Vehicle Started       ");
           digitalWrite(13,HIGH);
           delay(1000);
          digitalWrite(13,LOW);
          delay(100);
          digitalWrite(9,HIGH);
          digitalWrite(10,LOW);
           digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          while(1);
        }
         else if (fingerprintID == 5)
        {
          lcd.setCursor(0, 0);
          lcd.print("Access Granted        ");
          lcd.setCursor(0, 1);
          lcd.print("Vehicle Started       ");
          digitalWrite(6,HIGH);
           digitalWrite(13,HIGH);
           delay(1000);
          digitalWrite(13,LOW);
          delay(100);
          digitalWrite(9,HIGH);
          digitalWrite(10,LOW);
           digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          while(1);
        }
        else
        {
           
          lcd.setCursor(0, 0);
          lcd.print("Pls Place a        ");
          lcd.setCursor(0, 1);
          lcd.print("Valid Finger       ");
          digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
          digitalWrite(13,HIGH);
           delay(100);
          digitalWrite(13,LOW);
          delay(100);
        }
        }
}
