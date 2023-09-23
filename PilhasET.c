
// Código a ser implementado

void FPVazia(TipoPilha* pPilha)
{
pPilha->iTopo = 0;
} /* FPVazia */
int PEhVazia(TipoPilha* pPilha)
{
return (pPilha->iTopo == 0);
} /* PEhVazia */
int PEmpilha(TipoPilha* pPilha,TipoItem* pItem)
{
if (pPilha->iTopo == MaxTam)
return 0;
else
{
pPilha->iTopo++;
pPilha->Item[Pilha->iTopo - 1] = *pItem;
}
return 1;
} /* PEmpilha */

int PDesempilha(TipoPilha* pPilha, TipoItem* pItem)
{
if (PEhVazia(pPilha))
return 0
else
{
*pItem = pPilha->Item[pPilha->iTopo - 1];
pPilha->iTopo--;
}
return 1;
} /* PDesempilha */

int PTamanho(TipoPilha* pPilha)
{
return (pPilha->iTopo);
} /* Tamanho */

int main(int argc, char* argv[])
{
TipoPilha Pilha;
TipoItem x;
FPVazia(&Pilha);
x.Chave = getchar();
while (x.Chave != MarcaEof)
{
if (x.Chave == CancelaCarater)
{ if (!PEhVazia(&Pilha)) PDesempilha(&Pilha, &x);}
else if (x.Chave == CancelaLinha) FPVazia(&Pilha);
else if (x.Chave == SaltaLinha) PImprime(&Pilha);
else
{ if (PTamanho(Pilha) == MaxTam) PImprime(&Pilha);
PEmpilha(&Pilha, &x); }
x.Chave = getchar();
}
if (!PEhVazia(&Pilha)) PImprime(&Pilha);
return 0;
} /* ET */

void PImprime(TipoPilha* pPilha)
{
TipoPilha Pilhaux;
TipoItem x;
FPVazia(&Pilhaux);
while (!PEhVazia(pPilha))
{
PDesempilha(pPilha, &x); PEmpilha(&Pilhaux,&x);
}
while (!PEhVazia(&Pilhaux))
{
PDesempilha(&Pilhaux, &x); putchar(x.Chave);
}
putchar('\n');
} /* Imprime */