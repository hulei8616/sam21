#ifndef __ALCS_ADAPTER_H__
#define __ALCS_ADAPTER_H__
#if defined(__cplusplus)
extern "C" {
#endif

#include "iot_export_mqtt.h"
#include "CoAPExport.h"
#include "alcs_mqtt.h"
#include "linked_list.h"
#include "iot_export_alcs.h"

typedef struct iotx_alcs_send_msg_st{
	uint8_t token_len;
	uint8_t *token;
	char *uri;
} iotx_alcs_send_msg_t, *iotx_alcs_send_msg_pt;

typedef enum {
	IOTX_ALCS_SUBDEV_DISCONNCET_CLOUD,
	IOTX_ALCS_SUBDEV_CONNECT_CLOUD
} iotx_alcs_subdev_stage_t;

#define IOTX_ALCS_SUBDEV_RETRY_INTERVAL_MS (10000)

typedef struct iotx_alcs_subdev_item_st{
	char product_key[PRODUCT_KEY_MAXLEN];
	char device_name[DEVICE_NAME_MAXLEN];
	char prefix[ALCS_MQTT_PREFIX_MAX_LEN];
	char secret[ALCS_MQTT_SECRET_MAX_LEN];
	uint8_t stage;
	uint64_t retry_ms;
} iotx_alcs_subdev_item_t, *iotx_alcs_subdev_item_pt;

typedef void (*iotx_alcs_auth_timer_fnuc_t)(CoAPContext *);

typedef struct iotx_alcs_adapter_st{
	void *mutex;
	CoAPContext *coap_ctx;
	uint8_t role;
	iotx_alcs_auth_timer_fnuc_t alcs_client_auth_timer_func;
	iotx_alcs_auth_timer_fnuc_t alcs_server_auth_timer_func;
	iotx_alcs_event_handle_t *alcs_event_handle;
	linked_list_t *alcs_send_list;
	linked_list_t *alcs_subdev_list;
	char local_ip[NETWORK_ADDR_LEN];
	uint16_t local_port;
} iotx_alcs_adapter_t, *iotx_alcs_adapter_pt;

int iotx_alcs_subdev_insert(iotx_alcs_subdev_item_t *item);
int iotx_alcs_subdev_remove(const char *pk, const char *dn);
int iotx_alcs_subdev_search(const char *pk, const char *dn, iotx_alcs_subdev_item_t **item);
int iotx_alcs_subdev_update_stage(iotx_alcs_subdev_item_t *item);
void iotx_alcs_send_list_handle(void* list_node, va_list* params);
int iotx_alcs_adapter_list_init(iotx_alcs_adapter_t *adapter);

#if defined(__cplusplus)
}
#endif
#endif
