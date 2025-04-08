#include <cstring>
#include <iostream>
using namespace std;

class Solution {
	public:
		static const int N = 1e+3;
		int minSteps(int n) {
			int f[N];
			memset(f, 0x3f, sizeof f);
			f[1] = 0;
			for (int i = 2; i <= n; i++) {
				for (int j = 1; j * j <= i; j++) {

					//此处的j很有心机，其实i并不一定指的是
					//用来作为copy的基数
					//也指的是paste的阶数 因此才能
					//全部限制于sqrt(i)之中
					if (i % j == 0) {
						f[i] = min(f[i], f[j] + i / j);
						f[i] = min(f[i], f[i / j] + j);
					}
				}
			}
			return f[n];
		}
};

int main(void) {

	Solution s;
	int n = s.minSteps(1000);
	printf("%d", n);
}