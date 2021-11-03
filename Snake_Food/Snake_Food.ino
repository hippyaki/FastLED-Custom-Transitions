#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    60

int z=1;
CRGB leds[NUM_LEDS];
void setup() {
  Serial.begin(9600);
  delay(3000);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  
}
void loop() 
{ 
  for (int x = z;x<NUM_LEDS; x++){
    
    leds[x] = CRGB(255, 0, 0);
    
    for (int y=1; y<z;y++){
      leds[x-y] = CRGB(0, 255, 0);
      Serial.print(" Loop -");
      Serial.print(y);
    }
    
    FastLED.show();
    
    Serial.print("- F -> ");
    Serial.println(x); 
    
    delay(20-z); 
    
    leds[x] = CRGB(0, 0, 0);
    
    for (int y=1; y<z;y++){
      leds[x-y] = CRGB(0, 0, 0);
    }
  }
  z++;
  //Serial.println(z);

}
