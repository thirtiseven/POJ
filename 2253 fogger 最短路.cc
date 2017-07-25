#include <iostream>
#include <cstring>
#include <vector> 
#include <queue> 
#include <algorithm>
#include <cmath>
#include <iomanip>

#define inf 1000000000 
#define maxn 210

int n;

struct node {
	double x;
	double y;
}stone[maxn];

double way(int i, int j) {
	return sqrt(pow(stone[i].x - stone[j].x, 2) + pow(stone[i].x - stone[j].x, 2));
}

class dijkstra {
	private:
		struct heapnode {
			int u;
			double d;
			heapnode(int u, int d) :u(u), d(d) {}
			bool operator < (const heapnode &b) const {
				return d > b.d;
			}
		};
		
		struct edge {
			int v, w;
			edge(int v, int w) :v(v), w(w) { }
		};
		
		std::vector<edge> g[maxn];
		
	public:
		bool vis[maxn];
		double d[maxn];
		std::priority_queue<heapnode> q;
		void clear(int size) {
			for(int i = 0; i <= size; i++) {
				g[i].clear();
			}
			for(int i = 1; i <= size; i++) {
				d[i] = inf;
			}
			memset(vis, 0, sizeof(vis));
		}
		
		void addedge(int u, int v, double w) {
			g[u].push_back(edge(v, w));
		}
		
		double run(int s) {
			int u;
			double min_cost = inf;	
			for(int i = 1; i <= n; i++) {  
				d[i] = inf;
			}	
			d[s] = 0;
			q.push(heapnode(s, 0));
			int now = 0;
			while (!q.empty()) {
				u = q.top().u;
				q.pop();
				if(!vis[u]) {
					vis[u] = 1;
					for (std::vector<edge>::iterator e = g[u].begin(); e != g[u].end(); e++) {
						if (d[e->v] > d[u] + e->w) {
							d[e->v] = d[u] + e->w;
							q.push(heapnode(e->v, d[e->v]));
						} 
					}
				}
			}
			for(int i = 1; i <= n; i++) {
				min_cost = std::min(min_cost,d[i]);
			}
			return min_cost;
		}
	};

int main(int argc, char *argv[]) {  
	int t = 0;
	while(std::cin >> n) {
		if(n == 0) {
			break;
		}
		dijkstra dij;
		dij.clear(n * n);
		for(int i = 1; i <= n; i++) {
			std::cin >> stone[i].x >> stone[i].y;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				double temp_dis = way(i, j);
				dij.addedge(i, j, temp_dis);
				dij.addedge(j, i, temp_dis);
			}
		}
		double ans = dij.run(1);
		if(t) {
			std::cout << "\n";
		} 
		std::cout << "Scenario #" << t << "\nFrog Distance = " 
				  << std::fixed << std::setprecision(3) << ans 
				  << "\n";  
	}
	return 0;
}