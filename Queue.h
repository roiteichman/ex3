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
    /*
     * C'tor of Queue class
     *
     * @param
     * @return
     *      A new instance of Queue
    */
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

    /*
     * copy C'tor of Queue class
     *
     * @param queue- to be copied
     * @return
     *      A copy instance of queue
    */
    Queue(const Queue<T>& queue):
    m_first(NULL),
    m_last(NULL),
    m_counter(0)
    {
        try {
            for (const T &element: queue) {
                this->pushBack(element);
            }
        }
        catch (...){
            while(!isEmpty())
                popFront();
            throw;
        }
    }

    /*
    * Operator =
    *
    * @param queue- the queue to be copied
    * @return
    *      reference to a new Queue
    */
    Queue& operator=(const Queue<T>& queue)
    {
        if (this == &queue){
            return *this;
        }
        Queue<T>* queue1 = new Queue<T>();

        try {
            for (const T &element: queue) {
                queue1->pushBack(element);
            }
        }
        catch (...){
            delete queue1;
            throw;
        }
        while (!isEmpty())
        {
            this->popFront();
        }
        this->m_first = queue1->m_first;
        this->m_counter = queue1->m_counter;
        this->m_last = queue1->m_last;
        queue1->m_counter = 0;
        delete queue1;
        return *this;
    }


    /*
    * pushes a new element to the queue
    *
    * @param element- the element to be pushed
    * @return
    *      void
    */
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

    /*
    * return the first element in the queue by referene
    *
    * @param
    * @return
    *      reference to the first element in the queue
    */
    T& front() const
    {
        if (isEmpty()) {
            throw EmptyQueue();
        }
        return m_first->getData();
    }

    /*
    * delete the first element in the queue
    *
    * @param
    * @return
    *     void
    */
    void popFront()
    {
        if ( isEmpty() ){
            throw EmptyQueue();
        }
        if (m_first == nullptr){
            return;
        }
        Node<T>* tmp = m_first;
        m_first = m_first->getNext();
        m_counter--;
        delete tmp;
    }

    /*
    * return the number of elements in the queue
    *
    * @param
    * @return
    *      the size of the queue
    */
    int size() const
    {
        return m_counter;
    }

    /*
    * return if the queue has at least 1 element
    *
    * @param
    * @return
    *      type bool if the queue has at least 1 element
    */
    bool isEmpty() const
    {
        return m_counter == 0;
    }

    /*
    * return a new queue that contains only the elements that was filtred
     * in the condition method
    *
    * @param queue- the queue to be filtred
     * @param condition - the method that filters the elements
    * @return
    *      new filtered Queue object
    */
    template<class P, class Condition>
    friend Queue<P> filter(Queue<P> queue,Condition condition);

    /*
   * changes the elements of queue by sending it to operation
   *
   * @param queue- the queue to be changed
    * @param operation - the method that changes the elements
   * @return
   *      void
   */
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
    Iterator(const Iterator&) = default;

    Iterator& operator=(const Iterator&) = default;

    ~Iterator() = default;
    class InvalidOperation {};

    T& operator*() const
    {
        if(!(m_queue->isEmpty()) && (&m_current))
        {
            return m_current->getData();
        }
        throw InvalidOperation();
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
    ConstIterator(const ConstIterator&) = default;

    ConstIterator& operator=(const ConstIterator&) = default;

    ~ConstIterator() = default;

    class InvalidOperation {};

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
