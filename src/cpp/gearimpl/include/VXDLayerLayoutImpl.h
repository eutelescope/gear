// -*- C++ -*-
#ifndef GEAR_VXDLayerLayoutImpl_H
#define GEAR_VXDLayerLayoutImpl_H 1

#include "gear/VXDLayerLayout.h"
#include <vector>

namespace gear {

/** Abstract description of layers in a Vertex detector. <br>
 *  This assumes a symmetric layout of ladders, arranged in layers equidistant 
 *  to IP.  <br>
 *  The sensitive area is assumed to be inside the ladders but can be positioned independently.
 * 
 * @author R. Lippe, DESY
 * @version $Id: 
 */

class VXDLayerLayoutImpl : public VXDLayerLayout {

public: 
  
  /** Helper class for layer properties */
  struct Layer {
    int    NLadders ;
    double Phi0 ;
    double Distance ;
    double Offset ;
    double Thickness ;
    double Length ;
    double Width ;
    double RadLength ;
  } ;

  typedef std::vector<Layer> LayerVec ;

  // Destructor.
  virtual ~VXDLayerLayoutImpl() { /* nop */; }
  
  /** The total number of layers.
   */
  virtual int getNLayers() const { return _lVec.size() ; }
  
  /** The number of ladders in the layer layerIndex - layer indexing starts at 0
   *  for the layer closest to IP.
   */
  virtual int getNLadders(int layerIndex) const { return _lVec.at( layerIndex ).NLadders  ; }

  /** The angle phi0 for a straight line connecting IP and ladder perpendicular to ladder.
   *  for layerIndex - layer indexing starting at 0 for the layer closest to IP.
   */
  virtual double getPhi0(int layerIndex) const { return _lVec.at( layerIndex ).Phi0  ; }
  
  /** The radiation length in the support structure ladders of layer layerIndex - layer indexing starts at 0
   *  for the layer closest to IP.
   */
  virtual double getLadderRadLength(int layerIndex) const { return _lVec.at( layerIndex ).RadLength  ; }
  
  /** The distance of ladders in layer layerIndex from the IP - layer indexing starts at 0
   *  for the layer closest to IP.
   */
  virtual double getLadderDistance(int layerIndex) const { return _lVec.at( layerIndex ).Distance  ; }

  /** The thickness in mm of the ladders in layerIndex - layer indexing starting at 0
   *  for the layer closest to IP.
   */
  virtual double getLadderThickness(int layerIndex) const { return _lVec.at( layerIndex ).Thickness  ; }

  /** The offset of the ladder measured from space point perpendicular to z
   *  and perpendicular to connecting line IP-ladder to middle of ladder in mm 
   *  (e.g. if phi0=0 --> x)
   *  for ladder in layerIndex - layer indexing starting at 0
   *  for the layer closest to IP.
   */
  virtual double getLadderOffset(int layerIndex) const { return _lVec.at( layerIndex ).Offset  ; }

  /** The width of the ladder in layer in mm for ladders in layer layerIndex -
   *  layer indexing starting at 0 from the layer closest to IP.
   */
  virtual double getLadderWidth(int layerIndex) const { return _lVec.at( layerIndex ).Width  ; }

  /** The length of the ladder in z direction in mm for ladders in layer layerIndex -
   *  layer indexing starting at 0 from the layer closest to IP.
   */
  virtual double getLadderLength(int layerIndex) const { return _lVec.at( layerIndex ).Length  ; }
  
  /** The radiation length in sensitive volumes in layer layerIndex - layer indexing starts at 0
   *  for the layer closest to IP.
   */
  virtual double getSensitiveRadLength(int layerIndex) const { return _sVec.at( layerIndex ).RadLength  ; }

  /** The distance of sensitive area in ladders in layer layerIndex from the IP.
   */
  virtual double getSensitiveDistance(int layerIndex) const { return _sVec.at( layerIndex ).Distance  ; }

  /** The thickness in mm of the sensitive area in ladders in layer layerIndex.
   */
  virtual double getSensitiveThickness(int layerIndex) const { return _sVec.at( layerIndex ).Thickness  ; }

  /** The offset of the sensitive area in ladder measured from space point perpendicular to z
   *  and perpendicular to connecting line IP-sensArea to middle of sensitive area in mm 
   *  (e.g. if phi0=0 --> x)
   *  for the sensitive area in ladders in layerIndex
   */
  virtual double getSensitiveOffset(int layerIndex) const { return _sVec.at( layerIndex ).Offset  ; }

  /** The width of the sensitive area in ladders in layer layerIndex in mm.
   */
  virtual double getSensitiveWidth(int layerIndex) const { return _sVec.at( layerIndex ).Width  ; }

  /** The length of the sensitive area in ladders in z direction in mm for ladders in layer layerIndex.
   */
  virtual double getSensitiveLength(int layerIndex) const { return _sVec.at( layerIndex ).Length  ; }

  /** Add a new layer at the given positon
   */
  virtual void addLayer(int nLadders, double phi0, 
			// ladder
			double ladderDistance, double ladderOffset, double ladderThickness,
			double ladderLength, double ladderWidth, double ladderRadLength,
			// sensitive
			double sensitiveDistance, double sensitiveOffset, double sensitiveThickness,
			double sensitiveLength, double sensitiveWidth, double sensitiveRadLength);
 
  /** returns maximum radius for a given layer
   */
  virtual double getMaxRadius( int layerIndex , bool sensitive=false ) const ; 
  
  /** returns starting phi for first ladder in layer layerIndex (on side facing IP)
   */
  virtual double getStartInnerPhi( int layerIndex , bool sensitive=false ) const ;

  /** returns ending phi for first ladder in layer layerIndex (on side facing IP)
   */
  virtual double getEndInnerPhi( int layerIndex , bool sensitive=false ) const ;

  /** returns starting phi for first ladder in layer layerIndex (on side away from IP)
   */
  virtual double getStartOuterPhi( int layerIndex , bool sensitive=false ) const ;

  /** returns ending phi for first ladder in layer layerIndex (on side away from IP)
   */
  virtual double getEndOuterPhi( int layerIndex , bool sensitive=false ) const ;
  
  /** returns thickness as viewed under the angle phi only for the first ladder
   *  in layer layerIndex.
   *  returns -1 if phi is not covered by ladder
   */
  virtual double getThicknessForPhi( int layerIndex, double phi , bool sensitive=false ) const ;
  
  
protected:

  // Ladder
  LayerVec _lVec ;
  // Sensitive
  LayerVec _sVec ;
    
private:


}; // class
} // namespace gear
#endif /* ifndef GEAR_VXDLAYERLAYOUT_H */