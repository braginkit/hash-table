#include "person.h"
#include <climits>

template <typename K>
Person<K>::Person()
{
    this->first = nullptr;
    this->last = nullptr;
}

template <typename K>
Person<K>::~Person()
{
    this->delete_all_employees();
    delete first;
    delete last;
}

template <typename K>
void Person<K>::add_employee(const K new_name)
{
    employee * tmp;
    tmp = first;
    bool flag = false;
    while(tmp != nullptr && flag == false)
    {
        if(tmp->name == new_name)
        {
            tmp->mistakes++;
            flag = true;
        }
        else
            tmp = tmp->next;
    }
    if(flag == false)
    {
        employee * current = new employee;
        current->name = new_name;
        current->mistakes = 0;
        current->next = nullptr;
        if(first == nullptr)
        {
            first = current;
            last = current;
        }
        else
        {
            last->next = current;
            current->next = nullptr;
            last = current;
        }
    }
}

template <typename K>
void Person<K>::delete_all_employees()
{
    employee * current = first;
    while(first != nullptr)
    {
        current = first;
        first = first->next;
        current->name.clear();
        delete current->next;
    }
    current = nullptr;
    delete current;
    first = nullptr;
    last = nullptr;
}

template <typename K>
void Person<K>::copy(Person<K> * other)
{
    employee * current;
    current = other->first;
    while(current != nullptr)
    {
        employee * add = new employee;
        add->name = current->name;
        add->mistakes = current->mistakes;
        add->next = nullptr;
        if(first == nullptr)
        {
            first = add;
            last = add;
        }
        else
        {
            last->next = add;
            last = add;
        }
        current = current->next;
    }
}

template <typename K>
K Person<K>::get_name() const
{
    if(first != nullptr)
        return first->name;
    else
        return "";
}

template <typename K>
int Person<K>::get_mistakes(const K try_name) const
{
    employee * current;
    current = first;
    while(current != nullptr)
    {
        if(current->name == try_name)
            return current->mistakes;
        else
            current = current->next;
    }
    return 0;
}

template <typename K>
void Person<K>::increase_mistakes(const K try_name)
{
    employee * current;
    current = first;
    bool done = false;
    while(current != nullptr && done == false)
    {
        if(current->name == try_name)
        {
            current->mistakes++;
            done = true;
        }
        else
            current = current->next;
    }
}

template <typename K>
void Person<K>::delete_pair(const K try_name)
{
    employee * current;
    employee * previous;
    current = first;
    previous = first;
    bool done = false;
    while(current != nullptr && done == false)
    {
        if(current->name == try_name)
        {
            if(previous == first)
            {
                first = first->next;
                current->name.clear();
                delete current->next;
                done = true;
            }
            else
            {
                previous->next = current->next;
                current->name.clear();
                delete current->next;
                done = true;
            }
        }
        else
        {
            current = current->next;
            if(previous != first)
                previous = previous->next;
        }
    }
}

template <typename K>
typename Person<K>::employee * Person<K>::get_first() const
{
    return first;
}

template <typename K>
bool Person<K>::existence(const K try_name) const
{
    employee * current;
    current = first;
    while(current != nullptr)
    {
        if(current->name == try_name)
            return true;
        else
            current = current->next;
    }
    return false;
}

template <typename K>
typename Person<K>::employee * Person<K>::get_min_mistakes() const
{
    employee * current;
    employee * min;
    min = last;
    current = first;
    int min_mistakes = last->mistakes;
    while(current != nullptr)
    {
        if(current->mistakes < min_mistakes)
        {
            min_mistakes = current->mistakes;
            min = current;
        }
        current = current->next;
    }
    return min;
}

template <typename K>
typename Person<K>::employee * Person<K>::get_max_mistakes() const
{
    employee * current;
    employee * max;
    max = last;
    current = first;
    int max_mistakes = last->mistakes;
    while(current != last)
    {
        if(current->mistakes > max_mistakes)
        {
            max_mistakes = current->mistakes;
            max = current;
        }
        current = current->next;
    }
    return max;
}

template <typename K>
void Person<K>::save_file(ofstream & out)
{
    employee * current;
    current = first;
    if(first != nullptr)
        while(current != nullptr)
        {
            out << current->name << " " << current->mistakes << endl;
            current = current->next;
        }
}







