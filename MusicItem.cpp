#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#include "ListItem.cpp"
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>


#pragma once
class MusicItem:public ListItem{
	public:
		bool isLoaded=false;
		bool isPlaying=false;
		inline static sf::Music music;

		
				
	
		
	MusicItem(){
		
	}

	MusicItem(std::string ppath,std::string pname){
		//ListItem(ppath,pname);
		text=pname;
		value=ppath;
		
	}
	
	void render(sf::RenderWindow *window,sf::Color color,int x,int y,float w,float h,int fsize,sf::Color fcolor,sf::Font font,int px,int py){
		sf::RectangleShape rec(sf::Vector2f(w,h));
		rec.setFillColor(color);
		rec.setPosition(x,y);
	
		sf::Text dtext;
		 if (text.length() > 70) {
        text = text.substr(0, 70) + "...";
        
    } 
		dtext.setString(text);
		dtext.setFont(font);
		dtext.setCharacterSize(fsize); 
		dtext.setFillColor(fcolor);

		dtext.setPosition(x+px,y+py);

        
		

        	window->draw(rec);
        	window->draw(dtext);
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
