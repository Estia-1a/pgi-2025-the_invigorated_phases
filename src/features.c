#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>



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
    printf("second_line: %d, %d, %d",data[channel_count * width],data[channel_count * width +1],data[channel_count * width +2]);
}

void print_pixel( char *filename, int x, int y ) {
    pixelRGB* pixel;
    unsigned char* data;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    pixel = get_pixel(data, width, height, channel_count, x, y );
    printf("print_pixel (%d, %d): %d, %d, %d", x, y, pixel->R, pixel->G, pixel->B);
}

void max_pixel(char *filename) {
    pixelRGB* pixel;
    pixelRGB res_pixel;
    unsigned char* data;
    int width, height, channel_count;
    int i, j, p, res=0, x=0, y=0;
    read_image_data(filename, &data, &width, &height, &channel_count);
    pixel = get_pixel(data, width, height, channel_count, 0, 0);
    res_pixel=*pixel;
    res=res_pixel.R+res_pixel.G+res_pixel.B;

    for (i=0; i<width; i++) {
        for (j=0; j<height; j++) {
            pixel=get_pixel(data, width, height, channel_count, i, j);
            p=pixel->R+pixel->G+pixel->B;
            if (p>res) {
                res=p;
                x=i;
                y=j;
                res_pixel=*pixel;
            }
        }
    }
    printf("max_pixel (%d, %d): %d, %d, %d\n", x, y, res_pixel.R, res_pixel.G, res_pixel.B);
}

void min_pixel(char *filename){
    pixelRGB* pixel;
    pixelRGB res_pixel;
    unsigned char* data;
    int width, height, channel_count;
    int i,j,p,res=765, x, y;
    read_image_data(filename, &data, &width, &height, &channel_count);
    res_pixel=*get_pixel(data, width, height, channel_count, 0, 0);
    for (i=0;i<width;i++){
        for (j=0;j<height;j++){
            pixel = get_pixel(data, width, height, channel_count, i, j);
            p=(pixel->R)+(pixel->G)+(pixel->B);
            if (p<res){
                res=p;
                x=i;
                y=j;
                res_pixel=*pixel;
            }
        }
    }
    printf("min_pixel (%d, %d): %d, %d, %d", x, y, res_pixel.R, res_pixel.G, res_pixel.B);
}

void min_component(char *filename, char X){
    pixelRGB* pixel;
    pixelRGB* res_pixel;
    unsigned char* data;
    int width, height, channel_count;
    int i,j,x=0,y=0;
    read_image_data(filename, &data, &width, &height, &channel_count);
    res_pixel=get_pixel(data, width, height, channel_count, 0, 0);
    for (i=0;i<width;i++){
        for (j=0;j<height;j++){
            pixel = get_pixel(data, width, height, channel_count, i, j);
            if (X=='R'){
                if (pixel->R < res_pixel->R){
                    x=i;
                    y=j;
                    res_pixel=pixel;
                }
            }
            if (X=='G'){
                if(pixel->G < res_pixel->G){
                    x=i;
                    y=j;
                    res_pixel=pixel;
                }
            }
            if (X=='B'){
                if(pixel->B < res_pixel->B){
                    x=i;
                    y=j;
                    res_pixel=pixel;
                    
                }
            }
            }
        }
if (X=='R'){
   printf("min_component R (%d,%d): %d",x,y,res_pixel->R);
}
if (X=='G'){
    printf("min_component G (%d,%d): %d",x,y,res_pixel->G);
}
if (X=='B'){
    printf("min_component B (%d,%d): %d",x,y,res_pixel->B);
}
}

void max_component(char *filename, char X){
    pixelRGB* pixel;
    pixelRGB* res_pixel;
    unsigned char* data;
    int width, height, channel_count;
    int i,j,x=0,y=0;
    read_image_data(filename, &data, &width, &height, &channel_count);
    res_pixel=get_pixel(data, width, height, channel_count, 0, 0);
    for (i=0;i<width;i++){
        for (j=0;j<height;j++){
            pixel = get_pixel(data, width, height, channel_count, i, j);
            if (X=='R'){
                if (pixel->R > res_pixel->R){
                    x=i;
                    y=j;
                    res_pixel=pixel;
                }
            }
            if (X=='G'){
                if(pixel->G > res_pixel->G){
                    x=i;
                    y=j;
                    res_pixel=pixel;
                }
            }
            if (X=='B'){
                if(pixel->B > res_pixel->B){
                    x=i;
                    y=j;
                    res_pixel=pixel;
                    
                }
            }
            }
        }
if (X=='R'){
   printf("max_component R (%d,%d): %d",x,y,res_pixel->R);
}
if (X=='G'){
    printf("max_component G (%d,%d): %d",x,y,res_pixel->G);
}
if (X=='B'){
    printf("max_component B (%d,%d): %d",x,y,res_pixel->B);
}
}

