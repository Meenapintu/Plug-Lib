#ifndef LIST_H
#define LIST_H
#include<iostream>

using namespace std;

void debug(string str);

template<class Type>
struct Node
{
public:
    Type m_value;
    Node* m_next;

public:
    Node(Type value);
    virtual ~Node()
    {
        m_next=nullptr;
    }

    inline Type value()const
    {
        return this->m_value;
    }
    inline Node* next()const
    {
        return this->m_next;
    }
    inline Node(const Node* node)
    {
        this->m_value=node->value();
        debug("ERROR");
        this->m_next=node->next();
        debug("ERROR");
    }
};

template <class Type>
class list
{
public:

    /** Default constructor */
    list();

    /** Default destructor */
    virtual ~list();

    /** Copy constructor
     *  \param other Object to copy from
     */
    list(const list& other);

    /** Assignment operator
     *  \param other Object to assign from
     *  \return A reference to this
     */
    list& operator=(const list& other);


    /** insert an element to the list at beginning  of list **/
    bool insert(Type elem);


    /** delete an element from the list **/
    bool remove();

    /** delete an element from the list  with given key value**/
    bool remove(Type key);

    /** display list element **/
    void display();

    /** search an element in list  return node if node found else return @nullptr**/
    Node<Type>* search(Type key);

    /** pointer to first element  **/
    //inline Node<Type>* first(){return m_head;}
    inline  Node<Type>* first() const
    {
        return m_head;
    }
    /** length of list (little bit memory overhead but o(1) time) **/
    inline   int length() const
    {
        return m_length;
    }

protected:
    Node<Type>* m_head;
    Node<Type>* m_temp;
    node<Type>* m_back;
    int m_length;

private:

};

#include "../src/list.cpp"

#endif // LIST_H
