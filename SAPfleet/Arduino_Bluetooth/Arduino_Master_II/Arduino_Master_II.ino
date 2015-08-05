// Basic Bluetooth sketch HC-05_AT_MODE_01
// Communicate with a HC-05 using the serial monitor
//
// The HC-05 defaults to communication mode when first powered on you will need to manually enter AT mode
// The default baud rate for AT mode is 38400
// See www.martyncurrey.com for details
//
 
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX. 
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
// 
 
char c = ' ';
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino is ready");
    Serial.println("Remember to select Both NL & CR in the serial monitor");
 
    // HC-05 default serial speed for AT mode is 38400
    BTserial.begin(38400);
//      BTserial.begin(9600);  
}
 
void loop() {

//PARA ENVIAR COMANDOS PARA O OBDII:

  // Ler a porta Serial do Arduino
  if (Serial.available()) {
    char inByte = Serial.read();
    BTserial.print(inByte);    //JANELA SERIAL PARA "Carriage return" (\r) e 38400 de baud rate
    
}
 
//PARA ENVIAR COMANDOS RECEBIDOS DO OBDII PARA O SERIAL MONITOR DO IDE:
 
if (BTserial.available()) {
  char recvChar;
  boolean prompt;
  prompt=false;

    while(!prompt){                                     //while no prompt 
       while ((BTserial.available()>0) && (!prompt)){       //while there is data and not prompt
          recvChar = BTserial.read();            //read from elm
          Serial.print(recvChar); 
          if (recvChar==62) { 
            prompt=true; Serial.println(""); Serial.println("------");
          }    //if received char is '>' then prompt is true
        }        
     }         
  }   
}
