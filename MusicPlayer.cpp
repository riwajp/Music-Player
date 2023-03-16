#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MusicList.cpp"
#include <string>
#include "ClickHandler.cpp"
#include "SeekBar.cpp"


class MusicPlayer{
	public:
		SeekBar seekbar;
		MusicItem * now_playing=NULL;
		MusicList * list;
		MusicPlayer(MusicList * list){
			this->list=list;
			
		}
	
	
		
	
		//buttons==================
		void drawButton(sf::RenderWindow * window,std::string image,float x, float y,float scale_x,float scale_y){
			sf::Texture texture;
			texture.loadFromFile(image);
				texture.setSmooth(true);
			sf::Sprite sprite(texture);
			sprite.setScale(scale_x,scale_y);
			sprite.setPosition(x,y);
		
			
				
		window->draw(sprite);
			
					
		}
	
				
		void print(sf::RenderWindow *window,sf::Event *event,ClickHandler * click_handler){
				sf::RectangleShape main_rec(sf::Vector2f(950.f,200.f));
		main_rec.setFillColor(sf::Color(44,51,51,80));
		main_rec.setPosition(0,0);
			window->draw(main_rec);
		if( now_playing!=NULL && now_playing->isLoaded ){
		//std::cout<<now_playing->text;
	
		
		sf::Font font;
    	font.loadFromFile("Montserrat.ttf");
    	sf::Text now_playing_name;
    	
    	now_playing_name.setString(now_playing->text);
		now_playing_name.setFont(font);
		now_playing_name.setCharacterSize(22); 
		now_playing_name.setFillColor(sf::Color(255,255,255));
		now_playing_name.setPosition(50,25);
		
		
		
		float bc_x=460;
		float bc_y=140;
	
			
			drawButton(window,std::string(now_playing->isPlaying?"./Sprites/_pause.png":"./Sprites/_play.png"),bc_x,bc_y,0.05,0.05);
			click_handler->addAction(bc_x,bc_y,20.f,20.f,30.f,30.f,now_playing->isPlaying?"pause":"play");
			
			if(click_handler->triggerAction(event)=="pause"){
				now_playing->pause();
			}else if(click_handler->triggerAction(event)=="play"){
				now_playing->play();
			}
			
			
			
			drawButton(window,std::string("./Sprites/_next.png"),bc_x+80,bc_y,0.05,0.05);
			click_handler->addAction(bc_x+80,bc_y,20.f,20.f,30.f,30.f,"play next");
			if(click_handler->triggerAction(event)=="play next"){
				list->playNext();
			}
			
			
			
			
			drawButton(window,std::string("./Sprites/_previous.png"),bc_x-80,bc_y,0.05,0.05);
			click_handler->addAction(bc_x-80,bc_y,20.f,20.f,30.f,30.f,"play previous");
				if(click_handler->triggerAction(event)=="play previous"){
				list->playPrevious();
			}
			
			
				
			drawButton(window,std::string(list->shuffle?"./Sprites/shuffle.png":"./Sprites/unshuffle.png"),bc_x+160,bc_y,list->shuffle?0.04:0.055,list->shuffle?0.04:0.055);
			click_handler->addAction(bc_x+160,bc_y,20.f,20.f,30.f,30.f,"toggle shuffle");
			
			if(click_handler->triggerAction(event)=="toggle shuffle"){
				
				list->shuffle=!(list->shuffle);
		}
		
				
			drawButton(window,std::string(list->repeat?"./Sprites/repeat.png":"./Sprites/unrepeat.png"),bc_x-160,bc_y,list->repeat?0.06:0.105,list->repeat?0.06:0.105);
			click_handler->addAction(bc_x-160,bc_y,20.f,20.f,30.f,30.f,"toggle repeat");
			
			if(click_handler->triggerAction(event)=="toggle repeat"){
				
				list->repeat=!(list->repeat);
		}
			
			window->draw(now_playing_name);
			seekbar.render(window,now_playing,click_handler,event);
			
	}

	
			int length=(now_playing->music).getDuration().asSeconds();
			int clength=(now_playing->music).getPlayingOffset().asSeconds();
			if(length==clength && length!=0.f){
				list->autoPlay();
			}
	

		
		
	}
		
};


