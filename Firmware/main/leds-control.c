

// ================================= HEADERS =================================
#include "leds-control.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void set_led_red() {
	// Ligado mas não está conectado ao wifi
	gpio_set_level(LED_R, true);
	gpio_set_level(LED_G, false);
	gpio_set_level(LED_B, false);
}

void set_led_green() {
	// Ligado e configurado
	gpio_set_level(LED_R, false);
	gpio_set_level(LED_G, true);
	gpio_set_level(LED_B, false);
}

void set_led_blue() {
	// Ligado e conectado ao wifi mas não configurado
	gpio_set_level(LED_R, false);
	gpio_set_level(LED_G, false);
	gpio_set_level(LED_B, true);
}

void led_control() {
	//TODO: Colocar o status para ser recebido pela queue para ser controlado
	while(1) {
		set_led_red();
		vTaskDelay(100 / portTICK_PERIOD_MS);

		set_led_blue();
		vTaskDelay(100 / portTICK_PERIOD_MS);

		set_led_green();
		vTaskDelay(100 / portTICK_PERIOD_MS);
	}
}

void init_leds() {
	// * Configuração dos Leds como saidas
	gpio_pad_select_gpio(LED_R);
	gpio_set_direction(LED_R, GPIO_MODE_OUTPUT);

	gpio_pad_select_gpio(LED_G);
	gpio_set_direction(LED_G, GPIO_MODE_OUTPUT);

	gpio_pad_select_gpio(LED_B);
	gpio_set_direction(LED_B, GPIO_MODE_OUTPUT);

	xTaskCreate(led_control, "led_control", 1024, NULL, 1, NULL);
}