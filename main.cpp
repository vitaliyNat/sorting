#include <iostream>
#include <cmath>
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
dynamicArray<T> * countingSort(dynamicArray<T> * arr){
    T max = *arr->index(0);
    T min = *arr->index(0);
    for(int i =0; i < arr->length; i++){
         T temp = *arr->index(i);
         if(maxHepify(temp,max)){
            max = temp;
         }
         if(maxHepify(min,temp)){
             min = temp;
         }
    }
    auto * newArr = new dynamicArray<int>();
    for(int i = 0; i<=max;i++){
        newArr->add(0);
    }

    for(int i = 0; i< arr->length;i++){
        int temp = * arr->index(i);
        int count = * newArr->index(temp);
        count = count +1;
        newArr->change(temp,count);
    }


    auto * resultArray = new dynamicArray<T>();


    for(int i = 0; i< newArr->length;i++){
        for(int j = 0; j < *newArr->index(i);j++){
            resultArray->add(i);
        }
    }


    return resultArray;
}


template <class T>
void bucketSort(dynamicArray<T> * arr){
    T max = *arr->index(0);
    T min = *arr->index(0);
    for(int i =0; i < arr->length; i++){
        T temp = *arr->index(i);
        if(maxHepify(temp,max)){
            max = temp;
        }
        if(maxHepify(min,temp)){
            min = temp;
        }
    }


    auto * bucket = new dynamicArray<dynamicArray<T>>();
    int bucketCount = ceil((max-min)/10);

    for(int i = 0; i<=bucketCount;i++){
        bucket->add(* new dynamicArray<T>());
    }

    for(int i = 0; i<arr->length;i++){
        T temp = * arr->index(i);
        int numbBucket = floor((temp-min)/10);
        bucket->index(numbBucket)->add(temp);
    }
    int l = 0;
    for(int i  = 0; i <=bucketCount; i++){
        bucket->index(i)->sort(maxHepify);
        for(int j = 0; j<bucket->index(i)->length; j++){
            arr->change(l, *bucket->index(i)->index(j));
            l++;
        }
    }


}
template <class T>
T getRandom(){
    return rand() % 1000;
}
int main() {
    auto *  ar1 = new dynamicArray<int>();
    for(int i = 10;i>0;i--){
        ar1->add(i);
    }

    auto *  array2 = new dynamicArray<int>();
    for(int i = 10;i>0;i--){
        array2->add(i);
    }
    for(int i = 0; i < 10;i++){
        ar1->add(i);
    }

    auto *  ar3 = new dynamicArray<int>();
    for(int i = 100;i>0;i-=5){
        ar3->add(getRandom<int>());
    }
    //ar3->toString();

    auto * countsort = countingSort(ar1);
    bucketSort(ar3);
    auto * heap = new Heap<int>(array2);
   //array2->toString();
    //cout<< "counting sort: " << endl;
    //countsort->toString();
    cout<<"Bucket Sort"<<endl;
    ar3->toString();
    return 0;
}
