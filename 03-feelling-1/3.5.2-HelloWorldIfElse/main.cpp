#include <iostream>
#include <string>
using namespace std;

void Hello(string const name)
{
    if (name == "־��")
    {
        cout << "Hi! ־����á�����С�ǣ��úð��ء���" << endl;
    }
    else
    {
        cout << "Hello! " << name << "." << endl;
    }
}

int main()
{    
    string name;
    
    cout << "Please input the name: ";
    getline(cin, name);
    Hello(name);
    
    cout << "Please input the name: ";
    getline(cin, name);
    Hello(name);
    return 0;
}
