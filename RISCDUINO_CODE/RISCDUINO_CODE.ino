#include <Servo.h>
#include<LiquidCrystal.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

LiquidCrystal lcd(13,8,12,11,10,4);

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;

char incomingChar =0;

void setup() {
  myservo1.write(0); 
  myservo2.write(0); 
  myservo3.write(0); 
  myservo4.write(0);
  myservo1.attach(21);
  myservo2.attach(22);
  myservo3.attach(23);
  myservo4.attach(24);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Please scan QR"); // Display the initial message

}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming character
    incomingChar = Serial.read();
    Serial.println(incomingChar);
  }
//----------------------------------------------------------------------
  if (incomingChar == 'A' || incomingChar == 'B') {
    lcd.clear(); // Clear the LCD
    lcd.setCursor(0, 0); // Set the cursor to the first line
    lcd.print("Please take"); // Display "Please take" on the first line
    lcd.setCursor(0, 1); // Set the cursor to the second line
    lcd.print("medicines"); // Display "medicines" on the second line
    delay(2000); // Display the message for 2 seconds
   
  
   if(incomingChar == 'A') {   
    
   myservo1.write(90);
    delay(1000);
   myservo1.write(0);
   delay(1000);
    myservo2.write(90);
    delay(1000);
    myservo2.write(0);
    delay(2000);
    incomingChar = '0';
  }
//-----------------------------------------------------------------  
  
  
  if(incomingChar =='B')
  {   
    myservo3.write(90);
    delay(1000);
   myservo3.write(0);
   delay(1000);
    myservo4.write(90);
    delay(1000);
    myservo4.write(0);
    delay(2000);
    incomingChar = '0';
}  
      lcd.clear(); // Clear the LCD
    lcd.setCursor(0, 0); // Set the cursor to the first line
       
    lcd.print("Thank you"); // Display "Thank you" on the first line
    delay(2000); // Display the message for 2 seconds
    lcd.clear(); // Clear the LCD
    lcd.setCursor(0, 0); // Set the cursor to the first line
    lcd.print("Please Scan QR");
    
  }
  


  
    
  if (incomingChar != '0') {
    lcd.clear(); // Clear the LCD
    lcd.setCursor(0, 0); // Set the cursor to the first line
    lcd.print("Invalid QR code"); // Display "Invalid QR code"
    delay(2000); // Display the message for 2 seconds
    lcd.clear(); // Clear the LCD
    lcd.setCursor(0, 0); // Set the cursor to the first line
    lcd.print("Please scan QR"); // Display the initial message
    incomingChar = '0'; // Reset incomingChar
  }
  
  
  
 
}