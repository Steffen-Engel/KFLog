/***********************************************************************
**
**   igc3dviewstate.cpp
**
**   This file is part of KFLog.
**
************************************************************************
**
**   Copyright (c):  2002 by Heiner Lamprecht
**
**   This file is distributed under the terms of the General Public
**   License. See the file COPYING for more information.
**
**   $Id$
**
***********************************************************************/

#include <cmath>

#include "igc3dviewstate.h"

/**
 * Based on 3dIgc by Jan Max Kreuger
 */

Igc3DViewState::Igc3DViewState()
{
  alpha = 300;
  beta = 90;
  gamma = 290;
  deltax = 0;
  deltay = -300;
  deltayoffset = 0;
  deltaz = 0;

  mag = 25;
  dist = 50;
  flag = 0;

  maxx = maxy = maxz = 50;
  minx = miny = minz = -50;
  polyhedron_back = 1;
  polyhedron_front = 1;
  flight_trace = 1;
  flight_shadow = 1;
  zfactor = 33;
  rotate_fract = 10.0;
  timerflag = 1;
  ms_timer = 40;
  flight_marker_position = 0;
  centering = 0;
}

Igc3DViewState::~Igc3DViewState()
{
}

void Igc3DViewState::reset()
{
  float tmpx, tmpy, tmpz;

  alpha = 300;
  beta = 90;
  gamma = 290;
  deltay = -200;

  (fabs(maxx) > fabs(minx)) ? tmpx = maxx : tmpx = minx;
  (fabs(maxy) > fabs(miny)) ? tmpy = maxy : tmpy = miny;
  (fabs(maxz) > fabs(minz)) ? tmpz = maxz : tmpz = minz;

  deltayoffset = - sqrt(tmpx * tmpx + tmpy * tmpy + tmpz * tmpz) - 0.1;
  deltay = deltay + deltayoffset;

  mag = 25;
  flag = 0;
  zfactor = 33;
  rotate_fract = 10.0;
  ms_timer = 40;
  flight_marker_position = 0;
  centering = 0;
}
