/***********************************************************************
**
**   radiopoint.cpp
**
**   This file is part of KFLog.
**
************************************************************************
**
**   Copyright (c):  2000 by Heiner Lamprecht, Florian Ehinger
**
**   This file is distributed under the terms of the General Public
**   Licence. See the file COPYING for more information.
**
**   $Id$
**
***********************************************************************/

#include "radiopoint.h"

RadioPoint::RadioPoint(QString n, QString i, QString g, unsigned int t,
    WGSPoint wgsP, QPoint pos, const char* f, int elev)
  : SinglePoint(n, g, t, wgsP, pos, elev),
    frequency(f), icao(i)
{

}

RadioPoint::~RadioPoint()
{

}

void RadioPoint::printMapElement(QPainter* printPainter, bool isText)
{

}

QString RadioPoint::getFrequency() const { return frequency; }

QString RadioPoint::getICAO() const { return icao; }
