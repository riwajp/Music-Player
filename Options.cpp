#include "RectangleShape.cpp"
#include "Button.cpp"
#pragma once
class Options:public RectangleShape{
	public:

   
	bool opened=false;
	float max_width;
	float max_height=0;
	float x,y;

	
	Options( float width,float height, float x, float y,int r,int g ,int b, int a=255):RectangleShape(width,0,x-250,y,r,g,b,a){
		
	max_width=width;
	max_height=height;
	
	this->x=x-250;
	this->y=y;


	}
	
	void open(){
		std::cout<<max_width;
		opened=true;
	
	}
	void close(){
		opened=false;
	}
	
	void render(sf::Event *event,sf::RenderWindow *window){
		
	
	
			
		if( opened && height<max_height){
			//std::cout<<"opened"<<height;
			height+=1+height*0.1;
			if(height>max_height){
				height=max_height;
			}
			setSize(sf::Vector2f(width,height));
		}else if(!opened && height>0){
			//std::cout<<"Closed";
			height-=30;
			if(height<0){
				height=0;
			}
			setSize(sf::Vector2f(width,height));
			
		}
		window->draw(*this);
		
		
	
		
	}
	
};
