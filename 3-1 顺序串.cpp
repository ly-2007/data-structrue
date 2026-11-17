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

//串匹配（查找）
int Index_BF(String &s,String &T){
    int n = s.length;
    int m = T.length;
    int i = 0;
    int j = 0;
    while(i<n && j<m){
        if(s.ch[i] == T.ch[j]){
            i++;
            j++;
        }else{
            i = i-j+1; 
            //此处 i-j是i-移动次数，即回到开头，+1即新的起点
            j = 0;
        }
    }
    if(j == m) return i-m;//匹配成功 i-m即i-移动次数，即匹配的串起点
    return -1;
}
//串匹配（查找），从pos位置开始找 找不到就返回-1
bool Index_BF(String &S,String &T,int &pos){
    int n = S.length;
    int m = T.length;
    if(pos > n || pos < 0) return false;
    int i = pos,j = 0;
    while(i<n && j<m){
        if(S.ch[i] == T.ch[j]){
            i++;
            j++;
        }else{
            i = i-j+1;
            j = 0;
        }
    }
    if(j == m) {
        pos = i-m;
        return true;
    }
    return false;
}
//串匹配---KMP算法
int* build_next(String &a){
    return 
}
int Index_KMP(String &s,String &t){
    int* next = build_next(t);

    int i = j = 0;
    while(i < s.length){

    }
}