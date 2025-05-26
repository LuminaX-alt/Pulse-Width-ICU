pmc_enable_periph_clk(ID_PWM);
/** Input parameters when initializing PWM */
typedef struct {
	/** Frequency of clock A in Hz (set 0 to turn it off) */
	uint32_t ul_clka;
	/** Frequency of clock B in Hz (set 0 to turn it off) */
	uint32_t ul_clkb;
	/** Frequency of master clock in Hz */
	uint32_t ul_mck;
} pwm_clock_t;
pwm_clock_t PWMDAC_clock_config = 
{
	.ul_clka = 1000000,
	.ul_clkb = 0,
	.ul_mck = sysclk_get_cpu_hz()
};
pwm_init(PWM, &PWMDAC_clock_config);
pwm_channel_instance.channel = PWM_CHANNEL_0;
pwm_channel_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;
pwm_channel_instance.polarity = PWM_HIGH;
pwm_channel_instance.alignment = PWM_ALIGN_LEFT;
pwm_channel_instance.ul_period = 20;
pwm_channel_instance.ul_duty = 5;
#include 

#define PWM_DAC IOPORT_CREATE_PIN(PIOA, 23)

pwm_channel_t pwm_channel_instance;

int main (void)
{
	//clock configuration and initialization
	sysclk_init();
	
	/*Disable the watchdog timer and configure/initialize
	port pins connected to various components incorporated 
	into the SAM4S Xplained development platform, e.g., the 
	NAND flash, the OLED interface, the LEDs, the SW0 pushbutton.*/  
	board_init();
	
	//connect peripheral B to pin A23
	pio_configure_pin(PWM_DAC, PIO_TYPE_PIO_PERIPH_B);

	//enable the peripheral clock for the PWM hardware
	pmc_enable_periph_clk(ID_PWM);

	//disable the channel until it is properly configured
	pwm_channel_disable(PWM, PWM_CHANNEL_0);

	//PWM clock configuration
	pwm_clock_t PWMDAC_clock_config = 
	{
		.ul_clka = 1000000,
		.ul_clkb = 0,
		.ul_mck = sysclk_get_cpu_hz()
	};
	
	//apply the clock configuration
	pwm_init(PWM, &PWMDAC_clock_config);
	
	//see the article for details
	pwm_channel_instance.channel = PWM_CHANNEL_0;
	pwm_channel_instance.ul_prescaler = PWM_CMR_CPRE_CLKA;
	pwm_channel_instance.polarity = PWM_HIGH;
	pwm_channel_instance.alignment = PWM_ALIGN_LEFT;
	pwm_channel_instance.ul_period = 20;
	pwm_channel_instance.ul_duty = 5;
	
	//apply the channel configuration
	pwm_channel_init(PWM, &pwm_channel_instance);
	
	//configuration is complete, so enable the channel
	pwm_channel_enable(PWM, PWM_CHANNEL_0);
	
	while(1);
}
