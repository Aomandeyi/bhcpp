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
        if (name == "־��")
        {
            cout << "��Һã�����־�ᣬ������գ�" << endl;
        }
        else
        {
            cout << "Hi, my name is " << name << "." << endl;
        }
    }

    std::string name;
};

int main()
{
    Person xiaoA;
    xiaoA.name = "Xiao A";

    Person* zhiLing = new Person;
    zhiLing->name = "־��";

    xiaoA.Introduction();
    zhiLing->Introduction();

    delete zhiLing;

    return 0;
}
