// BUMP CODE
// NOPE CODES
// UPDATED TO 3.0 LIB
// UNIFIED LANGUAGE ACROSS CODES

#include <Arduino.h>
#include <ButtonDebounce.h>
#include <IRremote.h>

#if defined(ARDUINO_ARCH_SAMD)
#define Serial SerialUSB
#endif

const int LED_0 = 9;
const int LED_1 = 8;
const int LED_2 = 7;
const int LED_3 = A2;
const int LED_4 = A1;
const int LED_5 = A0;
const int LED_6 = 15;
const int LED_7 = 14;
const int LED_8 = 16;
const int LED_9 = 10;

const int buttonACTIVATION = 6; 
const int buttonLEFT = 4;
const int buttonSTALL = 3;
const int buttonRIGHT = 2;
const int buttonNOPEleft = 0;
const int buttonNOPEback = 1;
const int buttonNOPEright = A3;
const int IR_SEND_PIN = 5;
const int debounceDelay = 50;
int buttonState = 0;   

   void sequence(){
    digitalWrite(LED_0, HIGH);
    delay(10);
    digitalWrite(LED_1, HIGH);
    delay(10);
    digitalWrite(LED_2, HIGH);
    delay(10);
    digitalWrite(LED_3, HIGH);
    delay(10);
    digitalWrite(LED_4, HIGH);
    delay(10);
    digitalWrite(LED_5, HIGH);
    delay(10);
    digitalWrite(LED_6, HIGH);
    delay(10);
    digitalWrite(LED_7, HIGH);
    delay(10);
    digitalWrite(LED_8, HIGH);
    delay(10);
    digitalWrite(LED_9, HIGH);
    delay(10);

    digitalWrite(LED_0, LOW);
    delay(10);
    digitalWrite(LED_1, LOW);
    delay(10);
    digitalWrite(LED_2, LOW);
    delay(10);
    digitalWrite(LED_3, LOW);
    delay(10);
    digitalWrite(LED_4, LOW);
    delay(10);
    digitalWrite(LED_5, LOW);
    delay(10);
    digitalWrite(LED_6, LOW);
    delay(10);
    digitalWrite(LED_7, LOW);
    delay(10);
    digitalWrite(LED_8, LOW);
    delay(10);
    digitalWrite(LED_9, LOW);
    delay(10);
   }
       
       
void setup() {
    pinMode(LED_0, OUTPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    pinMode(LED_4, OUTPUT);
    pinMode(LED_5, OUTPUT);
    pinMode(LED_6, OUTPUT);
    pinMode(LED_7, OUTPUT);
    pinMode(LED_8, OUTPUT);
    pinMode(LED_9, OUTPUT);
    pinMode(buttonRIGHT, INPUT);
    pinMode(buttonLEFT, INPUT);
    pinMode(buttonSTALL, INPUT);
    pinMode(buttonNOPEleft, INPUT);
    pinMode(buttonNOPEback, INPUT);
    pinMode(buttonNOPEright, INPUT);
    pinMode(buttonACTIVATION, INPUT);

////////////////////////////////////////////////
//LED RING START UP SEQUENCE 
////////////////////////////////////////////////
    
    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_9, HIGH);
    delay (100);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_8, HIGH);
    delay (100);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_7, HIGH);
    delay (100);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_6, HIGH);
    delay (100);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, HIGH);
    delay (250);

    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, HIGH);
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_9, HIGH);
    delay(100);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);
    digitalWrite(LED_8, LOW);
    digitalWrite(LED_9, LOW);
    delay(100);
    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, HIGH);
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_9, HIGH);
    delay(100);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);
    digitalWrite(LED_8, LOW);
    digitalWrite(LED_9, LOW);
    delay(100);
    digitalWrite(LED_0, HIGH);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, HIGH);
    digitalWrite(LED_6, HIGH);
    digitalWrite(LED_7, HIGH);
    digitalWrite(LED_8, HIGH);
    digitalWrite(LED_9, HIGH);
    delay(100);
    digitalWrite(LED_0, LOW);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    digitalWrite(LED_5, LOW);
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_7, LOW);
    digitalWrite(LED_8, LOW);
    digitalWrite(LED_9, LOW);
    delay(100);
    digitalWrite(LED_9, HIGH);
    delay (50);
    digitalWrite(LED_8, HIGH);
    delay (50);
    digitalWrite(LED_7, HIGH);
    delay (50);
    digitalWrite(LED_6, HIGH);
    delay (50);
    digitalWrite(LED_5, HIGH);
    delay (50);
    digitalWrite(LED_4, HIGH);
    delay (50);
    digitalWrite(LED_3, HIGH);
    delay (50);
    digitalWrite(LED_2, HIGH);
    delay (50);
    digitalWrite(LED_1, HIGH);
    delay (50);
    digitalWrite(LED_0, HIGH);
    delay (50);
    digitalWrite(LED_9, LOW);
    delay (50);
    digitalWrite(LED_8, LOW);
    delay (50);
    digitalWrite(LED_7, LOW);
    delay (50);
    digitalWrite(LED_6, LOW);
    delay (50);
    digitalWrite(LED_5, LOW);
    delay (50);
    digitalWrite(LED_4, LOW);
    delay (50);
    digitalWrite(LED_3, LOW);
    delay (50);
    digitalWrite(LED_2, LOW);
    delay (50);
    digitalWrite(LED_1, LOW);
    delay (50);
    digitalWrite(LED_0, LOW);
    delay(750);

////////////////////////////////////////////////
//END STATRT UP SEQUENCES 
////////////////////////////////////////////////
    
    Serial.begin(115200);
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) || defined(SERIAL_PORT_USBVIRTUAL)  || defined(ARDUINO_attiny3217)
    delay(1000); // To be able to connect Serial monitor after reset or power up and before first printout
#endif
    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin

    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}
uint32_t botACTIVATION = 0xFFC23D; // BOTS ON
uint32_t botBumpRIGHT  = 0xFFE21D; // BOT BUMP RIGHT
uint32_t botBumpLEFT   = 0xFFA25D; // BOT BUMP LEFT
uint32_t botSTALL      = 0xFF629D; // BOT SWITCHES TO REVERSE 
uint32_t botNOPEleft   = 0xFFE01F; // BOT 90 LEFT 
uint32_t botNOPEback   = 0xFFA857; // BOT 180
uint32_t botNOPEright  = 0xFF906F; // BOT 90 RIGHT

uint8_t nbits = 32;
uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

  void loop() {
    if (digitalRead(buttonACTIVATION) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(botACTIVATION, sCommand, sRepeats);
    sequence();
}

    if (digitalRead(buttonRIGHT) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(botBumpRIGHT, sCommand, sRepeats);
    sequence();
}

    if (digitalRead(buttonLEFT) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(botBumpLEFT, sCommand, sRepeats);
    sequence();
}

    if (digitalRead(buttonSTALL) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(botSTALL, sCommand, sRepeats);
    sequence();
}

    if (digitalRead(buttonNOPEleft) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(botNOPEleft, sCommand, sRepeats);
    sequence();
}

    if (digitalRead(buttonNOPEright) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(botNOPEright, sCommand, sRepeats);
    sequence();
}

    if (digitalRead(buttonNOPEback) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(botNOPEback, sCommand, sRepeats);
    sequence();
}
}
