#include "Color.h"
#include <string>
#include <iostream>
#include <sstream>

Color::Color(){
	setId();
}
Color::Color(int red, int green, int blue, double alpha){
	setId();
	setRed(red);
	setGreen(green);
	setBlue(blue);
	setAlpha(alpha);
}
Color::~Color(){
}
void Color::setId(){
	id = idCount;
	++idCount;
}
void Color::setRed(int red){
	checkColor(red);
	this->red = red;
}
int Color::getRed() const{
	return red;
}
void Color::setGreen(int green){
	checkColor(green);
	this->green = green;
}
int Color::getGreen() const{
	return green;
}
void Color::setBlue(int blue){
	checkColor(blue);
	this->blue = blue;
}
int Color::getBlue() const{
	return blue;
}
void Color::setAlpha(double alpha){
	checkAlpha(alpha);
	this->alpha = alpha;
}
double Color::getAlpha() const{
	return alpha;
}
std::string Color::to_string() const{
	std::stringstream ss;
	ss << "ID: " << id << "; ";
	ss << " Red: " << red << "; ";
	ss << " Green: " << green << "; ";
	ss << " Blue: " << blue << "; ";
	ss << " Alpha: " << alpha << "; ";
	return ss.str();
}
void Color::checkColor(int color){
	if(color < 0 || color > 255){
		throw std::invalid_argument("Invalid color value.");
	}
}
void Color::checkAlpha(double alpha){
	if(alpha < 0 || alpha > 1.0){
		throw std::invalid_argument("Invalid alpha value.");
	}
}

// operators
bool Color::operator==(const Color &c) const {
    if(red == c.getRed() && green == c.getGreen() && blue == c.getBlue() && alpha == c.getAlpha()) {
        return true;
    } 
	else {
        return false;
    }
}
bool Color::operator!=(const Color &c) const {
    if(red == c.getRed() && green == c.getGreen() && blue == c.getBlue() && alpha == c.getAlpha()) {
        return false;
    }
	else {
        return true;
    }
}
bool Color::operator<(const Color &c) const {
    if(red < c.getRed() && green < c.getGreen() && blue < c.getBlue() && alpha < c.getAlpha()) {
        return true;
    }
	else {
        return false;
    }
}
bool Color::operator<=(const Color &c) const {
    if(red <= c.getRed() && green <= c.getGreen() && blue <= c.getBlue() && alpha <= c.getAlpha()) {
        return true;
    }
	else {
        return false;
    }
}
bool Color::operator>(const Color &c) const {
    if(red > c.getRed() && green > c.getGreen() && blue > c.getBlue() && alpha > c.getAlpha()) {
        return true;
    }
	else {
        return false;
    }
}
bool Color::operator>=(const Color &c) const {
    if(red >= c.getRed() && green >= c.getGreen() && blue >= c.getBlue() && alpha >= c.getAlpha()) {
        return true;
    }
	else {
        return false;
    }
}
Color& Color::operator++(){
	if(this->blue + 1 != 255){
		++this->blue;
		return *this;
	}
	else if(this->green + 1 != 255){
		++this->green;
		return *this;
	}
	else if(this->red + 1 != 255){
		++this->red;
		return *this;
	}
	else{
		this->red = 0;
		this->green = 0;
		this->blue = 0;
		return *this;
	}
}
Color& Color::operator--(){
	if(this->blue - 1 != 0){
		--this->red;
		return *this;
	}
	else if(this->green - 1 != 0){
		--this->green;
		return *this;
	}
	else if(this->blue - 1 != 0){
		--this->red;
		return *this;
	}
	else{
		this->red = 255;
		this->green = 255;
		this->blue = 255;
		return *this;
	}
}
Color& Color::operator++(int){
	if(this->blue + 1 != 255){
		this->blue++;
		return *this;
	}
	else if(this->green + 1 != 255){
		this->green++;
		return *this;
	}
	else if(this->red + 1 != 255){
		this->red++;
		return *this;
	}
	else{
		this->red = 0;
		this->green = 0;
		this->blue = 0;
		return *this;
	}
}
Color& Color::operator--(int){
	if(this->blue - 1 != 0){
		this->red--;
		return *this;
	}
	else if(this->green - 1 != 0){
		this->green--;
		return *this;
	}
	else if(this->blue - 1 != 0){
		this->red--;
		return *this;
	}
	else{
		this->red = 255;
		this->green = 255;
		this->blue = 255;
		return *this;
	}
}
std::ostream& operator<<(std::ostream &os, const Color &c){
	os << c.to_string();
	return os;
}
std::istream& operator>>(std::istream &is, Color &c){
	Color temp;
	is >> temp.red >> temp.green >> temp.blue >> temp.alpha;
	
	Color check;
	check.setRed(temp.red);
	check.setGreen(temp.green);
	check.setBlue(temp.blue);
	check.setAlpha(temp.alpha);
	
	c = check;
	return is;
}