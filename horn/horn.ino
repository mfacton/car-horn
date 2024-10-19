#include <SD.h>          // using digital pin 10 on arduino uno 328, can use other pins
#include <TMRpcm.h>                   // also need to include this library...
#include <SPI.h>

TMRpcm output;

boolean pressed = false;
short val_1;
short val_2;

void setup()
{
  output.speakerPin = 9;
  pinMode(10, OUTPUT);
  pinMode(A7, INPUT);
  pinMode(A3, INPUT);

  //Serial.begin(9600);
  if (!SD.begin(4))
  {
    //Serial.println("SD fail");
    return;
  }
  output.setVolume(7);
}

void loop() {

  val_1 = analogRead(A7);
  val_2 = analogRead(A3);
  
  if (!pressed) {
    if (val_1 == 0) {
      pressed = true;
      output.play("2.wav");
      while (output.isPlaying()) {
        delay(1);
      }
    }else if (val_2 == 0){
      pressed = true; 
      output.play("1.wav");
      while (output.isPlaying()) {
        delay(1);
      }
    }
  }

  if (val_1 != 0 && val_2 != 0) {
    pressed = false;
    delay(500);
  }

  delay(10);
}
