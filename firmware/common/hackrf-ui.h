#ifndef HACKRF_UI_H
#define HACKRF_UI_H

#include <rf_path.h>
#include <stdint.h>

typedef void (*hackrf_ui_init_fn)(void);
typedef void (*hackrf_ui_set_frequency_fn)(uint64_t frequency);
typedef void (*hackrf_ui_set_sample_rate_fn)(uint32_t sample_rate);
typedef void (*hackrf_ui_set_direction_fn)(const rf_path_direction_t direction);
typedef void (*hackrf_ui_set_filter_bw_fn)(uint32_t bandwidth);
typedef void (*hackrf_ui_set_lna_power_fn)(bool lna_on);
typedef void (*hackrf_ui_set_bb_lna_gain_fn)(const uint32_t gain_db);
typedef void (*hackrf_ui_set_bb_vga_gain_fn)(const uint32_t gain_db);
typedef void (*hackrf_ui_set_bb_tx_vga_gain_fn)(const uint32_t gain_db);
typedef void (*hackrf_ui_set_first_if_frequency_fn)(const uint64_t frequency);
typedef void (*hackrf_ui_set_filter_fn)(const rf_path_filter_t filter);
typedef void (*hackrf_ui_set_antenna_bias_fn)(bool antenna_bias);

typedef struct {
	hackrf_ui_init_fn init;
	hackrf_ui_set_frequency_fn set_frequency;
	hackrf_ui_set_sample_rate_fn set_sample_rate;
	hackrf_ui_set_direction_fn set_direction;
	hackrf_ui_set_filter_bw_fn set_filter_bw;
	hackrf_ui_set_lna_power_fn set_lna_power;
	hackrf_ui_set_bb_lna_gain_fn set_bb_lna_gain;
	hackrf_ui_set_bb_vga_gain_fn set_bb_vga_gain;
	hackrf_ui_set_bb_tx_vga_gain_fn set_bb_tx_vga_gain;
	hackrf_ui_set_first_if_frequency_fn set_first_if_frequency;
	hackrf_ui_set_filter_fn set_filter;
	hackrf_ui_set_antenna_bias_fn set_antenna_bias;
} hackrf_ui_t;

/* TODO: Lame hack to know that PortaPack was detected.
 * In the future, whatever UI was detected will be returned here,
 * or NULL if no UI was detected.
 */
const hackrf_ui_t* hackrf_ui(void) __attribute__((weak));

void hackrf_ui_init(void) __attribute__((weak));
void hackrf_ui_setFrequency(uint64_t _freq) __attribute__((weak));
void hackrf_ui_setSampleRate(uint32_t _sample_rate) __attribute__((weak));
void hackrf_ui_setDirection(const rf_path_direction_t _direction) __attribute__((weak));
void hackrf_ui_setFilterBW(uint32_t bw) __attribute__((weak));
void hackrf_ui_setLNAPower(bool _lna_on) __attribute__((weak));
void hackrf_ui_setBBLNAGain(const uint32_t gain_db) __attribute__((weak));
void hackrf_ui_setBBVGAGain(const uint32_t gain_db) __attribute__((weak));
void hackrf_ui_setBBTXVGAGain(const uint32_t gain_db) __attribute__((weak));

void hackrf_ui_setFirstIFFrequency(const uint64_t freq) __attribute__((weak));
void hackrf_ui_setFilter(const rf_path_filter_t filter) __attribute__((weak));
void hackrf_ui_setAntennaBias(bool antenna_bias) __attribute__((weak));

#endif
