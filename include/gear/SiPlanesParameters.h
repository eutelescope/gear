// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef GEAR_SIPLANESPARAMETERS_H
#define GEAR_SIPLANESPARAMETERS_H 1

#include "gear/GearParameters.h"

namespace gear {

class SiPlanesLayerLayout;

/**Geometry properties of a pixel beam telescope needed for reconstruction code.
   *  @author T. Klimkovich, DESY
   *  @version $Id: 
   */
	
class SiPlanesParameters : virtual public GearParameters {

public: 
    /// Destructor.
    virtual ~SiPlanesParameters() { /* nop */; }

  // static constants (enums( for the type of layout

    static const int TelescopeWithDUT    = 1 ;
    static const int TelescopeWithoutDUT    = 2 ;
    /** The layer layout of pixel beam telescope. */
    virtual const SiPlanesLayerLayout & getSiPlanesLayerLayout() const = 0;

    /** ID of telescope setup.
     */

    virtual int getSiPlanesID() const = 0;

    /** The type of SiPlanes detector: 
     * SiPlanesParameters.TelescopeWithDUT, SiPlanesParameters.TelescopeWithoutDUT.
     */

    virtual int getSiPlanesType() const = 0;

    /** Number of telescope planes of SiPlanes detector.
     */

    virtual int getSiPlanesNumber() const = 0;
}; // class
} // namespace gear
#endif /* ifndef GEAR_SIPLANESPARAMETERS_H */