// -*- C++ -*-
#ifndef GEAR_TrackerPlanesLayerLayoutImpl_H
#define GEAR_TrackerPlanesLayerLayoutImpl_H 1

#include "gear/TrackerPlanesLayerLayout.h"
#include <vector>
#include <iostream>

namespace gear {

/** Abstract description of layers in pixel beam telescope. <br>
 *  This assumes a number of silicon layers arranged perpendicular to the beam.
 * 
 * @author I. Rubinskiy,  DESY
 * @version $Id: 
 */


// basic scattering only layer
class TrackerPlanesMaterialLayerImpl: public TrackerPlanesMaterialLayer  {

    private:
	
    /**      */
    int ID ;	
    /**      */
    std::string info;
    /**      */
    double OffsetX ;
    /**      */
    double OffsetY ;
    /**      */
    double OffsetZ ;
    /**      */
    double DeltaRotationXY;
    /**      */
    double DeltaRotationZX;
    /**      */
    double DeltaRotationZY;
    /**      */
    double SizeX ;
    /**      */
    double SizeY ;
    /**      */
    double Thickness ;
    /**      */
    std::string Material ;
    
    public:
     /** safe default contructor **/
    TrackerPlanesMaterialLayerImpl() : ID(0), info(""), OffsetX(0.), OffsetY(0.), OffsetZ(0.),  DeltaRotationXY(0.), DeltaRotationZX(0.), DeltaRotationZY(0.), SizeX(0.), SizeY(0.), Thickness(0.), Material("") { ; } ;

    /// Destructor.
    /**      */
    virtual ~TrackerPlanesMaterialLayerImpl() { /* nop */; }
    /**      */
    virtual int getID() const { return ID  ; }
    /**      */
    virtual std::string getInfo() const { return info ; }
    /**      */
    virtual double getOffsetX() const { return OffsetX  ; }
    /**      */
    virtual double getOffsetY() const { return OffsetY  ; }
    /**      */
    virtual double getOffsetZ() const { return OffsetZ  ; }
    /**      */
    virtual double getDeltaRotationXY() const { return DeltaRotationXY  ; }
    /**      */
    virtual double getDeltaRotationZX() const { return DeltaRotationZX  ; }
    /**      */
    virtual double getDeltaRotationZY() const { return DeltaRotationZY  ; }
    /**      */
    virtual double getSizeX() const { return SizeX  ; }
    /**      */
    virtual double getSizeY() const { return SizeY  ; }
    /**      */
    virtual double getThickness() const { return Thickness  ; }
    /**      */
    virtual std::string getMaterial() const { return Material  ; }	 
 
    // add "set" methods:
    /**      */
    virtual void setID( int value )           {  ID = value         ; }  
    /**      */
    virtual void setInfo( std::string value) { info = value ; }
    /**      */
    virtual void setMaterial( std::string value)  {  Material = value  ; }
    /**      */
    virtual void setOffsetX( double value)  {  OffsetX = value  ; }
    /**      */
    virtual void setOffsetY( double value)  {  OffsetY = value  ; }
    /**      */
    virtual void setOffsetZ( double value)  {  OffsetZ = value  ; }
    /**      */
    virtual void setDeltaRotationXY( double value) {  DeltaRotationXY = value ; }
    /**      */
    virtual void setDeltaRotationZX( double value) {  DeltaRotationZX = value ; }
    /**      */
    virtual void setDeltaRotationZY( double value) {  DeltaRotationZY = value ; }
    /**      */
    virtual void setSizeX( double value)      {  SizeX = value      ; }
    /**      */
    virtual void setSizeY( double value)      {  SizeY = value      ; }
    /**      */
    virtual void setThickness( double value)  {  Thickness = value  ; }


};

//basic scattering and sensitve layer
class TrackerPlanesSensitiveLayerImpl: public TrackerPlanesSensitiveLayer   {

    private:   
   
    /**      */
    int ID ;
    /**      */
    std::string info;
    /**      */
    std::string geometry;
    /**      */
    double OffsetX ;
    /**      */
    double OffsetY ;
    /**      */
    double OffsetZ ;
    /**      */
    double DeltaRotationXY;
    /**      */
    double DeltaRotationZX;
    /**      */
    double DeltaRotationZY;

    /**      */
    double OffsetXunc;
    /**      */
    double OffsetYunc;
    /**      */
    double OffsetZunc;
    /**      */
    double DeltaRotationXYunc;
    /**      */
    double DeltaRotationZXunc;
    /**      */
    double DeltaRotationZYunc;

