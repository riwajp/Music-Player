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

#pragma once
class MusicItem:public ListItem{
	public:
		bool isLoaded=false;
		bool isPlaying=false;
		bool isFavourite=false;
		inline static sf::Music music;

		
				
	
		
	MusicItem(){
		
	}

	MusicItem(std::string ppath,std::string pname){
		//ListItem(ppath,pname);
		text=pname;
		value=ppath;
		
	}
	
	void render(sf::RenderWindow *window,sf::Color color,float x,float y,float w,float h,int size,std::string font,int px,int py){
	
		RectangleShape rec(w,h,x,y,55,57,62,150);
	
		Text text(std::string(font),222,222,222,this->text,size,x+px,y+py);
		text.truncate(40);
		
		Sprite add("./Sprites/add.png",0.025,0.025,x+800,y+20);
		Sprite fav("./Sprites/heart.png",0.1,0.1,x+850,y+20);
        
    
		      
		

        	window->draw(rec);
        	window->draw(text);
        	window->draw(add);
        	window->draw(fav);
	}
	
	
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
		mciSendString(TEXT("close mp3"), NULL, 0, NULL);
		music.stop();
	}
	
};
