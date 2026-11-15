/*之前转专业考核有类似的题目，于是想练习一下，安慰一下当时没做出来的自己*/
/*你可能需要有一点点stl的基础*/

/*题目描述*/
/*有三对符号 () [] {} ，判断符号是否匹配*/
/*有三种情况，1.配错了 2.符号少了 3.符号多了 后两种最好判断，直接看个数*/
#include<iostream>
#include<stack>
using namespace std;

bool isValid(const string& s){
    //判断 多了/少了 的情况
    if(s.size() %2 != 0) return false;
    stack<char> st;
    //判断配错了的情况
    for(int i=0;i<s.size();i++){
        if(s[i] =='(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }else if(!st.empty() && s[i]==')' && st.top() == '('){
            st.pop(); //此处注意，可能出现 )( 的情况，此时st是空栈，不能.top()，故需要加个判空条件
        }else if(!st.empty() && s[i] == ']' && st.top() == '['){
            st.pop();
        }else if(!st.empty() && s[i] == '}' && st.top() == '{'){
            st.pop();
        }else return false;
    }

    return st.empty(); //如果最后为空则正确 反例为 (( ;
}

/*对比所找的视频代码，可以改进的：*/
/*我写：
    else if(s[i] == ')'){
        if(st.top() == '('){
            st.pop();
        }else{
            break;
        }*/

/*可改为*/
/*  else if(s[i]==')' && st.top() == '('){
        st.pop();
    }
        */