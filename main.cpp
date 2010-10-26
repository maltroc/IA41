/*
 *  centre.cpp
 *  Untitled
 *
 *  Created by Adrien BAUD on 23/10/10.
 *  Copyright 2010 UTBM. All rights reserved.
 *
 */

#include "fonctions.h"
#include <iostream>
#include <string.h>

using namespace sf;
using namespace std;

const int LARGEUR = 37;
const int HAUTEUR = 37;

void Effacer(RenderWindow& App,int x, int y){
	Image case_jeu;
	Sprite sprite;
	
	if (!case_jeu.LoadFromFile("case_dfl.jpg")) // Si le chargement du fichier a échoué
	{
		cout << "Erreur durant le chargement de l'image" << endl;
	}
	else // Si le chargement de l'image a réussi
	{
		sprite.SetImage(case_jeu);
		sprite.SetPosition(x*37,y*37);
		App.Draw(sprite);
		
	}
}
	

void Move_Pion_Jaune(RenderWindow& App, char *move, int *Position_Jaune,int *Obstacle_Hor,int *Obstacle_Ver) {

	Image pion_jaune;
	Sprite sprite_jaune;
	int i,obs=0;
	
	if (!pion_jaune.LoadFromFile("pion_jaune.jpg")) // Si le chargement du fichier a échoué
	{
		cout << "Erreur durant le chargement de l'image" << endl;
	}
	else // Si le chargement de l'image a réussi
	{
		// Efface l'ancienne position du pion
		Effacer(App,Position_Jaune[0],Position_Jaune[1]);
		
		// Converti les coordonnées x,y en un seul chiffe de 0 a 256 parcourant toute la table de jeu
		int positionx = (Position_Jaune[0] + Position_Jaune[1]*16);
		int positiony = (Position_Jaune[0]*16 + Position_Jaune[1]);
		// On calcule les position des bordures droite et gauche du pion
		int position_bordure_droite = Position_Jaune[1]*16+15;
		int position_bordure_gauche = Position_Jaune[1]*16;
		
		if(strcmp("Up", move)==0){                    // Mouvement en haut
			
			// Positionne le pion au bon endroit   			
			Position_Jaune[1]=0;
		
		}
		
		if(strcmp("Down", move)==0){                   // Mouvement en bas
			// Positionne le pion au bon endroit
			Position_Jaune[1]=15;
			
		}
		
		if(strcmp("Right", move)==0){                   // Mouvement sur la droite
			for(i=0;i<25;i++){
				if( positionx < Obstacle_Ver[i] && Obstacle_Ver[i]< position_bordure_droite){
					obs=1;
					Position_Jaune[0]= (Obstacle_Ver[i])%16-1;
					i=25;
					
				}			
			}
							
			if(obs==0){                      // si pas d'obstacle on positionne le pion à l'extremité de la table
				Position_Jaune[0]=15;
			}
			
		}
		
		obs=0;
		if(strcmp("Left", move)==0){                   // Mouvement sur la gauche
			for(i=0;i<25;i++){
				if( positionx > Obstacle_Ver[i] && Obstacle_Ver[i]> position_bordure_gauche){
					obs=1;
					Position_Jaune[0]= (Obstacle_Ver[i])%16;
					i=25;
				}			
			}
			
			if(obs==0){                      // si pas d'obstacle on positionne le pion à l'extremité de la table
				Position_Jaune[0]=15;
			}
		}
		
		// Affice la nouvelle position du pion
		sprite_jaune.SetImage(pion_jaune);
		sprite_jaune.SetPosition(Position_Jaune[0]*37,Position_Jaune[1]*37);
		App.Draw(sprite_jaune);
		
	}
	
}

