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
        if(job[r] == 0){
            maxCnt = max(maxCnt, r - l + 1);
        }
        else{
            //job[r] == 1;
            jobCnt++;
            while(l < r && jobCnt > a){
                if(job[l] == 1)
                    jobCnt -= 1;
                l++;
            }
        }
        maxCnt = max(maxCnt, r - l + 1);
        r++;
    }
    cout << maxCnt;
}