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
	//下面这里是有问题的
	//例子 {3,31,37}
	//quicksort(a,0,2)->quicksort(a,0,0);quicksort(a,1,2)
	//quicksort(a,1,2)->quicksort(a,1,0);quicksort(a,1,2)
	// 因为如果i=l时候dowhile  停止了  i单纯是l-1  +1上来的
	//a[i-1]确实<=x 不过那就是另一个区间的事情了
	//这种情况下 选取1~i-1 i~r就会无限递归
	//因为 i=l  quicksort(a,l,i-1) quicksort(a,i,r) 右边这个又进去了
	//所以即使这样得出的l~i-1 i~r 分别两个区间 但是取i-1 i的话会mle


	//而取j j+1不会卡住的原因是 sortquick(a,l,j);quicksort(a,j+1,r)
	//右边的quicksort只会把最大值给单独sort 保证每次至少取一个最大值出去

	//i-1 i时，一般情况下会把保证把最小值卡出去
	//但是只有两个值时，由于i-1 <l  卡不出去最小值，卡死了 mle

	//l -  i-1  a[]<=x
	//i - r  a[]>=x

	//j+1 - r a[]>=x
	//l - j a[]<=x


	//本质来说 上面的这个while保证了a[l]~a[j]<=x
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