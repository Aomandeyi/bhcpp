#include <iostream>

using namespace std;

struct Object
{
    Object()
    {
        std::cout << "Hello world!" << endl;
    }

    ~Object()
    {
        std::cout << "Bye-bye world!" << endl;
    }
};

int main()
{
    Object* o1 = new Object();
    delete o1;

    Object o2;
    //delete o2; ���벻ͨ��

    return 0;
}