void Initialisation_pions(RenderWindow& App, int *Position_Jaune) {
	
	Image pion_bleu, pion_rouge, pion_vert, pion_jaune;
	Sprite sprite_bleu, sprite_rouge, sprite_vert, sprite_jaune;
	int x1, y1, x2, y2, x3, y3, x4, y4;
	
	do {
		x1 = rand()%(16);
		y1 = rand()%(16);
	}
	while ((x1==7 && y1==7) || (x1==7 && y1==8) || (x1==8 && y1==7) || (x1==8 && y1==8));
	
	do {
		x2 = rand()%(16);
		y2 = rand()%(16);
	}
	while ((x2==7 && y2==7) || (x2==7 && y2==8) || (x2==8 && y2==7) || (x2==8 && y2==8) || (x2==x1 && y2==y1));
	
	do {
		x3 = rand()%(16);
		y3 = rand()%(16);
	}
	while ((x3==7 && y3==7) || (x3==7 && y3==8) || (x3==8 && y3==7) || (x3==8 && y3==8) || (x3==x1 && y3==y1) || (x3==x2 && y3==y2));
	
	do {
		x4 = rand()%(16);
		y4 = rand()%(16);
	}
	while ((x4==7 && y4==7) || (x4==7 && y4==8) || (x4==8 && y4==7) || (x4==8 && y4==8) || (x4==x1 && y4==y1) || (x4==x2 && y4==y2) || (x4==x3 && y4==y3));
	
	if (!pion_bleu.LoadFromFile("pion_bleu.jpg")) // Si le chargement du fichier a échoué
	{
		cout << "Erreur durant le chargement de l'image" << endl;
	}
	else // Si le chargement de l'image a réussi
	{
		sprite_bleu.SetImage(pion_bleu);
		sprite_bleu.SetPosition(x1*37,x2*37);
		App.Draw(sprite_bleu);
	}
	
	
	if (!pion_vert.LoadFromFile("pion_vert.jpg")) // Si le chargement du fichier a échoué
	{
		cout << "Erreur durant le chargement de l'image" << endl;
	}
	else // Si le chargement de l'image a réussi
	{
		sprite_vert.SetImage(pion_vert);
		sprite_vert.SetPosition(x2*37,y2*37);
		App.Draw(sprite_vert);
	}
	
	
	
	if (!pion_rouge.LoadFromFile("pion_rouge.jpg")) // Si le chargement du fichier a échoué
	{
		cout << "Erreur durant le chargement de l'image" << endl;
	}
	else // Si le chargement de l'image a réussi
	{
		sprite_rouge.SetImage(pion_rouge);
		sprite_rouge.SetPosition(x3*37,y3*37);
		App.Draw(sprite_rouge);
	}
	
	
	
	if (!pion_jaune.LoadFromFile("pion_jaune.jpg")) // Si le chargement du fichier a échoué
	{
		cout << "Erreur durant le chargement de l'image" << endl;
	}
	else // Si le chargement de l'image a réussi		
	{
		Position_Jaune[0]=x4;
		Position_Jaune[1]=y4;
		sprite_jaune.SetImage(pion_jaune);
		sprite_jaune.SetPosition(x4*37,y4*37);
		App.Draw(sprite_jaune);
	}
}

