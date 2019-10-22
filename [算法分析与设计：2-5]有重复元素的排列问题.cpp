//
//  main.cpp
//  【算法分析与设计：2-5】有重复元素的排列问题
//
//  Created by 洪湘 on 2019/10/16.
//  Copyright © 2019 洪湘. All rights reserved.
//

/*
 题目描述
 设R={ r1, r2 , …, rn}是要进行排列的n个元素。其中元素r1, r2 , …, rn可能相同。试设计一个算法，列出R的所有不同排列。

 输入
 文件的第 1 行是元素个数n，1≤n≤500。接下来的 1 行是待排列的n个元素。

 输出
 计算出的n个元素的所有不同排列输出到文件中。文件最后1行中的数是排列总数。

 样例输入
 4
 aacc
 样例输出
 aacc
 acac
 acca
 caac
 caca
 ccaa
 6
 */

#include <iostream>
using namespace std;

int hx_count=0;

void Swap(char &n,char &m) {
    char temp;
    temp=n;
    n=m;
    m=temp;
}

int hx_ok(char* list,int k,int i) {
    //判断第i个元素是否在前面的元素[k,i-1]中出现过，出现过则返回0
    if(i>k)
        for(int t=k;t<i;t++)
            if(list[t]==list[i])
                return 0;
    return 1;
}

void hx_Perm(char* list,int k,int m) {
    if(k==m) {//只剩一个元素时输出
        hx_count++;
        for(int i=0;i<=m;i++)
            cout<<list[i];
        cout<<endl;
    }
    else for(int i=k;i<=m;i++) {//还有多个元素待排列，递归产生排列
                                //若第i个元素在[k,i-1]中没有出现过，则交换list[k]和list[i]，再除i及i之前的元素进行排列
        if(hx_ok(list,k,i)) {
            Swap(list[k],list[i]);
            hx_Perm(list,k+1,m);
            Swap(list[k],list[i]);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    char list[n];
    for(int i=0;i<4;i++) {
        cin>>list[i];
    }
    hx_Perm(list, 0, n-1);
    cout<<hx_count<<endl;
    return 0;
}
