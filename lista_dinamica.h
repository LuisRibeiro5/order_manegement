#ifndef LISTADINAMICA_H_INCLUDED
#define LISTADINAMICA_H_INCLUDED

template<typename T>
struct NodoLista
{
    T valor;
    NodoLista<T>* prox;
};

template<typename T>
struct lista_dinamica
{
    int cardinalidade;
    NodoLista<T>* inicio;
    NodoLista<T>* fim;
};

template<typename T>
void cria(lista_dinamica<T>& lista ){
    lista.cardinalidade = 0;
    lista.fim = nullptr;
    lista.inicio = nullptr;
}

template<typename T>
void destroi(lista_dinamica<T>& lista ){
    while (lista.inicio)
    {
        NodoLista<T>* apagado = lista.inicio;
        lista.inicio = lista.inicio->prox;

        delete apagado;
    }

    cria(lista);
}

template<typename T>
bool existeElem(lista_dinamica<T>& lista, T elem ){
    NodoLista<T>* atual = lista.inicio;

    while (atual)
    {
        if (atual->valor == elem)
        {
            return true;
        }
        
    }
    
    return false;
}

template<typename T>
bool existePos(lista_dinamica<T>& lista, int pos ){
    return pos > 0 && pos <= lista.cardinalidade;
}

template<typename T>
bool ehVazia(lista_dinamica<T>& lista ){
    return lista.cardinalidade == 0;
}

template<typename T>
int numeroElementos(lista_dinamica<T>& lista ){
    return lista.cardinalidade;
}

template<typename T>
T getElem(lista_dinamica<T>& lista, int pos ){
    if (!existePos(lista, pos))
    {
        throw "POSICAO INVALIDA.";
    }

    NodoLista<T>* atual = lista.inicio;
    for (int i = 1; i < pos; i++)
    {
        atual = atual->prox;
    }
    
    return atual->valor;
}

template<typename T>
T &getRefElem(lista_dinamica<T>& lista, int pos ){
    if (!existePos(lista, pos))
    {
        throw "POSICAO INVALIDA.";
    }

    NodoLista<T>* atual = lista.inicio;
    for (int i = 1; i < pos; i++)
    {
        atual = atual->prox;
    }
    
    return atual->valor;
}

template<typename T>
int getPos(lista_dinamica<T>& lista, T elem ){
    if (!existeElem(lista, elem))
    {
        throw "ELEMENTO NAO EXISTE.";
    }
    
    NodoLista<T>* atual = lista.inicio;
    int i = 1;
    for (; atual != nullptr; atual = atual->prox){
        if (atual->valor == elem)
        {
            return i;
        }
        i++;
    }                                                                                                                                                                                
    
}

template<typename T>
void insere(lista_dinamica<T>& lista, T elem, int pos ){
    if (pos <= 0 || pos > lista.cardinalidade + 1)
    {
        throw "POSICAO INVALIDA DE INSERCAO.";
    }

    NodoLista<T>* novo = new NodoLista<T>;
    novo->valor = elem;
    novo->prox = nullptr;

    if (ehVazia(lista))
    {
        lista.inicio = novo;
        lista.fim = novo;
    } else if (pos == 1){
        novo->prox = lista.inicio;
        lista.inicio = novo;
    } else {
        NodoLista<T>* ant = lista.inicio; //pos ant ao lugar que vou inserir novo valor

        for (int i = 1; i < pos - 1; i++)
        {
            ant = ant->prox;
        }
        
        if (ant->prox == nullptr) lista.fim = novo;
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    
    lista.cardinalidade++;
}

template<typename T>
void retira(lista_dinamica<T>& lista, int pos){
    if (ehVazia(lista))
    {
        throw "LISTA VAZIA.";
    }
    if (pos <= 0 || pos > lista.cardinalidade)
    {
        throw "POSICAO INVALIDA DE INSERCAO.";
    }

    NodoLista<T>* apagado;
    if (pos == 1)
    {
        apagado = lista.inicio;
        lista.inicio = lista.inicio->prox;

        if (lista.inicio == nullptr) lista.fim = nullptr;
    } else {
        NodoLista<T>* ant = lista.inicio;

        for (int i = 1; i <= pos - 1; i++)
        {
            ant = ant->prox;
        }
        
        apagado = ant->prox; // valor que sera apagado
        ant->prox = apagado->prox; // religa o ponteira ant com a posicao a frente do que sera apagado

        if (apagado->prox == nullptr) lista.fim = ant;        
        
    }
    
    delete apagado;
    lista.cardinalidade--;
}

template<typename T>
void mostra(lista_dinamica<T>& lista ){
    std::cout << "[";
    for (int i = 1; i <= numeroElementos(lista); i++)
    {
        std::cout << getElem(lista, i);
        if (i != numeroElementos(lista)) std::cout << ", ";
    }
    std::cout << "]";
}
#endif