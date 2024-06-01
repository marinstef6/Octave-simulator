//Marin Stefania,311CA, 2022-2023
#include<stdio.h>
#include<stdlib.h>
//functie creare matrice
int **creare (int m, int n)
{

  int i, j;
  int **a = (int **) malloc (m * sizeof (int *));

  if (!a)
	{
	  fprintf (stderr, "malloc() for matrix failed\n");
	  return NULL;
	}

  for (i = 0; i < m; i++)
	{
	  a[i] = (int *) malloc (n * sizeof (int));
	  if (!a[i])
	{
	  fprintf (stderr, "malloc() for line %d failed\n", i);
	  for (j = 0; j < i; j++)
		free (a[j]);

	  free (a);
	  return NULL;
	}
	}

  for (i = 0; i < m; i++)
	{
	  for (j = 0; j < n; j++)
	{
	  scanf ("%d", &a[i][j]);

	}
	}
  getchar ();
  return a;
}
//functie afisare matrice
void comanda_P (int m, int n, int **matrice)
{
  int i, j;

  for (i = 0; i < m; i++)
	{
	  for (j = 0; j < n; j++)
	printf ("%d ", matrice[i][j]);
	  printf ("\n");
	}
}
//functie eliberare matrice
void elib_matrix (int m, int **matrice)
{
  int i;

  for (i = 0; i < m; i++)
	{
	  free (matrice[i]);
	}
  free (matrice);
}
//functie creare dimensiuni matrice
int *vector (int n, int m)
{
  int *v = (int *)malloc(2 * sizeof (int));
  v[0] = n;
  v[1] = m;
  return v;
}
//functia de inmultire a doua matrice
int **comanda_M (int **a, int **b, int n, int m, int k)
{
  int i, j, l;
  int **p = (int **) malloc (n * sizeof (int *));
  for (i = 0; i < n; i++)
	p[i] = (int *) malloc (m * sizeof (int));
  for (i = 0; i < n; i++)
	for (j = 0; j < m; j++)
	  {
	p[i][j] = 0;
	for (l = 0; l < k; l++)
	  {
		p[i][j] += a[i][l] * b[l][j];
		if (p[i][j] > 0)
		  p[i][j] = p[i][j] % 10007;
		else if (p[i][j] < 0)
		  p[i][j] = p[i][j] % 10007 + 10007;
		if(p[i][j]==10007) p[i][j]=0;
	  }
	  }
  return p;
}
//functia de aflare a sumei elementelor unei matrice
int suma (int m, int n, int **matrice)
{
  int i, j, sum = 0;

  for (i = 0; i < m; i++)
	{
	  for (j = 0; j < n; j++)
	sum += matrice[i][j];
	}
  if (sum > 0)
	sum = sum % 10007;
  else
	sum = 10007 + sum % 10007;
  return sum;
}
//functia de transpunere a unei matrice
int **trans (int m, int n, int **matrice)
{
  int i, j;
  int **t = (int **) malloc (n * sizeof (int *));

  for (i = 0; i < n; i++)
	t[i] = (int *) malloc (m * sizeof (int));

  for (i = 0; i < n; i++)
	for (j = 0; j < m; j++)
	  {
	t[i][j] = matrice[j][i];
	  }
  return t;
}
//functia de ridicare la putere
int **putere (int **matrice, int put, int m, int n)
{
  int i,j,k;
	int **aux = (int **) malloc (m * sizeof (int *));
  for (i = 0; i < m; i++)
	aux[i] = (int *) malloc (n * sizeof (int));
//aux=dublu pointer care retine matricea la patrat
		for(i = 0;i<m;i++)
			for(j=0;j<n;j++)
			{
				aux[i][j]=0;
	  			for(k=0;k<n;k++)
	   			aux[i][j]+=matrice[i][k]*matrice[k][j];
			}

	if(put == 2) return aux;
	else if(put>2)
	{
		put=put-2;
		int **p = (int **) malloc (m * sizeof (int *));
  		for (i = 0; i < m; i++)
   			 p[i] = (int *) malloc (n * sizeof (int));

		int **a = (int **) calloc (m, sizeof (int *));
  		for (i = 0; i < m; i++)
   			 a[i] = (int *) calloc (n, sizeof (int));
//a=dublu pointer care retine matricea la patrat
			for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				a[i][j]=aux[i][j];
//p=dublu pointer care retine rezultatul final
			while(put)
			{
				if(put%2==1)
				for(i = 0; i < m; i++)
			for(j = 0; j < n; j++)
			{
				p[i][j] = 0;
	  			for(k = 0;k < n; k++)
				  p[i][j]+=a[i][k]*matrice[k][j];
			}
			put=put/2;
			}
	elib_matrix(m,a);
	elib_matrix(m,aux);
		return p;
	}
   return NULL;
}
//functia care ajuta la redimensionare
int **redimens (int **matrice, int l, int c, int L[], int C[])
{
  int i, j;
  int **r = (int **) malloc (l * sizeof (int *));
  for (i = 0; i < l; i++)
	r[i] = (int *) malloc (c * sizeof (int));

  for (i = 0; i < l; i++)
	for (j = 0; j < c; j++)
	  {
	r[i][j] = matrice[L[i]][C[j]];
	  }
  return r;
}

