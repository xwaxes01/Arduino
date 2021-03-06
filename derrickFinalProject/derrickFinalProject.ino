#include<LCD.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Variables for the coinDetector fuction
int threshold = 1000;
int coinValue;
int previousState = 0;
int currentState = 1;
int coinInputPin = A0;

//Variables for the controllerModule function
String names [7] = {"1. Coke", "2. Fanta", "3. Fudge", "4. Wafer", "5. Candy Bar", "6. Chocolate", ""};
int upButton = 12;
int okButton = 11;
int downButton = 10;
int scrollDown = LOW; 
int scrollUp = LOW;
int select = LOW;
int counter = 0;
char pointer = '>';
int maintainer = 0;//Maintains the display until an item is purchased

// Variables for liquid dispensing
int solenoid0 = 3;
int solenoid1 = 4;

// Variables for motors
int motor0 = 5;
int motor1 =6 ;
int motor2 =7 ;
int motor3 = 8;
int motorTimer = 300;

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
//  Contol variables
  pinMode(coinInputPin, INPUT);
  pinMode(LED_BUILTIN,  OUTPUT);
  pinMode(upButton, INPUT);
  pinMode(okButton, INPUT);
  pinMode(downButton, INPUT);
  
  //  solids
  pinMode(motor0, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  
  //  liquids
  pinMode(solenoid0, OUTPUT);
  pinMode(solenoid1, OUTPUT);

  animator();
}
 
void loop(){
  coinDetector();
}
