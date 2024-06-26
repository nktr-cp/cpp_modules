#include "Point.h"

int main() {
	Point a(0.0f,0.0f);
	Point b(100.0f,0.0f);
	Point c(100.0f,100.0f);

	{
		Point p(0.5f,0.5f);

		std::cout << ((bsp(a,b,c,p)) ? "inside" : "outside") << std::endl;
	}

	{
		Point p(0.0f,0.0f);
		std::cout << ((bsp(a,b,c,p)) ? "inside" : "outside") << std::endl;
	}

	{
		Point p(1.5f,0.5f);
		std::cout << ((bsp(a,b,c,p)) ? "inside" : "outside") << std::endl;
	}

	{
		Point p(42.5f, 42.5f);
		std::cout << ((bsp(a,b,c,p)) ? "inside" : "outside") << std::endl;
	}

	{
		Point p(0.8f,0.2f);
		std::cout << ((bsp(a,b,c,p)) ? "inside" : "outside") << std::endl;
	}

	{
		Point p(0.2f,0.8f);
		std::cout << ((bsp(a,b,c,p)) ? "inside" : "outside") << std::endl;
	}

	{
		Point p(1.0f,1.5f);
		std::cout << ((bsp(a,b,c,p)) ? "inside" : "outside") << std::endl;
	}
}