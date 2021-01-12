#pragma once
class Square
{
	//Size specifiers//
	int width;
	int length;
	//Cordinate Specifier//
	int x_pos;
	int y_pos;
	//2D index Specifier//
	int x_index;
	int y_index;
public:
	Square() 
	{
		//Default values pixel wise
		width = 30;
		length = 30;
		x_pos = 0;
		y_pos = 0;
		x_index = 0;
		y_index = 0;
	}

	Square(int x, int y) 
	{
		x_pos = 0;
		y_pos = 0;
	}

	    //Setters//
	void set_x_pos(int a) 
	{
		x_pos = a;
	}
	void set_y_pos(int a) 
	{
		y_pos = a;
	}
	void set_x_index(int x)
	{
		x_index = x;
	}
	void set_y_index(int x)
	{
		y_index = x;
	}
	
	//Getters//
	int get_x_pos() 
	{
		return x_pos;
	}
	int get_y_pos() 
	{
		return y_pos;
	}
	int get_x_index() 
	{
		return x_index;
	}
	int get_y_index() 
	{
		return y_index;
	}
//Operator to copy (Usage in displaying next tetromine )
	void operator =(Square& obj) {

		width = obj.width;
		length= obj.length;
		x_pos = obj.x_pos;
		y_pos = obj.y_pos;
		x_index = obj.x_index;
		y_index = obj.y_index;
	}
};

