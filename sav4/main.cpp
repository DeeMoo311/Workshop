#include "Color.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int Color::idCount = 0;

int main()
{
	srand(time(NULL));
	std::vector<Color> colors;
	try{		
	
		Color c;
		std::cin >> c;
		std::cout << c << std::endl;
		
		Color c1;
		std::cin >> c1;
		std::cout << c1 << std::endl;
		
		
		if(c == c1){
			std::cout << "These colors are the same!" << std::endl;
		}
		else{
			std::cout << "These colors are different!" << std::endl;
		}
	} 
	catch(std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
	} 
	catch(...){
		std::cout << "Unknown exception." << std::endl;
	}
	return 0;
}