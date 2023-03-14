#include <iostream>
#include "ListItem.cpp"
#include <conio.h>

#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>

#include <mmsystem.h>

class List
{

private:
    int size;                       // number of elements in the array of ListItem
    ListItem *items;                // pointer to the first item of the array of ListItem
              

public:
    // constructor
    List(int psize, ListItem *pitems)
    {
        size = psize;
        items = pitems;
    }

    

    // function to print the list(all its elements)
    
    /*
    void print()
    {
        for (int i = display_index[0]; i <= display_index[1]; i++)
        {
            std::cout << (i == current_index ? "=>  " : "    ");
            std::cout << (items + i)->text << std::endl;
        }
    }
    */
    
    void print(sf::RenderWindow *window, sf::Event *event){
    	int x=0;
    	int y=200;
    	
    	sf::Font font;
    	font.loadFromFile("Montserrat.ttf");
    	for (int i = 0; i < size; i++)
        {
        	sf::RectangleShape rec(sf::Vector2f(950.f,60.f));
        	if(i%2==0){
			
        	rec.setFillColor(sf::Color(33,34,37));
        }else{
        	rec.setFillColor(sf::Color(55,57,62));
        	
		}
		
			rec.setPosition(x,y);
		if(event->type==sf::Event::MouseButtonPressed && (event->mouseButton).button==sf::Mouse::Left){
			int x=(event->mouseButton).x;
			int y=(event->mouseButton).y;
			
			sf::Vector2f position = rec.getPosition();
		
			if(y>=position.y && y<=position.y+60){
				std::cout<<(items+i)->value<<std::endl;
				
			
			

				
			}
		
		}
		sf::Text text;
		text.setString((items+i)->text);
		text.setFont(font);
		text.setCharacterSize(18); 
		text.setFillColor(sf::Color::White);

		text.setPosition(x+50,y+20);

        
		

        	window->draw(rec);
        	window->draw(text);
        	
        	
        	y+=60;
        	
           
        }
    	
	}

    
};


// main function
/*
int main()
{

    string item_names[10] = {"item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10"};
    ListItem *arr = new ListItem[11];
    for (int i = 0; i < 10; i++)
    {

        ListItem item(item_names[i]);
        *(arr + i) = item;
    };
    List list1(10, arr);
    list1.display_size = 4;
    while (true)
    {

        list1.print();

        int ch = getch();
        system("cls");
        list1.scroll(ch);
    }
}
*/
