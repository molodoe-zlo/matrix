#include <iostream>
#include <algorithm>
#include "matrix.h"
#include "diagonal_matrix.h"
#include "matrix_one.h";

int main()
{
    int m, n;
    std::cin >> m >> n;
    matrix a(m, n);
    matrix b(m, n);
    a.input();
    b.input();
    matrix c(m, n);
    c = (a * b);
    c.print();
    //a * b;
}
