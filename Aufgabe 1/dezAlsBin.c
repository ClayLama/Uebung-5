//Übung 4, Aufgabe 1: "dezAlsBin(LK,MS).c" (02.06.2024) (Autoren:  Leif Kendelbacher, Mattis Schreiner) änderung
//Programm zur Umrechnung einer Dezimalzahl in eine Binärzahl
#include <stdio.h>
#include <math.h>

/// Ziel: Eingabe und Validierung des eingegebenen Integers
/// Parameter: Minimal mögliche Eingabe, Maximal mögliche Eingabe (Maximal 4-Stellig)
/// Return: Eingegebene Zahl
int eingabeInt(int minimalZahl, int maximalZahl);

/// Ziel:	Die Binärdarstellung einer Dezimalzahl soll ermittelt werden
/// Parameter: Eine Zahl dez, die Adresse eines Vektor zum Speichern der Binärdarstellung, die Länge des Vektors
/// Return:	Return 0 bei erfolgreicher Umrechnung
int dezAlsBin(int dez, int* vektor, int anzahl);

/// Ziel:	Ein Vektor soll für den Benutzer ausgegeben werden
/// Parameter: Die Adresse eines Vektors in dem die Binärzahl gespeichert ist, die länge des Vektors
/// Return:	Return 0 bei erfolgreichem Durchlauf
int druckeVektor(int* vektor, int anzahl, int eingegebeneZahl);

main() {
	int korrekteEingabe = 0;		//Variable zur Abfrage einer korrekten Eingabe
	int zahlBenutzer = 0;			//Speichert die Nutzereingabe 
	int vektor[8] = { 0 };			//Speichert die Binärdarstellung der Zahl
	int minimalZahl = 0,
		maximalZahl = 255;			//maximale und minimale Eingabe
	int schleife = 1;				//Wird auf 0 gesetzt, wenn Schleife beendet werden soll
	char eingabeBuchstabe = '\0';	//Eingabe, ob Schleife fortgesetzt werden soll

	//Startnachricht
	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*              Dezimalzahl als Bin\x84rzahlen             *\n");
	printf("*                                                    *\n");
	printf("******************************************************\n\n");

	while (schleife) {
		//Fragt eine Zahl zwischen 0 und 255 vom Benutzer ab, bis eine korrekte Eingabe angegeben wurde
		printf("Es wird eine Dezimalzahl ben\x94tigt.\n");
		zahlBenutzer = eingabeInt(minimalZahl, maximalZahl);

		dezAlsBin(zahlBenutzer, vektor, 8);		//In Vektor wird Binärzahl gespeichert
		druckeVektor(vektor, 8, zahlBenutzer);	//Vektor wird in Konsole ausgegeben

		//Abfrage, ob Schleifenwiederholung
		printf("\n\nM%cchten Sie eine weitere Binaerzahl berechnen? (J/N): ", '\x94');
		scanf_s("%c", &eingabeBuchstabe, 1);
		while (getchar() != '\n');
		printf("\n");
		if (eingabeBuchstabe != 'J' && eingabeBuchstabe != 'j')
			schleife = 0;
	}
	return 0;
}

/// Ziel: Eingabe und Validierung des eingegebenen Integers
/// Parameter: Minimal mögliche Eingabe, Maximal mögliche Eingabe (Maximal 4-Stellig)
/// Return: Eingegebene Zahl
int eingabeInt(int minimalZahl, int maximalZahl) {
	int eingabe = 0;						//Eingegebene Zahl
	int korrekteEingabe = 1;				//Wenn falsche Eingabe, dann = 0

	printf("Geben Sie eine Ganzzahl ein: ");
	do {
		//Fehlerausgabe
		if (!korrekteEingabe)
			printf("Bitte geben Sie eine Ganzzahl zwischen %d und %d ein: ", minimalZahl, maximalZahl);

		korrekteEingabe = scanf_s("%4d", &eingabe);

		if (eingabe > maximalZahl || eingabe < minimalZahl)
			korrekteEingabe = 0;
		if (getchar() != '\n') {
			korrekteEingabe = 0;
			while (getchar() != '\n');
		}
	} while (!korrekteEingabe);
	return eingabe;
}

/// Ziel:	Die Binärdarstellung einer Dezimalzahl soll ermittelt werden
/// Parameter: Eine Zahl dez, die Adresse eines Vektor zum Speichern der Binärdarstellung, die Länge des Vektors
/// Return:	Return 0 bei erfolgreicher Umrechnung
int dezAlsBin(int dez, int* vektor, int anzahl) {
	for (int i = anzahl - 1; i >= 0; i--) {
		if ((int)pow(2, i) <= dez && dez) {
			vektor[anzahl - 1 - i] = 1;
			dez = dez - (int)pow(2, i);
		}
		else
			vektor[anzahl - 1 - i] = 0;
	}
	return 0;
}

/// Ziel:	Ein Vektor soll für den Benutzer ausgegeben werden
/// Parameter: Die Adresse eines Vektors in dem die Binärzahl gespeichert ist, die länge des Vektors
/// Return:	Return 0 bei erfolgreichem Durchlauf
int druckeVektor(int* vektor, int anzahl, int eingegebeneZahl) {
	printf("\nDie Binaerdarstellung der Zahl %d ist: ", eingegebeneZahl);
	for (int i = 0; i < anzahl; i++) {
		printf("%d", vektor[i]);
	}
	return 0;
}