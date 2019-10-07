#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

//ѧ��
struct Student
{
  unsigned int number; //ѧ��
  string name;
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
    void InputStudents();
    void InputScores();
    void OutputScores() const;

private:
    vector<Student> students;
    list<Score> scores;
};

void StudentScoreManager::InputStudents()
{
    unsigned int number = 1; //ѧ�Ŵ�1��ʼ

    while(true)
    {
        cout << "������" << number << "��ѧ������(����x��ʾ����)��";

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

struct CompareByNumber_Equal
{
   unsigned int number; //ѧ��

   bool operator () (unsigned int current_number) const
   {
        return current_number == number;
   }
};

//�� find ��������������������Բ�ͬ�������Լ���ͬ������Ԫ�أ�������������
template <typename T>
T find (T beg, T end, CompareByNumber_Equal cmp)
{
    for (T iter = beg; iter != end; ++iter)
    {
        if (cmp (iter->number))
        {
            return iter;
        }
    }

    //û�ҵ�,����end
    return end;
}

void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;

        cout << "������ѧ�ţ�����0��ʾ��������";

        cin >> number;

        if (number == 0)
        {
            break;
        }

        //���ж�ѧ���Ƿ���ȷ��
        if (number > students.size())
        {
            cout << "����ѧ�ű���λ��: 1 ~ " << students.size() << " ֮�䡣" << endl;
            continue;
        }

        float mark;
        cout << "�������ѧԱ�ɼ���";
        cin >> mark;

        Score score;
        score.number = number;
        score.mark = mark;

        scores.push_back(score);
    }
}

void StudentScoreManager::OutputScores() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; //ѧ��

        cout << "ѧ�ţ�" << number << endl;
        cout << "������" << students[i].name << endl;

        //���ҳɼ�:
        CompareByNumber_Equal cmp;
        cmp.number = number;

        list<Score>::const_iterator iter = find(scores.begin(), scores.end(), cmp);

        if (iter != scores.end())
        {
            cout << "�ɼ���" << iter->mark << endl;
        }
        else //û�ҵ�
        {
             cout << "�ɼ���" << "���޳ɼ���" << endl;
        }
    }
}

int main()
{
    StudentScoreManager ssm;

    ssm.InputStudents();
    ssm.InputScores();
    ssm.OutputScores();

    return 0;
}
