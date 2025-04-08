#include<iostream>

using namespace std;

int a[105][105] ={0},b[105][105] = {0};
string str;
int n, m;
bool check(int x, int y){
    if(a[x][y] != b[x][y])
        return false;
    for(int i = x; i < x + m; i++){
        for(int j = y; j < y + m; j++){
            if(a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}
int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < n; j++){
            a[i][j] = str[j] == 'R' ? 1 : 0;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> str;
        for(int j = 0; j < m; j++){
            a[i][j] = str[j] == 'R' ? 1 : 0;
        }
    }
    for(int i = 0; i <= n - m; i++){
        for(int j = 0; j <= n - m; j++){
            if(check(i, j))
                {
                    cout << "YES";
                    return 0;
                }
        }
    }
    cout <<"No";
}