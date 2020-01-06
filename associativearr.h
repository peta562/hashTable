#ifndef ASSOCIATIVEARR_H
#define ASSOCIATIVEARR_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <QMainWindow>
#include <QTextEdit>


using namespace std;


class hashEntry
{
private:
    string value;

public:
    hashEntry(string str = " ") : value{str}
    {
    }
    ~hashEntry()
    {
    }
    hashEntry(const hashEntry &hE)
    {
        value = hE.value;
    }
    void print(QTextEdit* field)
    {
        if(value != " ")
            field->setText(QString::fromStdString(value));
        else
            field->setText(QString("Not found"));
    }
    void setValue(string str)
    {
       value = str;
    }
    string getValue()
    {
        return value;
    }

    friend bool operator== (hashEntry const &a, hashEntry const &b)
    {
        return (a.value == b.value);
    }

    friend bool operator!= (hashEntry const &a, hashEntry const &b)
    {
        return !(a == b);
    }
};





template <class T>
class hashTable
{
private:
    int size;
    int cur = 0;
    vector<T> table;
    int hash(string str)
    {
        int asciisum = 0;
        for ( int i = 0; i < str.length(); i++ )
        {
            asciisum += str[i];
        }
        return asciisum % size;
    }
public:
    hashTable(int sz = 100) : size {sz}, table{sz}
    {
    }
    ~hashTable()
    {
         table.clear();
    }
    int getSize()
    {
        return size;
    }
    void push(T& obj)
    {
        cur++;
        if((static_cast<float>(cur) / size) >= 0.7)
            resizeTable();
        const int hsh = hash(obj.getValue());
        table[abs(hsh)] = obj;

    }
    int getKey(string value)
    {
        for(int i = 0; i < size; i++)
        {
            if(table[i].getValue() == value)
               return i;
        }
    }

    T& getValue(int i)
    {
        return table[i];
    }
    void resizeTable()
    {
        size = size + 20;
        table.resize(size);
    }

};

#endif // ASSOCIATIVEARR_H