int main ()
{
  int n, m;
  char litera;

  int ***octav, **dim, total = 0, indice;
  octav = (int ***) malloc (1 * sizeof (int **));
  dim = (int **) malloc (1 * sizeof (int *));
  while (1)
	{
	  scanf ("%c", &litera);
	  getchar ();
	  if (litera == 'L')
	{
	  scanf ("%d%d", &m, &n);
	  //octav=triplu pointer care retine toate matricele
	  octav[total] = creare (m, n);
	  octav = (int ***) realloc (octav, (total + 2) * sizeof (int **));
	  dim[total] = vector (m, n);
	  //dim=dublu pointer care retine dimensiunea unei matrice
	  dim = (int **) realloc (dim, (total + 2) * sizeof (int *));
	  total++;
	}
	  else if (litera == 'P')
	{
	  scanf ("%d", &indice);
	  getchar ();
	  if (indice < 0 || indice >= total)
		printf ("No matrix with the given index\n");
	  else
		comanda_P (dim[indice][0], dim[indice][1], octav[indice]);
	}
	  else if (litera == 'C')
	{
		//l nr de linii,c nr de coloane, L vector care retine niste linii,C vector care retine niste coloane
	  int i, l, c, indice;
	  int L[1000], C[1000];
		  scanf ("%d", &indice);
		  scanf ("%d", &l);
		  for (i = 0; i < l; i++)
		scanf ("%d", &L[i]);
		  scanf ("%d", &c);
		  for (i = 0; i < c; i++)
		scanf ("%d", &C[i]);
		  getchar ();
		  if (indice < 0 || indice >= total)
		printf ("No matrix with the given index\n");
		  else{int **red = redimens (octav[indice], l, c, L, C);
		  elib_matrix (dim[indice][0], octav[indice]);
		  octav[indice] = red;
		  dim[indice][0] = l;
		  dim[indice][1] = c;
		  }
	}
	  else if (litera == 'D')
	{
	  scanf ("%d", &indice);
	  getchar ();
	  if (indice < 0 || indice >= total)
		printf ("No matrix with the given index\n");
	  else
		{
		  printf ("%d ", dim[indice][0]);
		  printf ("%d\n", dim[indice][1]);
		}
	}
	  else if (litera == 'M')
	{
	  int indice1, indice2;

	  scanf ("%d%d", &indice1, &indice2);
	  getchar ();

	  if (indice1 >= total || indice2 >= total)
		printf ("No matrix with the given index\n");
	  else if (dim[indice1][1] != dim[indice2][0])
		printf ("Cannot perform matrix multiplication\n");
	  else
		{
		  int **mat_a =comanda_M (octav[indice1], octav[indice2], dim[indice1][0],
			   dim[indice2][1], dim[indice1][1]);
		  int *v = (int *) malloc (2 * sizeof (int));
		  v[0] = dim[indice1][0];
		  v[1] = dim[indice2][1];
		  octav =(int ***) realloc (octav, (total + 1) * sizeof (int **));
		  dim = (int **) realloc (dim, (total + 1) * sizeof (int *));
		  octav[total] = mat_a;
		  dim[total] = v;
		  total++;
		}
	}
	  else if (litera == 'O')
	{
	  int *s = (int *) malloc (total * sizeof (int));
	  int i, j, aux;
	  int **mat_aux;
	  int *dim_aux;

	  for (i = 0; i < total; i++)
		s[i] = suma (dim[i][0], dim[i][1], octav[i]);

	  for (i = 0; i < total - 1; i++)
		for (j = i + 1; j < total; j++)
		  {
		if (s[i] > s[j])
		  {
			aux = s[i];
			s[i] = s[j];
			s[j] = aux;
			mat_aux = octav[i];
			octav[i] = octav[j];
			octav[j] = mat_aux;
			dim_aux = dim[i];
			dim[i] = dim[j];
			dim[j] = dim_aux;

		  }
		  }
		  free(s);
	}
	  else if (litera == 'T')
	{
	  scanf ("%d", &indice);
	  getchar ();
	  if (indice < 0 || indice >= total)
		printf ("No matrix with the given index\n");
	  else
		{
		  int a = dim[indice][0];
		  int b = dim[indice][1];
		  int **tr = trans (a, b, octav[indice]);
		  elib_matrix (a, octav[indice]);
		  octav[indice] = tr;
		  dim[indice][0] = b;
		  dim[indice][1] = a;
		}
	}
	  else if (litera == 'R')
	{
	  int power;
	  scanf ("%d", &indice);
	  scanf ("%d", &power);
	  getchar ();
	  if (indice >= total || indice < 0)
		printf ("No matrix with the given index\n");
	  else if (power < 0)
		printf ("Power should be positive\n");
	  else if (dim[indice][0] != dim[indice][1])
		printf ("Cannot perform matrix multiplication\n");
	  else
		{
			int a,b;
			a=dim[indice][0];
			b=dim[indice][1];
		  int **pt =putere (octav[indice], power, a, b);
		  elib_matrix (dim[indice][0], octav[indice]);
		  octav[indice] = pt;
		}

	}
	  else if (litera == 'F')
	{
	  int indice, i;
	  scanf ("%d", &indice);
	  getchar ();
	  if (indice < 0 || indice >= total)
		printf ("No matrix with the given index\n");
	  else
		{
		  elib_matrix (dim[indice][0], octav[indice]);
		  free (dim[indice]);
		  for (i = indice; i < total - 1; i++)
		{
		  octav[i] = octav[i + 1];
		  dim[i] = dim[i + 1];
		}

		  total--;
		}

	}
	  else if (litera == 'Q')
	{
	  int i;
	  for (i = 0; i < total; i++)
		{
		  elib_matrix (dim[i][0], octav[i]);
		  free (dim[i]);
		}
	  free (octav);
	  free (dim);
	  break;

	}
	  else if (litera != 'P' || litera != 'L' || litera != 'D' || litera != 'O'|| litera != 'R' || litera != 'C' ||
	  			litera != 'T'|| litera != 'F' || litera != 'Q')
		printf ("Unrecognized command\n");
	}
  return 0;
}
