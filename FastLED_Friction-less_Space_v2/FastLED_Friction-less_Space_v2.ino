#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    60

//int y=1;
int z=1;
CRGB leds[NUM_LEDS];
void setup() {
  Serial.begin(9600);
  delay(3000);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  
}
void loop() 
{ 
  
  for (int y=1;y <= 30; y++){
    Game_Loop(y);    
    }
 
 /* for (int b = 30; b>=0; b--){
    
    Serial.print("OOOO  -  ");
    Serial.println(b);
    leds[b] = CRGB(255, 0, 0);
    //leds[60-b+1] = CRGB(255, 0, 0);
  } */
  
  for (int D = 30; D>=0; D--){

    leds[NUM_LEDS-D+1] = CRGB(255, 0, 0); //31,32,33,34...
    Serial.print("Front -");
    Serial.println(NUM_LEDS-D+1);
    
    leds[D] = CRGB(255, 0, 0); //30, 29, 28, ...
    Serial.print("Back - ");
    Serial.println(D);
    
    FastLED.show();
  }

  for (int D = 30; D>=0; D--){

    leds[NUM_LEDS-D+1] = CRGB(0, 0, 0); //31,32,33,34...
    Serial.print("Front -");
    Serial.println(NUM_LEDS-D+1);
    
    leds[D] = CRGB(0, 0, 0); //30, 29, 28, ...
    Serial.print("Back - ");
    Serial.println(D);
    
    FastLED.show();
  }
  
}

void Game_Loop(int y){
  
  for (int x = y; x<NUM_LEDS-y; x++){
    
    leds[x] = CRGB(255, 0, 0);
    /*
    for (int y=1; y<z;y++){
      leds[z-y] = CRGB(0, 255, 0);
      Serial.print(" Loop -");
      Serial.print(y);
    }
    */
    FastLED.show();
    
    Serial.print("F -> ");
    Serial.println(x); 
    
    delay(20); 
    
    leds[x] = CRGB(0, 0, 0);
    
   
  }
  if (z%2!=0){
    Serial.print("ODDDD");
    
    leds[NUM_LEDS-y] = CRGB(0, 255, 0);
    Serial.print("Loop -");
    Serial.println(NUM_LEDS-y);
  }
    
  z++;
  //Serial.println(z);
  
  for (int x = NUM_LEDS-y-1;x>=y-1; x--){
    
    leds[x] = CRGB(255, 0, 0);
    /*
    for (int y=1; y<z;y++){
      leds[x-z+1+y] = CRGB(0, 255, 0);
      Serial.print(" Loop -");
      Serial.print(y);
    }
    */
    
    FastLED.show();
    Serial.print("B -> ");
    Serial.print(x);

    delay(20);
    
    leds[x] = CRGB(0, 0, 0);
      
  } 
  if (z%2==0){
    Serial.print (" EVENNNN");
        
    leds[y-1] = CRGB(0, 255, 0);
    Serial.print("Loop - ");
    Serial.println(y);
    }
  z++;  
  FastLED.show();
  
}
