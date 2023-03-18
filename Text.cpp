#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once 

class Text:public sf::Text{
	public:
		sf::Font font;
	
    
		Text(std::string font_path,int r,int g, int b,std::string text,int size,float x, float y){
			
	    	font.loadFromFile(font_path);
	    	sf::Color color=sf::Color(r,g,b);
	    	setString(text);
			setFont(font);
			setCharacterSize(20.f); 
			setFillColor(color);
			setPosition(x,y);
		    	
		}
		
		
		
		void truncate(int num_chars){
		
		if (getString().getSize() > num_chars) {
        setString(getString().substring(0, 70) + "...");
    	}
    
				 
  	}
  
	
			
			

	
	
	
};
