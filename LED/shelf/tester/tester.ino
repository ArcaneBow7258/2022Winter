//Include for neopixel controller
#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN 6  //pin fro neopixel

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
// brightness controller
uint16_t bright_turn = 50;
uint16_t bright_min = 50;
uint16_t bright = bright_min;
uint16_t bright_breathe = 0;
uint16_t increasing = true;
float colours[] = {0, 106, 180, 250,330};
int motion = 0;
int breath = 0;
int inc = -1 ;
int idx = 0;
int len = 30;
int addy[30] = {};
int m = 0;
void setup() {

    Serial.begin(9600);
    //Initialize Strip
    strip.begin();
    strip.setBrightness(100);
    strip.fill(strip.Color(0,0,0),0);
    strip.fill(strip.gamma32(strip.ColorHSV((512/ 1023.0) * 65536 , 150, 100)),0);
    strip.show(); // Initialize all pixels to 'off'
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  //pick random address to lighten
  for(int i = 0; i < len; i++){
    addy[i] = random(60);
    //randomSeed(analogRead(A1));
    Serial.print(addy[i]);
    Serial.print(' ');
    
  }
  
  for(int i = 0; i < 100;  i++){
    for(int j = 0; j < len; j++){
       
       
       strip.setPixelColor(addy[j],strip.gamma32(strip.ColorHSV((256 / 1023.0) * 65536 , 150, 100 + i)));
       
    }
    delay(10);
    
    //
    strip.show();
    m = i + 100;
  }
  for(int i = 0; i < 100;  i++){
    for(int j = 0; j < len; j++){
       
       
       strip.setPixelColor(addy[j],strip.gamma32(strip.ColorHSV((256 / 1023.0) * 65536 , 150, m - i)));
       
    }
    delay(10);
    
    //
    strip.show();
  }
  delay(500);
  Serial.println("break");
  Serial.println(addy[0]);
  
  
    
}
  
