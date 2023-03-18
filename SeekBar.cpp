#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "MusicItem.cpp"
#include "ClickHandler.cpp"
#include "Text.cpp"
#include "RectangleShape.cpp"
#include "Sprite.cpp"

class SeekBar{
	public:
	void render(sf::RenderWindow *window,MusicItem *now_playing,ClickHandler *click_handler,sf::Event *event ){
		
		//print the duration of now playing
		int length=(now_playing->music).getDuration().asSeconds();
		int length_mins=length/60;
		int length_secs=length%60;
		
		Text dtext(std::string("Montserrat.ttf"),222,222,222,std::to_string(length_mins)+":"+std::to_string(length_secs),18,850,58);
					
		//print the offset of now playing
		int clength=(now_playing->music).getPlayingOffset().asSeconds();
		int clength_mins=clength/60;
		int clength_secs=clength%60;
		Text ctext(std::string("Montserrat.ttf"),222,222,222,std::to_string(clength_mins)+":"+std::to_string(clength_secs)+" / ",18,800,58);
	
        
		//rectangles
		float total_width=850;
		float total_height=10.f;
		
		float cwidth=(float)clength/length*total_width;
		RectangleShape rec_filled(cwidth,7,50,96,79,179,196);
	
		
		
		//==============
		RectangleShape rec_empty(total_width-cwidth,5.f,50+cwidth,100,181,235,245);		
		
        	window->draw(rec_filled);
        	window->draw(rec_empty);
        	window->draw(dtext);
        	window->draw(ctext);
        	Sprite sprite(std::string("./Sprites/seek.png"),0.5,0.5,40+cwidth,85);
		
			window->draw(sprite);
		click_handler->addAction(475,100,425.f,425.f,9.f,9.f,"seek");
			if(click_handler->triggerAction(event)=="seek"){
				float x=(event->mouseButton).x;
				
				sf::Time time=sf::seconds((float)(x-50)/850*length);
				(now_playing->music).setPlayingOffset(time);
				std::cout<<x<<std::endl;
			}	      
		

        }
};
