

#ifndef _MAIN_H_
#define _MAIN_H_

#include <k_api.h>

#ifdef __cplusplus
extern "C"
{
#endif


#define APP_DEBUG MX_DEBUG_ON
#define app_log(M, ...) MX_LOG(APP_DEBUG, "APP", M, ##__VA_ARGS__)

enum
{
	ALI_HANDLE_CURRENT_HUMIDITY,
	ALI_HANDLE_CURRENT_TEMPERATURE,
	ALI_HANDLE_SATURATION,
	ALI_HANDLE_BRIGHTNESS,
	ALI_HANDLE_HUE,
	ALI_HANDLE_LIGHT_SWITCH,
	ALI_HANDLE_IO_SWITCH_1,
	ALI_HANDLE_IO_SWITCH_2,
	ALI_HANDLE_CONSOLE,
	ALI_HANDLE_MAX,
};

mx_status rgbled_task_init(void);
mx_status SHT20_task_init(void);
mx_status switch_task_init(void);
mx_status console_task_init(void);

void SHT20_task(void);
void switch_task(void);

/* Attribute handlers */
mx_status handle_read_cur_humidity		(alisds_att_val_t *value);
mx_status handle_read_cur_temperature	(alisds_att_val_t *value);

mx_status handle_read_cur_saturation	(alisds_att_val_t *value);
mx_status handle_read_cur_bright		(alisds_att_val_t *value);
mx_status handle_read_cur_hue			(alisds_att_val_t *value);
mx_status handle_read_cur_light_switch	(alisds_att_val_t *value);
mx_status handle_write_cur_saturation	(alisds_att_val_t value);
mx_status handle_write_cur_bright		(alisds_att_val_t value);
mx_status handle_write_cur_hue			(alisds_att_val_t value);
mx_status handle_write_cur_light_switch	(alisds_att_val_t value);

mx_status handle_read_cur_switch_1		(alisds_att_val_t *value);
mx_status handle_read_cur_switch_2		(alisds_att_val_t *value);

mx_status handle_read_console			(alisds_att_val_t *value);
mx_status handle_write_console			(alisds_att_val_t value);


/* Attr write functions */
mx_status handle_write_cur_saturation	(alisds_att_val_t value);
mx_status handle_write_cur_bright		(alisds_att_val_t value);
mx_status handle_write_cur_hue			(alisds_att_val_t value);

void OLED_ShowStatusString(const char *status_str);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif