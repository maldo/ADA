#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
#define alfabet_size 'z'-'a'+1

void radix_sort(queue<string>& q, size_t x)
{
	/*
	 * Definimos un Vector de tamaño del alfabeto
	 * de colas de prioridad(pq), una cola de
	 * por cada letra.
	 */
	vector< priority_queue <string, vector<string>, greater<string> > > radix(alfabet_size);
	
	string word;
		
	/*
	 * Iteramos tantas veces como letras haya.
	 */
	for (; x>0; --x)
	{
		/*
		 * Por cada palabra de la cola, miramos su
		 * el caracter de la posicion x y lo insertamos
		 * en la cola de prioridad que corresponda
		 */
		while (!q.empty())
		{
			word = q.front();
			q.pop();
	
			radix[word[x-1] - 'a'].push(word);
		}
		/*
		 * Coste: por cada palabra(n) tenemos que
		 * sacarla de la cola e insertarla en la cola
		 * de prioridad (log(n))
		 * Coste del fragmento: O(nlog(n))
		 */
		
		
		/**
		 * Igual que en el caso anterior tiene el mismo coste O(nlog(n))
		 */
		for (int i = 0; i<alfabet_size; ++i)
		{
			while (!radix[i].empty())
			{
				word = radix[i].top();

				q.push(word);
				radix[i].pop();
			}
		}
	}
}

//NOTA: queue no soporta iterator
void print_queue(queue<string> q)
{
	size_t total = q.size();
	for (size_t x = 0; x<total-1; ++x)
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<q.front();
	cout<<endl;
}

int main()
{
	queue<string> Q;

	string word;

	cin>>word;

	/* Sabemos que todas las palabras
	 * tienen la misma longitud
	 */
	size_t x = word.size();

	/* 
	 * Leemos las palabras de entrada y las vamos
	 * dejando en una cola hasta encontrar un EOF
	 */
	for (;cin;)
	{
		Q.push(word);
		cin>>word;
	}
	
	/*
	 * Llamamos a la funcion radix_sort, destinada
	 * a ordenar Q
	 */
	radix_sort(Q, x);
	/* O(x(nlog(n))*/
	
	if (!Q.empty())
	{	
		/*
		 * Imprimimos como se nos pide
		 */
		print_queue(Q);
	}
	else cout<<endl;

	return 0;
}