    /**      */
	int Flip1;
    /**      */
	int Flip2;
    /**      */
	int Flip3;
    /**      */
	int Flip4;

    /**      */
    double Thickness ;
    /**      */
    std::string Material ;

    /**      */
    int NpixelX;
    /**      */
    int NpixelY;
    /**      */
    double PitchX;
    /**      */
    double PitchY;
    /**      */
    double ResolutionX;
    /**      */
    double ResolutionY;
    /**      */
    bool Enabled;

    public:
    /** safe default contructor **/
    TrackerPlanesSensitiveLayerImpl() :	ID(0), info(""), geometry(""),
										OffsetX(0.), OffsetY(0.), OffsetZ(0.),
										DeltaRotationXY(0.), DeltaRotationZX(0.), DeltaRotationZY(0.),
										OffsetXunc(0.), OffsetYunc(0.), OffsetZunc(0.),
										DeltaRotationXYunc(0.), DeltaRotationZXunc(0.), DeltaRotationZYunc(0.),
										Flip1(1), Flip2(0), Flip3(0), Flip4(1),
										Thickness(0.), Material(""),
										NpixelX(0), NpixelY(0),
										PitchX(0.), PitchY(0.),
										ResolutionX(0.), ResolutionY(0.),
										Enabled(true)
     { ; } ;

    /// Destructor.
    virtual ~TrackerPlanesSensitiveLayerImpl() { /* nop */; }

    /**      */
    virtual int getID() const { return ID  ; }
    /**      */
    virtual std::string getInfo() const { return info ; }
    /**      */
    virtual std::string getGeometry() const { return geometry ; }
    /**      */
    virtual double getOffsetX() const { return OffsetX  ; }
    /**      */
    virtual double getOffsetY() const { return OffsetY  ; }
    /**      */
    virtual double getOffsetZ() const { return OffsetZ  ; }
    /**      */
    virtual double getDeltaRotationXY() const { return DeltaRotationXY  ; }
    /**      */
    virtual double getDeltaRotationZX() const { return DeltaRotationZX  ; }
    /**      */
    virtual double getDeltaRotationZY() const { return DeltaRotationZY  ; }
    /**      */
    virtual double getOffsetXunc() const { return OffsetXunc  ; }
    /**      */
    virtual double getOffsetYunc() const { return OffsetYunc  ; }
    /**      */
    virtual double getOffsetZunc() const { return OffsetZunc  ; }
    /**      */
    virtual double getDeltaRotationXYunc() const { return DeltaRotationXYunc  ; }
    /**      */
    virtual double getDeltaRotationZXunc() const { return DeltaRotationZXunc  ; }
    /**      */
    virtual double getDeltaRotationZYunc() const { return DeltaRotationZYunc  ; }
    /**      */
    virtual double getThickness() const { return Thickness  ; }
    /**      */
    virtual std::string getMaterial() const { return Material  ; }

    /**      */
    virtual int getNpixelX() const { return NpixelX  ; }
    /**      */
    virtual int getNpixelY() const { return NpixelY  ; }
    /**      */
    virtual double getPitchX() const { return PitchX  ; }
    /**      */
    virtual double getPitchY() const { return PitchY  ; }
	/**      */
	virtual int getFlip1() const { return Flip1 ; }
	/**      */
	virtual int getFlip2() const { return Flip2 ; }
	/**      */
	virtual int getFlip3() const { return Flip3 ; }
	/**      */
	virtual int getFlip4() const { return Flip4 ; }
	/**      */
    virtual double getResolutionX() const { return ResolutionX  ; }
    /**      */
    virtual double getResolutionY() const { return ResolutionY  ; }
    /**      */
	virtual bool getEnabled() const { return Enabled ; }

    /**      */
    virtual void setID( int value )           {  ID = value         ; }  
    /**      */
    virtual void setInfo( std::string value) { info = value ; }
    /**      */
    virtual void setGeometry( std::string value) { geometry = value ; }
    /**      */
    virtual void setMaterial( std::string value)  {  Material = value  ; }
    /**      */
    virtual void setOffsetX( double value)  {  OffsetX = value  ; }
    /**      */
    virtual void setOffsetY( double value)  {  OffsetY = value  ; }
    /**      */
    virtual void setOffsetZ( double value)  {  OffsetZ = value  ; }
    /**      */
    virtual void setDeltaRotationXY( double value) {  DeltaRotationXY = value ; }
    /**      */
    virtual void setDeltaRotationZX( double value) {  DeltaRotationZX = value ; }
    /**      */
    virtual void setDeltaRotationZY( double value) {  DeltaRotationZY = value ; }

