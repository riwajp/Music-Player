#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MusicList.cpp"
#include <string>
#include "ClickHandler.cpp"
#include "SeekBar.cpp"
#include "Text.cpp"
#include "RectangleShape.cpp"
#pragma once

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
		
		if(now_playing!=NULL){
				
		}
			RectangleShape main_rec(950,200,0,0,44,51,51,80);
			
			window->draw(main_rec);
		if( now_playing!=NULL && now_playing->isLoaded ){
		
	
		
		Text now_playing_name(std::string("Montserrat.ttf"),222,222,222,now_playing->text,22,50,25);
		now_playing_name.truncate(70);
		
		
		
		
		float bc_x=460;
		float bc_y=140;
	
			Sprite pause(now_playing->isPlaying?"_pause.png":"_play.png",0.05,0.05,bc_x,bc_y);
			window->draw(pause);
			//drawButton(window,std::string(now_playing->isPlaying?"_pause.png":"_play.png"),bc_x,bc_y,0.05,0.05);
			click_handler->addAction(bc_x,bc_y,20.f,20.f,30.f,30.f,now_playing->isPlaying?"pause":"play");
			
			if(click_handler->triggerAction(event)=="pause"){
				now_playing->pause();
			}else if(click_handler->triggerAction(event)=="play"){
				now_playing->play();
			}
			
			
			Sprite next("_next.png",0.05,0.05,bc_x+80,bc_y);
			window->draw(next);
			//drawButton(window,std::string("_next.png"),bc_x+80,bc_y,0.05,0.05);
			click_handler->addAction(bc_x+80,bc_y,20.f,20.f,30.f,30.f,"play next");
			if(click_handler->triggerAction(event)=="play next"){
				list->playNext();
			}
			
			
			
			Sprite previous("_previous.png",0.05,0.05,bc_x-80,bc_y);
			window->draw(previous);
			//drawButton(window,std::string("_previous.png"),bc_x-80,bc_y,0.05,0.05);
			click_handler->addAction(bc_x-80,bc_y,20.f,20.f,30.f,30.f,"play previous");
				if(click_handler->triggerAction(event)=="play previous"){
				list->playPrevious();
			}
			
			
			Sprite shuffle(list->shuffle?"shuffle.png":"unshuffle.png",list->shuffle?0.04:0.055,list->shuffle?0.04:0.055,bc_x+160,bc_y);
			window->draw(shuffle);	
			//drawButton(window,std::string(list->shuffle?"shuffle.png":"unshuffle.png"),bc_x+160,bc_y,list->shuffle?0.04:0.055,list->shuffle?0.04:0.055);
			click_handler->addAction(bc_x+160,bc_y,20.f,20.f,30.f,30.f,"toggle shuffle");
			
			if(click_handler->triggerAction(event)=="toggle shuffle"){
				
				list->shuffle=!(list->shuffle);
		}
		
			Sprite repeat(list->repeat?"repeat.png":"unrepeat.png",list->repeat?0.06:0.105,list->repeat?0.06:0.105,bc_x-160,bc_y);
			window->draw(repeat);
			//drawButton(window,std::string(list->repeat?"repeat.png":"unrepeat.png"),bc_x-160,bc_y,list->repeat?0.06:0.105,list->repeat?0.06:0.105);
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


