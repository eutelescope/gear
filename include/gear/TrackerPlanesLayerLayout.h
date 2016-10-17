// -*- C++ -*-
#ifndef GEAR_TrackerPlanesLAYERLAYOUT_H
#define GEAR_TrackerPlanesLAYERLAYOUT_H 1

#include <vector>
#include <string>

#include <cstdio>
#include <iostream> 
#include <iomanip>


namespace gear {

/**Abstract description of layers in a pixel beam telescope.
 * @author I. Rubinskiy,  DESY
 * @version $Id: 
 */

class TrackerPlanesLayerImpl;

class TrackerPlanesMaterialLayer  {

    
public:
    /// Destructor.
    virtual ~TrackerPlanesMaterialLayer() { /* nop */; }

    /** */
    virtual int getID() const = 0;

    /** a free parameter string field
     */
    virtual std::string getInfo() const = 0;

    /** The radiation length of nonsensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source.
     */
    virtual std::string getMaterial() const = 0;

    /** x position of the center of nonsensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source.
     */
    virtual double getOffsetX() const = 0;

    /** y position of the center of nonsensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source.
     */
    virtual double getOffsetY() const = 0;

    /** z position of the center of nonsensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source. 
     */
    virtual double getOffsetZ() const = 0;

    /** rotation angles according to Euler implementation scheme
     * (in XY plane -> around axis Z: gamma )
     */
    virtual double getDeltaRotationXY() const = 0;
    
    /** rotation angles according to Euler implmentation scheme
     * (in ZX plane -> around axis Y: beta  )
     */
    virtual double getDeltaRotationZX() const = 0;
  
    /** rotation angles according to Euler implmentation scheme
     *  (in ZY plane -> around axis X: alfa  )
     */
    virtual double getDeltaRotationZY() const = 0;

    virtual void setID(int value)               = 0;
   
    /** */
    virtual void setInfo(std::string value) = 0;

    /** a free parameter string field
     */
    virtual void setMaterial( std::string value)    = 0;

    /** a free parameter string field
     */
    virtual void setOffsetX( double value)    = 0;

    /** a free parameter string field
     */
    virtual void setOffsetY( double value)    = 0;

    /** a free parameter string field
     */
    virtual void setOffsetZ( double value)    = 0;

    /** a free parameter string field
     */
    virtual void setDeltaRotationXY( double value)   = 0;

    /** a free parameter string field
     */
    virtual void setDeltaRotationZX( double value)   = 0;

    /** a free parameter string field
     */
    virtual void setDeltaRotationZY( double value)   = 0;
    
    /** a free parameter string field
     */
    virtual void setSizeX( double value)        = 0;
   
    /** a free parameter string field
     */
    virtual void setSizeY( double value)        = 0;
   
    /** a free parameter string field
     */
    virtual void setThickness( double value)    = 0;


    /** Size in x direction of nonsensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source. 
     */	
    virtual double getSizeX() const = 0;

    /** Size in y direction of nonsensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source. 
     */	
    virtual double getSizeY() const = 0;

    /** Thickness of nonsensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source. 
     */	
    virtual double getThickness() const = 0;

};

class TrackerPlanesSensitiveLayer  {

    
public:
    /// Destructor.
    virtual ~TrackerPlanesSensitiveLayer() { /* nop */; }


    /** ID of sensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source.*/
    virtual int getID() const = 0;

    /** */
    virtual std::string getInfo() const = 0;

    /** get the geometry string
     */
    virtual std::string getGeometry() const = 0;

    /** x position of the center of sensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source.
     */
    virtual double getOffsetX() const = 0;

    /** y position of the center of sensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source.
     */
    virtual double getOffsetY() const = 0;

    /** z position of the center of sensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source.
     */
    virtual double getOffsetZ() const = 0;

    /** rotation angles according to Euler implementation scheme
     * (in XY plane -> around axis Z: gamma )
     */
    virtual double getDeltaRotationXY() const = 0;
    
    /** rotation angles according to Euler implmentation scheme
     * (in ZX plane -> around axis Y: beta  )
     */
    virtual double getDeltaRotationZX() const = 0;
  
