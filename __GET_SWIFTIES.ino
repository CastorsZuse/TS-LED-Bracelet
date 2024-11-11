// iR receiver pin
const int irPin = 10;

// RGB LED pins
const int LEDred = 3;
const int LEDgreen = 5;
const int LEDblue = 6;
const int NEOIO = A4;

// Veritables for color set
enum Color : int {
  RED   = 1,
  GREEN = 2,
  BLUE  = 4
};

//Variables for IR Receiver
#define DECODE_NEC
#include <IRremote.h>
unsigned long current_code = 0;



//Control IR numbers 3.0 UPDATE
//const long iRIN_botACTIVATION = 3409232445;
//const long iRIN_botSTOP_R =     3409195215;
//const long iRIN_botSTOP_G =     3409214085;
//const long iRIN_botSTOP_B =     3409189095;
//const long iRIN_botSTOP_RB =    3409187055;
//const long iRIN_botSTOP_RG =    3409197255;
//const long iRIN_botSTOP_BG =    3409205925;
//const long iRIN_botBumpLEFT =   3409224285;
//const long iRIN_botSTALL =      3409207965;
//const long iRIN_botBumpRIGHT =  3409240605;
//const long iRIN_botNOPEleft =   3409240095;
//const long iRIN_botNOPEback  =  3409225815;
//const long iRIN_botNOPEright =  3409219695;

//Control IR numbers TEST REMOTE
const long iRIN_botACTIVATION = 3158572800;
const long iRIN_botSTOP_R =     4077715200;
const long iRIN_botSTOP_G =     3877175040;
const long iRIN_botSTOP_B =     2707357440;
const long iRIN_botSTOP_RB =    4144561920;
const long iRIN_botSTOP_RG =    3810328320;
const long iRIN_botSTOP_BG =    2774204160;
const long iRIN_botBumpLEFT =   3125149440;
const long iRIN_botSTALL =      3108437760;
const long iRIN_botBumpRIGHT =  3091726080;
const long iRIN_botNOPEleft =   4161273600;
const long iRIN_botNOPEback  =  3927310080;
const long iRIN_botNOPEright =  4127850240;


// Veritables for setting leds 
void setLEDs(int colorValue, bool neoValue) {
  digitalWrite(LEDblue, BLUE & colorValue);
  digitalWrite(LEDgreen, GREEN & colorValue);
  digitalWrite(LEDred, RED & colorValue);

}

void SetLEDs(int colorValue) {
  setLEDs(colorValue, false);
}


void setup() {

  pinMode(LEDred, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDblue, OUTPUT);
  pinMode(NEOIO, OUTPUT);
  IrReceiver.enableIRIn();
  Serial.begin(9600);
}

void loop() {

  if (IrReceiver.decode()){
    current_code = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("New code received: ");
    Serial.println(current_code);
    IrReceiver.resume();        

    switch (current_code) { 
      

      case iRIN_botSTOP_R:
      SetLEDs(RED);
        break;
        
      case iRIN_botSTOP_G:
      SetLEDs(GREEN);
        break;
        
      case iRIN_botSTOP_B:
       SetLEDs(BLUE);
        break;
        
      case iRIN_botSTOP_RB:
       SetLEDs(RED | BLUE);
        break;
        
      case iRIN_botSTOP_RG:
       SetLEDs(RED | GREEN);
        break;
        
      case iRIN_botSTOP_BG:
       SetLEDs(BLUE | GREEN);
        break;

      case iRIN_botBumpLEFT:
       SetLEDs(RED | BLUE | GREEN);

       break;
        
     
      default:
        break;
    }
  }
}


 
