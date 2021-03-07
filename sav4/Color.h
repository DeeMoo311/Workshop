#ifndef COLOR_H
#define COLOR_H

#include <stdexcept>

class Color{
	public:
		static int idCount;
		
	private:
		int id;
		int red;
		int green;
		int blue;
		double alpha;
		
	public:
		Color();
		Color(int red, int green, int blue, double alpha);
		~Color();
		void setId();
		void setRed(int red);
		int getRed() const;
		void setGreen(int green);
		int getGreen() const;
		void setBlue(int blue);
		int getBlue() const;
		void setAlpha(double alpha);
		double getAlpha() const;
		std::string to_string() const;
		
	private:
		void checkColor(int color);
		void checkAlpha(double alpha);
			
	public:
		bool operator==(const Color &c) const;
		bool operator!=(const Color &c) const;
		bool operator<(const Color &c) const;
		bool operator<=(const Color &c) const;
		bool operator>(const Color &c) const;
		bool operator>=(const Color &c) const;
		 
		Color& operator++();
		Color& operator--();
		Color& operator++(int);
		Color& operator--(int);
		
		friend std::ostream& operator<<(std::ostream &os, const Color &c);
		friend std::istream& operator>>(std::istream &is, Color &c);
};
#endif