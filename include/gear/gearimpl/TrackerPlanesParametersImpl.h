// -*- C++ -*-
#ifndef GEAR_TrackerPlanesParametersImpl_H
#define GEAR_TrackerPlanesParametersImpl_H 1

#include "gear/TrackerPlanesParameters.h"
#include "gearimpl/GearParametersImpl.h"
#include "gearimpl/TrackerPlanesLayerLayoutImpl.h"


namespace gear {

class TrackerPlanesLayerLayout;

  /** Abstract description of layers in pixel beam telescope.
   *  This assumes a number of silicon layers, arranged perpendicular to the beam.
   *  @author I. Rubinskiy, DESY
   *  @version $Id: 
   */
class TrackerPlanesParametersImpl : public GearParametersImpl, public TrackerPlanesParameters {

public: 
  /** C'tor  
   *  @param siplanesID             ID of TrackerPlanes detector setup   
   *  @param siplanesType           the type of the TrackerPlanes detector
   *  @param siplanesNumber         the number of Si planes
   */
  TrackerPlanesParametersImpl(int siplanesID, int siplanesType, int siplanesNumber) ;

  // Destructor.
  virtual ~TrackerPlanesParametersImpl() { /* nop */; }
  

  /** Adding a Layer to the TrackerPlanes detector (without parameters for layer rotation)
   **/
  virtual void addLayer( TrackerPlanesLayerImpl* _layer ){

     _layerLayout.addLayer( _layer ); // pointer as input
  }
 
 
      
  /** Returns the layer layout of TrackerPlanes detector 
   */
  virtual const TrackerPlanesLayerLayout & getTrackerPlanesLayerLayout() const { return _layerLayout ; }
  

  /** Returns the ID of TrackerPlanes detector setup
   */

  virtual int getTrackerPlanesID() const { return _siplanesID ; }

  /** Returns the type of TrackerPlanes detector
   */
  virtual int getTrackerPlanesType() const { return _siplanesType ; }

  /** Returns the number of Si planes
   */
  virtual int getTrackerPlanesNumber() const { return _siplanesNumber ; }
  
protected:
  
  TrackerPlanesLayerLayoutImpl _layerLayout ;
  
  int _siplanesID;

  int _siplanesType ;
  
  int _siplanesNumber ;

private:

}; // class

} // namespace gear

#endif /* #ifndef GEAR_TrackerPlanesParametersImpl_H */

