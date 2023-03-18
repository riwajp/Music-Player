#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

struct Texture{
	std::string path;
	sf::Texture texture;

};

static Texture textures[30];
static int size;

static void loadTextures(std::string *paths,int psize){
	size=psize;
	for(int i=0;i<psize;i++){
		
		Texture texture;
		
		texture.path=*(paths+i);
		texture.texture.loadFromFile("./Sprites/"+texture.path);
		textures[i]=texture;
	}
	
	
}

static sf::Texture* getTexture(std::string path){
	for(int i=0;i<size;i++){
		
	if(textures[i].path==path){
		
		return &((textures+i)->texture);
	
	}
	}

	return &(textures->texture);
}


