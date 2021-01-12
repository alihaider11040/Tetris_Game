#include<SFML/Graphics.hpp>
////////////////////////////////////////////////Tetromine_Libraries/////////////////////////////////////////////////
#include"Tetro_a.h"
#include"Tetro_b.h"
#include"Tetro_c.h"
#include"Tetro_d.h"
#include"Tetro_e.h"
#include"Tetro_f.h"
#include"Tetro_g.h"
#include"Peice.h"
////////////////////////////////////////////////Tetris_Board ////////////////////////////////////////////////////////
#include"Tetris_Board.h"
////////////////////////////////////////////////Other////////////////////////////////////////////////////////
#include<cstdlib>//for delay
#include <string>//for integer to string conversion in score and time printing
#include<ctime>  //Time maintainance
#include<Windows.h>//For Sleep function
#include<iostream>
using namespace std;

////////////////////////////////////////////////Functions ////////////////////////////////////////////////////////

										//Fuctions_OF_tetromines//
//load_Pices loads seven type of Tetromines in one pointer
void load_Peices(Peice**& list_Of_Peices) 
{
	list_Of_Peices = new Peice * [7];
	//at each index we have different type of Peice
	list_Of_Peices[0] = new Tetro_a;
	list_Of_Peices[1] = new Tetro_b;
	list_Of_Peices[2] = new Tetro_c;
	list_Of_Peices[3] = new Tetro_d;
	list_Of_Peices[4] = new Tetro_e;
	list_Of_Peices[5] = new Tetro_f;
	list_Of_Peices[6] = new Tetro_g;
}
//select_Random_Peice radomly select value from 0 to 6 to be selected as index of 
//list_of_tetromine to be used
void select_Random_Peice(int& peice_num) 
{
	srand((unsigned)time(0));
	//built-in by cstdlib
	peice_num = rand() % 7;
}

////////////////////////////////////////////////Start/End_Page_Printing//////////////////////////////////////////

void display_Starting() 
{
	sf::RenderWindow window1(sf::VideoMode(695, 475), "Welcome_To_Tetris"); // Starting logo

	sf::Texture logotexture;
	logotexture.loadFromFile("game logo.png");   //starting logo
	sf::Sprite logo(logotexture);
	logo.setPosition(0, 0);
	window1.draw(logo);
	window1.display();
	Sleep(3000);
	window1.close();

}
void display_Ending() 
{
	sf::Texture logotexture_end;
	logotexture_end.loadFromFile("end game logo.png");   //ending logo
	sf::Sprite logo_end(logotexture_end);
	logo_end.setPosition(0, 0);
	sf::RenderWindow win(sf::VideoMode(630, 395), "Ending_Tetris ");   // this 600,600 is the dimension of MY MINDOW//
	win.draw(logo_end);
	win.display();
	Sleep(2500);
	win.close();
}

