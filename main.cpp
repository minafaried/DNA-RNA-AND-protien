#include "Sequence.h"
#include "protein.h"
#include "CodonsTable.h"
#include "RNA.h"
#include "DNA.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

void TypeMenu();
void DNAMenu();
void RNAMenu();
void proteinMenu();
bool checkDNA(char*seq, int l)
{
	for (int i = 0; i < l; i++)
	{
		if (seq[i] != 'A' && seq[i] != 'G' && seq[i] != 'C' && seq[i] != 'T') {

			return false;
		}
	}
	return true;
}
bool checkRNA(char*seq, int l)
{
	for (int i = 0; i < l; i++)
	{
		if (seq[i] != 'A' && seq[i] != 'G' && seq[i] != 'C' && seq[i] != 'U') {

			return false;
		}
	}
	return true;
}
int main()

{

	int choice;
	cout << "\n\n\t\t\t\t Hello USER\n\n\n" << endl;
	TypeMenu();
	cin >> choice;
	cout << endl;
	if (choice == 1)
	{
		int DChoice;
		DNAMenu();
		cout << "\n\n";
		cout << "\tEnter the Number of your Choice : ";
		cin >> DChoice;
		cout << "\n\n";

		if (DChoice == 1) {
			DNA D;
			RNA R;
			cin >> D;
			if (!checkDNA(D.getSeq(), D.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,T)\n";
					cin >> D;
					if (checkDNA(D.getSeq(), D.getLength()))
					{
						break;
					}
				}
			}
			R = D.ConvertToRNA();
			cout << R;
		}

		else if (DChoice == 2)
		{
			DNA D;
			int  SIndex, EIndex;
			cin >> D;
			if (!checkDNA(D.getSeq(), D.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,T)\n";
					cin >> D;
					if (checkDNA(D.getSeq(), D.getLength()))
					{
						break;
					}
				}
			}
			cout << "\n\n";
			cout << "Enter the Start index : ";
			cin >> SIndex;
			cout << "Enter the End index : ";
			cin >> EIndex;
			D.SetStart(SIndex);
			D.SetEnd(EIndex);
			D.BuildComplementaryStrand();
		}
		else if (DChoice == 3)
		{
			DNA D;
			cin >> D;
			if (!checkDNA(D.getSeq(), D.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,T)\n";
					cin >> D;
					if (checkDNA(D.getSeq(), D.getLength()))
					{
						break;
					}
				}
			}
			DNA d2, d3;
			cin >> d2;
			if (!checkDNA(d2.getSeq(), d2.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,T)\n";
					cin >> d2;
					if (checkDNA(d2.getSeq(), d2.getLength()))
					{
						break;
					}
				}
			}
			d3 = D + d2;
			cout << d3;
		}
		else if (DChoice == 4)
		{
			DNA D;
			cin >> D;
			if (!checkDNA(D.getSeq(), D.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,T)\n";
					cin >> D;
					if (checkDNA(D.getSeq(), D.getLength()))
					{
						break;
					}
				}
			}
			DNA d2;
			cin >> d2;
			if (!checkDNA(d2.getSeq(), d2.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,T)\n";
					cin >> d2;
					if (checkDNA(d2.getSeq(), d2.getLength()))
					{
						break;
					}
				}
			}
			bool res;
			res = D == d2;
			cout << res;
		}
		else if (DChoice == 5)
		{
			DNA D;
			cin >> D;
			if (!checkDNA(D.getSeq(), D.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,T)\n";
					cin >> D;
					if (checkDNA(D.getSeq(), D.getLength()))
					{
						break;
					}
				}
			}
			DNA d2;
			cin >> d2;
			if (!checkDNA(d2.getSeq(), d2.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,T)\n";
					cin >> d2;
					if (checkDNA(d2.getSeq(), d2.getLength()))
					{
						break;
					}
				}
			}
			bool res;
			res = D != d2;
			cout << res;
		}
		else if (DChoice == 6)
		{
			DNA D;
			cin >> D;
			if (!checkDNA(D.getSeq(), D.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,T)\n";
					cin >> D;
					if (checkDNA(D.getSeq(), D.getLength()))
					{
						break;
					}
				}
			}
			DNA d2;
			if (!checkDNA(d2.getSeq(), d2.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,T)\n";
					cin >> d2;
					if (checkDNA(d2.getSeq(), d2.getLength()))
					{
						break;
					}
				}
			}
			cin >> d2;
			Align(D.getSeq(), d2.getSeq(), D.getLength(), d2.getLength());
		}
		else
		{
			return 0;
		}
	}
	else if (choice == 2)
	{
		int RChoice;

		RNAMenu();
		cout << "\n\n";
		cout << "\tEnter the Number of your Choice : ";
		cin >> RChoice;
		cout << "\n\n";
		if (RChoice == 1) {
			RNA R;
			DNA D;
			cin >> R;

			if (!checkRNA(R.getSeq(), R.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,U)\n";
					cin >> R;
					if (checkRNA(R.getSeq(), R.getLength()))
					{
						break;
					}
				}
			}
			D = R.ConvertToDNA();
			cout << D;
		}
		else if (RChoice == 2)
		{
			CodonsTable c;
			Protein P;
			RNA R;
			c.LoadCodonsFromFile("RNA_codon_table.txt");
			cin >> R;
			if (!checkRNA(R.getSeq(), R.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,U)\n";
					cin >> R;
					if (checkRNA(R.getSeq(), R.getLength()))
					{
						break;
					}
				}
			}
			P = R.ConvertToProtein(c);
			cout << P;
		}
		else if (RChoice == 3)
		{
			RNA r1, r2, r3;
			cin >> r1;
			if (!checkRNA(r1.getSeq(), r1.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,U)\n";
					cin >> r1;
					if (checkRNA(r1.getSeq(), r1.getLength()))
					{
						break;
					}
				}
			}
			cin >> r2;
			if (!checkRNA(r2.getSeq(), r2.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,U)\n";
					cin >> r2;
					if (checkRNA(r2.getSeq(), r2.getLength()))
					{
						break;
					}
				}
			}
			r3 = r1 + r2;
			cout << r3;
		}
		else if (RChoice == 4)
		{
			RNA r1, r2;
			cin >> r1;
			if (!checkRNA(r1.getSeq(), r1.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,U)\n";
					cin >> r1;
					if (checkRNA(r1.getSeq(), r1.getLength()))
					{
						break;
					}
				}
			}
			cin >>r2;
			if (!checkRNA(r2.getSeq(), r2.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,U)\n";
					cin >> r2;
					if (checkRNA(r2.getSeq(), r2.getLength()))
					{
						break;
					}
				}
			}
			bool res;
			res = r1 == r2;
			cout << res;
		}
		else if (RChoice == 5)
		{
			RNA r1, r2;
			cin >> r1;
			if (!checkRNA(r1.getSeq(), r1.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,U)\n";
					cin >> r1;
					if (checkRNA(r1.getSeq(), r1.getLength()))
					{
						break;
					}
				}
			}
			cin>> r2;
			if (!checkRNA(r2.getSeq(), r2.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,U)\n";
					cin >> r2;
					if (checkRNA(r2.getSeq(), r2.getLength()))
					{
						break;
					}
				}
			}
			bool res;
			res = r1 != r2;
			cout << res;
		}
		else if (RChoice == 6)
		{
			RNA r1, r2;
			cin >> r1;
			if (!checkRNA(r1.getSeq(), r1.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,U)\n";
					cin >> r1;
					if (checkRNA(r1.getSeq(), r1.getLength()))
					{
						break;
					}
				}
			}
			cin>> r2;
			if (!checkRNA(r2.getSeq(), r2.getLength()))
			{
				while (true)
				{
					cout << "the DNA sequence is wrong plase enter sequence of (A,C,G,U)\n";
					cin >> r2;
					if (checkRNA(r2.getSeq(), r2.getLength()))
					{
						break;
					}
				}
			}
			Align(r1.getSeq(), r2.getSeq(), r1.getLength(), r2.getLength());

		}
		else
		{
			return 0;
		}
	}
	else if (choice == 3)
	{
		int PChoice;

		proteinMenu();
		cout << "\n\n";
		cout << "\tEnter the Number of your Choice : ";
		cin >> PChoice;
		cout << "\n\n";

		if (PChoice == 1) {
			DNA D;
			Protein p;
			cout << "enter protien sequence \n\n";
			cin >> p;
			cout << "\nenter DNA sequence \n\n";
			cin >> D;
			int sizee = 0;
			DNA* result = p.GetDNAStrandsEncodingMe(D, sizee);
			cout << sizee << endl;
			for (int i = 0; i < sizee; i++)
			{
				cout << result[i] << endl;
			}
		}
		else if (PChoice == 2)
		{
			Protein p1, p2, p3;
			cin >> p1;
			cin >> p2;
			p3 = p1 + p2;
			cout << p3;
		}
		else if (PChoice == 3)
		{
			Protein p1, p2;
			cin >> p1 >> p2;
			bool res;
			res = p1 == p2;
			cout << res;
		}
		else if (PChoice == 4)
		{
			Protein p1, p2;
			cin >> p1 >> p2;
			bool res;
			res = p1 != p2;
			cout << res;
		}
		else if (PChoice == 5)
		{
			RNA p1, p2;
			cin >> p1 >> p2;
			Align(p1.getSeq(), p2.getSeq(), p1.getLength(), p2.getLength());

		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	
	return 0;
}

void TypeMenu()
{
	cout << "Enter the type of the Sequence you want to Enter : " << endl;
	cout << "\t1. DNA\t"
		<< "\t2. RNA\t"
		<< "\t3. Protein" << endl;
	cout << "\n\nEnter your Choice number : ";
}

void DNAMenu()
{
	cout << "What you want to do with this Sequence ?" << endl;
	cout << "\t1. Convert to RNA Sequence" << endl;
	cout << "\t2.Build Complementary Strand of the DNA Sequence" << endl;
	cout << "\t3.Operator +" << endl;
	cout << "\t4.Operator ==" << endl;
	cout << "\t5.Operator !=" << endl;
	cout << "\t6.LCS" << endl;
}

void RNAMenu()
{
	cout << "What you want to do with this Sequence ?" << endl;
	cout << "\t1. Convert to DNA Sequence" << endl;
	cout << "\t2.ConvertToProtein" << endl;
	cout << "\t3.Operator +" << endl;
	cout << "\t4.Operator ==" << endl;
	cout << "\t5.Operator !=" << endl;
	cout << "\t6.LCS" << endl;
}
void proteinMenu()
{
	cout << "What you want to do with this Sequence ?" << endl;
	cout << "\t1. GetDNAStrandsEncodingMe" << endl;
	cout << "\t2.Operator +" << endl;
	cout << "\t3.Operator ==" << endl;
	cout << "\t4.Operator !=" << endl;
	cout << "\t5.LCS" << endl;
}