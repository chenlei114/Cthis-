#include "MyString.h"

static This   this = NULL;
static String setThis(String string){
    this->setThis(this,string);
    return string;
}

static void getNext(char*T,int* next);
static int indexOf_KMP(char* S,char* T);
static int indexOf(String T);
boolean equals(struct String* T);

String createString(char* str){
    //初始化This栈
    if(this==NULL){
        this= createThis(10);
    }
    int length= strlen(str);
    String string= malloc(sizeof(struct String));
    memset(string,0,sizeof(struct String));
    string->str= malloc(sizeof(char)*length+1);
    strcpy(string->str,str);
    string->length=length;

    string->setThis=setThis;
    string->indexOf=indexOf;
    string->equals=equals;

    return string;
}


static int indexOf(String T){
    String temp=this->getThis(this);
    return indexOf_KMP(temp->str,T->str);
}


boolean equals(struct String* T){
    String temp=this->getThis(this);
    if(strcmp(temp->str,T->str)!=0){
        return false;
    }
    return true;
}


static void getNext(char* T,int* next){
    int i=1;
    next[1]=0;
    int j=0;
    while (i<strlen(T)) {
        if (j==0||T[i-1]==T[j-1]) {
            i++;
            j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}

static int indexOf_KMP(char* S,char* T){
    int lengthS = strlen(S);
    int lengthT = strlen(T);
    int next[lengthT];
    getNext(T,next);
    int i=1,j=1;
    while (i<=lengthS&&j<=lengthT) {
        if (j==0 || S[i-1]==T[j-1]) {
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    if (j>lengthT) {
        return i-lengthT-1;
    }
    return -1;
} 
