#include <iostream>
#include "FileScanner.cpp"
#include "MusicList.cpp"

#include "MusicPlayer.cpp"
#include <SFML/Graphics.hpp>



using namespace std;


int main()
{

	FileScanner scanner;
	MusicPlayer player;
	
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
    
    
    
    
    
    sf::RenderWindow window(sf::VideoMode(950,800),"Musisssssc Plssayer");
    window.setVerticalSyncEnabled(true); 
	window.setFramerateLimit(10); 
	

	sf::Event event;
	while(window.isOpen()){
	ClickHandler click_handler;
	while(window.pollEvent(event)){	
			
		if(event.type==sf::Event::Closed) {
			window.close();
		}	
		
	}
	
			list.print(&window,&event,&click_handler);
			player.now_playing=list.now_playing;
			player.print(&window);
			window.display();
			
}


    
}



