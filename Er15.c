/*
	Name: Il gioco del 15
	Copyright: Nessuno
	Author: Michele Pagano
	Date: 16/02/21 10.31
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
int contaPlayer, contaMacchina; //implementazione del sistema di conta delle mosse.

//dichiarazione delle funzioni di difficoltà
void facile();
void medio();
void difficile();

//dichiarazione delle funzioni di gioco
int controlloInput();
void inizioMacchinaC();
void inizioGiocatoreC();
void determinato();


int main()  //TO DO: ricordarsi di scommentare le varie parti del codice
{
	probInizio = rand()%100 + 1;
	probSconf = rand()%100 + 1;
	
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
			difficile();
			break;
			
		default:
			printf("Hai immesso una difficolta' inesistente\n");		
			break;	
	}
}

int controlloInput(int input)
{
	do
	{
		printf("Ci sono %d monete. Quante monete vuoi prendere? \n", monete);
		scanf("%d", &input);
		
		if(input <= 0 && input >= 4)
		{
			printf("Per favore insersci da un numero da 1 a 3");	
		}		
	}
	while(input <= 0 && input >= 4);
}

void inizioGiocatoreC()
{
	while(monete > 0)
	{	
		controlloInput(moneteRaccolteP);
		
		monete -= moneteRaccolteP;
		contaPlayer += 1;
		
		moneteRaccolteM = rand()%3 + 1;
		monete -= moneteRaccolteM;
		contaMacchina += 1;
		
		printf("La macchina ha preso %d monete. Ne rimangono %d\n", moneteRaccolteM, monete);
	}
}

void inizioMacchinaC()
{	
	while(monete > 0)
	{
		moneteRaccolteM = rand()%3 + 1;
		monete -= moneteRaccolteM;
		contaMacchina += 1;
		printf("La macchina ha preso %d monete. Ne rimangono %d\n", moneteRaccolteM, monete);
		
		controlloInput(moneteRaccolteP);
		monete -= moneteRaccolteP;
		contaPlayer += 1;
	}
}

void determinato()
{
	switch(moneteRaccolteP)
	{
		case 1:
			moneteRaccolteM = 3;
			monete -= moneteRaccolteM;
			printf("La macchina ha preso %d monete. Ne rimangono %d\n", moneteRaccolteM, monete);
			break;
			
		case 2:
			moneteRaccolteM = 2;
			monete -= moneteRaccolteM;
			printf("La macchina ha preso %d monete. Ne rimangono %d\n", moneteRaccolteM, monete);
			break;	
			
		case 3:
			moneteRaccolteM = 1;
			monete -= moneteRaccolteM;
			printf("La macchina ha preso %d monete. Ne rimangono %d\n", moneteRaccolteM, monete);
			break;	
	}
}


void facile()
{

		if(probInizio >= 80)
		{
			if(probSconf > 10)
				inizioGiocatoreC();
			else
			{
				while(monete > 0)
				{
					controlloInput(moneteRaccolteP);
					determinato();
				}
			}
		}
		else
		{
			if(probSconf > 10)
				inizioMacchinaC();
			else
			{
				srand(time(NULL));
				moneteRaccolteM = rand()%3 + 1;
				monete -= moneteRaccolteM;
				printf("La macchina ha preso %d monete. Ne rimangono %d\n", moneteRaccolteM, monete);
				
				while(monete > 0)
				{
					controlloInput(moneteRaccolteP);
					determinato();
				}
			}
		}
}

void medio()
{
	if(probInizio >= 50)
	{
		if(probSconf > 40)
			inizioGiocatoreC();
		else
		{
			while(monete > 0)
			{
				controlloInput(moneteRaccolteP);
				determinato();
			}
		}
	}
	else
	{
		if(probSconf > 40)
			inizioMacchinaC();
		else
		{
			srand(time(NULL));
			moneteRaccolteM = rand()%3 + 1;
			monete -= moneteRaccolteM;
			printf("La macchina ha preso %d monete. Ne rimangono %d\n", moneteRaccolteM, monete);
				
			while(monete > 0)
			{
				controlloInput(moneteRaccolteP);
				determinato();
			}
		}
	}
	
}

void difficile()
{
	if(probInizio >= 10)
	{
		if(probSconf > 75)
			inizioGiocatoreC();
		else	
		{
			while(monete > 0)
			{
				controlloInput(moneteRaccolteP);
				determinato();
			}
		}
	}
	else
	{
		if(probSconf > 75)
			inizioMacchinaC();
		else
		{
			srand(time(NULL));
			moneteRaccolteM = rand()%3 + 1;
			monete -= moneteRaccolteM;
			printf("La macchina ha preso %d monete. Ne rimangono %d\n", moneteRaccolteM, monete);
				
			while(monete > 0)
			{
				controlloInput(moneteRaccolteP);
				determinato();
			}
		}
	}
	
}
