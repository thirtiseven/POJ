#include <iostream>
#include <cstring>

bool table[6][6] = {0};
int ans;
bool find = 0;

struct solution{
	int row, col;
}N[20];

void output_table() {
	for(int i = 1; i < 5; i++) {
		std::cout << "\n";
		for(int j = 1; j < 5; j++) {
			std::cout << table[i][j];
		}
	}
}

void turn(int a, int b) {
	for(int i = 1; i < 5; i++) {
		table[i][b] = !table[i][b];
	}
	for(int i = 1; i < 5; i++) {
		table[a][i] = !table[a][i];
	}
	table[a][b] = !table[a][b];
}

bool is_open() {
	for(int i = 1; i <= 4; i++) {
		for(int j = 1; j <= 4; j++) {
			if(table[i][j] == 1) {
				return 0;
			}
		}
	}
	return 1;
}

void dfs(int a, int b, int depth) {
	if(depth == ans){
		find = is_open();
		if(find == 1) {
			std::cout << ans << std::endl;
			for(int i = 0; i < ans; i++) {
				std::cout << N[i].row << " " << N[i].col << std::endl;
			}
			return;
		}
		return;
	}
	if(a == 5 || find) {
		return;
	}	
	turn(a, b);
	N[depth].row = a;
	N[depth].col = b;
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
			if(temp[j] == '-') {
				table[i+1][j+1] = 0;
			} else if(temp[j] == '+') {
				table[i+1][j+1] = 1;
			} else {
				continue;
			}
		}
	}
	for(ans = 0; ans <= 16; ans++){
		dfs(1, 1, 0);
	}	
	return 0;
}