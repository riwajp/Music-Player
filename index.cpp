 #include <iostream>
#include "FileScanner.cpp"

#include "MusicPlayer.cpp"
#include <SFML/Graphics.hpp>
#include "Sidebar.cpp"
#include "Options.cpp"


using namespace std;


	
int main()
{
	Memory memory;
	memory.readFavourites();
	memory.readPlaylists();
	memory.getBackground();
	

	
	
	Playlist *playlist=new Playlist();
	
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

    //load textures
    string paths[]={"background.png","edit.png","playlist.png","home.png","delete.png","plus.png","cross.png","hamburger.png","_next.png","_pause.png","_play.png","_previous.png","_shuffle.png","_stop.png","_unshuffle.png","add.png","heart.png","icon.png","repeat.png","seek.png","shuffle.png","unheart.png","unrepeat.png","unshuffle.png"};
    loadTextures(paths,24);
    
	
    
    

    sf::RenderWindow window(sf::VideoMode(950,840),"ssssssssss]ss",sf::Style::Titlebar|sf::Style::Close);
    window.setVerticalSyncEnabled(true); 
	
	//icon
	
	sf::Image icon;
icon.loadFromFile("./Sprites/icon.png"); // File/Image/Pixel
window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	
		
		
  sf::Clock clock;
    float delay = 0.3f; // 200 milliseconds delay between events
    bool can_trigger = true;
   
    
	sf::Event event;
	int v_position=210;
	
	bool mouseCaptured=false;

	std::string music_filter="all";
	list.music_filter=&music_filter;
	
	Sidebar sidebar(&mouseCaptured,&music_filter,&playlist,300,840,0,0,50,50,50,230);
		std::string background=memory.background;
	sf::Texture texture;
	texture.loadFromFile(memory.background);
	while(window.isOpen()){
	
	ClickHandler click_handler;
	
	

	
	while(window.pollEvent(event)){	
	
				if(event.type==sf::Event::MouseWheelScrolled){
    		int delta=(event.mouseWheelScroll).delta;
    		
    		v_position+=delta*70;
    	}
		if(event.type==sf::Event::Closed) {
			window.close();
		}	
	
	}
	//background
	if(background!=memory.background){
	
	texture.loadFromFile(memory.background);
	background=memory.background;
}
	sf::Sprite sprite;
	sprite.setScale(1,1);

	sprite.setTexture(texture);
	sprite.setPosition(0,0);	

		//sprite=Sprite(std::string(memory.background),1,1,0,0);
		window.draw(sprite);
		
	
	
		
			sf::RectangleShape main_rec(sf::Vector2f(950.f,830.f));
		main_rec.setFillColor(sf::Color(44,51,51,150));
		main_rec.setPosition(0,0);
			window.draw(main_rec);
		
	

		
	sf::Event *pevent=&event;
	
	
	

	

	
	 if (event.type == sf::Event::MouseButtonPressed )
            {
                if (can_trigger)
                {
                	 can_trigger = false;
                    clock.restart();
                }else{
                	pevent=NULL;
				}
            }
            
            
            
            list.mouseEnabled=!mouseCaptured;
            list.playlist=playlist;
			list.print(&mouseCaptured,&window,pevent,&click_handler,&v_position);
			
			player.now_playing=list.now_playing;
			player.mouseEnabled=!mouseCaptured;
		
			player.print(&window,pevent,&click_handler);
			
			
	
	
	
	

	sidebar.render(pevent,&window,&v_position);
	
	window.display();	
	
	
	 if (!can_trigger && clock.getElapsedTime().asSeconds() > delay)
        {
            can_trigger = true;
        }
        
       
}


    
}



