#include <iostream>
using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void show(box p);
void work(box* p);
int main()
{
    struct box test = {
        "makeraaa",
        100,
        50,
        20,
    };
    work(&test);
    show(test);
    return 0;
}
void show(box p)
{
    cout << "maker: " << p.maker
        << "\nheight: " << p.height
        << "\nwidth: " << p.width
        << "\nlength: " << p.length
        << "\nvolume: " << p.volume;
}
void work(box* p)
{
    p->volume = p->height * p->width * p->length;
}