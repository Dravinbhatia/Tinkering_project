
/*
 Stepper Motor Control -Automatic Garage_Door

 This program drives a unipolar or bipolar stepper motor.
 It will close the door for '1' input and open the door for '0' input.
 */

#include <Stepper.h>
#include <SoftwareSerial.h>


SoftwareSerial BT(0,1);
// creates a "virtual" serial port/UART
// connect BT module TX to D0
// connect BT module RX to D1
// connect BT Vcc to 5V, GND to GND
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
                                     // for your motor

// initialize the stepper library on pins:
Stepper myStepper(stepsPerRevolution, 5,6,9,10);

void setup() {
   BT.begin(9600);  // set the data rate for the SoftwareSerial port
   myStepper.setSpeed(60);  // set the speed at 60 rpm
   Serial.begin(9600);  // initialize the serial port
}
char a; // stores incoming character from other device

void loop() {
   if(BT.available())
   {
     // if text arrived in from BT serial...
     a=(BT.read());
     if(a=='1'){
          Serial.write(a);
        //clockwise direction
        for(int i=0;i<=9;i++)//{
          myStepper.step(stepsPerRevolution);
          //delay(20);}
        BT.write('1');
     }
     else if(a=='0'){
         Serial.write(a);
         // anti-clockwise direction
        for(int i=0;i<=9;i++)//{
          myStepper.step(-stepsPerRevolution);
          //delay(20);}
        BT.write('0'); 
     }
   }
}
