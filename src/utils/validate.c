#include "../headers/validate.h"

void err(const char * message)
{
    fprintf(stderr, "\x1b[31mError: \x1b[0m%s\n", message);
    exit(-1);
}

void validate_params(int argc, char * argv[])
{
    argc--; // Name of the program does not count

    if(argc < 3)
        err("Arguments must be 3");
}

double validate_range(char * color_value, char * color, double max)
{
    char * tmp   = "";
    double value = strtod(color_value, &tmp);

    bool not_number   = color_value[0] != '0' && value == 0;

    if(not_number)
        err("Arguments must be numbers");

    bool within_range = value >= 0 && value <= max;

    if(!within_range)
    {
        char message[] = "";
        char * format  = "%s is not in the valid range";

        snprintf(message, strlen(format) + strlen(color), format, color);

        err(message);
    }

    return value;
}

double validate_red(char * color_value)
{
    return (int) validate_range(color_value, "red", 255);
}

double validate_green(char * color_value)
{
    return (int) validate_range(color_value, "green", 255);
}

double validate_blue(char * color_value)
{
    return (int) validate_range(color_value, "blue", 255);
}

double validate_hue(char * value)
{
    return (double) validate_range(value, "hue", 360);
}

double validate_saturation(char * value)
{
    return validate_range(value, "saturation", 1);
}

double validate_lightness(char * value)
{
    return validate_range(value, "lightness", 1);
}

