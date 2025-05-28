#include <estia-image.h>

#include <stdio.h>
#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ) {
    int place;
 
    if ((x>=width)||(y>=height)) {
        return NULL;
    }
    if (data==NULL) {
        return NULL;
    }
    place = y*width*n + n*x;
    return (pixelRGB*) &data[place];
}