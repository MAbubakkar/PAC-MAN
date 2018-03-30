#include<iostream>
#include <windows.h>
using namespace std;
#include"Player.h"
Player::Player()
{
	  x=0;
	  y=0;
	  BLANK = ' ';
	        		 PAC_MAN = '<';
	        		 FOOD = 'o';
	        		 MAP_ROWS = 27;
	        		 MAP_COLUMNS =100;
	        		LEFT = 1;
	        		 RIGHT = 2;
	        		 UP = 3;
	        		 DOWN = 4;
	        		 direction = 0;
	        		 Score =0;
	        		 bhou='@';
	        		 fruit='$';
	        		 w=0,q=0;
	        		 a=0;
	        		  qa=19;
	        		  az=20;
	        			 b=0;
	        			 z=1;
}
const char BOUNDARY='|';
                    const int LEFT = 1;
                    const int RIGHT = 2;
                    const int UP = 3;
                    const int DOWN = 4;

int main()
{


	Player player;
	int u=5;
	player.map[19][20]=player.fruit;//player.fruit;
	 while(!GetAsyncKeyState(VK_SPACE))
			   {
				  system("cls");
				   u++;
	         			player.color(u);
		       			if(u==15)
		       			{
		       				u=1;
		       			}
			   player.faisal(u);
			   cout<<"\n\t\t\tPress SPACE To Continue:";
			   Sleep(300);
			   }
		   player.MOVEMENT(player, 3, 3);
		   while (true)
		   {
			   system("cls");
			   player.color(22);
		       player.MAP();
		       player.SCORE();
		       if (GetAsyncKeyState(VK_UP))
			   {
				   player.direction = player.UP;
			   }
		       else if (GetAsyncKeyState(VK_DOWN))
			   {
				   player.direction = player.DOWN;
			   }
		       else if (GetAsyncKeyState(VK_LEFT))
			   {
		    	   player.direction = player.LEFT;
			   }
		       else if (GetAsyncKeyState(VK_RIGHT))
			   {
		    	   player.direction = player.RIGHT;
			   }
		       switch (player.direction)
			   {
			   case UP:
				   {
					   player.MOVEMENT(player, player.x-1, player.y);
				       break;
				   }
			   case DOWN:
				   {
					   player.MOVEMENT(player, player.x+1, player.y);
					   break;
				   }
		       case LEFT:
				   {
					   player.MOVEMENT(player, player.x, player.y-1);
					   break;
				   }
		       case RIGHT:
				   {
					   player.MOVEMENT(player, player.x, player.y+1);
					   break;
				   }

			   }
		        Sleep(200);
				if(player.Score>=20)
				{
					player.color(18);
					cout<<endl<<endl<<"\t\t\tYour Score is"<<player.Score<<"\t\t\t\t\t\t\t\t\t"<<endl;
					Sleep(1000);
					system("cls");
					while(!GetAsyncKeyState(VK_SPACE))
					{
						player.color(32);
						cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t PRESS SPACE TO PLAY LEVEL 2";
						Sleep(1000);
						system("cls");


					}
					player.level2();
					Sleep(500);

				}
		   }

    return 0;

}
int Player:: level2()
						{

	                    const int LEFT = 1;
	                    const int RIGHT = 2;
	                    const int UP = 3;
	                    const int DOWN = 4;

							Player player;
							player.map2[2][16]=player.fruit;//player.fruit;
								   player.MOVEMENT2(player, 3, 3);
								   while (true)
								   {
									   system("cls");
									   player.color(0xC);
								       player.MAP2();
								       player.SCORE2();
								       if (GetAsyncKeyState(VK_UP))
									   {
										   player.direction = player.UP;
									   }
								       else if (GetAsyncKeyState(VK_DOWN))
									   {
										   player.direction = player.DOWN;
									   }
								       else if (GetAsyncKeyState(VK_LEFT))
									   {
								    	   player.direction = player.LEFT;
									   }
								       else if (GetAsyncKeyState(VK_RIGHT))
									   {
								    	   player.direction = player.RIGHT;
									   }
								       switch (player.direction)
									   {
									   case UP:
										   {
											   player.MOVEMENT2(player, player.x-1, player.y);
										       break;
										   }
									   case DOWN:
										   {
											   player.MOVEMENT2(player, player.x+1, player.y);
											   break;
										   }
								       case LEFT:
										   {
											   player.MOVEMENT2(player, player.x, player.y-1);
											   break;
										   }
								       case RIGHT:
										   {
											   player.MOVEMENT2(player, player.x, player.y+1);
											   break;
										   }

									   }
								        Sleep(200);
										if(player.Score>=20)
										{
											player.color(0xC);
											cout<<endl<<endl<<"\t\t\tYour Score is: "<<player.Score<<"\t\t\t\t\t\t\t\t\t"<<endl;
											cout<<"\t\t\t!!WELL DONE!!"<<"\t\t\t\t\t\t\t\t\t"<<endl<<"\t\t\tGAME ENDED\t\t\t\t\t\t\t\t\t"<<endl;
											Sleep(500);
											system("pause");

										}
								   }
								   return 0;

						}


