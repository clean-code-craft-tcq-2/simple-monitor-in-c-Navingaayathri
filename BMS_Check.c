#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "BMSCheck.h"

int language = ENGLISH; /*Selected language for display of Battery status. Optional language: Deutsch*/

int displayonConsole(const char* BreachMessage) 
{
printf("%s \n", BreachMessage);
return 0;
}

int languageSelector(int result_Temp, int result_SoC, int result_chargeRate)
{
if (language == ENGLISH)
{
displayonConsole(DisplayinEnglish[result_Temp]);
displayonConsole(DisplayinEnglish[(result_SoC)+5]);
displayonConsole(DisplayinEnglish[(result_chargeRate)+10]);}
else if (language == DEUTSCH)
{
displayonConsole(DisplayinDeutsch[result_Temp]);
displayonConsole(DisplayinDeutsch[(result_SoC)+5]);
displayonConsole(DisplayinDeutsch[(result_chargeRate)+10]); 
}
}
/*check the input level */
int checkValidRangeLow(float inputValue, float MinThresholdvalue, float MaxThresholdvalue)
{   
	int result = NORMAL;
	float LowLevelThreshold = (TOLERENCE_PERCENT *  MaxThresholdvalue) + MinThresholdvalue;	
	if(inputValue < MinThresholdvalue)
	{
        result=LOW_LEVEL_BREACH;
	}
	else if(inputValue <= LowLevelThreshold)
	{		
        result=LOW_LEVEL_WARNING;
        }
	return result;
}
int checkValidRangeHigh(float inputValue, float MinThresholdvalue, float MaxThresholdvalue)
{      
        int result = NORMAL;
	float HighLevelThreshold = MaxThresholdvalue - (TOLERENCE_PERCENT * MinThresholdvalue);	
	if(inputValue > MaxThresholdvalue)
	{
        result=HIGH_LEVEL_BREACH;
	}
	else if(inputValue > HighLevelThreshold)
	{		
        result=HIGH_LEVEL_WARNING;
        }
        return result;
}

int BatteryTemp(float temperature, float SoC , float chargeRate)
{	
int result_Temp_Low =checkValidRangeLow(temperature, MIN_BATTTEMP, MAX_BATTTEMP);
int result_Temp_High =checkValidRangeHigh(temperature, MIN_BATTTEMP, MAX_BATTTEMP);
int result_Temp = result_Temp_Low + result_Temp_High;
return result_Temp;
}
int BatterySoC(float temperature, float SoC , float chargeRate)
{	
int result_SoC_Low=checkValidRangeLow(SoC, MIN_BATTSoC, MAX_BATTSoC);
int result_SoC_High=checkValidRangeHigh(SoC, MIN_BATTSoC, MAX_BATTSoC);
int result_SoC = result_SoC_Low + result_SoC_High;
return result_SoC;
}
int BatteryChargeRate(float temperature, float SoC , float chargeRate)
{	
int result_chargeRate_Low=checkValidRangeLow(chargeRate, MIN_BATTCHARGERATE, MAX_BATTCHARGERATE);
int result_chargeRate_High=checkValidRangeHigh(chargeRate, MIN_BATTCHARGERATE, MAX_BATTCHARGERATE);
int result_chargeRate = result_chargeRate_Low + result_chargeRate_High;
return result_chargeRate;
}
/* Check battery status based on input values and display the status in selected language*/
int BatteryStateOk(float temperature, float SoC , float chargeRate)
{	
int result_Temp = BatteryTemp(temperature, SoC, chargeRate);
int result_SoC = BatterySoC(temperature, SoC , chargeRate);
int result_chargeRate = BatteryChargeRate(temperature, SoC , chargeRate);
languageSelector(result_Temp, result_SoC, result_chargeRate);
int result = (result_Temp || result_SoC || result_chargeRate);
return result;
}

int testBatteryStateOk(float temperature, float SoC, float chargeRate)  
{
  int status;
  status = BatteryStateOk(temperature, SoC, chargeRate);
  assert(status==0);
  return 0;
}

int testBatteryStateNOk(float temperature, float SoC, float chargeRate)  
{
  int status;	
  status = BatteryStateOk(temperature, SoC, chargeRate);
  assert(status!=0);
  return 0;
}

int main()
{
   testBatteryStateOk(10, 25, 0.1);
   testBatteryStateOk(12, 30, 0.15);
   testBatteryStateOk(15, 40, 0.17);
   testBatteryStateOk(18, 42, 0.2);
   testBatteryStateNOk(15, 81, 0.3);
   testBatteryStateNOk(-6, 30, 0.4);
   testBatteryStateNOk(50, 5, 0.9);
   testBatteryStateNOk(8, -20, 1.2);
   testBatteryStateNOk(2, 13, -0.5);  
   return 0;
 }
