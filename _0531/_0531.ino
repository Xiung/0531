/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

int greenPin = 6;
int redPin = 9;
int bluePin = 5;
int counter = 0;

int melody[] = {
 523, 784, 698, 784, 880, 880, 880, 988, 880, 988, 1047, 1047, 1175, 1318, 1397, 1397, 1318, 1175, 1047, 698, 698, 1175, 1175, 0, 1175, 1175, 1047, 988, 880, 988, 1047, 1047, 0, 988, 988, 880, 784, 698, 784, 880, 880, 988, 880, 988, 1047, 1047, 1175, 1318, 1397, 1397, 1397, 1318, 1175, 1047, 698, 698, 1175, 1175, 1175, 0, 1175, 1175, 1047, 988, 880, 988, 1047, 1047, 0, 988, 1047, 880, 784, 698, 784, 784, 698, 698, 0
};

int noteDurations[] = {
 8,8,8,8,8,2,8,8,8,8,8,1,8,8,2,8,8,8,8,8,8,8,2,4,2,8,8,8,8,8,1,4,4,2,8,8,8,8,8,4,4,8,8,8,8,2,8,8,8,2,8,8,8,8,8,8,8,4,4,4,2,8,8,8,8,8,2,4,4,2,8,8,8,8,8,8,8,2,4
};

void setup() {
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

  for (int thisNote = 0; thisNote < 79; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
      counter++;
  if(counter == 1){//紅綠同時點亮，產生黃色
    analogWrite(greenPin,255);
    analogWrite(redPin,255);
    analogWrite(bluePin,0);
  }
  else if(counter == 2){//藍紅同時點亮，產生紫色
    analogWrite(greenPin,0);
    analogWrite(redPin,255);
    analogWrite(bluePin,255);
  }
  else if(counter == 3){//藍綠同時點亮，產生青色
    analogWrite(greenPin,255);
    analogWrite(redPin,0);
    analogWrite(bluePin,255);
    counter = 0;
  }
 
}
}

void loop() {
}
