#include <stdio.h>
#include <assert.h>
#include "BMSCheck.h"

int printCallCount = 0;

int fakePrintOnConsole(const char* condition) {
	printf("%s \n",condition);
	printCallCount++;
	return 0;
}

void testCheckBatteryTemperature(float temperature, int StatusOk) {
	assert(checkBatteryTemperature(temperature) == StatusOk);
}
 
void testCheckBatterySoC(float SoC, int StatusOk) {
	assert(checkBatterySoC(SoC) == StatusOk);
}

void testCheckBatteryChargeRate(float chargeRate, int StatusOk){
	assert(checkBatteryChargeRate(chargeRate) == StatusOk);
}
 
void testCheckBatterySoH(float temperature, float SoC, float chargeRate, int StatusOk){
	assert(checkBatterySoH(temperature, SoC, chargeRate) == StatusOk);
}

int main() {
	fpPrintOnConsole = &fakePrintOnConsole; //Assigning fake print function for testing
	testCheckBatteryTemperature(40, 1);
	testCheckBatteryTemperature(67, 0);
	testCheckBatterySoC(25, 1);
	testCheckBatterySoC(92, 0);
	testCheckBatteryChargeRate(0.2, 1);
	testCheckBatteryChargeRate(1.0, 0);
	testCheckBatterySoH(25, 45, 0.6, 1);
	testCheckBatterySoH(51, 100, 0.9, 0);
	testCheckBatterySoH(42, 88, 0.6, 0);
	testCheckBatterySoH(40, 65, 0.9, 0);
	assert(printCallCount == 6);
}
