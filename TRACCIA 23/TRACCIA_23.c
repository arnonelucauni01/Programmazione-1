/*  TRACCIA 23

Scrivere una function C che ha come input i dati che identificano uno studente (nome, cognome, matricola)
e che restituisce in output una struttura dati opportuna, che contiene i dati di identificazione e il libretto universitario
con al massimo 20 esami. Ogni esame è caratterizzato da denominazione, cfu e voto.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct anagraficaStudente {
    char nome[100];
    char cognome[100];
    int  matricola;
} anagraficaStudente;


typedef struct esame {
    char nomeEsame[50];
    int  Voto;
    int cfu;
} esame;

typedef struct studente {
    anagraficaStudente alunno;
    esame libretto[20];
} studente;

char *corsi[] = { "Programmazione 1", "Matematica 1", "Architettura dei calcolatori",
        "Fisica", "Programmazione 2", "Matematica 2", "Econimia aziendale",
        "Inglese", "Algoritmi e struttre dati", "Tecnologie web", "Programmazione 3"
    };

int *CFU[] = {9, 12, 12, 6, 12, 6, 6, 3, 9, 12, 12};

void dividiLinee(){
    printf("\n\n");
}

void stampaBannerBenvenuto(){
    printf("%s", "|  ********************************  |\n");
    printf("%s", "      ----GESTIONE STUDENTI----");
    printf("%s", "\n|  ********************************  |\n");
}

void stampaBannerAnagraficaStudente(){
    dividiLinee();
    printf("%s", "|  ********************************  |\n");
    printf("%s", "     ----ANAGRAFICA STUDENTI----");
    printf("%s", "\n|  ********************************  |\n");
}

void stampaBannerEsamiDati(){
    dividiLinee();
    printf("%s", "|  ********************************  |\n");
    printf("%s", "      ----Dati esami fatti----");
    printf("%s", "\n|  ********************************  |\n");
}

anagraficaStudente creazioneAnagraficaStudente(char nome[100], char cognome[100], int matricola){
    anagraficaStudente s;
    strcpy(s.nome, nome);
    strcpy(s.cognome, cognome);
    s.matricola = matricola;
    return s;

}

studente creazioneStudente(anagraficaStudente a){
    studente s;
    strcpy(s.alunno.nome, a.nome);
    strcpy(s.alunno.cognome, a.cognome);
    s.alunno.matricola = a.matricola;

    int nLibretto = 0;
    for(int i = 0; i < sizeof(corsi) / sizeof(corsi[0]); i++){
        if(selezioneEsameDatoInput(corsi[i])){
            printf("%s", "Corso svolto!\n");
            int voto = selezioneVotoEsameDatoInput();
            strcpy(s.libretto[nLibretto].nomeEsame, corsi[i]);
            s.libretto[nLibretto].Voto = voto;
            s.libretto[nLibretto].cfu = CFU[i];
        } else {
            printf("Corso da svolgere");
            strcpy(s.libretto[nLibretto].nomeEsame, corsi[i]);
            s.libretto[nLibretto].Voto = 0;
            s.libretto[nLibretto].cfu = 0;
        }
        nLibretto++;

    }
    return s;
}

int selezioneEsameDatoInput(char corso[50]){
    char scelta;
    printf("%s %s %s", "\nLo studente ha superato il corso: ", corso, "? S/N: ");
    scanf("\n%c", &scelta);
    int valore = scelta;
    if(valore == 83 || valore == 115){
        return 1;
    } else if(valore == 78 || valore == 110){
        return 0;
    } else {
        printf("Valore inserito non valido, riprovare\n");
        return selezioneEsameDatoInput(corso);
    }
}

int selezioneVotoEsameDatoInput(){
    int scelta;
    printf("Inserire un voto tra 18 e 30: ");
    scanf("\n%d", &scelta);
    if(scelta > 17 && scelta < 31){
        return scelta;
    } else {
        printf("valore non valido, inserirne uno corretto!\n");
        return selezioneVotoEsameDatoInput();
    }
}

void stampaAnagraficaStudente(anagraficaStudente s){
    stampaBannerAnagraficaStudente();
    dividiLinee();
    printf("%s", "|  ********************************  |");
    printf("%s %s", "\n - Nome dello studente: ", s.nome);
    printf("%s %s", "\n - Cognome dello studente: ", s.cognome);
    printf("%s %d", "\n - matricola dello studente: ", s.matricola);
    printf("%s", "\n|  ********************************  |");
}

void stampaEsame(esame e){
    dividiLinee();
    printf("%s", "|  ********************************  |");
    printf("%s %s", "\n - Nome dell'esame: ", e.nomeEsame);
    printf("%s %d", "\n - Voto dell'esame: ", e.Voto);
    printf("%s %d", "\n - CFU dell'esame: ", e.cfu);
    printf("%s", "\n|  ********************************  |");
}

void stampaStudente(studente s){
    system("cls");
    int size = sizeof(corsi) / sizeof(corsi[0]);
    stampaAnagraficaStudente(s.alunno);
    stampaBannerEsamiDati();
    for(int i = 0; i < size; i++){
        s.libretto[i].Voto > 0 ?  stampaEsame(s.libretto[i]) : 0;
    }
}


void main() {
    stampaBannerBenvenuto();
    anagraficaStudente s = creazioneAnagraficaStudente("Tizio", "Baudo", 10);
    stampaStudente(creazioneStudente(s));
}
