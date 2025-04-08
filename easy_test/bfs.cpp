#include<iostream>
#include<queue>
using namespace std;



struct Friend{
    int x, y, z;
};
struct Edge{
    int des;
    int deltaX;
    int deltaY;
    int deltaZ;
    Edge(int d, int a,int b, int c){
        des = d;
        deltaX = a;
        deltaY = b;
        deltaZ = c;
    }
};
const int N = 1e5 + 4;
Friend f[N];
int vis[N] = {0};
queue<int> q;
int n, m, t,f1, f2,deltaX,deltaY,deltaZ,itx,x,y,z;
vector<vector<Edge>> e;
void bfs(){
    while(!q.empty()){
        int curI = q.front();
        q.pop();
        for(auto & _e : e[curI]){
            if(vis[_e.des] == 0){
                vis[_e.des] = 1;
                f[_e.des].x = f[curI].x + _e.deltaX;
                f[_e.des].y = f[curI].y + _e.deltaY;
                f[_e.des].z = f[curI].z + _e.deltaZ;
                q.push(_e.des);
            }
        }
    }
}
int main(void){

    cin >> n >> m;
    e.resize(n + 1);
    for(int i = 1; i <= m; i++){
        cin >> t;
        //1-base
        if(t == 1){
            cin >> f1 >> f2 >> deltaX >> deltaY >> deltaZ;
            Edge e1 = Edge(f2,deltaX,deltaY,deltaZ);
            e[f1].push_back(e1);
        }
        else{
            cin >> itx >> x >> y >> z;
            f[itx].x = x;
            f[itx].y = y;
            f[itx].z = z;
            vis[itx] = 1;
            q.push(itx);
        }
    }
    bfs();
    for(int i = 1; i <= n; i++){
        if(vis[i] == 1)
            cout << f[i].x << " " << f[i].y << " " << f[i].z << endl;
        else
            cout << -1 << endl;
    }
}