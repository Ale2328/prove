//gioco del 15
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int monete = 11;
char diff;
int probInizio;


int controlloInput();
void inizioMacchina();
void inizioGiocatore();


int main()
{
	probInizio = rand()%100 + 1;

	printf("Ciao! Seleziona una difficolta'\n");
	printf("F = facile, M = medio, D = difficile\n");
	scanf("%c", &diff);
	
	switch(diff)
	{
		case 'f':
			if(probInizio >= 80)
			{
				inizioGiocatore();
			}
			else
			{
				inizioMacchina();
			}
			break;
		
		case 'm':
			if(probInizio >= 60)
			{
				inizioGiocatore();
			}
			else
			{
				inizioMacchina();
			}
			break;
			
		case 'd':
			if(probInizio >= 30)
			{
				inizioGiocatore();
			}
			else
			{
				inizioMacchina();
			}
			break;
			
		default:
			printf("Hai immesso una difficolta' inesistente\n");		
			break;	
	}
}

void inizioGiocatore()
{
	srand(time(NULL));
	int probSconf;
	
	probSconf = rand()%100 + 1;
	
}
