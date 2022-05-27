// ##############################################
// # THE ROBÓTICO PROJECT - MARI AND DADDY WORK #
// #                                            #
// #     TKS MARI ABOUT THIS FUNNY IDEA!!!      #
// ##############################################
// 
// 
// This arduino sketch use parts of the original script of Mundo Inventivo  
// www.youtube.com/mundoinventivo writen by Gelson Leandro Kaul
// It'll avalible on my github repository

#include <Arduino.h> //I'm using the PlatformIO IDE for VSCode, so I need to import the Arduino library
#include <SoftwareSerial.h>

// Pin defination: usin pin 2 and 3 to Bluetooth Module (from now, I'll refere as hc05) we have the 
// Arduino serial port free to sync, so we don't need to disconnect the hc05 to upload the program.
#define rxPin 2 //rx pin from hc05 - don't forget the communication of hc05 use 3.3V, so you 
// MUST use a voltage divider to get 3.3V or 5V provided for Arduino out pin 
#define txPin 3 //tx pin from hc05
#define baudrate 9600 // the boudrate of communication. You can change it, but a lot of control apps use this boudrate

SoftwareSerial hc05(rxPin, txPin);
 
int HB_IN1 = 7;
int HB_IN2 = 6;
int HB_IN3 = 5;
int HB_IN4 = 4;
int HB_PWM_Left = 9; //PWM Pin
int HB_PWM_Right = 10; //PWM Pin
char Command;
 
void setup() {
  //here we'll define every PIN as we'll use and start the serial/bluetooth communication

  Serial.begin(9600); //start the serial port (we'll send some messages to debug the program)
  
  // pins of hc05 
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);

  hc05.begin(baudrate); // start hc05

  // pins of H Bridge DC motor control. We use the same name the circuit board use
  pinMode(HB_IN1, OUTPUT); 
  pinMode(HB_IN2, OUTPUT);
  pinMode(HB_IN3, OUTPUT);
  pinMode(HB_IN4, OUTPUT);
  pinMode(HB_PWM_Left, OUTPUT);
  pinMode(HB_PWM_Right, OUTPUT);
}
 
void loop() {

  while (hc05.available()) {

    if (hc05.available() > 0) {
        Serial.println("Communication is Ok!"); //If the comm is enabled and working, it'll print that's ok at serial monitor
        Serial.println(Command);
    }
    //At the first command you'll see some commented lines print the direction and de command at Serial Monitor.
    //If you need see the other commands, you can use it as source.

    Command = hc05.read();
    if (Command == 'F') {
        // Serial.println("Forward"); //this two lines print at screen (serial arduino screen) the procedure and command. 
        // Serial.println(Command);
      Forward(); //call the procedure Forward, there we'll write the commands to robot go forward
    }
    else if (Command == 'B') {
      Backward();
    }
    else if (Command == 'L') {
      Left();
    }
    else if (Command == 'R') {
      Right();
    }    
    else if (Command == 'I') {
      Right_Front();
    }    
    else if (Command == 'G') {
      Left_Front();
    }
    else {
      Stoped();
    }
  }
}
 
void Backward() {
  //Turn both motors on clockwise 
  analogWrite(HB_PWM_Left, 250);
  analogWrite(HB_PWM_Right, 250);
  digitalWrite(HB_IN1, LOW);
  digitalWrite(HB_IN2, HIGH);
  digitalWrite(HB_IN3, LOW);
  digitalWrite(HB_IN4, HIGH);

}
 
void Forward() {
  //Turn both motors on counterclockwise
  analogWrite(HB_PWM_Left, 250);
  analogWrite(HB_PWM_Right, 250);
  digitalWrite(HB_IN1, HIGH);
  digitalWrite(HB_IN2, LOW);
  digitalWrite(HB_IN3, HIGH);
  digitalWrite(HB_IN4, LOW);
}
 
void Left() {
  //Turn right motor counterclockwise and left motor clockwise
  analogWrite(HB_PWM_Left, 250);
  analogWrite(HB_PWM_Right, 250);
  digitalWrite(HB_IN1, LOW);
  digitalWrite(HB_IN2, HIGH);
  digitalWrite(HB_IN3, HIGH);
  digitalWrite(HB_IN4, LOW);
}
 
void Right() {
  //Turn left motor counterclockwise and right motor clockwise
  analogWrite(HB_PWM_Left, 250);
  analogWrite(HB_PWM_Right, 250);
  digitalWrite(HB_IN1, HIGH);
  digitalWrite(HB_IN2, LOW);
  digitalWrite(HB_IN3, LOW);
  digitalWrite(HB_IN4, HIGH);
}

void Right_Front() {
  //Turn both motors counterclockwise but the right fastest then left
  analogWrite(HB_PWM_Left, 70);
  analogWrite(HB_PWM_Right, 250);
  digitalWrite(HB_IN1, HIGH);
  digitalWrite(HB_IN2, LOW);
  digitalWrite(HB_IN3, HIGH);
  digitalWrite(HB_IN4, LOW);
}

void Left_Front() {
  //Turn both motors counterclockwise but the left fastest then lefright
  analogWrite(HB_PWM_Left, 250);
  analogWrite(HB_PWM_Right, 70);
  digitalWrite(HB_IN1, HIGH);
  digitalWrite(HB_IN2, LOW);
  digitalWrite(HB_IN3, HIGH);
  digitalWrite(HB_IN4, LOW);
}

void Stoped() {
  //Stop all motors if anyother key is pressed
  digitalWrite(HB_IN1, LOW);
  digitalWrite(HB_IN2, LOW);
  digitalWrite(HB_IN3, LOW);
  digitalWrite(HB_IN4, LOW);
}