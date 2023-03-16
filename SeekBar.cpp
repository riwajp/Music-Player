#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "MusicItem.cpp"
#include "ClickHandler.cpp"

class SeekBar{
	public:
		
	
	void drawButton(sf::RenderWindow * window,std::string image,float x, float y,float scale_x,float scale_y){
			sf::Texture texture;
			texture.loadFromFile(image);
			sf::Sprite sprite(texture);
			sprite.setScale(scale_x,scale_y);
			sprite.setPosition(x,y);
		
			
			
		window->draw(sprite);
			
					
		}
	void render(sf::RenderWindow *window,MusicItem *now_playing,ClickHandler *click_handler,sf::Event *event ){
	
	
		
		sf::Font font;
    	font.loadFromFile("Montserrat.ttf");
		sf::Text dtext,ctext;
		
		//print the duration of now playing
		int length=(now_playing->music).getDuration().asSeconds();
		int length_mins=length/60;
		int length_secs=length%60;
		
		dtext.setString(std::to_string(length_mins)+":"+std::to_string(length_secs));
		dtext.setFont(font);
		dtext.setCharacterSize(18); 
		dtext.setFillColor(sf::Color(255,255,255));

		dtext.setPosition(850.f,58.f);
		
		//print the offset of now playing
		int clength=(now_playing->music).getPlayingOffset().asSeconds();
		int clength_mins=clength/60;
		int clength_secs=clength%60;
		
		ctext.setString(std::to_string(clength_mins)+":"+std::to_string(clength_secs)+" / ");
		ctext.setFont(font);
		ctext.setCharacterSize(18); 
		ctext.setFillColor(sf::Color(255,255,255));

		ctext.setPosition(800.f,58.f);

        
		//rectangles
		float total_width=850;
		float total_height=10.f;
		
		float cwidth=(float)clength/length*total_width;
		
		sf::RectangleShape rec_filled(sf::Vector2f(cwidth,18.f));
		rec_filled.setFillColor(sf::Color(134,134,135));
		rec_filled.setPosition(50,96);
		
		
		//==============
		
		sf::RectangleShape rec_empty(sf::Vector2f(total_width-cwidth,10.f));
		rec_empty.setFillColor(sf::Color(67,68,69));
		rec_empty.setPosition(50+cwidth,100);
		
		
        	window->draw(rec_filled);
        	window->draw(rec_empty);
        	window->draw(dtext);
        	window->draw(ctext);
	drawButton(window,"./Sprites/seek.png",40+cwidth,87,0.6,0.6);
		click_handler->addAction(475,100,425.f,425.f,9.f,9.f,"seek");
			if(click_handler->triggerAction(event)=="seek"){
				float x=(event->mouseButton).x;
				
				sf::Time time=sf::seconds((float)(x-50)/850*length);
				(now_playing->music).setPlayingOffset(time);
				std::cout<<x<<std::endl;
			}	      
		

        }
};
