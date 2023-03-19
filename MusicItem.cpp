#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#include "ListItem.cpp"
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "Text.cpp"
#include "RectangleShape.cpp"
#include "Sprite.cpp"
#include "Clickable.cpp"
#include "Button.cpp"
#include "Memory.cpp"
#include "Options.cpp"

#pragma once
class MusicItem:public ListItem,public Clickable{
	public:
		bool isLoaded=false;
		bool isPlaying=false;
		bool isFavourite=false;
		inline static sf::Music music;
		Memory memory;
		
		static Options options;

		
				
	
		

	
	
		void play(){
		isPlaying=true;

	music.play();
		
	}
	void pause(){
		isPlaying=false;
	music.pause();
	}
	void load(){
		isLoaded=true;
		std::string p;
		music.openFromFile(value);
		//std::cout<<p<<std::endl;
		

	}
	void unload(){
		isLoaded=false;
		isPlaying=false;
	
		music.stop();
	}
	
	
	void onClick(){
		load();
		play();
		//std::cout<<"Clicked me"<<std::endl;
	}
	
	
	MusicItem(){
		Clickable();
		
	}

	MusicItem(std::string ppath,std::string pname){
		//ListItem(ppath,pname);
		text=pname;
		value=ppath;
		Clickable();
		isFavourite=memory.isFavourite(value);
		
	}	
	void render(sf::RenderWindow *window,sf::Event *event,sf::Color color,float x,float y,float w,float h,int size,std::string font,int px,int py){
		
	
		RectangleShape rec(w,h,x,y,55,57,62,150);
	
		Text text(std::string(font),222,222,222,this->text,size,x+px,y+py);
		text.truncate(40);
		
    	window->draw(rec);
    	window->draw(text);
    	
     	/*Button add("add.png", 0.025, 0.025, x+800, y+20);
        add.setParams(event,x + 800, y+20, 20.f, 20.f, 30.f, 30.f);
		add.render(window,[this](){
			std::cout<<"Add";
		});*/
		
		
		
	
		
		
		Button add("add.png", 0.025, 0.025, x+800, y+20);
		add.setParams(event,x+800, y+20, 22.f, 22.f, 30.f, 30.f);
		add.render(window,[this,x,y](){
		std::cout<<"trigger";
		(this->options).setPosition(x+800-250,y+20+30);
		(this->options).opened=!(this->options).opened;
		
	});	
	
	
		options.render(event,window);
	
	
		std::cout<<options.height;
		
		Button fav(isFavourite?"heart.png":"unheart.png", 0.1, 0.1, x+850, y+20);
        fav.setParams(event,x + 850, y+20, 20.f, 20.f, 30.f, 30.f);
		fav.render(window,[this](){
			std::cout<<"Fav";
			this->isFavourite=!this->isFavourite;
			memory.addFavourites(this->value);
		});
			

        setParams( event,x,  y,  0, 790, 0, h);
        listen([this]() { this->onClick(); });
        	
        
	}
	
	

	
};
