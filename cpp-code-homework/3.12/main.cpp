#include "LinkList.h"
#include <iostream>
using namespace std;
void main_show()
{
    cout << "1.���һ���ڵ�" << endl;
    cout << "2.ɾ����һ���ڵ�" << endl;
    cout << "3.�����������" << endl;
    cout << "0.�˳�" << endl;
}
int main()
{
    Link link;
    while(1)
    {
        int i;
        int x;
        system("clear");
        main_show();
        cout << "��������ţ�";
        cin >> i;
        switch (i)
        {
        case 0:
            exit(0);
            break;
        case 1:
            cout << "������ڵ��������ݣ�";
            cin >> x;
            link.insert(x);
            break;
        case 2:
            link.delete_();
            cout << "ɾ���ɹ���" << endl;
            break;
        case 3:
            link.print();
            break;
        default :
            cout << "��������ȷ��ţ�" << endl;
            break;
        }
    }
}