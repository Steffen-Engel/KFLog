/***********************************************************************
**
**   mapcalc.h
**
**   This file is part of KFLog2.
**
************************************************************************
**
**   Copyright (c):  1999, 2000 by Heiner Lamprecht, Florian Ehinger
**
**   This file is distributed under the terms of the General Public
**   Licence. See the file COPYING for more information.
**
**   $Id$
**
***********************************************************************/

#ifndef MAPCALC_H
#define MAPCALC_H

#include <wp.h>

#define PI 3.141592654

/**
 * The earth's radius used for calculation, given in Meter.
 * NOTE: We use the earth as a sphere, not as a spheroid!
 */
#define RADIUS 6370289.509

/**
 * Calculates the distance between two given points (in km).
 */
double dist(double lat1, double lon1, double lat2, double lon2);

/**
 * Calculates the distance between two given points (in km).
 */
double dist(wayPoint* wp1, wayPoint* wp2);

/**
 * Calculates the distance between two given points (in km).
 */
double dist(wayPoint* wp, flightPoint* fp);

/**
 * Calculates the distance between two given points (in km).
 */
double dist( flightPoint* fp1, flightPoint* fp2);

/**
 * Converts the given coordinate into a readable string.
 * ( xxx,xxxx�[N,S,E,W] )
 */
QString printPos(int coord, bool isLat = true);

/**
 * Converts the given time (in sec.) into a readable string.
 * ( hh:mm:ss )
 */
QString printTime(int time, bool isZero = false, bool isSecond = true);

/**
 * Calculates the vario of a given point
 */
float getVario(flightPoint p);

/**
 * Calculates the speed of a given point
 */
float getSpeed(flightPoint p);

/**
 * Calculates the bearing to the previous point
 */
float getBearing(flightPoint p1, flightPoint p2);

/**
 * Converts a x/y position into a polar-coordinate.
 */
double polar(double x, double y);

#endif
