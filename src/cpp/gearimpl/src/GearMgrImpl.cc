
#include "gearimpl/GearMgrImpl.h"
#include "gearimpl/GearParametersImpl.h"
#include "gear/CalorimeterParameters.h"
#include "gear/VXDParameters.h"
#include "gear/SiPlanesParameters.h"
#include "gear/GearPointProperties.h"
#include "gear/GearDistanceProperties.h"
#include "gear/BField.h"

namespace gear{


  GearMgrImpl::GearMgrImpl() :
    _tpcParameters(0) ,
    _ecalBarrelParameters(0) ,
    _ecalEndcapParameters(0) ,
    _ecalPlugParameters(0) ,
    _hcalBarrelParameters(0) ,
    _hcalEndcapParameters(0) ,
    _hcalRingParameters(0) ,
    _lcalParameters(0) ,
    _vxdParameters(0) ,
    _siplanesParameters(0) ,
    _pointProperties(0) ,
    _distanceProperties(0) ,
    _bField(0),
    _detectorName("Unknwon"){
  }
  
  GearMgrImpl::~GearMgrImpl() {
    
    // clean up all parameters
    if( _tpcParameters ) delete _tpcParameters ;
    if( _ecalBarrelParameters ) delete _ecalBarrelParameters ;
    if( _ecalEndcapParameters ) delete _ecalEndcapParameters ;
    if( _ecalPlugParameters ) delete _ecalPlugParameters ;
    if( _hcalBarrelParameters ) delete _hcalBarrelParameters ;
    if( _hcalEndcapParameters ) delete _hcalEndcapParameters ;
    if( _hcalRingParameters ) delete _hcalRingParameters ;
    if( _lcalParameters ) delete  _lcalParameters;
    if( _vxdParameters ) delete _vxdParameters ;
    if( _siplanesParameters ) delete _siplanesParameters ;
    if( _pointProperties ) delete _pointProperties ;
    if( _distanceProperties ) delete _distanceProperties ;
    if( _bField  ) delete  _bField ;
    
    
    ParameterMap::iterator it_end = _map.end() ;

    for( ParameterMap::iterator it = _map.begin() ; it != it_end ; ++ it ) {
      delete it->second ;
    }
    
  }
  

  const GearParameters & GearMgrImpl::getGearParameters(const std::string & key) const 
    
    throw (UnknownParameterException, std::exception ) {
    
    ParameterMap::const_iterator it = _map.find( key ) ;
    if( it == _map.end() || it->second == 0 )
      throw UnknownParameterException( "No parameters set for : " + key ) ;
    return * it->second ;
    
  }   
  
  const TPCParameters & GearMgrImpl::getTPCParameters() const
    throw (UnknownParameterException, std::exception ) {
    
    if( _tpcParameters == 0 )
      throw UnknownParameterException( "No TPCParameters set ") ;

    return  *_tpcParameters ;

  }


  const BField & GearMgrImpl::getBField() const
    throw (UnknownParameterException, std::exception ) {
    
    if( _bField == 0 )
      throw UnknownParameterException( "No BField set ") ;

    return  *_bField ;

  }

  const CalorimeterParameters & GearMgrImpl::getEcalBarrelParameters() const
    throw (UnknownParameterException, std::exception ) {
    
    if( _ecalBarrelParameters == 0 )
      throw UnknownParameterException( "No EcalBarrelParameters set ") ;

    return  *_ecalBarrelParameters ;

  }
  const CalorimeterParameters & GearMgrImpl::getEcalEndcapParameters() const
    throw (UnknownParameterException, std::exception ) {
    
    if( _ecalEndcapParameters == 0 )
      throw UnknownParameterException( "No EcalEndcapParameters set ") ;

    return  *_ecalEndcapParameters ;

  }
  
  const CalorimeterParameters & GearMgrImpl::getEcalPlugParameters() const
    throw (UnknownParameterException, std::exception ) {
    
    if( _ecalPlugParameters == 0 )
      throw UnknownParameterException( "No EcalPlugParameters set ") ;

    return  *_ecalPlugParameters ;

  }

  const CalorimeterParameters & GearMgrImpl::getHcalBarrelParameters() const
    throw (UnknownParameterException, std::exception ) {
    
    if( _hcalBarrelParameters == 0 )
      throw UnknownParameterException( "No HcalBarrelParameters set ") ;

    return  *_hcalBarrelParameters ;

  }
  const CalorimeterParameters & GearMgrImpl::getHcalEndcapParameters() const
    throw (UnknownParameterException, std::exception ) {
    
    if( _hcalEndcapParameters == 0 )
      throw UnknownParameterException( "No HcalEndcapParameters set ") ;

    return  *_hcalEndcapParameters ;

  }

  const CalorimeterParameters & GearMgrImpl::getHcalRingParameters() const
    throw (UnknownParameterException, std::exception ) {
    
    if( _hcalRingParameters == 0 )
      throw UnknownParameterException( "No HcalRingParameters set ") ;

    return  *_hcalRingParameters ;

  }


