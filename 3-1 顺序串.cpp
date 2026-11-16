#include<iostream>
using namespace std;

#define MAXSIZE 255 //注意，define后面不能加;

typedef struct {
    char ch[MAXSIZE+1];
    int length;
}String;

//串赋值
bool StrAssign(String &T ,char s){

}

//串比较
bool StrCompare(String s1,String s2){

}
//求串长
int StrLength(const String &s){

}
//串连接
bool Concat(String &T,String &s1,String &s2){

}
//求字串
bool SubString(String &Sub,String s,int pos,int len){

}
//串拷贝
bool StrCopy(String &T,String s){

}
//串判空
bool StrEmpty(const String &s){

}
//清空串

//字串的位置

//串替换

//子串插入

//字串删除

//串销毁