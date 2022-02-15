#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "BMSCheck.h"

int displayonConsole(const char* BreachMessage) 
{
printf("%s \n", BreachMessage);
return 0;
}

bool checkValidRange(float inputValue, float MinThresholdvalue, float MaxThresholdvalue)
{
return (inputValue < MinThresholdvalue || inputValue > MaxThresholdvalue);
}

bool checkBatteryTemperature(float temperature)
{
bool result = (checkValidRange(temperature, (float)MIN_BATTTEMP, (float)MAX_BATTTEMP));
if(result == true)	
displayonConsole("Temperature out of range");
else
displayonConsole("Temperature is in range");
return result;
}

bool checkBatterySoC(float SoC)
{
bool result = (checkValidRange(SoC, (float)MIN_BATTSoC, (float)MAX_BATTSoC));
if(result == true)	
displayonConsole("State of Charge out of range");
else
displayonConsole("State of Charge is in range");
return result;
}
	
bool checkBatteryChargeRate(float chargeRate)
{
bool result = (checkValidRange(chargeRate, (float)MIN_BATTCHARGERATE, (float)MAX_BATTCHARGERATE));
if(result == true)	
displayonConsole("Charge rate out of range");
else
displayonConsole("Charge rate is in range");
return result;
}

int BatteryStateOk(float temperature, float SoC , float chargeRate)
{	
bool result_Temp =checkBatteryTemperature(temperature);
bool result_SoC=checkBatterySoC(SoC);
bool result_chargeRate=checkBatteryChargeRate(chargeRate);
return(result_Temp || result_SoC || result_chargeRate);
}


int testBatteryStateOk(float temperature, float SoC, float chargeRate)  
{
  bool status;
  status = BatteryStateOk(temperature,SoC,chargeRate);
  assert(status == 0);
  return 0;
}

int testBatteryStateNOk(float temperature, float SoC, float chargeRate)  
{
  bool status;	
  status = BatteryStateOk(temperature,SoC,chargeRate);
  assert(status == 1);
  return 0;
}

int main()
{
    testBatteryStateOk(40.0, 55.0, 0.5);
    testBatteryStateOk(22.0, 30.0, 0.2);
    testBatteryStateNOk(73.0, 65.0, 0.4);
    testBatteryStateNOk(40.0, 75.0, 0.9);
    testBatteryStateNOk(45.0, 85.0, 0.7);
    testBatteryStateNOk(60.0, 100.0, 1.2);
    return 0;	
}
