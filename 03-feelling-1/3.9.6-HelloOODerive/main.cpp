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

    //��ͨ�ˣ�����һ�������Ա����
    void Sing()
    {
        std::cout << "@ # $ % ^ &" << std::endl;
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
    Person xiaoA;
    xiaoA.name = "Xiao A";

    Beauty* zhiLing = new Beauty; //�ǵģ�־������ǴӴ˲���һ���ࡱ
    zhiLing->name = "־��";

    //�¼�һ����Ů������ջ����
    Beauty jiaLing;
    jiaLing.name = "����";

    xiaoA.Introduction();
    zhiLing->Introduction();
    jiaLing.Introduction();

    delete zhiLing;

    Beauty power;
    power.Sing(); //��Ů�ӻ��ࣨ���ࣩ�̳еĹ���

    return 0;
}
