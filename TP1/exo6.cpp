#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    // your code
};

struct DynaTableau{
    int* donnees;
    // your code
    int capacite; //taille max du tableau qui change si capacité est dépassé
    int taille; //nombre d'éléments dans le tableau
};


void initialise(Liste* liste)
{
    liste->premier = nullptr;
}

bool est_vide(const Liste* liste)
{
    if (liste->premier != nullptr) return false;
    return true;
}

void ajoute(Liste* liste, int valeur)
{
    if(liste->premier == nullptr){
        liste->premier = new Noeud {valeur, nullptr};
        return;
    }
    Noeud* temp = liste->premier;
    while(temp->suivant != nullptr){
        temp = temp->suivant;
    }
    temp->suivant = new Noeud {valeur, nullptr};
}

void affiche(const Liste* liste)
{
    Noeud *temp = liste->premier;
    while(temp !=nullptr){
        cout << temp -> donnee << endl;
        temp = temp->suivant;
    }

}

int recupere(const Liste* liste, int n)
{
    Noeud* temp = liste->premier;
    for(int i=0; i<n; i++){
        if(temp==nullptr) return -1;
        temp = temp->suivant;
    }
    if(temp == nullptr) return 0;
    return temp->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud* temp = liste->premier;
    int compt = 0;
    while(temp != nullptr){
        compt++;
        if(temp->donnee == valeur) return compt;
        temp = temp->suivant;
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud* temp =liste->premier;
    for(int i=1; i<n ; i++){
        temp = temp->suivant;
    }
    temp->donnee = valeur;
}

void ajoute(DynaTableau* tableau, int valeur)
{
    if(tableau->taille == tableau->capacite){
        tableau->capacite = tableau->capacite*2;
        int* temp = new int[tableau->capacite];
        for(int i = 0; i < tableau->taille; i++){
            temp[i] = tableau->donnees[i];
        }
        delete[] tableau->donnees;
        tableau->donnees = temp;
    }
    tableau->donnees[tableau->taille] = valeur;
    tableau->taille = tableau->taille + 1;
}


void initialise(DynaTableau* tableau, int capacite)
{
    tableau->donnees = new int{capacite};
    tableau->capacite = capacite;
    tableau->taille = 0;
}

bool est_vide(const DynaTableau* tableau)
{
    if (tableau->taille != 0) return false;
    return true;
}

void affiche(const DynaTableau* tableau)
{
    for(int i = 0; i<tableau->taille; i++){
       cout << tableau->donnees[i] << endl; 
    }
}

int recupere(const DynaTableau* tableau, int n)
{
    return tableau->donnees[n];
}

int cherche(const DynaTableau* tableau, int valeur)
{
    for(int i=0; i<tableau->taille ; i++ ){
        if (tableau->donnees[i] == valeur) return i+1;
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    tableau->donnees[n-1] = valeur;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(DynaTableau* tableau, int valeur)
{
    if(tableau->taille == tableau->capacite) {
        tableau->capacite = tableau->capacite*2;
        int* temp = new int[tableau->capacite];
        for(int i = 0; i < tableau->taille; i++) {
            temp[i] = tableau->donnees[i];
        }
        delete[] tableau->donnees;
        tableau->donnees = temp;
    }
    tableau->donnees[tableau->taille] = valeur;
    tableau->taille = tableau->taille + 1;
}

//int retire_pile(DynaTableau* liste)
int retire_pile(DynaTableau* tableau)
{
    int val_ret = 0;
    if (tableau->taille != 0)
    {
        int taille = tableau->taille;
        delete[] &tableau->donnees[taille];
        tableau->taille = tableau->taille-1;
        return tableau->donnees[taille];
    }
    return val_ret;
    return 0;
}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    if(liste->premier == nullptr) {
        liste->premier = new Noeud {valeur, nullptr};
        return;
    }
    Noeud* temp = liste->premier;
    while(temp->suivant != nullptr) {
        temp = temp->suivant;
    }
    temp->suivant = new Noeud {valeur, nullptr};
}

//int retire_file(Liste* liste)

int retire_file(Liste* liste)
{
    int val_ret = 0;
    if (liste != nullptr)
    {
        Noeud* temp = liste->premier->suivant;
        val_ret = liste->premier->donnee;
        free(liste), liste->premier = nullptr;
        liste->premier = temp;
    }
    return val_ret;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste 01" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau 01" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }


    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste 02" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau 02" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste a " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans le tableau a " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements apres stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    DynaTableau pileTab; // DynaTableau pile;
    DynaTableau fileTab; // DynaTableau file;

    initialise(&pile);
    initialise(&file);
    initialise(&pileTab, 6);
    initialise(&fileTab, 6);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pileTab, i);
    }

    int compteur = 7;
    while(!est_vide(&file) && compteur > 0)
    {
        retire_file(&file);
        affiche(&file);
        compteur--;
    }
    cout << endl;

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 7;
    while(!est_vide(&pileTab) && compteur > 0)
    {
        retire_pile(&pileTab);
        affiche(&pileTab);
        compteur--;
    }
    cout << endl;

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
