
//BALJ17058609 - baldo jérôme 

//---- POINT DE SITUATION -----
//L'affichage a été  mis dans une classe à part. 
// Cette classe appelé Affichage contient toutes les méthodes 
// permettant d'affficher le conteneur cible.
//-----------------------------

#include "Lemming.h"
#include "Affichage.h"

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


//--- METHODES SUR PROBABILITE ----
//methode pour savoir si lemming  est supprimé 
//en entrée on donne le probabilité et on lance le rand()
//si chiffre aleatoire compris entre 0 et probabilité entrée alors suppression lemming
bool ProbaMourir(int proba);

//Methode servant pour ProbaMourir et pour le choix des lemming à l'étape 5
//probabilite sur 100 
int Proba(int max); 

//METHODES 1er ETAPE 
//creer la list avec 20 lemmings 
//en entree , il faut la list dans lequel incremente le nombre de lemming donné par int nb
void DefinirAttroupement(list<Lemming>& lemmingAttroupement, int nb);

//METHODES 2e ETAPE
//transfert de la list à la queue 
void AvancerPassage(list<Lemming>& lemmingAttroupement, queue<Lemming>&lemmingPassageSombre);

//METHODES 3e ETAPE 
//utilisation de la methode ProbaMourir avec proba de 5% pour  eliminer  lemmings
//transfert de queue à queue 
void PasserPente(queue<Lemming>& lemmingPassageSombre, queue<Lemming>& lemmingPente);

//METHODES 4e ETAPE
//methode creer echelle prenant les 10 premiers lemmings 
//transfert de queue à stack
void CreerEchelle(queue<Lemming>& lemmingPente, stack<Lemming>& lemmingEchelle);
//methode transfert de queue à list 
void PassageEchelle(queue<Lemming>& lemmingPente, list<Lemming>& lemmingPassageEchelle);
//methode transfert de queue à list 
//deuxieme appel pour recuperer les 10 lemmings situés dans la stack
void PassageEchelle(stack<Lemming>& lemmingEchelle, list<Lemming>& lemmingPassageEchelle);

//METHODES 5e ETAPE
//utilisation de la methode ProbaMourir avec proba de 50% pour  eliminer  lemmings
//utilisation de la VerifEntier pour verifier si la valeur entrée est deja ou non 
//dans la liste des lemmings potiellement éliminés
void PassageSprint(list<Lemming>& lemmingPassageEchelle, queue<Lemming>& lemmingSprint);
bool VerifEntier(list<int>& tab, int nbr);

//METHODES 6e ETAPE 
//methode pour le transfert entre queue et list pour les lemmings disparus et queue à queue pour succes 
//utilisation de la methode ProbaMourir avec une  probalite de 20%
void PassageGouffre(queue<Lemming>& lemmingSprint, list<Lemming>& lemmingDisparu, queue<Lemming>& lemmingSurvi);

int main()
{
    srand(time(NULL));
    //objet pour l'affichage des conteneurs 
    Affichage affiche;
    
    //Etape #1 : l'attroupement 
    list<Lemming> lemmingAttroupement;
    cout << "ETAPE #1 : l'attroupement" << endl;
    DefinirAttroupement(lemmingAttroupement, 20);
    //affichage du conteneur 
    affiche.Affic(lemmingAttroupement);
    cout << endl;
    
    //Etape #2 : le passage sombre 
    queue<Lemming> lemmingPassageSombre;
    cout << "ETAPE #2 : le passage sombre" << endl;
    AvancerPassage(lemmingAttroupement, lemmingPassageSombre); //pareil 
    affiche.Affic(lemmingPassageSombre);
    cout << endl;

    //Etape #3 : la pente
    queue<Lemming>lemmingPente;
    cout << "ETAPE #3 : la pente" << endl;
    PasserPente(lemmingPassageSombre, lemmingPente); //pareil
    affiche.Affic(lemmingPente);
    cout << endl;

    //Etape #4 : l'échelle
    stack<Lemming>lemmingEchelle;
    list<Lemming>lemmingPassageEchelle;
    cout << "ETAPE #4 : l'echelle" << endl;
    CreerEchelle(lemmingPente, lemmingEchelle);
    PassageEchelle(lemmingPente, lemmingPassageEchelle); //pareil 
    PassageEchelle(lemmingEchelle, lemmingPassageEchelle); //pareil 
    affiche.Affic(lemmingPassageEchelle);
    cout << endl;

    //Etape #5 : le sprint 
    queue<Lemming>lemmingSprint;
    cout << "ETAPE #5 : le sprint" << endl;
    PassageSprint(lemmingPassageEchelle, lemmingSprint);
    affiche.Affic(lemmingSprint);
    cout << endl;

    //Etape #6 : Liberté!
    list<Lemming> lemmingDisparu;
    queue<Lemming> lemmingSurvi;
    cout << "ETAPE #6 : Liberte !!!" << endl;
    PassageGouffre(lemmingSprint, lemmingDisparu, lemmingSurvi);
    affiche.Affic(lemmingSurvi);
    cout << endl;
    cout << endl;
    affiche.Affic(lemmingDisparu);
}
//probabilite en entree
//generation nombre aleatoire avec methode Proba avec max 100 
// si chiffre généré est compris entre 0 et probabilite alors retourne false. 
bool ProbaMourir(int proba)
{
    bool probaVie = true;
        
    int chiffreProba = Proba(100);
    if (chiffreProba >= 1 && chiffreProba <= proba)
    {
        probaVie = false;
    }
    return probaVie;
}
//generation d'un nombre aleatoire compris entre 1 et 100
int Proba(int max)
{
    int chiffreAlea = 0;
    chiffreAlea = 1 + rand() % (max + 1 - 1);
    return chiffreAlea;
}

