#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    60
#define BRIGHTNESS   255


CRGB leds[NUM_LEDS];
void setup() {
  Serial.begin(9600);
  delay(3000);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  
}
void loop() 
{ 
  
 for (int x = 1; x<NUM_LEDS-1; x++){

    leds[x-2] = CRGB(150, 0, 0);
    leds[x-1] = CRGB(200, 0, 0);
    leds[x] = CRGB(255, 0, 0);
    leds[x+1] = CRGB(200, 0, 0);
    leds[x+2] = CRGB(150, 0, 0);

    FastLED.show();
    
    Serial.print("F -> ");
    Serial.println(x); 
    
    delay(20); 
    
    leds[x-2] = CRGB(0, 0, 0);
    leds[x-1] = CRGB(0, 0, 0);
    leds[x] = CRGB(0, 0, 0);
    leds[x+1] = CRGB(0, 0, 0);
    leds[x+2] = CRGB(0, 0, 0);
    
   
  } 
  for (int x = NUM_LEDS-1;x>=0; x--){
    
    leds[x-2] = CRGB(150, 0, 0);
    leds[x-1] = CRGB(200, 0, 0);
    leds[x] = CRGB(255, 0, 0);
    leds[x+1] = CRGB(200, 0, 0);
    leds[x+2] = CRGB(150, 0, 0);
    
    FastLED.show();
    Serial.print("B -> ");
    Serial.print(x);

    delay(20);
    
    leds[x-2] = CRGB(0, 0, 0);
    leds[x-1] = CRGB(0, 0, 0);
    leds[x] = CRGB(0, 0, 0);
    leds[x+1] = CRGB(0, 0, 0);
    leds[x+2] = CRGB(0, 0, 0);
      
  } 
  FastLED.show();
 
}
