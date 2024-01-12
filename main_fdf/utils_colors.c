#include "fdf.h"
#include <stdio.h>

int is_dark(t_color color)
{
	int brightness = color.r * RED_COEFFICIENT + color.g * GREEN_COEFFICIENT + color.b * BLUE_COEFFICIENT;
	return brightness < DARK_THRESHOLD;
}

t_color *gen_gradient(void)
{
    srand(time(NULL));

    t_color *gradients = malloc(2 * sizeof(t_color));
    if (gradients == NULL) {
        return NULL;
    }

    do
    {
        gradients[0].r = rand() % 256;
        gradients[0].g = rand() % 256;
        gradients[0].b = rand() % 256;

        gradients[1].r = rand() % 256;
        gradients[1].g = rand() % 256;
        gradients[1].b = rand() % 256;

        printf("First gradient: %d\n", is_dark(gradients[0]));
        printf("Second gradient: %d\n", is_dark(gradients[1]));
    } while (is_dark(gradients[0]) || is_dark(gradients[1]));

    return gradients;
}

void print_gradient(t_color *gradient)
{
	if (gradient != NULL)
	{
		printf("Gradient 0: R - %d, G - %d, B - %d\n", gradient[0].r, gradient[0].g, gradient[0].b);
		printf("Gradient 1: R - %d, G - %d, B - %d\n", gradient[1].r, gradient[1].g, gradient[1].b);
	}
	else
	{
		printf("Failed to generate gradient.\n");
	}
}

int gradient_to_int(t_color *color)
{
    return (color->r << 16) | (color->g << 8) | color->b;
}