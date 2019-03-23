#ifndef _JHQUEUE_H_
#define _JHQUEUE_H_


typedef struct jhqueue_st{
    size_t size;	// Queue Size
    void** data;	// Data Infop
    int head;		// head Positon
    int cnt;		// the count of data;
}jhqueue_t;

jhqueue_t* jhqueue_create(size_t size);
int jhqueue_in(jhqueue_t* que, void* data);
int jhqueue_out(jhqueue_t* que, void** data);
void jhqueue_clear(jhqueue_t* que);
void jhqueue_free(jhqueue_t** que);


#endif /*  _JHQUEUE_H_ */
