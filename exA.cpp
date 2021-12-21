

#include<iostream>
using namespace std;
/*	Exercitiul 1 – Elementul din vector
Sa se scrie un program care citeste de la tastatura un vector cu N elemente
si un numar intreg a. 
Sa se verifice daca numarul a este
un element al vectorului si sa se afiseze si de cate ori apare.
*/

void ex1() 
{
	int i, a, contor = 0, n, v[100]; 
	cout << "Dimensiunea vectorului este n = ";
	cin >> n; // citim de la tastatura ce dimensiune va avea vectorul v
	cout << " a = ";
	cin >> a; //citim de la tatatura valoare pe care o vom cauta in elementele vectorului

	for (i = 0; i < n; i++) 
	{
		cout << "v [ " << i << " ] = ";
		cin >> v[i]; //citim de la tastatura valorile vectorului 
		if (v[i] == a) //comparam valoare introdusa in vector daca este egala cu valoarea variabilei a pe care o cauta
			contor++; // daca valoarea lui a este egala cu valoarea elementului v[i] din tablou incrementam variabila contor
	}
	//iesim din for - am terminat de introdus toate elementele vectorului si am terminat de comparat cu valoarea lui a
	if (contor > 1) //daca variabila contor este mai mare decat 1 inseama ca am gasit cel putin de 2 ori  valoarea variabilei a in vector
					//folosim aceasta informatie pentru a afisa un mesaj corect
		cout << "Numarul a = " << a << " a aparut in vector de " << contor << " ori."; 
	else if (contor == 1) // daca variabila contor nu este mai mare decat 1, va fii verificata aici daca este egal 1
						// daca contor este 1, inseamna ca valoarea variabilei a a fost gasita 1 data in vector -> afisam un mesaj corespunzator
		cout << "Numarul a = " << a << " a aparut 1 data in vector.";
	else //daca contor nu este nici mai mare decat 1, si nici egal cu 1, inseama ca a ramas 0 (valoarea pe care am dat-o cand am declarat variabila contor)
		//ceea ce inseamna ca valoarea variabilei a nu a fost gasita in vector deloc -> afisam un mesaj corespunzator.
		cout << "Numarul a = " << a << " nu a aparut in vector.";
}

/*	Exercitiul 2 – Impar/ par
Sa se scrie un program care citeste de la tastatura un vector cu
n elemente numere intregi.
Sa se afiseze vectorul astfel incat
numerele impare sa ocupe primele pozitii,
iar cele pare ultimele pozitii.
*/

void ex2()
{
	int i, n, v[100], indice_st, indice_dr, w[100];
	cout << "Dimensiunea vectorului n = ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "v[" << i << "] = ";
		cin >> v[i];
	}
	indice_st = 0; //variabila indice_st este initializata cu cel mai mic indice al vectorului in care putem pune un nr impar
	indice_dr = n - 1; //variabila indice_dr este initializata cu cel mai mare indice al vectorului in care putem pune un nr par
	/*Folosim un al doilea vector w[] in care mutam elementele impare din v[] la inceputul vectorului w[], si elementele pare din v[] la finalul vectorului w[] */
	for(i=0;i<n;i++) //parcurgem elementele din vectorul v, una cate una
		if (v[i] % 2 == 0) //verificam daca elementul din v[i] este par
		{	//daca este par atunci se executa urmatoare 2 instructiuni
		
			w[indice_dr] = v[i]; //retinem in al doilea vector w[] pe indicele cel mai din dreapta( pt prima iteratie va fi w[n-1] valoarea pe care o are v[i])
			indice_dr--; //dupa ce am alocat valoarea la acest indice, trb sa scadem indicele cu 1, sa punem urmatorul element par pe un indice mai mic
			//salvam aici elementele din vectorul v[] in vectorul w[] de la dreapta la stanga, cand elementele v[i] sunt pare
		}
		else //daca elementul v[i] este impar (restul impartirii la 2 nu da 0) atunci facem urmatoarele instructiuni
		{
			w[indice_st] = v[i]; //salvam in vectorul w[] valoarea elementului v[i] pe pozitia cea mai din stanga (pt prima iteratie cand se intra pe acest caz indice_st va fi 0, deci salvam in w[0])
			indice_st++; //crestem valoarea indicelui indice_st cu 1, pentru a salva urmatorul element impar la urmatorul indice. 
			//noi punem acum elementele impare din v[i] la inceputului vectorului w[]
		}

	cout << "Afisam vectorul ordonat cu elementele impare pe primele pozitii si elementele pare pe ultimele pozitii:" << endl;
	for (i = 0; i < n; i++) 
		cout << w[i] << " "; //afisam elementele vectorului w, separate de un spatiu 

}