    /** rotation angles according to Euler implmentation scheme
     *  (in ZY plane -> around axis X: alfa  )
     */
    virtual double getDeltaRotationZY() const = 0;

    /** x position uncertainty 
     */
    virtual double getOffsetXunc() const = 0;

    /** y position uncertainty 
     */
    virtual double getOffsetYunc() const = 0;

    /** z position uncertainty 
     */
    virtual double getOffsetZunc() const = 0;

    /** Uncertainty on XY angle
	 */
    virtual double getDeltaRotationXYunc() const = 0;
    
    /** Uncertainty on ZX angle
	 */
    virtual double getDeltaRotationZXunc() const = 0;
  
    /** Uncertainty on ZY angle
	 */
    virtual double getDeltaRotationZYunc() const = 0;

    /** Thickness of sensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source. 
     */	
    virtual double getThickness() const = 0;

    /** The radiation length of sensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source.
     */
    virtual std::string getMaterial() const = 0;

    /** Number of pixels in x direction in sensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source. 
     */
    virtual int getNpixelX() const = 0;

    /** Number of pixels in y direction in sensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source. 
     */
    virtual int getNpixelY() const = 0;

    /** Pitch size in x direction in sensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source. 
     */
    virtual double getPitchX() const = 0;

    /** Pitch size in y direction in sensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source. 
     */
    virtual double getPitchY() const = 0;

	virtual int getFlip1() const = 0;
	virtual int getFlip2() const = 0;
	virtual int getFlip3() const = 0;
	virtual int getFlip4() const = 0;

    /** Intrinsic resolution of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source. 
     */
    virtual double getResolutionX() const = 0;

    /** Intrinsic resolution of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source. 
     */
    virtual double getResolutionY() const = 0;

	virtual bool getEnabled() const = 0;

    /** a free parameter string field
     */
    virtual void setID(int value)               = 0;
 
    /** */
    virtual void setInfo(std::string value) = 0;
    
	/** */
    virtual void setGeometry(std::string value) = 0;

    /** a free parameter string field
     */
    virtual void setMaterial( std::string value)    = 0;
 
    /** a free parameter string field
     */
    virtual void setOffsetX( double value)    = 0;
 
    /** a free parameter string field
     */
    virtual void setOffsetY( double value)    = 0;
 
    /** a free parameter string field
     */
    virtual void setOffsetZ( double value)    = 0;
 
    /** a free parameter string field
     */
    virtual void setDeltaRotationXY( double value)   = 0;
 
    /** a free parameter string field
     */
    virtual void setDeltaRotationZX( double value)   = 0;
 
    /** a free parameter string field
     */
    virtual void setDeltaRotationZY( double value)   = 0;

    virtual void setOffsetXunc( double value)    = 0;
    virtual void setOffsetYunc( double value)    = 0;
    virtual void setOffsetZunc( double value)    = 0;
    virtual void setDeltaRotationXYunc( double value)   = 0;
    virtual void setDeltaRotationZXunc( double value)   = 0;
    virtual void setDeltaRotationZYunc( double value)   = 0;
 
    /** a free parameter string field
     */
    virtual void setThickness( double value)    = 0;

    /**      */
    virtual void setNpixelX( int value )        = 0;   
    /**      */
    virtual void setNpixelY( double value )     = 0;
    /**      */
    virtual void setPitchX( double value )      = 0;
    /**      */
    virtual void setPitchY( double value )      = 0;


	/**      */
	virtual void setFlip1( int value )        = 0; 
	/**      */
	virtual void setFlip2( int value )        = 0; 
	/**      */
	virtual void setFlip3( int value )        = 0; 
	/**      */
	virtual void setFlip4( int value )        = 0; 

    /**      */
    virtual void setResolutionX( double value ) = 0; 
    /**      */
    virtual void setResolutionY( double value ) = 0;
    /**      */
    virtual void setEnabled( bool value ) = 0;

};


class TrackerPlanesLayer  {

public:
    /// Destructor.
    virtual ~TrackerPlanesLayer() { /* nop */; }

    /** Layer ID of nonsensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source.*/
    virtual int getID() const = 0;

    /** */
    virtual std::string getInfo() const = 0;

    /** add a setter method
     * set ID of a new layer
     */
    virtual void setID(int value)  = 0;

