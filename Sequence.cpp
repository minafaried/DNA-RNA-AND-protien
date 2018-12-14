#include "Sequence.h"

// Constructors and Destructor.
Sequence::Sequence()
{
	seq = NULL;
}
Sequence::Sequence(const int& sent_length)
{
    length = sent_length;
    seq = new char[sent_length + 1];
}
Sequence::Sequence(const Sequence& rhs)
{
	length = rhs.length;
    seq = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		seq[i] = rhs.seq[i];
	}
	seq[length] = '\0';
}
Sequence::~Sequence()
{
//	delete[]seq;
}
// Setters.
void Sequence::SetLength(const int& sent_length)
{
	length = sent_length;
}
void Sequence::SetData(char* sent_sequence, const int& sent_length)
{
	length = sent_length;
	delete []seq;
	seq = new char[sent_length + 1];
	for (int i = 0 ; i < length /* OR sent_length */ ; i++)
	{
		seq[i] = sent_sequence[i];
	}
	seq[length] = '\0';
}
void Sequence::SetData(int * arr, const int & sent_length)
{
	length = sent_length;
	delete[]seq;
	seq = new char[sent_length + 1];
	for (int i = 0; i < sent_length; i++)
	{
		seq[i] = (char)arr[i];
	}
	seq[length] = '\0';


}
void Sequence::SetSeq(char* sent_sequence)
{
    seq = sent_sequence;
}
// Getters.
char* Sequence::getSeq() const
{
    return seq;
}
int Sequence::getLength() const
{
    return length;
}
void Sequence::operator=(const Sequence& rhs)
{
	length = rhs.getLength();
	char* temp = rhs.getSeq();
	seq = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		seq[i] = temp[i];
	}
	seq[length] = '\0';
	delete []temp;
}
// Operators Overloading.
istream& operator>>(istream& in, Sequence& sent_sequence)
{
	cout << "Enter the length of the Sequence : ";
	in >> sent_sequence.length;
	cout << "Enter the items in the Sequence : ";
	delete []sent_sequence.seq;
	sent_sequence.seq = new char[sent_sequence.length + 1];
	for (int i = 0; i < sent_sequence.length; i++)
	{
		in >> sent_sequence.seq[i];
	}
	sent_sequence.seq[sent_sequence.length] = '\0';
	return in;
}
ostream& operator<<(ostream& out, const Sequence& sent_sequence)
{
	out << "The Length of the Sequence is : " << sent_sequence.getLength() << endl;
	for (int i = 0 ; i < sent_sequence.getLength() ; i++)
	{
		out << sent_sequence.seq[i] << " ";
	}
	out << endl;
	return out;
}
// Align Function.
void Align(char* first_sequence, char* second_sequence, int size1, int size2)
{
    // Declaring A Matrix For The Numbers.
    int **table;
    table = new int* [size1 + 1];
    for (int i = 0 ; i < size1 + 1 ; i++)
        table[i] = new int[size2 + 1];
    // Declaring A Matrix For The Directions.
    char **symbols;
    symbols = new char* [size1 + 1];
    for (int i = 0 ; i < size1 + 1; i++)
        symbols[i] = new char[size2 + 1];
    for (int i = 0 ; i < size1 + 1 ; i++)
    {
        for (int j = 0 ; j < size2 + 1; j++)
        {
            symbols[i][j] = '0';
        }
    }
    for (int i = 0 ; i <size1 + 1 ; i++)
    {
        table[i][0] = 0;
    }
    for (int j = 0 ; j < size2 + 1 ; j++)
    {
        table[0][j] = 0;
    }
    // Comparing The Two Sequences And Record The Output And The Direction.
    for (int i = 1 ; i < size1 + 1 ; i++)
    {
        for (int j = 1 ; j < size2 + 1 ; j++)
        {

            if (first_sequence[i-1] == second_sequence[j-1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                symbols[i][j] = 'b';
            }
            else if (first_sequence[i - 1] != second_sequence[j - 1] && table[i][j - 1] <= table[i - 1][j])
            {
                table[i][j] = table[i - 1][j];
                symbols[i][j] = 'u';
            }
            else
            {
                table[i][j] = table[i ][j-1];
                symbols[i][j] = 'l';
            }

        }

    }

    int i = size1;
    int j = size2;
    int sizee = (table[i][j]);
    char* arr = new char(sizee);
    int counter = 0;
    // Filling arr With The Result.
    while (true)
    {
        if (table[i][j] == 0)
        {
            break;
        }
        if (symbols[i][j] == 'b')
        {
            arr[counter] = first_sequence[i - 1];
            i--;
            j--;
            counter++;
        }
        else if (symbols[i][j] == 'u')
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    // Printing The Result To The Screen.
	cout << endl << endl;
    for(int i = sizee - 1 ; i >= 0 ; i--)
    {
        cout << arr[i];
    }
	cout << endl << endl;
    // Deleting The Allocated Memory.
    delete []arr;
	for (int i = 0; i < size1 + 1; i++)
    {
		delete table[i];
    }
	delete[]table;
	for (int i = 0; i < size1 + 1; i++)
    {
		delete symbols[i];
    }
	delete[]symbols;
}
