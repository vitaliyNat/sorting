#include <iostream>
#include "heap2.h"
//template <class T>
//dynamicArray<T>* HeapSort(dynamicArray<T> * array){
//    auto * heap = new Heap<T>();
//    for(int i = 0; i<array->length;i++){
//        heap->add(array->index2(i), minHepify);
//    }
//    for(int i = 0; i<array->length;i++){
//        T temp = heap->deleteFirst(minHepify);
//        array->change(i,temp);
//    }
//    return array;
//
//}

template <class T>
T getRandom(){
    return rand() % 1000;
}
int main() {
    auto *  arr = new dynamicArray<int>();
    for(int i = 10;i>0;i--){
        arr->add(getRandom<int>());
    }
    arr->add(1);

    auto * heap = new Heap<int>(arr);
    arr->toString();
    return 0;
}
