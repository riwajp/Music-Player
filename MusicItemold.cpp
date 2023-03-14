#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#include "ListItem.cpp"
#include <SFML/Graphics.hpp>


#pragma once
/*
class MusicItem:public ListItem{
	public:
		bool isLoaded=false;
		bool isPlaying=false;
		
				
	
		
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
				std::cout<<"Playing\n\n";

		mciSendString(TEXT("play mp3"), NULL, 0, NULL);
		
	}
	void pause(){
		isPlaying=false;
		mciSendString(TEXT("pause mp3"), NULL, 0, NULL);
	}
	void load(){
		isLoaded=true;
		std::string p;
		p="open \""+value+"\" alias mp3";
		std::cout<<p<<std::endl;
		mciSendString(p.c_str(), NULL, 0, NULL);
		

	}
	void unload(){
		isLoaded=false;
		mciSendString(TEXT("close mp3"), NULL, 0, NULL);
	}
	
};
*/
