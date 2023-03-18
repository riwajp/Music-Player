#include <SFML/Window.hpp>
#include <iostream>

#pragma once
struct ClickAction{
	float x;
	float y;
	float x_offset_left,x_offset_right;
	float y_offset_up,y_offset_down;
	std::string action;
	bool left=true;
	
};

class ClickHandler{
	public:
		ClickAction actions[50];
		int actions_last_index=-1;
		//sf::Event *event;
	
		void addAction(float x, float y, float x_offset_left,float x_offset_right,float y_offset_up,float y_offset_down,std::string p_action){
			ClickAction action;
			action.x=x;
			action.y=y;
			action.x_offset_left=x_offset_left;
			action.x_offset_right=x_offset_right;
			action.y_offset_up=y_offset_up;
			action.y_offset_down=y_offset_down;
			action.action=p_action;
			
			
			actions[++actions_last_index]=action;
		
			
		}
	
		std::string triggerAction(sf::Event *event){
			std::string triggered_action;
		

		
			
			if(event!=NULL && event->type==sf::Event::MouseButtonPressed ){
				
			
				float x=(event->mouseButton).x;
				float y=(event->mouseButton).y;
				
				
				for(int i=0;i<=actions_last_index;i++){
					ClickAction action=actions[i];
					if((action.left && (event->mouseButton).button==sf::Mouse::Left) ||(!action.left && (event->mouseButton).button==sf::Mouse::Right) ){
					
				
					
					if(x>action.x-action.x_offset_left && x<action.x+action.x_offset_right &&
						y>action.y-action.y_offset_up && y<action.y+action.y_offset_down ){
							
							triggered_action= action.action;
						}
					}
				}
			
		}

			

	

        return triggered_action;
}

		
	
	
};
