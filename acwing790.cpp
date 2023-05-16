#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
double query;

bool check(double x) {
	if (eps > query - x * x * x)
		return true;
	else
		return false;
}

int main(void) {
	scanf("%lf", &query);
	double l = -100, r = 100;
	double mid = (l + r) / 2;
	while (eps < r - l) {
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%.6lf", l);
}