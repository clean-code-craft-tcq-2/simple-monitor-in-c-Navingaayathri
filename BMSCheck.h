#define MIN_BATT_TEMP 0
#define MAX_BATT_TEMP 45
#define MIN_BATT_SoC 20
#define MAX_BATT_SoC 80
#define MIN_BATT_CHARGE_RATE 0
#define MAX_BATT_CHARGE_RATE 0.8

extern bool checkValidRange(float inputValue, float MinThresholdvalue, float MaxThresholdvalue);
extern bool checkBatteryTemperature(float temperature, float MIN_BATT_TEMP, float MAX_BATT_TEMP);
extern bool checkBatterySoC(float SoC, float MIN_BATT_SoC, float MAX_BATT_SoC) ;
extern bool checkBatteryChargeRate(float chargeRate, float MIN_BATT_CHARGE_RATE, float MAX_BATT_CHARGE_RATE);
extern int BatteryStateOk(float temperature, float SoC , float chargeRate, bool StateOk);
extern int BatteryStateNOk(float temperature, float SoC , float chargeRate, bool StateNOk);
extern void displayonConsole();
extern int main();
