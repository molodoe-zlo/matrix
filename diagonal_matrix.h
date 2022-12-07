#include <iostream>
#include <algorithm>
#include "matrix.h"

class diagonal_matrix : public matrix
{
private: int weight; int hight;
       int* elements;
public:
    diagonal_matrix(int col, int lines)
    {
        elements = new int[col];
        weight = col; hight = lines;
        for (int i = 0; i < col; i++)
        {
            elements[i] = getmatrix(i, i);
        };
    };

    diagonal_matrix(const diagonal_matrix& d)
    {
        int* array = new int[weight];
        weight = d.weight; hight = d.hight;
        for (int i = 0; i < weight; i++)
        {
            elements[i] = getmatrix(i, i);
        };
    };

    int& getmatrix(int x, int y)
    {
        if ((x > weight) || (y > hight))
        {
            std::cout << "error size" << std::endl;
        }
        else if (x = y) return (elements[x]);
        else {
            int r = 0;
            return (r);
        }
    };

    ~diagonal_matrix()
    {
        delete[] elements;
    }
};