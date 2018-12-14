#pragma once

#include<iostream>
#include<string>
using namespace std;

class Sequence
{

protected:
    int length;
    char* seq;

public:
    // constructors and destructor.
    Sequence();
    Sequence(const int& sent_length);
    Sequence(const Sequence& rhs);
    virtual ~Sequence();
    // Setters.
    void SetLength(const int& sent_length);
    void SetData(char* sent_sequence, const int& sent_length);
    void SetData(int *arr, const int& sent_length);
    void SetSeq(char* sent_sequence);
    // Getters.
    char* getSeq() const;
    int getLength() const;
    // Operators Overloading.
	void operator= (const Sequence& rhs);
    friend istream& operator>> (istream& in, Sequence& sent_sequence);
    friend ostream& operator<< (ostream& out, const Sequence& sent_sequence);
    // friend function that will find the LCS (longest common
    // subsequence) between 2 sequences of any type, according to
    // polymorphism.
    friend void Align(char*first_sequence, char* second_sequence,int size1,int size2);
};

