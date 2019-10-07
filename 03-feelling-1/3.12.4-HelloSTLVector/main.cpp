#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
public:
    Person()
    {
        cout << "������������";
        getline(cin, name);
        
        cout << "���������䣺";
        cin >> age;
    }
    
    virtual ~Person()
    {
    }
    
    string GetName() const
    {
        return name;
    }
    
    int GetAge() const
    {
        return age;
    }
    
private:
    string name;
    int age;
};

struct Beauty : public Person
{
public:
    Beauty ()
    {
        cout << "�����������";
        cin.sync();
        getline(cin, nationality);
        
        cout << "��������Χ���ݣ��ء������Σ��������Կո�������س�ȷ�ϣ�";
        cin >> bust >> waist >> hips;
        
        cout << "���������ҽ������ݣ�";
        cin.sync();
        getline(cin, introduction);
    }
    
    string GetNationality() const
    {
        return nationality;
    }

    int GetBust() const
    {
        return bust;
    }
    
    int GetWaist() const
    {
        return waist;
    }
    
    int GetHips() const
    {
        return hips;
    }
        
    void Introduction() const
    {
        cout << introduction << endl;
    }
    
private:
    std::string nationality; //����
    
    int bust;   //��Χ
    int waist;  //��Χ
    int hips;   //��Χ
    
    std::string introduction; //���ҽ�������
};

//��Ů������
struct BeautiesManager
{
public:
    void Input();  //�����µ���Ů
    void Find() const; //������������Ů
    
    void Count() const //��ʾ��ǰ��Ů����
    {
        cout << "��ǰ��Ů������" << beauties.size() << endl;
    }
    
    void Introduction() const; //������Ů�������ҽ���
    void Clear(); //��յ�ǰ������Ů
    
private:
    vector<Beauty> beauties;
};

void BeautiesManager::Input()
{
    Beauty b;    
    beauties.push_back(b);
}

void BeautiesManager::Find() const
{
    cout << "������Ҫ���ҵ���Ů������";
    string name;
    
    getline(cin, name);
    
    int found = 0;
    
    for (unsigned int i=0; i<beauties.size(); ++i)
    {
        if (beauties[i].GetName() == name)
        {
            ++found;
            
            cout << "�ҵ���������Ů��������: " << i << endl;
            
            cout << "������" << beauties[i].GetName() << endl
                << "���䣺" << beauties[i].GetAge() << endl
                << "������" << beauties[i].GetNationality() << endl
                << "��Χ��" << beauties[i].GetBust() << ", "
                    <<  beauties[i].GetWaist() << ", " << beauties[i].GetHips() << endl; 
        }
    }
    
    cout << "���ҵ���" << found << "λ��Ϊ��" << name << "����Ů��" << endl; 
}

void BeautiesManager::Introduction() const
{
    for (unsigned int i=0; i<beauties.size(); ++i)
    {
        cout << "���ڳ������ǣ�" << beauties[i].GetName() << endl;
        beauties[i].Introduction();
    }
}

void BeautiesManager::Clear()
{
    cout << "��ȷ��Ҫ���������Ů�����𣿸ò������ɻָ��� (y/n)��";
    
    char c;
    cin >> c;
    
    cin.sync();
    
    if (c == 'y')
    {
        beauties.clear();
        cout << "�����������" << endl;
    }
}

//��ʾ���˵�:
int ShowMenu()
{
    cout << "��ѡ��" << endl;
    cout << "1----��Ů��Ϣ¼��" << endl
        << "2----��Ů��Ϣ����" << endl
        << "3----�����Ů����" << endl
        << "4----��Ů�������ҽ���" << endl
        << "5----���ȫ����Ů����" << endl
        << endl
        << "6----���ڱ�����" << endl
        << "7----�˳�" << endl;
        
    int sel = 0;
    cin >> sel;
    cin.sync();
    
    return sel;
}

void About()
{
    cout <<  "���أأع�����Ů������Ϣ����ϵͳ Ver 1.0��" << endl
        << "���ߣ���С�� Copyright 2008~???" << endl;
}

int main()
{
    enum {sel_input = 1, sel_find, sel_count, sel_introduction, sel_clear, sel_about, sel_exit};
 
    cout << "XXX������Ů������ӭ����" << endl;
 
    BeautiesManager bm;
       
    while(true)
    {
        int sel = ShowMenu();
                
        if ( sel_input == sel)
        {
            bm.Input();
        }        
        else if (sel_find == sel)
        {
            bm.Find();
        }
        else if (sel_count == sel)
        {
            bm.Count();
        }
        else if (sel_introduction == sel)
        {
            bm.Introduction();
        }
        else if (sel_clear == sel)
        {
            bm.Clear();
        }
        else if (sel_about == sel)
        {
            About();
        }
        else if (sel_exit == sel)
        {
            break;
        }
        else //ʲôҲ����?
        {
            if (cin.fail ())
            {
                cin.clear(); //���cin��ǰ���ܴ��ڴ���״̬�������
                cin.sync();
            }
            
            cout << "ѡ����������ѡ��" << endl;
        }
    }
    
    return 0;
}
