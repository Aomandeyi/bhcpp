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
    { //��һ��
        Object* o1 = new Object();
        { //Ƕ�׵ĵ�һ��
            delete o1; //OK
        } //Ƕ���������
    } //��һ�����

    return 0;
}
