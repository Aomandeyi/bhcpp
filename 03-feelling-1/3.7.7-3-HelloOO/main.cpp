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
    Object* o1; //�ȶ���һ���ѱ���

    {
       o1 = new Object(); //��Ϊ����ʼ��
    }

    delete o1; //�ͷ��� ��o1��ʱ�ɼ���

    return 0;
}
