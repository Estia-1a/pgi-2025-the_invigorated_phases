#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension (char *source_path){
    int width,height,channel_count;
    unsigned char* data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("dimension: %d,%d",width,height);
}

void first_pixel (char *source_path){
    int width,height,channel_count;
    unsigned char* data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("first_pixel: %d, %d, %d",data[0],data[1],data[2]);
}

void tenth_pixel (char *source_path){
    int width,height,channel_count;
    unsigned char* data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("tenth_pixel: %d, %d, %d",data[27],data[28],data[29]);
}
void second_line(char *source_path){
    int width, height, channel_count;
    unsigned char* data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("second ligne : %d, %d, %d",data[channel_count * width],data[channel_count * width +1],data[channel_count * width +2]);
}

void print_pixel( char *filename, int x, int y ) {
    pixelRGB* pixel;
    unsigned char* data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    pixel = get_pixel(data, width, height, channel_count, x, y );
    printf("print_pixel (%d, %d): %d, %d, %d", x, y, pixel->R, pixel->G, pixel->B);
}
void max_pixel(char *filename){
    pixelRGB* pixel;
    pixelRGB* res_pixel;
    unsigned char* data;
    int width, height, channel_count;
    int i,j,p,res=0, x, y;
    read_image_data(filename, &data, &width, &height, &channel_count);
    res_pixel=get_pixel(data, width, height, channel_count, 0, 0);
    for (i=0;i<width;i++){
        for (j=0;j<height;j++){
            pixel = get_pixel(data, width, height, channel_count, i, j);
            p=(pixel->R)+(pixel->G)+(pixel->B);
            if (p>res){
                res=p;
                x=i;
                y=j;
                res_pixel=pixel;
            }
        }
    }
    printf("max_pixel (%d, %d): %d, %d, %d", x, y, res_pixel->R, res_pixel->G, res_pixel->B);
}
