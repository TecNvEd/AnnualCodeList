#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq[4];
priority_queue<int,vector<int>,greater<int>> pq2;
int tmp;
int u,v,w,a,b,c,x;
int main(void){
	cin >>u >>v >>w >> a >> b >> c >> x;
	for(int i = 0; i < a; i++){
		cin >> tmp;
		pq[0].push(tmp);
	}
	for(int i = 0; i < b; i++){
		cin >> tmp;
		pq[1].push(tmp);
	}
	for(int i = 0; i < c; i++){
		cin >> tmp;
		pq[2].push(tmp);
	}
	for(int i = 0; i < x; i++){
		cin >> tmp;
		pq[3].push(tmp);
	}
	while(!pq[0].empty() && u > 0){
		pq2.push(pq[0].top());
		pq[0].pop();
		u--;
	}
	while(!pq[1].empty() && v > 0){
		pq2.push(pq[1].top());
		pq[1].pop();
		v--;
	}
	while(!pq[2].empty() && w > 0){
		pq2.push(pq[2].top());
		pq[2].pop();
		w--;
	}
	while(!pq[3].empty() || pq[3].top() < pq2.top()){
		pq2.pop();
		pq2.push(pq[3].top());
		pq[3].pop();
	}
	long long ret = 0;
	while(!pq2.empty()){
		ret += pq2.top();
		pq2.pop();
	}
	cout << ret;
		
	
}