void Afficher_obstacles (RenderWindow& app) {
	
	Image image2,image3;
	Sprite obs1, obs2;
	
	// Chargement de l'obstacle 1
	//
	if (!image2.LoadFromFile("obs1.jpg")) // Si le chargement a échoué
	{
		cout<<"Erreur durant le chargement de l'image obs1"<<endl;
	}
	else // Si le chargement de l'image a réussi
	{
		obs1.SetImage(image2);
	}
	
	// Chargement de l'obstacle 2
	//
	if (!image3.LoadFromFile("obs2.jpg")) // Si le chargement a échoué
	{
		cout<<"Erreur durant le chargement de l'image obs2"<<endl;
	}
	else // Si le chargement de l'image a réussi
	{
		obs2.SetImage(image3);
	}
	
	
	// Affichage des obstacles
	//////
	
	// obstacle 1 horizontal
	
	obs1.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs1.SetPosition(15*37, 1*37);
	app.Draw(obs1);
	
	obs1.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs1.SetPosition(15*37, 11*37);
	app.Draw(obs1);
	
	obs1.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs1.SetPosition(0*37, 4*37);
	app.Draw(obs1);
	
	obs1.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs1.SetPosition(0*37, 10*37);
	app.Draw(obs1);
	
	// obstacle 1 verticale
	
	obs1.Rotate(270); // permet la verticalité de l'image 1 en la rotationnant
	
	obs1.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs1.SetPosition(5*37, 0*37);
	app.Draw(obs1);
	
	obs1.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs1.SetPosition(11*37, 0*37);
	app.Draw(obs1);
	
	obs1.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs1.SetPosition(6*37, 15*37);
	app.Draw(obs1);
	
	obs1.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs1.SetPosition(13*37, 15*37);
	app.Draw(obs1);
	
	
	// Obstacle 2
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(2*37, 4*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(14*37, 4*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(1*37, 13*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(14*37, 13*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(7*37, 12*37);
	app.Draw(obs2);
	
	// obstacle 2 rotationné de -90°
	
	obs2.Rotate(-90);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(6*37, 2*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(14*37, 1*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(10*37, 11*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(4*37, 14*37);
	app.Draw(obs2);
	
	
	// obstacle 2 rotationné de 180°
	
	obs2.Rotate(180);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(9*37, 4*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(1*37, 7*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(6*37,11*37);
	app.Draw(obs2);
	
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(11*37, 15*37);
	app.Draw(obs2);
	
	
	
	// obstacle 2 rotationné de 90°
	
	obs2.Rotate(90);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(8*37, 6*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(13*37, 7*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(5*37, 10*37);
	app.Draw(obs2);
	
	obs2.SetSubRect(IntRect(0, 0, LARGEUR , HAUTEUR));
	obs2.SetPosition(14*37, 10*37);
	app.Draw(obs2);
	
	
	
	
}
void Afficher_case_centre (RenderWindow& App) {
	
	Image case_centre;
	Sprite sprite;
	int nb;
	string tbl[16];
	srand(time(NULL)); // initialisation de rand
	
	tbl[0] = "case_centre_vert1.jpg";
	tbl[1] = "case_centre_rouge1.jpg";
	tbl[2] = "case_centre_bleu1.jpg";
	tbl[3] = "case_centre_jaune1.jpg";
	tbl[4] = "case_centre_vert2.jpg";
	tbl[5] = "case_centre_rouge2.jpg";
	tbl[6] = "case_centre_bleu2.jpg";
	tbl[7] = "case_centre_jaune2.jpg";
	tbl[8] = "case_centre_vert3.jpg";
	tbl[9] = "case_centre_rouge3.jpg";
	tbl[10] = "case_centre_bleu3.jpg";
	tbl[11] = "case_centre_jaune3.jpg";
	tbl[12] = "case_centre_vert4.jpg";
	tbl[13] = "case_centre_rouge4.jpg";
	tbl[14] = "case_centre_bleu4.jpg";
	tbl[15] = "case_centre_jaune4.jpg";
	
	nb = rand()%(16);
	
	if (!case_centre.LoadFromFile(tbl[nb])) // Si le chargement du fichier a échoué
	{
		cout << "Erreur durant le chargement de l'image" << endl;
	}
	else // Si le chargement de l'image a réussi
	{
		sprite.SetImage(case_centre);
		sprite.SetPosition(7*37,7*37);
		App.Draw(sprite);
	}
	

}

void Remplissage_plateau (RenderWindow& App) {
	
	Image case_jeu;
	Sprite sprite;
	
	if (!case_jeu.LoadFromFile("case_dfl.jpg")) // Si le chargement du fichier a échoué
	{
		cout << "Erreur durant le chargement de l'image" << endl;
	}
	else // Si le chargement de l'image a réussi
	{
		int i=0, j=0;
		
		sprite.SetImage(case_jeu);
		
		for (i=0; i<16; i++) {
			for (j=0; j<16; j++) {
				sprite.SetPosition(i*37,j*37);
				App.Draw(sprite);
			}
		}
	}
		
}

void Afficher_menu(RenderWindow& App) {
	sf::String titre;
	
	Font font;
	
	// Chargement à partir d'un fichier sur le disque
	if(!font.LoadFromFile("Arial.ttf"))
	{
		// Traitement de l'erreur
	}
	else {
		titre.SetFont(font);
		titre.SetColor(Color(255,255,255,120));
		titre.SetText("Rasende Roboter");
		titre.SetPosition(612,20);
		titre.SetSize(18);
		App.Draw(titre);
	}

}

void Afficher_cibles (RenderWindow& app) {
	
	// tableau ou toute les position des cibles sont reportorié :
	int INDEX_CIBLE[] = {29,37,57,66,78,87,97,108,148,157,166,185,199,209,222,227,235};
	string NOM_CIBLE[] = {"cible_bleu1.jpg", "cible_bleu2.jpg","cible_bleu3.jpg","cible_bleu4.jpg","cible_jaune1.jpg","cible_jaune2.jpg","cible_jaune3.jpg","cible_jaune4.jpg","cible_rouge1.jpg","cible_rouge2.jpg","cible_rouge3.jpg","cible_rouge4.jpg","cible_vert1.jpg","cible_vert2.jpg","cible_vert3.jpg","cible_vert4.jpg"}; 
	
	int a,x,mod; // variable utilisée pour positionner la cible
	int longeur =17; // longeur du tableau des index 
	int i,w; // incrementeur
	Image image;
	Sprite cible;
	
	for(w=0;w<16;w++){
		
		if (!image.LoadFromFile(NOM_CIBLE[w])) // Si le chargement a échoué
			{
				cout<<"Erreur durant le chargement de l'image d'une cible"<<endl;
			}
		else // Si le chargement de l'image a réussi
		{
			cible.SetImage(image);
		}
		
		
		srand(time(NULL)); // initialisation de rand
		a = rand()%(longeur);
		mod = INDEX_CIBLE[a]/16; // axe Y
		x = INDEX_CIBLE[a]%16; // axe X
		
		// Supprime l'emplacement de la cible deja utilisé dans le tableau en décalent les valeurs et ensuite on reduit la longueur du tableau grace a la variable long
		for(i=a; i<= longeur; i++)
			INDEX_CIBLE[i]=INDEX_CIBLE[i+1];
		
		longeur=longeur-1;
		
		
		cible.SetSubRect(IntRect(0, 0,24,25));
		cible.SetPosition((x*37)+7, (mod*37)+5); // les +5 et +7 permettent de centrer la cible dans la case
		app.Draw(cible);
	}
	
	
}

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main(int argc, const char** argv)
{
    // Create main window
    RenderWindow App(VideoMode(792, 592), "SFML Graphics");
	int Position_Jaune[2];             // Coordonnées du pion jaune
	
	// Permet de repertorier tous les obstacles verticaux
	int Obstacle_Ver[]={4,10,30,38,57,67,79,87,97,108,119,121,135,137,148,157,166,186,200,210,223,228,235,245,252};
	
	// Permet de repertorier tous les obstacles horizontaux
	int Obstacle_Hor[]={5,11,22,29,36,63,74,83,106,118,119,121,124,135,137,147,156,190,199,210,218,228,237,242,252};
		
	// Clear screen
	App.Clear();
	
	Remplissage_plateau(App);
	Afficher_case_centre(App);
	Afficher_obstacles(App);
	Afficher_cibles(App);
	Initialisation_pions(App, Position_Jaune);
	Afficher_menu(App);

    // Start game loop
    while (App.IsOpened())
    {
        // Process events
        Event event;
        while (App.GetEvent(event))
        {
			switch (event.Type) // Type de l'évènement en attente :
			{
				case Event::Closed : // Croix en haut à droite
					App.Close();
					break;
					
				case Event::KeyPressed : // Appui sur une touche du clavier
				{
					switch (event.Key.Code)
					{
						case Key::Escape : // Appui sur la touche echap
							App.Close();
							break;
						
						case Key::Up :
							Move_Pion_Jaune(App, "Up", Position_Jaune,Obstacle_Hor,Obstacle_Ver);
							break;
							
						case Key::Down :
							Move_Pion_Jaune(App, "Down", Position_Jaune,Obstacle_Hor,Obstacle_Ver);
							break;
							
						case Key::Right :
							Move_Pion_Jaune(App, "Right", Position_Jaune,Obstacle_Hor,Obstacle_Ver);
							break;
							
						case Key::Left :
							Move_Pion_Jaune(App, "Left", Position_Jaune,Obstacle_Hor,Obstacle_Ver);
							break;
							
							
						default :
							break;
					}
				}
					break;
					
				default :
					break;
			}
        }
		
		App.Display();
		

    }

    return EXIT_SUCCESS;
}