    /** */
    virtual void setInfo(std::string value) = 0;

    /** The total number of nonSense layers. */
    virtual int getNMaterialLayers() const = 0;

    /** The total number of Sensitive layers. */
    virtual int getNSensitiveLayers() const = 0;

//---
//-
	//Position Setters
    virtual void setPositionX( double value)    = 0;
    virtual void setPositionY( double value)    = 0;
    virtual void setPositionZ( double value)    = 0;
	//Rotation Setters 
    virtual void setRotationXY( double value)   = 0;
    virtual void setRotationZX( double value)   = 0;
    virtual void setRotationZY( double value)   = 0;
	//Uncertaintu Setters
    virtual void setPositionXunc( double value)    = 0;
    virtual void setPositionYunc( double value)    = 0;
    virtual void setPositionZunc( double value)    = 0;
    virtual void setRotationXYunc( double value)   = 0;
    virtual void setRotationZXunc( double value)   = 0;
    virtual void setRotationZYunc( double value)   = 0;
//-
	//Position Getters
    virtual double getPositionX() const = 0;
    virtual double getPositionY() const = 0;
    virtual double getPositionZ() const = 0;
	//Rotation Getters
    virtual double getRotationXY() const = 0;
    virtual double getRotationZX() const = 0;
    virtual double getRotationZY() const = 0;
 	//Uncertainty Getters
    virtual double getPositionXunc() const = 0;
    virtual double getPositionYunc() const = 0;
    virtual double getPositionZunc() const = 0;
    virtual double getRotationXYunc() const = 0;
    virtual double getRotationZXunc() const = 0;
    virtual double getRotationZYunc() const = 0;
//-
//---



    /** a free parameter string field
     */
    virtual void addMaterialLayer(
			      int ID, std::string info,
			      double OffsetX, double OffsetY, double OffsetZ,
			      double DeltaRotationXY, double DeltaRotationZX, double DeltaRotationZY,
			      double SizeX, double SizeY, double Thickness, std::string Material
                              ) = 0;

    /** a free parameter string field
     */
    virtual void addSensitiveLayer(
			      int ID, std::string info, std::string geometry,
			      double OffsetX, double OffsetY, double OffsetZ,
			      double DeltaRotationXY, double DeltaRotationZX, double DeltaRotationZY,
			      double OffsetXunc, double OffsetYunc, double OffsetZunc,
			      double DeltaRotationXYunc, double DeltaRotationZXunc, double DeltaRotationZYunc,
				  int Flip1, int Flip2, int Flip3, int Flip4,
			      double Thickness, std::string Material,
			      int NpixelX, int NpixelY,
			      double PitchX,double PitchY, double ResolutionX, double ResolutionY,
				  bool Enabled
                              ) = 0;

};


class TrackerPlanesLayerLayout  {

public: 
    /// Destructor.
    virtual ~TrackerPlanesLayerLayout() { /* nop */; }

    /** The total number of layers. */
    virtual int getNLayers() const = 0;
 
    /** a free parameter string field
     */
    virtual const TrackerPlanesLayerImpl* getLayer( unsigned int ID ) const = 0;
 
    /** a free parameter string field
     */
    virtual const TrackerPlanesLayerImpl* getLayerByID( int ID ) const = 0;

  
    /** a free parameter string field
     */
    virtual void addLayer( TrackerPlanesLayerImpl* )  = 0;

     /** Layer ID of nonsensitive volume of layer layerIndex - layer indexing starts at 0
     *  for the layer closest to the beam source.*/
    virtual int getID() const = 0;

    /** */
    virtual void setID(int ID) = 0;

    /** */
    virtual std::string getInfo() const = 0;

    /** */
    virtual void setInfo(std::string value) = 0;
 
    /** a free parameter string field
     */
    virtual void PrintHeader( std::ostream& s) const = 0;
 
    /** a free parameter string field
     */
    virtual void PrintLayers( std::ostream& s) const = 0;
 
    /** a free parameter string field
     */
    virtual void PrintFooter( std::ostream& s) const = 0;

}; // class


} // namespace gear
#endif /* ifndef GEAR_TrackerPlanesLAYERLAYOUT_H */
