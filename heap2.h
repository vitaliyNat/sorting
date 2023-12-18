#include <iostream>
#include <chrono>

using namespace std;



template <class T>
bool maxHepify(T first, T second){
    return first > second;
}
template <class T>
bool minHepify(T first, T second){
    return !(first > second);
}




template <class T>
class dynamicArray{
private:
    int size;
    T * head;
    float grow = 1.5;
public:
    int length;

    dynamicArray(){
        head = new T[5];
        size = 5;
        length = 0;
    }


    bool checkSize(){
        return size*0.8 < length;
    }

    void add(T value){
        if(checkSize()) growSize();
        head[length]= value;
        length++;
    }

    void growSize(){
        size= size*grow;
        auto *newHead = new T[size];

        for(int i = 0; i<length;i++){
            newHead[i] = head[i];
        }
        delete [] head;
        head = newHead;
    }


    void clear(){
        delete [] head;
        length = 0;
        size = 5;
        head = new T[size];
    }

    T  operator [] (int index) {

        if(length<= index){
            //  cout<<"Index out of range!";
            return -1;
        }
        return head[index];

    }

    T  * index(int index){
        if(length<= index){
            //  cout<<"Index out of range!";
            return nullptr;
        }
        return &head[index];
    }

    T index2(int index){
        return head[index];
    }

    void change(int index, T newValue){
        if(length<= index){
            cout<<"Index out of range!";
            return;
        }
        head[index] = newValue;

    }
    void deleteLast(){
        if(length){
            length--;
        }else{
            clear();
        };
    }


    void toString(){
        cout<<"Size: "<< size<< ". Length: "<<length<<endl;
        for(int i = 0; i<length; i++){
            cout<<"Value: "<< head[i]<<endl;
        }
    }
    void toStringShort(){
        cout<<"Size: "<< size<< ". Length: "<<length<<endl;
        cout << "First element: "<< head[0]<< ". Last element: " << head[length-1]<<endl;
    }
    int getSize(){
        return this->size;
    }

    void sort(bool (*cmp)(T,T)){
        for(int i = 0; i<length;i++){
            for(int j = 0; j<length-i-1; j++){
                if(cmp(head[j],head[j+1])){
                    int temp = head[j];
                    head[j] =  head[j+1];
                    head[j+1] = temp;
                }
            }
        }
    }
};

template <class T>
class Heap{
private:
    dynamicArray<T>  *array;
    int size;
    T * getParent(int index){
        return array->index(((index-1)/2));
    }
    T * getLeft(int index){
        return array->index((index * 2)+1);
    }
    T * getRight(int index){
        return array->index((index * 2)+2);
    }
    void swap(T & value1, T & value2){
        auto temp =value1;
        value1 = value2;
        value2 = temp;
    }



    void heapifyUp(int index,bool (*cmp)(T,T)){

        T *left = getLeft(index);
        T *right = getRight(index);
        T *max = getIndex(index);
        if(left && right){
            if (cmp(*right, *left) && cmp(*right, *max)) {
                swap(*right, *max);
            }else
            if (cmp(*left, *right) && cmp(*left, *max)) {
                swap(*left, *max);
            }}else{
            if(right && cmp(*right, *max)){
                swap(*right, *max);
            }else if(left && cmp(*left, *max)){
                swap(*left, *max);
            }
        }

        if(index !=0) {
            heapifyUp((index-1)/2, cmp);
        }

    }
    void heapifyDown(int index,bool (*cmp)(T,T)){

        T *left = getLeft(index);
        T *right = getRight(index);
        T *max = getIndex(index);
        int temp;
        if(left && right){
            if (cmp(*right, *left) && cmp(*right, *max)) {
                swap(*right, *max);
                temp = index*2+2;
            }else
            if (cmp(*left, *right) && cmp(*left, *max)) {
                swap(*left, *max);
                temp = index*2+1;
            }}else{
            if(right && cmp(*right, *max)){
                swap(*right, *max);
                temp = index*2+2;
            }else if(left && cmp(*left, *max)){
                swap(*left, *max);
                temp = index*2+1;
            }
        }

        if(array->index(temp)) {
            heapifyDown(temp, cmp);
        }

    }
public:
    Heap(){
        array = new dynamicArray<T>();
        size = 0;
    }

    Heap(dynamicArray<T> * arr){
        array = new dynamicArray<T>();
        size = 0;
        for(int i = 0; i<arr->length;i++){
            this->add(arr->index2(i), minHepify);
        }
        for(int i = 0; i<arr->length;i++){
            T temp = this->deleteFirst(minHepify);
            arr->change(i,temp);
        }
    }
    T * getIndex(int index){
        return array->index(index);
    }
    void add(T value,bool (*cmp)(T,T)){
        array->add(value);
        size++;
        heapifyUp(array->length-1,cmp);
    }
    void toString(){
        array->toString();
    }
    void clear(){
        array->clear();
        size = 0;
    }
    T  deleteFirst(bool (*cmp)(T,T)){

        T *temp = array->index(0);
        T value = *temp;
        swap(*array->index(0),*array->index(size-1));
        size--;
        if(size == 0){
            clear();
        }
        array->deleteLast();
        heapifyDown(0,cmp);

        return value;
    }

};


