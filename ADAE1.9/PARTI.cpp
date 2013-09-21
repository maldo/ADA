#include <iostream>
#include <vector>
#include <list>
using namespace std;

/**
 * Solucion comprueba si ya hemos asignado todos los elementos a todos los conjuntos.
 */
bool solucion(vector<string>& words, unsigned int m)
{
	return words.size()==m;
}

/**
 * Imprimimos la solucion tal como se nos pide
 */
void print_sol(vector<list<string> >& conjuntos)
{
	list<string>::iterator it;

	for (size_t i=0; i<conjuntos.size(); ++i)
	{
		cout<<"subconjunt "<<i+1<<": {";
		it = conjuntos[i].begin();
		if (conjuntos[i].size()>=1)
			cout<<*it;
		++it;

		for (; it!=conjuntos[i].end(); ++it)
		{
			cout<<","<<*it;
		}
		cout<<"}"<<endl;
	}

	cout<<endl;
}

/**	
 * Cuando encontramos una solucion la escribimos por pantalla, sino asignamos
 * el elemento k al conjunto i. Llamamos recursivamente con el siguiente elemento y
 * cuando volvemos sacamos la palabra k del conjunto i.	
 */
void partir(vector<string>& words, vector<list<string> >& conjuntos,
		unsigned int k)
{
	if (solucion(words, k))
	{
		print_sol(conjuntos);
	}
	else
	{
		if (k<words.size())
		{
			for (size_t i = 0; i<conjuntos.size(); ++i)
			{
				conjuntos[i].push_back(words[k]);
				partir(words, conjuntos, k+1);
				conjuntos[i].pop_back();
			}
		}
	}
}

int main()
{
	int p, n;

	/** Leemos el total de elementos*/
	cin>>n;

	vector<string> words(n);

	for (int i=0; i<n; i++)
	{
		cin >> words[i];
	}

	/** Leemos el numero de particiones*/
	cin>>p;

	/** 
	 * Un vector de conjuntos donde cada conjunto representa una particion y esta
	 * contiene elementos asignados a ella
	 */
	vector<list<string> > conjuntos(p);

	/**
	 * Llamada inicial vector de palabras, los conjuntos y el primer elemento a mirar
	 */
	partir(words, conjuntos, 0);

	return 0;
}