    /**      */
    virtual void setOffsetXunc( double value)  {  OffsetXunc = value  ; }
    /**      */
    virtual void setOffsetYunc( double value)  {  OffsetYunc = value  ; }
    /**      */
    virtual void setOffsetZunc( double value)  {  OffsetZunc = value  ; }
    /**      */
    virtual void setDeltaRotationXYunc( double value) {  DeltaRotationXYunc = value ; }
    /**      */
    virtual void setDeltaRotationZXunc( double value) {  DeltaRotationZXunc = value ; }
    /**      */
    virtual void setDeltaRotationZYunc( double value) {  DeltaRotationZYunc = value ; }

    /**      */
    virtual void setThickness( double value)  {  Thickness = value  ; }
    /**      */

    /**      */
    virtual void setNpixelX( int value )        {  NpixelX = value ; }
    /**      */
    virtual void setNpixelY( double value )     {  NpixelY = value ; }
    /**      */
    virtual void setPitchX( double value )      {  PitchX  = value ; }
    /**      */
    virtual void setPitchY( double value )      {  PitchY  = value ; }


	/**      */
	virtual void setFlip1( int value ) { Flip1 = value ; }
	/**      */
	virtual void setFlip2( int value ) { Flip3 = value ; }
	/**      */
	virtual void setFlip3( int value ) { Flip2 = value ; }
	/**      */
	virtual void setFlip4( int value ) { Flip4 = value ; }

    /**      */
    virtual void setResolutionX( double value ) {  ResolutionX = value ; }
    /**      */
    virtual void setResolutionY( double value ) {  ResolutionY = value ; }
    
    /**      */
	virtual void setEnabled( bool value ) {  Enabled = value ; }

};

  typedef std::vector<TrackerPlanesMaterialLayerImpl> TrackerPlanesMaterialLayerImplVec ;
  typedef std::vector<TrackerPlanesSensitiveLayerImpl> TrackerPlanesSensitiveLayerImplVec ;


// a detector element consisting of a vector of scatterrers and sensors
class TrackerPlanesLayerImpl: public TrackerPlanesLayer  {

  private:

    /**      */
    int ID;

    /**      */
    std::string info;

//---
//-
    double PositionX ;
    double PositionY ;
    double PositionZ ;
    double RotationXY;
    double RotationZX;
    double RotationZY;
    /**      */
    double PositionXunc;
    double PositionYunc;
    double PositionZunc;
    double RotationXYunc;
    double RotationZXunc;
    double RotationZYunc;
//-
//---

    /** material Layer vector */
    TrackerPlanesMaterialLayerImplVec _materialVec ;

    /** sensitive Layer vector */
    TrackerPlanesSensitiveLayerImplVec _sensitiveVec ;

  public:

    /** default constructor */
    TrackerPlanesLayerImpl() : ID(0), info("")
    { ; };

    /** normal constructor */
    TrackerPlanesLayerImpl( TrackerPlanesMaterialLayerImplVec& materials, TrackerPlanesSensitiveLayerImplVec& sensors) : ID(0), info("")
    {
       //          
       _materialVec.clear(); 
       for(unsigned int i=0; i< materials.size(); i++){
          _materialVec.push_back( materials.at(i) );
       }
  
       //
       _sensitiveVec.clear();
       for(unsigned int i=0; i< sensors.size(); i++){
          _sensitiveVec.push_back( sensors.at(i) );
       }
    }

    /** Destructor.
     */
    virtual ~TrackerPlanesLayerImpl() { /* nop */; }

    /** get methods
     */
    virtual int getID() const { return ID; }
 
    /** get methods
     */
    virtual std::string getInfo() const { return info ; }

    /** set methods
     */
    virtual void setID(int value)  { ID = value; }

    /** get methods
     */
    virtual void setInfo( std::string value) { info = value ; }

    /** The total number of nonSense layers. */
    virtual int getNMaterialLayers() const { return _materialVec.size(); }

