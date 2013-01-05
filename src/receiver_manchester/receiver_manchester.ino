#include <MANCHESTER.h>

int rxPin = 0;
int ledPin = 1;

void setup()
{
  //  Serial.begin(9600);	// Debugging only
  //  Serial.println("setup");

  pinMode(rxPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Set digital TX pin
  MANRX_SetRxPin(rxPin);
  // Prepare interrupts
  MANRX_SetupReceive();
  // Begin receiving data
  MANRX_BeginReceive();

  play_init_sequence();
}

void play_init_sequence(){
  for (int i=0; i<20; i++){
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);    
    delay(50);    
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);    
    delay(25);    
  }
}

void  play_alarm(){
  for (int i=0; i<20;i++){
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    delay(50); 
  }
  delay(1000);
}

void loop()
{

  delay(1);

  if (MANRX_ReceiveComplete())
  {
    unsigned int data = MANRX_GetMessage();
    MANRX_BeginReceive();
    play_alarm();    

  }
}







