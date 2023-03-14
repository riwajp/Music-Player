#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;


int main()
{
   int n;
   time_t t1, t2, previous_pause_time=0;
   
   //open the audio file
   mciSendString("open \"music.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
   
   while(1)
   {
   	
   	cout << "Press 1 to play the file and press 2 to exit the file." << endl;
      cin>>n;
      if(n==1)
      {	
      	//play the audio file
   		t1=time(0);
   		mciSendString("play mp3", NULL, 0, NULL);
   		cout<<"Audio file playing...\n\n";
   	}
   	else if(n==2)
   	{
   		//close the file and get out of the loop
   		mciSendString("close mp3", NULL, 0, NULL);
   		break;
   	}

   	cout << "Press 0 to pause the file and press 2 to exit the file." << endl;
   	cin>>n;
   	if(n==0)
   	{
   		//pause the audio file
   		mciSendString("pause mp3", NULL, 0, NULL);
   		t2=time(0);
   		cout<<"Audio file paused after " << t2-t1+previous_pause_time << " seconds.\n\n";
   		previous_pause_time+=t2-t1;
   	}
   	else if(n==2)
   	{
   		//close the audio file
   		mciSendString("close mp3", NULL, 0, NULL);
   		break;
   	}
   		
   }
  

   return 0;
}
