#pragma once
#include"Peice.h"
#include"Square.h"

//# # # #-> shape == 0  1  2  3
class Tetro_a :public Peice {

	int rotaions;
public:
	Tetro_a() {
		int x = 124, y = 31;
		Square* shape = Peice::get_Boxes();
		//sets standard shape
		//# # # #-> shape == 0  1  2  3
		for (int i = 0,y_ind=4; i < 4; i++,y_ind++){
			shape[i].set_x_pos(x);
			shape[i].set_y_pos(y);
			
			shape[i].set_x_index(1);
			shape[i].set_y_index(y_ind);
			
			x += 31;
		}
		rotaions = 0;
	}
	//rotation
	void rotate() 
	{
		//shape will be equal to 4 square array
		Square* shape = Peice::get_Boxes();
		//Rotation=0 means current shape is # # # #
		//In that case as i starts from 1 box 1 will be below box 0
		//then same goes for box 2 and then box 3
		//after that shape will be
		//#
		//#
		//#
		//#
		//and this shape is 1 roatation ==1 means current shape is vertical
		if (rotaions == 0) 
		{
			for (int i = 1; i < 4; i++)
			{
				shape[i].set_x_pos(shape[i-1].get_x_pos());
				shape[i].set_y_pos(shape[i - 1].get_y_pos() + 31);
				
				shape[i].set_y_index(shape[i - 1].get_y_index());
				shape[i].set_x_index(shape[i-1].get_x_index()+1);
			}
			rotaions = 1;

		}
		else
		{
			/// <summary>
			/// Here else will run if current shape is vertical line
			/// vertical line will be shifted into horizontal line
			/// </summary>
			for (int i = 1; i < 4; i++)
			{
				shape[i].set_x_pos(shape[i-1].get_x_pos() + 31);
				shape[i].set_y_pos(shape[i - 1].get_y_pos());

				shape[i].set_x_index(shape[i - 1].get_x_index());
				shape[i].set_y_index(shape[i - 1].get_y_index() + 1);
			}
			rotaions = 0;//again making rotation=0 means current shape now is horizontal line i.e. ####

		}
	}
	//standard shape conversion
	void reset_Cordinates() 
	{
		//Resets the shape to standard shape
		//# # # #-> shape == 0  1  2  3
		//irrespective of rotation
		{
			int x = 124, y = 31;
			Square* shape = Peice::get_Boxes();

			for (int i = 0, y_ind = 4; i < 4; i++, y_ind++)
			{
				shape[i].set_x_pos(x);
				shape[i].set_y_pos(y);

				shape[i].set_x_index(1);
				shape[i].set_y_index(y_ind);

				x += 31;
			}
			rotaions = 0;
		}
	}

};

