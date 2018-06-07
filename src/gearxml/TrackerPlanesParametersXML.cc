#include "gearxml/TrackerPlanesParametersXML.h"

#include "gearxml/XMLHandlerMgr.h"
#include "gearxml/GearParametersXML.h"

#include "gearxml/tinyxml.h"
#include "gearimpl/TrackerPlanesParametersImpl.h"
#include "gearxml/TrackerPlanesConstants.h"

#include "gear/GearMgr.h"

#include <iostream>
#include <vector>
#include <string>

 
#include <cstring>

  /** Abstract description of layers in pixel beam telescope .
   *  This assumes a number of silicon layers, arranged perpendicular to the beam.
   *  @author I. Rubinskiy, DESY
   *  @version $Id: 
   */

namespace gear {

  TiXmlElement TrackerPlanesParametersXML::toXML( const GearParameters & parameters ) const {

    // check whether parameter is valid TrackerPlanesParameter
    const TrackerPlanesParameters* param = dynamic_cast<const TrackerPlanesParameters*> ( &parameters ) ;

    if( param == 0 ) {

      throw Exception( "TrackerPlanesParametersXML::toXML given parameters not of correct type. "
		       "needs to be gear::TrackerPlanesParameters." ) ;
    }

    // Set up Beam telescope  as Element
    TiXmlElement det(DETECTOR_NODE_NAME) ;

    TiXmlElement setup_id( "LayoutID" ) ;
    setup_id.SetAttribute("ID", param->getLayoutID()) ;
    det.InsertEndChild( setup_id ) ;


    TiXmlElement nplanes( "LayoutNumberOfLayers" ) ;
    nplanes.SetAttribute("number", param->getLayoutNumberOfLayers()) ;
    det.InsertEndChild( nplanes ) ;

    TrackerPlanesLayerLayout const & trackerplanesLayerLayout = param->getTrackerPlanesLayerLayout() ;

    TiXmlElement layers(LAYERS_NODE_NAME) ;

    for( int i=0 ; i < trackerplanesLayerLayout.getNLayers() ; i++ ) {
	  
	  TrackerPlanesLayerImpl const * layer = trackerplanesLayerLayout.getLayer(i);
      if( layer == 0 ) continue;
      
	  TiXmlElement xmlLayer(LAYER_NODE_NAME) ;

	  //The ID is not optional, we always have to set it
	  xmlLayer.SetAttribute(LAYER_ID, layer->getID());
	  //Only write values if they differ from the default, i.e. 0 in all cases for <layer> attributes
	  double posX = layer->getPositionX();
	  double posY = layer->getPositionY();
	  double posZ = layer->getPositionZ();
	  if(posX != 0) xmlLayer.SetDoubleAttribute( LAYER_POSX, posX );
	  if(posY != 0) xmlLayer.SetDoubleAttribute( LAYER_POSY, posY );
	  if(posZ != 0) xmlLayer.SetDoubleAttribute( LAYER_POSZ, posZ );
	  
	  double posXunc = layer->getPositionXunc();
	  double posYunc = layer->getPositionYunc();
	  double posZunc = layer->getPositionZunc();
	  if(posXunc != 0) xmlLayer.SetDoubleAttribute( LAYER_POSXUNC, posXunc );
	  if(posYunc != 0) xmlLayer.SetDoubleAttribute( LAYER_POSYUNC, posYunc );
	  if(posZunc != 0) xmlLayer.SetDoubleAttribute( LAYER_POSZUNC, posZunc );

	  double rotXY = layer->getRotationXY();
	  double rotZX = layer->getRotationZX();
	  double rotZY = layer->getRotationZY();
	  if(rotXY != 0) xmlLayer.SetDoubleAttribute( LAYER_ROTXY, rotXY );
	  if(rotZX != 0) xmlLayer.SetDoubleAttribute( LAYER_ROTZX, rotZX );
	  if(rotZY != 0) xmlLayer.SetDoubleAttribute( LAYER_ROTZY, rotZY );
	
	  double rotXYunc = layer->getRotationXYunc();
	  double rotZXunc = layer->getRotationZXunc();
	  double rotZYunc = layer->getRotationZYunc();
	  if(rotXYunc != 0) xmlLayer.SetDoubleAttribute( LAYER_ROTXYUNC, rotXYunc );
	  if(rotZXunc != 0) xmlLayer.SetDoubleAttribute( LAYER_ROTZXUNC, rotZXunc );
	  if(rotZYunc != 0) xmlLayer.SetDoubleAttribute( LAYER_ROTZYUNC, rotZYunc );


	  //Each <layer> can have multiple <ladder> & <sensitive> nodes
      TrackerPlanesMaterialLayerImplVec const & material = layer->getMaterialLayerVec();
      TrackerPlanesSensitiveLayerImplVec const & sensitive = layer->getSensitiveLayerVec();

      for( int i=0 ; i < material.size() ; i++ ) {
           TrackerPlanesMaterialLayerImpl const & ladder = material.at(i);

           TiXmlElement xmlLadder(LADDER_NODE_NAME ) ;

		   //ID is required
           xmlLadder.SetAttribute( LADDER_ID , ladder.getID()) ;

		   //Info string might be empty, in this case we don't set it
		   std::string const& info = ladder.getInfo();
           if(!info.empty()) xmlLadder.SetAttribute( LADDER_INFO , info ) ;

		   //Set optional parameters if they differ from their defaults
		   double offX =  ladder.getOffsetX();
		   double offY =  ladder.getOffsetY();
		   double offZ =  ladder.getOffsetZ();
           if(offX != 0) xmlLadder.SetDoubleAttribute( LADDER_OFFX, offX ) ;
           if(offY != 0) xmlLadder.SetDoubleAttribute( LADDER_OFFY, offY ) ;
           if(offZ != 0) xmlLadder.SetDoubleAttribute( LADDER_OFFZ, offZ ) ;
           
		   double dRotXY = ladder.getDeltaRotationXY();
		   double dRotZX = ladder.getDeltaRotationZX();
		   double dRotZY = ladder.getDeltaRotationZY();
		   if(dRotXY != 0) xmlLadder.SetDoubleAttribute( LADDER_DELTAROTXY, dRotXY ) ;
           if(dRotZX != 0) xmlLadder.SetDoubleAttribute( LADDER_DELTAROTZX, dRotZX ) ;
           if(dRotZY != 0) xmlLadder.SetDoubleAttribute( LADDER_DELTAROTZY, dRotZY ) ;

		   //Size, thickness and material are not optional!
           xmlLadder.SetDoubleAttribute( LADDER_SIZEX , ladder.getSizeX() ) ;
           xmlLadder.SetDoubleAttribute( LADDER_SIZEY , ladder.getSizeY() ) ;
           xmlLadder.SetDoubleAttribute( LADDER_THICKNESS , ladder.getThickness() ) ;
           xmlLadder.SetAttribute( LADDER_MATERIAL , ladder.getMaterial() ) ;
     
           xmlLayer.InsertEndChild( xmlLadder ) ;
        }
      
 
        for( int i=0 ; i < sensitive.size() ; i++ ) {
           TrackerPlanesSensitiveLayerImpl const & sensor = sensitive.at(i);
 
           TiXmlElement xmlSensor( SENSITIVE_NODE_NAME ) ;

		   //ID is required
           xmlSensor.SetAttribute( SENSITIVE_ID , sensor.getID() ) ;

		   //Info and geometry are not required
		   std::string const& info = sensor.getInfo();
		   std::string const& geometry = sensor.getGeometry();
           if(!info.empty()) xmlSensor.SetAttribute( SENSITIVE_INFO , info ) ;
           if(!geometry.empty()) xmlSensor.SetAttribute( SENSITIVE_GEOMETRY , geometry ) ;

		   //Neither any of the offsets and rotations
		   double offX =  sensor.getOffsetX();
           double offY =  sensor.getOffsetY();
           double offZ =  sensor.getOffsetZ();
           if( offX != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_OFFX , offX ) ;
           if( offY != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_OFFY , offY ) ;
           if( offZ != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_OFFZ , offZ ) ;

		   double dRotXY = sensor.getDeltaRotationXY();
		   double dRotZX = sensor.getDeltaRotationZX();
		   double dRotZY = sensor.getDeltaRotationZY();
           if( rotXY != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_DELTAROTXY , dRotXY ) ;
           if( rotZX != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_DELTAROTZX , dRotZX ) ;
           if( rotZY != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_DELTAROTZY , dRotZY ) ;

		   double offXunc =  sensor.getOffsetXunc();
           double offYunc =  sensor.getOffsetYunc();
           double offZunc =  sensor.getOffsetZunc();
           if( offXunc != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_OFFXUNC , offXunc ) ;
           if( offYunc != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_OFFYUNC , offYunc ) ;
           if( offZunc != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_OFFZUNC , offZunc ) ;

		   double dRotXYunc = sensor.getDeltaRotationXY();
		   double dRotZXunc = sensor.getDeltaRotationZX();
		   double dRotZYunc = sensor.getDeltaRotationZY();
           if( rotXYunc != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_DELTAROTXYUNC , dRotXYunc ) ;
           if( rotZXunc != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_DELTAROTZXUNC , dRotZXunc ) ;
           if( rotZYunc != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_DELTAROTZYUNC , dRotZYunc ) ;

		   //Or the flips (if they are the same as the defaults)
		   int flip1 = sensor.getFlip1();
		   int flip2 = sensor.getFlip2();
		   int flip3 = sensor.getFlip3();
		   int flip4 = sensor.getFlip4(); 
           if(flip1 != 1) xmlSensor.SetAttribute( SENSITIVE_FLIP1 , flip1 ) ;
           if(flip2 != 0) xmlSensor.SetAttribute( SENSITIVE_FLIP2 , flip2 ) ;
           if(flip3 != 0) xmlSensor.SetAttribute( SENSITIVE_FLIP3 , flip3 ) ;
           if(flip4 != 1) xmlSensor.SetAttribute( SENSITIVE_FLIP4 , flip4 ) ;

		   //Since we also allow the geometry to be either set via the geometry string or this description,
		   //these values might be optional
		   int nPixX = sensor.getNpixelX();
		   int nPixY = sensor.getNpixelY();
           if(nPixX != 0) xmlSensor.SetAttribute( SENSITIVE_NPIXX , nPixX ) ;
           if(nPixY != 0) xmlSensor.SetAttribute( SENSITIVE_NPIXY , nPixY ) ;
	
		   double pitchX = sensor.getPitchX();
		   double pitchY = sensor.getPitchY();
           if(pitchX != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_PITCHX , pitchX ) ;
           if(pitchY != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_PITCHY , pitchY ) ;

		   double resX = sensor.getResolutionX();
		   double resY = sensor.getResolutionY();
           if(resX != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_RESX , resX ) ;
           if(resY != 0) xmlSensor.SetDoubleAttribute( SENSITIVE_RESY , resY ) ;

		   //Thickness and material are not optional in order to estimate scattering
           xmlSensor.SetAttribute( SENSITIVE_MATERIAL , sensor.getMaterial() ) ;
           xmlSensor.SetDoubleAttribute( SENSITIVE_THICKNESS , sensor.getThickness() ) ;

		   //Eanabled is optional
           if(!sensor.getEnabled()) xmlSensor.SetAttribute( SENSITIVE_ENABLED, "false" ) ;
           
		   xmlLayer.InsertEndChild( xmlSensor ) ;
       }

      layers.InsertEndChild( xmlLayer ) ;
    }

	det.InsertEndChild( layers );
    // Assemble Detector
    GearParametersXML::getXMLForParameters( &det , &parameters ) ;

    return det ;

  }

