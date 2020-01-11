#include <iostream>

using namespace std;

//��̬�������飺
void demo_1()
{
    cout << "˵����¼�����ɸ��ɼ��������ҳ����е�һ����߷�" << endl;
    cout << "������ɼ�������";
   
    int score_count;
    cin >> score_count;
    
    if (score_count <= 0)
    {
        return;
    }
    
    unsigned int* scores = new unsigned int[score_count];
    
    cout << "��¼��" << score_count << "���ɼ�(������)��" << endl;
    
    unsigned int top_score = 0;
    
    for (int i=0; i<score_count; ++i)
    {
        cout << "��¼���" << i+1 << "���ɼ���";
        cin >> scores[i];
        
        if (scores[i] > top_score)
        {
            top_score = scores[i]; //ȡ����ǰ���ĳɼ�
        }
    }
    
    //��ʾ��
    cout << "��¼��ĳɼ��ǣ�";
    for (int i=0; i<score_count; ++i)
    {
        cout << *(scores + i) << ", ";
    }
    
    cout << "������߷��ǣ�" << top_score << endl;
    
    cout << "���棬�������" << score_count << "��Ԫ�صĵ�ַ��" << endl;
    system("pause");
    for (int i=0; i<score_count; ++i)
    {
        cout << "��" << i << "��Ԫ�صĵ�ַ��" << scores + i << endl;
    }
    
    delete [] scores; //������
}

//ջ����
void demo_2()
{
    int cost[7]; 
    
    cout << "˵���������������7������ÿ�ջ�������λ��Ԫ����Ҫ¼��С����" << endl
        << "���򽫼������һ������ÿ��ƽ�������Ƕ��١�" << endl;
    
    int total = 0;
    
    for (int i=0; i<7; ++i)
    {
        cout << "��" << i+1 << "�죺";
        cin >> cost[i];
        
        total += cost[i];
    }
    
    //��ʾ:
    cout << "�����7���ÿ�ջ����ǣ�";
    for (int i=0; i<7; ++i)
    {
        cout << cost[i] << "Ԫ, ";
    }
    
    int average_cost = total / 7;
    cout << "ƽ����" <<  average_cost << "Ԫ��" << endl;
    
    if (average_cost >= 1000)
    {
        cout << "��Ѿ��Ҳ̫�ݳ��˰� :}" << endl;
    }
    
    cout << "���棬�������7��Ԫ�صĵ�ַ��" << endl;
    system("pause");
    for (int i=0; i<7; ++i)
    {
        cout << "Ԫ��" << i << "����ַ������һ��" << &(cost[i])
            << "\t��������" << cost + i << endl;
    }
}

//��ά����
void demo_3()
{
    int cost[7][3];
    
    cout << "˵���������������7������ÿ�����͵Ļ���" << endl
        << "���򽫸������ۣ������ο���" << endl;
        
    char* titles [3] = 
    {
        "���", "���", "���",
    };
    
    for (int i=0; i<7; ++i)
    {
        cout << "��" << i+1 << "��:" << endl;
        
        for (int j=0; j<3; ++j)
        {
            cout << titles[j] << "������";
            cin >> cost[i][j]; //cin >> *(*(cost + i) + j);
        }
    }
    
    int total[3]; //���ͷֿ�С��
    int total_all = 0; //ȫ���ʹ��ۼ�

    //����ѭ��Ϊ��Ϊ�ʹ�
    for (int j=0; j<3; ++j)
    {
        total[j] = 0;
        
        for (int i=0; i<7; ++i) //�ڲ�����ѭ��7��
        {
            total[j] += cost[i][j]; //i,j λ�� ���� 
        }
        
        total_all += total[j];
    }

    if (total[0] < ((total_all * 15 / 100) * 80 / 100)
        || total[0] > ((total_all * 15 / 100) * 120 / 100)
        || total[2] < ((total_all * 30 / 100) * 80 / 100)
        || total[2] > ((total_all * 30 / 100) * 120 / 100)
        )
    {
        cout << "�����ͻ��Ѱ��ŵ��е㲻�����ޡ�" << endl;
    }
    else
    {
        cout << "�����Ͱ��ŵúܺ���" << endl;
    }
    
    cout << "���棬�������21��Ԫ�صĵ�ַ��" << endl;
    system("pause");
    
    for (int i=0; i<7; ++i)
    {
        for (int j=0; j<3; ++j)
        {
            cout << "��" << i*7 + j << "��Ԫ�ص�ַ:" << &(cost[i][j])
                << "\t��������" << *(cost + i) + j << endl;
        }
    }
}

int main()
{
    cout << "ʾ��1��һά������ʾ��" << endl;
    cout << "----------------��˵�еķָ���----------------" << endl;
    demo_1();
    
    cout << "ʾ��2��һάջ����ʾ��" << endl;
    cout << "----------------��˵�еķָ���----------------" << endl;
    demo_2();
    
    cout << "ʾ��3����άջ����ʾ��" << endl;    
    cout << "----------------��˵�еķָ���----------------" << endl;
    demo_3();
    
    return 0;
}
