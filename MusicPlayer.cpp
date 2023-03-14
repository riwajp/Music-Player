#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MusicItem.cpp"
#include <string>
#include "ClickHandler.cpp"



class MusicPlayer{
	public:
		MusicItem * now_playing=NULL;
	
		
		
		//buttons==================
		void drawButton(sf::RenderWindow * window,std::string image,float x, float y,float scale_x,float scale_y){
			sf::Texture texture;
			texture.loadFromFile(image);
			sf::Sprite sprite(texture);
			sprite.setScale(scale_x,scale_y);
			sprite.setPosition(x,y);
		
			
			
		window->draw(sprite);
			
					
		}
				
		void print(sf::RenderWindow *window,sf::Event *event,ClickHandler * click_handler){
		if( now_playing!=NULL && now_playing->isLoaded ){
		//std::cout<<now_playing->text;
		sf::RectangleShape main_rec(sf::Vector2f(950.f,200.f));
		main_rec.setFillColor(sf::Color(44,51,51));
		main_rec.setPosition(0,0);
		
		sf::Font font;
    	font.loadFromFile("Montserrat.ttf");
    	sf::Text now_playing_name;
    	
    	now_playing_name.setString(now_playing->text);
		now_playing_name.setFont(font);
		now_playing_name.setCharacterSize(22); 
		now_playing_name.setFillColor(sf::Color(255,255,255));
		now_playing_name.setPosition(50,25);
		
		
		window->draw(main_rec);
		float bc_x=460;
		float bc_y=120;
	
			//std::cout<<now_playing->text;
			
			//std::cout<<now_playing->isPlaying?1:0<<std::endl;
			drawButton(window,std::string(now_playing->isPlaying?"./Sprites/_pause.png":"./Sprites/_play.png"),bc_x,bc_y,0.07,0.07);
			click_handler->addAction(bc_x,bc_y,50.f,70.f,now_playing->isPlaying?"pause":"play");
			if(click_handler->triggerAction(event)=="pause"){
				now_playing->pause();
			}else if(click_handler->triggerAction(event)=="play"){
				now_playing->play();
			}
			drawButton(window,std::string("./Sprites/_next.png"),bc_x+100,bc_y,0.07,0.07);
			drawButton(window,std::string("./Sprites/_previous.png"),bc_x-100,bc_y,0.07,0.07);
				window->draw(now_playing_name);
			
	}

	
		
	

		
		
	}
		
};


