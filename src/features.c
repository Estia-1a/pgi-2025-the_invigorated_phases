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

void color_gray_luminance(char *filename){
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int i;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int size;
    size = width*height*3;
    data2=malloc(size);
    for (i=0;i<size;i+=3) {
        unsigned char value=0.21*data[i]+0.72*data[i+1]+0.07*data[i+2];
        data2[i] = value;
        data2[i + 1] = value;
        data2[i + 2] = value;
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

void color_desaturate(char *filename) {
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    int i, R, G, B, min, max, new_val;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int size = width*height*3;
    data2 = malloc(size);
    for (i=0;i<size;i+=3) {
        R=data[i];
        G=data[i+1];
        B=data[i+2];
        min=R;
        if (G<min) {
            min=G;
        }
        if (B<min) {
            min=B;
        }
        max=R;
        if (G>max) {
            max=G;
        }
        if (B>max) {
            max=B;
        }
        new_val=(min+max)/2;
        data2[i]=new_val;
        data2[i+1]=new_val;
        data2[i+2]=new_val;
    }
    write_image_data("image_out.bmp", data2, width, height);
}

void scale_crop(char *filename, int center_x, int center_y, int new_width, int new_height) {
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    if (new_width>width) new_width=width;
    if (new_height>height) new_height=height;
    int x_start=center_x-new_width/2;
    int y_start=center_y-new_height/2;
    if (x_start<0) x_start=0;
    if (y_start<0) y_start=0;
    if (x_start+new_width>width) x_start=width-new_width;
    if (y_start+new_height>height) y_start=height-new_height;
    int size=new_width*new_height*channel_count;
    data2=malloc(size);
    int x, y;
    int index, index2;
 
    for (y=0; y<new_height; y++) {
        for (x=0; x<new_width; x++) {
            int src_x=x_start+x;
            int src_y=y_start+y;
 
            index=(src_y*width+src_x)*3;
            index2=(y*new_width+x)*3;
            data2[index2]=data[index];
            data2[index2+1]=data[index+1];
            data2[index2+2]=data[index+2];
        }
    }
    write_image_data("image_out.bmp", data2, new_width, new_height);
}

void scale_nearest(char *filename, float X){
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int width2, height2,size;
    width2 = width*X;
    height2 = height*X;
    size = width2*height2*channel_count;
    data2= malloc(size);
    int x1,y1,x2,y2,c;
    int index1,index2;
    for(y1=0;y1<height2;y1++){
        for(x1=0;x1<width2;x1++){
            x2=x1/X;
            y2=y1/X;

            if (x2>=width){
                x2=width-1;
            }
            if(y2>height){
                y2=height-1;
            }
            for (c=0;c<channel_count;c++){
                index1=(y2*width+x2)*channel_count+c;
                index2= (y1*width2+x1)*channel_count+c;
                data2[index2]=data[index1];
        }
    }
    }
write_image_data("image_out.bmp", data2, width2, height2);

}

void scale_bilinear(char *filename, float X){
    unsigned char* data;
    unsigned char* data2;
    int width, height, channel_count;
    read_image_data(filename, &data, &width, &height, &channel_count);
    int width2, height2,size;
    width2 = width*X;
    height2 = height*X;
    size = width2*height2*channel_count;
    data2=malloc(size);
    int x1,y1,c;
    float dx,dy;
    float gx, gy;
    int pixel_droite,pixel_dessous;
    int x0,y0;
    int index1, index2, index3, index4;
    float v1, v2, v3, v4;
    float bilineaire;
    for(y1=0;y1<height2;y1++){
        for(x1=0;x1<width2;x1++){
            gx=x1/X;
            gy=y1/X;
            x0=(int)gx;
            y0=(int)gy;
            pixel_droite=x0+1;
            pixel_dessous=y0+1;
            if (pixel_droite>=width){
                pixel_droite=width-1;
            }
            if (pixel_dessous>=height){
                pixel_dessous=height-1;
            }
            if (x0>=width){
                x0=width-1;
            }
            if (y0>=height){
                y0=height-1;
            }
            dx=gx-x0;
            dy=gy-y0;
            for(c=0;c<channel_count;c++){
                index1=(y0*width+x0)*channel_count+c;
                index2=(y0*width+pixel_droite)*channel_count+c;
                index3=(pixel_dessous*width+x0)*channel_count+c;
                index4=(pixel_dessous*width+pixel_droite)*channel_count+c;

                v1=data[index1];
                v2=data[index2];
                v3=data[index3];
                v4=data[index4];

                bilineaire=(1-dx)*(1-dy)*v1+v2*dx*(1-dy)+v3*(1-dx)*dy+v4*dx*dy;
                data2[(y1*width2+x1)*channel_count+c]=(unsigned char)bilineaire;
            }

        }
    }
    write_image_data("image_out.bmp", data2, width2, height2);
}
