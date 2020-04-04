#include "pitches.h"
//#define button 3

int buttonPoll = 0;   //integer for button state

// notes in the melody
int melody[] = 
{
  //AULD LANG SYNE - NOTES
  NOTE_C4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, 
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_D5,
  NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_F4,

  //Chorus - NOTES
  NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, 
  NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_F4
};
float noteDurations[] =
{
  //AULD LANG SYNE - RHYTHM
  //1 = 1 crochet beeat; 0.5 = 1 quaver beat; 2= 1 minum beat
  1, 1.5, 0.5, 1,
  1, 1.5, 0.5, 1, 
  0.5, 0.5, 1.5, 0.5, 1,
  1, 3,
  1, 1.5, 0.5, 1,
  1, 1.5, 0.5, 1, 
  0.5, 0.5, 1.5, 0.5, 1,
  1, 3,
  //AULD LANG SYNE CHORUS- RHYTHM
  1, 1.5, 0.5, 1,
  1, 1.5, 0.5, 1,
  1, 1.5, 0.5, 1,
  1, 3,
  1, 1.5, 0.5, 1,
  1, 1.5, 0.5, 1, 
  0.5, 0.5, 1.5, 0.5, 1,
  1, 3
};
void setup() 
{
  pinMode(PB1,OUTPUT);
  pinMode(PB2,OUTPUT);
  pinMode(PB3,OUTPUT);
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < sizeof(melody); thisNote++)
  {
    if(thisNote%3 == 1)
    {
      digitalWrite(PB1, LOW);
      digitalWrite(PB2, HIGH);
      digitalWrite(PB3, LOW);
    }
    else if(thisNote%3 == 2)
    {
      digitalWrite(PB1, LOW);
      digitalWrite(PB2, LOW);
      digitalWrite(PB3, HIGH);
    }
    else
    {
      digitalWrite(PB1, HIGH);
      digitalWrite(PB2, LOW);
      digitalWrite(PB3, LOW);
    }
    // to calculate the note duration, take one second multiplied by 500ms
    // tempo set at 500ms. change this value will change tempo
    int noteDuration = 500 * noteDurations[thisNote];
    tone(0, melody[thisNote], noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.20;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(0);
  }
  digitalWrite(PB1, LOW);
  digitalWrite(PB2, LOW);
  digitalWrite(PB3, LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
}
