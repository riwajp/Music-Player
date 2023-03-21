#include "Clickable.cpp"
#include "Sprite.cpp"
#include <SFML/Window.hpp>

#pragma once
class Button:public Clickable{
	
	public:
		Sprite sprite;
		Button(bool* mouseEnabled, std::string image_path,float scale_x,float scale_y,float x, float y){
			agent="button";
			sprite=Sprite(image_path, scale_x, scale_y, x,  y);
			Clickable::mouseEnabled=*mouseEnabled;
			
		}
	 	template<typename T>
		void render(sf::RenderWindow *window,T && lambda) {
			window->draw(sprite);
			listen(lambda);
		
		}
		template<typename T,typename M>
		void render(sf::RenderWindow *window,T && lambda,M && _lambda) {
			window->draw(sprite);
			listen(lambda,_lambda);
		
		}
		
		
	
};
