#ifndef ARRAY_INPUT_H
#define ARRAY_INPUT_H

#define ERROR       -2147483647
#define OK          1
#define default_len 500

#include<iostream>
using namespace std;

class array_input
{
public:
    int n;
    int *A;
private:
    int len;
    int remake();
public:
    array_input();
    ~array_input();

    int clear();           //清除数组
    int add(const int);    //向数组中追加元素
};


#endif // ARRAY_INPUT_H
