#include <iostream>

using namespace std;

struct ShaFaTie
{
    ShaFaTie()
    {
        cout << "����������ɳ����Ц����¥ͷ��" << std::endl;
    }

    ~ShaFaTie()
    {
        cout << "����һ¥��������" << std::endl;
    }
};

struct BanDengTie : public ShaFaTie
{
    BanDengTie()
    {
        cout << "\t" << "[�ظ�]������ʡ�һ¥����������Ц����¥��" << std::endl;
    }

    ~BanDengTie()
    {
        cout << "\t" << "���Ƕ�¥��������" << std::endl;
    }
};

struct DibanTie : public BanDengTie
{
    DibanTie()
    {
        cout << "\t\t" << "[�ظ�]��¥��ô����ϯ�ض�����͹�Բ�ͬ��" << std::endl;
    }

    ~DibanTie()
    {
        cout <<  "\t\t" << "������¥��������" << std::endl;
    }
};

int main()
{
    ShaFaTie l1;
    cout << "==============================" << std::endl;

    BanDengTie l2;
    cout << "==============================" << std::endl;

    DibanTie l3;
    cout << "==============================" << std::endl;

    return 0;
}
