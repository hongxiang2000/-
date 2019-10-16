//
//  main.cpp
//  [算法分析与设计：1-2]字典序问题
//
//  Created by hx on 2019/10/9.
//  Copyright © 2019 hx. All rights reserved.
//

/*
题目描述
«问题描述：
        在数据加密和数据压缩中常需要对特殊的字符串进行编码。给定的字母表 A 由 26 个小写英文字母组成 A={a,b,…,z}。该字母表产生的升序字符串是指字符串中字母按照从左到右出现的次序与字母在字母表中出现的次序相同，且每个字符最多出现 1 次。例如，a,b,ab,bc,xyz 等字符串都是升序字符串。现在对字母表 A 产生的所有长度不超过 6 的升序字符串按照字典序排列并编码如下。
1	2	…	26	27	28	…
a	b	…	z	ab	ac	…

        对于任意长度不超过 6 的升序字符串，迅速计算出它在上述字典中的编码。
«编程任务：
        对于给定的长度不超过 6 的升序字符串，编程计算出它在上述字典中的编码。

输入
文件的第一行是一个正整数 k，表示接下来共有 k 行。
接下来的 k 行中，每行给出一个字符串。

输出
运行结束输出共有 k 行，每行对应于一个字符串的编码

样例输入
2
a
b
样例输出
1
2
*/

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
