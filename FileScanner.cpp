#include <string>
#include <iostream>
#include <filesystem>
#include <stdlib.h>
#include <array>
namespace fs=std::filesystem;





class FileScanner{
	
	
	public:

	FileScanner(){
	
	}
	
	std::string *  scan(std::string path){
		static std::string files[100];
		int i=0;
    	for (const auto& entry : fs::directory_iterator(path)){
	
       
        files[i]=entry.path().u8string();
        i++;
    }
    
    files[i]="END";
   
    return &files[0];
		
	}
	
	std::string *  scan(std::string path,std::string extension){
		static std::string files[100];
		std::string * files_p=scan(path);
		int i=0;
		int j=0;
		while(*(files_p+i)!="END"){
			std::string current_file=*(files_p+i);
		if(current_file.substr(current_file.find_last_of(".")+1)==extension){
			files[j]=current_file;
		
			j++;
		}
		
		i++;
	}
	files[j]="END";
	return &files[0];
		
		
	}
	
};


