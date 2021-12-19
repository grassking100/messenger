#ifndef CLIMATE_H_INCLUDED
#define CLIMATE_H_INCLUDED
const int temperatureMax=100;
const int humidityMax=100;
const int seaMax=100;
struct Climate
{
    int temperature=40;
    int humidity=40;
    int seaLevel=2;
    void setTemparature(int change);
    void setHumidity(int change);
    void setSeaLevel(int change);

};



#endif // CLIMATE_H_INCLUDED
