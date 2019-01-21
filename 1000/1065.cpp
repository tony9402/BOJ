#include<cstdio>

int checking(int n) {
	int in[4] = { 0 }, len = 0, dis = 10, chk;
	if (n / 10 == 0)return 1;
	for (int i = 0; n; i++) {
		in[i] = n % 10;
		n /= 10;
		len++;
	}
	for (int i = 1; i < len; i++) {
		dis = in[i] - in[i - 1];
		if (i != 1 && dis != chk) {
			return 0;
		}
		chk = dis;
	}
	return 1;
}

int main() {
	int n, count = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (checking(i) == 1) {
			count++;
		}
	}
	printf("%d", count);
}