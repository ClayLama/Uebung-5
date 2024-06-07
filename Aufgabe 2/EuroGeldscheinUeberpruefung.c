//Übung 4, Aufgabe 2: "EuroGeldscheinUeberpruefung(LK,MS).c" (06.06.2024) (Autoren:  Leif Kendelbacher, Mattis Schreiner)
//Programm zur Überprüfung eines Euro-Geldscheines anhand der Seriennummer
#include <stdio.h>

/// Ziel:	Es wird eine Seriennummer in drei Stücken eingegeben und validiert. Anschließend speichern in Parameter
/// Parameter: Vektor, in dem die einzelnen Ziffern gespeichert werden
/// Return:	/
void eingabeSeriennummer(int seriennummer[]);

/// Ziel:	Ein Buchstabe wird eingegeben und validiert
/// Parameter: /
/// Return:	Eingegebner Buchstabe als Ascii Code
int eingabeBuchstabe();

/// Ziel:	Eingabe einer Zahl (mit bestimter Anzahl an Ziffern, gespeichert als Ziffern in Vektor)
/// Parameter: Anzahl an Ziffern, die eingegeben werden sollen / Vektor, in dem Ziffern gespeichert werden sollen
/// Return:	/
void eingabeZahl(int anzahlZiffern, int ausgabeZiffern[]);

/// Ziel:	Rekursive Berechnung einer Quersumme aus Vektor mit Zahlen (Buchstaben werden in Zahlen kovertiert)
/// Parameter: Vektor, mit einzelnen Ziffern / Zahlen, bei welchem Element die Quersumme anfängt und aufhört
/// Return:	Berechnete Quersumme
int berechnungQuersumme(int vektor[], int anfangszahl, int letzteZahl);

/// Ziel: Berechnete Quersumme wird nach Anforderungen der Prüfziffer umgerechnet
/// Parameter: Zu konvertierende Quersumme
/// Return:	/
void konvertiereQuersumme(int* quersumme);

/// Ziel: Ausgabe in der Konsole der eingegebenen Seriennummer
/// Parameter: Auszugebene Seriennummer
/// Return:	/
void ausgabeSeriennummer(int seriennummer[]);

int main() {
	int seriennummer[12] = { 0 };	//Eingegebene Seriennummer ([0-1] Buchstaben in Ascii Code, [2-10] Ziffern, [11] Prüfziffer)
	int berechnetePruefziffer = 0;	//Prüfziffer wird durch Quersumme und anschließende Konvertierung berechnet
	int schleife = 1;				//Wird auf 0 gesetzt, wenn Schleife beendet werden soll
	char eingabeBuchstabe = '\0';	//Eingegebener Buchstabe, bei Frage ob Schleifenwiederholung

	//Startnachricht
	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*       %cberpr%cfung eines Euro-Geldscheines          *\n", '\x9a', '\x81');
	printf("*                                                    *\n");
	printf("******************************************************\n");
	printf("Programm zur Ueberpruefung der Seriennummer eines Geldscheins.\n\n");

	while(schleife){
	//Eingabe der Seriennummer in 3 Teilen
	eingabeSeriennummer(seriennummer);
	printf("\n");

	//Überprüfung der Prüfziffer
	berechnetePruefziffer = berechnungQuersumme(seriennummer, 0, 10);
	konvertiereQuersumme(&berechnetePruefziffer);

	//Ausgabe vom Ergebnis
	printf("Der Geldschein mit der Seriennummer: \"");
	ausgabeSeriennummer(seriennummer);
	if (berechnetePruefziffer == seriennummer[11]) {
		printf("\" ist in Ordnung.\nDie Pruefziffer ist korrekt!");
	}
	else {
		printf("\" ist gefaelscht.\nDie Pruefziffer ist falsch!");
	}

	//Abfrage, ob Schleifenwiederholung
	printf("\n\nM%cchten Sie eine weitere Seriennummer ueberpruefen? (J/N): ", '\x94');
	scanf_s("%c", &eingabeBuchstabe, 1);
	while (getchar() != '\n');
	printf("\n");
	if (eingabeBuchstabe != 'J' && eingabeBuchstabe != 'j')
		schleife = 0;
}
	return 0;
}

/// Ziel:	Es wird eine Seriennummer in drei Stücken eingegeben und validiert. Anschließend speichern in Parameter
/// Parameter: Vektor, in dem die einzelnen Ziffern gespeichert werden
/// Return:	/
void eingabeSeriennummer(int seriennummer[]) {
	int eingabeZiffern[10] = { 0 };			//Die Ziffern der Seriennummer werden gespeichert

	//Eingabe der Seriennummer in 3 Stücken
	printf("Im folgenden m\x81ssen Sie eine Seriennummer st%cckweise eingeben.\n\n", '\x81');

	printf("Bitte geben Sie den ersten Buchstaben ein.\n");
	seriennummer[0] = eingabeBuchstabe();

	printf("\nBitte geben Sie den zweiten Buchstaben ein.\n");
	seriennummer[1] = eingabeBuchstabe();

	printf("\nBitte geben Sie die zehn Ziffern ein.\n");
	eingabeZahl(10, eingabeZiffern);

	//Zusammensetzung der Seriennummer und speichern als Vektor in seriennummer[]
	for (int i = 2; i <= 11; i++) {
		seriennummer[i] = eingabeZiffern[i - 2];
	}
	return;
}

