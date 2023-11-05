#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "headers/validate.h"
#include "headers/color-conversion.h"
#include "types/rgb.h"
#include "types/hsl.h"


int main(int argc, char * argv[])
{
    HSL hsl = {0.000000, 0.000000, 0.000000};
    RGB rgb = {0, 0, 0};

    validate_params(argc, argv);

    hsl.hue        = validate_hue(argv[1]);
    hsl.saturation = validate_saturation(argv[2]);
    hsl.lightness  = validate_lightness(argv[3]);

    rgb = hsl2rgb(&hsl);

    printf(
        "rgb(%li, %li, %li)",
        lround(rgb.red),
        lround(rgb.green),
        lround(rgb.blue)
    );

    putchar('\n');
}

