#include <Servo.h> // Include the Servo library for controlling servos
#include<LiquidCrystal.h> // Include the LiquidCrystal library for LCD display
Servo myservo1; // Create a Servo object for servo 1
Servo myservo2; // Create a Servo object for servo 2
Servo myservo3; // Create a Servo object for servo 3
Servo myservo4; // Create a Servo object for servo 4

LiquidCrystal lcd(13,8,12,11,10,4); //LiquidCrystal object for the LCD display with pin connections

int pos1 = 0;  // Initialize a variable to store the position of servo 1
int pos2 = 0;  // Initialize a variable to store the position of servo 2
int pos3 = 0;  // Initialize a variable to store the position of servo 3
int pos4 = 0;  // Initialize a variable to store the position of servo 4

char incomingChar =0;

void setup() {
  myservo1.write(0); // Set servo 1 to the initial position (0 degrees)
  myservo2.write(0); // Set servo 2 to the initial position (0 degrees)
  myservo3.write(0); // Set servo 3 to the initial position (0 degrees)
  myservo4.write(0); // Set servo 4 to the initial position (0 degrees)

  myservo1.attach(3); // Attach servo 1 to digital pin 3
  myservo2.attach(5); // Attach servo 2 to digital pin 5
  myservo3.attach(6); // Attach servo 3 to digital pin 6
  myservo4.attach(9); // Attach servo 4 to digital pin 9

  Serial.begin(9600);  // Initialize serial communication at 9600 baud
  lcd.begin(16,2);    // Initialize the LCD display with 16 columns and 2 rows
  lcd.print("Please scan QR"); // Display the initial message on LCD

}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming character from serial communication
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
   
  // A set of two motors is used
  //Motor 1 is used to open a flap, which releases the bottle (the plane on which the bottles are, is inclined so the bottle falls due to gravity)
  //After the bottle falls, Motor 1 closes the flap attached to it
  //Motor 2 opens its flap so that the bottle next in line can take the place of the previous bottle
  //After the bottle rolls into position, the flap is closed to isolate the other bottles from this bottle
  // 'A'  stands for medicine 1
   if(incomingChar == 'A') {   //If it is medicine A, then commence the following motor operations
    
   myservo1.write(90);     //motor1 flap open
    delay(1000);
   myservo1.write(0);    //motor 1 flap close
   delay(1000);
    myservo2.write(90);   //motor 2 flap open
    delay(1000);
    myservo2.write(0);  //motor 2 flap close
    delay(2000);
    incomingChar = '0';
  }
//-----------------------------------------------------------------  
 // 'B' stands for medicine 2 and uses two motors for the same functionality as above. 
  
  if(incomingChar =='B')    //If it is medicine B, then commence the following motor operations
  {
    
    myservo3.write(90);   //motor 3 flap open
    delay(1000);
   myservo3.write(0);     // motor 3 flap close
   delay(1000);
    myservo4.write(90);   // motor 4 flap open
    delay(1000);
    myservo4.write(0);      //motor 4 flap close
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
  


  
   // If the medicine for the QR code that is scanned is not available, then show "not available" on the LCD screen
  if (incomingChar != '0') {
    lcd.clear(); // Clear the LCD
    lcd.setCursor(0, 0); // Set the cursor to the first line
    lcd.print("Not Available"); // Display "Invalid QR code"
    delay(2000); // Display the message for 2 seconds
    lcd.clear(); // Clear the LCD
    lcd.setCursor(0, 0); // Set the cursor to the first line
    lcd.print("Please scan QR"); // Display the initial message
    incomingChar = '0'; // Reset incomingChar
  }
  
   
 
}