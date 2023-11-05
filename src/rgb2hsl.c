#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "headers/validate.h"
#include "headers/color-conversion.h"
#include "types/rgb.h"
#include "types/hsl.h"


int main(int argc, char * argv[])
{
    RGB rgb = {0, 0, 0};
    HSL hsl = {0.000000, 0.000000, 0.000000};

    validate_params(argc, argv);

    rgb.red   = validate_red(argv[1]);
    rgb.green = validate_green(argv[2]);
    rgb.blue  = validate_blue(argv[3]);

    hsl = rgb2hsl(&rgb);

    printf(
        "hsl(%i, %i, %i)",
        (int)round(hsl.hue),
        (int)((hsl.saturation) * 100),
        (int)((hsl.lightness) * 100)
    );

    putchar('\n');
}

