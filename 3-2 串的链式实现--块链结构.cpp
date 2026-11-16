//以一个个字符块为单位连接起来的链表
//chunk 语块
#include<iostream>
using namespace std;

#define CHUNKSIZE 80

typedef struct Chunk{
    char ch[CHUNKSIZE];
    struct Chunk* next;
}Chunk;

typedef struct{
    Chunk *head,*tail;
    int curlen;
}LString;

int main(){
    
    return 0;
}