int main()
{

	/////////////////////////////////////////////////Data_Deleration/////////////////////////////////////////////////

	////////////////////////////////////////////////Classes_Objects//////////////////////////////////////////////////
	Tetris_Board Game;//Tetris_Board object will have Score count and board covered and empty positions
	//along with border index of board
	Peice** list_Of_Tetromines;//list of 7 Peices
	Peice next_shape;//This will save next Peice

	////////////////////////////////////////////////Integer_Type_Data//////////////////////////////////////////////////

	int tetromine_Number = 0;//Tetromine to be selected randomly
	int next_Tetromine_Number = 0;//Next tetromine to be selected
	int score = Game.get_Score();//Here we separate Board and Score into global variables
	int m = 0;//This will stores the minutes of Gameplay
	int s = 0;//This will stores seconds of Gameplay
	int execution_Speed = 0;//This Controls the Game_Running speed i.e slow/Fast the movement of tetromines 
	int execution_Limiter = 5;//Limits the speed Up and speed down
	int** board = Game.get_Board();//board is tetris board

	////////////////////////////////////////////////Bool_Type_Data//////////////////////////////////////////////////

	bool Peice_selected = true;//Either the Peice is Moving inside the board or setteled

	////////////////////////////////////////////////SFML_Graphics_Type_Data//////////////////////////////////////////

	//Class_Type_Graphics//
	sf::Clock clock;//Maintains clock of Program execution
	sf::Time time;  // To print time in Graphics window

	//Text-Type_Grapgics//
	sf::Text seconds;// Text for header printing of seconds
	sf::Text sec;    // Text for printing of seconds
	sf::Text minutes;// Text for header printing of minutes
	sf::Text min;    // Text for  printing of minutes

////////////////////////////////////////////////Game_Execution ////////////////////////////////////////////////////////

	display_Starting();

////////////////////////////////////////////////Getting ready ////////////////////////////////////////////////////////

	load_Peices(list_Of_Tetromines);//loads all 7 type of tetromines
	select_Random_Peice(tetromine_Number);//select first shape
	select_Random_Peice(next_Tetromine_Number);//selects 2nd shape
	next_shape = *list_Of_Tetromines[next_Tetromine_Number];//Here we copy next shape using assignment operator
	//so that standard tetromines remain unchanged

	// The fundamental difference between the  window and render window is just this that
	   //one is meant for simply creating a blank window for context-creation 
	   //and other is specifically for 2D rendering which
	   //you can’t use outside of SFML.
	sf::RenderWindow window(sf::VideoMode(800, 560), "TETRIS_GAME");   // this 600,600 is the dimension of MY MINDOW//
	//window.setFramerateLimit(30);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))   //this is for clear previous screen//
			if (event.type == sf::Event::Closed)
				window.close();
		if (Peice_selected == false) //Peice_selected will be false when a tetromine is settled on board
		{
			tetromine_Number = next_Tetromine_Number;//the next tetromine was already selected randomly
			//here we made next tetro thr current tetromine and update next
			select_Random_Peice(next_Tetromine_Number);
			next_shape = *list_Of_Tetromines[next_Tetromine_Number];
			Peice_selected = true;//as the tetromine is selected
		}

		//board_graph is Graphic display of board of Game
		sf::RectangleShape board_graph[18][12];
		//There x and y positions will only be used by border
		int x_position = 0;
		int y_position = 0;
		for (int i = 0; i < 18; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				///<summary>
				///board is a 2d[18][12] array ,the number presentation of Graphic interface
				/// there will be values 0 and 1 
				/// 1 means that a sqaure has to be printed that either its border or a i.e space is not free
				/// part of board
				if (board[i][j] == 1) 
				{
					board_graph[i][j].setSize(sf::Vector2f(30, 30));
					board_graph[i][j].setPosition(x_position, y_position);
					board_graph[i][j].setFillColor(sf::Color::Magenta);
					window.draw(board_graph[i][j]);
				}
				x_position += 31;
			}
			x_position = 0;
			y_position += 31;
		}
			//In shape sqaures we will have four square with the cordinates of selected tetromine
			Square* shape_Squares = list_Of_Tetromines[tetromine_Number]->get_Boxes();
			//From Here ///////////Graphical Display of Selected tetromine
			sf::RectangleShape shape[4];//Shape is the selected tetromine
			for (int i = 0; i < 4; i++)
			{
				shape[i].setSize(sf::Vector2f(30, 30));
				shape[i].setPosition(shape_Squares[i].get_x_pos(), shape_Squares[i].get_y_pos());
				shape[i].setFillColor(sf::Color::Green);
				window.draw(shape[i]);
			}

			//Next shape Printing
			sf::RectangleShape next_Shape_Graphics[4];//The next Shape to be printed
			Square* next_shape_Squares = next_shape.get_Boxes();
			for (int i = 0; i < 4; i++)
			{
				next_Shape_Graphics[i].setSize(sf::Vector2f(30, 30));
				next_Shape_Graphics[i].setPosition(next_shape_Squares[i].get_x_pos() + 420, next_shape_Squares[i].get_y_pos()+450);
				next_Shape_Graphics[i].setFillColor(sf::Color::Green);
				window.draw(next_Shape_Graphics[i]);
			}
