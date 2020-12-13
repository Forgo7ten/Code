#include <iostream>

struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    using namespace std;
    const int Size = 2;
    chaff* p = new chaff[Size];
    int i;
    strcpy(p[0].dross,"dross1");
    p[0].slag = 111;
    strcpy(p[1].dross,"dross2");
    p[1].slag = 222;
    for (i = 0; i < Size; i++)
        cout << "dross: " << p[i].dross << "\tslag: " << p[i].slag << endl;
    delete[] p;
    return 0;
}