#include<iostream>
#include <windows.h>
#include<Time.h>
#include<stdlib.h>
using namespace std;
#ifndef PLAYER_H_
#define PLAYER_H_
class Player
{
public:
	int level2();
	int x,y;
	 char BLANK;
			 char PAC_MAN;
			 char FOOD;
			 int MAP_ROWS;
			 int MAP_COLUMNS;
			 int LEFT;
			 int RIGHT;
			 int UP;
			 int DOWN;
			int direction;
			int Score;
			 char bhou;
			 char fruit;
			char tempmap[1000];
			char arr[1000];
			int w,q,a,b,z;
			int qa,az;
			char map[27][100] =
									{

										        						       "==============================================================================",
										        							   "==============================================================================",
										        							   "||  o             oo           oo    || oo          oo           oo          ||",
										        						       "||            oo         oo          ||      oo          oo                  ||",
										        							   "||             ======================||======================                ||",
										        							   "||                                 oo||oo                                    ||",
										        						       "||                                 oo||oo                                    ||",
										        							   "||============                ooooooo||ooooooo                  =============||",
										        							   "||          ||        ||      ================      ||          ||           ||",
										        							   "||          ||        ||            oooo            ||          ||           ||",
										        							   "||          ||        ||          oo    oo          ||          ||           ||",
										        							   "||          ||        ||       oo    ||    oo       ||          ||           ||",
										        						       "||                    ||    oo       ||      oo     ||                       ||",
										        						       "||======              ||       oo    ||    oo       ||                =======||",
										        							   "||                    ||          oo    oo          ||                       ||",
										        						       "||          ||        ||            oooo            ||          ||           ||",
										        							   "||          ||        ||      ================      ||          ||           ||",
										        							   "||          ||                       ||                         ||           ||",
										        							   "||          ||            oo         ||       oo                ||           ||",
										        							   "||============                       ||                         =============||",
										        							   "||                                   ||                                      ||",
										        							   "||             ==============================================                ||",
										        							   "||        oo                oo       ||      oo               oo             ||",
										        							   "||oo              oo                 ||             oo                     oo||",
										        							   "=============================================================================",

									};
			char map2[27][100] =
																		{

																			        						       "==============================================================================",
																			        							   "==============================================================================",
																			        							   "||                ||             oo   || oo                  ||              ||",
																			        						       "||                ||                  ||                     ||              ||",
																			        							   "||                ||       oo         ||        oo           ||              ||",
																			        							   "||                ||                  ||                     ||              ||",
																			        						       "||                oo    oo            ||               oo    oo              ||",
																			        							   "||                oo         =====================           oo              ||",
																			        							   "||=========       oo         ||                 ||           oo     =========||",
																			        							   "||                           ||    o        o   ||                           ||",
																			        							   "||   oo        =========     ||                 ||     =========        oo   ||",
																			        							   "||             ||                     ||                      ||             ||",
																			        						       "||      =======||  oo                 ||                  oo  ||=======      ||",
																			        						       "||             ||                                             ||             ||",
																			        							   "||   oo        =========     || ==============  ||     =========        oo   ||",
																			        						       "||                           ||                 ||                           ||",
																			        							   "||=========                  ||                 ||                  =========||",
																			        							   "||             oo            =====================           oo              ||",
																			        							   "||                                    ||                                     ||",
																			        							   "||                                    ||                                     ||",
																			        							   "||                ||                  ||                     ||              ||",
																			        							   "||                ||                  ||                     ||              ||",
																			        							   "||        oo      ||          oo      ||       oo            || oo           ||",
																			        							   "||oo              ||oo                ||              oo     ||             o||",
																			        							   "=============================================================================",

																		};



	Player();
	virtual ~Player()
	{

	}

	bool RIGHT_POSITION(int x, int y)

		{
		    return (x >= 0 && x < MAP_ROWS && y >= 0 && y < MAP_COLUMNS);
		}

