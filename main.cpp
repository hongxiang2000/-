//
//  main.cpp
//  [算法分析与设计：1-2]字典序问题
//
//  Created by 洪湘 on 2019/10/9.
//  Copyright © 2019 洪湘. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int hx_f(int i,int k) {
    //hx_f函数表示以字母k开头的所有长度为k的升序字符串个数
    
    int hx_count=0;  //记录结果
    
    if(k==1) {
        return 1;
    }
    else {
        //k!=1时，f(i,k)为f(j,k-1)(j从i+1到26）的总和
        for(int j=i+1;j<=26;j++) {
            hx_count += hx_f(j,k-1);
        }
        
        return hx_count;
    }
}

int hx_g(int k) {
    //hx_g函数表示长度为k的升序字符串的个数
    
    int hx_count=0;  //记录结果
    
    if(k==1) {
        return 26;
    }
    else {
        for(int i=1;i<=26;i++) {
            for(int j=i+1;j<=26;j++) {
                hx_count += hx_f(j,k-1);
            }
        }
        
        return hx_count;
    }
}

int hx_code(string s,int k) {
    //hx_code函数计算长度为k的升序字符串i的编码
    int hx_sum=0;
    
    for(int i=0;i<k;i++) {
        hx_sum+=hx_g(i);
    }//所有长度小于k的升序字符串的个数
    
    int a=char(s[0])-'a'+1;
    int b=0;
    
    for(int i=1;i<a;i++) {
        hx_sum+=hx_f(i,k);
    }//所有以小于首字母的字母开头的长度为k的升序字符串的个数
    
    for(int i=1;i<k;i++) {
        b=char(s[i])-'a'+1;
        for(int j=a+1;j<b;j++) {
            hx_sum+=hx_f(j,k-i);
        }
        a=b;
    }//字符串中字母与其后一个字母之间的字母开头的长度为k-1的字符串的个数
    
    return  hx_sum+1;
}

int main(int argc, const char * argv[]) {
    int hx_n=0;  //要输入几行升序字符串
    cout<<"请输入升序字符串行数：";
    cin>>hx_n;
    
    string s[hx_n];  //存储升序字符串
    for(int i=0;i<hx_n;i++) {
        cin>>s[i];
    }
    
    for(int i=0;i<hx_n;i++) {
        int length=int(s[i].length());
        cout<<hx_code(s[i],length)<<endl;
    }
    
    return 0;
}
