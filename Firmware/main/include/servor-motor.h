
// You can get these value from the datasheet of servo you use, in general pulse width varies between 1000 to 2000 mocrosecond
#define SERVO_MIN_PULSEWIDTH_US (1000) // Minimum pulse width in microsecond
#define SERVO_MAX_PULSEWIDTH_US (2000) // Maximum pulse width in microsecond
#define SERVO_MAX_DEGREE        (90)   // Maximum angle in degree upto which servo can rotate

#define MOTOR        (18)   // GPIO connects to the PWM signal line

#define POSITION_A 0
#define POSITION_B 90
#define POSITION_C 180
#define POSITION_D 270

void init_motor();