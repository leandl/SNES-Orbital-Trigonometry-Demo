#ifndef MATH_TRIGONOMETRY_H
#define MATH_TRIGONOMETRY_H

#include <snes.h>


void TrigonometryOrbital_computePosition(u16 *obj_x, u16 *obj_y, u16 r_point_x, u16 r_point_y, u16 angle, u8 distance);
void TrigonometryOrbital_computePositionEx(u16 *obj_x, u16 *obj_y, u16 r_point_x, u16 r_point_y, u16 angle, u8 distance, u8 x_scale, u8 y_scale);

#endif // MATH_TRIGONOMETRY_H
