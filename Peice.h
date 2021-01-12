#pragma once
#include "Square.h"
class Peice
{
	//Each tetromine has 4 sqaures
	Square* boxes;
public:
	Peice() 
	{
		boxes = new Square[4];
	}

	Square* get_Boxes() 
	{
		return boxes;
	}

	//Pure virtual as each Tetromine rotate accordingly(Polymorphism usage)
	virtual void rotate() 
	{
	
	}
	//Pure virtual as each tetrmine has its own standard shape (Polymorphism usage)
	virtual void reset_Cordinates()
	{
	
	}

	//////////////////////////////////////Movement of Tetromines///////////////////////////////////////////////////////////////
	
	void move_Left(int ** board) 
	{
		bool collision_Check = false;
		//movement will be done if there is room for movement on board 
		for (int i = 0; i < 4 && collision_Check==false; i++)
		{
			if (board[boxes[i].get_x_index()][boxes[i].get_y_index() - 1] == 1) 
			{
				collision_Check = true;
			}	
		}
		if (collision_Check == false)
		{
			for (int i = 0; i < 4; i++)
			{
				boxes[i].set_x_pos(boxes[i].get_x_pos() - 31);
				boxes[i].set_y_index(boxes[i].get_y_index() - 1);
			}
		}
	}
	void move_Right(int** board)
	{
		bool collision_Check = false;
		for (int i = 0; i < 4 && collision_Check == false; i++)
		{
			if (board[boxes[i].get_x_index()][boxes[i].get_y_index() + 1] == 1)
			{
				collision_Check = true;
			}
		}

		if (collision_Check == false)
		{
			for (int i = 0; i < 4; i++)
			{
				boxes[i].set_x_pos(boxes[i].get_x_pos() + 31);
				boxes[i].set_y_index(boxes[i].get_y_index() + 1);
			}
		}
	}
	void move_Down()
	{
		//Check for lower border collision is check_border_Collision(Peice& tetromine)
		//here we just simply move it downward
		for (int i = 0; i < 4; i++)
		{
			boxes[i].set_y_pos(boxes[i].get_y_pos() + 31);
			boxes[i].set_x_index(boxes[i].get_x_index() + 1);
		}
	} 

	//Operator assignment(Usage in displaying next Peice)
	void operator =(Peice& obj) 
	{
		for (int i = 0; i < 4; i++)
		{
			boxes[i] = obj.boxes[i];
		}
	}
	//Destructors//
	~Peice() 
	{
		if (boxes != nullptr)
			delete[] boxes;
	}
};