  GearParameters* TrackerPlanesParametersXML::fromXML( const TiXmlElement* xmlElement, GearMgr* gearMgr) const {

    // setup ID

    const TiXmlElement* trackerplanesID = xmlElement->FirstChildElement( "LayoutID" ) ;
    int setupID = atoi( getXMLAttribute( trackerplanesID , "ID" ).c_str() ) ;

    int intType = 0;
 
    const TiXmlElement* trackerplanesNumber = xmlElement->FirstChildElement( "LayoutNumberOfLayers" ) ;
    int nplanes = atoi( getXMLAttribute( trackerplanesNumber , "number" ).c_str() ) ;


    // create TrackerPlanesParameters
    TrackerPlanesParametersImpl* trackerplanesParam = new TrackerPlanesParametersImpl( setupID, intType , nplanes) ;

    // layers
    const TiXmlNode* xmlLayers = xmlElement->FirstChildElement( LAYERS_NODE_NAME ) ;

    const TiXmlNode* xmlLayer = 0 ;
    while( ( xmlLayer = xmlLayers->IterateChildren( LAYER_NODE_NAME, xmlLayer ) ) != 0 ) {

            TrackerPlanesLayerImpl* layerImpl = new TrackerPlanesLayerImpl() ;

            int layerID = atoi( getXMLAttribute( xmlLayer, LAYER_ID ).c_str() ) ;
	    	std::string infoLayer = getOptionalXMLAttribute( xmlLayer, LAYER_INFO, "" ).c_str()  ;

		    double posX   = atof( getOptionalXMLAttribute( xmlLayer , LAYER_POSX, "0." ).c_str() ) ;
		    double posY   = atof( getOptionalXMLAttribute( xmlLayer , LAYER_POSY, "0." ).c_str() ) ;
		    double posZ   = atof( getOptionalXMLAttribute( xmlLayer , LAYER_POSZ, "0." ).c_str() ) ;
		    double rotXY  = atof( getOptionalXMLAttribute( xmlLayer , LAYER_ROTXY, "0." ).c_str() ) ;
		    double rotZX  = atof( getOptionalXMLAttribute( xmlLayer , LAYER_ROTZX, "0." ).c_str() ) ;  
		    double rotZY  = atof( getOptionalXMLAttribute( xmlLayer , LAYER_ROTZY, "0." ).c_str() ) ;

		    double posXunc   = atof( getOptionalXMLAttribute( xmlLayer , LAYER_POSXUNC, "0." ).c_str() ) ;
		    double posYunc   = atof( getOptionalXMLAttribute( xmlLayer , LAYER_POSYUNC, "0." ).c_str() ) ;
		    double posZunc   = atof( getOptionalXMLAttribute( xmlLayer , LAYER_POSZUNC, "0." ).c_str() ) ;
		    double rotXYunc  = atof( getOptionalXMLAttribute( xmlLayer , LAYER_ROTXYUNC, "0." ).c_str() ) ;
		    double rotZXunc  = atof( getOptionalXMLAttribute( xmlLayer , LAYER_ROTZXUNC, "0." ).c_str() ) ;  
		    double rotZYunc  = atof( getOptionalXMLAttribute( xmlLayer , LAYER_ROTZYUNC, "0." ).c_str() ) ;

            layerImpl->setID( layerID ) ; 
            layerImpl->setInfo( infoLayer ) ; 
            layerImpl->setPositionX( posX ) ; 
            layerImpl->setPositionY( posY ) ; 
            layerImpl->setPositionZ( posZ ) ; 
            layerImpl->setRotationXY( rotXY ) ; 
            layerImpl->setRotationZX( rotZX ) ; 
            layerImpl->setRotationZY( rotZY ) ; 

            layerImpl->setPositionXunc( posXunc ) ; 
            layerImpl->setPositionYunc( posYunc ) ; 
            layerImpl->setPositionZunc( posZunc ) ; 
            layerImpl->setRotationXYunc( rotXYunc ) ; 
            layerImpl->setRotationZXunc( rotZXunc ) ; 
            layerImpl->setRotationZYunc( rotZYunc ) ; 


            const TiXmlNode* xmlLad = 0 ;
            while( ( xmlLad = xmlLayer->IterateChildren( LADDER_NODE_NAME , xmlLad ) ) != 0 ) {

		    int lID        = atoi( getXMLAttribute( xmlLad , LADDER_ID ).c_str() ) ;
		    std::string lInfo = getOptionalXMLAttribute( xmlLad, LADDER_INFO, "" ).c_str()  ;
		    double lPosX   = atof( getOptionalXMLAttribute( xmlLad , LADDER_OFFX, "0."  ).c_str() ) ;
		    double lPosY   = atof( getOptionalXMLAttribute( xmlLad , LADDER_OFFY, "0."  ).c_str() ) ;
		    double lPosZ   = atof( getOptionalXMLAttribute( xmlLad , LADDER_OFFZ, "0."  ).c_str() ) ;
		    double lRotXY  = atof( getOptionalXMLAttribute( xmlLad , LADDER_DELTAROTXY, "0." ).c_str() ) ;
		    double lRotZX  = atof( getOptionalXMLAttribute( xmlLad , LADDER_DELTAROTZX, "0." ).c_str() ) ;  
		    double lRotZY  = atof( getOptionalXMLAttribute( xmlLad , LADDER_DELTAROTZY, "0." ).c_str() ) ;
		    double lSizX   = atof( getXMLAttribute( xmlLad , LADDER_SIZEX ).c_str() ) ;
		    double lSizY   = atof( getXMLAttribute( xmlLad , LADDER_SIZEY ).c_str() ) ;
		    double lThick  = atof( getXMLAttribute( xmlLad , LADDER_THICKNESS ).c_str() ) ;
		    std::string lMat = getXMLAttribute( xmlLad , LADDER_MATERIAL ).c_str()  ;

         	    layerImpl->addMaterialLayer( lID, lInfo, lPosX, lPosY, lPosZ, lRotXY, lRotZX, lRotZY, lSizX, lSizY, lThick, lMat);                  
	    }

            const TiXmlNode* xmlSen = 0 ;
            while( ( xmlSen = xmlLayer->IterateChildren( SENSITIVE_NODE_NAME , xmlSen ) ) != 0 ) {

		    int sID        = atoi( getXMLAttribute( xmlSen , SENSITIVE_ID ).c_str() ) ;
		    std::string sInfo = getOptionalXMLAttribute( xmlSen, SENSITIVE_INFO, "" ).c_str()  ;
		    std::string sGeometry = getOptionalXMLAttribute( xmlSen, SENSITIVE_GEOMETRY, "" ).c_str()  ;

		    double sPosX   = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_OFFX, "0." ).c_str() ) ;
		    double sPosY   = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_OFFY, "0." ).c_str() ) ;
		    double sPosZ   = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_OFFZ, "0." ).c_str() ) ;
		    double sRotXY  = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_DELTAROTXY, "0." ).c_str() ) ;
		    double sRotZX  = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_DELTAROTZX, "0." ).c_str() ) ;  
		    double sRotZY  = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_DELTAROTZY, "0." ).c_str() ) ;

		    double sPosXunc   = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_OFFX, "0." ).c_str() ) ;
		    double sPosYunc   = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_OFFY, "0." ).c_str() ) ;
		    double sPosZunc   = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_OFFZ, "0." ).c_str() ) ;
		    double sRotXYunc  = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_DELTAROTXYUNC, "0." ).c_str() ) ;
		    double sRotZXunc  = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_DELTAROTZXUNC, "0." ).c_str() ) ;  
		    double sRotZYunc  = atof( getOptionalXMLAttribute( xmlSen , SENSITIVE_DELTAROTZYUNC, "0." ).c_str() ) ;

		    int flip1  = atoi(getOptionalXMLAttribute( xmlSen , SENSITIVE_FLIP1, "1" ).c_str() ) ;
		    int flip2  = atoi(getOptionalXMLAttribute( xmlSen , SENSITIVE_FLIP2, "0" ).c_str() ) ;
		    int flip3  = atoi(getOptionalXMLAttribute( xmlSen , SENSITIVE_FLIP3, "0" ).c_str() ) ;
		    int flip4  = atoi(getOptionalXMLAttribute( xmlSen , SENSITIVE_FLIP4, "1" ).c_str() ) ;

		    double sThick  = atof( getXMLAttribute( xmlSen , SENSITIVE_THICKNESS ).c_str() ) ;
		    std::string sMat = getXMLAttribute( xmlSen , SENSITIVE_MATERIAL ).c_str() ;

		    int sNPixX     = atoi(getOptionalXMLAttribute( xmlSen , SENSITIVE_NPIXX, "0" ).c_str() ) ;
		    int sNPixY     = atoi(getOptionalXMLAttribute( xmlSen , SENSITIVE_NPIXY, "0" ).c_str() ) ;
		    double sPitX   = atof(getOptionalXMLAttribute( xmlSen , SENSITIVE_PITCHX, "0." ).c_str() ) ;
		    double sPitY   = atof(getOptionalXMLAttribute( xmlSen , SENSITIVE_PITCHY, "0." ).c_str() ) ;
		    double sResolX = atof(getOptionalXMLAttribute( xmlSen , SENSITIVE_RESX, "0." ).c_str() ) ;
		    double sResolY = atof(getOptionalXMLAttribute( xmlSen , SENSITIVE_RESY, "0." ).c_str() ) ;

		    std::string sEnabled = getOptionalXMLAttribute( xmlSen, SENSITIVE_ENABLED, "" ).c_str()  ;

			bool bEnabled = true;

			if(sEnabled.compare("False") || sEnabled.compare("false") || sEnabled.compare("0")){
				bEnabled = false;
			}

	       	    layerImpl->addSensitiveLayer(	sID, sInfo, sGeometry,
												sPosX, sPosY, sPosZ, sRotXY, sRotZX, sRotZY, 
												sPosXunc, sPosYunc, sPosZunc, sRotXYunc, sRotZXunc, sRotZYunc,
												flip1, flip2, flip3, flip4,
												sThick, sMat, sNPixX, sNPixY, 
												sPitX, sPitY, sResolX, sResolY,
												bEnabled ); 
	    }  

            trackerplanesParam->addLayer( layerImpl ) ; // ? many scattering ladders and multi sensitive scructure -> double layer?

    } // end loop

    // now read the generic parameters
    GearParametersXML::setParametersFromXML( xmlElement, trackerplanesParam  ) ;
    
    // ------- add to GearMgr ----
    if( gearMgr != 0 ) {
      
      gearMgr->setTrackerPlanesParameters( trackerplanesParam ) ;

    }

    return trackerplanesParam ;

  } // fromXML

} // namespace
  
    
