#include <time.h>
#include "esp_tls.h"

#define SSID_DEFAULT "celular"
#define PSW_DEFAULT "12345678"
#define PERIOD_DEFAULT 240 // 4 horas

struct equipament
{
    char ssid[32];
    char password[64];
    int16_t period;
    bool configured;
    int16_t last_position;
    time_t last_time;
};

void init_memory();
void configure_motor(int16_t period, bool startnow);
