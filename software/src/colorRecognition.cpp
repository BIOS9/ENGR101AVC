#include <stdio.h>
#include "E101.h"
#include <unistd.h>
#include <time.h>
#include <iostream>

//Setting up the namespace
using namespace std;

int main()
{	
	//Initialising the variables
	init();
	int arr;
	arr = int();
	int countrun = 0;
	int counter = 0;
	int totgreen = 0;
	
	int totintgreen = 0;
	
	int countc = 0;
	float greeness = 0;
	float  redness = 0;
	
	//Loop runs until condition is met
	while(countrun != -1)
	{
		//Setting up the variables to grab the pixel colours
		select_IO(0, 0);
		open_screen_stream();
		take_picture();
		update_screen();
		counter = 80;
		totgreen = 0;
		
		totintgreen = 0;
		
		countc = 0;
		greeness = 0;
		redness = 0;
		
		//running vertically down the image
		while(counter<160)
		{
			//Setting the horizontal image counter
			countc=106;
			//running horizontally accross the image
			while(countc<213)
			{
				//Getting the red and green values of each pixel
				totgreen = totgreen + (int)get_pixel(counter,countc,1);
				totintgreen = totintgreen + (int)get_pixel(counter,countc,3);
				greeness = (float)totgreen/(3.0*(float)totintgreen);
				
				countc++;			
			}
			//Checking if the ruby is initially present
			if (counter == 80) {
				if (greeness > 0.02 and greeness < 0.4) {
						cout<<"Ruby is present"<< endl;
						//printf("	\n");
					//printf("Greeness %f\n", greeness);
					//printf("	\n");
					//printf("redness %f\n", redness);
						
				} else {
					printf("No ruby");
					//printf("	\n");
					//printf("Greeness %f\n", greeness);
					//printf("Greeness %f\n", greeness);
					//printf("	\n");
					//printf("redness %f\n", redness);
					break;
					
				}				
			}

			counter++;	
		}

		//Sleeping an dincrementing the program
		sleep1(0,20000);
		countrun++;

		//Checking if the ruby is gone
			 if (greeness < 0.02 or greeness > 0.4) {
				
				
									printf("	\n");
					printf("Greeness %f\n", greeness);
					printf("	\n");
					printf("redness %f\n", redness);
					printf("It's gone!! Someone stole it. \n");
					//Makes the loop exit
					countrun = -1;

			}
		
	}
	//Printed whent he loop exits
	close_screen_stream();
	printf("After intt() error=%d\n", arr);
	printf("Again\n");
	return 0;
}
 
