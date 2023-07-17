

// ================================= HEADERS =================================
#include "memory-task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "string.h"


char ssid[32];
char password[64];

void init_memory() {
	nvs_handle_t my_handle;
	size_t required_size = 0;
	esp_err_t err = nvs_open("storage", NVS_READWRITE, &my_handle);
	printf("Reading restart counter from NVS ... \n");
	err = nvs_get_str(my_handle, "ssid", NULL, &required_size);
	if(err == ESP_OK) {
		err = nvs_get_str(my_handle, "ssid", ssid, &required_size);
		printf("ssid value = %s\n", ssid);
	}
	else {
		printf("Error (%s) reading!\n", esp_err_to_name(err));
		strcpy(ssid, SSID_DEFAULT);
	}

	err = nvs_get_str(my_handle, "password", NULL, &required_size);
	if(err == ESP_OK) {
		err = nvs_get_str(my_handle, "password", password, &required_size);
		printf("password value = %s\n", password);
	}
	else {
		printf("Error (%s) reading!\n", esp_err_to_name(err));
		strcpy(password, PSW_DEFAULT);
	}
}