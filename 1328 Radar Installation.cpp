#include <iostream>
#include <algorithm>
#include <cmath>

struct extent {  
	double l, r;    
}line[1100];

bool cmp(extent a, extent b) {
	return a.r < b.r;
}

int main(int argc, char *argv[]) {  
	int n, d, cnt_case = 0, ok;
	while(std::cin >> n >> d) {
		ok = 1;
		if(n == 0 && d == 0) {
			break;
		}
		double x, y;
		for(int i = 0; i < n; i++) {
			std::cin >> x >> y;
			double temp = double(d * d) - y * y;
			if(temp < 0 || d < 0) {
				ok = 0;
			} else {
				line[i].l = x - sqrt(temp);
				line[i].r = x + sqrt(temp);
			}			
		}
		if(!ok) {
			cnt_case ++;
			std::cout << "Case " << cnt_case << ": -1"<< std::endl;
		} else {
			std::sort(line, line + n, cmp);
			int ans = 1;
			double temp = line[0].r;
			for(int i = 1; i < n; i++) {
				if(temp < line[i].l) {
					ans++;
					temp = line[i].r;
				}				
			}
			cnt_case ++;
			std::cout << "Case " << cnt_case << ": " << ans << std::endl;
		}		
	}
	return 0;
}