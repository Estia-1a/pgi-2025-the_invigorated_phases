#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void dimension (char *source_path);

void first_pixel (char *source_path);

void tenth_pixel (char *source_path);

void second_line(char *source_path);

void max_pixel(char *filename);

void min_pixel(char *filename);

void min_component(char *filename, char X);

void max_component(char *filename, char X);

void stat_report(char *filename);

void color_red(char *filename);

void color_green(char *filename);

void color_blue(char *filename);

void color_gray(char *filename);

void color_gray_luminance(char *filename);

void color_invert(char *filename);

void rotate_cw(char *filename);

void rotate_acw(char *filename);

void mirror_horizontal(char *filename);

void mirror_vertical(char *filename);

void mirror_total(char *filename);

void color_desaturate(char *filename);

void scale_crop(char *filename, int center_x, int center_y, int new_width, int new_height);

void scale_nearest(char *filename, float X);

void scale_bilinear(char *filename, float X);
#endif
