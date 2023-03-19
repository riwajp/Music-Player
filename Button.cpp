#include "Clickable.cpp"
#include "Sprite.cpp"
#include <SFML/Window.hpp>

#pragma once
class Button:public Clickable{
	
	public:
		Sprite sprite;
		Button(std::string image_path,float scale_x,float scale_y,float x, float y){
			sprite=Sprite(image_path, scale_x, scale_y, x,  y);
			
		}
	 	template<typename T>
		void render(sf::RenderWindow *window,T && lambda) {
			window->draw(sprite);
			listen(lambda);
		
		}
		
		
	
};
