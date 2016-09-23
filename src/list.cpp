#include "../include/list.h"


void debug(string str)
{
    std::cout<<str<<'\n';
}

template<class Type>
inline Node<Type>::Node(Type value)
{
    this->m_value=value;
    this->m_next = nullptr;
}


template <class Type>
list<Type>::list()
{
    m_head =nullptr;
    m_length=0;
}
template <class Type>
list<Type>::~list()
{
    while(m_head != nullptr)
    {
        this->remove();
        //delete m_head;
    }

}
template <class Type>
list<Type>::list(const list& other)
{
    m_head=nullptr;
    if(other.first() == nullptr)
    {

        this->m_head =nullptr;
    }
    else
    {
        Node<Type> *node = other.first();
        Node<Type> *temp = new Node<Type>(node->value());
        this->m_head=temp;
        while(node->next() !=nullptr)
        {
            temp->m_next= new Node<Type>(node->next()->value());
            temp = temp->next();
            node=node->next();
        }
        this->m_length= other.length();
    }
}
template <class Type>
list<Type>& list<Type>::operator=(const list& rhs)
{

    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


template<class Type>
bool list<Type>::insert(Type elem)
{
    m_temp = new Node<Type>(elem);
    m_temp->m_next =m_head;
    m_head =m_temp;
    m_temp =nullptr; // set it to default
    this->m_length++;
    return true;
}


template<class Type>
bool list<Type>::remove()
{
    if(m_head!=nullptr )
    {
        m_temp = m_head;
        m_head = m_head->next();
        this->m_length--;
        //m_temp->m_next = nullptr;
        delete m_temp;
        return true;

    }
    else
    {
        debug("empty list : nothing to remove");
        return false;
    }

}
template<class Type>
bool list<Type>::remove(Type key)
{
    if(m_head==nullptr)
    {
        debug("empty list : nothing to remove");
        return false;
    }
    Node<Type> * node = m_head;
    while(node!=nullptr)
    {
        if(key ==node->value())
        {
            m_temp = node->next();
            node->m_value = m_temp->value();
            node->m_next = m_temp->next();
            //m_temp->m_next = nullptr;
            delete m_temp;
            this->m_length--;
            return true;

        }
        node = node->next();
    }
    return false;
}
template<class Type>
void list<Type>::display()
{
    Node<Type> * node = m_head;
    std::cout<<"list.size: "<<m_length<<'\n';
    int i=0;
    while(node!=nullptr)
    {
        std::cout<<node->value()<<"   ";
        node = node->next();
    }
    std::cout<<'\n';
}
template<class Type>
Node<Type>* list<Type>::search(Type key)
{
    Node<Type> * node = m_head;
    while(node!=nullptr)
    {
        if(key ==node->value())return node;
        node = node->next();
    }
    return nullptr;
}
