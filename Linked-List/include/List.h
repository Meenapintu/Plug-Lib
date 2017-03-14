#ifndef LIST_H
#define LIST_H


#include "iterator.h"

template<typename Object>
class List
{
    public:
        /** Default constructor */
        List();
        /** Default destructor */
        virtual ~List();
        /** Copy constructor
         *  \param other Object to copy from
         */
        List(const List& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        List& operator=(const List& other);

        /** Access size
         * \return The current value of size
         */
        int getsize()const { return size; }
        /** Set size
         * \param val New value to set
         */
        void setsize(int val) { size = val; }
        /** Access *head
         * \return The current value of *head
         */
        Node<Object>* Gethead() { return head; }

        /** Access *tail
         * \return The current value of *tail
         */
        Node<Object>* Gettail() { return tail; }

        //class const_iterator;
        //class iterator ;

        iterator<Object> begin(){return iterator<Object>(head->next);}
        iterator<Object> end(){return iterator<Object>(tail);}

        const_iterator<Object> begin()const{return const_iterator<Object>(head->next);}
        const_iterator<Object> end()const{return const_iterator<Object>(tail);}

        bool empty()const {return getsize()==0;}
        void clear(){while(!empty()){pop_front();}}

        Object & front(){ return *begin();}
        Object & back(){return *--end();}
        void push_front(const Object & obj){insert(begin(),obj);}
        void push_back(const Object & obj){insert(end(),obj);}
        void pop_front(){erase(begin());}
        void pop_back(){erase(--end());}

        iterator<Object> insert(iterator<Object> itr,const Object & obj);
        iterator<Object> erase(iterator<Object> itr);
        iterator<Object> erase(iterator<Object> start,iterator<Object> end);

    protected:

    private:
        int size; //!< Member variable "size"
        Node<Object> *head; //!< Member variable "*head"
        Node<Object> *tail; //!< Member variable "*tail"
};

#include"../src/List.cpp"
#endif // LIST_H
