#define BLYNK_PRINT Serial
#include <TimeLib.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <SimpleModbusMaster.h>
#define baud 38400
#define timeout 1000
#define polling 100 // the scan rate
#define retry_count 1000
#define TxEnablePin 2
char auth[] = "7nzAZRfm3xJAfgXjvCvhpwdsvT91FR17";//
char ssid[] = "SIMOR#2020";
char pass[] = "simor123";
BlynkTimer timer;
enum
{
  PACKET1,
  PACKET2,
  PACKET3,
  PACKET4,
  PACKET5,
  TOTAL_NO_OF_PACKETS
};
Packet packets[TOTAL_NO_OF_PACKETS];
packetPointer packet1 = &packets[PACKET1];//
packetPointer packet2 = &packets[PACKET2];//
packetPointer packet3 = &packets[PACKET3];//
packetPointer packet4 = &packets[PACKET4];
packetPointer packet5 = &packets[PACKET5];
unsigned int STM32[2];//STM32
unsigned int PM800[1];//PM800
unsigned int ARDUINO1[1];//ARDUINO
unsigned int RELAY[1];
unsigned int SERVO[1];
WidgetLED led0(V1);//PIR
int ledStatus0; 

#define BLYNK_GREEN     "#23C48E"
#define BLYNK_BLUE    "#04C0F8"
#define BLYNK_YELLOW    "#ED9D00"
#define BLYNK_RED       "#D3435C"
#define BLYNK_DARK_BLUE "#5F7CD8"
unsigned long interval = 36000000;//10 jam

void simor()
{
  ledStatus0 = (ARDUINO1[0]);
  if (ledStatus0 > 0) {
    led0.setColor(BLYNK_RED);
     } else {
    led0.setColor(BLYNK_GREEN);
    }
  float PIR = ARDUINO1[0];
  
  float FREQ = PM800[0]/100.0f ;
  float TEMP = STM32[1];
  float HUMI = STM32[0];
 
 
  Blynk.virtualWrite(V0, FREQ ); //
  Blynk.virtualWrite(V2, TEMP ); //
  Blynk.virtualWrite(V3, HUMI ); //
  Blynk.virtualWrite(V6, PIR ); //
 
 
}
BLYNK_WRITE(V4)//RELAY
{
  RELAY[0] = param.asInt();
}

BLYNK_WRITE(V5)//SERVO
{
  SERVO[0] = param.asInt();
}
void setup()
{
  Serial.begin(9600);
  /*
  packet1->id = 1;//STM32
  packet1->function = READ_HOLDING_REGISTERS;
  packet1->address = 0;
  packet1->no_of_registers = 2;
  packet1->register_array = STM32;
*/
  packet2->id = 2;//PM800
  packet2->function = READ_HOLDING_REGISTERS;
  packet2->address = 1179;
  packet2->no_of_registers = 1;
  packet2->register_array = PM800;

  packet3->id = 3;
  packet3->function = READ_HOLDING_REGISTERS;
  packet3->address = 0;
  packet3->no_of_registers = 1;
  packet3->register_array = ARDUINO1;

  packet4->id = 3;
  packet4->function = PRESET_MULTIPLE_REGISTERS;
  packet4->address = 2;
  packet4->no_of_registers = 1;
  packet4->register_array = SERVO;

  packet5->id = 3;
  packet5->function = PRESET_MULTIPLE_REGISTERS;
  packet5->address = 1;
  packet5->no_of_registers = 1;
  packet5->register_array = RELAY;
  
  modbus_configure(baud, timeout, polling, retry_count, TxEnablePin, packets, TOTAL_NO_OF_PACKETS);
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);
  led0.on();
  timer.setInterval(1000L, simor);
}

void loop()
{
  modbus_update(packets);
  Blynk.run();
  timer.run();
  if (millis() >= interval) {
    ESP.restart();
  }
  if (WiFi.status() != WL_CONNECTED) {
      Serial.print("Connecting Wifi: ");
      Serial.println(ssid);
      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
}
