#include <iostream>
#include <algorithm>
#include "matrix.h"

class one_matrix : public matrix
{
private: int weight; int hight;
public:
	one_matrix(int col, int lines)
	{
		if (col != lines)
		{
			std::cout << "error size" << std::endl;
		}
		else weight = col; hight = lines;
	};

	int& getmatrix(int x, int y)
	{
		if ((x > weight) || (y > hight))
		{
			std::cout << "error size" << std::endl;
		}
		else if (x = y) {
			int r = 1;
			return r;
		}
		else {
			int r = 0;
			return r;
		}
	};

	~one_matrix() {};
};