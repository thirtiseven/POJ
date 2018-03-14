#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

const int maxn = 666;

int main(int argc, char *argv[]) {  
	int w, l;
	std::cin >> w >> l;
	std::string s, dict[maxn];
	std::cin >> s;
	for (int i = 0; i < w; i++) {
		std::cin >> dict[i];
	}
	int dp[321];
	memset(dp, 0, sizeof(dp));
	for (int i = s.length()-1; i >= 0; i--) {
		bool yes = 0;
		dp[i] = 100000000;
		for (int j = 0; j < w; j++) {
			if (dict[j][0] == s[i] && dict[j].length() <= s.length() - i) {
				int cnt = i;
				for (int m = 0; m < dict[j].length(); m++) {
					while (s[cnt] != dict[j][m]) {
						cnt++;
						if (cnt >= s.length()) {
							goto http;
						}
					}
					if (s[cnt] == dict[j][m]) {
						cnt++;
					}
					if (m == dict[j].length()-1) {
						yes = 1;
						dp[i] = std::min(std::min(dp[i+1]+1, dp[i]), dp[cnt] + (cnt - i - (int)dict[j].length()));
						break;
					}
				}
			}
			http://www.thirtiseven.com
			;
		}
		if (!yes) {
			dp[i] = dp[i+1]+1;
		}
	}
	std::cout << dp[0];
}