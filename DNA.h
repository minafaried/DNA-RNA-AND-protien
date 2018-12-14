#pragma once
#include "Sequence.h"
#include"RNA.h"

enum DNA_Type { promoter, motif, tail, noncoding };

class RNA;
class DNA : public Sequence
{
private:
    DNA_Type type;
    char* complementary_strand;
    int startIndex;
    int endIndex;

public:
    // Constructors And Destructor.
    DNA();
    DNA(char* sent_sequence, const DNA_Type& sent_type, const int& sent_length);
	DNA(int* sent_sequence, const DNA_Type& sent_type, const int& sent_length);
    DNA(const DNA& rhs);
    ~DNA();
    // Setters.
	void setType(DNA_Type x);
    void setDna(char* sent_sequence, const DNA_Type& sent_type, const int& sent_length);
	void SetStart(int SIndex);
	void SetEnd(int EIndex);
    // Getters.
	DNA_Type getType() const;
    // Operators Overloading.
	void operator= (DNA sent_DNA);
    bool operator== (DNA sent_DNA);
    bool operator!= (DNA sent_DNA);
    DNA operator+ (DNA sent_DNA);
	friend istream& operator>> (istream& in, DNA& sent_sequence);
	friend ostream& operator<< (ostream & out, const DNA& sent_sequence);
    // function to convert the DNA sequence to RNA sequence
    // It starts by building the complementary_strand of the current
    // DNA sequence (starting from the startIndex to the endIndex), then,
    // it builds the RNA corresponding to that complementary_strand.
    RNA ConvertToRNA();
    // function to build the second strand/pair of DNA sequence
    // To build a complementary_strand (starting from the startIndex to
    // the endIndex), convert each A to T, each T to A, each C to G, and
    // each G to C. Then reverse the resulting sequence.
    void BuildComplementaryStrand();
};
