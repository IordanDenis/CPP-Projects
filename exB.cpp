#include<iostream>
#include<string>

using namespace std;

/*	Exercitiul 1 – Vocale/ consoane
Sa se scrie un program care citeste de la tastatura
un sir de N caractere si afiseaza vectorul avand pe primele pozitii vocalele,
iar pe ultimele pozitii consoanele introduse.
*/

void ex1()
{
	int n, i, indice_st, indice_dr;
	char v[30], c[30];
	cin.get(v, 30, '\n');
	n = strlen(v);
	cout << "Sirul are " << n << " caractere"<<endl;
	indice_st = 0;
	indice_dr = n - 1;
	for (i = 0; i < n; i++)
	{
		if (v[i] == 'a' || v[i] == 'e' || v[i]=='i'|| v[i] == 'o' || v[i]=='u')
		{
			c[indice_st] = v[i];
			indice_st++;
		}
		else
		{
			c[indice_dr] = v[i];
			indice_dr--;
		}

	}

	for(i = 0;i<n;i++)
	cout << c[i];

}
/*	Exercitiul 2 – Eliminarea vocalelor
Sa se scrie un program care citeste de la tastatura o propozitie 
si elimina toate vocalele din acea propozitie.
Sa se afiseze rezultatul obtinut pe ecran.
*/

void ex2()
{
	int n, i, j;
	char v[30];
	cin.get(v, 30, '\n');
	n = strlen(v);
	cout << "Sirul are " << n << " caractere" << endl;

	for (i = 0; i < n; i++)
	{
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
		{
			for (j = i; j < n; j++) //eliminam din vector vocala, mutand toate caracterele la stanga
			{
				v[j] = v[j + 1];
			}
			n--;
			i--;
		}
	}

	cout << "Vectorul fara vocale este:" << endl;

	for (i = 0; i < n; i++)
	{
		cout << v[i];
	}
}

/*	Exercitiul 3 – Cel mai scurt si cel mai lung cuvant
Sa se scrie un program care citeste de la tastatura
o fraza si afiseaza pe ecran cel mai scurt si cel mai lung cuvant pe care aceasta il contine.
*/
void ex3()
{
	int n, i;
	string s, max_word = "" ,min_word, word = "";
	cout << "Introduceti fraza:" << endl;
	getline(cin,s);
	n = s.length();
	cout << "Dimensiunea frazei introduse este " << n << endl;
	
	for(i=0;i<n-1;i++)
	{	
		if (s[i] != ' ')
		{
			word += s[i];
		}
		else
			word = "";
		if (word.length() > max_word.length())
		{
			max_word = word;
		}
	}

	
	cout << "Cuvantul cel mai lung din fraza este: " << max_word << " si are dimensiunea " << max_word.length() << endl;

	min_word = s;
	word = "";
	for (i = 0; i < n - 1; i++)
	{
		if (s[i] != ' ')
		{
			word += s[i];
		}
		else 
			{
				if (min_word.length() == 0)
					min_word = word;
				
				if (word.length() < min_word.length())
				{
					min_word = word;
				}
				word = "";
			}
	}

	cout << "Cuvantul cel mai scurt din fraza este: " << min_word << " si are dimensiunea " << min_word.length() << endl;

}

int main()
{

	cout << "Problema 1 - Vocale/ consoane " << endl;
	ex1();
	cout << endl<< "================================" << endl;
//	cout << "Problema 2 - Eliminarea vocalelor" << endl;
//	ex2();
//	cout << endl<< "================================" << endl;
//	cout << endl << "Problema 3 - Cel mai scurt si cel mai lung cuvant" << endl;
//	ex3();

	
	return 0;

}