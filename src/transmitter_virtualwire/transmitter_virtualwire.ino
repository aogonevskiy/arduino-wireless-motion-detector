#include <VirtualWire.h>

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

  // Initialise the IO and ISR
  //    vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);  // Bits per sec
  vw_set_tx_pin(txPin);
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
    
    const char *msg = "## md ##";

    vw_send((uint8_t *)msg, strlen(msg)); //send message
    vw_wait_tx(); // Wait until the whole message is gone
    
    delay(500);
    
  } 
  else {
    digitalWrite(txLedPin, LOW);
  } 
}


