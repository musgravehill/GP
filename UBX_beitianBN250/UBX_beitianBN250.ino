/**
   The sketch parses UBX messages from u-blox and outputs ready GPS data to a serial port in a CSV format.

   u-blox-----arduino
   VCC -       5V
   RX -         3
   TX -          2
   GND - GND
*/

#define GPS_BAUDRATE 57600L
#define PC_BAUDRATE 57600L

#include <Arduino.h>
#include <SoftwareSerial.h>

#include "UBLOX.h"
UBLOX gps(Serial, GPS_BAUDRATE);

SoftwareSerial ss(2, 3);


void setup(){
  ss.begin(PC_BAUDRATE);
  gps.begin();
}

void loop() {
 if(gps.readSensor()) {
    ss.print(gps.getYear());                ///< [year], Year (UTC)
    ss.print("\t");
    ss.print(gps.getMonth());               ///< [month], Month, range 1..12 (UTC)
    ss.print("\t");
    ss.print(gps.getDay());                 ///< [day], Day of month, range 1..31 (UTC)
    ss.print("\t");
    ss.print(gps.getHour());                ///< [hour], Hour of day, range 0..23 (UTC)
    ss.print("\t");
    ss.print(gps.getMin());                 ///< [min], Minute of hour, range 0..59 (UTC)
    ss.print("\t");
    ss.print(gps.getSec());                 ///< [s], Seconds of minute, range 0..60 (UTC)
    ss.print("\t");
    ss.print(gps.getNumSatellites());       ///< [ND], Number of satellites used in Nav Solution
    ss.print("\t");
    ss.print(gps.getLatitude_deg(),10);     ///< [deg], Latitude
    ss.print("\t");
    ss.print(gps.getLongitude_deg(),10);    ///< [deg], Longitude
    ss.print("\t");
    ss.println(gps.getMSLHeight_m());      ///< [ft], Height above mean sea level
  }
}
