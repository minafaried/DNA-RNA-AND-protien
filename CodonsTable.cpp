#include "CodonsTable.h"


// Constructor And Destructor.
CodonsTable::CodonsTable()
{
}
CodonsTable::~CodonsTable()
{
}

void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
	fstream file(codonsFileName.c_str());
	if (file.fail())
	{
		cout << "can't open this file";
		return;
	}
	int i = 0;
	char temp[6] ;
	while (!file.eof())
	{

		file.getline(temp, 6);
		if (temp[0] == '\0')
		{
			continue;
		}
		codons[i].value[0] = temp[0];
	    codons[i].value[1] = temp[1];
		codons[i].value[2] = temp[2];
		codons[i].value[3] = '\0';

		if (temp[0] == 'U'&&temp[1] == 'A'&&temp[2] == 'A'||
			temp[0] == 'U'&&temp[1] == 'G'&&temp[2] == 'A'||
			temp[0] == 'U'&&temp[1] == 'A'&&temp[2] == 'G')
		{
			codons[i].AminoAcid = '0';
		}
		else
		{
			codons[i].AminoAcid = temp[4];
		}
		i++;
	}
}

Codon CodonsTable::getAminoAcid(char* value)
{
	bool found=false;
	Codon result;
	result.value[0] = value[0];
	result.value[1] = value[1];
	result.value[2] = value[2];
	result.value[3] = '\0';
	for (unsigned int i = 0; i < 64; i++)
	{
//		cout << value[0] << " " << codons[i].value[0];
		if (value[0] == codons[i].value[0] &&
			value[1] == codons[i].value[1] &&
			value[2] == codons[i].value[2])
		{
			result.AminoAcid = codons[i].AminoAcid;
			found = true;
			break;
		}
	}
	if (!found)
	{
		result.AminoAcid = '1';
	}
	return result;
}

void CodonsTable::setCodon(char* value, char AminoAcid, const int& index)
{
	codons[index].value[0] = value[0];
	codons[index].value[1] = value[1];
	codons[index].value[2] = value[2];
	codons[index].value[3] = value[3];
	codons[index].AminoAcid = AminoAcid;
}
