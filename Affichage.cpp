

//BALJ17058609 - baldo j�r�me 

//---- POINT DE SITUATION -----
//L'affichage a �t�  mis dans une classe � part. 
// Cette classe appel� Affichage contient toutes les m�thodes 
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
