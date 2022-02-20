#include <iostream>
#include <stdlib.h>

using namespace std;

void afisareMeniuPrincipal {
    system("CLS"); // Clear Screen
    cout << "Alege o optiune de mai jos:" << endl;
    cout << "1.Definitii:\n";
    cout << "2.Gradul unui varf:\n";
    cout << "3.Metode de reprezentare:\n";
    cout << "4.Parcurgere:\n";
    cout << "5.Conexitate:\n";
    cout << "6.Graf Hamiltonian:\n";
    cout << "7.Graf Eulerian:\n";
    cout << "8.Aplicatii:\n";
    cout << "9.Test:\n";
    cout << "10.Iesire:\n";
}

void definitii{
    system("CLS"); // Clear Screen
    cout << "Graf Neorientat: Se numeşte graf neorientat o pereche ordonată de multimi notată G=(V, M) unde V:este o multime finită şi nevidă, ale cărei elemente se numesc noduri sau vârfuri; si M: este o multime, de perechi neordonate de elemente distincte din V, ale cărei elemente
se numesc muchii.\n";
    cout << "Intr-un graf neorientat, se numeste lant o secventa de varfuri cu proprietatea ca oricare doua varfuri consecutive din secventa sunt adiacente. De exemplu, pentru graful dat, [3,1,2,5,1,3,1] este un lant cu lungimea 6.\n";
    cout << "Se numeste ciclu, un lant simplu in care varful initial coincide cu varful final. In alte cuvinte lantul pleaca din varful x si ajunge tot in varful x. De exemplu, pentru graful dat, [1,2,5,1,2,5,1] este un ciclu.\n";
    cout << "Graful G’=(V,E’) se numeste un graf partial al lui G daca E’ ⊂ E.\n";
    cout << "Un subgraf al lui G se obtine eliminand un varf si toate muchiile incidente cu acesta.\n";
    cout << "Un graf neorientat G = (V,E) se numeste bipartit daca multimea varfurilor sale poate fi partitionata in doua submultimi A si B nevid ( A ∪ B = V ; A ∩ B = Ø) astfel incat orice muchie sa aia o extremitate in A si una in B.\n";
    cout << "Un graf neorientat se numeste regulat daca toate varfurile sale au acelasi grad.\n";
}

