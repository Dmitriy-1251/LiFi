
#include <Manchester.h>
#define RX_PIN A2
#define LED_PIN 13

uint8_t moo = 1;
#define BUFFER_SIZE 25
uint8_t buffer[BUFFER_SIZE];

//test
uint32_t myTimer1 = 0;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, moo);
  Serial.begin(9600);
  man.setupReceive(RX_PIN, MAN_9600);
  man.beginReceiveArray(BUFFER_SIZE, buffer);
}

void loop()
{
  if (man.receiveComplete())
  {
    uint8_t receivedSize = 0;
    //do something with the data in 'buffer' here before you start receiving to the same buffer again
    receivedSize = buffer[0];
    for (uint8_t i = 1; i < receivedSize; i++)
      Serial.write(buffer[i]);

    Serial.println();
    man.beginReceiveArray(BUFFER_SIZE, buffer);
    moo = ++moo % 2;
    digitalWrite(LED_PIN, moo);

    /*Serial.print(" ");
    Serial.print(micros() - myTimer1);
    myTimer1 = micros();*/
    Serial.print(" ");
  }

  /*Serial.print(" ");
    Serial.print(micros()-myTimer1);
    myTimer1 = micros();*/
}
