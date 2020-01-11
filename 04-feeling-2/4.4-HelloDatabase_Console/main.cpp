#include <iostream>
#include <string>
#include <cstdlib> //for system

#include <mysql++.h>

using namespace std;

int main()
{
    mysqlpp::Connection con(false);

    con.set_option(new mysqlpp::SetCharsetNameOption("gbk"));

    cout << "���������ݿ�(root�û�)�������룺";
    string pwd;
    getline(cin, pwd);

    if (!con.connect("d2school", "localhost", "root", pwd.c_str()))
    {
        cout << "�޷����������ݣ����������Ƿ���ȷ!" << endl;
        return -1;
    }


//    mysqlpp::Query q1 = con.query("SET character_set_connection='gb2312'");
//    q1.execute();
//
//    mysqlpp::Query q2 =  con.query("SET character_set_client ='gb2312'");
//    q2.execute();
//
//    mysqlpp::Query q3 = con.query("SET character_set_results = 'gb2312'");
//    q3.execute();

    mysqlpp::Query query = con.query("SELECT abs_index, day_index, name"
        ", province, sex, item, score FROM champions_2008 ORDER BY abs_index");

    mysqlpp::StoreQueryResult res = query.store();

    if (!res)
    {
        cout << "���޼�¼�����������query����ǲ���д���ˣ�" << endl;
        return -1;
    }

    for (unsigned int i = 0; i < res.num_rows(); ++i)
    {
        cout << "��" << res[i]["abs_index"] << "��";
        cout << "\t�ջ��ڵ�" << res[i]["day_index"] << "��" << endl;

        cout << "���ƻ���ߣ�" << res[i]["name"];

        cout << "\t�Ա�" << ((res[i]["sex"] == "0")? "Ů" : "��") << endl;

        cout << "�ھ����ԣ�" << res[i]["province"] << endl;
        cout << "����Ŀ��" << res[i]["item"] << endl;

        cout << "�ɼ���";
        if (res[i]["score"].is_null())
        {
            cout << "N/A" << endl;
        }
        else
        {
            cout << res[i]["score"] << endl;
        }

        cout << "-----------------------------------------------" << endl;
        system("pause");
    }
}


