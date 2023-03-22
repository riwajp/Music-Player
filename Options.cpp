#include "RectangleShape.cpp"
#include "Button.cpp"
#include "Option.cpp"
#include "Memory.cpp"

#pragma once
class Options:public RectangleShape{
	public:
		float height;
		std::string song_path;
	bool enabled=false;
   Memory memory;
	bool opened=false;
	float max_width;
	float max_height=0;
	float x,y;
	bool up=false;
	int max_opacity=0;
	int opacity=0;
	int r,g,b;
	sf::Color color;

	Options(){
	};
	Options( float width,float height, float x, float y,int r,int g ,int b, int a=255):RectangleShape(width,0,x-250,y,r,g,b,0){
	this->height=memory.playlists_size*50 + 10 > height? height : memory.playlists_size*50 + 10;
	max_opacity=a;	
	max_width=width;
	max_height=height;

	this->x=x-250;
	this->y=y;
	this->r=r;
	this->g=g;
	this->b=b;
	


	}
	
	void open(){
		std::cout<<max_width;
		opened=true;
	
	}
	void close(){
		opened=false;
	}
	
	void render(sf::Event *event,sf::RenderWindow *window){
		this->height=memory.playlists_size*50 + 5 > max_height? max_height : memory.playlists_size*50 + 5;
		
	
	/*	Option option(std::string("./Montserrat.ttf"),255,255,255,std::string("Playlist 1"),20,x+5,y+5);
		
			//option.SetParams(window,event,x+5,y+5,290,290.f,20.f,20.f);
			option.setParams(event,x+5,y+5,5,290,0,50);
			//std::cout<<x<<","<<y<<std::endl;
			*/
			window->draw(*this);
		
		
		if( opened && opacity<=max_opacity){
			
			
			setSize(sf::Vector2f(width,height));
			
			//std::cout<<"opened"<<height;
			opacity+=35;
			if(opacity>=max_opacity){
				opacity=max_opacity;
			}
			
			color=sf::Color(r,g,b,opacity);
			setFillColor(color);
			
			
			
			//options list
			//Text textt(std::string("./Montserrat.ttf"),255,255,255,std::string("Playlist 1"),30,200+5,200+5);
			//window->draw(textt);
			//std::cout<<x<<" , "<<y<<std::endl;
				
		
			
			
		}else if(!opened && opacity>0){
			//std::cout<<"Closed";
		
			height=0;
			setSize(sf::Vector2f(width,height));
			opacity-=25;
			if(opacity<0){
				opacity=0;
			}
			color=sf::Color(r,g,b,opacity);
			setFillColor(color);
			window->draw(*this);
			
		}
		
		if(enabled){
			int y=this->y+15;
			for(int i=0;i<memory.playlists_size;i++){
					if(memory.isInPlaylist(song_path,&(this->memory).playlists[i])){
	RectangleShape rec(250,50,x,y-15,20,20,20,230);
	window->draw(rec);
	}
	RectangleShape rec(250,1,x,y+34,255,255,255,230);
	window->draw(rec);
			Option op(std::string("./Montserrat.ttf"),255,255,255,std::string(memory.playlists[i].name),20,x+10,y);
			op.setParams(event,x,y,15,200,20,20);
			op.render(window,[this,i](){
				std::cout<<"Clicked Playlist"<<std::endl;
				if(!memory.isInPlaylist(song_path,&(this->memory).playlists[i])){
				
				(this->memory).playlists[i].songs[memory.playlists[i].songs_size++]=this->song_path;
				(this->memory).writePlaylist((this->memory).playlists[i]);
			}else{
				std::cout<<"Removing";
				(this->memory).removeFromPlaylist(&(this->memory).playlists[i],this->song_path);
			}
			
		
	});
	y+=50;
		}
			/*option.render(window,[](){
				std::cout<<"Lazarus";
			});*/
		}
	
		
		
		
		
		
	
		
	}
	
};
