//Übung 4, Aufgabe 3: "EuroGeldscheinUeberpruefung(LK,MS).c" (07.06.2024) (Autoren:  Leif Kendelbacher, Mattis Schreiner)
//Programm zur Sortierung von Zufallszahlen
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LENGTH 10

void selectsort(int n, int arr[]);

int main() {
	int i = 0;
	int arr[LENGTH] = { 0 };
	srand(100);
	printf("Vor dem Sortieren\n");
	for (i = 0; i < LENGTH; i++)
	{
		arr[i] = rand();
		printf("%6d", arr[i]);
	}
	printf("\n");
	selectsort(LENGTH, arr);
	printf("Nach dem Sortieren\n");
	for (i = 0; i < LENGTH; i++)
		printf("%6d", arr[i]);
	printf("\n");
	return 0;
}

void selectsort(int n, int arr[]) {
	int j = 0;
	int i = 0;
	int min = 0;
	int hilf = 0;

	while (j < n - 1) {
		min = j;
		i = j + 1;
		while (i < n) {
			if (arr[i] < arr[min]) {
				min = i;

			}
			i++;
		}
		hilf = arr[j];
		arr[j] = arr[min];
		arr[min] = hilf;
		j++;
	}
	return;
}