void stat_report(char *filename){
 
    FILE *f = fopen("AAAAAAAAAAAAAAH.txt", "w");
 
    int stdout_copy = dup(fileno(stdout));
    fflush(stdout);
    dup2(fileno(f), fileno(stdout));
 
    max_pixel(filename);
    printf("\n");
    min_pixel(filename);
    printf("\n");
 
    fflush(stdout);
    dup2(stdout_copy, fileno(stdout));
    close(stdout_copy);
    fclose(f);
}

void color_red(char *filename){
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int i;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int size;
    size = width*height*3;
    data2=malloc(size);
    for (i=0;i<size;i+=3){
        data2[i]= data[i];
        data2[i+1]=0;
        data2[i+2]=0;
    }
    write_image_data("image_out.bmp", data2, width, height);
}

void color_green(char *filename){
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int i;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int size;
    size = width*height*3;
    data2=malloc(size);
    for (i=0;i<size;i+=3){
        data2[i]= 0;
        data2[i+1]=data[i+1];
        data2[i+2]=0;
    }
    write_image_data("image_out.bmp", data2, width, height);
}

void color_blue(char *filename){
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int i;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int size;
    size = width*height*3;
    data2=malloc(size);
    for (i=0;i<size;i+=3){
        data2[i]= 0;
        data2[i+1]=0;
        data2[i+2]=data[i+2];
    }
    write_image_data("image_out.bmp", data2, width, height);
}

void color_gray(char *filename){
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int i;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int size;
    size = width*height*3;
    data2=malloc(size);
    for (i=0;i<size;i+=3){
        unsigned char value = (data[i]+data[i+1]+data[i+2])/3;
        data2[i]=value;
        data2[i+1]=value;
        data2[i+2]=value;
    }
    write_image_data("image_out.bmp", data2, width, height);
}

void color_invert(char *filename){
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int i;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int size;
    size = width*height*3;
    data2=malloc(size);
    for (i=0;i<size;i++){
        data2[i]=255-data[i];  
    }
    write_image_data("image_out.bmp", data2, width, height);
}

void rotate_cw(char *filename) {
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int x, y;
    int index1, index2, new_x, new_y;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int size = width * height * 3;
    data2 = malloc(size);
    for (y=0;y<height;y++) {
        for (x=0;x<width;x++){
            index1=y*width*3+3*x;
            new_x=height-1-y;
            new_y=x;
            index2=new_y*height*3+3*new_x;
            data2[index2]=data[index1];
            data2[index2+1]=data[index1+1];
            data2[index2+2]=data[index1+2];
        }
    }
    write_image_data("image_out.bmp", data2, height, width);
}

void rotate_acw(char *filename) {
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int x, y;
    int index1, index2, new_x, new_y;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int size = width * height * 3;
    data2 = malloc(size);
    for (y=0;y<height;y++) {
        for (x=0;x<width;x++){
            index1=y*width*3+3*x;
            new_x=y;
            new_y=width-1-x;
            index2=new_y*height*3+3*new_x;
            data2[index2]=data[index1];
            data2[index2+1]=data[index1+1];
            data2[index2+2]=data[index1+2];
        }
    }
    write_image_data("image_out.bmp", data2, height, width);
}

void mirror_horizontal(char *filename) {
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int x, y;
    int index1, index2, new_x;
    read_image_data(filename, &data, &width,
   
    &height, &channel_count);
    int size = width * height * 3;
    data2 = malloc(size);
    for (y=0;y<height;y++) {
        for (x=0;x<width;x++){
            index1=y*width*3+3*x;
            new_x=width-1-x;
            index2=y*width*3+3*new_x;
            data2[index2]=data[index1];
            data2[index2+1]=data[index1+1];
            data2[index2+2]=data[index1+2];
        }
    }
    write_image_data("image_out.bmp", data2, height, width);
}

void mirror_vertical(char *filename) {
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int x, y;
    int index1, index2, new_y;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int size = width * height * 3;
    data2 = malloc(size);
    for (y=0; y<height; y++) {
        for (x=0; x<width; x++) {
            index1= y*width*3+3*x;
            new_y =height-1-y;
            index2 =new_y*width*3+3*x;
            data2[index2]=data[index1];
            data2[index2+1]=data[index1+1];
            data2[index2+2]=data[index1+2];
        }
    }
    write_image_data("image_out.bmp", data2, width, height);
}

void mirror_total(char *filename) {
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int x, y;
    int index1, index2, new_x, new_y;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int size = width * height * 3;
    data2 = malloc(size);
    for (y=0; y<height; y++) {
        for (x=0; x<width; x++) {
            index1=y*width*3+3*x;
            new_x=width-1-x;
            new_y=height-1-y;
            index2=new_y*width*3+3*new_x;
            data2[index2]=data[index1];
            data2[index2+1]=data[index1+1];
            data2[index2+2]=data[index1+2];
        }
    }
    write_image_data("image_out.bmp", data2, width, height);
}