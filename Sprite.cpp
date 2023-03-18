#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

class Sprite:public sf::Sprite{
	public:
	sf::Texture texture;
	Sprite(std::string image_path,float scale_x,float scale_y,float x, float y){
		
		
		texture.loadFromFile(image_path);
		texture.setSmooth(true);
		setTexture(texture);
		setScale(scale_x,scale_y);
		setPosition(x,y);
	}
	
	
};
