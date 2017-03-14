#include "../include/List.h"
template<typename Object>
List<Object>::List()
{
    //ctor
    this->size=0;
    this->head = new Node<Object>;
    this->tail = new Node<Object>;
    this->head->next = this->tail;
    this->tail->prev = this->head;
}
template<typename Object>
List<Object>::~List()
{
    //dtor
    this->clear();
    delete this->head;
    delete this->tail;
}
template<typename Object>
List<Object>::List(const List& other)
{
    //copy ctor
    List();
    *this=other;
}
template<typename Object>
List<Object>& List<Object>::operator=(const List& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->clear();
    for(const_iterator<Object> itr = rhs.begin();itr!=rhs.end();++itr){push_back(*itr);}
    return *this;
}
template<typename Object>
iterator<Object> List<Object>::insert(iterator<Object> itr,const Object & obj)
{
    Node<Object> *curr =  itr.current;
    this->size++;
    return iterator<Object>(curr->prev = curr->prev->next =new Node<Object>(obj,curr->prev,curr));
}
template<typename Object>
iterator<Object> List<Object>::erase(iterator<Object> itr)
{
    Node<Object> *curr = itr.current;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    this->size--;
    return itr++;
}

template<typename Object>
iterator<Object> List<Object>::erase(iterator<Object> start,iterator<Object> end)
{
    for(iterator<Object> itr = start; itr !=end;){itr=this->erase(itr);}
    return end;
}
