#ifndef CASAMENTO_H_
#define CASAMENTO_H_
#define MAXTAMTEXTO 1000
#define MAXTAMPADRAO 10
#define MAXCHAR 256
#define NUMMAXERROS 10
typedef char TipoTexto[MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];
void ForcaBruta(TipoTexto, long, TipoPadrao, long);
void BM(TipoTexto, long, TipoPadrao, long);
void BMH(TipoTexto, long, TipoPadrao, long);
void BMHS(TipoTexto, long, TipoPadrao, long);
void ShitAndExato(TipoTexto, long, TipoPadrao, long);

long ultimaOcorrencia(TipoPadrao, long, char);
long retornaMenor(long, long);
#endif /* CASAMENTO_H_ */
