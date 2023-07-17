
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

//! Instale a extensao no vscode better comments
// * Requisitos para me guiar ao codigo
// * 1 - Criar uma task que pisque um led
// * 2 - Criar uma task que apite o buzzer
// * 3 - Criar uma task que controle o motor de passos
// * 4 - Criar uma task que leia o horario pelo wifi e configure o rtc local
// * 5 - Criar uma task que   envie e receba as configurações via wifi e salve na memoria flash

#define BUZZER 25

void app_main(void)
{

	// * Inicializa os Leds
	init_leds();

	// * Inicializa a memoria
	init_memory();

	// * Inicializa os Leds
	init_motor();

	// * Inicializa o WIFI
	init_wifi();

	// * Configuração do Buzzer
	gpio_pad_select_gpio(BUZZER);
	gpio_set_direction(BUZZER, GPIO_MODE_OUTPUT);

	while (1)
	{
		// Todo:  Aqui estará o codigo se aconteceu algo aciona tal coisa etc
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}
