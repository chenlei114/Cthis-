#include "This.h"


static inline void* pop(This this);
static inline void  push(This this,void* data);
static inline void* getThis(This this);
static inline void  setThis(This this,void* object);
static void  		destroy(This this);

This createThis(int size){
    This this = malloc(sizeof(struct Stack));
    memset(this,0,sizeof(struct Stack));
    this->base     = 0;
    this->top      = 0;
    this->size     = size;
    this->flag     = false;
    this->data     = malloc(size*sizeof(int));
    memset(this->data,0,size*sizeof(int));

    //初始化对象方法
    this->setThis=setThis;
    this->getThis=getThis;
    this->destroy=destroy;

    return this;
}


static inline void*  pop(This this){
    if(this->top-this->base>0){
        return this->data[--this->top];
    }else{
        printf("Stack Overflow!\n");
        exit(0);
    }
}

static inline void  push(This this,void* data){
    if(this->top-this->base<this->size){
        this->data[this->top++]=data;
    }else{
        printf("Stack Overflow!\n");
        exit(0);
    }
}

static inline void* getThis(This this){
    //对象出栈
    void* object=pop(this);
    //解对象入栈出栈同步锁
    this->flag=false;
    return object;
}

static inline void  setThis(This this,void* object){
    //等待flag锁解除
    while(this->flag);
    //给对象入栈出栈操作上同步锁
    this->flag=true;
    //对象入栈
    push(this,object);
}



static void  destroy(This this){
    free(this->data);
    free(this);
} 
