#include "RectangleShape.cpp"
#include "Button.cpp"
#include "Option.cpp"
#include "TextField.cpp"
#include "Memory.cpp"

class Sidebar:public RectangleShape{
	public:
		Memory memory;
	TextField text_field;
	TextField bg_text_field;
   bool textboxOpened=false;
   bool bgTextboxOpened=false;
	bool opened=false;
	float max_width;
	bool * mouseCaptured;
	std::string * music_filter;
	Playlist **playlist;
	
	Sidebar( bool * mouseCaptured,std::string * music_filter,Playlist ** playlist,float width,float height, float x, float y,int r,int g ,int b, int a=255):RectangleShape(0,height,x,y,r,g,b,a){
	this->music_filter=music_filter;
	max_width=width;
	this->mouseCaptured=mouseCaptured;
	this->playlist=playlist;


	}
	
	void open(){
	
		opened=true;
	
	}
	void close(){
		opened=false;
	}
	
	void render(sf::Event *event,sf::RenderWindow *window,int *v_position){
	
	
			
		if(opened && width<max_width){
			
			width+=2+width;
			if(width>max_width){
				width=max_width;
			}
			setSize(sf::Vector2f(width,height));
		}else if(!opened && width>0){
			
			width-=1+width*0.6;
			if(width<0){
				width=0;
			}
			setSize(sf::Vector2f(width,height));
			
		}
		window->draw(*this);
		
		bool T=true;
		Button ham(&T,opened?"cross.png":"hamburger.png", opened?0.05:0.03, opened?0.05:0.03, 15, 20);
		ham.setParams(event,15, 30, 22.f, 22.f, 30.f, 30.f);
		ham.render(window,[this](){
		(this->textboxOpened)=false;
		(this->text_field).value="Playlist 1|";
		this->opened=!(this->opened);
		*(this->mouseCaptured)=!*(this->mouseCaptured);
		std::cout<<"Triggered"<<std::endl;
		
	});	
	
	
	//items
	float x=width-max_width+25;
	float y=130;
		
	if(opened){
	
	//home
	if(*music_filter=="all"){
	RectangleShape rec(310,60,x-35,y-16.5,20,20,20,230);
	window->draw(rec);
	}
	Sprite home_sprite("home.png",0.018,0.018,x,y);

	window->draw(home_sprite);
	Option home(std::string("./Montserrat.ttf"),255,255,255,std::string("Home"),20,x+40,y);
	home.setParams(event,x,y,15,300,20,20);
	home.render(window,[this,v_position](){
		std::cout<<"Home";
		*(this->music_filter)="all";
		this->opened=false;
		*(this->mouseCaptured)=!*(this->mouseCaptured);
		*v_position=210;
	});
	
	//favourites
	y+=60;
	if(*music_filter=="favourites"){
	RectangleShape rec(310,60,x-35,y-16.5,20,20,20,230);
	window->draw(rec);
	}
	Sprite favs_sprite("unheart.png",0.09,0.09,x,y);

	window->draw(favs_sprite);
	
	Option favs(std::string("./Montserrat.ttf"),255,255,255,std::string("Favourites"),20,x+40,y);
	favs.setParams(event,x,y,15,300,20,20);
	favs.render(window,[this,v_position](){
		std::cout<<"Favourite";
		*(this->music_filter)="favourites";
		this->opened=false;
		*(this->mouseCaptured)=!*(this->mouseCaptured);
		*v_position=210;
	});
	
	y+=60;
	
	//Playlist
	y+=40;
	Sprite pl_sprite("playlist.png",0.04,0.04,x,y+4);
	window->draw(pl_sprite);
	Option pl(std::string("./Montserrat.ttf"),255,255,255,std::string("Playlists"),22,x+40,y);
	pl.text.setStyle(sf::Text::Bold);
	pl.setParams(event,x,y,15,200,20,20);
	pl.render(window,[](){	
	});
	
	RectangleShape rec(275,2,x-10,y+32,255,255,255);
	window->draw(rec);
	

	
	//Add Playlist
	bool T=true;
	Button add(&T,"plus.png", 0.028, 0.028, x+230, y-3);
            add.setParams(event,x+230, y-6, 20.f, 20.f, 30.f, 30.f);
			add.render(window,[this](){
				std::cout<<"Add Playlist";
				(this->text_field).value="Playlist 1|";
				this->textboxOpened=true;
				this->bgTextboxOpened=false;
			});
			
	y+=60;		
			
	if(textboxOpened){
	
	text_field=TextField(220,40,x,y,100,100,100,200);
	text_field.render(window,event,[this](){
		this->textboxOpened=false;
		
		Playlist playlist;
		playlist.name=(this->text_field).value;
		
		memory.playlists[memory.playlists_size++]=playlist;
		memory.writePlaylists();
		
	});
	
		Button cancel(&T,"cross.png", 0.04, 0.04, x+240, y+10);
            cancel.setParams(event,x+240, y+10, 15.f, 15.f, 20.f, 20.f);
			cancel.render(window,[this](){
				
				this->textboxOpened=false;
				
			});
	
		y+=70;
}
	
	
		
		for(int i=0;i<memory.playlists_size;i++){
			
				if(*music_filter=="playlist" && (*(playlist))->name==(memory.playlists[i]).name){
	RectangleShape rec(310,50,x-35,y-11.5,20,20,20,230);
	window->draw(rec);
	}
	
			Option op(std::string("./Montserrat.ttf"),255,255,255,std::string(memory.playlists[i].name),20,x,y);
			op.setParams(event,x,y,15,200,20,20);
			op.render(window,[this,i,v_position](){
				std::cout<<((this->memory).playlists[i].name);
				*(this->music_filter)="playlist";
		this->opened=false;
		*(this->mouseCaptured)=!*(this->mouseCaptured);
				
				*(this->playlist)=&((this->memory).playlists[i]);
				*v_position=210;
				
		
	});
	
		Button del(&T,"delete.png", 0.045,0.045, x+230, y);
		del.setParams(event,x+230, y, 22.f, 22.f, 30.f, 30.f);
		del.render(window,[this,i](){
			std::cout<<"Delete";
			(this->memory).deletePlaylist(&(this->memory).playlists[i]);
			*(this->music_filter)="all";
		
	});
	
	y+=60;
		}
	y+=60;	
	
	
	Sprite bg_sprite("background.png",0.022,0.022,x,y+1);
	window->draw(bg_sprite);
	Option bg(std::string("./Montserrat.ttf"),255,255,255,std::string("Background"),22,x+40,y);
	bg.text.setStyle(sf::Text::Bold);
	bg.setParams(event,x,y,15,200,20,20);
	bg.render(window,[](){	
	});
		
	RectangleShape brec(275,2,x-10,y+32,255,255,255);
	window->draw(brec);
	

	
	//Add Playlist
	
	Button edit(&T,"edit.png", 0.04, 0.04, x+230, y+1);
            edit.setParams(event,x+230, y-6, 20.f, 20.f, 30.f, 30.f);
			edit.render(window,[this](){
				(this->bg_text_field).value=memory.background+"|";
				this->bgTextboxOpened=true;
				this->textboxOpened=false;
			});
			
		y+=50;

	if(bgTextboxOpened){
	bg_text_field=TextField (220,40,x,y,100,100,100,200);
	
	bg_text_field.render(window,event,[this](){
		this->bgTextboxOpened=false;
		memory.setBackground((this->bg_text_field).value);
		
	
		
	});
	
		Button bg_cancel(&T,"cross.png", 0.04, 0.04, x+240, y+10);
            bg_cancel.setParams(event,x+240, y+10, 15.f, 15.f, 20.f, 20.f);
			bg_cancel.render(window,[this](){
				
				this->bgTextboxOpened=false;
				
			});
}else{
	Option pl(std::string("./Montserrat.ttf"),255,255,255,std::string(memory.background),20,x+15,y);
	
	pl.setParams(event,x+20,y,15,200,20,20);
	pl.render(window,[](){	
	});
}
	}
}
};
