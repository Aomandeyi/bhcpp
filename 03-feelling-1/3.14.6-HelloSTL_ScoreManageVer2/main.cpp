#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//ѧ��
struct Student
{
  unsigned int number; //ѧ��
  string name; //����
};

//�ɼ�
struct Score
{
   unsigned int number; //ѧ��
   float mark; //����
};


//ѧ���ɼ�������
struct StudentScoreManager
{
public:
    void InputStudents(); //¼��ѧ��������Ϣ��¼��ǰ�Զ����ԭ�����ݣ�
    void InputScores(); //¼��ɼ���¼��ǰ�����ԭ�����ݣ�
    void ClearScores(); //��ճɼ�����

    void OutputScoresByNumber() const; //��ѧ�Ŵ������ÿ��ѧ����Ϣ�������ɼ�
    void OutputScoresByMark() const; //�Է������������ÿ���ɼ�������ѧ��������Ϣ

    void FindStudentByNumber() const; //ͨ��ѧ�ţ�����ѧ������ʾ������ѧ�ţ��ɼ�
    void FindStudentByName() const; //ͨ������������ѧ������ʾ������ѧ�ţ��ɼ�

private:
    //�ڲ����õĺ���:
    //����һ��ѧ�ţ���scores�в��ң�����������
    void FindScoreByNumber(unsigned int number) const;

    vector<Student> students;
    list<Score> scores;
};

//����Ƿ������������У����������״̬�������ء��桱.
bool CheckInputFail()
{
    if (cin.fail ()) //��� cin�ǲ��ǳ����ˣ�
    {
        //������...
        cin.clear(); //���cin��ǰ���ܴ��ڴ���״̬
        cin.sync(); //�������ǰ����δ���������

        cout << "�������������´���" << endl;

        return true;
    }

    return false;
}

//����ѧ���ɼ�
void StudentScoreManager::InputStudents()
{
    //����Ƿ��Ѿ�������:
    if (students.empty() == false)
    {
        cout << "ȷ��Ҫ����¼��ѧ��������Ϣ��(y/n)";
        char c;
        cin >> c;

        if (c != 'y')
        {
            return;
        }

        cin.sync(); //�Ե��س���.
    }

    //��Ϊ�����û�����¼�룬����������Ҫ���ԭ������
    students.clear();

    unsigned int number = 1; //ѧ�Ŵ�1��ʼ

    while(true)
    {
        cout << "������ѧ������(����x��ʾ����), " << number << "�ţ�";

        string name;

        getline(cin, name);

        if (name == "x")
        {
            break;
        }

        Student student;
        student.number = number;
        student.name = name;

        students.push_back(student);

        ++number;
    }
}

//�Ƚ������Ƚ������Ƿ����
//������students�в���ָ��������ѧ��
struct CompareByName4Find
{
    bool operator () (Student student) const
    {
        return student.name == name;
    }

    //�����ҵ�����
    string name;
};

//�Ƚ������Ƚϳɼ��е�ѧ���Ƿ����
//������ scores�в���ָ��ѧ�ŵĳɼ�
struct CompareByNumber_Equal4Find
{
    bool operator () (Score s) const
    {
        return (s.number == number);
    }

    unsigned int number;
};

//�ڲ����õĺ���:
//����һ��ѧ�ţ���scores�в��ң�����������
void StudentScoreManager::FindScoreByNumber(unsigned int number) const
{
    CompareByNumber_Equal4Find cbne;
    cbne.number = number;

    list<Score>::const_iterator itScore = find_if(scores.begin(), scores.end(), cbne);

    if (itScore == scores.end())
    {
       //�Ҳ����ɼ���
       cout << "���ɼ������޳ɼ���";
    }
    else
    {
        //�鵽�ɼ��ˣ���ʾ��
        cout << "���ɼ���" << itScore->mark;
    }
}

//ͨ��ѧ�Ų鵽��ϸ��Ϣ
void StudentScoreManager::FindStudentByNumber() const
{
    cout << "������Ҫ���ҵ�ѧ�ţ�";

    unsigned int number;
    cin >> number;

    //�û�����������ַ�ʱ����ʱ��������
    if (CheckInputFail())
    {
        return;
    }

    //����ǲ����ںϷ���Χ�ڵ�ѧ��:
    unsigned int maxNumber = students.size();

    if (number > maxNumber)
    {
        cout << "ѧ��ֻ������ 1~" << maxNumber << " ֮�䣡" << endl;
        return;
    }

    cout << "ѧ�ţ�" << number;
    cout << "��������" << students[number - 1].name;

    //�����飺��ѧ�Ų����:
    FindScoreByNumber(number);

    cout << endl;
}

