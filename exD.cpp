#include <iostream>

using namespace std;

/*          Exercitiul 2 – Numerele pare din stiva
Sa se scrie un program care adauga intr-o stiva numere de la 1 la 10 si elimina numerele impare.
 Sa se afiseze stiva care contine doar numerele pare din intervalul [1,10].
Se va crea o stiva de rezerva pentru a nu pierde numerele pare.
*/

struct Node {
	int value;
	Node* next;
};

void push(Node*& stack, int val) {
	Node* newNode = new Node;
	newNode->value = val;
	newNode->next = nullptr;

	if (!stack) {
		stack = newNode;
	}
	else {
		newNode->next = stack;
		stack = newNode;
	}
}

Node* pop(Node*& stack) {
	Node* aux = stack;
	stack = stack->next;
	return aux;
}

//stack e capul listei
int main()
{
	Node* stack = nullptr;
	Node* aux_stack = nullptr;

	for (int i = 1; i < 11; i++) {
		push(stack, i);
	}

	while (stack) {
		Node* sters = pop(stack);

		if (sters->value % 2 == 0) {
			push(aux_stack, sters->value);
		}
	}

	while (aux_stack) {
		Node* sters = pop(aux_stack);
		cout << sters->value << " ";
	}
}
