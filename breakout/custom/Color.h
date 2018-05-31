#pragma once

/**
* @brief bt namespace.
*/
namespace bt {
    /**
    * @brief Color.
    */
    class Color {
        public:
           /**
            * Default constructor for Color.
            */
            Color() {}
           
           /**
            * Create a new Color with rgb colors.
            * @param r Red color ranging from 0 to 255.
            * @param g Green color ranging from 0 to 255.
            * @param b Blue color ranging from 0 to 255.
            */
            Color(int r, int g, int b);
           
            int red;
            int green;
            int blue;
    };
}

