# Daily Evaluation 13/06 - 14:36:23
You can find below how you did for each feature. 
 You should merge the pull request to keep the eval and automatically close and open the issues you have finished!
# Milestone  Tutorial
Score : 18/23 :  78%
## Detail by Feature
| Feature     | Score       | Missed tests                                                                                                                                                                                              | Stdout                            |
| :---------- | :---------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| dimension   | 4/4 :  100% |                                                                                                                                                                                                           |                                   |
| first_pixel | 5/5 :  100% |                                                                                                                                                                                                           |                                   |
| tenth_pixel | 5/5 :  100% |                                                                                                                                                                                                           |                                   |
| second_line | 0/5 :  0%   | Second line First Pixel 64x64 : 255,0,0<br>Second line First Pixel Red : 255,0,0<br>Second line First Pixel Green : 0,255,0<br>Second line First Pixel Blue : 0,0,255<br>Second line First Pixel 21 22 23 | second ligne : 255, 0, 0<br>seco… |
| print_pixel | 4/4 :  100% |                                                                                                                                                                                                           |                                   |

# Milestone  statistiques
Score : 24/26 :  92%
## Detail by Feature
| Feature         | Score       | Missed tests        | Stdout                            |
| :-------------- | :---------- | :------------------ | :-------------------------------- |
| max_pixel       | 3/4 :  75%  | Max Pixel black 8x8 | max_pixel (0, 1940474936): 0, 0,… |
| min_pixel       | 3/4 :  75%  | Min Pixel white 8x8 | min_pixel (0, 816725048): 255, 2… |
| min_component R | 3/3 :  100% |                     |                                   |
| min_component G | 3/3 :  100% |                     |                                   |
| min_component B | 3/3 :  100% |                     |                                   |
| max_component R | 3/3 :  100% |                     |                                   |
| max_component G | 3/3 :  100% |                     |                                   |
| max_component B | 3/3 :  100% |                     |                                   |

# Milestone  colors
Score : 29.779999999999998/35 :  85%
## Detail by Feature
| Feature              | Score                      | Missed tests                                                                                                                                         | Stdout           |
| :------------------- | :------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------- |
| color_red            | 5/5 :  100%                |                                                                                                                                                      |                  |
| color_blue           | 5/5 :  100%                |                                                                                                                                                      |                  |
| color_green          | 5/5 :  100%                |                                                                                                                                                      |                  |
| color_gray           | 5/5 :  100%                |                                                                                                                                                      |                  |
| color_invert         | 5/5 :  100%                |                                                                                                                                                      |                  |
| color_gray_luminance | 4.779999999999999/5 :  95% |                                                                                                                                                      |                  |
| color_desaturate     | 0/5 :  0%                  | Convert red image to GRAY<br>Convert blue image to GRAY<br>Convert green Image to GRAY<br>Convert white Image to GRAY<br>convert black Image to GRAY | <br><br><br><br> |

# Milestone  transform
Score : 6/15 :  40%
## Detail by Feature
| Feature           | Score       | Missed tests                                                   | Stdout   |
| :---------------- | :---------- | :------------------------------------------------------------- | :------- |
| rotate_cw         | 3/3 :  100% |                                                                |          |
| rotate_acw        | 3/3 :  100% |                                                                |          |
| mirror_horizontal | 0/3 :  0%   | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_vertical   | 0/3 :  0%   | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_total      | 0/3 :  0%   | mirror square image<br>mirror large image<br>mirror high image | <br><br> |

# Milestone  resize
Score : 0/60 :  0%
## Detail by Feature
| Feature        | Score      | Missed tests                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Stdout                            |
| :------------- | :--------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| scale_nearest  | 0/20 :  0% | scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3                                                                                 | <br><br><br><br><br><br><br><br>… |
| scale_bilinear | 0/20 :  0% | scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12<br>scale_bilinear 0.21<br>scale_bilinear 0.76<br>scale_bilinear 1.41<br>scale_bilinear 2.12                               | <br><br><br><br><br><br><br><br>… |
| scale_crop     | 0/20 :  0% | scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10 | <br><br><br><br><br><br><br><br>… |

