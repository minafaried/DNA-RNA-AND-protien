#include "DNA.h"

// Constructors And Destructor.
DNA::DNA()
{
	seq = NULL;
}
DNA::DNA(char* sent_sequence, const DNA_Type& sent_type, const int& sent_length)
{
	length = sent_length;
    seq = new char[sent_length + 1];
	for (int i = 0; i < length; i++)
	{
		seq[i] = sent_sequence[i];
	}
	seq[length] = '\0';
    type = sent_type;
}
DNA::DNA(int* sent_sequence, const DNA_Type & sent_type, const int & sent_length)
{
	seq = new char[sent_length + 1];
	for (int i = 0; i < length; i++)
	{
		this->seq[i] = (char)sent_sequence[i];
	}
	seq[length] = '\0';
	type = sent_type;
	length = sent_length;
}
DNA::DNA(const DNA& rhs)
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
DNA::~DNA()
{
}
// Setters.

void DNA::setType(DNA_Type x)
{
	type = x;
}

void DNA::setDna(char* sent_sequence, const DNA_Type& sent_type, const int& sent_length)
{
	length = sent_length;

	delete []seq;
    seq = new char[sent_length + 1];
    for (int i = 0 ; i < length ; i++)
    {
        seq[i] = sent_sequence[i];
    }
	seq[length] = '\0';

    type = sent_type;
}
void DNA::SetStart(int SIndex)
{
	startIndex = SIndex;
}
void DNA::SetEnd(int EIndex)
{
	endIndex = EIndex;
}
// Getters.
DNA_Type DNA::getType() const
{
	return (this -> type);
}
// Operators Overloading.
void DNA::operator= (DNA sent_DNA)
{
	delete[] (this -> seq);
	this -> length = sent_DNA.getLength();

	seq = new char[length + 1];
	char* temp = sent_DNA.getSeq();
	for (int i = 0; i < length; i++)
	{
		seq[i] = temp[i];
	}
	seq[length] = '\0';

	startIndex = sent_DNA.startIndex;
	endIndex = sent_DNA.endIndex;
	type =sent_DNA.type;
}
bool DNA::operator==(DNA sent_DNA)
{
	if (length != sent_DNA.length)
	{
		cout << this -> length << " " << sent_DNA.length;
		return false;
	}
	for (int i = 0; i < this->length; i++)
	{
		if (sent_DNA.seq[i] != this->seq[i])
		{
			return false;
		}
	}
	return true;
}

bool DNA::operator!=(DNA sent_DNA)
{
    if (length != sent_DNA.length)
	{
		cout << this -> length << " " << sent_DNA.length;
		return true;
	}
    for (int i = 0; i < this->length; i++)
	{
		if (sent_DNA.seq[i] == this->seq[i])
		{
			return false;
		}
	}
	return true;
}
DNA DNA::operator+(DNA sent_DNA)
{
    int result_length = this -> length + sent_DNA.getLength();
    char* temp = new char[result_length + 1];
    char* copy_sent_DNA = new char[sent_DNA.getLength() + 1];
    copy_sent_DNA = sent_DNA.getSeq();
    for (int i = 0 ; i < this -> length ; i++)
    {
        temp[i] = this -> seq[i];
    }
    for(int i = 0 ; i < sent_DNA.getLength() ; i++)
    {
        temp[i + length] = copy_sent_DNA[i];
    }
    temp[result_length] = '\0';
    DNA result(temp, tail /* Default Type */, result_length);
    delete []temp;
    delete []copy_sent_DNA;
    return result;
}
// Function That Convert The DNA to RNA.
RNA DNA::ConvertToRNA()
{
	char* arr = new char[length+1];
	for (int i = 0; i < length; i++)
	{
		arr[i] = this->seq[i];
	}
	arr[length] = '\0';
    int i = 0;
    while (true)
    {
        if (arr[i] == '\0')
        {
            break;
        }
        if (arr[i] == 'T')
        {
            arr[i] = 'U';
        }

        i++;
    }
	arr[length] = '\0';
    RNA temp_RNA;
	temp_RNA.setRNASeq(arr, length);
    return temp_RNA;
}
// Function That Get The Complementary Strand From The First Strand.
void DNA::BuildComplementaryStrand()
{
    complementary_strand = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		if (seq[i] == 'A')
		{
			complementary_strand[i] = 'T';
		}
		else if (seq[i] == 'T')
		{
			complementary_strand[i] = 'A';
		}
		else if (seq[i] == 'C')
		{
			complementary_strand[i] = 'G';
		}
		else if (seq[i] == 'G')
		{
			complementary_strand[i] = 'C';
		}
	}
	complementary_strand[length] = '\0';
	
	for (int i = endIndex-1 ; i >startIndex - 1; i--)
	{
		cout << complementary_strand[i];
	}
	cout <<endl<< endl;
}

istream & operator>> (istream & in, DNA & sent_sequence)
{
	cout << "Enter the length of the Sequence : ";
	in >> sent_sequence.length;

	delete []sent_sequence.seq;
	sent_sequence.seq = new char[sent_sequence.length + 1];
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

ostream & operator<<(ostream  &out, const DNA& sent_sequence)
{
	out << "The Length of the Sequence is : " << sent_sequence.getLength() << endl;
	for (int i = 0; i < sent_sequence.getLength(); i++)
	{
		out << sent_sequence.seq[i] << " ";
	}
	out << endl;
	return out;
}
