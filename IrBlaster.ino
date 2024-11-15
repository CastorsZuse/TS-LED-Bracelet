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

const int SignalWhite = 6; 
const int SignalRed = 4;
const int SignalGreen = 3;
const int SignalBlue = 2;
const int SignalRedBlue = 0;
const int SignalRedGreen = 1;
const int SignalBlueGreen = A3;
const int IR_SEND_PIN = 5;
const int debounceDelay = 50;
int buttonState = 0;    

       
       
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
    pinMode(SignalBlue, INPUT);
    pinMode(SignalRed, INPUT);
    pinMode(SignalGreen, INPUT);
    pinMode(SignalRedBlue, INPUT);
    pinMode(SignalRedGreen, INPUT);
    pinMode(SignalBlueGreen, INPUT);
    pinMode(SignalWhite, INPUT);


    
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
uint32_t White = 0xFFC23D; 
uint32_t Blue  = 0xFFE21D; 
uint32_t Red   = 0xFFA25D;
uint32_t Green      = 0xFF629D; 
uint32_t RedBlue   = 0xFFE01F;
uint32_t RedGreen   = 0xFFA857; 
uint32_t BlueGreen  = 0xFF906F; 

uint8_t nbits = 32;
uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

  void loop() {
    if (digitalRead(SignalWhite) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(White, sCommand, sRepeats);
}

    if (digitalRead(SignalBlue) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(Blue, sCommand, sRepeats);
}

    if (digitalRead(SignalRed) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(Red, sCommand, sRepeats);
}

    if (digitalRead(SignalGreen) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(Green, sCommand, sRepeats);
}

    if (digitalRead(SignalRedBlue) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(RedBlue, sCommand, sRepeats);
}

    if (digitalRead(SignalBlueGreen) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(RedGreen, sCommand, sRepeats);
}

    if (digitalRead(SignalRedGreen) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(BlueGreen, sCommand, sRepeats);
}
}
