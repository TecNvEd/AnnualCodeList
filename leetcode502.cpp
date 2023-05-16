#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using PII = pair<int,int>;
    vector<PII> vecP;
    priority_queue<int> pq;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        for(int i=0;i<n;i++){
            vecP.push_back({capital[i],profits[i]});
        }
        sort(vecP.begin(),vecP.end());
        int index=0;
        while(k--){
            while(vecP[index].first<=w&&index<n){
                pq.push(vecP[index].second);
                index++;
            }
            if(!pq.empty())
            {w+=pq.top();
            pq.pop();}
        }
        return w;
    }
};

int main(void) {
	Solution s;
	vector<int>profits = {1, 2, 3};
	vector<int>capital = {0, 1, 1};
	int ans = s.findMaximizedCapital(2, 0, profits, capital);
	printf("%d", ans);
}