#include <stdio.h>
#include <string.h>
#include "BMSCheck.h"

char String[85] = "Alert! Breach message : ";

int (*fpPrintOnConsole) (const char*) = &printOnConsole;

int printOnConsole(const char* BreachMessage) {
	printf("%s \n", BreachMessage);
	return 0;
}

int ValidTemperartureCheck(float parameterValue, float MinTemp_Threshold, float MaxTemp_Threshold) {
	if (parameterValue < MinTemp_Threshold || parameterValue > MaxTemp_Threshold) {
		return 0;
	}
	return 1;
}

int ChargeRateLimitCheck(float parameterValue, float max_limit) {
	if (parameterValue  > max_limit) {
		return 0;
	}
	return 1;
}

int BatteryStateCheck(int condition, const char* parameter) {
	char BreachMessage[85];
	strcpy(BreachMessage, String);
	if (condition == 0) {
		strcat(BreachMessage, parameter);
		(*fpPrintOnConsole)(BreachMessage);
	}
	return condition;
}

int checkBatteryTemperature(float temperature) {
	int condition;
	condition = ValidTemperartureCheck(temperature, MIN_THRESHOLD_BATT_TEMP, MAX_THRESHOLD_BATT_TEMP);
	condition = BatteryStateCheck(condition, "Temperature out of range");
	return condition;
}

int checkBatterySoC(float SoC) {
	int condition;
	condition = ValidTemperartureCheck(SoC, MIN_THRESHOLD_BATT_SoC, MAX_THRESHOLD_BATT_SoC);
	condition = BatteryStateCheck(condition, "State of Charge out of range");
	return condition;
}

int checkBatteryChargeRate(float chargeRate){
	int condition;
	condition = ChargeRateLimitCheck(chargeRate, MAX_THRESHOLD_BATT_CHARGE_RATE);
	condition = BatteryStateCheck(condition, "Charge Rate out of range");
	return condition;
}

int checkBatterySoH(float temperature, float SoC, float chargeRate){
	int condition;
	condition =(checkBatteryTemperature(temperature)) && (checkBatterySoC(SoC)) && (checkBatteryChargeRate(chargeRate));
	return condition;	
}
