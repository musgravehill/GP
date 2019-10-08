#ifndef UBXGPSNAVPVT_H_
#define UBXGPSNAVPVT_H_

#include "UbxGps.h"

template <class T>
class UbxGpsNavPvt : public UbxGps<T>
{
  public:
    // Type         Name           Unit     Description (scaling)
    uint32_t  iTOW;       // U4 ms       GPS time of week of the navigation epoch. See the description of iTOW
    uint16_t  year;       //U2 y        Year UTC
    uint8_t   month;      //U1 month    Month, range 1..12 UTC
    uint8_t   day;        // d        Day of month, range 1..31 UTC
    uint8_t   hour;       // h        Hour of day, range 0..23 UTC
    uint8_t   minute;        // min      Minute of hour, range 0..59 UTC
    uint8_t   sec;        // s        Seconds of minute, range 0..60 UTC
    byte      valid;      // -        Validity Flags (see graphic below)
    uint32_t  tAcc;       // ns       Time accuracy estimate UTC
    int32_t   nano;       // ns       Fraction of second, range -1e9..1e9 UTC
    uint8_t   fixType;    // -        GNSSfix Type, range 0..5
    byte      flags;      // -        Fix Status Flags (see graphic below)
    byte      flags2;
    uint8_t   numSV;      // -        Number of satellites used in Nav Solution
    int32_t   lon;        // deg      Longitude (1e-7)
    int32_t   lat;        // deg      Latitude (1e-7)
    int32_t   height;     // mm       Height above Ellipsoid
    int32_t   hMSL;       // mm       Height above mean sea level
    uint32_t  hAcc;       // mm       Horizontal Accuracy Estimate
    uint32_t  vAcc;       // mm       Vertical Accuracy Estimate
    int32_t   velN;       // mm/s     NED north velocity
    int32_t   velE;       // mm/s     NED east velocity
    int32_t   velD;       // mm/s     NED down velocity
    int32_t   gSpeed;     // mm/s     Ground Speed (2-D)
    int32_t   headMot;    // deg      Heading of motion 2-D (1e-5)
    uint32_t  sAcc; // mm/s Speed accuracy estimate
    uint32_t  headAcc; //deg Heading accuracy estimate (both motion and vehicle)
    uint16_t  pDOP;  //Position DOP
    uint8_t  reserved1;  //Reserved
    int32_t  headVeh; //deg Heading of vehicle (2-D)
    int16_t  magDec; //deg Magnetic declination
    uint16_t  magAcc; //deg Magnetic declination accuracy

    UbxGpsNavPvt(T &serial) : UbxGps<T>(serial)
    {
      this->setLength(92);
    }
};

#endif
