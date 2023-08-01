
// ================================= HEADERS =================================
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "leds-control.h"
#include "servor-motor.h"
#include "memory-task.h"
#include "communication-task.h"
#include "bluetooth-task.h"

//! Instale a extensao no vscode better comments
// * Requisitos para me guiar ao codigo
// * 1 - Criar uma task que pisque um led
// * 2 - Criar uma task que apite o buzzer
// * 3 - Criar uma task que controle o motor de passos
// * 4 - Criar uma task que leia o horario pelo wifi e configure o rtc local
// * 5 - Criar uma task que   envie e receba as configurações via wifi e salve na memoria flash

#define BUZZER 25

struct equipament PetFedder;

void app_main(void)
{

	// * Inicializa os Leds
	init_leds();

	// * Inicializa a memoria
	init_memory(&PetFedder);

	// * Inicializa os Leds
	init_motor(PetFedder.position);

	// * Inicializa o BLE
	init_bluetooth();

	// * Inicializa o WIFI
	init_wifi(&PetFedder);

	// * Configuração do Buzzer
	gpio_pad_select_gpio(BUZZER);
	gpio_set_direction(BUZZER, GPIO_MODE_OUTPUT);

	time_t current_time;
	double diff_minutes;

	while (1)
	{
		printLocalTime(&current_time);
		diff_minutes = difftime(current_time, PetFedder.last_time) / 60;
		if (diff_minutes >= PetFedder.period)
		{
			put_motor_in_next_position(&PetFedder.position);
			PetFedder.last_time = current_time;
		}

		vTaskDelay(5000 / portTICK_PERIOD_MS);
	}
}
