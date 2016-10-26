#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED

//#include "const_iterator.h"

#include "Node.h"

template<typename Object>
class List;

template<typename Object>
class const_iterator
{
    public:
        const_iterator():current(nullptr)
        {}
        const Object & operator*() const {return retrive();}
        const_iterator & operator++(){current =current->next;return *this;}
        const_iterator operator++(int){const_iterator citr = *this;++(*this);return citr;}
        bool operator==(const const_iterator &rhs)const {return current ==rhs.current;}
        bool operator!=(const const_iterator &rhs)const {return !(*this==rhs);}


        protected:
            Node<Object> *current;
            Object & retrive()const{return current->data;}
            const_iterator(Node<Object> *node):current(node)
            {}
            friend class List<Object>;

};



template<typename Object>
class iterator : public const_iterator<Object>{
    public:
        iterator(){}

        Object & operator*(){return this->retrive();}
        const Object & operator*()const{return this->const_iterator<Object>::operator*();}
        iterator & operator++(){this->current=this->current->next;return *this;}
        iterator operator++(int){iterator citr = *this;++(*this);return citr;}

    protected:
        iterator(Node<Object> *node):const_iterator<Object>(node)
        {}
        friend class List<Object>;
};

#endif // ITERATOR_H_INCLUDED
