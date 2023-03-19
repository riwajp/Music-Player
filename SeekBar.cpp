#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "MusicItem.cpp"
#include "ClickHandler.cpp"
#include "Text.cpp"
#include "RectangleShape.cpp"
#include "Sprite.cpp"
#include "Clickable.cpp"

class SeekBar:public Clickable{
	public:
		sf::Event *event;
		int length,clength;
		MusicItem *now_playing;
	void render(sf::RenderWindow *window,MusicItem *now_playing,ClickHandler *click_handler,sf::Event *event ){
		this->event=event;
		this->now_playing=now_playing;
		//print the duration of now playing
		length=(now_playing->music).getDuration().asSeconds();
		int length_mins=length/60;
		int length_secs=length%60;
		
		Text dtext(std::string("Montserrat.ttf"),222,222,222,std::to_string(length_mins)+":"+std::to_string(length_secs),18,850,62);
					
		//print the offset of now playing
		clength=(now_playing->music).getPlayingOffset().asSeconds();
		int clength_mins=clength/60;
		int clength_secs=clength%60;
		Text ctext(std::string("Montserrat.ttf"),222,222,222,std::to_string(clength_mins)+":"+std::to_string(clength_secs)+" /  ",18,790,62);
	
        
		//rectangles
		float total_width=830;
		float total_height=10.f;
		
		float cwidth=(float)clength/length*total_width;
		RectangleShape rec_filled(cwidth,7,70,96,79,179,196);
	
		
		
		//==============
		RectangleShape rec_empty(total_width-cwidth,5.f,70+cwidth,100,181,235,245);		
		
        	window->draw(rec_filled);
        	window->draw(rec_empty);
        	window->draw(dtext);
        	window->draw(ctext);
        	Sprite sprite(std::string("seek.png"),0.5,0.5,60+cwidth,85);
		
			window->draw(sprite);
			
			
		
		setParams(event,475,100,425.f,425.f,9.f,9.f);
		listen([this]() { 
		float x=(this->event->mouseButton).x;
				
				sf::Time time=sf::seconds((float)(x-50)/850*length);
				(this->now_playing->music).setPlayingOffset(time);});
				
	      
		

        }
};
