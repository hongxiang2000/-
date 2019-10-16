#include <iostream>
using namespace std;

void hx_fun(int page) {
    //我的函数
    //n表示页码

    int hx_result[10]; //我的结果
    int i,j;

    for(i=1;i<=page;i++) {//从1到page逐个统计
        if(i<10) {//个位数直接统计
            hx_result[i]++;
        }
        else {
            j=i;
            
            while(j) {
                hx_result[j%10]++;//统计最后一位数
                j=j/10;//去掉个位
            }
        }
    }

    for(i=0;i<10;i++) {//输出统计结果
        cout<<hx_result[i]<<endl;
    }
}

int main() {
    int page;
    cin>>page;
    hx_fun(page);
    return 0;
}
