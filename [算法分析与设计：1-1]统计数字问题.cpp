#include <iostream>
using namespace std;

void hongxiang_fun(int page) {
    //我的函数
    //n表示页码

    int hongxiang_result[10]; //我的结果
    int i,j;

    for(i=1;i<=page;i++) {
        if(i<10) {
            hongxiang_result[i]++;
        }
        else {
            j=i;
            
            while(j) {
                hongxiang_result[j%10]++;
                j=j/10;
            }
        }
    }

    for(i=0;i<10;i++) {
        cout<<hongxiang_result[i]<<endl;
    }
}

int main() {
    int page;
    cin>>page;
    hongxiang_fun(page);
    return 0;
}