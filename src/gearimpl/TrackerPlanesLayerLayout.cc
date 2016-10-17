#include "gearimpl/TrackerPlanesLayerLayoutImpl.h"
#include <math.h>

/** Abstract description of layers in pixel beam telescope with or without DUT.
   *  This assumes a number of silicon layers, arranged perpendicular to the beam.
   *  @author I. Rubinskiy, DESY
   *  @version $Id: 
   */

namespace gear{

  void TrackerPlanesLayerImpl::addMaterialLayer(
			      // layer
			      int ID, std::string info,
			      double OffsetX, double OffsetY, double OffsetZ,
			      double DeltaRotationXY, double DeltaRotationZX, double DeltaRotationZY,
			      double SizeX, double SizeY, double Thickness, std::string Material 
                              )
  {

    TrackerPlanesMaterialLayerImpl lL ;
    lL.setID         ( ID        );
    lL.setInfo       ( info      );
    lL.setOffsetX  ( OffsetX );
    lL.setOffsetY  ( OffsetY );
    lL.setOffsetZ  ( OffsetZ );
    lL.setDeltaRotationXY ( DeltaRotationXY);
    lL.setDeltaRotationZX ( DeltaRotationZX);
    lL.setDeltaRotationZY ( DeltaRotationZY);
    lL.setSizeX      ( SizeX     );
    lL.setSizeY      ( SizeY     );
    lL.setThickness  ( Thickness );
    lL.setMaterial  ( Material );
 
    _materialVec.push_back( lL ) ;
  }

  void TrackerPlanesLayerImpl::addSensitiveLayer(
			      int ID, std::string info, std::string geometry,
			      double OffsetX, double OffsetY, double OffsetZ,
			      double DeltaRotationXY, double DeltaRotationZX, double DeltaRotationZY,
			      double OffsetXunc, double OffsetYunc, double OffsetZunc,
			      double DeltaRotationXYunc, double DeltaRotationZXunc, double DeltaRotationZYunc,
				  int Flip1, int Flip2, int Flip3, int Flip4,
			      double Thickness, std::string Material,
			      int NpixelX, int NpixelY, double PitchX,double PitchY, 
				  double ResolutionX, double ResolutionY, bool Enabled
                              )
  {

    TrackerPlanesSensitiveLayerImpl sL ;
    sL.setID         ( ID        );
    sL.setInfo       ( info      );
    sL.setGeometry   ( geometry  );
    sL.setOffsetX  ( OffsetX );
    sL.setOffsetY  ( OffsetY );
    sL.setOffsetZ  ( OffsetZ );
    sL.setDeltaRotationXY ( DeltaRotationXY);
    sL.setDeltaRotationZX ( DeltaRotationZX);
	sL.setDeltaRotationZY ( DeltaRotationZY);
    sL.setOffsetXunc	( OffsetXunc );
    sL.setOffsetYunc	( OffsetYunc );
    sL.setOffsetZunc	( OffsetZunc );
    sL.setDeltaRotationXYunc	( DeltaRotationXYunc);
    sL.setDeltaRotationZXunc ( DeltaRotationZXunc);
    sL.setDeltaRotationZYunc	( DeltaRotationZYunc);
    sL.setFlip1		 ( Flip1	 );
    sL.setFlip2		 ( Flip2	 );
    sL.setFlip3		 ( Flip3	 );
    sL.setFlip4		 ( Flip4	 );
    sL.setThickness  ( Thickness );
    sL.setMaterial  ( Material );
    sL.setNpixelX    ( NpixelX   );
    sL.setNpixelY    ( NpixelY   );
    sL.setPitchX     ( PitchX    );
    sL.setPitchY     ( PitchY    );
    sL.setResolutionX ( ResolutionX );
    sL.setResolutionY ( ResolutionX );
    sL.setEnabled     ( Enabled     );

    _sensitiveVec.push_back( sL ) ;

  }

} //namespace
