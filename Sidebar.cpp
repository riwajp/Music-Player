#include "RectangleShape.cpp"
#include "Button.cpp"

class Sidebar:public RectangleShape{
	public:

   
	bool opened=false;
	float max_width;
	
	Sidebar( float width,float height, float x, float y,int r,int g ,int b, int a=255):RectangleShape(0,height,x,y,r,g,b,a){
		
	max_width=width;


	}
	
	void open(){
		std::cout<<max_width;
		opened=true;
	
	}
	void close(){
		opened=false;
	}
	
	void render(sf::Event *event,sf::RenderWindow *window){
	
	
			
		if(opened && width<max_width){
			std::cout<<"opened"<<width;
			width+=1+width*0.6;
			if(width>max_width){
				width=max_width;
			}
			setSize(sf::Vector2f(width,height));
		}else if(!opened && width>0){
			std::cout<<"Closed";
			width-=30;
			if(width<0){
				width=0;
			}
			setSize(sf::Vector2f(width,height));
			
		}
		window->draw(*this);
		
		
			Button ham(opened?"closed.png":"hamburger.png", opened?0.05:0.03, opened?0.05:0.03, 15, 20);
		ham.setParams(event,15, 30, 22.f, 22.f, 30.f, 30.f);
		ham.render(window,[this](){
		
		this->opened=!this->opened;
		
	});	
		
	}
};
