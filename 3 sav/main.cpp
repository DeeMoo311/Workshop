#include "Color.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace rgba;

int Color::idCount = 0;

int main()
{
	srand(time(NULL));
	try{
		Color *c = new Color();
		c->setRed(134);
		c->setGreen(86);
		c->setBlue(64);
		std::cout << " " << c->getRed() << " " << c->getGreen() << " " << c->getBlue() << std::endl << std::endl;
		
		//List
		std::vector<Color> colors;
		for(int i = 0; i < 10; ++i){
			int red = rand() % 255;
			int green = rand() % 255;
			int blue = rand() % 255;
			double alpha = 1.0;
			colors.push_back(Color(red, green, blue, alpha));
			std::cout << colors[i].to_string() << std::endl;
		}
		
		
		//Test that throws exception
		Color c2(42, 80085, 68, 1);
		std::cout << c2.to_string() << std::endl;
		
	} catch(std::invalid_argument ex){
		std::cout << ex.what() << std::endl;
	} catch(...){
		std::cout << "Unknown exception." << std::endl;
	}
	return 0;
}