#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct graph {
    // vertices
    int v;         
    // edges
    int e;         
    // directie src -> des
    int **dir;     
};

struct graph *createGraph(int v,int e) {   
    struct graph *G = new graph; 
    G->v = v;
    G->e = e;

    //alocare memorie
    G->dir = new int*[v];
      
    for (int i = 0;i < v;i++)
        G->dir[i] = new int[v];
      
    /*  0-----1             GRAFIC DE TEST
        | \   |
        |  \  |
        |   \ |
        2-----3     */
      
      
    //directie 0
    G->dir[0][1]=1;
    G->dir[0][2]=1;
    G->dir[0][3]=1;
      
    //directie 1
    G->dir[1][0]=1;
    G->dir[1][3]=1;
      
    //directie 2
    G->dir[2][0]=1;
    G->dir[2][3]=1;
      
    //directie 3
    G->dir[3][0]=1;
    G->dir[3][1]=1;
    G->dir[3][2]=1;

    return G;
}
  
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void afisareGrafListeAdiacente(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v) {
        cout << "\n Lista de Adiacenta a nodului " << v
             << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}

void afisareMatriceAdiacenta(int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}

//VARAIBILE DEFINITE GLOBAL
int V = 5; // NUMAR NODURI
vector<int> adj[V]; // lista adiacenta
int vertArr[20][20]; // matrice adiacenta
int count = 0;
int u, v;

void nodAdaug(int u, int v) {       //Adaugare Nod in matrice pt adiacenta
   vertArr[u][v] = 1;
   vertArr[v][u] = 1;
}

int gradVarf(struct graph *G, int ver)
{    
    int degree = 0;         
    for (int i=0; i<G->v; i++)     
  
        if (G-> dir[ver][i] == 1) 
            degree++;             
      
    if(G-> dir[ver][ver] == 1)
          degree++;
    return degree;         
}

void revenire() {
    cout << "\nDoriti sa mai continuati?\n";
    int y=0;
    cout <<"Introduceti 1 daca mai doriti sa efectuati operatie, altfel introduceti orice alt numar.\n";
    cin >> y;
    if (y==1)
        afisareMeniuPrincipal();
    else
        return 0;
}

void afisareMeniuPrincipal() {
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

void definitii() {
    system("CLS"); // Clear Screen
    cout << "Graf Neorientat: Se numeşte graf neorientat o pereche ordonată de multimi notată G=(V, M) unde V:este o multime finită şi nevidă, ale cărei elemente se numesc noduri sau vârfuri; si M: este o multime, de perechi neordonate de elemente distincte din V, ale cărei elemente
se numesc muchii.\n";
    cout << "Intr-un graf neorientat, se numeste lant o secventa de varfuri cu proprietatea ca oricare doua varfuri consecutive din secventa sunt adiacente. De exemplu, pentru graful dat, [3,1,2,5,1,3,1] este un lant cu lungimea 6.\n";
    cout << "Se numeste ciclu, un lant simplu in care varful initial coincide cu varful final. In alte cuvinte lantul pleaca din varful x si ajunge tot in varful x. De exemplu, pentru graful dat, [1,2,5,1,2,5,1] este un ciclu.\n";
    cout << "Graful G’=(V,E’) se numeste un graf partial al lui G daca E’ ⊂ E.\n";
    cout << "Un subgraf al lui G se obtine eliminand un varf si toate muchiile incidente cu acesta.\n";
    cout << "Un graf neorientat G = (V,E) se numeste bipartit daca multimea varfurilor sale poate fi partitionata in doua submultimi A si B nevid ( A ∪ B = V ; A ∩ B = Ø) astfel incat orice muchie sa aia o extremitate in A si una in B.\n";
    cout << "Un graf neorientat se numeste regulat daca toate varfurile sale au acelasi grad.\n";
    revenire();
}

void gradVarfMeniu() {
    system("CLS"); // Clear Screen
    cout << "Alege o optiune de mai jos:" << endl;
    cout << "1.Definitii:\n";
    cout << "2.Varf Izolat\n";
    cout << "3.Varf Terminal\n";
    cout << "4.Revenire\n";
}

void gradVarfDefinitii() {
    system("CLS");
    cout << "Varful izolat = un varf care are gradul 0.\n";
    cout << "Varful terminal = un varf care are gradul 1.\n";
    revenire();

}

void varfIzolatMeniu() {
    system("CLS");
    cout << "Alege o optiune de mai jos:" << endl;
    cout << "1.Definitie:\n";
    cout << "2.Aplicatie\n";
    cout << "3.Revenire\n";
}

void varfIzolat1() {
    cout << "Varful izolat = un varf care are gradul 0.\n";
    revenire();
}

void varfIzolat2(int varf) {
    int grad = INT_MIN;
    grad = gradVarf(G,varf);
    if (grad == 0)
        cout <<"VARFUL ESTE IZOLAT\n";
    else
        cout <<"VARFUL NU ESTE IZOLAT\n";
    revenire();
}

void VarfTerminalMeniu() {
    system("CLS");
    cout << "Alege o optiune de mai jos:" << endl;
    cout << "1.Definitie:\n";
    cout << "2.Aplicatie\n";
    cout << "3.Revenire\n";
}

void varfTerminal1() {
    cout << "Varful terminal = un varf care are gradul 1.\n";
    revenire();
}

void varfTerminal2(int varf) {
    int grad = INT_MIN;
    grad = gradVarf(G,varf);
    if (grad == 1)
        cout <<"NODUL ESTE TERMINAL\n";
    else
        cout <<"NODUL NU ESTE TERMINAL\n";
    revenire();
}

void parcurgereMeniu() {
    system("CLS");
    cout << "Alege o optiune de mai jos:" << endl;
    cout << "1.Liste Adiacenta\n";
    cout << "2.Vectorul Muchiilor\n";
    cout << "3.Matricea de adiacenta\n";
}

void listeAdiacenta() {
    system("CLS");
    cout << "Alege o optiune de mai jos:" << endl;
    cout << "1.Definitie\n";
    cout << "2.Verificare\n";
    cout << "3.Intoarcere\n";
}

void listeAdiacenta1() {
    cout << "Reprezentarea grafului G prin liste de adiacență constă în:\n- precizarea numărului de vârfuri, n;\n- pentru fiecare vârf i, se precizează lista i a vecinilor săi, adică lista nodurilor adiacente cu nodul i.\n";
    revenire();
}

void listeAdiacenta2() {
    afisareGrafListeAdiacente(adj, V);
    cout << endl;
    revenire();
}

void matriceAdiacenta1() {
    cout << "Daca exista o muchie determinata de varfurile x si y atunci, varfurile x si y se numesc adiacente. De asemenea, varfurile x si y sunt considerate incidente cu muchia pe care o formeaza. Fiecare extremitate a unei muchii este considerata incidenta cu muchia respectiva.\n";
    revenire();
}

void matriceAdiacenta2() {
    cout << "Adaugati noduri in graf: (numar)\n";
    cin >> v;
    int i = 0;
    while (v>i) {
        cin >> u >> v;
        nodAdaug(u,v);
        i++;
        cout << endl;
    }
    
    afisareMatriceAdiacenta(v);

    cout << endl;

    revenire();
}

