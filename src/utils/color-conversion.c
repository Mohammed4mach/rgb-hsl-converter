#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/color-conversion.h"

int get_hue_deprecated()
{
    /* double angle = 0.000000000; */

    /* angle = */
    /*     (red - 0.5 * green - 0.5 * blue) / */
    /*     sqrt( */
    /*         pow(red, 2) + pow(green, 2) + pow(blue, 2) - */
    /*         red * green - red * blue - green * blue */
    /*     ); */

    /* double angle_acos = acos( */
    /*     degrees2radians(angle) */
    /* ); */

    /* hue = */
    /*     blue > green ? */
    /*         360 - angle_acos : */
    /*         angle_acos; */

    return 0;
}

double get_hue(const RGB * rgb, double delta_max_min)
{
    double red   = rgb->red / 255.0;
    double green = rgb->green / 255.0;
    double blue  = rgb->blue / 255.0;
    double hue   = 0;

    if(red > blue && red > green) // Red is max
        hue = (green - blue) / delta_max_min;
    else if(green > red && green > blue) // Green is max
        hue = 2.0 + (blue - red) / delta_max_min;
    else if(blue > red && blue > green) // Blue is max
        hue = 4.0 + (red - green) / delta_max_min;
    else
        hue = 0;

    hue *= 60;

    return hue;
}

double get_saturation(double lightness, double delta_max_min)
{
    double saturation;

    saturation =
        lightness > 0 ?
            delta_max_min / (1 - fabs(2 * lightness - 1)) :
            0;

    return saturation;
}

double get_lightness(int max, int min)
{
    double lightness = (double)(max + min) / 510;;

    return lightness;
}

HSL rgb2hsl(const RGB * rgb)
{
    HSL hsl = {0, 0.000000, 0.000000};

    int max              = 0;
    int min              = 0;
    double delta_max_min = 0.000000000;

    max = fmax(rgb->red, rgb->green);
    max = fmax(max, rgb->blue);

    min = fmin(rgb->red, rgb->green);
    min = fmin(min, rgb->blue);

    delta_max_min = (max - min) / 255.0;

    hsl.hue        = get_hue(rgb, delta_max_min);
    hsl.lightness  = get_lightness(max, min);
    hsl.saturation = get_saturation(hsl.lightness, delta_max_min);

    return hsl;
}

int get_red()
{
    return 1;
}

int get_green()
{
    return 1;
}

int get_blue()
{
    return 1;
}

RGB hsl2rgb(const HSL * hsl)
{
    RGB rgb = {0, 0, 0};

    double c = (1 - fabs(2 * hsl->lightness - 1)) * hsl->saturation;
    double tmp =
        1 - fabs(fmod(hsl->hue / 60, 2) - 1);

    double x = c * tmp;

    double m = hsl->lightness - c / 2;

    double hue = hsl->hue;

    if(hue > 0 && hue < 60)
        rgb = (RGB){c, x, 0};
    else if(hue > 60 && hue < 120)
        rgb = (RGB){x, c, 0};
    else if(hue > 120 && hue < 180)
        rgb = (RGB){0, c, x};
    else if(hue > 180 && hue < 240)
        rgb = (RGB){0, x, c};
    else if(hue > 240 && hue < 300)
        rgb = (RGB){x, 0, c};
    else if(hue > 300 && hue < 360)
        rgb = (RGB){c, 0, x};

    rgb.red   = (rgb.red + m) * 255;
    rgb.green = (rgb.green + m) * 255;
    rgb.blue  = (rgb.blue + m) * 255;

    return rgb;
}

