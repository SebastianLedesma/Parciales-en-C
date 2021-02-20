#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* lista= NULL;
    lista=(LinkedList*) malloc(sizeof(LinkedList));

    if(lista != NULL){
        lista->pFirstNode=NULL;
        lista->size=0;
    }

    return lista;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int retorno=-1;

    if(this != NULL){
        retorno = this->size;
    }

    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pAux = NULL;

    if(this != NULL && nodeIndex >=0 && nodeIndex < ll_len(this))
    {
        pAux=this->pFirstNode;
        if(nodeIndex!=0)
        {
            while(pAux->pNextNode!=NULL)
            {
                pAux=pAux->pNextNode;
                nodeIndex--;
                if(nodeIndex==0)
                    break;
            }
        }
    }
    return pAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int retorno = -1;
    Node* prev=NULL;
    Node* next=NULL;
    Node* nuevoNodo=NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){
        nuevoNodo =(Node*) malloc(sizeof(Node));

        if(nuevoNodo != NULL){
            nuevoNodo->pElement=pElement;

            if(nodeIndex == 0 && this->pFirstNode == NULL){
                this->pFirstNode=nuevoNodo;
            }else if(nodeIndex == 0 && this->pFirstNode != NULL){
                next = this->pFirstNode;
                this->pFirstNode = nuevoNodo;
                nuevoNodo->pNextNode=next;
            }else if(this->pFirstNode !=NULL && nodeIndex > 0 && nodeIndex < ll_len(this)){
                next = getNode(this,nodeIndex);
                nuevoNodo->pNextNode = next;
                prev = getNode(this,nodeIndex-1);
                prev->pNextNode=nuevoNodo;
            }else if(this->pFirstNode != NULL){
                next = getNode(this,nodeIndex-1);
                next->pNextNode = nuevoNodo;
            }
        }

        this->size++;
        retorno = 0;
    }

    return retorno;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this != NULL && addNode(this,ll_len(this),pElement)== 0){
        retorno = 0;
    }

    return retorno;
}


/** \brief Retorna un puntero al elemento en el indice especificado.
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* retorno = NULL;
    Node* pNode = NULL;
    if(this != NULL && index >= 0 && index <= ll_len(this)){
        pNode = getNode(this,index);

        if(pNode != NULL){
            retorno = pNode->pElement;
        }
    }

    return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno = -1;
    Node* actual = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){
        actual = getNode(this,index);

        if(actual != NULL){
            actual->pElement = pElement;
            retorno = 0;
        }
    }

    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int retorno = -1;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        if(index == 0 && this->pFirstNode != NULL)
        {
            this->pFirstNode = getNode(this, index)->pNextNode;
            free(getNode(this, index));

        }else if(index > 0 && index < ll_len(this) && getNode(this, index) != NULL && getNode(this, index-1) != NULL){
            getNode(this, index-1)->pNextNode = getNode(this, index)->pNextNode;
            free(getNode(this,index));
        }
        /*else{
            getNode(this, index-1)->pNextNode = NULL;
            free(getNode(this, index));
        }
        */
        this->size--;
        retorno = 0;
    }

    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int retorno = -1;
    int i;

    if(this != NULL)
    {
        for(i=ll_len(this); i > 0 ; i--)
        {
            ll_remove(this, ll_len(this)-1);
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        if(ll_clear(this)==0)
        {
            free(this);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno = -1;
    int i;
    int longitud;
    Node* nodo;

    longitud = ll_len(this);

    if(this != NULL && longitud >= 0){
        for(i=0;i< longitud;i++){
            nodo = getNode(this,i);
            if(pElement == nodo->pElement){
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno = -1;
    int tamanio;

    if(this != NULL)
    {
        tamanio = ll_len(this);
        if( tamanio == 0)
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this) && addNode(this,index,pElement)==0){
        retorno=0;
    }

    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* retorno = NULL;

    if(this != NULL && index >= 0 && index <= ll_len(this)){
        retorno=ll_get(this,index);
        if(retorno != NULL){
            ll_remove(this,index);
        }
    }

    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno = -1;
    int longitud;

    longitud = ll_len(this);

    if(this != NULL && longitud >= 0){
        retorno=0;
        if(ll_indexOf(this,pElement) != -1){
            retorno =1;
        }
    }

    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno = -1;
    int i;
    int longitud;
    Node* nodo;

    if(this != NULL && this2 != NULL){
        longitud = ll_len(this2);
        retorno = 1;
        for(i=0;i < longitud;i++){
            nodo = getNode(this2,i);
            if(nodo != NULL && ll_contains(this,nodo->pElement) != 1){
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement=NULL;

    if(this != NULL && from >= 0 && from < ll_len(this) && from < to && to <= ll_len(this) && this->pFirstNode != NULL){
        cloneArray = ll_newLinkedList();

        if(cloneArray != NULL){
            for(i=from; i < to;i++){
                pElement = ll_get(this,i);
                if(pElement != NULL){
                    ll_add(cloneArray,pElement);
                }
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL){
        cloneArray = ll_subList(this,0,ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int retorno =-1;
    void* pAux;
    int i;
    int j;
    int longitud;


    if(this != NULL && pFunc != NULL && ll_len(this) > 0 && (order == 0 || order == 1)){
        longitud = ll_len(this);

        for(i=0 ;i < longitud -1 ;i++){
            if(ll_get(this,i) != NULL){
                for(j=i+1; j < longitud;j++){
                    if(ll_get(this,j) != NULL){
                        if(pFunc(ll_get(this,i),ll_get(this,j)) < 0 && order == 0){
                            pAux = ll_get(this,i);
                            ll_set(this,i,ll_get(this,j));
                            ll_set(this,j,pAux);
                        }else if(pFunc(ll_get(this,i),ll_get(this,j)) > 0 && order == 1){
                            pAux = ll_get(this,i);
                            ll_set(this,i,ll_get(this,j));
                            ll_set(this,j,pAux);
                        }
                    }
                }
            }
        }
        retorno = 0;
    }


    return retorno;
}


/** \brief Funcion que filtra una lista y retorna un puntero a una nueva LinkedList.
 *
 * \param *fn Puntero a funcion que establecera el citerio de filtrado de la lista pasado por parametro.
 * \param LinkedList* Puntero a la lista a filtrar.
 *\return Retorna un puntero a la nueva lista filtrada o NULL si hubo error.
 */
LinkedList* ll_filter(LinkedList* this,int (*fn)(void*)){
    int i;
    int longitud;
    void* pAux;
    LinkedList* pLista = NULL;

    if(this != NULL){
        longitud = ll_len(this);
        pLista = ll_newLinkedList();
        for(i=0 ; i < longitud; i++){
            pAux = ll_get(this,i);
            if(pAux != NULL && fn(pAux)){
                ll_add(pLista,pAux);
            }
        }
    }

    return pLista;
}
