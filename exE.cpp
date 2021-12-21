#include <iostream>

using namespace std;

/*      	Exercitiul 3 – Numarul prim din coada
Sa se scrie un program care memoreaza n numere intregi intr-o structura de tip coada.
 Sa se stearga numerele care nu sunt prime din varful cozii pana cand se intalneste un numar prim.
 Sa se afiseze pe ecran rezultatul.
*/

struct Node {
	int value;
	Node* next;
};

struct Queue {
	Node* head; //cap
	Node* tail; //ultimul nod e denumit coada (a nu se confunda cu conceptul de coada)
	int length;
};

void push(Queue* &q, int val) {
	Node* newNode = new Node;
	newNode->value = val;
	newNode->next = nullptr;

	if (!q) {
		// daca coada e nula, atunci:
		q = new Queue; // alocam memorie
		q->head = newNode; // pozitionam capul cozii la noul nod
		q->tail = newNode; // pozitionam pointer-ul catre ultimul nod din coada la noul nod
		q->length = 1; // initializam lungimea cozii
	}
	else {
		// altfel:
		newNode->next = q->head; // asezam noul nod in fata capului cozii
		q->head = newNode; // mutam capul cozii pe noul nod
		q->length++; // incrementam lungimea cozii
	}
}

Node* pop(Queue*& q) {
	Node* aux = q->tail; // nodul pe care il vom sterge
	q->tail = q->head; // mutam pointerul catre ultimul nod din coada la capul cozii

	q->length--;

	// repozitionam pointerul catre ultimul nod din coada la noul final al cozii
	for (int i = 0; i < q->length - 1; i++) {
		q->tail = q->tail->next;
	}

	q->tail->next = nullptr; // stergem legatura catre nodul pe care vrem sa il stergem

	return aux;
}

int checkPrime(int value) {
	bool isPrime = true;
	
	/*
	mergem pana la jumatate + 1, deoarece, daca luam cazul in care verificam daca
	numarul 4 este prim, for-ul nu se va executa si functia va returna ca este prim
	*/

	for (int i = 2; i < value / 2 + 1; i++) {
		if (value % i == 0) {
			isPrime = false;
			break;
		}
	}

	return isPrime;
}

int main() {
	Queue* q = nullptr;

	for (int i = 20; i > 2; i--) {
		push(q, i);
	}
	
	// cat timp coada nu este nula
	while (q) {
		Node* sters = pop(q); // extragem un nod din coada

		// verificam daca este prim
		bool isPrime = checkPrime(sters->value);
		if (isPrime) {
			// daca numarul este prim, il afisam si incheiem executia
			cout << "Primul numar prim din coada este: " << sters->value << "\n";
			return 0;
		}
	}

	return 0;
}