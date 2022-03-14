#include "Casamento.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include "Analise.h"

int main(int argc, char* argv[])
{
	if(argc >= 4)
	{
		FILE *leitura;
		long n, m;
		int i = 1;
		tempo = clock(); comp = desl = 0;
		TipoTexto texto; TipoPadrao padrao;

		if((leitura = fopen(argv[2], "r")) == NULL)
		{
			printf("ERRO NA ABERTURA DE ARQUIVO!\n");
			exit(1);
		}

		strcpy(padrao, argv[3]);
		m = strlen(padrao);

		switch(atoi(argv[1]))
		{
		case 1:	//FORCA BRUTA
			while((fgets(texto, sizeof(TipoTexto), leitura))!=NULL)
			{
				n = strlen(texto);
				ForcaBruta(texto, n, padrao, m); i++;
			}
			break;
        case 2: //BM
            while((fgets(texto, sizeof(TipoTexto), leitura))!=NULL)
			{
				n = strlen(texto);
				BM(texto, n, padrao, m); i++;
			}
			break;
		case 3:	//BMH
			while((fgets(texto, sizeof(TipoTexto), leitura))!=NULL)
			{
				n = strlen(texto);
				BMH(texto, n, padrao, m); i++;
			}
			break;
		case 4:	//BMHS
			while((fgets(texto, sizeof(TipoTexto), leitura))!=NULL)
			{
				n = strlen(texto);
				BMHS(texto, n, padrao, m); i++;
			}
			break;
		case 5:	//SHIFT AND EXATO
			while((fgets(texto, sizeof(TipoTexto), leitura))!=NULL)
			{
				n = strlen(texto);
				ShitAndExato(texto, n, padrao, m); i++;
			}
			break;
		}

		double tempof = ((double) (clock() - tempo)) / (((double) CLOCKS_PER_SEC) / 1000);

		if(argc == 5 && ((strcmp(argv[4], "-p") == 0) || strcmp(argv[4], "-P") == 0)) printf("\nComparacoes: %li\nDeslocamentos: %li\nTempo: %lf ms\n", comp, desl, tempof);
	}

	else printf("casamento <metodo> <texto> <padrao> [-P]");
}
