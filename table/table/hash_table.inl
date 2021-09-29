#include "hash_table.h"
#include <climits>
#include <fstream>
#include <sstream>
#include "qerrormessage.h"

template <typename K>
HashTable<K>::HashTable()
{
     for (int i = 0; i < PRIME_SIZE; i++)
     {
         Person<K> * current;
         current = new Person<K>();
         this->table[i] = current;
     }
     persons_number = 0;
};

template <typename K>
HashTable<K>::HashTable(HashTable * other)
{
    for (int i = 0; i < PRIME_SIZE; i++)
    {
        Person<K> * current;
        current = new Person<K>();
        this->table[i] = current;
        this->table[i]->copy(other->table[i]);
    }
    persons_number = other->persons_number;
}

template <typename K>
HashTable<K>::~HashTable()
{
    for (int i = 0; i < PRIME_SIZE; i++)
    {
        this->table[i]->~Person();
        delete this->table[i];
    }
};

template <typename K>
void HashTable<K>::delete_all()
{
    for (int i = 0; i < PRIME_SIZE; i++)
        this->table[i]->delete_all_employees();
    persons_number = 0;
}

template <typename K>
K HashTable<K>::get_key(const K name) const
{
    return table[hash(name)]->get_name();
}

template <typename K>
int HashTable<K>::get_value(const K name) const
{
    return table[hash(name)]->get_mistakes(name);
}

template <typename K>
int HashTable<K>::get_keys_number() const
{
    return persons_number;
}

template <typename K>
bool HashTable<K>::operator==(const HashTable<K> &other) const
{
    bool flag = true;
    K this_name;
    K other_name;
    for (int i = 0; i < PRIME_SIZE; i++)
    {
        this_name = this->table[i]->get_name();
        other_name = other.table[i]->get_name();
        if(table[i]->get_name() != other.table[i]->get_name() ||
                table[i]->get_mistakes(this_name) != other.table[i]->get_mistakes(other_name))
            flag = false;
    }
    return flag;
}

template <typename K>
void HashTable<K>::operator<<(const K name)
{
    bool flag = false;
    for (int i = 0; i < PRIME_SIZE; i++)
        if(table[i]->get_name() == name)
        {
            table[hash(name)]->increase_mistakes(name);
            flag = true;
        }
    if(flag == false)
    {
        table[hash(name)]->add_employee(name);
        persons_number++;
    }
}

template <typename K>
void HashTable<K>::delete_key(const K name)
{
    int i = hash(name);
    if(table[i]->get_first() != nullptr)
    {
        table[i]->delete_pair(name);
        if(table[i]->get_first() == nullptr)
            persons_number--;
    }
}

template <typename K>
int HashTable<K>::operator[](const K try_name) const
{
    return table[hash(try_name)]->get_mistakes(try_name);
}

template <typename K>
bool HashTable<K>::key_existence(const K name) const
{
    int i = hash(name);
    if(table[i]->get_first() != nullptr)
        return table[i]->existence(name);
    else
        return false;
}

template <typename K>
K HashTable<K>::min_value_key() const
{
    int min_mistakes = INT_MAX;
    K min_name = "";
    for (int i = 1; i < PRIME_SIZE; i++)
        if(table[i]->get_first() != nullptr)
            if(table[i]->get_min_mistakes()->mistakes < min_mistakes)
            {
                min_name = table[i]->get_name();
                min_mistakes = table[i]->get_mistakes(min_name);
            }
    return min_name;
}

template <typename K>
K HashTable<K>::max_value_key() const
{
    int max_mistakes = 0;
    K max_name = "";
    for (int i = 1; i < PRIME_SIZE; i++)
        if(table[i]->get_first() != nullptr)
            if(table[i]->get_max_mistakes()->mistakes >= max_mistakes)
            {
                max_name = table[i]->get_name();
                max_mistakes = table[i]->get_mistakes(max_name);
            }
    return max_name;
}

template <typename K>
void HashTable<K>::read_file(const string path)
{
    string line;
    K name;
    string mistakes;
    int int_mistakes = 0;
    string::size_type i;
    ifstream in(path);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            i = line.find(" ");
            name = line.substr(0, i);
            mistakes = line.substr(i+1);
            line.clear();
            stringstream geek(mistakes);
            geek >> int_mistakes;
            int int_hash = hash(name);
            for(int j=0; j<=int_mistakes; j++)
                table[int_hash]->add_employee(name);
            persons_number++;
            name.clear();
            mistakes.clear();
            line.clear();
        }
    }
    else
        (new QErrorMessage())->showMessage("No file was chosen to read");
    in.close();
}

template <typename K>
void HashTable<K>::save_file(const string path) const
{
    std::ofstream out;
    out.open(path);
    if (out.is_open())
    {
    for (int i = 0; i < PRIME_SIZE; i++)
        table[i]->save_file(out);
    (new QErrorMessage())->showMessage("Saving completed");
    }
    else
        (new QErrorMessage())->showMessage("No file was chosen to save");
}

template <typename K>
K HashTable<K>::next_key(string previous_key) const
{
    int i;
    if(previous_key == "")
        i = 1;
    else
        i = hash(previous_key) + 1;
    while(i < PRIME_SIZE)
        if(this->table[i]->get_first() != nullptr)
            return table[i]->get_name();
        else
            i++;
    return 0;
}
