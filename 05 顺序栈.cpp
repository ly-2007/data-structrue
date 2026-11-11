#include<iostream>
#include<cstdlib>
using namespace std;

#define MAXSIZE 100
typedef int SElemType;/*shuo shi bi #define hao,yingwei define zhishitidai*/

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
    *s.top = a;//s.top = &a;
    s.top++;
    return true;
}
//converse,return remainder 
int converse(int a,int radix){
    return a%radix;
}

int main(){

    return 0;
}