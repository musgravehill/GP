/**
   The sketch parses UBX messages from u-blox and outputs ready GPS data to a serial port in a CSV format.

   u-blox-----arduino
   VCC -       5V
   RX -         3
   TX -          2
   GND - GND
*/

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "UbxGpsNavPvt.h"

#define GPS_BAUDRATE 57600L
#define GPS_RX 3
#define GPS_TX 2
#define PC_BAUDRATE 57600L

#define DATETIME_FORMAT "%04d.%02d.%02d %02d:%02d:%02d"
#define DATETIME_LENGTH 20

SoftwareSerial ss(GPS_TX, GPS_RX);
UbxGpsNavPvt<SoftwareSerial> gps(ss);
//UbxGpsNavPosllh<HardwareSerial> gps(Serial);  - GPS on HardwareSerial

#define DATETIME_FORMAT "%04d.%02d.%02d %02d:%02d:%02d"
#define DATETIME_LENGTH 20
char datetime[DATETIME_LENGTH];

void setup()
{
  Serial.begin(PC_BAUDRATE);
  gps.begin(GPS_BAUDRATE);
}

void loop(){
  if (gps.ready())  {
    // snprintf(datetime, DATETIME_LENGTH, DATETIME_FORMAT, gps.year, gps.month, gps.day, gps.hour, gps.min, gps.sec);

    //Serial.println(datetime);

    Serial.print(gps.lon / 10000000.0, 7);
    Serial.print(',');
    Serial.print(gps.lat / 10000000.0, 7);
    Serial.print(',');
    Serial.print(gps.height / 1000.0, 3);
    Serial.print(',');
    Serial.print(gps.gSpeed * 0.0036, 5);
    Serial.print(',');
    Serial.print(gps.headMot / 100000.0, 5);
    Serial.print(',');
    Serial.print(gps.fixType);
    Serial.print(',');
    Serial.println(gps.numSV);

  }
}
