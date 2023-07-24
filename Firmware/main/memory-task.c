

// ================================= HEADERS =================================
#include "memory-task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "string.h"

struct equipament Petfeeder;
nvs_handle_t my_handle;

void init_memory()
{
	// Initialize NVS
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
	{
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	size_t required_size = 0;
	esp_err_t err = nvs_open("storage", NVS_READWRITE, &my_handle);
	printf("Reading restart counter from NVS ... \n");
	err = nvs_get_str(my_handle, "ssid", NULL, &required_size);
	if (err == ESP_OK)
	{
		err = nvs_get_str(my_handle, "ssid", Petfeeder.ssid, &required_size);
		printf("Petfeeder. value = %s\n", Petfeeder.ssid);
	}
	else
	{
		printf("Error (%s) reading!\n", esp_err_to_name(err));
		strcpy(Petfeeder.ssid, SSID_DEFAULT);
	}

	err = nvs_get_str(my_handle, "password", NULL, &required_size);
	if (err == ESP_OK)
	{
		err = nvs_get_str(my_handle, "password", Petfeeder.password, &required_size);
		printf("password value = %s\n", Petfeeder.password);
	}
	else
	{
		printf("Error (%s) reading!\n", esp_err_to_name(err));
		strcpy(Petfeeder.password, PSW_DEFAULT);
	}

	err = nvs_get_i16(my_handle, "period", &Petfeeder.period);
	if (err == ESP_OK)
	{
		printf("period value = %d minutos\n", Petfeeder.period);
		Petfeeder.configured = true;
	}
	else
	{
		printf("Error (%s) reading!\n", esp_err_to_name(err));
		Petfeeder.period = PERIOD_DEFAULT;
		Petfeeder.configured = false;
	}
}

void configure_motor(int16_t period, bool startnow)
{
	Petfeeder.period = period;
	Petfeeder.configured = true;
	esp_err_t err = nvs_set_i16(my_handle, "period", (int16_t)period);
	err = nvs_commit(my_handle);
	printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
	
}