#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    60

int y=1;
int z=1;
CRGB leds[NUM_LEDS];
void setup() {
  Serial.begin(9600);
  delay(3000);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  
}
void loop() 
{ 
  for (int x = y-1; x<NUM_LEDS-y; x++){
    
    leds[x] = CRGB(255, 0, 0);

    FastLED.show();
    
    Serial.print("F -> ");
    Serial.println(x); 
    
    delay(20); 
    
    leds[x] = CRGB(0, 0, 0);
    
   
  }
  if (z%2!=0){
    Serial.println("ODDDD");
    
    leds[NUM_LEDS-y] = CRGB(0, 255, 0);
    Serial.print("Loop -");
    Serial.print(NUM_LEDS-y);
  }
    
  z++;
  //Serial.println(z);
  
  for (int x = NUM_LEDS-y;x>=y-1; x--){
    
    leds[x] = CRGB(255, 0, 0);
    
    FastLED.show();
    Serial.print("B -> ");
    Serial.println(x);

    delay(20);
    
    leds[x] = CRGB(0, 0, 0);
      
  } 
  if (z%2==0){
    Serial.println("EVENNNN");
        
    leds[y] = CRGB(0, 255, 0);
    Serial.print("Loop - ");
    Serial.print(y);
    }
  z++;
  y++;
  FastLED.show(); 
}
