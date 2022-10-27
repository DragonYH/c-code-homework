#include "LinkList.h"
#include <iostream>
using namespace std;
Link::Node::Node()
{
    next = NULL;
    prvs = NULL;
};
Link::Link()
{
    head = NULL;
};
//添加一个节点到链表最前
void Link::insert(int date)
{
    Node *p = new Node();
    p->date = date;
    if (head != NULL)
    {
        p->next = head;
        head->prvs = p;
    }
    head = p;
};
//删除链表第一个节点
void Link::delete_()
{
    Node *p;
    p = head;
    head = head->next;
    delete p;
};
//输出整条链表内容
void Link::print()
{
    Node *p;
    p= head;
    while(p != NULL)
    {
        cout << p->date <<',';
        p = p->next;
    }
    cout << endl;
}