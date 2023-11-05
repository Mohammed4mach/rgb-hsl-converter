#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../types/bool.h"

#ifndef VALIDATE_H_INCLUDED
#define VALIDATE_H_INCLUDED

void err(const char * message);

void validate_params(int argc, char * argv[]);

double validate_range(char * color_value, char * color, double max);

double validate_red(char * color_value);

double validate_green(char * color_value);

double validate_blue(char * color_value);

double validate_hue(char * value);

double validate_saturation(char * value);

double validate_lightness(char * value);

#endif // !VALIDATE_H_INCLUDED

