#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person()
    {
        cout << "Wa~Wa~" << endl;
    }

    ~Person()
    {
        cout << "Wu~Wu~" << endl;
    }

    void Introduction()
    {
        cout << "Hi, my name is " << name << "." << endl;
    }

    std::string name;
};

struct Beauty : public Person
{
    void Introduction()
    {
        cout << "��Һã�������Ů: " << name << "��������գ�" << endl;
    }
};

int main()
{
    Person* xiaoA = new Beauty; //СA��Ϊ Person����ʵΪ Beauty
    xiaoA->name = "Xiao A";

    xiaoA->Introduction();
    delete xiaoA;

    Beauty* zhiLing = new Beauty; //־����ʵһ�£�ȫ��Beauty
    zhiLing->name = "־��";

    zhiLing->Introduction();
    delete zhiLing;

    return 0;
}
