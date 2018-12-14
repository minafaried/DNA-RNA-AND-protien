#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include <cstdlib>

using namespace std;
struct Codon
{
	char value[4];    	    // 4th location for null character
	char AminoAcid;  	    // corresponding AminoAcid according to Table
};

// need to create one object of that class to load the AminoAcids table
// into memory
class CodonsTable
{
private:

public:
    Codon codons[64];
	// constructors and destructor
	CodonsTable();
	~CodonsTable();
	// function to load all codons from the given text file
	void LoadCodonsFromFile(string codonsFileName);//RNA_codon_table
	Codon getAminoAcid(char* values);
	void setCodon(char* value, char AminoAcid, const int& index);
};

