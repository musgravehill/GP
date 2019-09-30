/**
 * The sketch parses UBX messages from u-blox NEO-7M and outputs ready GPS data to a serial port in a CSV format.
 *
 * u-blox NEO-7M - Arduino Uno
 * VCC - 5V
 * RX - 3
 * TX - 2
 * GND - GND
 */

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <UbxGpsNavPosllh.h>

#define GPS_BAUDRATE 57600L
#define GPS_RX 3
#define GPS_TX 2
#define PC_BAUDRATE 57600L

#define DATETIME_FORMAT "%04d.%02d.%02d %02d:%02d:%02d"
#define DATETIME_LENGTH 20

SoftwareSerial ss(GPS_TX, GPS_RX);
UbxGpsNavPosllh<SoftwareSerial> gps(ss);  //NEO-6M does NOT support NavPvt-messages UBX-protocol

char datetime[DATETIME_LENGTH];

void setup()
{
    Serial.begin(PC_BAUDRATE);
    gps.begin(GPS_BAUDRATE);
}

void loop()
{
    if (gps.ready())
    {
        //snprintf(datetime, DATETIME_LENGTH, DATETIME_FORMAT, gps.year, gps.month, gps.day, gps.hour, gps.min, gps.sec);

        Serial.print("lon=");        
        Serial.print(gps.lon/10000000.0, 7);
        Serial.print(" lat=");
        Serial.print(gps.lat/10000000.0, 7);
        Serial.print(" h=");
        Serial.println(gps.height/1000);
         
    }
}
