#include <iostream>
#include <vector>

#include "matrix.h"
typedef bool (*test)(void);
typedef struct
{
    string str;
    test func;
} unit_test;


bool test_det_1()
{
    Matrix<int> matr = { { 1, 2, 6, 9 },
                         {4, 5, -1, 4},
                         {0, 6, 1, 3},
                         {-1, 0, 2, 0}}
    ;
    int a = matr.determinant();
    if (a != -227)
        return false;
    return true;
}
bool test_det_2()
{
    Matrix<int> matr = { { 1, 2, 6, 9 },
                         {4, 5, -1, 4},
                         {0, 6, 1, 3},
                         {0, 0, 0, 0}}
    ;
    int a = matr.determinant();
    if (a != 0)
        return false;
    return true;
}
bool test_det_3()
{
    Matrix<int> matr = { {1, 2},
                         {4, 5},
                         }
    ;
    int a = matr.determinant();
    if (a != -3)
        return false;
    return true;
}
bool test_det_4()
{
    Matrix<double> matr = {{2,  6, 5},
                           {-1, 9, 8},
                           {8,  0, 2}
    };
    int a = matr.determinant();
    if (a != 72)
        return false;
    return true;
}
bool test_transpose_1()
{
    Matrix<int> matr = { {1, 2, 3},
                         {4, 5, 6},
    }
    ;
    Matrix<int> check_matr = { {1, 4},
                               {2, 5},
                               {3, 6}
    }
    ;
    matr.transpose();
    MatrixIterator<int> iter = matr.begin();
    MatrixIterator<int> check_iter = check_matr.begin();
    for (; iter != matr.end(); ++iter, ++check_iter)
        if (*iter != *check_iter)
            return false;
    return true;
}
bool test_ajoint_1() {
    Matrix<int> matr = {{2,  6, 5},
                        {-1, 9, 8},
                        {8,  0, 2}
    };
    Matrix<int> check_matr = {{18,  -12, 3},
                              {66,  -36, -21},
                              {-72, 48,  24}
    };
    matr.adjoint();
    MatrixIterator<int> iter = matr.begin();
    MatrixIterator<int> check_iter = check_matr.begin();
    for (; iter != matr.end(); iter++, check_iter++)
    {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_ajoint_2() {
    Matrix<int> matr = {{1,  34, 101, 55},
                        {2, 6, 0, 9},
                        {81,  78, 21, 3},
                        {5, 8, 16, 1}
    };
    Matrix<int> check_matr = {{9558,	-53028,	7050,	-69588},
                              {-10665,	58812,	-5959,	75144},
                              {2034,	-12000,	626,	-5748},
                              {4986,	-13356,	2406,	-34632}
    };
    matr.adjoint();
    MatrixIterator<int> iter = matr.begin();
    MatrixIterator<int> check_iter = check_matr.begin();
    for (; iter != matr.end(); ++iter, ++check_iter)
    {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_inv_1() {
    Matrix<double> matr = {{2,  6, 5},
                        {-1, 9, 8},
                        {8,  0, 2}
    };
    Matrix<double> matr_copy = {{2,  6, 5},
                           {-1, 9, 8},
                           {8,  0, 2}
    };
    Matrix<double> check_matr = {{1, 0,	0},
                                 {0, 1, 0},
                                 {0, 0, 1}
    };
    matr.inverse();
    matr *= matr_copy;
    MatrixIterator<double> iter = matr.begin();
    MatrixIterator<double> check_iter = check_matr.begin();
    for (; iter != matr.end(); iter++, check_iter++)
    {
        if (abs(*iter - *check_iter) > 1e-5)
            return false;
    }
    return true;
}
bool test_inv_2() {
    Matrix<double> matr = {{1,  34, 101, 55},
                        {2, 6, 0, 9},
                        {81,  78, 21, 3},
                        {5, 8, 16, 1}
    };
    Matrix<double> matr_copy = {{1,  34, 101, 55},
                           {2, 6, 0, 9},
                           {81, 78, 21, 3},
                           {5, 8, 16, 1}
    };
    Matrix<double> check_matr = {{1, 0,	0, 0},
                                {0,	1, 0, 0},
                                {0,	0, 1, 0},
                                {0,	0, 0, 1}
    };

    matr.inverse();
    matr *= matr_copy;
    MatrixIterator<double> iter = matr.begin();
    MatrixIterator<double> check_iter = check_matr.begin();
    for (; iter != matr.end(); ++iter, ++check_iter)
    {
        if (abs(*iter - *check_iter) > 1e-5)
            return false;
    }
    return true;
}
bool test_sum_1()
{
    Matrix<int> matr_1 = {{2,  6, 5},
                           {-1, 9, 8},
                           {8,  0, 2}
    };
    Matrix<int> matr_2 = {{1,  1, 5},
                             {2, 3, 1},
                             {4,  5, 1}
    };
    Matrix<int> res_check = {{3,  7, 10},
                             {1, 12, 9},
                             {12,  5, 3}
    };
    Matrix<int> res = matr_1 + matr_2;

    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_sum_eq_1()
{
    Matrix<int> res = {{2,  6, 5},
                          {-1, 9, 8},
                          {8,  0, 2}
    };
    Matrix<int> matr = {{1,  1, 5},
                          {2, 3, 1},
                          {4,  5, 1}
    };
    Matrix<int> res_check = {{3,  7, 10},
                             {1, 12, 9},
                             {12,  5, 3}
    };
    res += matr;

    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_sub_1()
{
    Matrix<int> matr_1 = {{2,  6, 5},
                          {-1, 9, 8},
                          {8,  0, 2}
    };
    Matrix<int> matr_2 = {{1,  1, 5},
                          {2, 3, 1},
                          {4,  5, 1}
    };
    Matrix<int> res_check = {{1,  5, 0},
                             {-3, 6, 7},
                             {4,  -5, 1}
    };
    Matrix<int> res = matr_1 - matr_2;

    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_sub_eq_1()
{
    Matrix<int> res = {{2,  6, 5},
                       {-1, 9, 8},
                       {8,  0, 2}
    };
    Matrix<int> matr = {{1,  1, 5},
                        {2, 3, 1},
                        {4,  5, 1}
    };
    Matrix<int> res_check = {{1,  5, 0},
                             {-3, 6, 7},
                             {4,  -5, 1}
    };
    res -= matr;

    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_mul_1()
{
    Matrix<int> matr_1 = {{1, 2, 6, 7},
                          {3, 1, 2, 16},
                          {31, 7, 28, 1}
    };
    Matrix<int> matr_2 = {{8, 13},
                          {5, 6},
                          {3, 9},
                          {11, 5}
    };
    Matrix<int> res_check = {{113, 114},
                             {211, 143},
                             {378, 702}
    };
    Matrix<int> res = matr_1 * matr_2;

    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_mul_eq_1()
{
    Matrix<int> res = {{1, 2, 6, 7},
                          {3, 1, 2, 16},
                          {31, 7, 28, 1}
    };
    Matrix<int> matr = {{8, 13},
                          {5, 6},
                          {3, 9},
                          {11, 5}
    };
    Matrix<int> res_check = {{113, 114},
                             {211, 143},
                             {378, 702}
    };
    res *= matr;

    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_mul_elem_1()
{
    Matrix<int> matr_1 = {{1, 2, 6},
                          {3, 1, 2},
    };
    int el = 2;
    Matrix<int> res_check = {{2, 4, 12},
                             {6, 2, 4}
    };
    Matrix<int> res = matr_1 * el;

    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_mul_elem_eq_1()
{
    Matrix<int> res = {{1, 2, 6},
                          {3, 1, 2},
    };
    int el = 2;
    Matrix<int> res_check = {{2, 4, 12},
                             {6, 2, 4}
    };
    res *= el;

    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_div_1()
{
    Matrix<double> matr_1 = {{113, 114, 378},
                          {211, 143, 702}
    };
    Matrix<double> matr_2 = {{8, 13, 1},
                          {78, 6, 2},
                          {3, 10, 4}
    };
    Matrix<double> res = matr_1 / matr_2;
    res *= matr_2;
    MatrixIterator<double> iter = res.begin();
    MatrixIterator<double> check_iter = matr_1.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (abs(*iter - *check_iter) > 1e-6)
            return false;
    }
    return true;
}
bool test_div_eq_1()
{
    Matrix<double> res = {{113, 114, 378},
                             {211, 143, 702}
    };
    Matrix<double> res_check = {{113, 114, 378},
                          {211, 143, 702}
    };
    Matrix<double> matr = {{8, 13, 1},
                             {78, 6, 2},
                             {3, 10, 4}
    };
    res /= matr;

    res *= matr;

    MatrixIterator<double> iter = res.begin();
    MatrixIterator<double> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_div_elem_1()
{
    Matrix<int> matr_1 = {{2, 4, 12},
                          {6, 2, 4}
    };
    int el = 2;
    Matrix<int> res_check = {{1, 2, 6},
                             {3, 1, 2}
    };
    Matrix<int> res = matr_1 / el;

    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_div_elem_eq_1()
{
    Matrix<int> res = {{2, 4, 12},
                       {6, 2, 4}
    };
    int el = 2;
    Matrix<int> res_check = {{1, 2, 6},
                              {3, 1, 2}
    };
    res /= el;

    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_neg_1()
{
    Matrix<int> res = {{2, 4, -12},
                       {6, -2, 4}
    };
    Matrix<int> res_check = {{-2, -4, 12},
                             {-6, 2, -4}
    };
    res = -res;
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_eq_1()
{
    Matrix<int> res = {{2, 4, -12},
                       {6, -2, 4}
    };
    Matrix<int> res_check = {{2, 4, -12},
                             {6, -2, 4}
    };
    return res == res_check;
}
bool test_not_eq_1()
{
    Matrix<int> res = {{2, 4, -12},
                       {6, -2, 4}
    };
    Matrix<int> res_check = {{2, 5, -12},
                             {6, -2, 4}
    };
    return res != res_check;
}
bool test_not_eq_2()
{
    Matrix<int> res = {{2, 4, -12},
                       {6, -2, 4}
    };
    Matrix<int> res_check = {{2, 4, -12},
                             {6, -2, 4}
    };
    return !(res != res_check);
}
bool test_resize_1()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6}
    };
    Matrix<int> res_check = {{1, 2, 3, 1},
                             {4, 5, 6, 1},
                             {1, 1, 1, 1}
    };
    res.resize(res.get_rows() + 1, res.get_cols() + 1, 1);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_resize_2()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6}
    };
    Matrix<int> res_check = {{1, 2},
                             {4, 5},
                             {1, 1},
                             {1, 1}
    };
    res.resize(res.get_rows() + 2, res.get_cols() - 1, 1);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_resize_3()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6}
    };
    Matrix<int> res_check = {{1, 2, 3},
                             {4, 5, 6},
                             {1, 1, 1}
    };
    res.resize(res.get_rows() + 1, res.get_cols(), 1);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_insert_row_1()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6},
                       {2, 4, -12}
    };
    Matrix<int> res_check = {{1, 2, 3},
                             {4, 5, 6},
                             {2, 4, -12},
                             {1, 1, 1}
    };
    res.insert_row(3, 1);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_insert_row_2()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6},
                       {2, 4, -12}
    };
    Matrix<int> res_check = {{1, 1, 1},
                             {1, 2, 3},
                             {4, 5, 6},
                             {2, 4, -12}
    };
    res.insert_row(0, 1);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_insert_row_3()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6},
                       {2, 4, -12}
    };
    Matrix<int> res_check = {{1, 2, 3},
                             {1, 1, 1},
                             {4, 5, 6},
                             {2, 4, -12}
    };
    res.insert_row(1, 1);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_delete_row_1()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6},
                       {2, 4, -12},
                       {3, 4, 1}
    };
    Matrix<int> res_check = {{1, 2, 3},
                             {4, 5, 6},
                             {2, 4, -12},
    };
    res.delete_row(3);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_delete_row_2()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6},
                       {2, 4, -12},
                       {3, 4, 1}
    };
    Matrix<int> res_check = {{4, 5, 6},
                             {2, 4, -12},
                             {3, 4, 1}
    };
    res.delete_row(0);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_delete_row_3()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6},
                       {2, 4, -12},
                       {3, 4, 1}
    };
    Matrix<int> res_check = {{1, 2, 3},
                             {2, 4, -12},
                             {3, 4, 1}
    };
    res.delete_row(1);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}

