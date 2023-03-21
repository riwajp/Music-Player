#include "Clickable.cpp"
#include "Text.cpp"
#pragma once
#include <SFML/Window.hpp>
#include "RectangleShape.cpp"


class Option:public Clickable{
	public:
		Text text;
		bool T=true;
		float x;
		float y;
		RectangleShape rec;
		Option(){
			
		};
		
		
		Option(std::string font_path,int r,int g, int b,std::string text1,int size,float x, float y){
			
			text=Text(font_path, r, g,  b, text1, size, x,  y);
		
			Clickable::mouseEnabled=T;
			
		}
		
	
		template<typename T>
		void render(sf::RenderWindow *window,T && lambda) {
		
			window->draw(text);
			listen(lambda);
		
		}
		
	
};
