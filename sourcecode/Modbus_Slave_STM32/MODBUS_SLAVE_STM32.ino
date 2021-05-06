#include <SimpleModbusSlave.h>
#include "DHT.h"
#define DHTPIN PA0
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
enum
{
  VAL0,
  VAL1,
  VAL2,
  VAL3,
  
  HOLDING_REGS_SIZE // leave this one
};

unsigned int holdingRegs[HOLDING_REGS_SIZE]; //

void setup()
{
  modbus_configure(&Serial3, 38400, SERIAL_8N1, 1, 2, HOLDING_REGS_SIZE, holdingRegs);//serial A9 A10, baudrate, parity, ID, TXenable, function
  modbus_update_comms(38400, SERIAL_8N1, 1);
  dht.begin();
}

void loop()
{
  modbus_update();
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  holdingRegs[VAL0] = h; // kelembapan
  holdingRegs[VAL1] = t; // temperature
  holdingRegs[VAL2] = 912; //serial number
  holdingRegs[VAL3] = 10;
}
