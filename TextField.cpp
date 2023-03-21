#include "RectangleShape.cpp"
#include "Text.cpp"

class TextField{
	public:
		 inline static float k_delay=0.08;
    inline static bool k_can_trigger;
    inline static   sf::Clock k_clock;
    inline static char previous_inputChar;

		bool enabled;
		inline static std::string value="Hello|";
		RectangleShape rec;
		RectangleShape underline;
		Text text;
		TextField(){
		};
		TextField(float width,float height, float x, float y,int r,int g ,int b, int a=255){
			rec=RectangleShape(width,height,x,y,r,g,b);
			underline=RectangleShape(width,2,x,y+height,255,255,255,255);
			text=Text("./Montserrat.ttf",255,255,255,value,20,x+10,y+7);
			
		}
		
		template<typename T>
		void render(sf::RenderWindow *window,sf::Event *event, T && onEnter){
			
			window->draw(rec);
			window->draw(underline);
			window->draw(text);
			
			
		
            if(event!=NULL && event->type==sf::Event::TextEntered){
            	std::cout<<"here";
				
            	
				char inputChar = ((event->key).code);
						
            
                if (k_can_trigger || previous_inputChar!=inputChar)
                {
                	k_can_trigger = false;
                    k_clock.restart();
            
				
				
				value.pop_back();
				
					if(inputChar=='\b'){
						if (!value.empty()) {
                                value.pop_back();
                            }
					} else if ((event->text).unicode==13) {
                            onEnter();
                            
                            
                            
                        }else{
                        	value.push_back(inputChar);
                        	std::cout<<value<<std::endl;
                        	
                        
						}
					
					
				value.push_back('|');
				text.text=value;
			}
				previous_inputChar=inputChar;
			 if (!k_can_trigger && k_clock.getElapsedTime().asSeconds() > k_delay)
			{
				k_can_trigger = true;
			}
	
			
	
		}}
		
		
	
	
};
