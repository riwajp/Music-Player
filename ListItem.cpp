#include <iostream>
#include <cstdlib>

class ListItem
{

public:
    std::string text; 
    std::string value;

    // Constructor
    ListItem(){
    	
	}
    ListItem(std::string pvalue)
    {
        value = pvalue;
        text=pvalue;
        
    }
    
    ListItem(std::string pvalue, std::string ptext)
    {
        value = pvalue;
        text=ptext;
        
    }
};

