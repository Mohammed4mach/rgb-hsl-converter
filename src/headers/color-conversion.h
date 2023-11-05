#include "../types/hsl.h"
#include "../types/rgb.h"

#ifndef COLOR_CONVERSION_H_INCLUDED
#define COLOR_CONVERSION_H_INCLUDED

double get_hue(const RGB * rgb, double delta_max_min);
double get_saturation(double lightness, double delta_max_min);
double get_lightness(int max, int min);

int get_red();
int get_green();
int get_blue();

RGB hsl2rgb(const HSL * hsl);
HSL rgb2hsl(const RGB * rgb);

#endif // !COLOR_CONVERSION_H_INCLUDED

