#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        vector<long long> n;
        long long m = *max_element(nums.begin(),nums.end());
        auto bit = bitset<32>(m).to_string();
        bit = bit.substr(bit.find('1'));
        int len = bit.size();
        for(auto & i : nums){
            if(i >= (1 << (len - 1))|| i == m)
                n.emplace_back(i);
        }
        auto func = [&](long long i) -> long long{
            long long ret = i << k;
            for(auto &jj : n)
                if(jj != i)
                {
                    ret |= jj;
                }
            return ret;
            };
        long long max = 0;
        long long maxIndex = 0;
        long long maxNum = 0;
        
        for(int i = 0; i < n.size(); i++)
            if(func(n[i]) > max)
                { max = func(n[i]);maxIndex = i;maxNum = n[i];}
        long long ret = maxNum << k;
        for(auto & i : nums)
        {
            if(i != maxNum)
                ret |= i;
        }
        return ret;
        
        
    }
};
int main(void)
{
	vector<int> nums = {87,98,70,64,98};
	int k = 7;
	Solution s;
	s.maximumOr(nums,k);
	
}

