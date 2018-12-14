#include "RNA.h"

// Constructors And Destructor.
RNA::RNA()
{
	this->seq = NULL;
}
RNA::RNA(char* sent_sequence, const RNA_Type& sent_type, const int& sent_length)
{
	length = sent_length;

	seq = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		seq[i] = sent_sequence[i];
	}
	seq[length] = '\0';

    type = sent_type;

}
RNA::RNA(int * sent_sequence, const RNA_Type & sent_type, const int & sent_length)
{
	length = sent_length;

	seq = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		seq[i] = (char)sent_sequence[i];
	}
	seq[length] = '\0';

	type = sent_type;

}
RNA::RNA(const RNA& rhs)
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
RNA::~RNA()
{
}
void RNA::setType(RNA_Type x)
{
	type=x;
}
// Setters.
void RNA::setRNASeq(char* arr, int sent_length)
{
    delete []seq;
	seq = new char[sent_length + 1];
	length = sent_length;
	for (int i = 0; i < length; i++)
	{
		seq[i] = arr[i];
	}
	seq[length] = '\0';
}
// Operators Overloading.
void RNA::operator= (RNA sent_RNA)
{
	delete[] (this->seq);
	length = sent_RNA.getLength();

	seq = new char[length + 1];
	char* temp = sent_RNA.getSeq();
	for (int i = 0; i < length; i++)
	{
		seq[i] = temp[i];
	}
	seq[length] = '\0';
	delete []temp;

	type = sent_RNA.type;
}

bool RNA::operator==(RNA sent_RNA)
{
	if (length != sent_RNA.length)
	{
		cout << this->length << " " << sent_RNA.length;
		return false;
	}
	for (int i = 0; i < this->length; i++)
	{
		if (sent_RNA.seq[i] != this->seq[i])
		{
			return false;
		}
	}
	return true;
}

bool RNA::operator!=(RNA sent_RNA)
{
	if (length != sent_RNA.length)
	{
		cout << this->length << " " << sent_RNA.length;
		return true;
	}
	for (int i = 0; i < this->length; i++)
	{
		if (sent_RNA.seq[i] == this->seq[i])
		{
			return false;
		}
	}
	return true;
}

RNA RNA::operator+ (RNA sent_RNA)
{

    int result_length = length + sent_RNA.getLength();
    char* temp = new char[result_length + 1];
    char* copy_sent_RNA_seq = new char[sent_RNA.getLength()];
    copy_sent_RNA_seq = sent_RNA.getSeq();

    for (int i = 0 ; i < length; i++)
    {
        temp[i] = seq[i];
    }
    for (int i = 0; i < sent_RNA.getLength() ; i++)
    {
        temp[i + length] = copy_sent_RNA_seq[i];
    }
    temp[result_length] = '\0';
    RNA result(temp, mRNA /* Default Value */, result_length);
    return result;
}
//Function That Convert The RNA To Protein.
Protein RNA::ConvertToProtein(CodonsTable table)
{
    char* arr = new char[ (length / 3 ) + 1 ];
    int a = 0;
    Codon c;
    for (int i = 0; i < length ; i += 3)
    {
        char temp[4];
        temp[0] = this -> seq[i];
        temp[1] = this -> seq[i+1];
        temp[2] = this -> seq[i+2];
        temp[3] = '\0';

        c = table.getAminoAcid(temp);
		if (c.AminoAcid == '1')
		{	
			cout << "there is no AminoAcid of thid seq : " ;
			for (int i = 0; i < 4; i++)
			{
				cout << temp[i];
			}
			cout << endl;
			arr[0] = '\0';
			Protein p(arr, 0);
			return p;
		}
		if (c.AminoAcid == '0')
		{
			char* arr = new char[(a) + 1];
			arr[a] = '\0';
			Protein p(arr, a);
			return p;
		}
		if (c.AminoAcid == '1')
		{
			cout << "there is no AminoAcid of thid seq"<<endl;
			arr[0] = '\0';
			Protein p(arr,0);
			return p;
		}
        arr[a] = c.AminoAcid;
        a++;
    }
    arr[length / 3] = '\0';
    Protein p(arr, length / 3);

    return p;
}
// Function That Convert The RNA Back To DNA.
DNA RNA::ConvertToDNA()
{
    char* arr = this -> seq;
    int i = 0;
    while (true)
    {
        if (arr[i] == '\0')
        {
            break;
        }
        if (arr[i] == 'U')
        {
            arr[i] = 'T';
        }
        i++;
    }
    arr[this -> length] = '\0';
    DNA D(arr, tail, this -> length);
    return D;
}

istream& operator >> (istream & in, RNA& sent_sequence)
{
	cout << "Enter the length of the Sequence : ";
	in >> sent_sequence.length;

	delete [](sent_sequence.seq);
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

ostream & operator<<(ostream &out, RNA sent_sequence)
{
	out << "The Length of the Sequence is : " << sent_sequence.getLength() << endl;
	for (int i = 0; i < sent_sequence.getLength(); i++)
	{
		out << sent_sequence.seq[i] << " ";
	}
	out << endl;
	return out;
}
