//
//  main.cpp
//  【算法分析与设计：2-3】半数集问题
//
//  Created by hx on 2019/10/16.
//  Copyright © 2019 hx. All rights reserved.
//

/*
 题目描述
 给定一个自然数n，由n开始可以依次产生半数集set(n)中的数如下。
 (1) n∈set(n)；
 (2) 在n的左边加上一个自然数，但该自然数不能超过最近添加的数的一半；
 (3) 按此规则进行处理，直到不能再添加自然数为止。 例如，set(6)={6,16,26,126,36,136}。半数集set(6)中有6 个元素。 注意半数集是多重集。

 输入
 对于给定的自然数n(0<n<1000)，计算半数集set(n)中的元素个数。

 输出
 程序运行结束时，将计算结果输出。输出只有1 行，给出半数集set(n)中的元素个数。
 */

#include <iostream>
#include <string>
using namespace std;

long a[1000]={0};

long hx_comp(long n) {
    long hx_ans=1;
    if(a[n]>0)
        return a[n];
    for(int i=1;i<=n/2;i++)
        hx_ans+=hx_comp(i);
    a[n]=hx_ans;
    return hx_ans;
}

int main(int argc, const char * argv[]) {
    long n=0;
    cin>>n;
    
    a[1]=1;
    cout<<hx_comp(n)<<endl;
    return 0;
}
