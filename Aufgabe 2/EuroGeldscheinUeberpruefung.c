//�bung 4, Aufgabe 2: "EuroGeldscheinUeberpruefung(LK,MS).c" (06.06.2024) (Autoren:  Leif Kendelbacher, Mattis Schreiner)
//Programm zur �berpr�fung eines Euro-Geldscheines anhand der Seriennummer
#include <stdio.h>

int eingabeSeriennummer(int seriennummer[]);

int eingabeBuchstabe();

int eingabeZahl(int anzahlZiffern, int ausgabeZiffern[]);

int main() {
	int seriennummer[12] = { 0 };

	//Startnachricht
	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*       %cberpr%cfung eines Euro-Geldscheines          *\n", '\x9a', '\x81');
	printf("*                                                    *\n");
	printf("******************************************************\n\n");

	eingabeSeriennummer(seriennummer);

	return 0;
}

int eingabeSeriennummer(int seriennummer[]) {
	int korrekteEingabe = 0;
	int anfangFuenfZiffern[5] = { 0 },
		mitteVierZiffern[4] = { 0 },
		letzteZiffer[1] = { 0 };

	printf("Im folgenden m\x81ssen Sie eine Seriennummer st%cckweise eingeben.\n\n", '\x81');

	printf("Bitte geben Sie den ersten Buchstaben ein.\n");
	seriennummer[0] = eingabeBuchstabe();

	printf("Bitte geben Sie den zweiten Buchstaben ein.\n");
	seriennummer[1] = eingabeBuchstabe();

	printf("Bitte geben Sie die ersten f�nf Ziffern ein.\n");
	eingabeZahl(5, anfangFuenfZiffern);

	printf("Bitte geben Sie die nachfolgenden vier Ziffern ein.\n");
	eingabeZahl(4, mitteVierZiffern);

	printf("Bitte geben Sie die letzte Ziffer ein.\n");
	eingabeZahl(1, letzteZiffer);

	return 0;
}


int eingabeBuchstabe() {
	char eingabe = 0;						//Eingegebener Buchstabe 
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

	//Konvertierung zu Gro�buuchstaben
	if (eingabe >= 97)
		eingabe = eingabe - 'a' + 'A';

	return eingabe;
}

int eingabeZahl(int anzahlZiffern, int ausgabeZiffern[]) {
	char eingabe[6] = { 0 };					//Eingegebener Zahl, einzeln als Ziffern gespeichert Ascii Buchstaben gespeichert
	int korrekteEingabe = 1;					//Wenn falsche Eingabe, dann = 0

	do {
		if (korrekteEingabe)
			printf("Zahl: ");
		else
			printf("Bitte geben Sie eine %d-stellige Zahl ein: ", anzahlZiffern);

		korrekteEingabe = scanf_s("%s", &eingabe, 6);

		//�berpr�fung ob mehr als 5 Zahlen eingegeben
		if (getchar() != '\n') {
			korrekteEingabe = 0;
			while (getchar() != '\n');
		}

		//�berpr�fung, ob korrekte Anzahl an Ziffern
			if (eingabe[anzahlZiffern] != '\0')
				korrekteEingabe = 0;

		//�berpr�fung ob alles Zahlen und speichern als integerzahl
		for (int i = 0; i < anzahlZiffern; i++) {
			if (eingabe[i] < 48 || eingabe[i] > 57) {
				korrekteEingabe = 0;
				
			}
			ausgabeZiffern[i] = (int)eingabe[i] - 48;
		}

	} while (!korrekteEingabe);

	return 0;
}