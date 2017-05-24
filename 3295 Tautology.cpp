#include <iostream>
#include <stack>

std::stack<int> expr;
int p, q, r, s, t;
char expr_input[105]; 

bool solve() {
	int top = 0;
	int len = strlen(expr_input);
	for(int i = len - 1;i >= 0;i--) {
		switch (expr_input[i]) {
			case 'p': expr.push(p); break; 
			case 'q': expr.push(q); break; 
			case 'r': expr.push(r); break; 
			case 's': expr.push(s); break; 
			case 't': expr.push(t); break; 
			case 'K': 
				{
					int a = expr.top();  
					expr.pop();  
					int b = expr.top();  
					expr.pop();  
					expr.push(a&&b); 
					break; 
				}
			case 'A':
				{
					int a = expr.top();  
					expr.pop();  
					int b = expr.top();  
					expr.pop();  
					expr.push(a||b); 
					break; 
				}
			case 'N':
				{
					int a = expr.top();  
					expr.pop();    
					expr.push(!a); 
					break; 
				}
			case 'C':
				{
					int a = expr.top();  
					expr.pop();  
					int b = expr.top();  
					expr.pop();  
					expr.push((!a)||b); 
					break; 
				}
			case 'E':
				{
					int a = expr.top();  
					expr.pop();  
					int b = expr.top();  
					expr.pop();  
					expr.push(a==b); 
					break; 
				}
		}
	}
	return expr.top();
}

int main(int argc, char *argv[]) { 
	while(std::cin >> expr_input && expr_input[0] != '0') {
		int ok = 1;
		for(p=0; p<=1; p++) for(q=0; q<=1; q++) for(r=0; r<=1; r++) for(s=0; s<=1; s++) for(t=0; t<=1; t++) {
			if(!solve()) {
				ok = 0;
				goto out_of_siege;
			}
		}
		out_of_siege:
		if(ok) {
			std::cout << "tautology" << std::endl;
		} else {
			std::cout << "not" << std::endl;

		}
	}
	return 0;
}