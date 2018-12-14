#include "Protein.h"

// Constructors And Destructor.
Protein::Protein()
{
	this->seq = NULL;
}
Protein::Protein(char* sent_sequence, int sent_length)
{
	length = sent_length;

    seq = new char[length + 1];
	for(int i = 0 ; i < length ; i++)
	{
		seq[i] = sent_sequence[i];
	}
	seq[length] = '\0';
}
Protein::Protein(int* sent_protein, int sent_length)
{
	length = sent_length;

	seq = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		seq[i] = (char)sent_protein[i];
	}
	seq[length] = '\0';
}
Protein::Protein(const Protein& rhs)
{
	length = rhs.length;

	seq = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		seq[i] = rhs.seq[i];
	}
	seq[length] = '\0';

	type = rhs.type;
}
Protein::~Protein()
{
}
void Protein::setType(Protein_Type x)
{
	type = x;
}
// Getters.
char * Protein::getSeq()
{
	return (this -> seq);
}
DNA* Protein::GetDNAStrandsEncodingMe(DNA& bigDNA, int& sizee)
{
	int protein_length = length;
	int DNA_length = bigDNA.getLength();
	int max_number_of_possibilities = DNA_length - (protein_length * 3) + 1;
	DNA_Type sent_type = bigDNA.getType();

	DNA* result_DNA = NULL; // Initial Value.
	DNA* temp_result_DNA = new DNA[max_number_of_possibilities];
	// The Same Size of The Max Number OF Possibilities but Carry The Actual Output DNA Strands Temporarily.
	char* temp_sequence = new char[(protein_length * 3) + 1]; // Carry The Sequence Being TESTED.
	char* copy_DNA_sequence = bigDNA.getSeq(); // Copy The Sequence of The Sent DNA.
											   // Temporary Variables To Convert From DNA To Protein For Comparison.
	DNA temp_DNA;
	RNA temp_RNA;
	Protein temp_protein;
	// Object Table to get the Amino Acid.
	CodonsTable table;
	table.LoadCodonsFromFile("RNA_codon_table.txt");
	// The Cases Where There Will Be No Strands For Certain.
	if (protein_length == 0 || DNA_length == 0 || (protein_length * 3) > DNA_length)
	{
		delete[]temp_sequence;
		delete[]temp_result_DNA;
		return result_DNA;
	}
	int counter_DNA = 0; // The Actual Number OF DNAS Strands.
	for (int i = 0 ; i < max_number_of_possibilities ; i++)
	{
	    int counter = i;
		for (int j = 0; j < protein_length * 3; j++)
		{
			temp_sequence[j] = copy_DNA_sequence[counter];
			counter++;
		}
		temp_sequence[protein_length * 3] = '\0';
		temp_DNA = DNA(temp_sequence, sent_type, protein_length * 3);
		temp_RNA = temp_DNA.ConvertToRNA();
		temp_protein = temp_RNA.ConvertToProtein(table);
		if (temp_protein.getLength() == 0)
		{
			continue;
		}
		if (temp_protein == *this)
		{
			temp_result_DNA[counter_DNA] = temp_DNA;
			counter_DNA++;
		}
	}

	result_DNA = new DNA[counter_DNA];

	for (int i = 0; i < counter_DNA; i++)
	{
		result_DNA[i] = temp_result_DNA[i];
	}
    delete []temp_sequence;
	delete []temp_result_DNA;
	sizee = counter_DNA;

	return result_DNA;
}
// Operators Overloading.
void Protein::operator= (Protein sent_protein)
{
	delete[](this->seq);
	length = sent_protein.getLength();

	seq = new char[length + 1];
	char* temp = sent_protein.getSeq();
	for (int i = 0; i < length; i++)
	{
		seq[i] = temp[i];
	}
	seq[length] = '\0';
	delete[]temp;

	type = sent_protein.type;
}
bool Protein::operator==(Protein sent_protein)
{
	if (length != sent_protein.length)
	{
		cout << this->length << " " << sent_protein.length;
		return false;
	}
	for (int i = 0; i < this->length; i++)
	{
		if (sent_protein.seq[i] != this->seq[i])
		{
			return false;
		}
	}
	return true;
}
bool Protein::operator!=(Protein sent_protein)
{
	if (length != sent_protein.length)
	{
		cout << this->length << " " << sent_protein.length;
		return true;
	}
	for (int i = 0; i < this->length; i++)
	{
		if (sent_protein.seq[i] == this->seq[i])
		{
			return false;
		}
	}
	return true;
}
Protein Protein::operator+ (Protein sent_protein)
{

	int result_length = length + sent_protein.getLength();
	char* temp = new char[result_length];
	char* copy_sent_protein_seq = new char[sent_protein.getLength()];
	copy_sent_protein_seq = sent_protein.getSeq();

	for (int i = 0; i < length; i++)
	{
        temp[i] = seq[i];
	}
	for (int i = 0; i < sent_protein.getLength() ; i++)
	{
		temp[i + this->length] = copy_sent_protein_seq[i];
	}
	Protein result(temp, result_length);
	delete []temp;
	delete []copy_sent_protein_seq;
	return result;
}
istream & operator >> (istream & in, Protein & sent_sequence)
{
	cout << "Enter the length of the Sequence : ";
	in >> sent_sequence.length;
	sent_sequence.seq = new char[sent_sequence.length+1];
	cout << "Enter the items in the Sequence : ";
	string word;
	in >> word;
	for (int i = 0; i < sent_sequence.length; i++)
	{
		sent_sequence.seq[i] = word[i];
	}

	sent_sequence.seq[sent_sequence.length] = '\0';
	return in;
}
ostream & operator<<(ostream &out, Protein sent_sequence)
{
	out << "The Length of the Sequence is : " << sent_sequence.getLength() << endl;
	for (int i = 0; i < sent_sequence.getLength(); i++)
	{
		out << sent_sequence.seq[i] << " ";
	}
	out << endl;
	return out;
}
