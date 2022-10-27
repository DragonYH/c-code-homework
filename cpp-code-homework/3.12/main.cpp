#include "LinkList.h"
#include <iostream>
using namespace std;
void main_show()
{
    cout << "1.添加一个节点" << endl;
    cout << "2.删除第一个节点" << endl;
    cout << "3.输出整条链表" << endl;
    cout << "0.退出" << endl;
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
        cout << "请输入序号：";
        cin >> i;
        switch (i)
        {
        case 0:
            exit(0);
            break;
        case 1:
            cout << "请输入节点数据内容：";
            cin >> x;
            link.insert(x);
            break;
        case 2:
            link.delete_();
            cout << "删除成功！" << endl;
            break;
        case 3:
            link.print();
            break;
        default :
            cout << "请输入正确序号！" << endl;
            break;
        }
    }
}