#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <person.h>
#include <iostream>
#include <string>
using namespace std;
#define PRIME_SIZE 100

template <class K>
class HashTable
{
private:
    Person<K> * table[PRIME_SIZE];
    int persons_number;

    // Считает сумму ASCII кодов, делит на константу и получает остаток от деления
    static int hash (K str)
    {
        int ascii_sum = 0;
        for (auto s: str)
        {
            ascii_sum += s;
        }
        return ascii_sum % PRIME_SIZE;
    }

public:
    HashTable();
    HashTable(HashTable * other);
    ~HashTable();
    void delete_all();
    K get_key(const K) const;
    int get_value(const K) const;
    int get_keys_number() const;
    bool operator==(const HashTable<K> & other) const;
    void operator<<(const K);
    void delete_key(const K);
    int operator[](const K) const;
    bool key_existence(const K) const;
    K min_value_key() const;
    K max_value_key() const;
    void read_file(const string);
    void save_file(const string) const;
    K next_key(const string) const;

};

#include <hash_table.inl>
#endif // HASHTABLE_H
