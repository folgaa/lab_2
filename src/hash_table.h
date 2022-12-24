#ifndef LAB2_2_0_HASH_TABLE_H
#define LAB2_2_0_HASH_TABLE_H

#include <iostream>
#include <iomanip>

using namespace std;

template <class T> class Hash_table
{
private:

    class Data{friend class Hash_table;
    private:

        int key{0};
        T value;
        Data* next{NULL};

        Data(int key1, T value1)
        {
            key = key1;
            value = value1;
            next = NULL;
        }
    };

    int size{10};
    int capacity{0};
    Data** items;
    float rehash = 0.6;

    int hash_func(int key);

    void rehash_table();

public:

    Hash_table()
    {
        items = new Data*[size];
        for (int i = 0; i < size; ++i)
            items[i] = NULL;
    }

    ~Hash_table()
    {
        for (int i = 0; i < size; i++) {
            Data* ptr = items[i];
            while (ptr != nullptr) {
                Data* prev = ptr;
                ptr = ptr->next;
                delete prev;
            }
        }
        delete[] items;
    }

    bool find(int key);

    void remove(int key);

    void add(int key, T value);

    void print();
};

template<typename T>
int Hash_table<T>::hash_func(int key)
{
    return key % size;
}

template<typename T>
void Hash_table<T>::rehash_table()
{
    int size0 = size;
    size = size * 2;
    capacity = 0;
    Data** new_items = new Data*[size];
    for (int i = 0; i < size; i++)
        new_items[i] = NULL;
    swap(items, new_items);
    Data* cur = NULL;
    for (int i = 0; i < size0; i++) {
        cur = new_items[i];
        while (cur != NULL) {
            add(cur->key, cur->value);
            cur = cur->next;
        }
    }
    for (int i = 0; i < size0; i++)
        if (new_items[i])
            delete new_items[i];
    delete[] new_items;
}

template<typename T>
bool Hash_table<T>::find(int key)
{
    int index = hash_func(key);
    Data* ptr = items[index];
    while (ptr != NULL)
    {
        if(ptr->key == key) return true;
        ptr = ptr->next;
    }
    return false;
}

template<typename T>
void Hash_table<T>::remove(int key)
{
    if(!find(key))
    {
        cout << "This key doesn't exist!" << endl;
        return;
    }
    capacity--;
    int index = hash_func(key);
    Data* ptr = items[index];
    if(ptr->key == key)
    {
        items[index] = ptr->next;
        delete ptr;
        return;
    }
    while(ptr->next->key != key) ptr = ptr->next;
    Data* del_ptr = ptr->next;
    ptr->next = ptr->next->next;
    delete del_ptr;
    return;
}

template<typename T>
void Hash_table<T>::add(int key, T value)
{
    if(float(capacity) > float(size) * rehash) rehash_table();
    int index = hash_func(key);
    Data* new_el = new Data(key, value);

    if(items[index] != NULL)
    {
        Data* ptr = items[index];
        if(ptr->key == key)
        {
            cout << "This key already exists!" << endl;
            return;
        }
        while(ptr->next != NULL)
        {
            if(ptr->key == key)
            {
                cout << "This key already exists!" << endl;
                return;
            }
            ptr = ptr->next;
        }
        ptr->next = new_el;
    }
    if(items[index] == NULL)
    {
        items[index] = new_el;
    }
    capacity++;
}

template<typename T>
void Hash_table<T>::print()
{
    cout << endl << endl;
    for(int i = 0; i < size; i++)
    {
        cout << i << ")  ";
        Data* ptr = items[i];
        while(ptr != NULL)
        {
            cout << setw(3) << ptr->key<< ":" << ptr->value << setw(3) << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    cout << endl << endl;
}

#endif //LAB2_2_0_HASH_TABLE_H
