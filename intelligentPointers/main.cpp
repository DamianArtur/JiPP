#include <iostream>

using namespace std;

class MyClass {

public:
    MyClass() {
        cout << "Konstruktor" << endl;
    }

    ~MyClass(){
        cout << "Destruktor" << endl;
    }
};

template<typename T>
class mySharedPointer {

private:
    int* count;
    T* value;

public:
    mySharedPointer(T* obj){
        value = obj;
        count = new int(1);
    }

    mySharedPointer(const mySharedPointer<T> &obj){
        count = obj.count;
        value = obj.value;
        (*count)++;
    }

    void operator=(T* obj){
        value = obj;
        count = new int(1);
    }

    int use_count(){
        return *count;
    }

    T* operator*(){
        return value;
    }

    ~mySharedPointer(){
        (*count)--;
        if(*count == 0){
            delete count;
            delete value;
        }
    }
};

template <typename T> class myUniquePointer {

private:
    T *ptr;

public:
    myUniquePointer<T>(T *p) : ptr(p) {}

    void operator=(T *p) {
        if (ptr != NULL) {
            delete ptr;
        }
        ptr = p;
    }

    T *operator*() {
        return this->ptr;
    }

    ~myUniquePointer() {
        delete this->ptr;
    }
};

int main() {
        mySharedPointer<MyClass> ptr = new MyClass();
        cout << ptr.use_count() << endl;
        {
            mySharedPointer<MyClass> ptr2 = ptr;
            cout << ptr.use_count() << endl;
            cout << ptr2.use_count() << endl;
        }
        cout << ptr.use_count() << endl;
    return 0;
}