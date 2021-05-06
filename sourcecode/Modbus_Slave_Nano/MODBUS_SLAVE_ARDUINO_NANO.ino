/*
Author : Fuad Hasan (CEO SIMOR)
website : puaks.blogspot.com
*/


#include <ModbusRtu.h>
#define ID  3 //slave ID
#define SERIALNUMBER  25120 //slave ID
#define TXEN  2 //pin tx enable RS485
#define PS 0 //port serial 0,1,2,3 (1-3 for mega 2560, uno 0 only)
Modbus slave(ID, PS, TXEN); 
uint16_t au16data[10]; // jumlah address yang dibuat
#include <Servo.h>
Servo myservo;
int val;
/**
 saat uji protocol via modscan setting
 baudrate 9600
 parity none
 slave ID 1
 lengt 10
 address 1
 Holding register
 */
void setup() {
  io_setup(); // I/O settings
  slave.begin( 38400 ); // baudrate 
  myservo.attach(5);
}

void loop() {
  slave.poll( au16data, 10 );
   io_poll();
} 

void io_setup() {
  // define i/o
  //DIGITAL INPUT
  pinMode(6, INPUT);
  //DIGITAL OUTPUT
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW );
 
}

/**
 *  Link between the Arduino pins and the Modbus array
 */
void io_poll() {
  // get digital inputs -> au16data[0] HOLDING REGISTER 40001 di modscan, display options BINARY
  bitWrite( au16data[0], 0, digitalRead( 6 ));
 

  // set digital outputs -> au16data[1] HOLDING REGISTER 40002 di modscan, display options BINARY
  digitalWrite( 4, bitRead( au16data[1], 0 ));
 
  val = au16data[2];            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);
   
  
  // diagnose communication
  au16data[4] = slave.getInCnt();
  au16data[5] = slave.getOutCnt();
  au16data[6] = slave.getErrCnt();
  au16data[7] = SERIALNUMBER;
  au16data[8] = ID;
}
