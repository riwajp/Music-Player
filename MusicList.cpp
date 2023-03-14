#include <iostream>
#include "MusicItem.cpp"


class MusicList{
	public:
		int size;
		MusicItem *items;
		MusicItem *now_playing;
		
		MusicList(int psize, MusicItem *pitems){
        size = psize;
        items = pitems;
    }
    
    
    
    
    void print(sf::RenderWindow *window, sf::Event *event){
    	int x=0;
    	int y=200;
    	
    	sf::Font font;
    	font.loadFromFile("Montserrat.ttf");
    	sf::Color dark=sf::Color(33,34,37);
    	sf::Color light=sf::Color(55,57,62);
    
    	
    	for (int i = 0; i < size; i++)
        {
       
        sf::Color color=i%2==0 ? dark : light;
        
			
        (items+i)->render(window,color,x,y,950.f,60.f,18,sf::Color(222,222,222),font,50,20);
		
		
		if(event->type==sf::Event::MouseButtonPressed && (event->mouseButton).button==sf::Mouse::Left){
			int mx=(event->mouseButton).x;
			int my=(event->mouseButton).y;
			
			
		
			if(my>=y && my<=y+60){
			
				std::cout<<(items+i)->text;
				(items+i)->load();
				
				now_playing=(items+i);
			(items+i)->play();
						

				
			}
		
		}
		
		
        	
        	
        	y+=60;
        	
           
        }
    	
	}

		
	
};

