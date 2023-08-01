
// ================================= HEADERS =================================
#include "servor-motor.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/mcpwm.h"

#define MODEL 2
int16_t box_position[4] = {POSITION_A, POSITION_B, POSITION_C, POSITION_D};
static inline uint32_t servo_per_degree_init(int angle)
{
	return (angle + SERVO_MAX_DEGREE) * (SERVO_MAX_PULSEWIDTH_US - SERVO_MIN_PULSEWIDTH_US) /
			   (2 * SERVO_MAX_DEGREE) +
		   SERVO_MIN_PULSEWIDTH_US;
}

void put_motor_in_position(int8_t position)
{
	int angle = servo_per_degree_init(box_position[position]); // Volta para a posição inicial sempre que liga
	mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, angle);
}

void put_motor_in_next_position(int8_t *position)
{
	int angle = servo_per_degree_init(box_position[*position++]); // Volta para a posição inicial sempre que liga
	mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, angle);
	*position %= MODEL;
}

void init_motor(int16_t last_pos);
{
	mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, MOTOR); // To drive a RC servo, one MCPWM generator is enough

	mcpwm_config_t pwm_config = {
		.frequency = 50, // frequency = 50Hz, i.e. for every servo motor time period should be 20ms
		.cmpr_a = 0,	 // duty cycle of PWMxA = 0
		.counter_mode = MCPWM_UP_COUNTER,
		.duty_mode = MCPWM_DUTY_MODE_0,
	};
	mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);

	put_motor_in_position(last_pos);
}