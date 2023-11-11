#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>

template <class T>
class Heap{
    private:
        T *data;
        unsigned int size, count;

    public:
        Heap( unsigned int);
        ~Heap();

        unsigned int parent( unsigned int pos) const { return pos / 2; }
        unsigned int left( unsigned int pos) const { return pos * 2; }
        unsigned int right( unsigned int pos) const { return pos * 2 + 1; }
        bool empty() const { return (count == 0); }
        bool full() const { return (count == size); }
        T top() { return data[0]; }


        void push(T);
        T pop();

        void heapify( unsigned int);
        void swap( unsigned int, unsigned int);
        void heapsort();

};

template <class T>
Heap<T>::Heap( unsigned int sze) : size(sze + 1), data(nullptr), count(0){
    data = new T[size];
    if (data == 0) {
        std::cerr << "OutOfMemory()" << std::endl;
    }
}

template <class T>
Heap<T>::~Heap(){
    delete [] data;
    data = 0;
    size = count = 0;
}

template <class T>
void Heap<T>::push(T val) {
    if (full()) {
        std::cerr << "Overflow()" << std::endl;
        return;
    }

    unsigned int pos = count;
    data[pos] = val;

    while (pos > 0 && val < data[parent(pos)]){
        swap(pos, parent(pos));
        pos = parent(pos);
    }

    count++;
}

template <class T>
T Heap<T>::pop() {
    if(empty()){
        std::cerr << "NoSuchElement()" << std::endl;
    }

    T aux = data[0];
    data[0] = data[--count];
    heapify(0);

    return aux;
}

template <class T>
void Heap<T>::heapify( unsigned int pos){
    unsigned int small = pos;
    unsigned int lef = left(pos);
    unsigned int rig = right(pos);
    if( lef <= count && data[lef] < data[small])
        small = lef;
    if( rig <= count && data[rig] < data[small])
        small = rig;
    if( small != pos) {
        swap(pos, small);
        heapify(small);
    }
}

template <class T>
void Heap<T>::swap( unsigned int i, unsigned int j){
    T aux = data[i];
    data[i] = data[j];
    data[j] = aux;
}

template <class T>
void Heap<T>::heapsort(){
    for( int i = count /2 - 1; i >= 0; i--) heapify(i);
    for( int i = count - 1; i > 0; i--){
        swap(0, i);
        heapify(i);
    }
}

#endif