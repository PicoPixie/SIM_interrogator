#include <LGSM.h>

#define RECEIVER "INSERT_CELL_NUM_TO_SEND_MSG_TO_HERE"

LSMSClass sms;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(Serial.available()==0) {} //wait
  Serial.println("Serial setup OK.");
  while(!sms.ready()) 
    delay(1000);
  Serial.println("SIM ready and initialised.");
  
  
  sms.beginSMS(RECEIVER);
  sms.print("Hello from LinkIT ONE");
  if(sms.endSMS()) {
    Serial.println("SMS sent");
  } else {
    Serial.println("Failed to send SMS");
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //is there an unread msg blocking.?
  /*
  while(sms.available()) {
      Serial.println("There IS a mesg to retrieve.");
      Serial.println();
      //output it to serial port
      int c;
      while(true) {
        c = sms.read();
        if(c < 0) break;
        Serial.print((char)c);
      }
      sms.flush(); //removes the message from unread queue
      Serial.println();
  }  
  Serial.println("END of mesg retrieval.");
   */
}
