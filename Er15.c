//gioco del 15
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int monete = 11;

void facile();
void medio();
void difficile();

int controlloInput();
void inizioMacchina();
void inizioGiocatore();




int main()
{
	char diff;
	
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

int controlloInput(int monetePlayer)
{
	
}

void facile()
{
	srand(time(NULL));
	int probInizio;
	
	probInizio = rand()%100 + 1;
	
	if(probInizio >= 80)
	{
		inizioGiocatore();
	}
	else
	{
		inizioMacchina();
	}
}