//ͨ���������ҵ�ѧ��������Ϣ��Ȼ����ͨ��ѧ���ҵ�ѧ���ɼ���
//����ʾ�鵽�Ľ��������ж��ͬ��ѧ������ȫ�������
void StudentScoreManager::FindStudentByName() const
{
    cout << "����������ҵ�ѧԱ������";

    string name;

    getline(cin, name);

    CompareByName4Find cmp;
    cmp.name = name;

    int foundCount = 0; //�Ѿ����ҵ��������ˣ�

    vector<Student>::const_iterator beg = students.begin(); //���������

    while(true)
    {
        //����ѧ����ע����ҷ�ΧΪ: beg ~ students.end()
        beg = find_if(beg, students.end(), cmp);

        if (beg == students.end())
        {
            break; //�Ҳ�������...����ѭ��
        }

        //�鵽��ѧ����...
        ++foundCount; //�ҵ���������1��

        //��ʾѧ��������Ϣ��
        cout << "������" << name;
        cout << "��ѧ�ţ�" << beg->number;

        //�����飺��ѧ�Ų����:
        FindScoreByNumber(beg->number);

        cout << endl;

        //��Ҫ����begǰ������һ��λ�ã�
        //��˼�ǣ��´β���ʱ�����ӵ�ǰ�ҵ�����ѧ������һ��λ�ÿ�ʼ����
        beg++;
    }

    cout << "�ܹ��鵽" << foundCount << "λѧ������Ϊ��" << name << endl;
}

//����ѧ�ŵĴ������ѧ���ɼ���û�гɼ���ѧԱ����ʾ�����޳ɼ���
void StudentScoreManager::OutputScoresByNumber() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; //ѧ��

        cout << "ѧ�ţ�" << number;
        cout << "��������" << students[i].name;

        //���ҳɼ�:
        CompareByNumber_Equal4Find cmp;
        cmp.number = number;

        list<Score>::const_iterator iter = find_if(scores.begin(), scores.end(), cmp);

        if (iter != scores.end())
        {
            cout << "���ɼ���" << iter->mark << endl;
        }
        else //û�ҵ�
        {
             cout << "���ɼ���" << "���޳ɼ���" << endl;
        }
    }
}

//�Ƚ������Ƚϳɼ��еķ����ߵ�
//��InputScores()�У�¼��ɼ�֮�󣬻�����ʹ�ñ��Ƚ϶Գɼ���������
struct CompareByMarkBigger
{
    bool operator () (Score s1, Score s2) const
    {
        return (s1.mark > s2.mark);
    }
};

//¼��ѧ���ɼ���¼����ɺ�������
void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;

        cout << "������ѧ�ţ�����0��ʾ��������";

        cin >> number;

        //����û������ǲ��ǺϷ�������
        if (CheckInputFail())
        {
            continue;
        }

        if (number == 0)
        {
            break;
        }

        //�ж�ѧ�Ŵ�С�Ƿ��ںϷ��ķ�Χ�ڣ�
        if (number > students.size())
        {
            cout << "����ѧ�ű���λ��: 1 ~ " << students.size() << " ֮�䡣" << endl;
            continue;
        }

        float mark;
        cout << "������ɼ�(" << students[number-1].name << ")��"; //����˴�������������ʾ
        cin >> mark;

        //����û������ǲ��ǺϷ��ĸ�����
        if (CheckInputFail())
        {
            continue;
        }

        Score score;
        score.number = number;
        score.mark = mark;

        scores.push_back(score);
    }

    //�����������ܣ�¼��ɼ��������������ߵ�����
    //��֤scores�е�Ԫ����Զ�������
    CompareByMarkBigger cmp;
    scores.sort(cmp);
}

//��ճɼ�
void StudentScoreManager::ClearScores()
{
    cout << "��ȷ��Ҫ���ȫ���ɼ����ݣ� (y/n)";

    char c;
    cin >> c;

    if (c == 'y')
    {
        scores.clear();
        cout << "�ɼ����������ϣ�" << endl;
    }

    cin.sync();
}

//�������ߵͣ����ÿ���ɼ�������ѧ��������û�вμӿ���ѧԱ�������ᱻ���
void StudentScoreManager::OutputScoresByMark() const
{
    //��ÿ��¼��ɼ�֮�����Ƕ������sort����Ϊ���гɼ���������
    //����scores�е����гɼ����Ѿ��ǰ��ߵͷ�������
    //�����ǣ�������ͬʱ���봦�����β��С��������

    int index = 1; //��ǰ����,������1��ʼ
    int count = 0; //��ͬ��������
    double last = -1.0; //��һ�η������տ�ʼʱ����ʼ��Ϊһ�������ܵķ���

    for (list<Score>::const_iterator it = scores.begin();
        it != scores.end();
        ++it)
    {
        if (last != it->mark) //�µķ�������
        {
            last = it->mark;
            index += count;
            count = 1;
        }
        else //����ԭ���ķ�����ͬ�֣�
        {
            ++count;
        }

        cout << "���Σ�" << index;
        cout << "��������" << students[it->number - 1].name; //ͨ��ѧ�ŵõ�����
        cout << "��ѧ�ţ�" << it->number;
        cout << "���ɼ���" << it->mark << endl;
    }
}

