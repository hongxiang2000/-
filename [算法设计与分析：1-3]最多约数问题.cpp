//
//  main.cpp
//  [算法设计与分析：1-3]最多约数问题
//
//  Created by hx on 2019/10/10.
//  Copyright © 2019 hx. All rights reserved.
//

/*
题目描述
«问题描述：
        正整数 x 的约数是能整除 x 的正整数。正整数 x 的约数个数记为 div(x)。例如，1，2，5，10 都是正整数10 的约数，且 div(10)=4。设 a 和 b 是 2 个正整数，a≤b，找出 a 和 b之间约数个数最多的数 x。
«编程任务：
        对于给定的 2 个正整数 a≤b，编程计算 a 和 b 之间约数个数最多的数。 
输入
第1 行有 2 个正整数 a 和 b。 
输出
若找到的 a 和 b 之间约数个数最多的数是 x，将 div(x)输出
样例输入
1 36
样例输出
9
提示
输入范围：1-1000000000
*/

#include <iostream>
using namespace std;

#define max Max
const long MAXP=100000;
long prim[MAXP];
long max,numb,PCOUNT;//max存放最多约数个数，numb存放约数个数最多的数

void hx_primes() {
    //产生质数
    bool hx_get[MAXP+1];
    for(long i=2;i<=MAXP;i++) {
        hx_get[i]=true;
    }
    for(long i=2;i<=MAXP;i++) {      
        if(hx_get[i]) {
            long j=i+i;
            while(j<=MAXP) {
                hx_get[j]=false;
                j+=i;
            }
        }
    }
    long ii,j;
    for(ii=2,j=0;ii<=MAXP;ii++) {
    if(hx_get[ii])
        prim[++j]=ii;
    }
    PCOUNT=j;
}

void hx_search(long from,long tot,long num,long low,long up) {
    //区间[low,up]上，tot为当前约数最多个数，num是约数最多的数。from表示现在是第几个质数
    if(num>=1)
        if((tot>max) || ((tot==max) &&(num<numb)))  {
            max=tot;
            numb=num;
        }
    
    if((low==up) &&(low>num))
        hx_search(from,tot*2,num*low,1,1);
    
    for(long i=from;i<=PCOUNT;i++) {
        if(prim[i]>up)
            return;
        else {
            long j=prim[i],x=low-1,y=up,n=num,t=tot,m=1;
            while(true) {
                m++;
                t+=tot;
                x/=j;
                y/=j;
                if(x==y)
                    break;
                n*=j;
                hx_search(i+1,t,n,x+1,y);
            }
            m=1<<m;
            if(tot<max/m)
                return;
        }
    }
}

int main(int argc, const char * argv[]) {
    hx_primes();
    long hx_l,hx_u;
    cin>>hx_l>>hx_u;
    if((hx_l==1)&&(hx_u==1)) {
        max=1;
        numb=1;
    }
    else {
        max=2;
        numb=hx_l;
        hx_search(1,1,1,hx_l,hx_u);
    }
    cout<<max<<endl;
    return 0;
}
