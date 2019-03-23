#ifndef _JHSTACK_H_
#define _JHSTACK_H_

typedef struct jhstack_st{
    size_t size;
    int top;
    void** data;
}jhstack_t;

jhstack_t* jhstack_create(size_t size);
int jhstack_push(jhstack_t* stk, void* data);
int jhstack_pop(jhstack_t* stk, void** data);
void jhstack_clear(jhstack_t* stk);
void jhstack_free(jhstack_t** stk);

#endif /* _JHSTACK_H_ */
