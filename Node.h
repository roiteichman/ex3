//
// Created by shlom on 23/05/2022.
//

#ifndef EX3_NODE_H
#define EX3_NODE_H
#define NULL 0
template <class T>
class Node
{
private:
    T m_data;
    Node* m_next;
public:
    Node():
    m_next(NULL)
   // m_data(0)
    {}
    Node(const Node&) = default;
    Node& operator=(const Node&) = default;
    ~Node() = default;
    void setData(T element)
    {
        if(this!= nullptr)
        {
            m_data = element;
        }
    }
    void setNext(Node<T>* element)
    {
        if(this!= nullptr) {
            m_next = element;
        }
    }
    T& getData()
    {
        return m_data;
    }
    Node* getNext()
    {
        return m_next;
    }
};
#endif //EX3_NODE_H
