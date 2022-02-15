#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "BMSCheck.h"

void displayonConsole(const char* BreachMessage) 
{
printf("%s \n", BreachMessage);
}

bool checkValidRange(float inputValue, float MinThresholdvalue, float MaxThresholdvalue)
{
return (inputValue < MinThresholdvalue || inputValue > MaxThresholdvalue);
}

bool checkBatteryTemperature(float temperature, float MIN_BATT_TEMP, float MAX_BATT_TEMP) 
{
return(checkValidRange(temperature, (float) MIN_BATT_TEMP, (float) MAX_BATT_TEMP);
displayonConsole("Temperature out of range");
}

bool checkBatterySoC(float SoC, float MIN_BATT_SoC, float MAX_BATT_SoC) 
{
return (checkValidRange(SoC, (float) MIN_BATT_SoC, (float) MIN_BATT_SoC);
displayonConsole("State of Charge out of range");
}
	
bool checkBatteryChargeRate(float chargeRate, float MIN_BATT_CHARGE_RATE, float MAX_BATT_CHARGE_RATE) 
{
return (checkValidRange(chargeRate, (float) MIN_BATT_CHARGE_RATE, (float) MAX_BATT_CHARGE_RATE);
displayonConsole("Charge rate out of range");
}

int BatteryStateOk(float temperature, float SoC , float chargeRate)
{	
return((temperature) && (SoC) && (chargeRate));
}

int BatteryStateNOk(float temperature, float SoC , float chargeRate)
{	
return((temperature) || (SoC) || (chargeRate));
}	

int testBatteryStateOk(float temperature, float SoC, float chargeRate, bool StateOk)  
{
  bool status;
  status = BatteryStateOk(temperature,SoC,chargeRate);
  assert(status == StateOk);
  return 0;
}

int testBatteryStateNOk(float temperature, float SoC, float chargeRate, bool StateNOk)  
{
  bool status;	
  status = BatteryStateNOk(temperature,SoC,chargeRate);
  assert(status == StateNOk);
  return 0;
}

int main()
{
    assert(testBatteryStateOk(40.0, 55.0, 0.5, 1));
    return 0;	
}
