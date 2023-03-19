#include <SFML/Window.hpp>
#include <iostream>
#pragma once 
class Clickable{
	float cx, cy,  x_offset_left, x_offset_right, y_offset_up,y_offset_down;
	sf::Event *event;
	public:
		Clickable(){
			
		}
		
		
		
		template<typename T>
		void listen(T && lambda){
		
		
				if(event!=NULL && event->type==sf::Event::MouseButtonPressed ){
				
					float x=(event->mouseButton).x;
					float y=(event->mouseButton).y;
					if(x>cx-x_offset_left && x<cx+x_offset_right &&
						y>cy-y_offset_up && y<cy+y_offset_down ){
							
							lambda();
						}
				
					
				}
		}
		
	void printX(){
		std::cout<<2232322323;
	}
		
		void setParams(sf::Event * event,float cx, float cy, float x_offset_left,float x_offset_right,float y_offset_up,float y_offset_down){
			this->cx=cx;
			this->cy=cy;
			this->x_offset_left=x_offset_left;
			this->x_offset_right=x_offset_right;
			this->y_offset_up=y_offset_up;
			this->y_offset_down=y_offset_down;
			this->event=event;
			
			
			
		}
		
		
	
		
		
		
};
