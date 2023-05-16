#include <iostream>
#include <algorithm>
#include<vector>
#include<stack>


using namespace std;

class Solution1072_1
{
    // 寻找同分异构情况 找到其中一种数目最大的异构体
};
class Solution118_1 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0;j <= i; j++)
                if(j == 0 || j == i)res[i].push_back(1);
                else res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
        }
        return res;
    }
};
class Solution739_1{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        //pair [temperature, index];
        stack<pair<int,int>> st;
        for(int i = 0; i < temperatures.size(); i++)
        {
            if(st.empty() || temperatures[i] <= st.top().first)
                st.push({temperatures[i],i});
            else{
                while(!st.empty() && temperatures[i] > st.top().first)
                {
                    res[st.top().second] = i - st.top().second;
                    st.pop();
                }
            }
        }
        while(!st.empty()) 
        {
            res[st.top().second] = 0;
            st.pop();
        }
        return res;
    }
};
//官方题解 在很多细枝末节上对我的单调栈有优化
class Solution739_2{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }

};

//brute force solution
class Solution496_1{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++)
        {
            int j = 0;
            while(nums2[j] != nums1[i])j++;
            while(j + 1 < nums2.size() && nums2[j + 1] < nums1[i])j++;
            if(j + 1 != nums2.size() && nums2[j + 1] > nums1[i])
                res.push_back(nums2[j + 1]);
            else
                res.push_back(-1);  
             
        }
        return res;
    } 
}
//monotonic stack
//a pretty provoking and classic monotonic template problem
class Solution496_2{
    
};
int main(void)
{
    Solution118_1 s118_1;
    auto v = s118_1.generate(5);
    Solution739_1 s739_1;

    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    auto v2 = s739_1.dailyTemperatures(temperatures);

}