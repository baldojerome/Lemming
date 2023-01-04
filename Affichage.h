#pragma once

//BALJ17058609 - baldo jérôme 

//---- POINT DE SITUATION -----
//L'affichage a été  mis dans une classe à part. 
// Cette classe appelé Affichage contient toutes les méthodes 
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

