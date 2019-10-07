#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person()
    {
        cout << "Wa~Wa~" << endl;
    }

    virtual ~Person() //���������������ࣩ
    {
        cout << "Wu~Wu~" << endl;
    }

    virtual void Introduction()  //�����е��麯��
    {
        cout << "Hi, my name is " << name << "." << endl;
    }

    std::string name;
};

struct Beauty : public Person
{
    ~Beauty() override //�����������������ࣩ
    {
        cout << "wu~wu~��������ݡ��Ƴ�¶��������Ĳݣ������յĻ�����" << endl;
    }

    void Introduction() override //������������ȷָ���ú����ڻ����о����麯�� (C++11)
    {
        cout << "��Һã�������Ů: " << name << "��������գ�" << endl;
    }
};

int main()
{
    Person* xiaoA = new Beauty; //СA��Ϊ Person����ʵΪ Beauty
    xiaoA->name = "Xiao A";

    xiaoA->Introduction();  //���ڣ�СA���ڿ����������磬�ң�Ҳ������Ů������
    delete xiaoA;

    Beauty* zhiLing = new Beauty; //־����ʵһ�£�ȫ��Beauty
    zhiLing->name = "־��";

    zhiLing->Introduction();
    delete zhiLing;

    return 0;
}
