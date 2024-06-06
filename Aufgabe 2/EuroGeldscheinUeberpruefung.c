//Übung 4, Aufgabe 2: "EuroGeldscheinUeberpruefung(LK,MS).c" (06.06.2024) (Autoren:  Leif Kendelbacher, Mattis Schreiner)
//Programm zur Überprüfung eines Euro-Geldscheines anhand der Seriennummer
#include <stdio.h>

int eingabeSeriennummer();

char eingabeBuchstabe();

int main() {
	//Startnachricht
	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*       %cberpr%cfung eines Euro-Geldscheines          *\n", '\x9a', '\x81');
	printf("*                                                    *\n");
	printf("******************************************************\n\n");

	eingabeSeriennummer();

	return 0;
}

int eingabeSeriennummer() {
	int seriennummer[12] = {0};
	int korrekteEingabe = 0;

	printf("Bitte geben Sie den ersten Buchstaben ein.\n");
	seriennummer[0] = eingabeBuchstabe();
	return 0;
}


char eingabeBuchstabe() {
	char eingabe = 0;						//Eingegebene Zahl
	int korrekteEingabe = 1;				//Wenn falsche Eingabe, dann = 0

	do {
		printf("Buchstabe: ");

		korrekteEingabe = scanf_s("%c", &eingabe, 1);

		//Nur Buchstaben von a-z / A-Z
		if ((eingabe > 90 || eingabe < 65) && (eingabe > 122 || eingabe < 97))
			korrekteEingabe = 0;

		if (getchar() != '\n') {
			korrekteEingabe = 0;
			while (getchar() != '\n');
		}
	} while (!korrekteEingabe);

	return eingabe;
}