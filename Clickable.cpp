#include <SFML/Window.hpp>


class Clickable{
	float cx, cy,  x_offset_left, x_offset_right, y_offset_up,y_offset_down;
	sf::Event *event;
	public:
		Clickable(float cx, float cy, float x_offset_left,float x_offset_right,float y_offset_up,float y_offset_down){
			
		}
		
		virtual void onClick()=0;
		
		void render(){
				if(event!=NULL && event->type==sf::Event::MouseButtonPressed ){
					float x=(event->mouseButton).x;
					float y=(event->mouseButton).y;
					if(x>x-x_offset_left && x<x+x_offset_right &&
						y>y-y_offset_up && y<y+y_offset_down ){
							
							onClick();
						}
				
					
				}
		}
		
		
		
};
