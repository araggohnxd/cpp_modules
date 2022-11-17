/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   betay: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   gammareated: 2022/11/17 16:29:32 by maolivei          #+#    #+# */
/*   Updated: 2022/11/17 18:05:59 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool inside(float x) { return (0 <= x - EPSILON && x + EPSILON <= 1); }

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float px = point.getX().toFloat();
    float py = point.getY().toFloat();

    float x1 = a.getX().toFloat();
    float y1 = a.getY().toFloat();

    float x2 = b.getX().toFloat();
    float y2 = b.getY().toFloat();

    float x3 = c.getX().toFloat();
    float y3 = c.getY().toFloat();

    float denom = ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
    float alpha = ((y2 - y3) * (px - x3) + (x3 - x2) * (py - y3)) / denom;
    float beta  = ((y3 - y1) * (px - x3) + (x1 - x3) * (py - y3)) / denom;
    float gamma = 1 - alpha - beta;

    return (inside(alpha) && inside(beta) && inside(gamma));
}
