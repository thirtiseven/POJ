#include <iostream>
#include <cstring>

bool table[6][6] = {0};
int ans;
bool find = 0;

void output_table() {
	for(int i = 1; i < 5; i++) {
		std::cout << "\n";
		for(int j = 1; j < 5; j++) {
			std::cout << table[i][j];
		}
	}
}

void turn(int a, int b) {
	table[a][b] = !table[a][b];
	table[a-1][b] = !table[a-1][b];
	table[a][b-1] = !table[a][b-1];
	table[a+1][b] = !table[a+1][b];
	table[a][b+1] = !table[a][b+1];
}

bool is_sort() {
	for(int i = 1; i <= 4; i++) {
		for(int j = 1; j <= 4; j++) {
			if(table[i][j] != table[1][1]) {
				return 0;
			}
		}
	}
	return 1;
}

void dfs(int a, int b, int depth) {
	if(depth == ans){
		find = is_sort();
		return;
	}
	if(a == 5 || find) {
		return;
	}	
	turn(a, b);
	if(b < 4) {
		dfs(a, b+1, depth + 1);
	} else {
		dfs(a+1, 1, depth + 1);
	}
	turn(a, b);
	if(b < 4) {
		dfs(a, b+1, depth);
	} else {
		dfs(a+1, 1, depth);
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false); 
	memset(table, 0, sizeof(table));
	char temp[10];
	for(int i = 0; i < 4; i++) {
		std::cin >> temp;
		for(int j = 0; j < 4; j++) {
			if(temp[j] == 'b') {
				table[i+1][j+1] = 0;
			} else if(temp[j] == 'w') {
				table[i+1][j+1] = 1;
			} else {
				continue;
			}
		}
	}
	for(ans = 0; ans <= 16; ans++){
		dfs(1, 1, 0);
		if(find) {
			std::cout << ans << std::endl;
			return 0;
		}
	}
	//output_table();
	std::cout << "Impossible" << std::endl;
	return 0;
}