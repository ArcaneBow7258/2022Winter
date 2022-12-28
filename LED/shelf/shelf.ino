/* Code assembly by Alvin Tran
 * Arduino Nano controlling 60 LED / 1M Neopixel
 * Interfaced by a potentiometer and a button for color control and settings
 * 
 * 
 * 
 * 
 * 
 */
//Include for neopixel controller
#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN 6  //pin fro neopixel

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
// brightness controller
uint16_t bright_max = 100; //100 - breathe
uint16_t bright_min = 0; //duratiuon is difference between
uint16_t bright = bright_min;
uint16_t bright_breathe = 0;
uint16_t increasing = true;
float colours[] = {0, 106, 180, 250,330};
int motion = 0;
int breath = 0;
int inc = -0.1 ;
int breathDelay = 10;
int breathWait = 3000;



int buttonPin = 2;

void setup() {

    //
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
    //Initialize Strip
    strip.begin();
    strip.setBrightness(60);
    strip.fill(strip.Color(0,0,0),0);
    strip.show(); // Initialize all pixels to 'off'

}



// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
    //button stuff
    int reading = digitalRead(buttonPin);
    //Serial.println(reading);
    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH), and you've waited long enough
    // since the last press to ignore any noise:
  
    // If the switch changed, due to noise or pressing:
    if (reading != 0){
      //off = !off;
      motion = (motion + 1) % 3;
      delay(1000);
    }



    
    
    
    if (motion == 0){ //off
       strip.fill(strip.Color(0,0,0),0);
       breath = 0;
       strip.show(); // Initialize all pixels to 'off'
    
    }
    
    else { //breath
      float in = analogRead(A7);
      //Serial.println(in);
      if (motion ==1){
        strip.fill(strip.gamma32(strip.ColorHSV((in / 1023.0) * 65536 , 150, 200)),0);
        breath = 0;
      }
      
      if (motion == 2){
        if (breath == bright_max)
          {inc = -1;
           //delay(breathWait);
          }
          
        if (breath == bright_min){
          inc = 1;
          delay(breathWait);
        }
        breath += inc;
        strip.fill(strip.gamma32(strip.ColorHSV((in / 1023.0) * 65536 , 150, 200- breath)),0);
        delay(breathDelay);
      
      
      }
    strip.show();
    }

    
}
