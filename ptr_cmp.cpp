#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int a = 5;
	int *p1 = &a;
	int *p2 = &a;
	printf("%d\n", p1 == p2);
	printf("p1 :%p \np2 : %p\n", p1, p2);
	printf("p1 address :%p \np2 address: %p\n", &p1, &p2);
	printf("a address :%p\n", &a);
	printf("%d %d\n", *p1, *p2);
}