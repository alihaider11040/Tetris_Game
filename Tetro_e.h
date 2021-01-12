#pragma once
#include "Peice.h"
/// <summary>
///  shape->      #
///           #   #   #
/// </summary>
class Tetro_e :
    public Peice
{
    int rotation;
public:
    Tetro_e() 
    {
        rotation = 0;

        /// <summary>
        /// sets standard size  0
        ///                 1   2   3  this shape presents rotation=0
        /// </summary>
        int x = 124, y = 31,x_ind=1,y_ind=4;
        Square* shape = Peice::get_Boxes();

        shape[0].set_x_pos(x);
        shape[0].set_y_pos(y);

        shape[0].set_x_index(x_ind);
        shape[0].set_y_index(y_ind);

        shape[2].set_x_pos(shape[0].get_x_pos());
        shape[2].set_y_pos(shape[0].get_y_pos()+31);


        shape[2].set_x_index(shape[0].get_x_index()+1);
        shape[2].set_y_index(shape[0].get_y_index());

        shape[1].set_x_pos(shape[2].get_x_pos() - 31);
        shape[1].set_y_pos(shape[2].get_y_pos());

        shape[1].set_x_index(shape[2].get_x_index());
        shape[1].set_y_index(shape[2].get_y_index()-1);

        shape[3].set_x_pos(shape[2].get_x_pos() + 31);
        shape[3].set_y_pos(shape[2].get_y_pos());

        shape[3].set_x_index(shape[2].get_x_index());
        shape[3].set_y_index(shape[2].get_y_index()+1);
        //here   #        ==         0
        //   #   #   #           1   2   3
    }

    void rotate() 
    {
        Square* shape = Peice::get_Boxes();

        if (rotation == 0) 
        {
            shape[3].set_x_pos(shape[2].get_x_pos());
            shape[3].set_y_pos(shape[2].get_y_pos() + 31);

            shape[3].set_x_index(shape[2].get_x_index()+1);
            shape[3].set_y_index(shape[2].get_y_index());

            /// <summary>
            ///      0
            ///  1   2
            ///      3    is shape after 1 rotation
            /// </summary>
            rotation = 1;
        }
        else
        {
            if (rotation == 1) 
            {
                shape[0].set_x_pos(shape[2].get_x_pos() + 31);
                shape[0].set_y_pos(shape[2].get_y_pos());
                

                shape[0].set_x_index(shape[2].get_x_index());
                shape[0].set_y_index(shape[2].get_y_index()+1);
                /// <summary>
                /// 1   2   0
                ///     3         shape after 2 rotations
                /// </summary>
                rotation = 2;
            }
            else
            {
                if (rotation == 2) 
                {
                
                    shape[1].set_x_pos(shape[2].get_x_pos());
                    shape[1].set_y_pos(shape[2].get_y_pos() - 31);

                    shape[1].set_x_index(shape[2].get_x_index()-1);
                    shape[1].set_y_index(shape[2].get_y_index());
                  
                    
                    /// <summary>
                    ///     1
                    ///     2   0
                    ///     3            shape after 3 rotation and next rotation will result standard rotation =0
                    /// </summary>
                    
                    rotation = 3;
                }
                else
                {
                    if (rotation == 3) 
                    {
                        shape[3].set_x_pos(shape[0].get_x_pos());
                        shape[3].set_y_pos(shape[0].get_y_pos());

                        shape[3].set_x_index(shape[0].get_x_index());
                        shape[3].set_y_index(shape[0].get_y_index());

                        shape[0].set_x_pos(shape[1].get_x_pos());
                        shape[0].set_y_pos(shape[1].get_y_pos());

                        shape[0].set_x_index(shape[1].get_x_index());
                        shape[0].set_y_index(shape[1].get_y_index());

                        shape[1].set_x_pos(shape[2].get_x_pos() - 31);
                        shape[1].set_y_pos(shape[2].get_y_pos());

                        shape[1].set_x_index(shape[2].get_x_index());
                        shape[1].set_y_index(shape[2].get_y_index()-1);
                        /// <summary>
                        ///     0
                        /// 1   2   3
                        /// </summary>
                        rotation = 0;
                    }
                }
            }
        }
    
    }

    void reset_Cordinates() 
    {
        rotation = 0;

        /// <summary>
        /// sets standard size  0
        ///                 1   2   3  this shape presents rotation=0
        /// </summary>
        int x = 124, y = 31, x_ind = 1, y_ind = 4;
        Square* shape = Peice::get_Boxes();

        shape[0].set_x_pos(x);
        shape[0].set_y_pos(y);

        shape[0].set_x_index(x_ind);
        shape[0].set_y_index(y_ind);

        shape[2].set_x_pos(shape[0].get_x_pos());
        shape[2].set_y_pos(shape[0].get_y_pos() + 31);


        shape[2].set_x_index(shape[0].get_x_index() + 1);
        shape[2].set_y_index(shape[0].get_y_index());

        shape[1].set_x_pos(shape[2].get_x_pos() - 31);
        shape[1].set_y_pos(shape[2].get_y_pos());

        shape[1].set_x_index(shape[2].get_x_index());
        shape[1].set_y_index(shape[2].get_y_index() - 1);

        shape[3].set_x_pos(shape[2].get_x_pos() + 31);
        shape[3].set_y_pos(shape[2].get_y_pos());

        shape[3].set_x_index(shape[2].get_x_index());
        shape[3].set_y_index(shape[2].get_y_index() + 1);
        //here   #        ==         0
        //   #   #   #           1   2   3
    }

};

