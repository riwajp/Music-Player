#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once 

class RectangleShape:public sf::RectangleShape{
	public:
		float width;
		float height;
		RectangleShape(){
		}
	
		
		RectangleShape(float width,float height, float x, float y,int r,int g ,int b, int a=255){
		this->width=width;
		this->height=height;
		sf::Color color=sf::Color(r,g,b,a);
		setSize(sf::Vector2f(width,height));
		setFillColor(color);
		setPosition(x,y);
		}
		
	
};
