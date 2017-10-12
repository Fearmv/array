#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Animal {
public:
    virtual string speak() const = 0;
};


class Cat:public Animal {
public:
    virtual string speak() const;
};


//determines what our object will do when called on in the array;
//Cat goes meow; dog goes bark
string Cat::speak() const{
    return "Meow. ";
}

class Dog:public Animal {
public:
    virtual string speak() const;
};

string Dog::speak() const{
    return "Bark. ";
}

//new template class, will have to use template header in other functions
template <class T>
class Array {
public:
    Array(int size);
    ~Array();
    T & operator[](int i) const;
    int size() const;
    void fill(int k);
    T * begin();
    T * end();
    
private:
    int len;
    T * data;
};

//default constructor, how its made
template <class T>
Array<T>::Array(int size) {
    len = size;
    data = new T[size];
}
//deconstructor, deletes the data that it is pointing to
template <class T>
Array<T>::~Array() {
    delete [] data;
}
//returns the index, with "i" being selected variable for the data,
//if data points to an array, it will return the element
template <class T>
T & Array<T>::operator[](int i) const{
    return data[i];
}

template <class T>
int Array<T>::size() const{
    return len;
}
//going to read every spot in the array, going through the len, and setting it to "k"
template <class T>
void Array<T>::fill(int k) {
    for (int i = 0; i < len ; i++) {
        data[i] = k;
    }
}
//a pointer that is going to point at the beginning of the array
template <class T>
T * Array<T>::begin() {
    return data;
}
//the end is refering to the whole array, and its going to go up to  start at data (the first spot)
//and reads to len, which is to the end
template <class T>
T * Array<T>::end() {
    return data + len;
}

int main(int argc, char * args[]) {
    
    //in array spot 0 is dog and spot 1 is cat
    //a Bark, with a meow on next line according to our code
    Array <Animal *> d(2);
    d[0] = new Dog();
    d[1] = new Cat();
    
    cout << d[0] -> speak() << endl;
    cout << d[1] -> speak() << endl;
    
}
