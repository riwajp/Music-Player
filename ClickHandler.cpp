#include <SFML/Window.hpp>
#include <iostream>

#pragma once
struct ClickAction{
	float x;
	float y;
	float x_offset_left,x_offset_right;
	float y_offset_up,y_offset_down;
	std::string action;
	
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
			//std::cout<<actions_last_index<<std::endl;
			
		}
		
		std::string triggerAction(sf::Event *event){
			if(event->type==sf::Event::MouseButtonPressed && (event->mouseButton).button==sf::Mouse::Left){
				//std::cout<<(event->mouseButton).x<<","<<(event->mouseButton).y<<std::endl;
				float x=(event->mouseButton).x;
				float y=(event->mouseButton).y;
				std::cout<<x<<","<<y<<std::endl;
				
				for(int i=0;i<=actions_last_index;i++){
					ClickAction action=actions[i];
					//std::cout<<std::endl<<action.x<<","<<action.x_offset<<std::endl<<action.y<<","<<action.y_offset<<std::endl;
					
					if(x>action.x-action.x_offset_left && x<action.x+action.x_offset_right &&
						y>action.y-action.y_offset_up && y<action.y+action.y_offset_down ){
							//std::cout<<action.action;
							return action.action;
						}
				}
			
		}
			return "nothing";
	}

		
	
	
};
