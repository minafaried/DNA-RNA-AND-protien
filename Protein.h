#pragma once
#include "Sequence.h"
#include"DNA.h"
#include"CodonsTable.h"
#include"RNA.h"
class CodonsTable;
class Sequence;

enum Protein_Type { Hormon, Enzyme, TF, Cellular_Function };

class DNA;
class RNA;

class Protein : public Sequence
{
private:
	Protein_Type type;
public:
	// constructors and destructor
	Protein();
	Protein(char* sent_protein, int sent_length);
	Protein(int* sent_protein, int sent_length);
    Protein(const Protein& rhs);
	~Protein();
	//setter
	void setType(Protein_Type x);
	// Getters.
	char *getSeq();
	// return an array of DNA sequences that can possibly
	// generate that protein sequence
    DNA* GetDNAStrandsEncodingMe(DNA& bigDNA, int& sizee);
    // Overloading Operators.
	void operator= (Protein sent_protein);
    bool operator== (Protein sent_protein);
	bool operator!= (Protein sent_protein);
	Protein operator+ (Protein sent_protein);
	friend istream& operator >> (istream& in, Protein& sent_sequence);
	friend ostream& operator<< (ostream &out, Protein sent_sequence);

};
