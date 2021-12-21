#include<iostream>
#include<conio.h>

using namespace std;

/*
Definim o structura de tip nod al unui arbore binar (fiecare nod poate avea
maxim doi urmasi). Contine un camp de informatie <inf> unde vom stoca o 
valoare intreaga. In functie de situatie, putem defini oricate campuri care 
sa contina informatii (campurile pot fi inclusiv de tipul altor structuri 
definite). 
De asemenea, structura mai contine doua campuri de acelasi tip cu structura,
care vor memora adresele urmasului stanga, respectiv dreapta.
*/
struct Nod
{
	int inf;
	Nod *st;
	Nod *dr;
};

/*
Functie care insereaza un nou nod in arbore, respectand regula urmatoare:
Fiecare nod din arbore care nu este terminal (frunza) are valoarea retinuta
de el mai mare decat valoarea retinuta de urmasul stanga si mai mica decat
valoarea retinuta de urmasul dreapta. Daca nodul ce se doreste a fi introdus
contine o valoare ce exista deja in arbore, acesta nu va fi introdus. 
Nodul nou se va insera ca urmas al unui nod terminal (frunza).
Parametri:
	Nod* &p - adresa radacinii arborelui in care dorim sa inseram noul nod. 
			- * pentru ca e o adresa
 			- & (adica referinta) pentru ca modificarea acestei adrese sa
			fie vizibila si dupa apel. Adresa radacinii va fi modificata in
			cazul in care arborele este vid. In acest caz, noua radacina va
			fi chiar nodul introdus.
	int k	- valoare intreaga ce va fi introdusa in campul informatie al
			nodului ce se doreste a fi introdus in arbore
*/
void inserare(Nod* &p, int k) {
	//Daca nodul curent nu este null
	if (p) {
		/*Daca valoarea ce se doreste a fi introdusa exista in arbore, atunci nu
		inseram in arbore un nou nod cu aceasta valoare si afisam un mesaj
		corespunzator.*/
		if (p->inf == k) {
			cout << "Numarul este deja inserat" << endl;
		}
		else {
			/*Daca valoarea ce se doreste a fi introdusa este mai mica decat 
			valoarea din nodul curent, atunci inseamna ca nodul nou trebuie 
			introdus in undeva subarborele stang al nodului curent. Astfel, 
			apelam recursiv functia curenta si dam ca parametri nodul urmas
			stanga al nodului curent si valoarea ce se doreste a fi introdusa.*/
			if (k < p->inf) {
				inserare(p->st, k);
			}
			/*Daca valoarea ce se doreste a fi introdusa este mai mare decat
			valoarea din nodul curent, atunci inseamna ca nodul nou trebuie
			introdus in undeva subarborele drept al nodului curent. Astfel,
			apelam recursiv functia curenta si dam ca parametri nodul urmas
			dreapta al nodului curent si valoarea ce se doreste a fi introdusa.*/
			else {
				inserare(p->dr, k);
			}
		}
	}
	/*Daca nodul curent este null, atunci alocam spatiu pentru noul nod,
	introducem valoarea <k> in campul <inf> al nodului si il inseram in aceasta 
	pozitie. Aici ajungem in una din 2 situatii:
	1. Arborele este gol (nu contine niciun nod). Atunci introducem nodul ca 
	radacina arborelui.
	2. Am parcurs recursiv arborele pana cand am ajuns in pozitia corecta in
	care sa fie introdus nodul (conform regulii scrise in comentariul de 
	deasupra functiei)*/
	else {
		p = new Nod;
		p->inf = k;
		p->st = p->dr = nullptr;
	}
}

