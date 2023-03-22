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
		bool* mouseCaptured;
		Options options;
		inline static sf::Music music;
	
		Memory memory;
		
	

		
				
	
		

	
	
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
		Options options(250,300,0,0,120,120,120);
		this->options=options;		
	
		
	}

	MusicItem(std::string ppath,std::string pname){
		//ListItem(ppath,pname);
		text=pname;
		value=ppath;
		Clickable();
		isFavourite=memory.isFavourite(value);
		Options options(250,300,0,0,70,70,70,220);
		this->options=options;	
		
		
		
	}	
	void render(sf::RenderWindow *window,sf::Event *event,Options * options,sf::Color color,float x,float y,float w,float h,int size,std::string font,int px,int py){
		
	
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
		
		
		
	
		
		bool T=true;
		Button add(&T,"add.png", 0.025, 0.025, x+800, y+20);
		add.setParams(event,x+800, y+20, 22.f, 22.f, 30.f, 30.f);
		float max_height=300;
		(this->options).setPosition(x+800-250,y+50+(this->options.height)>=840?y+50-(this->options.height):y+50);
		(this->options).x=x+800-250;
		(this->options).y=y+50+(this->options.height)>=840?y+50-(this->options.height):y+50;
		(this->options).song_path=value;
		
		
		add.render(window,[this,x,y,options](){
	
		
			(this->options).enabled=true;
		
		
		(this->options).opened=!(this->options).opened;
		*(this->mouseCaptured)=!(*(this->mouseCaptured));
		*options=this->options;
		
	},[this,options](){
		
		if((this->options).opened){
		(this->options).opened=false;
		*(this->mouseCaptured)=false;
		*options=this->options;
		std::cout<<"closed";
	}
	});	
	
		//options.render(event,window);
	
	
		
		
		Button fav(&mouseEnabled,isFavourite?"heart.png":"unheart.png", 0.1, 0.1, x+850, y+20);
        fav.setParams(event,x + 850, y+20, 20.f, 20.f, 30.f, 30.f);
		fav.render(window,[this](){
			std::cout<<"Fav";
			if(this->isFavourite){
				memory.removeFavourites(this->value);
				
			}else{
			
			memory.addFavourites(this->value);
		}
			this->isFavourite=!this->isFavourite;
			
		});
			

        setParams( event,x,  y,  0, 790, 0, h);
        listen([this]() { this->onClick(); });
        	
        
	}
	
	

	
};
