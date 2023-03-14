#include <SFML/windows.hpp>

struct ClickAction{
	float x;
	float y;
	float x_offset;
	float y_offset;
	std::string action;
	
};

class ClickHandler{
	public:
		ClickAction actions[50];
		int actions_last_index=-1;
		//sf::Event *event;
	
		void addAction(float x, float y, float x_offset,float y_offset,std::string p_action){
			ClickAction action;
			action.x=x;
			action.y=y;
			action.x_offset=x_offset;
			action.y_offset=y_offset;
			action.action=p_action;
			
			actions[++actions_last_index]=action;
			
		}
		
		void triggerAction(sf::Event *event){
			cout<<x<<","<<y<<endl;
			
		}
		
	
	
};
