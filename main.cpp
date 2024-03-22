#include "mbed.h"
#include "module.h"

PWMDigOut g_led[] = {
	{ PTC0 },
	{ PTC1 },
	{ PTC2 },
	{ PTC3 },
	{ PTC4 },
	{ PTC5 },
	{ PTC7 },
	{ PTC8 },
};

BTN_NOT g_toggle_btn  { PTC9,  &leds_toggle        };	// leds_toggle controls LEDS globally
BTN_XOR g_leds_on_btn { PTC10, &leds_on, &leds_off };	// sets the LEDS ON only if leds_toggle is true
BTN_XOR g_leds_off_btn{ PTC11, &leds_off, &leds_on };	// set the LEDS off

int main() {
	printf("Hello\n");

	for(size_t i = 0; i < ARR_LEN(g_led); ++i) {
		g_led[i].nastav_jas_proc(i * 5);
	}

    while(1) __WFI();
}