/*	Exercitiul 3 – Eliminarea elementelor identice
Sa se scrie un program care citeste de la tastatura un vector v cu N elemente.
Sa se determine daca in vector exista elemente care se repeta
si daca da, sa se elimine astfel incat sa nu mai existe doua elemente identice.
*/

void ex3()
{
	int i, j, k, n, v[100], copie_n;
	cout << "Dimensiunea vectorului n = ";
	cin >> n;
	copie_n = n; //copiem valoare initiala a dimensiunii vectorului intr-o variabila numita copie_n pentru a compara la final dimensiunea vectorului dupa algoritm
	for (i = 0; i < n; i++)
	{
		cout << "v[" << i << "] = ";
		cin >> v[i];
	}
	/*pentru a verifica daca un element din vector apare de mai multe ori vom folosi un for care pleaca de la primul element (v[0]) si
	il compara cu toate elementele ramase in vector. Pentru a il compara cu toate elementele ne trebuie un al doilea for care ia pe rand fiecare element, pornind de la pozitia  i+1
	(pentru prima iteratia va fi v[0] comparat cu [v1], apoi urmeaza v[0] comparat cu v[2] etc. pana se termina indicii din al doilea for).
	Daca gasim un element care sa fie egal, trebuie sa il stergem. Bineinteles daca stergem un element, indicele din al doilea for trebuie sa scada, la fel si dimensiunea vectorului.
	*/
	for (i = 0; i < n - 1; i++) //folosim 'i' sa parcurgem vectorul incepand cu primul element, pana la penultimul element (inclusiv)
	{
		for (j = i + 1; j < n; j++) // folosim 'j' sa parcurgem vectorul de la pozitia imediat urmatoare (j=i+1 - inseamna ca vom aveam cand i = 0, j = 1, cand i = 1, j = 2 etc.) pana la ultimul element (inclusiv)
		{
			if (v[i] == v[j]) //comparam daca v[i] este egal ca valoare cu v[j]. Asta inseamna ca vom compara v[0] cu v[1], apoi v[0] cu v[2] etc.
			{ //daca gasim aceiasi valoare, trb sa stergem a doua aparitie a valoarii, adica valoare retinuta de v[j]
				for (k = j; k < n - 1; k++) // folosim 'k' sa parcurgem vectorul pentru stergerea elementului v[j], unde j este indicele la care se afla elementul dublat
				{
					v[k] = v[k + 1]; //mutam toate elementele vectorului de la dreapta la stanga, incepand cu pozitia pe care se afla elementul dublat.
				}
				n--; //scadem dimensiunea vectorului cu 1, pentru ca s-a sters un element din vector
				j--; //scadem valoarea lui j cu 1 sa nu sarim peste un element (la indicele j este acum alta valoare, deoarce cea gasita a fost inalocuita de valoarea elem din dreapta sa)
			}
		}
	}
	if (copie_n != n) //verificam daca dimensiunea vectorului introdusa initial s-a schimbat
	{//daca dimensiunea s-a schimbat (nu mai e egala cu cea inainte de algoritm) inseamna ca au fost duplicate care au fost scoase => dimensiunea vectorului este mai mica acum
		cout << "Vectorul fara duplicate este: " << endl; //afisam vectorul fara duplicate
		for (i = 0; i < n; i++)
		{
			cout << v[i] << " ";
		}
	}
	else //daca dimensiunea vectorului este la fel cu cea dinainte de algoritm inseamna ca nu au fost duplicate -> afisam un text corespunzator
	{
		cout << "Vectorul nu a continut nici un duplicat.";
	}
}


int main()
{
	cout << "Problema 1 -  Elementul din vector: " << endl;
	ex1(); //apelam in int main() functia 'ex1' pentru a se executa
//	cout << endl<< "Problema 2 - Impar/ par: " << endl;
//	ex2(); //apelam in int main() functia 'ex2' pentru a se executa
//	cout << endl << "Problema 3 - Eliminarea elementelor identice" << endl;
//	ex3(); // apelam in int main() functia 'ex3' pentru a se executa


	return 0;
}