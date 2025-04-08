#include<iostream>

using namespace std;
const int N = 1e5 + 1;
int job[N] = {0};
int n, a;
int main(void){
    cin >> n >> a;
    for(int i = 0; i< n; i++){
        cin >> job[i];
    }
    int l = 0, r = 0;
    int jobCnt = 0, maxCnt = 0;
    while(r < n){
        while(r < n && (jobCnt < a || jobCnt == a && job[r] == 0)){
            maxCnt= max(maxCnt,r - l + 1);
            if(job[r] == 1)
                jobCnt++;
            r++;
        }
        //cout << "r: " << r << endl;
        while(l < r && l < n && jobCnt >= a){
            if(job[l] == 1)
                jobCnt--;
            l++;
        }
        //cout << "l: " << l << endl;
    }
    cout << maxCnt;
}