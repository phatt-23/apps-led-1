#ifndef __MODULE_H
#define __MODULE_H

#define ARR_LEN(x) sizeof(x)/sizeof(*x)

class PWMDigOut {
private:
	Ticker 		m_ticker;
    DigitalOut 	m_led;
    uint8_t 	m_jas;
    uint32_t 	m_T;
    uint32_t 	m_ticks;

public:
    PWMDigOut(PinName t_led_pin);
    void nastav_jas_proc(uint8_t t_jas);
    void pwm_control();
};

class BTN_NOT {
private:
	Ticker 		m_ticker;
	DigitalIn 	m_btn;
	bool* 		m_state;
	uint32_t 	m_T;
	uint32_t 	m_ticks;
	bool 		m_pressed;
public:
	BTN_NOT(PinName t_pin, bool* t_state);
	void btn_control();
};

class BTN_XOR {
private:
	Ticker 		m_ticker;
	DigitalIn 	m_btn;
	bool* 		m_true_state;
	bool* 		m_false_state;
	uint32_t 	m_T;
	uint32_t 	m_ticks;
	bool 		m_pressed;

public:
	BTN_XOR(PinName t_pin, bool* t_true_state, bool* t_false_state);
	void btn_control();
};

#endif//__MODULE_H

