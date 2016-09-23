#ifndef LIST_H
#define LIST_H
#include<iostream>

using namespace std;
void debug(string str)
{
    std::cout<<str<<'\n';
}

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
            debug("NODE DESTRUCTOR CALLED   "+m_value);
            delete m_next;
            debug("NODE DESTRUCTOR CALLED");
        }

        inline Type value()const {return this->m_value;}
        inline Node* next()const {return this->m_next;}
        inline Node(const Node* node){this->m_value=node->value();debug("ERROR");this->m_next=node->next();debug("ERROR");}
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

        /** def template **/
        /** insert an element to the list at beginning  of list **/
        bool insert(Type elem);

        /** add an element at the end of list **/
        //bool push_back(Type elem); o(n^2 costly ) so we don't do it

        /** delete an element from the list **/
        bool remove();
        bool remove(Type key);

        /** display list element **/
        void display();

        /** search an element in list  return node if node found else return @nullptr**/
        Node<Type>* search(Type key);

        /** pointer to first element  **/
        //inline Node<Type>* first(){return m_list;}
        inline  Node<Type>* first() const {return m_list;}
        /** length of list (little bit memory overhead but o(1) time) **/
        //inline int length(){return m_length;}
        inline   int length() const {return m_length;}
        void name(string str){m_name=str;}
    protected:
    Node<Type>* m_list;
    Node<Type>* m_temp;
    int m_length;
    string m_name;
    private:

};


#endif // LIST_H
