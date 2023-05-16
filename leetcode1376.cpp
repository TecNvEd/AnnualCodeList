#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// class Solution {
// public:

//     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
//         //from the bottom to the top
//         vector<int> Time(n,0);
//         unordered_map<int,int> m;
//         int maxCount = 0;
//         function<int(int)> time = [&](int index)-> int 
//         {
//             int result = 0;
//             if(m.count(manager[index])) 
//                 result = m[manager[index]] + informTime[manager[index]];
//             else if(index == headID)
//                 m[headID] = 0;
//             else
//             {
//                 m[manager[index]] == time(manager[index]);
//                 result = time(manager[index]) + informTime[manager[index]];
//             }
//             m[index] = result;
//             return result;
//         };
//         for(int i = 0; i < n; i++)
//         {
//             Time[i]=time(i);
//             maxCount = max(maxCount,Time[i]);
//         }
//         return maxCount;

//     }
// };

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //bottom-up
        int countMax = 0;
        unordered_map<int,int> Time;
        function<int(int)> time = [&](int index)->int {
            if(index == headID) 
                Time[index] = 0;
            else{
                if(Time.count(manager[index])) 
                    Time[index] = Time[manager[index]] + informTime[manager[index]];
                else Time[index] = time(manager[index]) + informTime[manager[index]];
            }
            return Time[index];

        };
        for(int i = 0; i < n; i++)countMax = max(countMax,time(i));
        return countMax;

    }
};



int main(void)
{
    Solution s;
    vector<int> manager {-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6};
    cout << "This is the test for the vector's end  - vector's begin" << endl;
    cout << "for a vector length:" << manager.size() << " This Vector's end - begin -> " << manager.end() - manager.begin() << endl; 
    cout << "length is equal to the end - begin ?" << endl;
    bool outcome = manager.size() == (manager.end() - manager.begin());
    cout << boolalpha << outcome << endl;
    vector<int> informTime {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0}; 
    int n = 15; 
    int headID = 0;
    int ret = s.numOfMinutes(n,headID,manager,informTime);
    cout << ret << endl;

}
