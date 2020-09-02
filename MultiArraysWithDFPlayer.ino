#include <FastLED.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define NUM_LEDS_PER_STRIP 70
#define BRIGHTNESS  200
#define LED1pin 5
#define LED2pin 6
#define LED3pin 7

const int IR1pin = A0;
const int IR2pin = A1;
const int IR3pin = A2;

CRGB LED1color[NUM_LEDS_PER_STRIP];
CRGB LED2color[NUM_LEDS_PER_STRIP];
CRGB LED3color[NUM_LEDS_PER_STRIP];

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup() 
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }

  pinMode(IR1pin, INPUT);
  pinMode(IR2pin, INPUT);
  pinMode(IR3pin, INPUT);
  
  myDFPlayer.volume(20);
  myDFPlayer.EQ(DFPLAYER_EQ_CLASSIC);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  
  FastLED.addLeds<NEOPIXEL, LED1pin>(LED1color, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, LED2pin>(LED2color, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, LED3pin>(LED3color, NUM_LEDS_PER_STRIP);
  FastLED.setBrightness(  BRIGHTNESS );

}

void loop() {
  if(digitalRead(IR1pin) == LOW)
  {
    LED1show();
  }
  if(digitalRead(IR2pin) == LOW)
  {
    LED2show();
  }
  if(digitalRead(IR3pin) == LOW)
  {
    LED3show();
  }
}

void LED1show()
{
  myDFPlayer.play(1);
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++)
    {
      LED1color[i] = CRGB::Purple;
      FastLED.show();
      LED1color[i] = CRGB::Black;
      delay(100);
    }
      
    for(int i = NUM_LEDS_PER_STRIP-1; i >= 0; i--)
    {
      LED1color[i] = CRGB::Green;
      FastLED.show();
      LED1color[i] = CRGB::Black;
      delay(100);
    }
    myDFPlayer.pause();
}

void LED2show()
{
  myDFPlayer.play(2);
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++)
    {
      LED2color[i] = CRGB::Purple;
      FastLED.show();
      LED2color[i] = CRGB::Black;
      delay(100);
    }
      
    for(int i = NUM_LEDS_PER_STRIP-1; i >= 0; i--)
    {
      LED2color[i] = CRGB::Green;
      FastLED.show();
      LED2color[i] = CRGB::Black;
      delay(100);
    }
    myDFPlayer.pause();
}

void LED3show()
{
  myDFPlayer.play(3);
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++)
    {
      LED3color[i] = CRGB::Purple;
      FastLED.show();
      LED3color[i] = CRGB::Black;
      delay(100);
    }
      
    for(int i = NUM_LEDS_PER_STRIP-1; i >= 0; i--)
    {
      LED3color[i] = CRGB::Green;
      FastLED.show();
      LED3color[i] = CRGB::Black;
      delay(100);
    }
    myDFPlayer.pause();
}
