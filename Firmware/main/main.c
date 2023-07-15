/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include "driver/mcpwm.h"
#include "soc/mcpwm_periph.h"


// * Requisitos para me guiar ao codigo
// * 1 - Criar uma task que pisque um led
// * 2 - Criar uma task que apite o buzzer
// * 3 - Criar uma task que controle o motor de passos
// * 4 - Criar uma task que leia o horario pelo wifi e configure o rtc local
// * 5 - Criar uma task que   envie e receba as configurações via wifi e salve na memoria flash

#define BUZZER 25

void app_main(void) {

	// * Inicializa os Leds
	init_leds();

    // * Inicializa a memoria
    init_memory();

	// * Inicializa os Leds
	init_motor();

	// * Inicializa o WIFI
	init_wifi();

	// * Configuração do Buzzer
	gpio_set_direction(BUZZER, GPIO_MODE_OUTPUT);

	while(1) {
         //Todo:  Aqui estará o codigo se aconteceu algo aciona tal coisa etc
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}
