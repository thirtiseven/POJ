#include <iostream>
#include <algorithm>

const int maxn = 1234;

double arr[maxn];
int n, dpi[maxn], dpd[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		dpi[i] = 1;
		dpd[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dpi[i] = std::max(dpi[i], dpi[j]+1);
			}
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			if (arr[i] > arr[j]) {
				dpd[i] = std::max(dpd[i], dpd[j]+1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		dpi[i] = std::max(dpi[i], dpi[i-1]);
	}
	for (int i = n; i >= 1; i--) {
		dpd[i] = std::max(dpd[i], dpd[i+1]);
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans = std::max(ans, dpi[i]+dpd[i+1]);
	}
	std::cout << n-ans;
}