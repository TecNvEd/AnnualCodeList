#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		static const int N = 2e3 + 5;
		int f[N][2];
		int res;
		int ans;
		int findNumberOfLIS(vector<int> &nums) {
			int n = nums.size();
			for (int i = 0; i < n; i++) {
				f[i][0] = 1;
				f[i][1] = 1;
				int localmax = f[i][0] = 1;
				int sum = f[i][1] = 1;
				for (int j = 0; j < i; j++) {
					if (nums[i] > nums[j]) {
						if (f[j][0] + 1 > localmax) {
							localmax = f[j][0] + 1;
							sum = f[j][1];
						} else if (f[j][0] + 1 == localmax) {
							sum += f[j][1];
						}
					}
				}
				f[i][0] = localmax;
				f[i][1] = sum;

			}
			for (int i = 0; i < n; i++) {
				if (f[i][0] > res) {
					res = f[i][0];
					ans = i;
				}
			}
			if (res == 1)
				return n;
			else
				return f[ans][1];


		}
};

int main(void) {
	vector<int> nums = {1,3,2};
	Solution s;
	int res = s.findNumberOfLIS(nums);
	cout << res;

}