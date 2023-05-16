#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];

void quicksort(int *a, int l, int r) {
	if (l >= r)
		return ;
	int x = a[(l + r) >> 1];
	//int x= a[0];
	int i = l - 1, j = r + 1;
	while (i < j) {
		do
			i++;
		while (a[i] < x);
		do
			j--;
		while (a[j] > x);
		if (i < j)
			swap(a[i], a[j]);
	}
	//�����������������
	//���� {3,31,37}
	//quicksort(a,0,2)->quicksort(a,0,0);quicksort(a,1,2)
	//quicksort(a,1,2)->quicksort(a,1,0);quicksort(a,1,2)
	// ��Ϊ���i=lʱ��dowhile  ֹͣ��  i������l-1  +1������
	//a[i-1]ȷʵ<=x �����Ǿ�����һ�������������
	//��������� ѡȡ1~i-1 i~r�ͻ����޵ݹ�
	//��Ϊ i=l  quicksort(a,l,i-1) quicksort(a,i,r) �ұ�����ֽ�ȥ��
	//���Լ�ʹ�����ó���l~i-1 i~r �ֱ��������� ����ȡi-1 i�Ļ���mle


	//��ȡj j+1���Ῠס��ԭ���� sortquick(a,l,j);quicksort(a,j+1,r)
	//�ұߵ�quicksortֻ������ֵ������sort ��֤ÿ������ȡһ�����ֵ��ȥ

	//i-1 iʱ��һ������»�ѱ�֤����Сֵ����ȥ
	//����ֻ������ֵʱ������i-1 <l  ������ȥ��Сֵ�������� mle

	//l -  i-1  a[]<=x
	//i - r  a[]>=x

	//j+1 - r a[]>=x
	//l - j a[]<=x


	//������˵ ��������while��֤��a[l]~a[j]<=x
	//a[j+1]~a[r] >=x

	quicksort(a, l, j);
	quicksort(a,  j + 1, r);
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	quicksort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	fclose(stdin);
	fclose(stdout);
}