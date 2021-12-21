#include<iostream>
#include<conio.h>
#include<cmath>

using namespace std;

/*          Exercitiul 1 – Radical
Sa se scrie un program care aloca dinamic o variabila,
o initializeaza, afiseaza pe ecran rezultatul expresiei: √var si apoi o sterge.
*/

void exercitiul_1() {
	float *x = new float();
	cout << "x=";
	cin >> *x;
	cout << sqrt(*x);
	delete x;
}

/*      	Exercitiul 2 – Alocarea dinamica a unui vector
Sa se scrie un program care aloca dinamic un vector cu n componente numere intregi,
 n fiind citit de la tastatura. Cele n componente ale vectorului se initializeaza
 cu valori impare, vectorul se afiseaza pe ecran si la sfarsit se sterge.
*/

void exercitiul_2() {
	int n;
	cout << "n=";
	cin >> n;
	int *v = new int[n];
	for (int i = 0; i < n; i++) {
		*(v + i) = 2 * i + 1;
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	delete[] v;
}

/*  		Exercitiul 3 – Matrice alocata dinamic
Sa se scrie un program care aloca dinamic o matrice cu n linii si m coloane numere intregi,
 n si m fiind citite de la tastatura. Sa se initializeze matricea si sa se afiseze pe ecran.
Alocarea se face utilizand functiile de alocare a memoriei. 
*/

void exercitiul_3() {
	int linii;
	cout << "linii=";
	cin >> linii;
	int coloane;
	cout << "coloane=";
	cin >> coloane;
	int **mat;
	mat = (int**)malloc(linii * sizeof(int));
	for (int i = 0; i < linii; i++) {
		mat[i] = (int*)malloc(coloane * sizeof(int));
	}
	for (int i = 0; i < linii; i++) {
		for (int j = 0; j < coloane; j++) {
			//mat[i][j] = i + j;
			//*(mat[i] + j) = i + j;
			*(*(mat + i) + j) = i + j;
		}
	}
	for (int i = 0; i < linii; i++) {
		for (int j = 0; j < coloane; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < linii; i++) {
		free(mat[i]);
	}
	free(mat);
}

int main() {
	
	exercitiul_1();
	//exercitiul_2();
	//exercitiul_3();
	_getch();
	return 0;
}