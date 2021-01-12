#pragma once
#include "Peice.h"
/// <summary>
/// shape-> # #      ==    0  1
///           # #             2   3
/// </summary>
class Tetro_d :
    public Peice
{
    int rotation;
public:
    Tetro_d() 
    {
        int x = 124, y = 31;
        int x_ind = 1, y_ind = 4;
        Square* shape = Peice::get_Boxes();
        rotation = 0;

        /// shape-> # #      ==    0  1
        ///           # #             2   3    standard with 0 rotation

        shape[0].set_x_pos(x);
        shape[0].set_y_pos(y);

        shape[0].set_x_index(x_ind);
        shape[0].set_y_index(y_ind);

        shape[1].set_x_pos(shape[0].get_x_pos() + 31);
        shape[1].set_y_pos(shape[0].get_y_pos());

        shape[1].set_x_index(shape[0].get_x_index());
        shape[1].set_y_index(shape[0].get_y_index()+1);

        shape[2].set_x_pos(shape[1].get_x_pos());
        shape[2].set_y_pos(shape[1].get_y_pos() + 31);

        shape[2].set_x_index(shape[1].get_x_index()+1);
        shape[2].set_y_index(shape[1].get_y_index());

        shape[3].set_x_pos(shape[2].get_x_pos() + 31);
        shape[3].set_y_pos(shape[2].get_y_pos());

        shape[3].set_x_index(shape[2].get_x_index());
        shape[3].set_y_index(shape[2].get_y_index()+1);
    }

    void rotate() 
    {
        Square* shape = Peice::get_Boxes();
        if (rotation == 0) 
        {
           
            shape[2].set_x_pos(shape[0].get_x_pos());
            shape[3].set_x_pos(shape[1].get_x_pos());
            shape[3].set_y_pos(shape[1].get_y_pos()-31);

            shape[2].set_y_index(shape[0].get_y_index());
            
            shape[3].set_x_index(shape[1].get_x_index() - 1);
            shape[3].set_y_index(shape[1].get_y_index());
            

          
            /// <summary>
            ///        #           3
            ///     #  # ==     0  1
            ///     #           2
            /// Next rotation will be standard shape
            /// </summary>
            
            rotation = 1;

        }
        else
        {
            shape[2].set_x_pos(shape[1].get_x_pos());
            shape[3].set_x_pos(shape[2].get_x_pos() + 31);
            shape[3].set_y_pos(shape[2].get_y_pos());

            shape[2].set_y_index(shape[1].get_y_index());
           
            shape[3].set_x_index(shape[2].get_x_index());
            shape[3].set_y_index(shape[2].get_y_index()+1);


            /// shape-> # #      ==    0  1
            ///           # #             2   3    standard with 0 rotation
            /// next rotation will be rotation ==1
            rotation = 0;
        }
    
    }
   
    void reset_Cordinates() 
    {
        int x = 124, y = 31;
        int x_ind = 1, y_ind = 4;
        Square* shape = Peice::get_Boxes();
        rotation = 0;

        /// shape-> # #      ==    0  1
        ///           # #             2   3    standard with 0 rotation

        shape[0].set_x_pos(x);
        shape[0].set_y_pos(y);

        shape[0].set_x_index(x_ind);
        shape[0].set_y_index(y_ind);

        shape[1].set_x_pos(shape[0].get_x_pos() + 31);
        shape[1].set_y_pos(shape[0].get_y_pos());

        shape[1].set_x_index(shape[0].get_x_index());
        shape[1].set_y_index(shape[0].get_y_index() + 1);

        shape[2].set_x_pos(shape[1].get_x_pos());
        shape[2].set_y_pos(shape[1].get_y_pos() + 31);

        shape[2].set_x_index(shape[1].get_x_index() + 1);
        shape[2].set_y_index(shape[1].get_y_index());

        shape[3].set_x_pos(shape[2].get_x_pos() + 31);
        shape[3].set_y_pos(shape[2].get_y_pos());

        shape[3].set_x_index(shape[2].get_x_index());
        shape[3].set_y_index(shape[2].get_y_index() + 1);
    }

};