////////////////////////////////////////////////Gameplay display ////////////////////////////////////////////////////////

			sf::Font font;
			if (font.loadFromFile("fresh.ttf")) {//fresh.ttf is font file for game play
											  //Game_paly heading//
				sf::Text head;
				head.setFont(font);
				head.setString("Tetris_GamePlay");
				head.setStyle(sf::Text::Italic | sf::Text::StrikeThrough);
				head.setFillColor(sf::Color::Red);
				head.setCharacterSize(65);
				head.setPosition(400, 0);
				window.draw(head);
										//Score_haeding and actual score//
				sf::Text text;
				sf::Text score; //for score
				text.setFont(font);
				text.setString("Score");//heading
				text.setCharacterSize(50);
				text.setStyle(sf::Text::Underlined);
				text.setFillColor(sf::Color::Red);
				text.setPosition(520, 60);
				window.draw(text);

				// Score_actual//
				score.setFont(font);
				score.setString(std::to_string(Game.get_Score()));
				score.setCharacterSize(50);
				score.setFillColor(sf::Color::Yellow);
				score.setPosition(550, 110);
				window.draw(score);

////////////////////////////////////////////////////Time///////////////////////////////////////////////////////////

				//Actual seconds// 
				seconds.setFont(font);
				seconds.setCharacterSize(50);
				seconds.setFillColor(sf::Color::Yellow);
				seconds.setPosition(500, 340);
				//Seconds heading//
				sec.setFont(font);
				sec.setString("Seconds");
				sec.setCharacterSize(50);
				sec.setStyle(sf::Text::Underlined);
				sec.setFillColor(sf::Color::Red);
				sec.setPosition(500, 280);
				//Actual minutes//
				minutes.setFont(font);
				minutes.setCharacterSize(50);
				minutes.setFillColor(sf::Color::Yellow);
				minutes.setPosition(550, 220);
				//minutes heading//
				min.setFont(font);
				min.setString("Minutes");
				min.setCharacterSize(50);
				min.setFillColor(sf::Color::Red);
				min.setStyle(sf::Text::Underlined);
				min.setPosition(500, 170);
				//Time Mangament
				time = clock.getElapsedTime();
				s = time.asSeconds();
				seconds.setString(std::to_string(time.asSeconds()));

				if (s == 60)
				{
					m++;
					clock.restart();
				}
				minutes.setString(std::to_string(m));
				window.draw(minutes);
				window.draw(seconds);
				window.draw(sec);
				window.draw(min);
////////////////////////////////////////////////////Next_shape_heading////////////////////////////////////////////////
				sf::Text text1;
				text1.setFont(font);
				text1.setString("Next_shape");
				text1.setStyle(sf::Text::Underlined);
				text1.setFillColor(sf::Color::Red);
				text1.setCharacterSize(50);
				text1.setPosition(next_shape_Squares[0].get_x_pos() + 370, next_shape_Squares[0].get_y_pos() + 370);
				window.draw(text1);
			}

////////////////////////////////////////////////////Tetromine_Movement inside Board//////////////////////////////////

				   if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //If the user is holding down the key "A"
				   {
				list_Of_Tetromines[tetromine_Number]->move_Left(board);
				   }
			else   if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //If the user is holding down the key "D"
				   {
					list_Of_Tetromines[tetromine_Number]->move_Right(board);
				   }
			else   if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //If the user is holding down the key "S"
					{
						list_Of_Tetromines[tetromine_Number]->move_Down();
					}
			else   if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //If the user is holding down the key "W"
						{
							list_Of_Tetromines[tetromine_Number]->rotate();
							Game.rotation_Validity(*list_Of_Tetromines[tetromine_Number]);
							//Check either rotation cause over lap on boder or not
						}
			else   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
				   {
					   window.close();
					   break;
				   }
	
					
//////////////////////////////////////////////////////////Border_Collision ANd Game over//////////////////////////  
			
			if (!Game.border_Collision(*list_Of_Tetromines[tetromine_Number]) && execution_Speed==execution_Limiter)
			{
				list_Of_Tetromines[tetromine_Number]->move_Down();
				execution_Speed = 0;
			}
			if (Game.border_Collision(*list_Of_Tetromines[tetromine_Number])) {
				//This portion will run when one peice touches the lower border or
				//Peice cant move any furthure
				Peice_selected = false;
				execution_Speed = 0;
				//Fill board check for  row filled by current tetromine 
				Game.fill_Board(*list_Of_Tetromines[tetromine_Number]);
				list_Of_Tetromines[tetromine_Number]->reset_Cordinates();
				//row filled mean a row is filled with peices this will give score to player
				Game.check_Row_filled();
			}
			if (Game.check_Game_Over()) {
			//Game will be over if there is no room for new tetromine
				//Graphics work for GameOver Display//
				sf::Font font;
				font.loadFromFile("fresh.ttf");
				sf::Text text;
				text.setFont(font);
				text.setString("Game_Over");
				text.setStyle(sf::Text::Italic | sf::Text::StrikeThrough | sf::Text::Underlined);
				text.setFillColor(sf::Color::Yellow);
				text.setCharacterSize(80);
				text.setLetterSpacing(2);
				text.setPosition(1, 212);
				window.draw(text);
				window.display();
				Sleep(5000);
				window.close();
			}
		
		window.display();
		Sleep(100);
		window.clear();
		execution_Speed++;
	}
	display_Ending();
	system("pause");
	return 0;
}

