#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

/** Vector con el precalculo del binomio de newton donde
 * bn[n] = n sobre 2, esto nos da el numero de maximo de inversiones que puede tener [n]
 */
vector<int> bn;

/** La lista con los elementos que aun quedan por procesar. */
list<int> rem;
/** El vector con la solucion parcial hasta ahora. */
vector<int> cur;

/** Nos ayudara a imprimir el vector mas claramente*/
ostream& operator<<(ostream& o, const vector<int>& t)
{
	if (t.empty())
	{
		o << "()";
	}
	else
	{
		vector<int>::const_iterator i = t.begin();

		o << "(";

		o << *i;

		for (++i; i != t.end(); ++i)
		{
			o << "," << *i;
		}

		o << ")";
	}

	return o;
}

void gen(int n, int k)
{
	if (n == 0 && k == 0)
	{
		cout << cur << endl;
	}
	else
	{
		list<int>:: iterator i;
		int rank;

		for (i = rem.begin(), rank = rem.size(); i != rem.end(); ++i, --rank)
		{
			// Rank indica la posicion del elemento actual en la lista rem,
			// si estuviera ordenada crecientemente.

			// Esta condicion nos garantiza segun el lema 2.1 de Scott Elffer
			// en A CAT Algorithm for Generating Permutations with a Fixed Number of Inversions
			// que realmente podemos generar permutaciones.
			if (n - rank <= k and k <= bn[n - 1] + n - rank)
			{
				int x = *i;

				cur[n - 1] = x;

				i = rem.erase(i);
				gen(n - 1, k - n + rank);
				i = rem.insert(i, x);
			}
		}
	}
}

/** Calcula binomios de newton sobre 2 hasta n y los guarda en bn. */
void calcbn(int n)
{
	bn.reserve(n + 1);

	bn.push_back(0);
	bn.push_back(0);

	for (int i = 2; i <= n; i++)
	{
		bn.push_back(i - 1 + bn[i - 1]);
	}
}

int main()
{
	int n, k;

	cin >> n >> k;

	// Inicializa el vector bn
	calcbn(n);

	// Inicializa la lista de elementos restantes
	for (int i = n; i > 0; --i)
	{
		rem.push_back(i);
	}

	// Ajusta el tamanyo del vector donde guardaremos resultados parciales
	cur.resize(n);

	// Hacemos el calculo de las permutaciones
	gen(n, k);

	return 0;
}
