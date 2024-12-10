#include <cassert>
#include<iostream>
using namespace std;

template <typename T>
class Node
{
    public: 
        T val;
        Node* next;
        Node* prev;
        int level;

        Node(T x)
        {
            level = 0;
            val = x;
            next = nullptr;
            prev = nullptr;
        }
};

template<typename T>
class Queue{
    public:
    Node<T>* head=nullptr;
    Node<T>* tail=nullptr;
    Queue(){
        head=nullptr;
        tail=nullptr;
    }

    Queue(T x){
        tail = new Node(x);
        head = new Node(x);
    }

    void enqueue(T x){
         Node<T>* help = new Node(x);
        if(tail == nullptr){
            tail = help;
            head = help;
            return;
        }
        tail -> next = help;
        tail = help;
        if(head == nullptr){
            head = help;
        }
    }

    T dequeue(){
        assert(head!=nullptr);
        Node<T>* help = head;
        head = head-> next;
        T store = help->val;
        delete(help);
        return store;
    }

    T front(){
        assert(head!=nullptr);
        return head->val;
    }

    T rear(){
        assert(tail!=nullptr);
        return tail->val;
    }

    bool isEmpty(){
        if(head == nullptr){
            return true;
        }
        return false;
    }
};

template <typename T>
class Deque
{
    public:
    Node<T>* head=nullptr;
    Node<T>* tail=nullptr;
    Deque(){
        head=nullptr;
        tail=nullptr;
        
    }

    Deque(T x){
        tail = new Node(x);
        head = new Node(x);
        head -> prev = tail;
    }

    void push_back(T x){
         Node<T>* help = new Node(x);
        if(tail == nullptr){
            tail = help;
            head = help;
            return;
        }
        tail -> next = help;
        help -> prev = tail;
        tail = help;
        if(head == nullptr){
            head = help;
        }
    }

     void push_front(T x){
         Node<T>* help = new Node(x);
        if(head == nullptr){
            tail = help;
            head = help;
            return;
        }
        head -> prev = help;
        help -> next = head;
        head = help;
        if(head == nullptr){
            head = help;
        }
    }

    T pop_front(){
        assert(head!=nullptr);
        Node<T>* help = head;
        head = head->next;
        T store = help->val;
        if(head == nullptr){
            tail = nullptr;
        }
        delete(help);
        return store;
    }

    T pop_back(){
        assert(tail!=nullptr);
        Node<T>* help = tail;
        tail = tail->prev;
        T store = help->val;
        if(tail == nullptr){
            head = nullptr;
        }
        delete(help);
        return store;
    }

    T front(){
        assert(head!=nullptr);
        return head->val;
    }

    T rear(){
        assert(tail!=nullptr);
        return tail->val;
    }

    bool isEmpty(){
        if(head == nullptr&&tail==nullptr){
            return true;
        }
        return false;
    }
    // Your deque implementation here

};

template<typename T>
class PriorityQueue
{
    public:
    Node<T>* head=nullptr;
    Node<T>* tail=nullptr;
    PriorityQueue(){
        head=nullptr;
        tail=nullptr;
    }

    PriorityQueue(T x,int level){
        head = new Node(x);
        head-> level = level;
    }

    void push(T x,int levels){
         Node<T>* help = new Node(x);
         help->level = levels;
        if(head == nullptr){
            head = help;
            return;
        }
        if(tail == nullptr){
            tail = help;
            tail->prev = head;
            head -> next = tail;
            return;
        }

        bool newhead = 0;
         while(tail-> level > help-> level){
            if(tail->prev == nullptr){
                newhead = 1;
                break;
            }
            tail = tail->prev;
         }

         if(newhead){
            help -> next = head;
            head->prev = help;
            head = head->prev;
         }else{
            Node<T>* temp = tail->next;
            tail -> next = help;
            help -> next = temp;
            help -> prev = tail;
            if(temp!=nullptr) temp -> prev = help;
         }

         while(tail->next !=nullptr){
            tail=tail->next;
         }
         
    }

    T pop(){
        assert(head!=nullptr);
        Node<T>* help = head;
        head = head-> next;
        T store = help->val;
        if(head == nullptr){
            tail = nullptr;
        }
        delete(help);
        return store;
    }

    T peek(){
        assert(head!=nullptr);
        return head->val;
    }

    int levelpeek(){
        assert(head!=nullptr);
        return head->level;
    }

    bool isEmpty(){
        if(head == nullptr){
            return true;
        }
        return false;
    }
    
    // Your priority queue implementation here
};
