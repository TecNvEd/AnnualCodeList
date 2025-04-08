#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e4 + 5;
int n, m, k;
int f[N] = {0};
int g[N][N] = {0};
int timeCnt[N] = {0};
int x, y;
void dfs(int src, int t){
    for(int i = 1; i <= n; i++){
        if(g[src][i] == 1 && (timeCnt[i] == -1 || timeCnt[i] > t + 1)){
            timeCnt[i] = t + 1;
            dfs(i, t + 1);
        }
    }
}
int main(void){
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        cin >> x;
        f[x] = 1;
    }
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }
    memset(timeCnt, -1, sizeof(timeCnt));
    for(int i = 1; i <= n; i++){
        if(f[i] == 1){
            timeCnt[i] = 0;
            dfs(i, 0);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << timeCnt[i] << endl;
    }
}