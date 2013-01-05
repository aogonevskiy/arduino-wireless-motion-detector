#include <VirtualWire.h>

int rxPin = 0;
int ledPin = 1;

void setup()
{
//  Serial.begin(9600);	// Debugging only
//  Serial.println("setup");

  pinMode(rxPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Initialise the IO and ISR
  // vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);	 // Bits per sec
  vw_set_rx_pin(rxPin);

  vw_rx_start(); // Start the receiver PLL running
  
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

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    // got new message play alarm
    play_alarm();

//    int i;

    // Message with a good checksum received, dump it.
//    Serial.print("Got: ");
//
//    for (i = 0; i < buflen; i++)
//    {
//      // prints integer value of the byte as ASCII characters      
//      // Serial.print(buf[i], DEC);
//      //
//      // print character
//      Serial.write(buf[i]);
//      Serial.print(" ");
//    }
//    Serial.println("");

  }
}





