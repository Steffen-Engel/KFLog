/***********************************************************************
**
**   flightrecorderpluginbase.h
**
**   This file is part of KFLog2.
**
************************************************************************
**
**   Copyright (c):  2003 by Andr� Somers
**
**   This file is distributed under the terms of the General Public
**   Licence. See the file COPYING for more information.
**
**   $Id$
**
***********************************************************************/

#ifndef FLIGHTRECORDERPLUGINBASE_H
#define FLIGHTRECORDERPLUGINBASE_H


/**
 * This class funtions as a baseclass for all flightrecorder plugins.
 * It features default implementation of all functions that return
 * 'not available' values. Just re-implement the functions you want
 * to support.
 * @author Andr� Somers
 */

#include <qstring.h>
#include <qlist.h>
#include <qobject.h>

#include "frstructs.h"
#include "waypoint.h"
#include "flighttask.h"

// Standard FlightRecorder return values
#define FR_ERROR -1          // Error
#define FR_NOTSUPPORTED -2   // Function not supported
#define FR_OK 1              // OK, no problem.

// FlightRecorder capabilities
struct FR_Capabilities {
  unsigned int maxNrTasks;             //maximum number of tasks
  unsigned int maxNrWaypoints;         //maximum number of waypoints
  unsigned int maxNrWaypointsPerTask;  //maximum number of waypoints per task
  unsigned int maxNrPilots;            //maximum number of pilots

  bool supDlWaypoint;      //supports downloading of waypoints?
  bool supUlWaypoint;      //supports uploading of waypoints?
  bool supDlFlight;        //supports downloading of flights?
  bool supUlFlight;        //supports uploading of flights?
  bool supSignedFlight;    //supports downloading in of signed flights?
  bool supDlTask;          //supports downloading of tasks?
  bool supUlTask;          //supports uploading of tasks?
  bool supUlDeclaration;   //supports uploading of declarations?
};

    
class FlightRecorderPluginBase:public QObject {
Q_OBJECT
public: 
  enum TransferMode{none, serial, URL};
  /* The none option is pretty useless, but is included for completeness
     sake. It _is_ used in the flightrecorder dialog though! */

  FlightRecorderPluginBase();
  virtual ~FlightRecorderPluginBase();

  /**
   * Returns the name of the lib.
   */
  virtual QString getLibName()=0;
  /**
   * Returns the transfermode this plugin supports.
   */
  virtual TransferMode getTransferMode()=0;
  /**
   * Returns a list of recorded flights in this device.
   */
  virtual int getFlightDir(QList<FRDirEntry>*)=0;
  /**
   * Downloads a specific flight.
   */
  virtual int downloadFlight(int flightID, int secMode, const QString fileName)=0;
  /**
   * get recorder info serial id
   */
  virtual QString getRecorderSerialNo()=0;
  /**
   * Opens the recorder for serial communication.
   */
  virtual int openRecorder(const QString portName, int baud)=0;
  /**
   * Opens the recorder for other communication.
   */
  virtual int openRecorder(QString URL)=0;
  /**
   * Closes the connection with the flightrecorder.
   */
  virtual int closeRecorder()=0;
  /**
   * Write flight declaration to recorder
   */
  virtual int writeDeclaration(FRTaskDeclaration *taskDecl, QList<Waypoint> *taskPoints)=0; 
  /**
   * Read tasks from recorder
   */
  virtual int readTasks(QList<FlightTask> *tasks)=0;
  /**
   * Write tasks to recorder
   */
  virtual int writeTasks(QList<FlightTask> *tasks)=0;
  /**
   * Read waypoints from recorder
   */
  virtual int readWaypoints(QList<Waypoint> *waypoints)=0;
  /**
   * Write waypoints to recorder
   */
  virtual int writeWaypoints(QList<Waypoint> *waypoints)=0;
  /**
   * Returns whether the flighrecorder is connected.
   */
  inline bool isConnected(){return _isConnected;};

  /**
   * Returns the flightrecorders capabilities.
   */
  inline FR_Capabilities capabilities(){return _capabilities;};

  /**
   * Returns additional info about an error that occured (optional).
   * _errorinfo is reset afterwards.
   */
  QString lastError();
    
protected:
  /**
   * Is the flightrecorder connected?
   */
  bool _isConnected;

  /**
   * The flightrecorders capabilities.
   * To be set in the constructor of depending classes.
   */
  FR_Capabilities _capabilities;

  /**
   * Optionally contains additional info about an error.
   */
  QString _errorinfo; 
   
signals:
  /**
   * May be emitted when transfering data
   *  bool finished is true if the datatransfer is complete
   *  int progress is a measure how much progress has been made, relative to total
   *  int total is the total progress to be made, for instance the total number of bytes to transfer
   * May be used to display a progress dialog.
   */
  void progress(bool finished, int progress, int total);
};

#endif