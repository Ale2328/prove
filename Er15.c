/*
	Name: Il gioco del 15
	Copyright: Nessuno
	Author: Michele Pagano
	Date: 15/02/21 21.41
	Description: Un semplice gioco formato da 2 giocatori e 11 monete sul tavolo,
				 l'ultimo a prendere le monete perde.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//dichiarazione delle variabili globali necessarie
int monete = 11;
int moneteRaccolteP, moneteRaccolteM;
char diff;
int probInizio, probSconf;

//dichiarazione delle funzioni di difficoltà
void facile();
void medio();
void difficile();

//dichiarazione delle funzioni di gioco
int controlloInput();
void inizioMacchinaCasuale();
void inizioMacchinaDeterminato();
void inizioGiocatoreCasuale();
void inizioGiocatoreDeterminato();

int main()  //TO DO: ricordarsi di scommentare le varie parti del codice
{
	probInizio = rand()%100 + 1;

	printf("Ciao! Seleziona una difficolta'\n");
	printf("F = facile, M = medio, D = difficile\n");
	scanf("%c", &diff);
	
	switch(diff)
	{
		case 'f':
			facile();
			break;
		
		case 'm':
			medio();
			break;
			
		case 'd':
			diffile();
			break;
			
		default:
			printf("Hai immesso una difficolta' inesistente\n");		
			break;	
	}
}

void facile()
{
	srand(time(NULL));
	probSconf = rand()%100 + 1;
	
	if(probInizio >= 80)
	{
		if(probSconf > 10)
			inizioGiocatoreCasuale();
		else
//			inizioGiocatoreDeterminato();
	}
	else
	{
		if(probSconf > 10)
//			inizioMacchinaCasuale();
		else
//			inizioMacchinaDeterminato();
	}
	
}

void medio()
{
	srand(time(NULL));
	probSconf = rand()%100 + 1;
	
	if(probInizio >= 50)
	{
		if(probSconf > 40)
			inizioGiocatoreCasuale();
		else
//			inizioGiocatoreDeterminato();
	}
	else
	{
		if(probSconf > 40)
//			inizioMacchinaCasuale();
		else
//			inizioMacchinaDeterminato();
	}
	
}

void difficile()
{
	srand(time(NULL));
	probSconf = rand()%100 + 1;
	
	if(probInizio >= 10)
	{
		if(probSconf > 75)
			inizioGiocatoreCasuale();
		else
//			inizioGiocatoreDeterminato();
	}
	else
	{
		if(probSconf > 75)
//			inizioMacchinaCasuale();
		else
//			inizioMacchinaDeterminato();
	}
	
}

int controlloInput(int input)
{
	do
	{
		printf("Ci sono %d monete. Quante monete vuoi prendere? ", monete);
		scanf("%d", &input);
		
		if(input <= 0 && input >= 4)
			printf("Per favore insersci da un numero da 1 a 3");
		
		return input;		
	}
	while(input <= 0 && input >= 4);
	
}

void inizioGiocatoreCasuale()
{
	srand(time(NULL));
	int contaPlayer, contaMacchina; //implementazione del sistema di conta delle mosse.
	
	while(monete > 0)
	{
		controlloInput(moneteRaccolteP);	
		monete -= moneteRaccolteP;
		contaPlayer += 1;
		
		moneteRaccolteM = rand()%3 + 1;
		monete -= moneteRaccolteM;
		contaMacchina += 1;
		
		printf("La macchina ha raccolto %d monete. Rimangono %d monete. ", moneteRaccolteM, monete);
	}
	
	if(contaMacchina > contaPlayer) //TO DO: verificare il funzionamento dell'efficienza del sistema di conta nella realtà
	{
		printf("La macchina ha perso");
	}
	else
	{
		printf("La macchina ha vinto");
	}
	
}
