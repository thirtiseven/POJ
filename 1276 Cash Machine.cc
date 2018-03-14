#include <iostream>
#include <algorithm>
#include <cstring>

const int maxn=100005;
int w[10],v[10];
int W,n;
int dp[maxn];

void ZOP(int weight) {
	for(int i = W; i >= weight; i--) {
		dp[i]=std::max(dp[i],dp[i-weight]+weight);
	}
}

void CP(int weight){
	for(int i = weight; i <= W; i++) {
		dp[i] = std::max(dp[i], dp[i-weight]+weight);
	}
}

void MP(int weight, int cnt){
	if(weight*cnt >= W) {
		 CP(weight);
	} else {
		for(int k = 1; k < cnt; k <<= 1) {
			ZOP(k*weight);
			cnt -= k;
		}
		ZOP(cnt*weight);
	}
}

int main(int argc, char *argv[]) {  
	int cash;
	while (std::cin >> W) {
		std::cin >> n;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			int a, b;
			std::cin >> a >> b;
			MP(b, a);
		}
		for (int i = W; i >= 0; i--) {
			if (dp[i] == i) {
				std::cout << i << '\n';
				break;
			}
		}
	}
}