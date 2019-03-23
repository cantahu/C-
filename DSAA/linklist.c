/*****************************************************
** Author:J.Hu
** Date: 2015-05-04
** Copyright(c) All Rights Reserved.
*****************************************************/
/***** Include files ********************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"

/***** Define global ********************************/
/***** Define constant ******************************/
/***** Define structure *****************************/
/***** Define Prototype of functions ****************/
node_t *
node_create(elem_t data)
{
    node_t *lnk = NULL;

    lnk = (node_t*)malloc(sizeof(node_t));
    if(lnk){
	lnk->data = data;
	lnk->next = NULL;
    }
    return lnk;
}

int
node_insert(node_t **lnk, elem_t data, unsigned int index)
{
    int ret = DSAA_NG;
    int i;
    node_t *node = NULL;
    node_t *next = NULL;
    node_t *cur = NULL;
    node_t **tmp = NULL;
    
    if(!lnk)goto FIN;

    node = node_create(data);
    if(!node){
	goto FIN;
    }

    for(i = 0, tmp = lnk, next = *tmp; *tmp && i < index; i++){
	cur = *tmp;
	tmp = &(cur->next);
	next = cur->next;
    }
    
    node->next = next;
    *tmp = node;
    
    ret= DSAA_OK;
 FIN:
    return ret;
}

int
node_delete(node_t **lnk, elem_t data)
{
    int ret = DSAA_NG;
    node_t *cur;
    node_t **tmp;

    if(!lnk)goto FIN;

    tmp = lnk;
    while(*tmp){
	cur = *tmp;
	if(cur->data == data){
	    *tmp = cur->next;
	    free(cur);
	}else{
	    tmp = &(cur->next);
	}
    }
    ret = DSAA_OK;

 FIN:
    return ret;
}

void
node_destroy(node_t **lnk)
{
    node_t *tmp;
    
    if(lnk == NULL)return;
    while(*lnk){
	tmp = *lnk;
	*lnk = tmp->next;
	free(tmp);
    }
}

int
get_list_len(node_t *this)
{
    int len = 0;
 
    while(this != NULL){
	this = this->next;
	len++;
    }

    return len;    
}

int
main(int ac, char **av)
{
    node_t *obj;
    node_t *info;

    obj = node_create(100);
    node_insert(&obj, 50, 0);
    node_insert(&obj, 450, 1);
    node_insert(&obj, 350, 2);
    node_delete(&obj, 450);

    for(info = obj; info; info = info->next){
	printf("%d ", info->data);
    }

    node_destroy(&obj);
    
    return 0;
}
