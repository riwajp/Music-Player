 #include <iostream>
#include "FileScanner.cpp"

#include "MusicPlayer.cpp"
#include <SFML/Graphics.hpp>

using namespace std;


int main()
{

	FileScanner scanner;

	
	string * files=scanner.scan("./Music","ogg");
	int i=0;

	
	while(*(files+i)!="END"){
		i++;
	}
	
	
	MusicItem *list_items=new MusicItem[i];
	for (int j = 0; j < i; j++)
    {
		std:: string value=files[j];
		std::string text=value.substr(8,value.find_last_of(".")-8);

        MusicItem item(value,text);
        *(list_items + j) = item;
    };
    
    MusicList list(i,list_items);
    	MusicPlayer player(&list);

    
    
    
    
    
    sf::RenderWindow window(sf::VideoMode(950,840),"MusidssssssssssssssssPlasyer",sf::Style::Titlebar|sf::Style::Close);
    window.setVerticalSyncEnabled(true); 
	window.setFramerateLimit(60); 
	
	//icon
	
	sf::Image icon;
icon.loadFromFile("./Sprites/icon.png"); // File/Image/Pixel
window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	
	
		
		
  sf::Clock clock;
    float delay = 0.2f; // 200 milliseconds delay between events
    bool can_trigger = true;
    
	sf::Event event;
	int v_position=210;
	while(window.isOpen()){
	ClickHandler click_handler;
	while(window.pollEvent(event)){	
	
				if(event.type==sf::Event::MouseWheelScrolled){
    		int delta=(event.mouseWheelScroll).delta;
    		std::cout<<delta<<std::endl;
    		v_position+=delta*70;
    	}
		if(event.type==sf::Event::Closed) {
			window.close();
		}	
	
	}
	//background
	
	Sprite sprite(std::string("./Sprites/id1.jpg"),1,1,0,0);

			
			
		window.draw(sprite);
		
			sf::RectangleShape main_rec(sf::Vector2f(950.f,830.f));
		main_rec.setFillColor(sf::Color(44,51,51,150));
		main_rec.setPosition(0,0);
			window.draw(main_rec);
		
		
		
	sf::Event *pevent=&event;
	
	 if (event.type == sf::Event::MouseButtonPressed)
            {
                if (can_trigger)
                {
                	 can_trigger = false;
                    clock.restart();
                }else{
                	pevent=NULL;
				}
            }
			list.print(&window,pevent,&click_handler,&v_position);
		player.now_playing=list.now_playing;
			player.print(&window,pevent,&click_handler);
			window.display();
			 if (!can_trigger && clock.getElapsedTime().asSeconds() > delay)
        {
            can_trigger = true;
        }
			
}


    
}