void About()
{
    system("cls");

    cout << "ѧ���ɼ�����ϵͳ Ver 2.0" << endl;
    cout << "copyright 2008~?" << endl;
    cout << "���ߣ���С��" << endl;
    cout << "���ԣ�www.d2school.com/�׻�C++" << endl;
}

void Help()
{
    system("cls");

    cout << "1#¼��ѧ��������Ϣ��" << endl
        << "��ע�⣬����¼��ʱ��ԭ�����ݻ���գ�" << endl
        << endl;

    cout << "2#¼��ɼ���" << endl
        << "��ע�⣬����ԭ�гɼ�������¼�룬�����Ҫ��ճɼ�����ʹ�ã���ճɼ���" << endl
        << endl;

    cout << "3#��ճɼ���" << endl
        << "֮ǰ¼��ĳɼ�������������������ɻָ���" << endl
        << endl;

    cout << "4#��ѧ�Ŵ�����ʾ�ɼ���" << endl
        << "��ѧ�Ŵ�С��������ɼ�������������δ�μӿ��Ի�¼��ɼ�ѧԱ������ʾ���޳ɼ���" << endl
        << endl;

    cout << "5#������������ʾ�ɼ���" << endl
        << "�������Ӹߵ�������ɼ����������Σ�ѧ�ţ������ȡ�" << endl
        << "�Ҹ棺��˵��������ֹѧУ�����ɼ�������" << endl
        << endl;

    cout << "6#��ѧ�Ų���ѧ����" << endl
        << "����ѧ�ţ����ҵ�ָ��ѧ����ѧ����Ϣ�������ɼ���" << endl
        << endl;

    cout << "7#����������ѧ����" << endl
        << "�����������鵽�������ֵ�ѧ�������������Ϣ�������ɼ����������������������" << endl
        << endl;

    cout << "8#���ڣ����ڱ������һЩ��Ϣ��" << endl << endl;
    cout << "9#��������ʾ��������Ϣ��" << endl << endl;
    cout << "0#�˳�������0���˳�������" << endl << endl;
}

int Menu()
{
    cout << "---------------------------" << endl;
    cout << "----ѧ���ɼ�����ϵͳ Ver2.0----" << endl;
    cout << "---------------------------" << endl;

    cout << "��ѡ��(0~1)" << endl;

    cout << "1--#¼��ѧ��������Ϣ" << endl;
    cout << "2--#¼��ɼ�" << endl;
    cout << "3--#��ճɼ�" << endl;

    cout << "---------------------------" << endl;
    cout << "4--#��ѧ�Ŵ�����ʾ�ɼ�" << endl;
    cout << "5--#������������ʾ�ɼ�" << endl;

    cout << "---------------------------" << endl;
    cout << "6--#��ѧ�Ų���ѧ��" << endl;
    cout << "7--#����������ѧ��" << endl;

    cout << "---------------------------" << endl;
    cout << "8--#����" << endl;
    cout << "9--#����" << endl;

    cout << "---------------------------" << endl;
    cout << "0--#�˳�" << endl;

    int sel;
    cin >> sel;

    if (CheckInputFail())
    {
        return -1;
    }

    cin.sync(); //�����������֮��� �س���

    return sel;
}

int main()
{
    StudentScoreManager ssm;

    while(true)
    {
        int sel = Menu();

        if (sel == 1)
        {
            ssm.InputStudents();
        }
        else if (sel == 2)
        {
            ssm.InputScores();
        }
        else if (sel == 3)
        {
            ssm.ClearScores();
        }
        else if (sel == 4)
        {
            ssm.OutputScoresByNumber();
        }
        else if (sel == 5)
        {
            ssm.OutputScoresByMark();
        }
        else if (sel == 6)
        {
            ssm.FindStudentByNumber();
        }
        else if (sel == 7)
        {
            ssm.FindStudentByName();
        }
        else if (sel == 8)
        {
            About();
        }
        else if (sel == 9)
        {
            Help();
        }
        else if (sel == 0)
        {
            break;
        }
        else //ʲôҲ����..
        {
            cout << "����ȷ����ѡ�񣺷�Χ�� 0 ~ 9 ֮�ڡ�" << endl;
        }

        system("Pause");
    }

    cout << "bye~bye~" << endl;

    return 0;
}
