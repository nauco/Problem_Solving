#include <cstdio>
int x[1000];
int y[1000];
int dist(int x1, int y1, int x2, int y2) {
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	int ans = -1;
	for (int i = 0; i<n - 1; i++) {
		for (int j = i + 1; j<n; j++) {
			int d = dist(x[i], y[i], x[j], y[j]);
			if (ans == -1 || ans > d) {
				ans = d;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}