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
    int *width,*height,*channel_count;
    unsigned char* data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("dimension: %d,%d",width,height);
}

void first_pixel (char *source_path){
    int *width,*height,*channel_count;
    unsigned char* data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("first_pixel: %d, %d, %d",data[0],data[1],data[2]);
}

void tenth_pixel (char *source_path){
    int *width,*height,*channel_count;
    unsigned char* data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("tenth_pixel: %d, %d, %d",data[27],data[28],data[29]);
}
void second_line(char *source_path){
    int *width,*height,*channel_count;
    unsigned char* data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("second ligne : %d, %d, %d",data[4464],data[4465],data[4466]);
}

