#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template<typename Object>
struct Node
{
    Object data;
    Node *prev;
    Node *next;

    Node(const Object &obj=Object(),Node *prev=nullptr,Node *next=nullptr){this->data = obj;this->prev=prev;this->next=next;}
};


#endif // NODE_H_INCLUDED