/*
Functie care cauta in arbore un nod care contine o anumita valoarea <k>. Daca
unul dintre nodurile din arbore contine aceasta valoare, atunci functia
returneaza <true>, altfel returneaza <false>.
Parametri:
	Nod *p	- adresa radacinii arborelui in care cautam
			- * pentru ca este o adresa
	int k	- valoarea intreaga pe care o cautam in arbore
Returneaza:
	true	- daca am gasit valoarea intr-un nod din arbore
	false	- daca nu am gasit valoarea intr-un nod din arbore
*/
bool cautare(Nod *p, int k) {
	/*Daca nodul curent nu este null*/
	if (p) {
		/*Am gasit nodul care contine valoarea <k>*/
		if (p->inf == k) {
			return true;
		}
		else {
			/*Cautam in subarborele stang*/
			if (k < p->inf) {
				cautare(p->st, k);
			}
			/*Cautam in subarborele drept*/
			else {
				cautare(p->dr, k);
			}
		}
	}
	/*Nodul curent este null. Acest lucru se poate intampla in doua cazuri:
	1. Arborele este vid (nu contine niciun nod).
	2. Am ajuns la urmasul unui nod terminal (frunza).
	In ambele cazuri rezulta ca valoarea pe care o cautam nu se afla in arbore*/
	else {
		return false;
	}
}

/*
Functie care afiseaza valorile din nodurile arborelui in "preordine". Adica va 
afisa mai intai radacina, dupa care subarborele stang, iar apoi subarborele
drept. Aceeasi regula se aplica recursiv asupra celor doi subarbori.
Parametri:
	Nod *p	- radacina arborelui pe care il parcurgem
*/
void preordine(Nod *p) {
	if (p!=nullptr) {
		cout << p->inf << " ";
		preordine(p->st);
		preordine(p->dr);
	}
}

/*
Functie care afiseaza valorile din nodurile arborelui in "inordine". Adica va
afisa mai intai subarborele stang, dupa care radacina, iar apoi subarborele
drept. Aceeasi regula se aplica recursiv asupra celor doi subarbori.
Parametri:
	Nod *p	- radacina arborelui pe care il parcurgem
*/
void inordine(Nod *p) {
	if (p) {
		inordine(p->st);
		cout << p->inf << " ";
		inordine(p->dr);
	}
}

/*
Functie care afiseaza valorile din nodurile arborelui in "postordine". Adica va
afisa mai intai subarborele stang, dupa care subarborele drept, iar apoi 
radacina. Aceeasi regula se aplica recursiv asupra celor doi subarbori.
Parametri:
	Nod *p	- radacina arborelui pe care il parcurgem
*/
void postordine(Nod *p) {
	if (p) {
		postordine(p->st);
		postordine(p->dr);
		cout << p->inf << " ";
	}
}

/*
Functie in care stergem arborele, ceea ce inseamna ca trebuie sa stergem toate
nodurile din arbore. Pentru a putea realiza acest lucru, trebuie sa incepem cu
nodurile terminale (frunze). In caz contrar, daca am sterge un nod care mai are
urmasi, vom pierde accesul la acesti urmasi si nu vom mai putea elibera acea
memorie alocata.
*/
void sterge(Nod* &p) {
	if (p) {
		sterge(p->st);
		sterge(p->dr);
		cout << "Stergem nodul " << p->inf << endl;
		free(p);
	}
}

int main() {
	/*Vector ce contine valori ce urmeaza a fi introduse in arbore*/
	int v[] = { 10, 2, 4, 19, 20, 3, 6, 2, 15 };
	int n = 9;
	int x;
	/*Declaram un arbore gol*/
	Nod *radacina = nullptr;
	
	/*Inseram valorile din vectorul <v> in arbore*/
	for (int i = 0; i < n; i++) {
		inserare(radacina, v[i]);
	}

	/*Cautam valoarea <x> sa vedem daca se afla in arbore*/
	x = 8;
	if (cautare(radacina, x)) {
		cout << x << " se afla in arbore" << endl;
	}
	else {
		cout << x << " nu se afla in arbore" << endl;
	}

	/*Afisam valorile din arbore in cele 3 moduri de parcurgere*/
	preordine(radacina);
	cout << endl;
	inordine(radacina);
	cout << endl;
	postordine(radacina);
	cout << endl;

	/*Stergem arborele*/
	sterge(radacina);
	radacina = nullptr;

	preordine(radacina);
	inordine(radacina);
	postordine(radacina);
	

	_getch();
	return 0;
}