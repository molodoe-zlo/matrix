#include <iostream>
#include <algorithm>

class matrix
{
private: int weight; int hight;
public:
    matrix() {}
    int** array;

    //������� �������
    matrix(int col, int lines)
    {
        weight = col; hight = lines;
        array = new int* [col];
        for (int i = 0; i < col; i++)
        {
            array[i] = new int[lines];
        }
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < lines; j++)
            {
                array[i][j] = 0;
            }
        };
    };

    //������� ������ �������� �� �������
    int& getmatrix(int x, int y)
    {
        return array[x][y];
    };

    //�������� �����������
    matrix(const matrix& m)
    {
        weight = m.weight;
        hight = m.hight;
        array = new int* [weight];
        for (int i = 0; i < weight; i++)
        {
            array[i] = new int[hight];
        };
        for (int i = 0; i < weight; i++)
        {
            for (int j = 0; j < hight; j++)
                array[i][j] = m.array[i][j];
        }
    };

    //�������� �����������
    matrix(matrix&& m) noexcept
    {
        weight = m.weight;
        hight = m.hight;
        array = new int* [weight];
        for (int i = 0; i < weight; i++)
        {
            array[i] = new int[hight];
        };
        for (int i = 0; i < weight; i++)
        {
            for (int j = 0; j < hight; j++)
                array[i][j] = m.array[i][j];
        }
    };

    // �������� ������������
    matrix* operator= (const matrix& m)
    {
        for (int i = 0; i < weight; i++)
            delete[] array[i];
        delete[] array;
        weight = m.weight;
        hight = m.hight;
        array = new int* [weight];
        for (int i = 0; i < weight; i++)
        {
            array[i] = new int[hight];
        };
        for (int i = 0; i < weight; i++)
        {
            for (int j = 0; j < hight; j++)
                array[i][j] = m.array[i][j];
        }
        return this;
    };

    // �������� �����
    matrix operator+ (matrix& b)
    {
        matrix answer(weight, hight);
        for (int i = 0; i < weight; i++)
        {
            for (int j = 0; j < hight; j++)
            {
                answer.getmatrix(i, j) = getmatrix(i, j) + b.getmatrix(i, j);
            }
        }
        return answer;
    };

    // �������� ������������
    matrix operator* (matrix& b)
    {
        matrix answer(weight, hight);
        for (int i = 0; i < weight; i++)
        {
            for (int j = 0; j < hight; j++)
            {
                int sum = 0;
                for (int g = 0; g < hight; g++)
                {
                    sum += (getmatrix(g, j) * b.getmatrix(i, g));
                }
                answer.getmatrix(i, j) = sum;
            }
        }
        return answer;
    };

    //������� �����
    void input()
    {
        for (int i = 0; i < weight; i++)
        {
            for (int j = 0; j < hight; j++)
            {
                std::cin >> array[i][j];
                getmatrix(i, j) = array[i][j];
            }
        }
    };

    //������� ������
    void print()
    {
        for (int i = 0; i < weight; i++)
        {
            for (int j = 0; j < hight; j++)
            {
                std::cout << getmatrix(i, j) << ", ";
            }
            std::cout << std::endl;
        }
    };

    //����������
    ~matrix()
    {
        for (int i = 0; i < weight; i++)
            delete[] array[i];
        delete[] array;
    }
}