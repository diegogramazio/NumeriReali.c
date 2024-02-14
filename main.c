#include <stdio.h>
#include <stdlib.h>

struct NumeroReale {
        int intera;
        int decimale;
};
typedef struct NumeroReale NR;

struct Nodo {
        struct NumeroReale nr;
        struct Nodo *next;
};
typedef struct Nodo* NODO;

/****** STAMPA ******/

void stampaReale(NR numero) {
    printf("%d.%d", numero.intera, numero.decimale);
}

void stampaLista(NODO puntaNodo) {
     if(puntaNodo==NULL)
          printf("Lista vuota.\n\n");
     else {
          printf("\nEcco la lista: ");
          while(puntaNodo->next!=NULL) {
                 stampaReale(puntaNodo->nr);
                 printf(", ");
                 puntaNodo = puntaNodo->next;
          }
          stampaReale(puntaNodo->nr);
          printf("\n\n");
     }
}

/****** INSERIMENTI ******/

/* funzione che legge e restituisce un numero reale */
NR leggiReale() {
     NR numero;          // da leggere
     printf("Introduci la parte intera: ");
     scanf("%d", &numero.intera);
     do {
           printf("Introduci la parte decimale: ");
           scanf("%d", &numero.decimale);
           if(numero.decimale<0) {
                  printf("La parte decimale deve essere positiva!\n\n");
           }
     }
     while(numero.decimale<0);
     return numero;
}

/* funzione che inserisce un nodo in testa alla lista: soluzione con doppio puntatore */
void inserisciTesta(NODO* puntaHead) {
      NODO nuovoNodo;      // il nuovo nodo della lista
      nuovoNodo = malloc(sizeof(struct Nodo));      // allocazione nodo nell'heap
      nuovoNodo->nr = leggiReale();       // leggi il campo dati
      /* collega il nodo al successivo; tramite *puntahead accediamo al valore
         puntato da puntaHead, ovvero al contenuto della variabile head nel main,
         ovvero all'indirizzo del precedente primo nodo della lista. */
         nuovoNodo->next = *puntaHead;
         *puntaHead = nuovoNodo;
         printf("Inserimento riuscito!\n\n");
}

/* funzione che inserisce un nodo in coda alla lista: soluzione con doppio puntatore */
void inserisciInCoda(NODO* puntaHead) {
       NODO nuovoNodo;         // il nuovo nodo della lista
       nuovoNodo = malloc(sizeof(struct Nodo));   // allocazione nodo nell'heap
       nuovoNodo->nr = leggiReale();      // leggi il campo dati
       nuovoNodo->next = NULL;
       /* collega il nodo al precedente */
       if(*puntaHead==NULL)       // lista vuota?
             *puntaHead = nuovoNodo;     // il nuovo nodo diventa il primo
       else {           // lista non vuota, cerca l'ultimo nodo
          NODO nodoCorrente = *puntaHead;
          while(nodoCorrente->next!=NULL)
                nodoCorrente = nodoCorrente->next;
          /* ora nodoCorrente e' l'indirizzo dell'ultimo nodo della lista */
          nodoCorrente->next = nuovoNodo;
       }
       printf("Inserimento riuscito!\n\n");
}

/****** MAIN ******/

/* funzione principale */
int main() {
     int risposta = -1;                // valore inserito dall'utente
     NODO head = NULL;                   // lista inizializzata vuota
     /* ciclo di interazione con l'utente */
     while(risposta!=0) {
           printf("Che operazione vuoi svolgere?\n");
           printf("1) -> Immetti un numero reale in testa alla lista.\n\n");
           printf("2) -> Immetti un numero reale in coda alla lista.\n\n");
           printf("3) -> Visualizza la lista.\n\n");
           printf("0) -> Termina il programma.\n\n");
           scanf("%d", &risposta);

           /* inserimento in testa */
           if(risposta==1)
                   inserisciTesta(&head);
           /* inserimento in coda */
           if(risposta==2)
                   inserisciInCoda(&head);
           /* visualizzazione */
           else if(risposta==3)
                   stampaLista(head);
           /* numero sbagliato? */
           else if(risposta!=0)
                   printf("Questo numero non vuol dire niente. Riproviamo!\n\n");
   }
}
