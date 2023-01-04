#pragma once

//BALJ17058609 - baldo j�r�me 

//---- POINT DE SITUATION -----
//L'affichage a �t�  mis dans une classe � part. 
// Cette classe appel� Affichage contient toutes les m�thodes 
// permettant d'affficher le conteneur cible.
//-----------------------------

#include "Lemming.h"

#include <iostream>
#include <list>
#include <queue>

using namespace std;
class Affichage
{
public:
	Affichage();
	void Affic(queue<Lemming>& lemming);
	void Affic(list<Lemming>& lemming);
};

