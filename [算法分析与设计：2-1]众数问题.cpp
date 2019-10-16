//
//  main.cpp
//  【算法分析与设计：2-1】众数问题
//
//  Created by hx on 2019/10/11.
//  Copyright © 2019 hx. All rights reserved.
//

/*
题目描述
所谓众数，就是对于给定的含有N个元素的多重集合，每个元素在S中出现次数最多的成为该元素的重数， 多重集合S重的重数最大的元素成为众数。例如：S={1,2,2,2,3,5}，则多重集S的众数是2，其重数为3。 现在你的任务是：对于给定的由m个自然数组成的多重集S，计算出S的众数及其重数。

输入
第一行为n，表示测试数据组数。(n<30) 每组测试的第一行是一个整数m，表示多重集S中元素的个数为m 接下来的一行中给出m(m<100)个不大于10万的自然数 （不会出现不同元素出现的次数相同的情况，如：S={11,11,22,22,33,33}）。

输出
每组测试数据输出一行，包含两个数，第一个是众数，第二个是其重数，中间以空格隔开。

样例输入
1
6
1 2 2 2 3 5
样例输出
2 3
*/

#include <iostream>
using namespace std;

int largest=0; //重数
int element=0; //众数

int hx_median(int *a,int &l,int &r) {
    //找中位数
    return a[(l+r)/2];
}

void hx_split(int *a,int med,int &l,int &r,int &l1,int &r1) {
    //用中位数将数组分为两段
    for(l1=0;l<=r;l1++) {
        if(a[l1]==med)
            break;
    }//找到第一个和中位数相等的数
    
    for(r1=l1+1;r1<=r;r1++) {
        if(a[r1]!=med) {
            r1--;
            break;
        }
    }//找到最后一个和中位数相等的数
}

void hx_mode(int *a,int l,int r) {
    int l1=0,r1=0;
    int med=hx_median(a, l, r);  //求中位数
    hx_split(a,med,l,r,l1,r1);
    
    if(largest<r1-l1+1) {
        largest=r1-l1+1;
        element=med;
    }//如果当前重数小于中位数的个数，则中位数的个数为新的重数
    
    if(l1-l>largest) {
        hx_mode(a,l,l1-1);
    }//如果左边的个数大于当前重数的个数，则真正的重数可能在左边
    
    if(r-r1>largest) {
        hx_mode(a,r1+1,r);
    }//如果右边的个数大于当前重数的个数，则真正的重数可能在右边
}

int main(int argc, const char * argv[]) {
    int n; //测试组数
    int m; //多重集S中元素的个数为m
    cin>>n;
    while(n--) {
        cin>>m;
        int a[m];
        for(int i=0;i<m;i++) {
            cin>>a[i];
        }
        hx_mode(a,0,m-1);
        cout<<element<<" "<<largest<<endl;
    }
    return 0;
}