		bool MOVEMENT(Player &player, int x, int y)
		{

		    if (!RIGHT_POSITION(x, y))
		    {

		    			 enemy();
		    			    randam();
		        return false;
		    }
		    else if(map[x][y] != BLANK)
		    {
		    	enemy();
		    	randam();
		        return false;
		    }

		    else if (RIGHT_POSITION(player.x, player.y))
		    {
				if(map[x][y+1]==FOOD)
				{

				    map[x][y+1] = BLANK;
				    Score++;
				}
				else if(map[x][y-1]==FOOD)
				{
					map[x][y-1] = BLANK;
				    Score++;
				}
				else if(map[x+1][y]==FOOD)
				{
				    map[x+1][y] = BLANK;
				    Score++;
				}
				else if(map[x-1][y]==FOOD)
				{
				    map[x-1][y] = BLANK;
				    Score++;
				}
				if(map[x][y+1]==fruit)
								{

								    map[x][y+1] = BLANK;
								    Score=Score+3;
								}
				else if(map[x][y-1]==fruit)
								{
								    map[x][y-1] = BLANK;
								    Score=Score+3;
								}
				else if(map[x+1][y]==fruit)
								{
								    map[x+1][y] = BLANK;
								    Score=Score+3;
								}
				else if(map[x-1][y]==fruit)
								{
								    map[x-1][y] = BLANK;
								    Score=Score+3;
								}
		           map[player.x][player.y] = BLANK;
		           randam();
		    player.x = x; player.y = y;



		    map[x][y] = PAC_MAN;
		    enemy();
		    }


		    return true;
		}
		void MAP()
		{


		    for (int x = 0; x < MAP_ROWS; x++)
		    {

						        cout << map[x]<< endl;
		    }
		    if(GetAsyncKeyState(VK_SHIFT))
		    {
		    	system("pause");
		    }
		}

	void SCORE ()
	{
		cout<<endl<<endl<<"\t\t\t\t SCORE:"<<Score<<endl;
	}
	void color(int a)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
		}
	void faisal(int u)
	{
		char arr[35][80]=
			{
                    "                                                                       ",
					"                                                                       ",
					"!!!!!!!!!!!!!          @@@@@@@@@@@@@@@@@@@        &&&&&&&&&&&&&&&&&&&& ",
					"!!!*********!!         $$@@@@@@@@@@@@@@@@@        &&&&&&&&&&&&&&&&    ",
					"!!!         !!!        $$@@@@@@@@@@@@@@@$$        &&&&&&&&&&&&&&      ",
					"!!!         !!!!       $$               $$        &&&&&&&&&&          ",
					"!!!         !!!!!      $$               $$        &&&&&&&             ",
					"!!!         !!!!       $$               $$        &&&&&               ",
					"!!!         !!!        $$               $$        &&&&                ",
					"!!!         !!         $$               $$        &&&&                ",
					"!!!!!!!!!!!!!!         $$@@@@@@@@@@@@@@@$$        &&&&                ",
					"!!!                    $$               $$        &&&&&               ",
					"!!!                    $$               $$        &&&&&&               ",
					"!!!                    $$               $$        &&&&&&&&            ",
					"!!!                    $$               $$        &&&&&&&&&&&         ",
					"!!!                    $$               $$        &&&&&&&&&&&&&&       ",
					"!!!                    $$               $$        &&&&&&&&&&&&&&&&&&&&",
					"                                                                      ",
					"                                                                      ",
					"                                                                      ",
					"                                                                      ",
					"MMMMMMMMMMMMMMMMMMMMMMMM     @@@@@@@@@@@@@@@@@@    +++++           ++ ",
					"XX MMMMMMMMMMMMMMMMMMMXX     $$@@@@@@@@@@@@@@$$    +++ ++          ++ ",
					"XX  MMMMMMMMMMMMMMMM  XX     $$ @@@@@@@@@@@@ $$    +++  ++         ++ ",
					"XX    MMMMMMMMMMMM    XX     $$  @@@@@@@@@@  $$    +++   ++        ++ ",
					"XX      MMMMMMMM      XX     $$    @@@@@@    $$    +++    ++       ++ ",
					"XX        @@@@        XX     $$     @@@@     $$    +++     ++      ++ ",
					"XX                    XX     $$@@@@@@@@@@@@@@$$    +++      ++     ++ ",
					"XX                    XX     $$              $$    +++       ++    ++ ",
					"XX                    XX     $$              $$    +++        ++   ++ ",
					"XX                    XX     $$              $$    +++         ++  ++ ",
					"XX                    XX     $$              $$    +++          ++ ++ ",
					"XX                    XX     $$              $$    +++           ++++ ",

			};

		for(int i=0;i<35;i++)
		{
			cout<<"    "<<arr[i]<<endl;
		}
		}

	void randam()
	{
		//srand(time(NULL));
		//qa=rand()%20+1;
		//az=rand()%50+1;
		  if(map[qa][az]==map[x][y])
				   		    {
				   		    	srand(time(NULL));
				   		    	qa=rand()%20+1;
				   		    	az=rand()%50+1;
				   		    	if(map[qa][az]==FOOD)
				   		    	{
				   		    		qa=rand()%20+1;
				   		    		az=rand()%50+1;
				   		    		map[qa][az]=fruit;
				   		    	}
				   		    	if(map[qa][az]=='|' || map[qa][az]=='=' )
				   		    	{
				   		    		qa=rand()%20+1;
				   		    		az=rand()%50+1;
				   		    		map[qa][az]=fruit;
				   		    	}
				   		    	if(qa>20 || az>70)
				   		    	{
				   		    		qa=rand()%20+1;
				   		     		az=rand()%50+1;
			    		    		map[qa][az]=fruit;
				   		    	}
				   		    	map[qa][az]=fruit;

				   		    }

		 	}
	void enemy()
	{
		q++,w++;
				    arr[q]=x;
				    tempmap[w]=y;
				    if(Score>=3)
				    {
				    	              map[a][b]=BLANK;
				    		    		z++;
				    		    		a=arr[z-1];
				    		    		b=tempmap[z-1];
				    		    		map[a][b]=bhou;
				    		    		if(x==a && y==b)
				    		    				   	 {
				    		    			cout<<endl<<"\t\t\t  "<<"YOUR SCORE IS:"<<Score<<endl;
				    		    			cout<<"\t\t\t YOU LOSE "<<endl;
				    		    			 system("pause");
				    		    				   	 }
	}
	}


