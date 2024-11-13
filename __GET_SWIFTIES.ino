

// iR receiver pin
const int irPin = 10;

// RGB LED pins
const int LEDred = 3;
const int LEDgreen = 5;
const int LEDblue = 6;



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



////Control IR numbers TEST REMOTE SILVER
const long iRIN_botACTIVATION = 3409232445;
const long iRIN_botSTOP_R =     3409224285;
const long iRIN_botSTOP_G =     3409207965;
const long iRIN_botSTOP_B =     3409240605;
const long iRIN_botSTOP_RB =    3409240095;
const long iRIN_botSTOP_RG =    3409225815;
const long iRIN_botSTOP_BG =    3409219695;





// Veritables for setting leds 
void setLEDs(int colorValue, bool neoValue) {
  digitalWrite(LEDblue, BLUE & colorValue);
  digitalWrite(LEDgreen, GREEN & colorValue);
  digitalWrite(LEDred, RED & colorValue);
}

void stopAndSetLEDs(int colorValue) {
  setLEDs(colorValue, false);
}




void setup() {
////////////////////////////////////////////////////
/////////////////////////// DEBUG NOTE /////////////
//         for debugging led feeback, comment out...

  IrReceiver.begin(irPin, ENABLE_LED_FEEDBACK);
  IrReceiver.begin(irPin); // <-- THIS LINE

// WARNING! ledRED WILL NOT WORK IN DEBUG MODE // 
///////////////////////////////////////////////////  


  pinMode(LEDred, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDblue, OUTPUT);
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

      case iRIN_botACTIVATION:
        Serial.println("BOT ACTIVATION");
        stopAndSetLEDs(RED | BLUE | GREEN);
        break;

      case iRIN_botSTOP_R:{
        Serial.println("botSTOP_RED");
        stopAndSetLEDs(RED);
        delay(50);
       }
        break;
        
      case iRIN_botSTOP_G:{
        Serial.println("botSTOP_GREEN");
        stopAndSetLEDs(GREEN);
       }
        break;
        
      case iRIN_botSTOP_B:{
        Serial.println("botSTOP_BLUE");
        stopAndSetLEDs(BLUE);
       }
        break;
        
      case iRIN_botSTOP_RB:{
        Serial.println("botSTOP_RED_BLUE");
        stopAndSetLEDs(RED | BLUE);
       }
        break;
        
      case iRIN_botSTOP_RG:{
        Serial.println("botSTOP_RED_GREEN");
        stopAndSetLEDs(RED | GREEN);
       }
        break;
        
      case iRIN_botSTOP_BG:{
        Serial.println("botSTOP_BLUE_GREEN");
        stopAndSetLEDs(BLUE | GREEN);
       }
        break;


        


      default:
        break;
    }
  }
  }
