#include <iostream>

using namespace std;

int main()
{
    int* a;
    cout << "----����: int a;----" << endl;
    cout << "ָ�����a��ֵΪ: " << a 
        << "�������aָ��ĵ�ַ�������Ǹ���ȷ����ֵ��" << endl;
    cout << "ָ�����a���ڴ��ַΪ: " << &a << endl;
    cout << "ָ�����aռ�õ��ڴ�ߴ�Ϊ: " << sizeof(a) << "���ֽ�" << endl;
    cout << "ָ�����a��������������Ϣ����Ϊ: " << typeid(a).name() << endl;
    
    a = new int;
    cout << "----����: a = new int;----" << endl;
    cout << "ָ�����a��ֵΪ: " << a 
        << "�������aָ��ĵ�ַ��" << endl;
    cout << "ָ�����a���ڴ��ַΪ: " << &a << endl;
    cout << "ָ�����aռ�õ��ڴ�ߴ�Ϊ: " << sizeof(a) << "���ֽ�" << endl;
    cout << "ָ�����a��������������Ϣ����Ϊ: " << typeid(a).name() << endl;
    cout << "ָ�����a����ָ���ڴ��д�����������ǣ�" << *a 
        << ",�����Ǹ���ȷ����ֵ��" << endl;
    
    *a = 123;
    cout << "----����: a = new int;----" << endl;
    cout << "ָ�����a��ֵΪ: " << a 
        << "�������aָ��ĵ�ַ��" << endl;
    cout << "ָ�����a���ڴ��ַΪ: " << &a << endl;
    cout << "ָ�����aռ�õ��ڴ�ߴ�Ϊ: " << sizeof(a) << "���ֽ�" << endl;
    cout << "ָ�����a��������������Ϣ����Ϊ: " << typeid(a).name() << endl;
    cout << "ָ�����a����ָ���ڴ��д�����������ǣ�" << *a << endl;
    
    cout << "ָ�����a����ָ���ڴ��д������ռ�õ��ڴ�ߴ�Ϊ��" << sizeof(*a) << endl;
    
    return 0;
}
