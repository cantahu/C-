/*
 Author: Jet.Hu
 Date:2014/07/23.
 Just for fun...
*/
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "base64.h"

#define  BASE64_MASK		0x3F		// 0011 1111

static void do_endcode_ascii(uint8_t* obj, uint8_t* src, uint32_t len);

//encode ASCII 
static void
do_endcode_ascii(uint8_t* obj, uint8_t* src, uint32_t len)
{
	uint8_t tmp;
	int32_t data_index;
	int32_t obj_index;
	int32_t i;
	
	if( (obj == NULL) ||
		(src == NULL)){
		return;
	}
	
	obj_index = 0;
	
	for(i = 0; i < len; i++){
		data_index = i % 3;
		
		switch(data_index){
			case 0:
				if( i != 0){
					tmp = src[i-1] & BASE64_MASK;
					obj[obj_index++] = base64_tbl[tmp];
				}
				tmp = src[i] >> 2;
				tmp = tmp & BASE64_MASK;
				obj[obj_index++] = base64_tbl[tmp];
				break;
			case 1:
				tmp = src[i-1] << 4;
				tmp = tmp | (src[i] >> 4);
				tmp = tmp & BASE64_MASK;
				obj[obj_index++] = base64_tbl[tmp];
				break;
			case 2:
				tmp = src[i-1] << 2;
				tmp = tmp | (src[i] >> 6);
				tmp = tmp & BASE64_MASK;
				obj[obj_index++] = base64_tbl[tmp];
				break;
			default:
				break;
		}
	}
	
	data_index = len % 3;
	switch(data_index){
		case 0:
			tmp = src[i-1] & BASE64_MASK;
			obj[obj_index] = base64_tbl[tmp];
			break;
		case 1:
			tmp = src[i-1] << 4;
			tmp = tmp & BASE64_MASK; 
			obj[obj_index++] = base64_tbl[tmp];
			obj[obj_index++] = '=';
			obj[obj_index] = '=';
			break;
		case 2:
			tmp = src[i-1] << 2;	
			tmp = tmp & BASE64_MASK; 
			obj[obj_index++] = base64_tbl[tmp];				
			obj[obj_index] = '=';
			break;
		default:
			break;
	}
}

base64_t *
creat_base64_ascii(int8_t* src, uint32_t len)
{
	int32_t datalen;

	base64_t *obj = NULL;
	
	if(src == NULL){
		goto func_end;
	}
	
	obj = (base64_t *)malloc(sizeof(base64_t));
	if(obj == NULL){
		goto func_end;
	}
	
	datalen = len * 8 / 6;
	if(len % 3 != 0){
		datalen = datalen + 1;
		datalen = datalen + (3 - len % 3);
	}
	
	obj->datalen = datalen;
	obj->data = (int8_t *)malloc(datalen + 1);
	if(obj->data == NULL){
		free_base64(obj);
		obj = NULL;
		goto func_end;
	}
	
	do_endcode_ascii(obj->data, src, len);

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
