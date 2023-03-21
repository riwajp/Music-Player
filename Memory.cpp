#include <string>
#include <fstream>
#include <iostream>
#pragma once
struct Playlist{
	std::string name;
	std::string songs[100];
	int songs_size=0;
};


class Memory{
	public:
		inline static Playlist playlists[10];
		inline static int playlists_size;
		inline static std::string favourites[100];
		inline static int favourites_size;
		inline static std::string background;
		
		
		
		void readPlaylists(){
			std::ifstream infile("./Data/playlists.txt");
			playlists_size=0;
			if (infile) {
				
        		std::string line;
        		while (getline(infile, line)) {
        		Playlist playlist;
        		playlist.name=line;
        		std::ifstream iinfile("./Data/"+line+".txt");
        		if(iinfile){
        			std::string lline;
        			while(getline(iinfile,lline)){
        				playlist.songs[playlist.songs_size++]=lline;
					}
				}
        		
        		
        		
        			
            	playlists[playlists_size++] = playlist;
            	
            	
        }
        infile.close();
			
		}
	}
		void writePlaylists(){
			std::ofstream outfile;
		   outfile.open("./Data/playlists.txt");
		   
		  
		   for (int i = 0; i < playlists_size; i++) {
		      outfile << playlists[i].name << std::endl;
		   }
		   
		   outfile.close();
			
		}
		
		void writePlaylist(Playlist playlist){
			std::ofstream outfile;
		   outfile.open("./Data/"+playlist.name+".txt");
		   
		  
		   for (int i = 0; i < playlist.songs_size; i++) {
		      outfile << playlist.songs[i] << std::endl;
		   }
		   
		   outfile.close();
			
		}
		
		void removeFromPlaylist(Playlist *playlist,std::string track){
			int j=0;
			for(int i=0;i<playlist->songs_size;i++){
				if(playlist->songs[i]==track){
					
					continue;
				}
				playlist->songs[j]=playlist->songs[i];
				j++;
				
			}
			playlist->songs_size--;
			writePlaylists();
		}
		
		void deletePlaylist(Playlist * playlist){
			int j=0;
			for(int i=0;i<playlists_size;i++){
				if(playlists[i].name==playlist->name){
					
					continue;
				}
				playlists[j]=playlists[i];
				j++;
				
			}
			playlists_size--;;
			writePlaylists();
			
		}
	bool isInPlaylist(std::string song_path,Playlist *playlist){
		
		for(int i=0;i<playlist->songs_size;i++){
			
			if((playlist->songs)[i]==song_path){
				
				return true;
			
			}
		}
		return false;
		
	}
		void readFavourites(){
			std::ifstream infile("./Data/favourites.txt");
			favourites_size=0;
			if (infile) {
        		std::string line;
        		while (getline(infile, line)) {
            	favourites[favourites_size++] = line;
            	
            	
        }
        infile.close();
    }

			
		}
		
		void writeFavourites(){
			   
		   std::ofstream outfile;
		   outfile.open("./Data/favourites.txt");
		   
		  
		   for (int i = 0; i < favourites_size; i++) {
		      outfile << favourites[i] << std::endl;
		   }
		   
		   outfile.close();
		}
		
		void addFavourites(std::string track){
			favourites[favourites_size++]=track;
			writeFavourites();
		}
		
		void removeFavourites(std::string track){
			int j=0;
			for(int i=0;i<favourites_size;i++){
				if(favourites[i]==track){
					
					continue;
				}
				favourites[j]=favourites[i];
				j++;
			}
			favourites_size--;
			writeFavourites();
		}
		
		bool isFavourite(std::string track){
		
		
			for(int i=0;i<favourites_size;i++){
			
				if(favourites[i]==track){
					
					
					return true;
					
				}
			}
			return false;
			
		}
		
		void getBackground(){
			std::ifstream infile("./Data/background.txt");
		
			if (infile) {
        		std::string line;
        		while (getline(infile, line)){
				
            	background = line;
            }
            	std::cout<<line;
            	
            	
        
        infile.close();
			
		}else{
			std::cout<<"EEEEEEEEEEEEEEEEEEee";
		}
	}
		
		void setBackground(std::string bg){
			background=bg;
			std::ofstream outfile;
		   outfile.open("./Data/background.txt");
		   
		  	
		  
		    outfile << background << std::endl;
		   
		   
		   outfile.close();
			
		}

	
};


