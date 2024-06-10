//Übung 4, Aufgabe 3: "selectsort(LK,MS).c" (09.06.2024) (Autoren:  Leif Kendelbacher, Mattis Schreiner)
//Programm zur Sortierung von Zufallszahlen
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LENGTH 10			//Länge des Arrays mit Zufallszahlen

/// Ziel:	Aufsteigende Sortierung eines gegebenen Vektors
/// Parameter: Anzahl an Elementen / Vektor, der sortiert werden soll
/// Return:	/
void selectsort(int n, int arr[]);

int main() {
	int i = 0;			
	int arr[LENGTH] = { 0 };		//Array mit Zufallszahlen

	srand(time(NULL));

	//Ausgabe Array vor dem Sortieren
	printf("Vor dem Sortieren\n");
	for (i = 0; i < LENGTH; i++)
	{
		arr[i] = rand();
		printf("%6d", arr[i]);
	}
	printf("\n");

	selectsort(LENGTH, arr);

	//Ausgabe Array nach dem sortieren
	printf("Nach dem Sortieren\n");
	for (i = 0; i < LENGTH; i++)
		printf("%6d", arr[i]);
	printf("\n");
	return 0;
}

/// Ziel:	Aufsteigende Sortierung eines gegebenen Vektors
/// Parameter: Anzahl an Elementen / Vektor, der sortiert werden soll
/// Return:	/
void selectsort(int n, int arr[]) {
	int j = 0,
		i = 0;		//Durchlaufzählervariablen
	int min = 0;	//Geringster Wert
	int hilf = 0;	//Hilfsvariable zum tauschen

	while (j < n - 1) {
		min = j;
		i = j + 1;
		while (i < n) {
			if (arr[i] < arr[min])
				min = i;
			i++;
		}
		hilf = arr[j];
		arr[j] = arr[min];
		arr[min] = hilf;
		j++;
	}
	return;
}