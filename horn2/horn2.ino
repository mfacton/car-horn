#include <SD.h>
#include <SPI.h>

boolean s1 = false;
boolean s2 = false;
File f;

void setup() {
  DDRD = 0xFF;
  DDRB = DDRB & B11111100;
  
  if (!SD.begin(10)) {
    while (1);
  }
}

void loop() {
  if ((PINB & B00000001) == 0)  {
    s1 = true;
    s2 = false;
    f.close();
    f = SD.open("sound1.wav");
    f.read();
  }else if ((PINB & B00000010) == 0) {
    s1 = false;
    s2 = true;
    f.close();
    f = SD.open("sound2.wav");
    f.read();
  }
  if (f.available()) {
    _delay_us(54);
    PORTD = f.read();
  }else{
    PORTD = 0x77;
  }
}