/// Ziel:	Ein Buchstabe wird eingegeben und validiert
/// Parameter: /
/// Return:	Eingegebner Buchstabe als Ascii Code
int eingabeBuchstabe() {
	char eingabe = 0;						//Eingegebener Buchstabe 
	int korrekteEingabe = 1;				//Wenn falsche Eingabe, dann = 0

	do {
		printf("Buchstabe: ");

		korrekteEingabe = scanf_s("%c", &eingabe, 1);

		//Nur Buchstaben von a-z / A-Z
		if ((eingabe > 90 || eingabe < 65) && (eingabe > 122 || eingabe < 97))
			korrekteEingabe = 0;

		//Nur max ein Buchstabe
		if (getchar() != '\n') {
			korrekteEingabe = 0;
			while (getchar() != '\n');
		}
	} while (!korrekteEingabe);

	//Konvertierung zu Großbuuchstaben
	if (eingabe >= 97)
		eingabe = eingabe - 'a' + 'A';

	return eingabe;
}

/// Ziel:	Eingabe einer Zahl (mit bestimter Anzahl an Ziffern, gespeichert als Ziffern in Vektor)
/// Parameter: Anzahl an Ziffern, die eingegeben werden sollen / Vektor, in dem Ziffern gespeichert werden sollen
/// Return:	/
void eingabeZahl(int anzahlZiffern, int ausgabeZiffern[]) {
	char eingabe[11] = { 0 };					//Eingegebener Zahl, einzeln als Ziffern gespeichert Ascii Buchstaben gespeichert
	int korrekteEingabe = 1;					//Wenn falsche Eingabe, dann = 0

	//Wird wiederholt bis korrekte Eingabe
	do {
		if (korrekteEingabe)
			printf("Zahl: ");
		else
			printf("Bitte geben Sie eine %d-stellige Zahl ein: ", anzahlZiffern);

		korrekteEingabe = scanf_s("%s", &eingabe, (anzahlZiffern + 1));

		//Überprüfung ob mehr als 5 Zahlen eingegeben
		if (getchar() != '\n') {
			korrekteEingabe = 0;
			while (getchar() != '\n');
		}

		//Überprüfung, ob korrekte Anzahl an Ziffern
		if (eingabe[anzahlZiffern] != '\0')
			korrekteEingabe = 0;

		//Überprüfung ob alles Zahlen und speichert ziffern als einzelne Integer
		for (int i = 0; i < anzahlZiffern; i++) {
			if (eingabe[i] < 48 || eingabe[i] > 57) {
				korrekteEingabe = 0;

			}
			ausgabeZiffern[i] = (int)eingabe[i] - 48;
		}

	} while (!korrekteEingabe);

	return;
}

/// Ziel:	Rekursive Berechnung einer Quersumme aus Vektor mit Zahlen (Buchstaben werden in Zahlen kovertiert)
/// Parameter: Vektor, mit einzelnen Ziffern / Zahlen, bei welchem Element die Quersumme anfängt und aufhört
/// Return:	Berechnete Quersumme
int berechnungQuersumme(int vektor[], int anfangszahl, int letzteZahl) {
	int ersteStelle = 0;			//Wenn eine Zahl zweistellig, dann wird die erste Ziffer hier gespeichert
	int querSummeBuchstabe = 0;		//Quersumme der Zahl wird hier gespeichert

	//Buchstaben werden durch Zahl ersetzt
	if (vektor[anfangszahl] > 57) {
		querSummeBuchstabe = vektor[anfangszahl] - 64;

		//Quersumme falls Buchstabe => Zweistellige Zahl
		if (querSummeBuchstabe > 9) {
			ersteStelle = (int)(querSummeBuchstabe / 10);
			querSummeBuchstabe = ersteStelle + (querSummeBuchstabe - (ersteStelle * 10));
		}
		return querSummeBuchstabe + berechnungQuersumme(vektor, anfangszahl + 1, letzteZahl);
	}

	if (anfangszahl == letzteZahl)
		return vektor[anfangszahl];

	return vektor[anfangszahl] + berechnungQuersumme(vektor, anfangszahl + 1, letzteZahl);
}

/// Ziel: Berechnete Quersumme wird nach Anforderungen der Prüfziffer umgerechnet
/// Parameter: Zu konvertierende Quersumme
/// Return:	/
void konvertiereQuersumme(int* quersumme) {
	*quersumme = *quersumme % 9;
	*quersumme = 7 - *quersumme;
	*quersumme = (*quersumme == 0) ? 9 : *quersumme;
	*quersumme = (*quersumme == -1) ? 8 : *quersumme;
	return;
}

/// Ziel: Ausgabe in der Konsole der eingegebenen Seriennummer
/// Parameter: Auszugebene Seriennummer
/// Return:	/
void ausgabeSeriennummer(int seriennummer[]) {
	for (int i = 0; i < 2; i++)
		printf("%c", seriennummer[i]);
	for (int i = 2; i < 12; i++)
		printf("%d", seriennummer[i]);
	return;
}