//----- ETAPE 1 -----
void DefinirAttroupement(list<Lemming>& lemmingAttroupement, int nb)
{
    for (int i = 0; i < nb; i++)
    {
        lemmingAttroupement.push_back(Lemming());
    }
}

//----- ETAPE 2 -----
void AvancerPassage(list<Lemming>& lemmingAttroupement, queue<Lemming>&lemmingPassageSombre)
{
    list<Lemming>::iterator itAttroup = lemmingAttroupement.begin();
    
    for (itAttroup; itAttroup != lemmingAttroupement.end(); ++itAttroup)
    {
        lemmingPassageSombre.push(*itAttroup);
    }
}

//----- ETAPE 3 -----

void PasserPente(queue<Lemming>& lemmingPassageSombre, queue<Lemming>& lemmingPente)
{
    while (!lemmingPassageSombre.empty())
    {
        //utilisation de la methode probMourir pour determiner si le lemming ciblé est supprimé
        //methode appliquée pour chaque lemming 
        bool probSupp = ProbaMourir(5);
        if (probSupp)
        {
            lemmingPente.push(lemmingPassageSombre.front());
        }
        else
        {
            cout << "Le lemming numero " << lemmingPassageSombre.front() << " glisse et meurt !" << endl;
        }
        lemmingPassageSombre.pop();
    }
}

//----- ETAPE 4 -----
void CreerEchelle(queue<Lemming>& lemmingPente, stack<Lemming>& lemmingEchelle)
{
    int i = 0;
    while (i < 10)
    {
        lemmingEchelle.push(lemmingPente.front());           
        lemmingPente.pop();
        i++;
    }
}

void PassageEchelle(queue<Lemming>& lemmingPente, list<Lemming>& lemmingPassageEchelle)
{
    while (!lemmingPente.empty())
    {
        lemmingPassageEchelle.push_back(lemmingPente.front());
        lemmingPente.pop();
    }
}

void PassageEchelle(stack<Lemming>& lemmingEchelle, list<Lemming>& lemmingPassageEchelle)
{
    while (!lemmingEchelle.empty())
    {
        lemmingPassageEchelle.push_back(lemmingEchelle.top());
        lemmingEchelle.pop();
    }
}

//----- ETAPE 5 -----
void PassageSprint(list<Lemming>& lemmingPassageEchelle, queue<Lemming>& lemmingSprint)
{
    int max = lemmingPassageEchelle.size();
    int i = 0;
    //liste stockant les 5 lemmings qui seront soumis à la probabilite de mourir 
    list<int> listSup;
    int choixLemming = 0;
    while (listSup.size() < 5)
    {
        //si le nombre généré est deja dans la liste alors on relance la géénration aléatoire
        do
        {
            //generation de l'indice du lemming'
            choixLemming = Proba(max);
        } 
        while (!VerifEntier(listSup, choixLemming));//verification si nombre est déja dans la list
        
        listSup.push_back(choixLemming);
        //utilisation de la methode probMourir pour determiner si le lemming ciblé est supprimé
        //methode appliquée pour chaque lemming
        bool verif = ProbaMourir(50);
        int positionLemming = 0;
        if (!verif)
        {
            cout << "lemming numero " << choixLemming << " est victime du piege!" << endl;
            list<Lemming>::iterator it = lemmingPassageEchelle.begin();
            list<Lemming>::iterator positionSupp = lemmingPassageEchelle.begin();
            for (it; it != lemmingPassageEchelle.end(); it++)
            {
                if (it->getId() == choixLemming)
                {
                    positionSupp = it; // on positionne sur le lemming à supprimer 
                }
            }
            it = lemmingPassageEchelle.erase(positionSupp);
        }
    }
    for (auto& iterator : lemmingPassageEchelle)
    {
        lemmingSprint.push(iterator);
    }
}
//methode qui verifie si dans la list en entree il y a nbr
//retourne le booleen si trouve alors false
bool VerifEntier(list<int>& tab, int nbr)
{
    bool verif = true;
    for (auto it : tab)
    {
        if (it == nbr)
        {
            verif = false;
        }
    }
    return verif;
}

//----- ETAPE 6 -----
// 
//parcourir le queue et a chaque fois evaluer la proba de 20% 
// si cela tombe mettre dans une liste de lemmings disparus(liste #3)
// sinon reussite alors transferer de la file(file #3) vers une file de lemmings survivants(file #4)
void PassageGouffre(queue<Lemming>& lemmingSprint, list<Lemming>& lemmingDisparu, queue<Lemming>& lemmingSurvi)
{  
    while (!lemmingSprint.empty())
    {
        //si pas touché par  probabilité (pas compris entre 1 et 20) retourne true 
        if (ProbaMourir(20))
        {
            lemmingSurvi.push(lemmingSprint.front());
        }
        //sinon mis dans lemmingDisparu car touche par probabilite (false)
        else
        {
            lemmingDisparu.push_back(lemmingSprint.front());
            cout << "lemming numero " << lemmingSprint.front() << " est tombe dans le gouffre !" << endl;
        }
        lemmingSprint.pop();
    }  
}
