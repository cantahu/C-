#include <stdlib.h>
#include "jhstack.h"

jhstack_t*
jhstack_create(size_t size)
{
    jhstack_t* stk = NULL;
    void** data;

    stk = (jhstack_t*)malloc(sizeof(jhstack_t));
    if(!stk)goto FIN;

    data = (void**)malloc(sizeof(void*) * size);
    if(!data){
	jhstack_free(&stk);
	goto FIN;
    }

    stk->data = data;
    stk->size = size;
    stk->top = -1;
    
 FIN:
    return stk;
}

int
jhstack_push(jhstack_t* stk, void* data)
{
    int ret = -1;
    if(!stk)goto FIN;
    if(stk->top + 1 >= stk->size)goto FIN;

    stk->top++;
    *(stk->data + stk->top) = data;
    ret = 0;

 FIN:
    return ret;
}

int
jhstack_pop(jhstack_t* stk, void** data)
{
    int ret = -1;
    if(!stk)goto FIN;
    if(!data)goto FIN;
    if(stk->top == -1)goto FIN;

    *data = *(stk->data + stk->top--);
    ret = 0;
 FIN:
    return ret;
}

void
jhstack_clear(jhstack_t* stk)
{
    if(stk)stk->top = -1;
}

void
jhstack_free(jhstack_t** stk)
{
    if(!stk)goto FIN;    
    if((*stk)->data != NULL) free((*stk)->data);
    free(*stk);
    *stk = NULL;
 FIN:
    return;
}
