#ifndef THIS_H
#define THIS_H

#include "stdio.h"
#include "string.h"
#include "malloc.h"


#define call(n) (*(n->setThis(n)))

typedef char boolean;
#define true        1
#define false       0

typedef struct Stack{
    unsigned char       top;      //栈顶指针
    unsigned char       base;     //栈底指针
    unsigned char       size;     //链栈最大深度
    void**              data;     //栈存储区
    boolean             flag;     //同步信号量

    void* (*getThis)(struct Stack* this);
    void  (*setThis)(struct Stack* this,void* object);
    void  (*destroy)(struct Stack* this);
} *Stack;

typedef Stack This;


Stack createThis(int size);       //创建LStack链栈对象
#endif 
