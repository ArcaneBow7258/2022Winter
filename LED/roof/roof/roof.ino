/* Code assembly by Alvin Tran
 * Arduino Nano controlling 1 ultrabright Neopixel
 * Interfaced by a web app.
 * 
 * 
 * 
 * 
 * 
 */
//Include for neopixel controller
#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN 6  //pin fro neopixel

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIXEL_PIN, NEO_RGB + NEO_KHZ800);
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
    strip.setBrightness(100);
    strip.fill(strip.Color(0,0,0),0);
    strip.show(); // Initialize all pixels to 'off'

}



// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
   
    strip.fill(strip.gamma32(strip.ColorHSV((512 / 1023.0) * 65536 , 150, 200)),0);
    strip.show(); 

    
}
