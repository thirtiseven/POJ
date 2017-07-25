#include <iostream>
#include <cstring>
#include <vector> 
#include <queue> 
#include <algorithm>
#include <cmath>

#define inf 1000000000 
#define maxn 110 

int m, n;
bool vis[maxn];

class dijkstra {
private:
	struct heapnode {
		int u;
		int d;
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
	int d[maxn];
	int val[maxn];
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
	
	void addedge(int u, int v, int w) {
		g[u].push_back(edge(v, w));
	}
	
	int run(int s) {
		int u;
		int min_cost = inf;	
		for(int i = 1; i <= n; i++) {  
			d[i] = inf;
		}	
		d[s] = 0;
		q.push(heapnode(s, 0));
		while (!q.empty()) {
			u = q.top().u;
			q.pop();
			if(!vis[u]) {
				vis[u] = 1;
				for (std::vector<edge>::iterator e = g[u].begin(); e != g[u].end(); e++) {
					if (d[e->v] > d[u] + e->w && !vis[e->v]) {
						d[e->v] = d[u] + e->w;
						q.push(heapnode(e->v, d[e->v]));
					}
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			d[i] += val[i];
			min_cost = std::min(min_cost,d[i]);
		}
		return min_cost;
	}
};

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	dijkstra bob;
	int level[maxn];
	int ans = inf;
	std::cin >> m >> n;
	bob.clear(n);
	for(int id = 1; id <= n; id++) {
		int substitute;
		std::cin >> bob.val[id] >> level[id] >> substitute;
		for(int i = 0; i < substitute; i++) {1
			int to, value;
			std::cin >> to >> value;
			bob.addedge(id, to, value);
		}
	}
	for(int i = 0; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(level[j] < level[1] - m + i || level[j] > level[1] + i) {
				vis[j] = 1;
			} else {
				vis[j] = 0;
			}
		}
		int dij = bob.run(1);
		ans = std::min(ans, dij);
	}
	std::cout << ans << std::endl;
	return 0; 
}