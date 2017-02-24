// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PINA            6
#define PINB            7
#define PINC            8
#define PIND            9

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      512

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS, PINA, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PINB, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS, PINC, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4 = Adafruit_NeoPixel(NUMPIXELS, PIND, NEO_GRB + NEO_KHZ800);

int delayval = 10;
int r = 0;
int g = 0;
int b = 0;

void setup() {
  //Serial.begin(9600);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
//Serial.print("a");
  pixels1.begin();
  pixels2.begin();
  pixels3.begin();
  pixels4.begin();
//Serial.print("b");
  for(uint32_t i=0;i<NUMPIXELS;i++){
//Serial.print(i);
//Serial.println("c");
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels1.setPixelColor(i, pixels1.Color(50,50,50));
    pixels2.setPixelColor(i, pixels2.Color(50,50,50));
    pixels3.setPixelColor(i, pixels3.Color(50,50,50));
    pixels4.setPixelColor(i, pixels4.Color(50,50,50));

    pixels1.show(); 
    pixels2.show(); 
    pixels3.show(); 
    pixels4.show(); 

    //delay(delayval); // Delay for a period of time (in milliseconds).

  }
  //Serial.print("d");
  //
}

void loop() {
  //Serial.println("e");
  r = analogRead(A0)/4;
  g = analogRead(A1)/4;
  b = analogRead(A2)/4;

  //Serial.print(r);
  //Serial.print(" ");
  //Serial.print(g);
  //Serial.print(" ");
  //Serial.println(b);
  
  for(uint32_t i=NUMPIXELS-1;i>0;i--){
    pixels1.setPixelColor(i, pixels1.getPixelColor(i-1));
    pixels2.setPixelColor(i, pixels2.getPixelColor(i-1));
    pixels3.setPixelColor(i, pixels3.getPixelColor(i-1));
    pixels4.setPixelColor(i, pixels4.getPixelColor(i-1));
  }
  pixels1.setPixelColor(0, pixels1.Color(r,g,b));
  pixels2.setPixelColor(0, pixels2.Color(r,g,b));
  pixels3.setPixelColor(0, pixels3.Color(r,g,b));
  pixels4.setPixelColor(0, pixels4.Color(r,g,b));
  
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  
  delay(delayval); // Delay for a period of time (in milliseconds).
  
}
