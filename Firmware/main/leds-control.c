

void led_control() {

	while(1) {
		if(not_connected)
			set_led_red();
		else if(not_configured)
			set_led_blue();
		else
			set_led_green();
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}

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

void init_leds() {
	// * Configuração dos Leds
	gpio_set_direction(LED_R, GPIO_MODE_OUTPUT);
	gpio_set_direction(LED_G, GPIO_MODE_OUTPUT);
	gpio_set_direction(LED_B, GPIO_MODE_OUTPUT);

	xtaskCreate(led_control, "led_control", 1024, NULL, 1, NULL);
}