bool test_insert_col_1()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6},
                       {2, 4, -12}
    };
    Matrix<int> res_check = {{1, 2, 3, 1},
                             {4, 5, 6, 1},
                             {2, 4, -12, 1},
    };
    res.insert_col(3, 1);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_insert_col_2()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6},
                       {2, 4, -12}
    };
    Matrix<int> res_check = {{1, 1, 2, 3},
                             {1, 4, 5, 6},
                             {1, 2, 4, -12}
    };
    res.insert_col(0, 1);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_insert_col_3()
{
    Matrix<int> res = {{1, 2, 3},
                       {4, 5, 6},
                       {2, 4, -12}
    };
    Matrix<int> res_check = {{1, 1, 2, 3},
                             {4, 1, 5, 6},
                             {2, 1, 4, -12}
    };
    res.insert_col(1, 1);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_delete_col_1()
{
    Matrix<int> res = {{1, 2, 3, 3},
                       {4, 5, 6, 4},
                       {2, 4, -12, 1}
    };
    Matrix<int> res_check = {{1, 2, 3},
                             {4, 5, 6},
                             {2, 4, -12}
    };
    res.delete_col(3);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_delete_col_2()
{
    Matrix<int> res = {{1, 2, 3, 3},
                       {4, 5, 6, 4},
                       {2, 4, -12, 1}
    };
    Matrix<int> res_check = {{2, 3, 3},
                             {5, 6, 4},
                             {4, -12, 1}
    };
    res.delete_col(0);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
bool test_delete_col_3()
{
    Matrix<int> res = {{1, 2, 3, 3},
                       {4, 5, 6, 4},
                       {2, 4, -12, 1}
    };
    Matrix<int> res_check = {{1, 3, 3},
                             {4, 6, 4},
                             {2, -12, 1}
    };
    res.delete_col(1);
    MatrixIterator<int> iter = res.begin();
    MatrixIterator<int> check_iter = res_check.begin();
    for (; iter != res.end(); ++iter, ++check_iter) {
        if (*iter != *check_iter)
            return false;
    }
    return true;
}
int main() {
    vector<unit_test> tests;
    unit_test unit;

    unit.str = "test_det_1"; unit.func = test_det_1;
    tests.push_back(unit);

    unit.str = "test_det_2"; unit.func = test_det_2;
    tests.push_back(unit);

    unit.str = "test_det_3"; unit.func = test_det_3;
    tests.push_back(unit);

    unit.str = "test_det_4"; unit.func = test_det_4;
    tests.push_back(unit);

    unit.str = "test_transpose_1"; unit.func = test_transpose_1;
    tests.push_back(unit);

    unit.str = "test_ajoint_1"; unit.func = test_ajoint_1;
    tests.push_back(unit);

    unit.str = "test_ajoint_2"; unit.func = test_ajoint_2;
    tests.push_back(unit);

    unit.str = "test_inv_1"; unit.func = test_inv_1;
    tests.push_back(unit);

    unit.str = "test_inv_2"; unit.func = test_inv_2;
    tests.push_back(unit);


    unit.str = "test_sum_1"; unit.func = test_sum_1;
    tests.push_back(unit);

    unit.str = "test_sum_eq_1"; unit.func = test_sum_eq_1;
    tests.push_back(unit);

    unit.str = "test_sub_1"; unit.func = test_sub_1;
    tests.push_back(unit);

    unit.str = "test_sub_eq_1"; unit.func = test_sub_eq_1;
    tests.push_back(unit);

    unit.str = "test_mul_1"; unit.func = test_mul_1;
    tests.push_back(unit);

    unit.str = "test_mul_eq_1"; unit.func = test_mul_eq_1;
    tests.push_back(unit);

    unit.str = "test_mul_elem_1"; unit.func = test_mul_elem_1;
    tests.push_back(unit);

    unit.str = "test_mul_eq_elem_1"; unit.func = test_mul_elem_eq_1;
    tests.push_back(unit);

    unit.str = "test_div_1"; unit.func = test_div_1;
    tests.push_back(unit);

    unit.str = "test_div_eq_1"; unit.func = test_div_eq_1;
    tests.push_back(unit);

    unit.str = "test_div_elem_1"; unit.func = test_div_elem_1;
    tests.push_back(unit);

    unit.str = "test_div_eq_elem_1"; unit.func = test_div_elem_eq_1;
    tests.push_back(unit);

    unit.str = "test_neg_1"; unit.func = test_neg_1;
    tests.push_back(unit);

    unit.str = "test_eq_1"; unit.func = test_eq_1;
    tests.push_back(unit);

    unit.str = "test_not_eq_1"; unit.func = test_not_eq_1;
    tests.push_back(unit);

    unit.str = "test_not_eq_2"; unit.func = test_not_eq_2;
    tests.push_back(unit);

    unit.str = "test_resize_1"; unit.func = test_resize_1;
    tests.push_back(unit);

    unit.str = "test_resize_2"; unit.func = test_resize_2;
    tests.push_back(unit);

    unit.str = "test_resize_3"; unit.func = test_resize_3;
    tests.push_back(unit);

    unit.str = "test_insert_row_1"; unit.func = test_insert_row_1;
    tests.push_back(unit);

    unit.str = "test_insert_row_2"; unit.func = test_insert_row_2;
    tests.push_back(unit);

    unit.str = "test_insert_row_3"; unit.func = test_insert_row_3;
    tests.push_back(unit);

    unit.str = "test_delete_row_1"; unit.func = test_delete_row_1;
    tests.push_back(unit);

    unit.str = "test_delete_row_2"; unit.func = test_delete_row_2;
    tests.push_back(unit);

    unit.str = "test_delete_row_3"; unit.func = test_delete_row_3;
    tests.push_back(unit);

    unit.str = "test_insert_col_1"; unit.func = test_insert_col_1;
    tests.push_back(unit);

    unit.str = "test_insert_col_2"; unit.func = test_insert_col_2;
    tests.push_back(unit);

    unit.str = "test_insert_col_3"; unit.func = test_insert_col_3;
    tests.push_back(unit);

    unit.str = "test_delete_col_1"; unit.func = test_delete_col_1;
    tests.push_back(unit);

    unit.str = "test_delete_col_2"; unit.func = test_delete_col_2;
    tests.push_back(unit);

    unit.str = "test_delete_col_3"; unit.func = test_delete_col_3;
    tests.push_back(unit);

    for (size_t i = 0; i < tests.size(); i++) {
        if (!tests[i].func())
        {
            cout << tests[i].str << " failed" << endl;
        }
        else
        {
            cout << tests[i].str << " passed" << endl;
        }
    }
    return 0;
}
