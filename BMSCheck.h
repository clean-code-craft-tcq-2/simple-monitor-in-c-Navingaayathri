#define   MIN_BATTTEMP 0
#define   MAX_BATTTEMP 45
#define   MIN_BATTSoC 20
#define   MAX_BATTSoC 80
#define   MIN_BATTCHARGERATE 0
#define   MAX_BATTCHARGERATE 0.8

extern bool checkBatteryTemperature(float temperature);
extern bool checkBatterySoC(float SoC) ;
extern bool checkBatteryChargeRate(float chargeRate);
extern int BatteryStateOk(float temperature, float SoC , float chargeRate);
extern int BatteryStateNOk(float temperature, float SoC , float chargeRate);
extern int testBatteryStateOk(float temperature, float SoC, float chargeRate);
extern int testBatteryStateNOk(float temperature, float SoC, float chargeRate); 
extern int main();