  const CalorimeterParameters & GearMgrImpl::getLcalParameters() const
    throw (UnknownParameterException, std::exception ) {
    
    if( _lcalParameters == 0 )
      throw UnknownParameterException( "No LcalParameters set ") ;

    return  *_lcalParameters ;

  }

  const VXDParameters & GearMgrImpl::getVXDParameters() const
    throw (UnknownParameterException, std::exception ) {

    if( _vxdParameters == 0 )
      throw UnknownParameterException( "No VXDParameters set ") ;

    return *_vxdParameters ;

  }

  const SiPlanesParameters & GearMgrImpl::getSiPlanesParameters() const
    throw (UnknownParameterException, std::exception ) {

    if( _siplanesParameters == 0 )
      throw UnknownParameterException( "No SiPlanesParameters set ") ;

    return *_siplanesParameters ;

  }
  
  const GearPointProperties & GearMgrImpl::getPointProperties() const 
    throw (NotImplementedException, std::exception ) {

    if( _pointProperties == 0 )
      throw UnknownParameterException( "No PointProperties set or implemented ") ;
    
    return  *_pointProperties ;
  }
  
  
  
  const GearDistanceProperties & GearMgrImpl::getDistanceProperties() const 
    throw (NotImplementedException, std::exception ) {

    if( _distanceProperties == 0 )
      throw UnknownParameterException( "No DistanceProperties set or implemented ") ;
    
    return  *_distanceProperties ;

  }

  void GearMgrImpl::setGearParameters( const std::string & key, GearParameters* parameters ) {

    if( parameters == 0 )   // don't allow  null pointers 
      return  ;    
    
    ParameterMap::iterator it = _map.find( key ) ;

    if( it != _map.end() ) {
      
      delete it->second ;
      it->second = parameters ;
      
    } else {
      
      _map[ key ] = parameters ; 
      
    }
    
    
  }
  
  void GearMgrImpl::setTPCParameters( TPCParameters* tpcParameters ) {
    
    if(  _tpcParameters ) 
      delete _tpcParameters ;

    _tpcParameters = tpcParameters ;
  }

  void GearMgrImpl::setBField( BField* b){
    
    _bField = b ;
  }

  void GearMgrImpl::setEcalBarrelParameters( CalorimeterParameters* ecalBarrelParameters ) {
    
    _ecalBarrelParameters = ecalBarrelParameters ;
  }
  void GearMgrImpl::setEcalEndcapParameters( CalorimeterParameters* ecalEndcapParameters ) {
    
    _ecalEndcapParameters = ecalEndcapParameters ;
  }

  void GearMgrImpl::setEcalPlugParameters( CalorimeterParameters* ecalPlugParameters ) {
    
    _ecalPlugParameters = ecalPlugParameters ;
  }


  void GearMgrImpl::setHcalBarrelParameters( CalorimeterParameters* hcalBarrelParameters ) {
    
    _hcalBarrelParameters = hcalBarrelParameters ;
  }

  void GearMgrImpl::setHcalEndcapParameters( CalorimeterParameters* hcalEndcapParameters ) {

    _hcalEndcapParameters = hcalEndcapParameters ;
  }

  void GearMgrImpl::setHcalRingParameters( CalorimeterParameters* hcalRingParameters ) {

    _hcalRingParameters = hcalRingParameters ;
  }

  void GearMgrImpl::setLcalParameters( CalorimeterParameters* lcalParameters ) {

    try {

      lcalParameters->getDoubleVal("beam_crossing_angle") ;

    }catch( UnknownParameterException ){

      std::cout << "WARNING GearMgrImpl::setLcalParameters: added "
	" missing parameter beam_crossing_angle 0.0 ! " << std::endl ;
      
      GearParametersImpl* gp 
	= dynamic_cast<GearParametersImpl*>(lcalParameters) ;

      if( gp ) 
	gp->setDoubleVal("beam_crossing_angle", 0.0 ) ;

    }
    _lcalParameters = lcalParameters ;
  }

  void GearMgrImpl::setVXDParameters( VXDParameters* vxdParameters ) {

    _vxdParameters = vxdParameters ;
  }

  void GearMgrImpl::setSiPlanesParameters( SiPlanesParameters* siplanesParameters ) {

    _siplanesParameters = siplanesParameters ;
  }

  void GearMgrImpl::setPointProperties( GearPointProperties* pointProperties) {
    
    _pointProperties = pointProperties ;
  }

  void GearMgrImpl::setDistanceProperties( GearDistanceProperties* distanceProperties) {
 
   _distanceProperties = distanceProperties ;
  }
  
  const std::vector<std::string>& GearMgrImpl::getGearParameterKeys() const {

    _keys.clear() ;
    _keys.reserve( _map.size() ) ;

    for( ParameterMap::const_iterator it = _map.begin() ; it != _map.end() ; ++it ){
      _keys.push_back( it->first ) ;
    }
    return _keys ;
  }

}
