#include <iostream>
#include <cstring>

const int maxw = 15009;
const int maxn = 23;

int c[maxn], g[maxn], dp[maxn][maxw];
int nc, ng;

int main(int argc, char *argv[]) {  
	std::cin >> nc >> ng;
	for (int i = 0; i < nc; i++) {
		std::cin >> c[i];
	}
	for (int i = 1; i <= ng; i++) {
		std::cin >> g[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[0][7500] = 1;
	for (int i = 1; i <= ng; i++) {
		for (int j = 0; j < nc; j++) {
			for (int k = 0; k <= 15000; k++) {
				dp[i][k] += dp[i-1][k-c[j]*g[i]];
//				if(dp[i][k+c[j]*g[i]]) std::cout << dp[i][k+c[j]*g[i]] << " ";
			}
		}
	}
	std::cout << dp[ng][7500] << std::endl;
}