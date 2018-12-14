#pragma once
#include "Sequence.h"
#include "CodonsTable.h"
#include "DNA.h"
#include "protein.h"

enum RNA_Type { mRNA, pre_mRNA, mRNA_exon, mRNA_intron };
class DNA;
class Protein;

class RNA : public Sequence
{
private:
	RNA_Type type;

public:
	// Constructors And Destructor.
	RNA();
	RNA(char* sent_sequence, const RNA_Type& sent_type, const int& sent_length);
	RNA(int* sent_sequence, const RNA_Type& sent_type, const int& sent_length);
	RNA(const RNA& rhs);
	~RNA();
    // Setters.
	void setType(RNA_Type x);
	void setRNASeq(char* arr, int sent_length);
	// Operators Overloading.
	void operator= (RNA sent_RNA);
    bool operator== (RNA sent_RNA);
    bool operator!= (RNA sent_RNA);
    RNA operator+ (RNA sent_RNA);
	friend istream& operator>> (istream& in, RNA& sent_sequence);
	friend ostream& operator<< (ostream &out, RNA sent_sequence);
	// Function That Convert The RNA To Protein.
	Protein ConvertToProtein(CodonsTable table);
	// function to convert the RNA sequence back to DNA
	DNA ConvertToDNA();
};