//****************************************************************************************//
//****************************************************************************************//
		bool RIGHT_POSITION2(int x, int y)

				{
				    return (x >= 0 && x < MAP_ROWS && y >= 0 && y < MAP_COLUMNS);
				}

				bool MOVEMENT2(Player &player, int x, int y)
				{

				    if (!RIGHT_POSITION(x, y))
				    {

				    			 enemy2();
				    			    randam2();
				        return false;
				    }
				    else if(map2[x][y] != BLANK)
				    {
				    	enemy2();
				    	randam2();
				        return false;
				    }

				    else if (RIGHT_POSITION(player.x, player.y))
				    {
						if(map2[x][y+1]==FOOD)
						{

						    map2[x][y+1] = BLANK;
						    Score++;
						}
						else if(map2[x][y-1]==FOOD)
						{
							map2[x][y-1] = BLANK;
						    Score++;
						}
						else if(map2[x+1][y]==FOOD)
						{
						    map2[x+1][y] = BLANK;
						    Score++;
						}
						else if(map2[x-1][y]==FOOD)
						{
						    map2[x-1][y] = BLANK;
						    Score++;
						}
						if(map2[x][y+1]==fruit)
										{

										    map2[x][y+1] = BLANK;
										    Score=Score+3;
										}
						else if(map2[x][y-1]==fruit)
										{
										    map2[x][y-1] = BLANK;
										    Score=Score+3;
										}
						else if(map2[x+1][y]==fruit)
										{
										    map2[x+1][y] = BLANK;
										    Score=Score+3;
										}
						else if(map2[x-1][y]==fruit)
										{
										    map2[x-1][y] = BLANK;
										    Score=Score+3;
										}
				           map2[player.x][player.y] = BLANK;
				           randam2();
				    player.x = x; player.y = y;



				    map2[x][y] = PAC_MAN;
				    enemy2();
				    }


				    return true;
				}
				void MAP2()
				{


				    for (int x = 0; x < MAP_ROWS; x++)
				    {

								        cout << map2[x]<< endl;
				    }
				}

			void SCORE2 ()
			{
				cout<<endl<<"\t\t\t\t SCORE:"<<Score<<endl;
			}
			void randam2()
				{
					  if(map2[qa][az]==map2[x][y])
							   		    {
							   		    	srand(time(NULL));
							   		    	qa=rand()%20+1;
							   		    	az=rand()%50+1;
							   		    	if(map2[qa][az]==FOOD)
							   		    	{
							   		    		qa=rand()%20+1;
							   		    		az=rand()%50+1;
							   		    		map2[qa][az]=fruit;
							   		    	}
							   		    	if(map2[qa][az]=='|' || map2[qa][az]=='=' )
							   		    	{
							   		    		qa=rand()%20+1;
							   		    		az=rand()%50+1;
							   		    		map2[qa][az]=fruit;
							   		    	}
							   		    	if(qa>20 || az>70)
							   		    	{
							   		    		qa=rand()%20+1;
							   		     		az=rand()%50+1;
						    		    		map2[qa][az]=fruit;
							   		    	}
							   		    	map2[qa][az]=fruit;

							   		    }

					 	}
				void enemy2()
				{
					q++,w++;
							    arr[q]=x;
							    tempmap[w]=y;
							    if(Score>=3)
							    {
							    	              map2[a][b]=BLANK;
							    		    		z++;
							    		    		a=arr[z-1];
							    		    		b=tempmap[z-1];
							    		    		map2[a][b]=bhou;
							    		    		if(x==a && y==b)
							    		    				   	 {
							    		    			cout<<"\t\t\t YOUR SCORE IS:"<<Score<<endl;
							    		    			cout<<"\t\t\t YOU LOSE "<<endl;
							    		    			 system("pause");
							    		    				   	 }
				}
				}

};

#endif /* PLAYER_H_ */
