#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>

#include "MusicList.cpp"

#include <string>

#include "ClickHandler.cpp"

#include "SeekBar.cpp"

#include "Text.cpp"

#include "RectangleShape.cpp"

#pragma once
#include "Clickable.cpp"
#include "Button.cpp"

class MusicPlayer {
    public: SeekBar seekbar;
    MusicItem * now_playing = NULL;
    MusicList * list;
    bool mouseEnabled=true;
    MusicPlayer(MusicList * list) {
        this -> list = list;

    }

    void print(sf::RenderWindow * window, sf::Event * event, ClickHandler * click_handler) {

        RectangleShape main_rec(950, 200, 0, 0, 44, 51, 51, 80);

        window -> draw(main_rec);
        if (now_playing != NULL && now_playing -> isLoaded) {

            Text now_playing_name(std::string("Montserrat.ttf"), 222, 222, 222, now_playing -> text, 22, 70, 25);
            now_playing_name.truncate(70);

            float bc_x = 460;
            float bc_y = 140;
			
			Button pause(&mouseEnabled,now_playing -> isPlaying ? "_pause.png" : "_play.png", 0.05, 0.05, bc_x, bc_y);
            pause.setParams(event,bc_x,bc_y,20,20,30,30);
			pause.render(window,[this](){
				if(this->now_playing->isPlaying){
				
				this->now_playing->pause();
			}else{
				this->now_playing->play();
			}
			});
			
			
			Button next(&mouseEnabled,"_next.png", 0.05, 0.05, bc_x+80, bc_y);
            next.setParams(event,bc_x + 80, bc_y, 20.f, 20.f, 30.f, 30.f);
			next.render(window,[this](){
				this->list->playNext();
			});
			
		
         	Button previous(&mouseEnabled,"_previous.png", 0.05, 0.05, bc_x-80, bc_y);
            previous.setParams(event,bc_x - 80, bc_y, 20.f, 20.f, 30.f, 30.f);
			previous.render(window,[this](){
				this->list->playPrevious();
			});

           

			Button shuffle(&mouseEnabled,list -> shuffle ? "shuffle.png" : "unshuffle.png", list -> shuffle ? 0.04 : 0.055, list -> shuffle ? 0.04 : 0.055, bc_x + 160, bc_y);
            shuffle.setParams(event,bc_x + 160, bc_y, 20.f, 20.f, 30.f, 30.f);
			shuffle.render(window,[this](){
				this-> list -> shuffle = !(list -> shuffle);
			});
			
			
            Button repeat(&mouseEnabled,list -> repeat ? "repeat.png" : "unrepeat.png", list -> repeat ? 0.06 : 0.105, list -> repeat ? 0.06 : 0.105, bc_x - 160, bc_y);
            repeat.setParams(event,bc_x - 160, bc_y, 20.f, 20.f, 30.f, 30.f);
			repeat.render(window,[this](){
				this->list -> repeat = !(list -> repeat);
			});
			


           
            

            window -> draw(now_playing_name);
            seekbar.mouseEnabled=mouseEnabled,
            seekbar.render(window, now_playing, click_handler, event);

        }

        int length = (now_playing -> music).getDuration().asSeconds();
        int clength = (now_playing -> music).getPlayingOffset().asSeconds();
        if (length == clength && length != 0.f ) {
            list -> autoPlay();
        }

    }

};
