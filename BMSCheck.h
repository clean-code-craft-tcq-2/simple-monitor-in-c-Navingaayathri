#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#define  MIN_BATTTEMP 0
#define  MAX_BATTTEMP 45
#define  MIN_BATTSoC 20
#define  MAX_BATTSoC 80
#define  MIN_BATTCHARGERATE 0
#define  MAX_BATTCHARGERATE 0.8

#define NORMAL 0
#define LOW_LEVEL_WARNING 1
#define LOW_LEVEL_BREACH 2
#define HIGH_LEVEL_WARNING 3
#define HIGH_LEVEL_BREACH 4

#define TOLERENCE_PERCENT 0.05

#define ENGLISH 0
#define DEUTSCH 1

char * DisplayinEnglish[] = {"Temperature is Normal", "Temperature is approaching low level threshold", "Temperature is out of low level threshold", "Temperature is approaching high level threshold", "Temperature is out of high level threshold",
"SoC is Normal", "SoC is approaching low level threshold", "SoC is out of low level threshold", "SoC is approaching high level threshold", "SoC is out of high level threshold", 
"Charge rate is Normal", "Charge rate is approaching low level threshold", "Charge rate is out of low level threshold", "Charge rate is approaching high level threshold", "Charge rate is out of high level threshold"};

char * DisplayinDeutsch[] = {"Temperatur ist normal", "Temperatur nähert sich dem niedrigen Schwellenwert", "Temperatur liegt außerhalb des niedrigen Schwellenwerts", "Temperatur nähert sich dem oberen Schwellenwert", "Temperatur liegt außerhalb des oberen Schwellenwerts" ,
"SoC ist normal", "SoC nähert sich dem niedrigen Schwellenwert", "SoC liegt außerhalb des niedrigen Schwellenwerts", "SoC nähert sich dem hohen Schwellenwert", "SoC liegt außerhalb des hohen Schwellenwerts",
"Laderate ist normal", "Laderate nähert sich dem niedrigen Schwellenwert", "Laderate liegt unter dem niedrigen Schwellenwert", "Laderate nähert sich dem hohen Schwellenwert", "Laderate liegt außerhalb des hohen Schwellenwerts"}; 

int checkBatteryTemperatureLow(float temperature);
int checkBatterySoCLow(float SoC) ;
int checkBatteryChargeRateLow(float chargeRate);
int checkBatteryTemperatureHigh(float temperature);
int checkBatterySoCHigh(float SoC) ;
int checkBatteryChargeRateHigh(float chargeRate);
int BatteryStateOk(float temperature, float SoC , float chargeRate);
int BatteryStateNOk(float temperature, float SoC , float chargeRate);
int testBatteryStateOk(float temperature, float SoC, float chargeRate);
int testBatteryStateNOk(float temperature, float SoC, float chargeRate); 
int main();
