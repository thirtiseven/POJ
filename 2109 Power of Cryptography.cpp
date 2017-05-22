#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	double n, p;
	while(std::cin >> n >> p) {
		std::cout <<  pow(p, 1/n) << std::endl;
	}
	return 0;
}