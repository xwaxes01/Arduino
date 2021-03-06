#include <IRremote.h>
 
int IR_Recv = 2;   //IR Receiver Pin 2
int LED_R = 5;
int LED_G = 7;
int LED_Y = 6;

int lamp = 8;
int inputPin = 4; 

int Fan1 = 3; 
int Fan2 = 4;

int val = 0;

IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
  pinMode(LED_R, OUTPUT);      // sets the digital pin as output
  pinMode(LED_G, OUTPUT);      // sets the digital pin as output
   pinMode(LED_Y, OUTPUT);      // sets the digital pin as output 

   pinMode(lamp, OUTPUT); // declare lamp as output
  pinMode(inputPin, INPUT); // declare sensor as input
   
   pinMode (Fan1, OUTPUT);
  pinMode (Fan2, OUTPUT);
}
 
void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
Serial.println(results.value);
    //switch case to use the selected remote control button
    switch (results.value){
      case 21225: //when you press the Red button
      case 16195807: //when you press the Red button
        digitalWrite(LED_R, HIGH);
         digitalWrite(Fan2, HIGH);
        break;   
      
      case 16 : //when you press the 1 off button
      case 16191727 : //when you press the 1 off button 
     
        digitalWrite(LED_R, LOW);   
        digitalWrite(Fan2, LOW);
        break;
 
      
       case 13033: //when you press the Green button
       case 16720605: //when you press the Green button
        case 16736925 :
        digitalWrite(LED_G, HIGH);
        break;  

       case 2064: //when you press the Green button
       case 16738455:

        digitalWrite(LED_G, LOW);
        break;  
                

         case 29417: //when you press the yellow button
        digitalWrite(LED_Y, HIGH);
        break;           
       case 1040 : //when you press the 3 OFF button
        digitalWrite(LED_Y, LOW);
        break;
             
       case 2320: //when you press  0 the ALL OFF button
       case 16203967: //when you press  0 the ALL OFF button
       case 16730805 : //when you press  0 the ALL OFF button

        digitalWrite(LED_R, LOW);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_Y, LOW);
       
        break;
               
       case 112: //when you press Home the ALL ON button
       case 16236607: //when you press Home the ALL ON button
      case 16712445: //when you press Home the ALL ON button
       
       digitalWrite(LED_R, HIGH);
        digitalWrite(LED_G, HIGH);
        digitalWrite(LED_Y, HIGH);
       
        break;
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  delay(10);
}

void pir(){

val = digitalRead(inputPin); // read input value

Serial.println(val);

if( val== 1) {

digitalWrite(lamp,LOW); // turn ON the lamp

delay (1000);

digitalWrite(lamp,HIGH); // turn OFF the lamp


}
}
