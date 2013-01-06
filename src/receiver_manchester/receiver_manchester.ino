#include <MANCHESTER.h>

int rxPin = 0;
int ledPin = 1;

void setup()
{
  pinMode(ledPin, OUTPUT);

  MANCHESTER.SetRxPin(rxPin); //user sets rx pin default 4
  MANCHESTER.SetTimeOut(1000); //user sets timeout default blocks

  // initialization
  play_alarm(3);
}

void  play_alarm(int cnt){
  for (int i=0; i<cnt;i++){
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500); 
  }
}

void loop()
{
  unsigned int data = MANCHESTER.Receive();
  if (data == 1234) {
    play_alarm(10);
    delay(1000);
    play_alarm(5);
    delay(1000);
    play_alarm(3);
  }
}










