#pragma once
#include <iostream>

template < class T >
class ListNode{
    private:
        T data;
        ListNode<T>* next;
        ListNode<T>* prev;
    public:
    ListNode(T data, ListNode<T>* next=nullptr, ListNode<T>* prev=nullptr): data(data), next(next), prev(prev){}
};

template<class T>
class List{
    private:
        ListNode<T> * head;
        ListNode<T> * tail;
};