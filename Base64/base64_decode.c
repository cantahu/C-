/*
 Author: Jet.Hu
 Date:2014/07/27.
 Just for fun...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "base64.h"


#define BASE64_DECODE_MASK 	0xf0	// 1111 0000

#define BASE64_END	64

static int32_t get_base64_index(uint8_t obj);
static void do_dedcode_ascii(uint8_t* obj, uint8_t* src, uint32_t len);

static int32_t
get_base64_index(uint8_t obj)
{
	int32_t ret = -1;
	int32_t i;
	
	if(obj == '='){
		ret = BASE64_END;
	}else{
		for(i =0 ; i < BASE64_SIZE; i++){
			if(obj == base64_tbl[i]){
				ret = i;
				break;
			}
		}		
	}
	
	return ret;
}

static void
do_dedcode_ascii(uint8_t* obj, uint8_t* src, uint32_t len)
{
	int8_t ret;
	uint8_t tmp;
	uint8_t data;

	uint32_t i;
	uint32_t data_index;
	uint32_t obj_index;

	
	if((obj == NULL) ||
		(src == NULL)){
		return;
	}
	
	obj_index = 0;
	for(i = 0; i < len; i++){
		ret = get_base64_index(src[i]);
		
		if(ret == -1){
			fprintf(stderr, "Can not use base64 decode it\n");
			break;
		}
		
		data = (uint8_t)ret;
		
		if(data == BASE64_END){
			obj[obj_index] = tmp;
			break;
		}
		
		data_index = i % 4;
		
		switch(data_index){
			case 0:
				tmp = data << 2;
				break;
			case 1:
				tmp = (data >> 4) | tmp;
				obj[obj_index++] = tmp;
				tmp = (data << 4) & BASE64_DECODE_MASK;
				break;
			case 2:
				tmp = (data >> 2) | tmp;
				obj[obj_index++] = tmp;
				tmp = data << 6;
				break;
			case 3:
				tmp = tmp | data;
				obj[obj_index++] = tmp;
				break;
			default:
				break;
		}
	}
}

base64_t *
decode_base64_ascii(int8_t* src, uint32_t len)
{
	uint8_t *tmpsrc;
	int32_t datalen;
	base64_t *obj = NULL;
	
	if(src == NULL){
		goto func_end;
	}
	
	obj = (base64_t *)malloc(sizeof(base64_t));
	if(obj == NULL){
		goto func_end;
	}
	
	datalen = len * 6 / 8;
	
	tmpsrc = strchr(src, '=');
	if(tmpsrc != NULL){
		datalen = datalen - strlen(tmpsrc);
	}
	
	obj->datalen = datalen;
	obj->data = (int8_t *)malloc(datalen + 1);
	if(obj->data == NULL){
		free_base64(obj);
		obj = NULL;
		goto func_end;
	}
	
	do_dedcode_ascii(obj->data, src, len);
	
func_end:
	return obj;
}

void
free_base64(base64_t *obj)
{
	if(obj != NULL){
		if(obj->data != NULL){
			free(obj->data);
		}
		free(obj);
	}
}
