#include "earthunit.h"
#include <M5Unified.h>


int EarthUnit::getData()
{
    // earth unit
    int earth  = analogRead(33);
    Serial.print("earth:");
    Serial.println(earth);

    return earth;
}
