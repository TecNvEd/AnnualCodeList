#include <iostream>

#include <algorithm>

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Brute force enumeration of vector to find the -x and use max() to get the max
// Time Complexity O(n^2);
// Space Complexity O(1);
class Solution2441_1
{
public:
    int findMaxK(vector<int> &nums)
    {
        int k = -1;
        for (auto &x : nums)
        {
            if (x > 0 && std::find(nums.begin(), nums.end(), -x) != nums.end())
                k = max(x, k);
        }
        return k;
    }
};
// use hash to store the vector to fast locate the negative x
// Time Complexity O(n)
// Space Complexity O(n);
class Solution2441_2
{
public:
    int findMaxK(vector<int> &nums)
    {
        unordered_set<int> s = unordered_set<int>(nums.begin(), nums.end());
        int k = -1;
        for (auto &i : nums)
        {
            if (i > 0 && s.count(-i))
                k = max(k, i);
        }
        return k;
    }
};

// Sort the vector
// Use two pointers to find the biggest number and it's opposite appear in the vector
// Time Complexity O(nlogn)
// Space Complexity O(1)
class Solution2441_3
{
public:
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0, j = nums.size() - 1; j > 0; j--)
        {
            while (i < j && nums[i] < -nums[j])
                i++;
            if (nums[i] == -nums[j])
                return nums[j];
        }
        return -1;
    }
};
class Solution1054_1
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        unordered_map<int, int> count;
        for (int b : barcodes)
        {
            count[b]++;
        }
        priority_queue<pair<int, int>> pq;
        for (const auto &[b, bCount] : count)
        {
            pq.push({bCount, b});
        }
        vector<int> res;
        while (pq.size())
        {
            auto [bCount, b] = pq.top();
            pq.pop();
            if (res.empty() || res.back() != b)
            {
                res.push_back(b);
                --bCount;
            }
            else if (res.back() == b)
            {
                //若可能无答案 此处需要判断
                // if(pq.top() == )
                auto [nextCount, next] = pq.top();
                pq.pop();
                res.push_back(next);
                if (--nextCount > 0)
                    pq.push({nextCount, next});
            }
            if (bCount > 0)
                pq.push({bCount, b});
        }
        return res;
    }
};

class Solution1054_2
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        int length = barcodes.size();
        if (length < 2)
            return barcodes;

        unordered_map<int, int> count;
        for (int b : barcodes)
            ++count[b];
        int oddIndex = 0, evenIndex = 1, halfLength = length / 2;
        vector<int> res(length);
        for (auto &[b, bCount] : count)
        {
            while (bCount > 0 && bCount <= halfLength && evenIndex < length)
            {
                res[evenIndex] = b;
                bCount--;
                evenIndex += 2;
            }
            while (bCount > 0)
            {
                res[oddIndex] = b;
                bCount--;
                oddIndex += 2;
            }
        }
        return res;
    }
};
class Solution767_1
{
public:
    string reorganizeString(string s)
    {
        // try for the heap solution
        unordered_map<char, int> count;
        string res = "";
        for (auto &c : s)
            count[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto &[c, cCount] : count)
            pq.push({cCount, c});
        while (pq.size())
        {
            auto [cCount, c] = pq.top();
            pq.pop();
            if (res == "" || res.back() != c)
            {
                res.push_back(c);
                cCount--;
            }
            else if (res.back() == c)
            {
                if (pq.empty())
                    return "";
                auto [nextCount, next] = pq.top();
                pq.pop();
                res.push_back(next);
                if (--nextCount > 0)
                    pq.push([ nextCount, next]);
            }
            if (cCount > 0)
                pq.push([ cCount, c ]);
        }
        return res;
    }
};
class Solution1072_1
{
    //若两行亦或全为1或全为0说明同构
    //我们可以把全部行看成若干同构体组合而成的
    //
};

int main()
{
    vector<int> barCodes = {1, 1, 1, 2, 2, 2};
    Solution1054_2 s;
    
    auto v = s.rearrangeBarcodes(barCodes);
    for (auto i : v)
    {
        cout << i << "  ";
    }
    cout << endl;

}