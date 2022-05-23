//
// Created by teich on 23/05/2022.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
#include "Node.h"

template <class T>
class Queue
{

public:
    Queue():
            m_first(nullptr),
            m_last(nullptr),
            m_counter(0)
    {}

    ~Queue()
    {
        while(!isEmpty())
            popFront();
    }

    void pushBack(T element)
    {
        Node<T>* tmp = new Node<T>();
        tmp->setData(element);
        tmp->setNext(nullptr);

        if (isEmpty()) {
            m_first = m_last = tmp;
        }
        else {
            m_last->setNext(tmp);
            m_last = tmp;
        }
        m_counter++;
    }

    T front()
    {
        if (isEmpty()) {
            throw EmptyQueue();
        }
        return m_first->getData();
    }


    void popFront()
    {
        if ( isEmpty() ){
            throw EmptyQueue();
        }
        Node<T>* tmp = m_first;
        m_first = m_first->getNext();
        m_counter--;
        delete tmp;
    }


    int Size()
    {
        return m_counter;
    }

    bool isEmpty()
    {
        return m_counter == 0;
    }

    template<class P, class Condition>
    friend Queue<P> filter(Queue<P> queue,Condition condition);


    class EmptyQueue {};

private:
    Node<T>* m_first;
    Node<T>* m_last;
    int m_counter;
};

template <class P, class Condition>
Queue<P> filter(Queue<P> queue , Condition condition) {
    {
        Queue<P> result;
        for (const P& element: queue) {
            if ( condition(element) ){
                result.pushBack(element);
            }
        }
        return result;
    }
}


#endif //EX3_QUEUE_H
