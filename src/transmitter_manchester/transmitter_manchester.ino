#include <MANCHESTER.h>

int motionDetectPin = 0; 
int sleepModePin = 1; 

int txPin = 2;
int txLedPin = 3;

int val;

void setup()
{
  pinMode(txPin, OUTPUT);
  pinMode(txLedPin, OUTPUT);

  pinMode(sleepModePin, OUTPUT);
  pinMode(motionDetectPin, INPUT);
  
  digitalWrite(sleepModePin, HIGH);  

  // playinhg initialization sequence
  play_init_sequence();

  MANCHESTER.SetTxPin(txPin);
}

void play_init_sequence(){
  for (int i=0; i<20; i++){
    digitalWrite(txLedPin, HIGH);
    delay(100);
    digitalWrite(txLedPin, LOW);    
    delay(50);    
  }
}

void loop()
{

  val = digitalRead(motionDetectPin);
  if(val == LOW) {
    
    digitalWrite(txLedPin, HIGH);
    
    unsigned int data = 1234;
    MANCHESTER.Transmit(data);

    delay(500);
    
  } 
  else {
    digitalWrite(txLedPin, LOW);
  } 
}


