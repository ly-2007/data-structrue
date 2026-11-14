#include<iostream>
#include<cstdlib>
using namespace std;

#define MAXSIZE 100
typedef int SElemType;/*说是比#define好，后者只是起到一个替换的作用*/

typedef struct{
    SElemType* base;
    SElemType* top;
    int stacksize;
}SqStack;
 
bool InitStack (SqStack &s){
    s.base = new SElemType[MAXSIZE];
    if(!s.base) {
        cout<<"overflow."<<endl;
        exit(1);
    }
    s.top = s.base;
    s.stacksize = MAXSIZE;
    return true;
}

bool IsEmpty(const SqStack &s){
   return s.base == s.top;
}

int StackLength(const SqStack &s){
    return (s.top-s.base);
}

void ClearStack(SqStack &s){
    if(s.base) s.top = s.base;
}

void DestroyStack(SqStack &s){
    if(s.base){
        delete[] s.base;
        s.stacksize = 0;
        s.base = nullptr;
        s.top = nullptr;
    }
}

bool Push(SqStack &s,SElemType a){
    if(s.top == s.base) return false;
    *s.top = a;//s.top = &a;我一开始写的是后者，指针赋值，是不对的，值得思考
    s.top++;
    return true;
}

SElemType& Pop(SqStack &s){
    if(s. top == s.base) exit(0);
    SElemType a = *s.top;
    s.top--;
    return a;
}

bool Pop (SqStack &s,SElemType &e){
    if(s.top == s.base) return false;
    e = *s.top;
    s.top--;
    return true;
}

int main(){

    return 0;
}