    /** The total number of Sensitive layers. */
    virtual int getNSensitiveLayers() const {return _sensitiveVec.size(); }

//---
//-
    virtual void setPositionX( double value)  {  PositionX = value  ; }
    virtual void setPositionY( double value)  {  PositionY = value  ; }
    virtual void setPositionZ( double value)  {  PositionZ = value  ; }
    virtual void setRotationXY( double value) {  RotationXY = value ; }
    virtual void setRotationZX( double value) {  RotationZX = value ; }
    virtual void setRotationZY( double value) {  RotationZY = value ; }
    virtual void setPositionXunc( double value)  {  PositionXunc = value  ; }
    virtual void setPositionYunc( double value)  {  PositionYunc = value  ; }
    virtual void setPositionZunc( double value)  {  PositionZunc = value  ; }
    virtual void setRotationXYunc( double value) {  RotationXYunc = value ; }
    virtual void setRotationZXunc( double value) {  RotationZXunc = value ; }
    virtual void setRotationZYunc( double value) {  RotationZYunc = value ; }
//-
    virtual double getPositionX() const { return PositionX  ; }
    virtual double getPositionY() const { return PositionY  ; }
    virtual double getPositionZ() const { return PositionZ  ; }
    virtual double getRotationXY() const { return RotationXY  ; }
    virtual double getRotationZX() const { return RotationZX  ; }
    virtual double getRotationZY() const { return RotationZY  ; }
    virtual double getPositionXunc() const { return PositionXunc  ; }
    virtual double getPositionYunc() const { return PositionYunc  ; }
    virtual double getPositionZunc() const { return PositionZunc  ; }
    virtual double getRotationXYunc() const { return RotationXYunc  ; }
    virtual double getRotationZXunc() const { return RotationZXunc  ; }
    virtual double getRotationZYunc() const { return RotationZYunc  ; }
//-
//---





    /** get methods
     */
    TrackerPlanesMaterialLayerImplVec const & getMaterialLayerVec() const { return _materialVec;}

    /** get methods
     */
    TrackerPlanesSensitiveLayerImplVec const & getSensitiveLayerVec() const { return _sensitiveVec;}

    /** add methods
     */
    virtual void addMaterialLayer(
			      int ID, std::string info,
			      double OffsetX, double OffsetY, double OffsetZ,
			      double DeltaRotationXY, double DeltaRotationZX, double DeltaRotationZY,
			      double SizeX, double SizeY, double Thickness, std::string Material
                              );
  

    /** add methods
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
                              ); 

};

/** */
typedef std::vector<TrackerPlanesLayerImpl> TrackerPlanesLayerImplVec ;

/**  a collection of layers = telescope description */
class TrackerPlanesLayerLayoutImpl : public TrackerPlanesLayerLayout {

	protected:

	  /** Layer */
	  typedef double MyMatrix[2][2];
	  
	private:

    /** */
    int ID;

	/**      */
    std::string info;

	/** Layer */
	TrackerPlanesLayerImplVec _layerVec ;

	public: 

      /** */
	  TrackerPlanesLayerLayoutImpl() {
	    _layerVec.clear();
	  };

      /** */
	  virtual void addLayer( TrackerPlanesLayerImpl* layer ){
	    _layerVec.push_back( *layer ) ;
	  }

	  /**  Destructor */
	  virtual ~TrackerPlanesLayerLayoutImpl() { /* nop */; }
		
          /** */
          virtual int getID() const { return 0; }

          /** */
          virtual void setID(int value) { ID = value; }
 
          /** */
          virtual std::string getInfo() const { return info; }
 
      /** */
      virtual void setInfo(std::string value) { info = value; }
 
	  /** */
	  virtual int getNLayers() const { 
            return _layerVec.size() ; 
          }	 


          /** */
	  virtual const TrackerPlanesLayerImpl* getLayer( unsigned int ID ) const { 

            if( ID < _layerVec.size() ) {
              return &(_layerVec.at(ID)); // return an address
            }

            return 0; 
          }

