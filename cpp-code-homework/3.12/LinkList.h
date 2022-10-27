#ifndef LISTSTRING_H
#define LISTSTRING_H
class Link
{
private:
    class Node
    {
    public:
        int date;
        Node *next;
        Node *prvs;
        Node();
    };
public:
    Node *head;
    Link();
    void insert(int);   //插入节点
    void delete_();  //删除第一个节点
    void print();   //输出
    ~Link(){};
};
#endif