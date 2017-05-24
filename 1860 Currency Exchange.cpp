#include <iostream>

#define maxn 410
#define inf 0x3f3f3f3f

struct edge{
	int u, v;
	double rate, com;
}side[maxn];

double dis[maxn];

int edge_num, node_num, source;
double value;

void init() {
	for(int i = 1; i <= edge_num; i++) { 
		dis[i] = 0;
	}  
	dis[source] = value;
}

int bellman_ford() {
	init();
	for(int i = 0; i < edge_num; i++) {  
		for(int j = 1; j <= 2 * node_num; j++) {  
			if(dis[side[j].v] < (dis[side[j].u] - side[j].com) * side[j].rate){  
				dis[side[j].v] = (dis[side[j].u] - side[j].com) * side[j].rate;  
			}  
		}  
	}  
	for(int j = 1; j <= 2 * node_num; j++) {  
		if(dis[side[j].v] < (dis[side[j].u] - side[j].com) * side[j].rate){  
			return 1;  
		}  
	}  
	return 0;  
} 

int main(int argc, char *argv[]) {  
	//std::ios::sync_with_stdio(false);
	std::cin >> edge_num >> node_num >> source >> value;
	for(int i = 1; i <= 2 * node_num; i += 2) {
		//std::cout << "BIU!\n";
		std::cin >> side[i].u >> side[i].v >> side[i].rate >> side[i].com >> side[i+1].rate >> side[i+1].com;
		side[i+1].u = side[i].v;
		side[i+1].v = side[i].u;
	}
	if(bellman_ford()) {
		std::cout << "YES\n";  
	} else { 
		std::cout << "NO\n"; 
	}
	return 0;
}