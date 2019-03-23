/*****************************************************
** Author:J.Hu
** Date: 2015-05-04
** Copyright(c) All Rights Reserved.
*****************************************************/
#ifndef _LINKLIST_H_
#define _LINKLIST_H_
/***** INCLUDES *************************************/
/***** TYPEDEFS *************************************/
struct node_st;

typedef int elem_t;
typedef struct node_st *node_ptr_t;
typedef node_ptr_t pos_t;

typedef struct node_st{
    elem_t data;
    pos_t next;
}node_t;

/***** DEFINES **************************************/
#define DSAA_OK 0
#define DSAA_NG -1

/***** EXTERNAL VARIABLES ***************************/
/***** EXTERNAL FUNCTIONS ***************************/
/***** VARIABLES ************************************/
/***** PROTOTYPES ***********************************/




/***** CONSTANTS ************************************/
#endif /* _LINKLIST_H_ */
