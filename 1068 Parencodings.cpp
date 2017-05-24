#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	while(n--) {
		int p[30];
		std::vector<int> par;
		std::vector<int> w;
		int len;
		std::cin >> len;
		for(int i = 0; i < len; i++) {
			std::cin >> p[i];
		}
		int k = 1;
		for(int i = 0; i < len; i++) {
			for(int j = k; j <= p[i]; j++) {
				par.push_back(0);
			}
			par.push_back(1);
			k = p[i] + 1;
		}
//		for(std::vector<int>::iterator iter=par.begin();iter!=par.end(); iter++) {
//			std::cout << *iter << " ";
//		}		
//		std::cout << "\n";
		
		int d = par.size();
		for (int i = d-1; i >= 0; i--) {
			if (par[i] == 1) {
				int ans=0;
				int cnt1=0, cnt2=0;
				for (int u = i; u>=0; u--) {
					if (par[u] == 1) {
						cnt2++;
						ans++;
					} else {
						cnt1++;
					}
					if (cnt1 == cnt2) { 
						break;
					}
				}
				w.push_back(ans);
			}
		}		
		for (int i=w.size()-1; i>=0; i--) {
			std::cout << w[i] << ((i==0)?'\n':' ');			
		}
		par.clear();
		//w.clear();
	}
	return 0;
}