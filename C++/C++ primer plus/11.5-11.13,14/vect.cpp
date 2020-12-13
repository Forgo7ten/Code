// vect.cpp  methods for the Vector class
#include <cmath>
#include "vect.h"   // includes <iostreams>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    // compute degrees in one radian
    const double Rad_to_deg = 45.0 / atan(1.0); //求出一弧度是多少度
    // should be about 57.2957795130823
//private methods
    // calculates magnitude from x and y
    void Vector::set_mag()  // 用x,y求出极径
    {
        mag = sqrt(x * x + y * y);
    }
    void Vector::set_ang()  // 求出极角
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }
    // set x from polar coordinate
    void Vector::set_x()  //根据极坐标设置x
    {
        x = mag * cos(ang);
    }
    // set y from polar coordinate
    void Vector::set_y()  //根据极坐标设置y
    {
        y = mag * sin(ang);
    }

    // public methods
    Vector::Vector()    // default const ructor  创建对象默认构造函数
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
    // construct vector from rectangular coordinates if form is r
    // (the default) or else from polar coordinates if form is p
    Vector::Vector(double n1, double n2, Mode form)     //创建对象构造函数
    {

        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2;    // Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    // reset vector from rectangular coordinates if form is
    // RECT (the default) or else from polar coordinates if
    //formisPOL
    void Vector::reset(double n1, double n2, Mode form)     //重新设置对象
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    Vector::~Vector()   // destructor      析构函数
    {

    }

    void Vector::polar_mode()   // set to polar mode    更改形式为极坐标系
    {
        mode = POL;
    }

    void Vector::rect_mode()    // set to rectangular mode  更改形式为xy
    {
        mode = RECT;
    }
    // operator overloading
    // add two Vectors
    Vector Vector::operator+ (const Vector& b) const    // 对象之间的加法
    {
        return Vector(x + b.x, y + b.y);
    }


    // subtract Vector b from a
    Vector Vector::operator- (const Vector& b) const    // 对象之间的减法
    {
        return Vector(x - b.x, y - b.y);
    }


    // reverse sign of Vector
    Vector Vector::operator- () const   //对象自己的负数
    {
        return Vector(-x, -y);
    }

    // multiply vector by n
    Vector Vector::operator* (double n) const   //对象*double
    {
        return Vector(n * x, n * y);
    }

    // friend methods
    // multiply n by Vector a
    Vector operator* (double n, const Vector& a)    //double*对象
    {
        return a * n;
    }

    // display rectangular coordinates if mode is RECT,
    // else display polar coordinates if mode is POL
    std::ostream& operator<<(std::ostream& os, const Vector& v)     //打印对象
    {
        if (v.mode == Vector::RECT)
            os << "(x,y) =(" << v.x << "，" << v.y << ")";
        else if (v.mode == Vector::POL)
        {
            os << "(m,a)=(" << v.mag << ","
                << v.ang * Rad_to_deg << ")";
        }
        else
            os << "Vector object mode is invalid";
        return os;
    }
} // end namespace VECTOR
