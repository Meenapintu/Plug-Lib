#include "../include/list.h"

template<class Type>
inline Node<Type>::Node(Type value)
{
    this.m_value=value;
    this.m_m_next = nullptr;
}
template <class Type>
list<Type>::list()
{
    //ctor
     m_list =nullptr;
     m_length=0;
}
template <class Type>
list<Type>::~list()
{
    //dtor
    Node<Type> *temp = m_list;
    while(m_list!=nullptr)
    {

    }
}
template <class Type>
list<Type>::list(const list& other)
{
    //copy ctor
    this.m_list = other.first();
    this.m_length=other.length();
}
template <class Type>
list<Type>& list<Type>::operator=(const list& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/**================================**/
template<class Type>
bool list<Type>::insert(Type elem)
{
 Node<Type> *temp = new Node<Type>(elem);
 temp.m_next =m_list;
 m_list =temp;
 length++;
 return true;
}
template<class Type>
bool list<Type>::remove()
{
    if(m_list==nullptr)
    {
        std::cout<<"empty list : nothing to remove";
        return false;
    }
     Node<Type> *temp = m_list.m_next;
     delete m_list;
     m_list = temp;
     return true;

}
template<class Type>
bool list<Type>::remove(int key)
{
     if(m_list==nullptr)
    {
        std::cout<<"empty list : nothing to remove";
        return false;
    }
    Node<Type> * node = m_list;
    while(node!=nullptr)
    {
            if(key ==node->value())
            {
                Node<Type> *temp = node->m_next();
                node = Node<Type>(temp);
            }
        node = node->m_next();
    }
}
template<class Type>
void list<Type>::display()
{
    Node<Type> * node = m_list;
    std::cout<<"list.size: "<<m_length<<'\n';
    while(node!=nullptr)
    {
        std::cout<<node->value()<<"  ";
        node = node->m_next();
    }
}
template<class Type>
Type* list<Type>::search(Type key)
{
    Node<Type> * node = m_list;
    while(node!=nullptr)
    {
            if(key ==node->value())return node;
        node = node->m_next();
    }
    return nullptr;
}
