#include "Option.cpp"

class SidebarItem:public Option{
	public:
		SidebarItem(std::string font_path,int r,int g, int b,std::string text1,int size,float x, float y){
			Option(font_path,r,g,b,text1,size,x,y);
		}
		template <typename T>
		void render(sf::RenderWindow *window,T && lambda){
			Option::render(window,lambda);
		}
	
	
};
