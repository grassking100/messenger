#include "Climate.h"
#include "Tool.h"
void Climate::setTemparature(int change)
{
    setValue(&temperature,change,0,temperatureMax,Force);
}
void Climate::setHumidity(int change)
{
    setValue(&humidity,change,0, humidityMax,Force);
}
void Climate::setSeaLevel(int change)
{
    setValue(&seaLevel,change,0,seaMax,Force);
}

