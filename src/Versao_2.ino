// This arduino sketch use parts of the original script of Mundo Inventivo  
// www.youtube.com/mundoinventivo writen by Gelson Leandro Kaul
// It'll avalible on my github repository

#include <Arduino.h> //I'm using the PlatformIO IDE for VSCode, so I need to import the Arduino library
#include <SoftwareSerial.h>
#define rxPin 2
#define txPin 3
#define baudrate 9600

SoftwareSerial hc05(rxPin, txPin);
 
int IN1 = 7;
int IN2 = 6;
int IN3 = 5;
int IN4 = 4;
int PWML = 9;
int PWMR = 10;
int COM = 11;
int MOT = 12;
char comando;
 
void setup() {

  Serial.begin(9600);
  
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  hc05.begin(baudrate);
  //Define os pinos como saida

  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(PWMR, OUTPUT);
  pinMode(COM, OUTPUT);
  pinMode(MOT, OUTPUT);
}
 
void loop() {

  while (hc05.available()) {

    if (hc05.available() > 0) {
        Serial.println("Tem Comunicação");
    }
    
    comando = hc05.read();
    if (comando == 'F') {
        Serial.println("Frente");
        Serial.println(comando);
      frente();
    }
    else if (comando == 'B') {
      Serial.println("Trás");
      Serial.println(comando);
      tras();
    }
    else if (comando == 'L') {
      Serial.println("Esquerda");
      Serial.println(comando);
      esquerda();
    }
    else if (comando == 'R') {
      Serial.println("Direita");
      Serial.println(comando);
      direita();
    }
    else {
      Serial.println("Parado");
      Serial.println(comando);
      parado();
    }
  }
}
 
void tras() {
  //Gira o Motor A e B no sentido horario
  analogWrite(PWML, 180);
  analogWrite(PWMR, 180);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
 
void frente() {
  //Gira o Motor A e B no sentido anti-horario
  analogWrite(PWML, 180);
  analogWrite(PWMR, 180);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
 
void esquerda() {
  analogWrite(PWML, 180);
  analogWrite(PWMR, 180);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
 
void direita() {
  analogWrite(PWML, 180);
  analogWrite(PWMR, 180);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void parado() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
// O PROGRAMA DO RALABÔ TERMINA AQUI
