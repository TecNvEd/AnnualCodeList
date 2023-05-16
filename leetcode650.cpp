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

					//�˴���j�����Ļ�����ʵi����һ��ָ����
					//������Ϊcopy�Ļ���
					//Ҳָ����paste�Ľ��� ��˲���
					//ȫ��������sqrt(i)֮��
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