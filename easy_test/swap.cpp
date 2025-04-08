#include<iostream>
#include<algorithm>
using namespace std;
string num,numT,maxNum;
int cnt,strLen;
void dfs(int t){
    if(num == numT || t >= strLen * (strLen - 1) / 2){
        maxNum = numT;
        return;
    }
    if(t == 0){
        if(num > maxNum)
            maxNum = num;
        return;
    }
    for(int i = 0; i < strLen - 1; i++){
        if((i == 0 && num[1] == 0) || num[i] >= num[i + 1])
            continue;
        else{
            swap(num[i],num[i + 1]);
            dfs(t - 1);
            swap(num[i],num[i + 1]);
        }
    }

}
int main(void){
    cin >> num >> cnt;
    strLen = num.size();
    numT = num;
    sort(numT.begin(),numT.end(),greater<char>());

    dfs(cnt);
    cout << maxNum;

}