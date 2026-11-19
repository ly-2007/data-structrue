#include<iostream>
using namespace std;

#define MAXSIZE 255 //注意，define后面不能加;

typedef struct {
    char ch[MAXSIZE+1];
    int length;
}SString;

//串赋值
bool StrAssign(SString &T ,char s){

}

//串比较
bool StrCompare(SString s1,SString s2){

}
//求串长
int StrLength(const SString &s){

}
//串连接
bool Concat(SString &T,SString &s1,SString &s2){

}
//求字串
bool SubSSSString(SString &Sub,SString s,int pos,int len){

}
//串拷贝
bool StrCopy(SString &T,SString s){

}
//串判空
bool StrEmpty(const SString &s){

}
//清空串

//字串的位置

//串替换

//子串插入

//字串删除

//串销毁

//串匹配（查找）
int Index_BF(SString &s,SString &T){
    int i = 0;
    int j = 0;
    while(i < s.length && j< T.length){
        if(s.ch[i] == T.ch[j]){
            i++;
            j++;
        }else{
            i = i-j+1; 
            //此处 i-j是(i-移动次数)，即回到开头，+1即新的起点
            j = 0;
        }
    }
    if(j == T.length) return i-T.length;//匹配成功 i-m即i-移动次数，即匹配的串起点
    return -1;
}
//串匹配（查找），从pos位置开始找 找不到就返回-1
bool Index_BF(SString &S,SString &T,int &pos){
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
int* build_next(const SString &a){
    int m = a.length;
    int* next = new int[m+1];//
    next[0] = 0;
    next[1] = 0;
    int i = 1,j = 0;
    while(i<m){
        if(a.ch[i] == a.ch[j]){
            j++;
            next[i+1] = j;
            //现在在被比较的是第i个和第j个，所以i是被包含在前缀部分的，所以在next[]中要i+1.
            i++;
        }else if(j > 0){
            j = next[j];
        }else{
            next[i+1] = 0;
            i++;
        }
    }
    return next;
}
int Index_KMP(SString &s,SString &t){
    int i = 0,j = 0;
    int* next = build_next(t);

    while(i < s.length && j < t.length){
        if( s.ch[i] == t.ch[j]){
            i++;
            j++;
        }else if(j == 0){
            i++;
        }else{//不匹配，i不回溯
            //此处不i++,如果此时 i++,就相当于直接跳过了主串这个字符，可能漏掉真正的匹配结果
            j = next[j];
        }
    }
    if(j == t.length) return i - j;
    //此处i-j 即i-移动次数，回到最开始的下标
    return -1;
}
int Index_KMP(SString &s,SString &t,int pos){
    int i = pos,j = 1;
    int* next = build_next(t);

    while(i < s.length && j < t.length){
        if(s.ch[i] == t.ch[j]){
            i++;
            j++;
        }else{
            j = next[j];
            
        }
    }
    if()
}