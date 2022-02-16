#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "BMSCheck.h"

int language = ENGLISH;

int displayonConsole(const char* BreachMessage) 
{
printf("%s \n", BreachMessage);
return 0;
}

int languageSelector(int result_Temp_Low, int result_Temp_High, int result_SoC_Low, int result_SoC_High, int result_chargeRate_Low, int result_chargeRate_High)
{
if (language == ENGLISH)
{
displayonConsole(DisplayinEnglish[result_Temp_Low + result_Temp_High]);
displayonConsole(DisplayinEnglish[(result_SoC_Low + result_SoC_High)+5]);
displayonConsole(DisplayinEnglish[(result_chargeRate_Low + result_chargeRate_High)+10]);}
else if (language == DEUTSCH)
{
displayonConsole(DisplayinDeutsch[result_Temp_Low + result_Temp_High]);
displayonConsole(DisplayinDeutsch[(result_SoC_Low + result_SoC_High)+5]);
displayonConsole(DisplayinDeutsch[(result_chargeRate_Low + result_chargeRate_High)+10]); 
}
}

int checkValidRangeLow(float inputValue, float MinThresholdvalue, float MaxThresholdvalue)
{   
	int result = NORMAL;
	float LowLevelThreshold = (TOLERENCE_PERCENT *  MaxThresholdvalue) + MinThresholdvalue;	
	if(inputValue < MinThresholdvalue)
	{
        result=LOW_LEVEL_BREACH;
	}
	else if(inputValue <= LowLevelThreshold))
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
	else if(inputValue > HighLevelThreshold))
	{		
        result=HIGH_LEVEL_WARNING;
        }
        return result;
}

int BatteryStateOk(float temperature, float SoC , float chargeRate)
{	
int result_Temp_Low =checkValidRangeLow(temperature, MIN_BATTTEMP, MAX_BATTTEMP);
int result_Temp_High =checkValidRangeHigh(temperature, MIN_BATTTEMP, MAX_BATTTEMP);
int result_SoC_Low=checkValidRangeLow(SoC, MIN_BATTSoC, MAX_BATTSoC);
int result_SoC_High=checkValidRangeHigh(SoC, MIN_BATTSoC, MAX_BATTSoC);
int result_chargeRate_Low=checkValidRangeLow(chargeRate, MIN_BATTCHARGERATE, MAX_BATTCHARGERATE);
int result_chargeRate_High=checkValidRangeHigh(chargeRate, MIN_BATTCHARGERATE, MAX_BATTCHARGERATE);
languageSelector(result_Temp_Low, result_Temp_High, result_SoC_Low, result_SoC_High, result_chargeRate_Low, result_chargeRate_High);
int result = ((result_Temp_Low) || (result_Temp_High) || (result_SoC_Low) || (result_SoC_High) || (result_chargeRate_Low) || (result_chargeRate_High));
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
   testBatteryStateOk(12,  30, 0.15);
   testBatteryStateOk(15,  40, 0.17);
   testBatteryStateOk(18,  42, 0.2);
   testBatteryStateNOk(15, 81, 0.3);
   testBatteryStateNOk(-6, 30, 0.4);
   testBatteryStateNOk(50, 5, 0.9);
   testBatteryStateNOk(8, -20, 1.2);
   testBatteryStateNOk(2, 13, -0.5);  
   return 0;
 }
