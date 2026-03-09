#include <iostream>

int main()
{
    int row = 256;
    int col = 256;

    std::cout << "P3\n" << col << " " << row << "\n" << "255\n"; 
    
    for(int x = 0; x < row; x++)
    {
        for(int i = 0; i < col; i ++)
        {
            std::cout << i << " " << x << " 0\n";
        }
    }
    
    return 0;
}

/*

  P3
  <width> <height>
  <max_color_value>
  <r> <g> <b>
  <r> <g> <b>
  ...one pixel per line, left-to-right, top-to-bottom


  Your task: Write a program that outputs a 256x256 image where:
  - The red channel increases left to right (based on column position)
  - The green channel increases top to bottom (based on row position)
  - Blue is always 0



  */