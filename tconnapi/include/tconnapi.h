#ifndef _H_TCONNAPI_H
#define _H_TCONNAPI_H

#ifdef  __cplusplus
extern "C" {
#endif

#include "tbusapi.h"
#include "sip.h"

typedef struct tconnapi_s tconnapi_t;

typedef sip_size_t (*encode_t)(const void *self, char *start, char *limit);
typedef void (*tconnapi_on_connect_func)(tconnapi_t *self, const sip_cid_t *cid);
typedef void (*tconnapi_on_close_func)(tconnapi_t *self, const sip_cid_t *cid);
typedef void (*tconnapi_on_recv_func)(tconnapi_t *self, const sip_cid_t *cid, const char *packet, sip_size_t packet_size);

struct tconnapi_s
{
    tbusapi_t tbusapi;

	encode_t encode;
	tconnapi_on_connect_func on_connect;
	tconnapi_on_close_func on_close;
	tconnapi_on_recv_func on_recv;
};




TERROR_CODE tconnapi_init(tconnapi_t *self, key_t ikey, key_t okey, encode_t encode);

void tconnapi_accept(tconnapi_t *self, const sip_cid_t *cid_vec, uint16_t cid_vec_num);

void tconnapi_send(tconnapi_t *self, const sip_cid_t *cid_vec, uint16_t cid_vec_num, const void* data);

void tconnapi_close(tconnapi_t *self, const sip_cid_t *cid_vec, uint16_t cid_vec_num);

TERROR_CODE tconnapi_process(tconnapi_t *self);

#ifdef  __cplusplus
}
#endif

#endif//_H_TCONNAPI_H

