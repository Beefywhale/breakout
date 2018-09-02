#pragma once

namespace bt {
    // Class: Color
    // A class for RGB colors.
    class Color {
        public:
            // Group: Functions

            // Constructor: Color
            // Default constructor.
            Color() {}

            /* Constructor: Color
               Init a Color with three values of color (rgb).

               Parameters:
                  r - int ranging from 0 to 255.
                  g - int ranging from 0 to 255.
                  b - int ranging from 0 to 255.
            */
            Color(int r, int g, int b);
           
            // Variable: red
            // the amount of red color as an int ranging from 0-255.
            int red;

            // Variable: green
            // the amount of green color as an int ranging from 0-255.
            int green;

            // Variable: blue
            // the amount of blue color as an int ranging from 0-255.
            int blue;
    };
}
