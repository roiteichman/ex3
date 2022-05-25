//
// Created by shlom on 23/05/2022.
//

#ifndef EX3_NODE_H
#define EX3_NODE_H
template <class T>
class Node
{
private:
    T *m_data;
    Node* m_next;
public:
    void setData(T element)
    {
        *m_data = element;
    }
    Node(const Node&) = default;

    Node& operator=(const Node&) = default;
    void setNext(Node<T>* element)
    {
        m_next = element;
    }
    T& getData() const
    {
        return *m_data;
    }
    Node* getNext()
    {
        return m_next;
    }
};
#endif //EX3_NODE_H
