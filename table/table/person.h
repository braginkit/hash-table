#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

template <typename K>
class Person
{
private:
    struct employee
    {
        K name;
        int mistakes;
        employee * next;
    };
    employee * first;
    employee * last;
public:
    Person();
    ~Person();
    void add_employee(const K);
    void delete_all_employees();
    void copy(Person<K> * other);
    K get_name() const;
    int get_mistakes(const K) const;
    void increase_mistakes(const K);
    void delete_pair(const K);
    employee * get_first() const;
    bool existence(const K) const;
    employee * get_min_mistakes() const;
    employee * get_max_mistakes() const;
    void save_file(ofstream&);

};

#include <person.inl>
#endif // PERSON_H
