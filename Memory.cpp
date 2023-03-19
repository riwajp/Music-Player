#include <string>
#include <fstream>
#include <iostream>
#pragma once
struct Playlist{
	std::string name;
	std::string songs[100];
};


class Memory{
	public:
		static Playlist playlists[10];
		static std::string favourites[100];
		static int favourites_size;
		
		
		
		void readPlaylists(){
			
		}
		void writePlaylists(){
			
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
		
		bool isFavourite(std::string track){
		
		
			for(int i=0;i<favourites_size;i++){
			
				if(favourites[i]==track){
					
					
					return true;
					
				}
			}
			return false;
			
		}

	
};


