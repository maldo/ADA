#include <iostream>
#include <stack>
using namespace std;

/** 
 * El coste del algoritmo es (n²) que es una mejora con respecto al algoritmo
 * recursivo que tenia un coste de (2^n)
 */
void escriu (int n)
{	
	/**La pila se vacia n veces antes de finalizar. Solo esta vacia cuando tratamos n
	 * y los n-1 elementos que pone en la pila.*/
	int empty=n;
	stack<int> rstack;
	
	/** Apilamos n como primera llamada */
	rstack.push(n);
	
	while(empty>0)
	{
		/** Apilamos de n-1 hasta 1 para tratarlos en siguientes iteraciones.*/
		for(int i=n-1;i>0;i--)
		{
			rstack.push(i);
		}
		
		/** En la cima hay un 1, como no hay que tratarlo lo imprimimos por pantalla
		 *  y lo desapilamos*/
		cout<<' '<<rstack.top();
		rstack.pop();

		/** Si la pila no esta vacia imprimimos la cima y dejamos la cima como n
		 * para tratarla en las siguientes iteraciones */
		if (!rstack.empty())
		{
			n=rstack.top();
			cout<<' '<<rstack.top();
			rstack.pop();
		}
		if(rstack.empty())empty--;
	}
}

/**
 * La funcion main() no se puede modificar
 */
int main()
{
	int n;
	while (cin >> n)
	{
		escriu(n);
		cout << endl;
	}
}
