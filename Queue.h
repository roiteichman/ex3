//
// Created by teich on 23/05/2022.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
#include "Node.h"
#include <cassert>
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

    Queue(const Queue&) = default;

    Queue& operator=(const Queue& queue)
    {
        if (this== &queue){
            return *this;
        }
        Queue<T>* queue1 = new Queue<T>();

        try {
            for (const T &element: queue) {
                queue1->pushBack(element);
            }
        }
        catch (...){
            delete queue1->m_first;
            throw;
        }
        delete this->m_first;
        this->m_first=queue1->m_first;
        this->m_counter=queue1->m_counter;
        this->m_last=queue1->m_last;
        return *this;
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

    T& front() const
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


    int size() const
    {
        return m_counter;
    }

    bool isEmpty() const
    {
        return m_counter == 0;
    }

    template<class P, class Condition>
    friend Queue<P> filter(Queue<P> queue,Condition condition);

    template<class P, class Operation>
    friend void transform(Queue<P> &queue, Operation operation);



    class Iterator;
    class ConstIterator;

    Iterator begin()
    {
        return Iterator(this, this->m_first);
    }
    Iterator end()
    {
        return Iterator(this, NULL);
    }

    ConstIterator begin() const
    {
        return ConstIterator(this, this->m_first);
    }
    ConstIterator end() const
    {
        return ConstIterator(this, NULL);
    }

    class EmptyQueue {};

private:
    Node<T>* m_first;
    Node<T>* m_last;
    int m_counter;
};

template <class P, class Condition>
Queue<P> filter(Queue<P> queue ,Condition condition) {
        Queue<P> result;
        for (const P& element: queue) {
            if ( condition(element) ){
                result.pushBack(element);
            }
        }
        return result;
}

template<class P, class Operation>
void transform(Queue<P> &queue ,Operation operation)
{
    for (typename Queue<P>::Iterator i = queue.begin(); i != queue.end(); ++i) {
        operation(*i);
    }
}

template<class T>
class Queue<T>::Iterator{
public:
    T& operator*() const
    {
        if(!(m_queue->isEmpty()) && (&m_current))
        {
            return m_current->getData();
        }
        throw InvalidOperation();
        //important
    }
    Iterator& operator++()
    {
        if (!(m_current)){
            throw InvalidOperation();
        }
        m_current = m_current->getNext();
        return *this;
    }

    Iterator operator++(int)
    {
        if (!m_current){
            throw InvalidOperation();
        }
        Iterator result = *this;
        ++*this;
        return result;
    }

    bool operator==(const Iterator& iterator) const
    {
        if(!(m_queue == iterator.m_queue))
        {
            throw InvalidOperation();
        };
        return m_current == iterator.m_current;
    }

    bool operator!=(const Iterator& iterator) const
    {
        return !(*this == iterator);
    }

    Iterator(const Iterator&) = default;

    Iterator& operator=(const Iterator&) = default;

    class InvalidOperation {};

private:
    const Queue<T>* m_queue;
    Node<T> *m_current;
    Iterator(const Queue<T> *queue, Node<T> *current):
            m_queue(queue),
            m_current(current)
    {};
    friend class Queue<T>;

};


template<class T>
class Queue<T>::ConstIterator{
public:
    const T& operator*() const
    {
        if(!(m_queue->isEmpty()) && m_current);
        return m_current->getData();
    }
    ConstIterator& operator++()
    {
        if (!(m_current)){
            throw InvalidOperation();
        }
        m_current = m_current->getNext();
        return *this;
    }

    ConstIterator operator++(int)
    {
        if (!m_current){
            throw InvalidOperation();
        }
        ConstIterator result = *this;
        ++*this;
        return result;
    }

    bool operator==(const ConstIterator& constIterator) const
    {
        if(!(m_queue == constIterator.m_queue))
        {
            throw InvalidOperation();
        };
        return m_current == constIterator.m_current;
    }

    bool operator!=(const ConstIterator& constIterator) const
    {
        return !(*this == constIterator);
    }

    ConstIterator(const ConstIterator&) = default;

    ConstIterator& operator=(const ConstIterator&) = default;

    class InvalidOperation {};

private:
    const Queue<T>* m_queue;
    Node<T> *m_current;
    ConstIterator(const Queue<T>* queue, Node<T>* current):
            m_queue(queue),
            m_current(current)
    {};
    friend class Queue<T>;

};


#endif //EX3_QUEUE_H
