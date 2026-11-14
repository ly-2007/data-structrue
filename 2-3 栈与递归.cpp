#include<iostream>
using namespace std;

//递归--后调用的先返回--->栈
//递归求阶乘
long Fact(long n){
    if(n == 0) return 1;        //归纳项
    else return n*Fact(n-1);    //基本项
}

//递归求斐波那契数列
long Fibonaci(long n){
    if(n == 1 || n == 2){
        return 1;
    }else 
        return Fibonaci(n-1) + Fibonaci(n-2);
}

//


int main(){


    return 0;
}