#include <stdio.h>

#define MaxTam 100
#define MarcaEof '\0'
#define CancelaCarater '\b'
#define CancelaLinha '\n'
#define SaltaLinha '\t'

typedef struct {
    char Chave;
} TipoItem;

typedef struct {
    int iTopo;
    TipoItem Item[MaxTam];
} TipoPilha;

void FPVazia(TipoPilha* pPilha) {
    pPilha->iTopo = 0;
}

int PEhVazia(TipoPilha* pPilha) {
    return (pPilha->iTopo == 0);
}

int PEmpilha(TipoPilha* pPilha, TipoItem* pItem) {
    if (pPilha->iTopo == MaxTam)
        return 0;
    else {
        pPilha->iTopo++;
        pPilha->Item[pPilha->iTopo - 1] = *pItem;
    }
    return 1;
}

int PDesempilha(TipoPilha* pPilha, TipoItem* pItem) {
    if (PEhVazia(pPilha))
        return 0;
    else {
        *pItem = pPilha->Item[pPilha->iTopo - 1];
        pPilha->iTopo--;
    }
    return 1;
}

int PTamanho(TipoPilha* pPilha) {
    return (pPilha->iTopo);
}

void PImprime(TipoPilha* pPilha) {
    TipoPilha Pilhaux;
    TipoItem x;
    FPVazia(&Pilhaux);
    while (!PEhVazia(pPilha)) {
        PDesempilha(pPilha, &x);
        PEmpilha(&Pilhaux, &x);
    }
    while (!PEhVazia(&Pilhaux)) {
        PDesempilha(&Pilhaux, &x);
        putchar(x.Chave);
    }
    putchar('\n');
}

int main(int argc, char* argv[]) {
    TipoPilha Pilha;
    TipoItem x;
    FPVazia(&Pilha);
    x.Chave = getchar();
    while (x.Chave != MarcaEof) {
        if (x.Chave == CancelaCarater) {
            if (!PEhVazia(&Pilha))
                PDesempilha(&Pilha, &x);
        } else if (x.Chave == CancelaLinha)
            FPVazia(&Pilha);
        else if (x.Chave == SaltaLinha)
            PImprime(&Pilha);
        else {
            if (PTamanho(&Pilha) == MaxTam)
                PImprime(&Pilha);
            PEmpilha(&Pilha, &x);
        }
        x.Chave = getchar();
    }
    if (!PEhVazia(&Pilha))
        PImprime(&Pilha);
    return 0;
}

// Uma pilha é uma estrutura de dados que admite remoção de elementos e inserção de novos objetos.  
// É uma estrutura sujeita à seguinte regra de operação:  sempre que houver  uma remoção, o elemento removido 
// é o que está na estrutura há menos tempo.