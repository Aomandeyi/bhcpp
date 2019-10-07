#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person()
    {
        cout << "Wa~Wa~" << endl;
    }

    virtual ~Person()
    {
        cout << "Wu~Wu~" << endl;
    }

    virtual void Introduction()
    {
        cout << "Hi, my name is " << name << "." << endl;
    }

    std::string name;
};

struct Beauty : public Person
{
    ~Beauty() override
    {
        cout << "wu~wu~��������ݡ��Ƴ�¶��������Ĳݣ������յĻ�����" << endl;
    }

    void Introduction() override
    {
        cout << "��Һã�������Ů: " << name << "��������գ�" << endl;
    }
};

int main()
{
    while(true)
    {
        Person *someone;

        cout << "��ѡ��(1/2/3)��" << endl
            << "1----��ͨ��" << endl
            << "2----����" << endl
            << "3----�˳�" << endl;

        int sel = 0;
        cin >> sel;

        if (cin.fail())
        {
            cin.clear();
        }

        cin.sync();

        if (3 == sel)
        {
            break;
        }

        if (1 == sel)
        {
            someone = new Person;
        }
        else if (2 == sel)
        {
            someone = new Beauty;
        }
        else //�û�����ģ������ǣ���Ҳ���ǣ���Ҳ���ǣ�...
        {
            cout << "��������ɣ�������ѡ��" << endl;
            continue;
        }

        cout << "������������";

        string name;
        getline(cin, name);

        someone->name = name;

        cout << name << "�����ҽ��ܣ�" << endl;
        someone->Introduction();

        delete someone;
    }

    return 0;
}
