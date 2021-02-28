#include "Color.h"
#include <string>
#include <iostream>
#include <sstream>

rgba::Color::Color(){
	this->id = idCount;
	++idCount;
}
rgba::Color::Color(int red, int green, int blue, double alpha){
	checkColor(red);
	checkColor(green);
	checkColor(blue);
	checkAlpha(alpha);
	
	this->id = idCount;
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
	++idCount;
}
rgba::Color::~Color(){
}
void rgba::Color::setRed(int red){
	checkColor(red);
	this->red = red;
}
int rgba::Color::getRed(){
	return red;
}
void rgba::Color::setGreen(int green){
	checkColor(green);
	this->green = green;
}
int rgba::Color::getGreen(){
	return green;
}
void rgba::Color::setBlue(int blue){
	checkColor(blue);
	this->blue = blue;
}
int rgba::Color::getBlue(){
	return blue;
}
void rgba::Color::setAlpha(double alpha){
	checkAlpha(alpha);
	this->alpha = alpha;
}
double rgba::Color::getAlpha(){
	return alpha;
}
std::string rgba::Color::to_string(){
	std::stringstream ss;
	ss << "ID: " << id << std::endl;
	ss << "Red: " << red << std::endl;
	ss << "Green: " << green << std::endl;
	ss << "Blue: " << blue << std::endl;
	ss << "Alpha: " << alpha << std::endl;
	return ss.str();
}
void rgba::Color::checkColor(int color){
	if(color < 0 || color > 255){
		throw std::invalid_argument("Invalid color value.");
	}
}
void rgba::Color::checkAlpha(double alpha){
	if(alpha < 0 || alpha > 1.0){
		throw std::invalid_argument("Invalid alpha value.");
	}
}