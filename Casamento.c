#include "Casamento.h"
#include "Analise.h"
#include "stdio.h"

void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m)
{
	long i, j, k;
	for(i = 1; i <= (n - m + 1); i++)
	{
		k = i; j = 1;
		while(T[k - 1] == P[j - 1] && j <= m) { j++; k++; comp++;}
		if(j > m) printf("Casamento na posicao %3ld\n", i);
	}
}

void BM(TipoTexto T, long n, TipoPadrao P, long m){
	long i, j, aux;
	i = m;
	while(i <= n){
		j = m;

		while(T[i - 1] == P[j - 1] && j > 0){
            i--; j--; comp++;
        }
		if(j == 0){
            printf("Casamento na posicao %3ld\n", i + 1);
            i++;
		}
        aux = ultimaOcorrencia(P, j-1, T[i-1]);
        aux = retornaMenor(j, aux);
        i += m - aux;
	}
}

long ultimaOcorrencia(TipoPadrao P, long tam, char c){
    while(tam > 0){
        comp++;
        if(P[tam-1] == c)
            return tam;
        tam--;
    }
    return tam;
}

long retornaMenor(long j, long aux){
    if(aux < j)
        return aux;
    else
        return j;
}

void BMH(TipoTexto T, long n, TipoPadrao P, long m)
{
	long i, j, k, d[MAXCHAR + 1];

	for(j = 0; j <= MAXCHAR; j++) d[j] = m;
	for(j = 1; j < m; j++) d[P[j - 1]] = m - j;
	i = m;
	while(i <= n)
	{
		k = i;
		j = m;
		while(T[k - 1] == P[j - 1] && j > 0) { k--; j--; comp++;}
		if(j == 0) printf("Casamento na posicao %3ld\n", k + 1);
		i += d[T[i-1]]; desl++;
	}
}

void BMHS(TipoTexto T, long n, TipoPadrao P, long m)
{
	long i, j, k, d[MAXCHAR + 1];

	for(j = 0; j <= MAXCHAR; j++) d[j] = m + 1;
	for(j = 1; j <= m; j++) d[P[j - 1]] = m - j + 1;
	i = m;;

	while(i <= m)
	{
		k = i;
		j = m;
		while(T[k-1] == P[j-1] && j > 0) { k--; j--; comp++;}
		if(j==0) printf("Casamento na posicao %3ld\n", k + 1);
		i += d[T[i]];
		desl++;
	}
}

void ShitAndExato(TipoTexto T, long n, TipoPadrao P, long m)
{
	long Masc[MAXCHAR], i, j;
	long R;

	for(i = 0; i < MAXCHAR; i++) Masc[i] = 0;
	for(i = 1; i <= m; i++) { Masc[P[i - 1] + 127] |= 1 << (m - i);}
	R = 0 << m;

	for(i = 0; i < n; i++)
	{
		R = ((R >> 1 | 1 << (m - 1)) & Masc[T[i] + 127]);
		if((R & 1) != 0) printf("Casamento na posicao %3ld\n", i - m + 2);
	}
}
