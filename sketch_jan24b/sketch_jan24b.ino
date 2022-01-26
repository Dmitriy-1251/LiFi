#include <Manchester.h>
#define TX_PIN  12  //pin where your transmitter is connected
#define LED_PIN 13 //pin for blinking LED

uint8_t moo = 1; //last led status
uint8_t data[17] = {11, 'T', 'E', 'S', 'T', '_', 'T', 'E', 'X', 'T', '_', '1', '2', '3', '5', '6', 'V'};

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, moo);
  man.setupTransmit(TX_PIN, MAN_9600);
}

uint8_t datalength = 2; //at least two data
void loop()
{
  if (datalength < 19)
  {
    test_transmit();
    datalength++;
  } else
  {
    //delay(00);
    datalength = 2;
  }

}

void test_transmit()
{

  data[0] = datalength;
  man.transmitArray(datalength, data);
  moo = ++moo % 2;
  digitalWrite(LED_PIN, moo);
  delayMicroseconds(0);


}
