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
