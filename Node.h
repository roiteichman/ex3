//
// Created by shlom on 23/05/2022.
//

#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H
template <class T>
class Node
{
private:
    T data;
    Node* next;
public:
    void setData(T element)
    {
        data = element;
    }
    void setNext(Node<T>* element)
    {
        next = element;
    }
    T getData(void)
    {
        return data;
    }
    Node* getNext(void)
    {
        return next;
    }
};
#endif //UNTITLED1_NODE_H
