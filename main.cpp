#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
using namespace sf;


int main(int argc, char *argv[]){
	srand(time(0));
	
	RenderWindow w(VideoMode(1360,680),"Menu");
	
	//Booleanos para cambiar de ventana
	bool conf=false;
	bool menu=true;
	
	//Carga la musica y la reproduce.
	sf::Music musica;
	musica.openFromFile("musica.wav");
	musica.setLoop(true);
	musica.play();
	
	Texture tmenu, tplay, tconf, tconf_mus, ttick, ticono1, ticono2;
	Sprite smenu, splay, sconf, sconf_mus, stick, sicono1, sicono2;
	
	tmenu.loadFromFile("menu.png");
	tplay.loadFromFile("play.png");
	tconf.loadFromFile("configuracion.png");
	tconf_mus.loadFromFile("conf.musica.png");
	ttick.loadFromFile("tick.png");
	ticono1.loadFromFile("icono1.png");
	ticono2.loadFromFile("icono1.png");
	smenu.setTexture(tmenu);
	splay.setTexture(tplay);
	sconf.setTexture(tconf);
	sconf_mus.setTexture(tconf_mus);
	stick.setTexture(ttick);
	sicono1.setTexture(ticono1);
	sicono2.setTexture(ticono2);
	smenu.setPosition(0,0);
	splay.setPosition(800,480);
	sconf.setPosition(1310,0);
	sconf_mus.setPosition(0,0);
	stick.setPosition(385,420);
	sicono1.setPosition(350,380);
	sicono2.setPosition(1040,380);
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // Detecta si hace click en alguno de los sprite mencionados
			{
				Vector2i posicion_mouse;
				posicion_mouse=Mouse::getPosition(w);
				
				if (sicono2.getGlobalBounds().contains(posicion_mouse.x, posicion_mouse.y)) //Si el click es en el sicono2 el spirte stick cambia de posición y para la música
				{
					stick.setPosition(1075,420);
					musica.pause();
					
				}
				
				if (sicono1.getGlobalBounds().contains(posicion_mouse.x, posicion_mouse.y)) //Si pulsa en el sprite reanuda la música y cambia la posición de la imagen
				{
					stick.setPosition(385,420);
					musica.play();
					
				}
				
				if (sconf.getGlobalBounds().contains(posicion_mouse.x, posicion_mouse.y)) //Cuando pulsa en el sprite un boleano se activo y otro se desactiva
				{
					//Cada booleano hace que se muestre una imagen o otra
					conf=true;
					menu=false;
					
					
				}
				
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) //Si pulsa la tecla "escape" dentro de la configuración de la musica, volverá al menú
			{
				conf=false;
				menu=true;
			}
			
			
		}
		
		
		
		w.clear(Color(255,255,255,255));
		if (conf == true) //Muestra los sprites de la configuración
		{
			w.draw(sconf_mus);
			w.draw(sicono1);
			w.draw(sicono2);
			w.draw(stick);
		}
		if (menu == true) //Muestra los sprites del menú
		{
			w.draw(smenu);
			w.draw(splay);
			w.draw(sconf);
		}
		w.display();
		
	}
	return 0;
}

