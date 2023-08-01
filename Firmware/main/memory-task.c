

// ================================= HEADERS =================================
#include "memory-task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "string.h"

nvs_handle_t my_handle;

void init_memory(struct equipament *memory)
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
		err = nvs_get_str(my_handle, "ssid", memory->ssid, &required_size);
		printf("memory-> value = %s\n", memory->ssid);
	}
	else
	{
		printf("Error (%s) reading!\n", esp_err_to_name(err));
		strcpy(memory->ssid, SSID_DEFAULT);
	}

	err = nvs_get_str(my_handle, "password", NULL, &required_size);
	if (err == ESP_OK)
	{
		err = nvs_get_str(my_handle, "password", memory->password, &required_size);
		printf("password value = %s\n", memory->password);
	}
	else
	{
		printf("Error (%s) reading!\n", esp_err_to_name(err));
		strcpy(memory->password, PSW_DEFAULT);
	}

	err = nvs_get_i16(my_handle, "period", &memory->period);
	if (err == ESP_OK)
	{
		printf("period value = %d minutos\n", memory->period);
		memory->configured = true;
	}
	else
	{
		printf("Error (%s) reading!\n", esp_err_to_name(err));
		memory->period = PERIOD_DEFAULT;
		memory->configured = false;
	}
	err = nvs_get_i16(my_handle, "position", &memory->position);
	if (err == ESP_OK)
	{
		printf("position value = %d minutos\n", memory->position);
	}
	else
	{
		printf("Error (%s) reading!\n", esp_err_to_name(err));
		memory->position = 0;
	}
}

void configure_motor(int16_t period, bool startnow)
{
	esp_err_t err = nvs_set_i16(my_handle, "period", (int16_t)period);
	err = nvs_commit(my_handle);
	printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
}

void save_position(int16_t position)
{
	esp_err_t err = nvs_set_i16(my_handle, "position", (int16_t)position);
	err = nvs_commit(my_handle);
	printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
}
