#include <iostream>

class Move {
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0); //sets x, y to a, b
    void showmove() const;                 //shows current x, y values
    Move add(const Move& m) const;
    // this function adds x of m to x of invoking object to get new x,
    // adds y of m to y of invoking object to get new y, creates a new
    // move object. initialized to new x，y values and returns it.
    void reset(double a = 0, double b = 0); // resets x,y to a, b.
};

Move::Move(double a, double b)
{
    x = a;
    y = b;
}
void Move::showmove() const
{
    std::cout << "x = " << x << "  y = " << y << std::endl;
}
Move Move::add(const Move& m) const
{
    Move newa;
    newa.x = m.x + this->x;
    newa.y = m.y + this->y;
    return newa;
}
void Move::reset(double a, double b)
{
    x = a;
    y = b;
}


int main()
{
    Move m;
    Move n(1, 1);
    m.showmove();
    n.showmove();
    m.reset(2, 2);
    m.showmove();
    Move aa = m.add(n);
    aa.showmove();
    return 0;
}