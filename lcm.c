#include <stdio.h>

long long gcd(long long x, long long y)
{
    	if (x == 0) {
		return y;
	}
    	return gcd(y % x, x);
}

int main()
{
	int n;
	scanf("%d", &n);
	long long a[n], b[n], c[n];
	long long temp, temp2;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i], &c[i]);
	}
	for (int i = 0; i < n; i++) {
		if ((a[i] > c[i]) || (c[i] % a[i] != 0)) {
			b[i] = -1;
			continue;
		}
		temp = c[i] / a[i];
		temp2 = gcd(a[i], temp);
		while (temp2 != 1) {
			temp = temp2;
			a[i] /= temp;
			temp2 = gcd(a[i], temp);
		}
		b[i] = c[i] / a[i];
	}
	for (int i = 0; i < n; i++) {
		printf("%lld\n", b[i]);
	}
	return 0;
}
