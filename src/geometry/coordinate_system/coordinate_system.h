#pragma once

#include "../vector2/vector2.h"
#include "../../utils/vector/vector.h"
#include "../shape/shape.h"

#define INITIAL_ZOOM 10

typedef struct CoordinateSystem
{
    Vector2 position;
    Vector2 size;
    Vector2 origin;
    double zoom;

    Vector* shapes;
} CoordinateSystem;

CoordinateSystem* coordinate_system_create(Vector2 position, Vector2 size, Vector2 origin);
void coordinate_system_free(CoordinateSystem* cs);

Vector2 screen_to_coordinates(CoordinateSystem* cs, Vector2 point);
Vector2 coordinates_to_screen(CoordinateSystem* cs, Vector2 point);

void coordinate_system_add_shape(CoordinateSystem* cs, Shape* shape);
void coordinate_system_remove_shape(CoordinateSystem* cs, Shape* shape);

Shape* coordinate_system_get_hovered_shape(CoordinateSystem* cs, Vector2 point);

void coordinate_system_translate(CoordinateSystem* cs, Vector2 translation);
void coordinate_system_zoom(CoordinateSystem* cs, double zoom);
void coordinate_system_update_dimensions(CoordinateSystem* cs, Vector2 position, Vector2 size);
void coordinate_system_draw(CoordinateSystem* cs);