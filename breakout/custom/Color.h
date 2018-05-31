#pragma once

<<<<<<< HEAD
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
=======
namespace bt {
    class Color {
     public:
         Color() {}
        Color(int r, int g, int b);
        int red;
        int green;
        int blue;
>>>>>>> 5375c24c6621ab1bd5924cb6c2f41bbbdc64e7dc
    };
}

