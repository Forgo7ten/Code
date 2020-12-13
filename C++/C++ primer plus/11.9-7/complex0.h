#ifndef _COMPLEX0_
#define _COMPLEX0_
#include <iostream>
using std::istream;
using std::ostream;
class complex {
    double real;
    double imagin;
public:
    complex(double x = 0, double y = 0);
    ~complex() {};
    void reset(double x, double y);
    complex operator+(const complex &m);   //对象相加
    complex operator-(const complex &m);   //对象相减
    complex operator*(const complex &m);   //对象相乘
    complex operator*(double n);    //对象与double相乘
    friend complex operator*(double n, complex & m);  //double与对象相乘
    complex operator~();    //求共轭
    friend ostream& operator<<(ostream& os, const complex& m);  //对输出<<的重载
    friend istream& operator>>(istream& is, complex& m);        //对输入>>的重载
};


#endif // !_COMPLEX0_