

//BALJ17058609 - baldo jérôme 

//---- POINT DE SITUATION -----
//L'affichage a été  mis dans une classe à part. 
// Cette classe appelé Affichage contient toutes les méthodes 
// permettant d'affficher le conteneur cible.
//-----------------------------

#include "Affichage.h"

Affichage::Affichage()
{
}

void Affichage::Affic(queue<Lemming>& lemming)
{
    cout << "PILE " << "(" << lemming.size() << ") : ";
    cout << lemming.front() << " <-- " << lemming.back();
    cout << endl;
}

void Affichage::Affic(list<Lemming>& lemming)
{
    cout << "LISTE " << "(" << lemming.size() << ") : ";

    for (auto it : lemming)
    {
        cout << it;
        cout << "<-";
    }
    cout << endl;
}
