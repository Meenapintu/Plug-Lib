#include "../include/list.h"



template<class Type>
inline Node<Type>::Node(Type value)
{
    debug("Node Constructor called with value"+value);
    this->m_value=value;
    this->m_next = nullptr;
}


template <class Type>
list<Type>::list()
{
    //ctor
    debug("list constructor called");
     m_list =nullptr;
     m_length=0;
}
template <class Type>
list<Type>::~list()
{
    //dtor
    debug("LIST NAME ====  "+m_name);
    while(m_list != nullptr)
    {
        this->remove();
       //delete m_list;
    }
    debug("REMOVED LIST NAME ====  "+m_name);
}
template <class Type>
list<Type>::list(const list& other)
{
    //copy ctor
    m_list=nullptr;
    debug("list copy constructor called");
    if(other.first() == nullptr)
    {
             debug("COUNT OF NULL");
            this->m_list =nullptr;
    }
    else
    {
        Node<Type> *node = other.first();
        Node<Type> *temp = new Node<Type>(node->value());
        this->m_list=temp;
        while(node->next() !=nullptr)
    {
            temp->m_next= new Node<Type>(node->next()->value());
            temp = temp->next();
            node=node->next();
    }


    /**
    Node<Type> *node = new Node<Type>(other.first());
    this->m_list =new Node<Type>(other.first());
    node=node->next();
    while(node !=nullptr)
    {
        node = new Node<Type>(node);
         node=node->next();
         debug("COUNT OF STR");
    }**/

     this->m_length= other.length();
    }
}
template <class Type>
list<Type>& list<Type>::operator=(const list& rhs)
{
    debug("list operator called ");
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/**================================**/
template<class Type>
bool list<Type>::insert(Type elem)
{
 m_temp = new Node<Type>(elem);
 m_temp->m_next =m_list;
 m_list =m_temp;
 m_temp =nullptr; // set it to default
 this->m_length++;
 return true;
}

template<class Type>
bool list<Type>::remove()
{
    if(m_list!=nullptr )
    {
            m_temp = m_list;
            m_list = m_list->next();
            this->m_length--;
            m_temp->m_next = nullptr;
            delete m_temp;
         return true;

    }
    else{
     std::cout<<"empty list : nothing to remove";
        return false;
    }

}
template<class Type>
bool list<Type>::remove(Type key)
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
                debug("Matched");
                m_temp = node->next();
                //node = new Node<Type>(temp);
                node->m_value = m_temp->value();
                node->m_next = m_temp->next();
                m_temp->m_next = nullptr;
                delete m_temp;
                this->m_length--;

            }
            else{
                debug("NOT Matched");
            }
        node = node->next();
    }
     debug("YES NO Matched");
    return true;
}
template<class Type>
void list<Type>::display()
{
    Node<Type> * node = m_list;
    std::cout<<"list.size: "<<m_length<<'\n';
    int i=0;
    while(node!=nullptr)
    {
        std::cout<<node->value()<<"->"<<i++<<"   ";
        node = node->next();
    }
    std::cout<<'\n';
}
template<class Type>
Node<Type>* list<Type>::search(Type key)
{
    Node<Type> * node = m_list;
    while(node!=nullptr)
    {
            if(key ==node->value())return node;
        node = node->next();
    }
    return nullptr;
}
