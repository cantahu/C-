#include <stdlib.h>
#include "jhqueue.h"

jhqueue_t*
jhqueue_create(size_t size)
{
    jhqueue_t* que = NULL;
    void** data;

    que = (jhqueue_t*)malloc(sizeof(jhqueue_t));
    if(!que)goto FIN;
    
    data = (void**)malloc(sizeof(void*) * size);
    if(!data){
	jhqueue_free(&que);
	goto FIN;
    }
    que->data = data;
    que->size = size;
    que->head = 0;
    que->cnt = 0;

 FIN:
    return que;
}

int
jhqueue_in(jhqueue_t* que, void* data)
{
    int ret = -1;
    int offset;

    if(!que)goto FIN;
    if(que->cnt + 1 > que->size)goto FIN;

    //data in, cnt+1; and find the offset position;
    offset = (que->head + que->cnt++) % que->size;
    *(que->data + offset) = data;
    
    ret = 0;
 FIN:
    return ret;
}

int
jhqueue_out(jhqueue_t* que, void** data)
{
    int ret = -1;

    if(!que)goto FIN;
    if(!data)goto FIN;
    if(que->cnt == 0)goto FIN;
    
    *data = *(que->data + que->head);
    que->head = (que->head + 1) % que->size;
    //data out, cnt-1
    que->cnt--;

    ret = 0;
 FIN:
    return ret;
}

void
jhqueue_clear(jhqueue_t* que)
{
    if(que){
	que->head = 0;
	que->cnt = 0;
    }
}

void
jhqueue_free(jhqueue_t** que)
{
    if(!que)goto FIN;
    if((*que)->data)free((*que)->data);
    free(*que);
    *que = NULL;
 FIN:
    return;
}
