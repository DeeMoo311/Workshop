#ifndef COLOR_H
#define COLOR_H

#include <stdexcept>

namespace rgba{
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
			void setRed(int red);
			int getRed();
			void setGreen(int green);
			int getGreen();
			void setBlue(int blue);
			int getBlue();
			void setAlpha(double alpha);
			double getAlpha();
			std::string to_string();
		
		private:
			void checkColor(int color);
			void checkAlpha(double alpha);
	};
}
	
#endif