          /** */
	  virtual const TrackerPlanesLayerImpl* getLayerByID( int ID ) const { 

            for( TrackerPlanesLayerImplVec::const_iterator it = _layerVec.begin(); it != _layerVec.end(); it++ ) {  
              if( (*it).getID() == ID ) return &(*it); // return a pointer (*it) is the element of the vector
            }

            return 0; 
          }

   
/** */
	virtual void PrintHeader( std::ostream& s ) const {

		// layers    									      
		s << " Number of layers : " << getNLayers() << std::endl << std::endl ;
 		s << " layer parameters : "  << std::endl ;

      char buffer[1024] ;    
sprintf(buffer,"|------------------|------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------|\n") ;
      s << buffer ; 
sprintf(buffer,"| layer:           |                 ladder/scattering only                                       |          sensitive /       scattering part                                   `      measurement part                 |\n") ;
      s << buffer ;
sprintf(buffer,"| ID      info     | ID      info       pozX  pozY  pozZ rotXY rotZX rotZY  sizX  sizY Thick   X  | ID     info        pozX  pozY  pozZ rotXY rotZX rotZY  sizX  sizY Thick   X  `  NX    NY  PitchX PitchY   ResX   RexY| \n") ;
      s << buffer ;
sprintf(buffer,"|------------------|------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------|\n") ;
      s << buffer ;

	}
 
/** */
	virtual void PrintLayers( std::ostream& s) const {

            	char buffer[1024] ;
                const char* a=""; 

		for( TrackerPlanesLayerImplVec::const_iterator it = _layerVec.begin(); it != _layerVec.end(); it++ ) {  
			TrackerPlanesLayerImpl* layer = const_cast<TrackerPlanesLayerImpl* > (&(*it)) ;

 		sprintf(buffer,"|%3d %14s|%3s %14s %5s %5s %5s %5s %5s %5s %5s %5s %5s %5s|%3s %14s %5s %5s %5s %5s %5s %5s %5s %5s %5s %5s`%5s %5s %6s %6s %6s %6s|\n"
			, layer->getID() 
			, layer->getInfo().c_str()
                        ,  a,a ,a,a,a,a,a,a,a,a,a,a, a,a ,a,a,a,a,a,a,a,a,a,a, a,a,a,a,a,a 
		);
		s << buffer ;

                TrackerPlanesMaterialLayerImplVec::const_iterator mb = layer->getMaterialLayerVec().begin();
                TrackerPlanesMaterialLayerImplVec::const_iterator me = layer->getMaterialLayerVec().end();
                TrackerPlanesSensitiveLayerImplVec::const_iterator sb = layer->getSensitiveLayerVec().begin();
                TrackerPlanesSensitiveLayerImplVec::const_iterator se = layer->getSensitiveLayerVec().end();

                for( TrackerPlanesMaterialLayerImplVec::const_iterator ml = mb ; ml < me; ml++) {
      		  sprintf(buffer,"|%3s %14s|%3d %14s %5.0f %5.0f %5.0f %5.0f %5.0f %5.0f %5.2f %5.2f %5.2f %10s|%3s %14s %5s %5s %5s %5s %5s %5s %5s %5s %5s %5s`%5s %5s %6s %6s %6s %6s|\n"
                      , a,a
                      , (*ml).getID() 
		      , (*ml).getInfo().c_str() 
		      , (*ml).getOffsetX() 
		      , (*ml).getOffsetY() 
		      , (*ml).getOffsetZ()
		      , (*ml).getDeltaRotationXY() 
		      , (*ml).getDeltaRotationZX() 
		      , (*ml).getDeltaRotationZY()
		      , (*ml).getSizeX() 
		      , (*ml).getSizeY() 
		      , (*ml).getThickness()
 		      , (*ml).getMaterial()
	              , a,a ,a,a,a,a,a,a,a,a,a,a, a,a,a,a,a,a
 		  ); 
	   	  s << buffer ;
                }
	
                for( TrackerPlanesSensitiveLayerImplVec::const_iterator sl = sb ; sl < se; sl++) {
	sprintf(buffer,"|%3s %14s|%3s %14s %5s %5s %5s %5s %5s %5s %5s %5s %5s %5s|%3d %14s %5.0f %5.0f %5.0f %5.0f %5.0f %5.0f %5.2f %10s`%5d %5d %5.4f %5.4f %5.4f %5.4f|\n"
                      , a,a,   a,a,  a,a,  a,a,  a,a,  a,a,  a,a
 		      , (*sl).getID() 
 		      , (*sl).getInfo().c_str()
		      , (*sl).getOffsetX() 
		      , (*sl).getOffsetY() 
		      , (*sl).getOffsetZ()
		      , (*sl).getDeltaRotationXY() 
		      , (*sl).getDeltaRotationZX() 
		      , (*sl).getDeltaRotationZY()
		      , (*sl).getThickness() 
		      , (*sl).getMaterial()

		      , (*sl).getNpixelX() 
		      , (*sl).getNpixelY() 
		      , (*sl).getPitchX() 
		      , (*sl).getPitchY() 
		      , (*sl).getResolutionX()
       		      , (*sl).getResolutionY()
	);
		  s << buffer ;
                  }
                }
sprintf(buffer,"|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n") ;
      		s << buffer ;

	}
        
/** */
	virtual void PrintFooter( std::ostream& s) const {
		char buffer[1024] ;

sprintf(buffer,"|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n") ;
		s << buffer ;

	}
     


}; // class

} // namespace gear
#endif /* #ifndef GEAR_TrackerPlanesLayerLayoutImpl_H */

