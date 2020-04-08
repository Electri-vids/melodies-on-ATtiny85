#include "pitches.h"
//#define button 3

int buttonPoll = 0;   //integer for button state

// notes in the melody
int melody[] = 
{
  //DESPACITO CHORUS - NOTES
  NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4,
  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_B4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_A4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_CS5
};
float noteDurations[] =
{
  //DESPACITO CHORUS - RHYTHM
  //1 = 1 crochet beeat; 0.5 = 1 quaver beat; 2= 1 minum beat
  1, 1, 0.5, 0.5, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.5, 0.25, 0.375,
  0.75, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.5, 0.25, 0.375, 0.75,
  0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.5, 0.25, 0.375, 0.75
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
    int noteDuration = 500 * noteDurations[thisNote];
    // time taken for one beat = 1 * 500ms
    // Beats per second = 1/500ms = 2; change this value will change tempo
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
