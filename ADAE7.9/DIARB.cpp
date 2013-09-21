#include <iostream>
using namespace std;

/**
 * El Coste en caso medio es log(n)
 *	T(n) = 2·T(n/2) + 0 aplicando el segundo Teorema Maestro
 * En caso peor el coste es n. Este caso se da cuando el arbol esta desbalanceado
 *
 */
int diarb(int & m)
{
	int x;
	cin >> x;
	if (x == -1)
		return 0;

	int a1 = 0;
	int a2 = 0;

	/**
	 * Llamadas recursivas, primero hijo izquierdo, segundo hijo derecho
	 */
	a1 = diarb(m);
	a2 = diarb(m);

	/**
	 * Actulizamos la cuenta de las alturas parciales
	 */
	m = max(m, a1+a2+1);

	return max(a1, a2)+1;
}

int main()
{
	/** n es el numero de arboles a procesar*/
	int n;
	cin >> n;

	/**
	 * m nos servira para guardarnos las alturas parciales de los arboles
	 * puesto que el diametro de un arbol puede estar exclusivamente 
	 * dentro en un arbol hijo derecho o izquierdo
	 */
	int m = 0;

	/**
	 * El diametro de un arbol sera en log(n) -o caso peor (n)- y para x arboles
	 * el coste sera xlog(n), donde n es el tamaño del arbol
	 */
	for (int i = 0; i < n; i++)
	{
		/** Leemos la raiz del arbol*/
		int x;
		cin >> x;

		/** Comprobamos que el arbol no sea nulo*/
		if (x == -1)
		{
			cout<<0<<endl;
		}
		else
		{
			/** La lectura del arbol tiene que ser en preorden*/

			/** Buscamos el diametro en el hijo izquierdo*/
			int k1 = diarb(m);

			/** Buscamos el diametro en el hijo derecho*/
			int k2 = diarb(m);

			/**
			 *  k es el diametro del arbol, se calcula mediante el diametro de los 2 hijos o
			 *  la suma de las altura
			 */
			int k = max(m, k1+k2+1);

			cout<<k<<endl;
		}
		/** Hemos acabado de procesar un arbol, reseteamos la variable*/
		m=0;
	}
}
