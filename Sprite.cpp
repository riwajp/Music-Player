#include <SFML/Graphics.hpp>
#include <iostream>

#include "textures.cpp"
#pragma once

extern sf::Texture* getTexture(std::string path);

class Sprite:public sf::Sprite{
	public:
	
	sf::Texture* getTexture(std::string path){
		extern sf::Texture* getTexture(std::string path);
		return getTexture(path);
	};

	sf::Texture texture;
	Sprite(){
	}
	Sprite(std::string image_path,float scale_x,float scale_y,float x, float y){
		
		

		setTexture(*getTexture(image_path));
		setScale(scale_x,scale_y);
		setPosition(x,y);
	
	}
	
	
};
