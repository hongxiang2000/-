//
//  main.cpp
//  [算法设计与分析：1-3]最多约数问题
//
//  Created by 洪湘 on 2019/10/10.
//  Copyright © 2019 洪湘. All rights reserved.
//

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
