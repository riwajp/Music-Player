#include <iostream>
#include "MusicItem.cpp"
#include "ClickHandler.cpp"
#include "Options.cpp"
#include "Memory.cpp"
class MusicList{
	public:
		Playlist *playlist;
		Options *options=new Options();
		bool shuffle=false;
		bool repeat=false;
		bool mouseEnabled=true;
		int position=0;
		int size;
		MusicItem *items;
		
		MusicItem *now_playing=NULL;
		int now_playing_index=-1;
		std::string *music_filter;
	
		Memory memory;
	
		
		MusicList(int psize, MusicItem *pitems){
	
        size = psize;
        items = pitems;
    }
    
    
    
    bool isInList(MusicItem *item){
    	if(*music_filter=="all"){
    		return true;
		}
    	else if(*music_filter=="favourites"){
        	if((item)->isFavourite){
        		return true;
			}
		}else if(playlist!=NULL){
			
			if(memory.isInPlaylist((item)->value,playlist)){
				return true;
			}
		}
		return false;
	}
	
	void playNext(){
		
		
		now_playing->unload();
		srand (time(NULL));
		int random=rand()%size;
		
		do{
		
		
		now_playing_index=shuffle?random++%size:(now_playing_index+1)%size;
		now_playing=(items+now_playing_index);
	}while(!isInList(now_playing));
	
		now_playing->load();
		now_playing->play();
		
			
		}
		
		
			void playPrevious(){
				now_playing->unload();
		
		do{
		
		
		now_playing_index=(now_playing_index-1)==-1?size-1 : now_playing_index-1;
		now_playing=(items+now_playing_index);
	}while(!isInList(now_playing));
	
		now_playing->load();
		now_playing->play();
		
			
		}
		
		void autoPlay(){
			if(!repeat){
				playNext();
			}else{
				(now_playing->music).setPlayingOffset(sf::seconds((float)0.f));
				now_playing->play();
			}
		}
    void print(bool *mouseCaptured,sf::RenderWindow *window, sf::Event *event,ClickHandler *click_handler,int *v_position){
    	//options=new Options();
		float x=30;
    	float y;
    	if(*v_position<=210 && *v_position>=210-(size*70-9*70)){

	y=*v_position;
		
		}else{
			y=*v_position>210?210 : 210-(size*70-9*70);
			*v_position=y;
		
		}

    
    
    		
    	
			
			
    	
    
    	sf::Color dark=sf::Color(33,34,37);
    	sf::Color light=sf::Color(55,57,62,150);
    	
    
    	for (int i = 0; i < size; i++)
        {
        	
        if(!isInList(items+i)){
        	continue;
		}
       
        sf::Color color=i%2==0 ? light : light;
        
		if(y>=210 && y<=210+560){
		(items+i)->mouseEnabled=mouseEnabled;
		(items+i)->mouseCaptured=mouseCaptured;
        (items+i)->render(window,event,options,color,x,y,890.f,60.f,18,std::string("./Montserrat.ttf"),50,20);
        //(items+i)->Clickable::listen([i, this]() { this->items[i].onClick(); });
       
    }
		
		
		
		
				
	
		

				if((items+i)->isLoaded && i!=now_playing_index ){
					
					if(now_playing!=NULL){
					
					now_playing->unload();
				}
				
					now_playing=items+i;
					now_playing->play();
					now_playing_index=i;
				
					
					
			}
						
	
        	
        	y+=70;
        	
           
        }
        
        
        if(options!=NULL){
      
		options->render(event,window);
		  if(!options->opened){
        	options->enabled=false;
		}
		
	}
    
    	
	}

		
	
};

