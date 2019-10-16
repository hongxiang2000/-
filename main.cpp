//
//  main.cpp
//  【算法分析与设计：2-1】众数问题
//
//  Created by 洪湘 on 2019/10/11.
//  Copyright © 2019 洪湘. All rights reserved.
//

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
