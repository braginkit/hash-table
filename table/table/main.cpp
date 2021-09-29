#include <iostream>
#include <string>
#include <person.h>
#include "hash_table.h"
#include <assert.h>
#include "mainwindow.h"
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    //HashTable<string> One;
    //assert(One.get_keys_number() == 0);
    //One<<"123";
    //assert(One.get_keys_number() == 1);
    //One<<"123";
    //assert(One.get_keys_number() == 1);
    //assert(One.get_value("123") == 1);
    //assert(One.key_existence("123") == true);
    //assert(One["123"] == 1);
    //One.delete_key("123");
    //assert(One.get_keys_number() == 0);
    //assert(One.key_existence("123") == false);
    //One.delete_key("555");
    //assert(One.get_keys_number() == 0);

    //HashTable<string> Two;
    //Two<<"123";
    //Two<<"123";
    //Two<<"Dog";
    //Two.delete_all();
    //HashTable<string> Three;
    //assert(Two==Three);

    //HashTable<string> Four;
    //Four<<"123";
    //Four<<"123";
    //Four<<"Dog";
    //HashTable<string> Five(&Four);
    //assert(Five==Four);

    //Four<<"Dog";
    //assert(!(Five==Four));

    //HashTable<string> Six;
    //Six<<"1234";
    //Six<<"2345";
    //Six<<"2345";
    //Six<<"cat";
    //Six.save_file("C:\\test\\test.txt");
    //HashTable<string> Seven;
    //Seven.read_file("C:\\test\\test.txt");
    //assert(Six==Seven);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    //cout<<"So far, so good..";

}
