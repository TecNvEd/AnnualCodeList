#include <iostream>

bool isPrime(int x) {
	printf("isPrime %d\n", x);
	if (x <= 1)
		return false;
	bool flag = true;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) {
			flag = false;
			break;
		}
	return flag;

}
int N, i;
bool isP[6];

int main(void) {
	scanf("%d", &N);
	if (isPrime(N) && isPrime(N - 6))
		printf("Yes\n%d\n", N - 6);
	else if (isPrime(N) && isPrime(N + 6))
		printf("Yes\n%d\n", N + 6);
	else {
		for (int j = 0; j <= 5 ; j++)
			isP[j] = isPrime(N - 5 + j);
		while (true) {
			if (isP[i % 6] && isPrime(N + 1 + i)) {
				printf("No\n%d", N + 1 + i );
				break;
			} else {
				isP[i % 6] = isPrime(N + 1 + i);

				printf("isP[%d] = %d\n", i % 6, isP[i % 6]);
				i++;
				//printf("isP[%d] = %d",(i - 1)%6, isPrime(N + i));

			}
		}
	}

}