#include <iostream>
#include <list> 

using namespace std;

int main()
{
    list<int> lst;

    lst.push_front(10);
    lst.push_front(20);

    lst.push_back(8);
    lst.push_back(9);

    lst.pop_front();
    lst.pop_back();
    
    lst.clear();
    
    lst.push_back(1);
    lst.push_back(2);
    
    int a = lst.front();
    cout << a << endl;

    int b = lst.back();
    cout << b << endl;

    int count = lst.size();
    cout << count << endl;

    cout << lst.empty() << endl;
    lst.clear();
    cout << lst.empty() << endl;

    lst.push_back(1);
    lst.push_back(2);
    list<int>::iterator  iter = lst.begin();
    a = *iter;
    cout << a << endl;
    *iter = 1000;
    cout << *iter << endl;
    cout << a << endl;
    b = *iter;
    cout << b << endl;
    
    /*
    lst<int>::iterator iter2 = lst.end();
    int a = *iter2; //���ѷ���
    *iter2 = 100; //���ѷ���
    */
        
    lst.clear();
    lst.push_back(10);
    lst.push_back(100);
    iter = lst.begin();
    ++iter; //iterǰ��1����ָ��ڶ���Ԫ��
    lst.insert(iter, 1); //�ڵڶ���Ԫ�ص�λ���ϣ�������Ԫ��

    iter = lst.begin();
    ++iter;
    lst.erase(iter);

    list<int>::const_iterator  c_iter = lst.begin();  //��ʱ���õ��ǳ�����
    a = *c_iter; //��ȷ
    cout << a << endl;
    //*c_iter = 1000;  //����c_iter��ֻ������������������޸����󶨵�Ԫ��
    
    for (list<int>::const_iterator c_iter = lst.begin();
        c_iter != lst.end();
        ++c_iter)
    {
        cout << *c_iter << endl;
    }
    
    for (list<int>::const_reverse_iterator c_iter = lst.rbegin();
        c_iter != lst.rend();
        ++c_iter)
    {
        cout << *c_iter << endl;
    }

    return 0;
}
