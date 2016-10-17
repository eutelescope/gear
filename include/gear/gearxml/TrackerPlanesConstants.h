#ifndef GEAR_TrackerPlanesConstants_H
#define GEAR_TrackerPlanesConstants_H

/*
 *
 *	<detector>
 *	  <layers>
 *      <layer>
 *        <ladder> </ladder>
 *        <sensitive> </sensitive>
 *        ...
 *       </layer> 
 *		 <layer>
 *		  ...
 *		 </layer>
 *    </layers>
 *	</detector>
 *
 */ 


namespace gear{
	
	//detector parameters
	const char* DETECTOR_NODE_NAME = "detector";
	//layers parameters
	const char* LAYERS_NODE_NAME = "layers";
	//layer parameters
	const char* LAYER_NODE_NAME = "layer";
	
	const char* LAYER_ID = "ID";
	const char* LAYER_INFO = "info";
	const char* LAYER_POSX = "positionX";
	const char* LAYER_POSY = "positionY";
	const char* LAYER_POSZ = "positionZ";

	const char* LAYER_POSXUNC = "positionXunc";
	const char* LAYER_POSYUNC = "positionYunc";
	const char* LAYER_POSZUNC = "positionZunc";

	const char* LAYER_ROTXY = "rotationXY";
	const char* LAYER_ROTZX = "rotationZX";
	const char* LAYER_ROTZY = "rotationZY";

	const char* LAYER_ROTXYUNC = "rotationXYunc";
	const char* LAYER_ROTZXUNC = "rotationZXunc";
	const char* LAYER_ROTZYUNC = "rotationZYunc";

	//ladder parameters
	const char* LADDER_NODE_NAME = "passive";

	const char* LADDER_ID = "ID";
	const char* LADDER_INFO = "info";
	const char* LADDER_OFFX = "offsetX";
	const char* LADDER_OFFY = "offsetY";
	const char* LADDER_OFFZ = "offsetZ";

	const char* LADDER_DELTAROTXY = "deltaRotXY";
	const char* LADDER_DELTAROTZX = "deltaRotZX";
	const char* LADDER_DELTAROTZY = "deltaRotZY";
	
	const char* LADDER_MATERIAL = "material";
	const char* LADDER_THICKNESS = "thickness";
	
	const char* LADDER_SIZEX = "sizeX";
	const char* LADDER_SIZEY = "sizeY";

	//sensitive parameters
	const char* SENSITIVE_NODE_NAME = "active";

	const char* SENSITIVE_ID = "ID";
	const char* SENSITIVE_INFO = "info";
	
	const char* SENSITIVE_OFFX = "offsetX";
	const char* SENSITIVE_OFFY = "offsetY";
	const char* SENSITIVE_OFFZ = "offsetZ";

	const char* SENSITIVE_DELTAROTXY = "deltaRotXY";
	const char* SENSITIVE_DELTAROTZX = "deltaRotZX";
	const char* SENSITIVE_DELTAROTZY = "deltaRotZY";

	const char* SENSITIVE_OFFXUNC = "offsetXunc";
	const char* SENSITIVE_OFFYUNC = "offsetYunc";
	const char* SENSITIVE_OFFZUNC = "offsetZunc";

	const char* SENSITIVE_DELTAROTXYUNC = "deltaRotXYunc";
	const char* SENSITIVE_DELTAROTZXUNC = "deltaRotZXunc";
	const char* SENSITIVE_DELTAROTZYUNC = "deltaRotZYunc";
	
	const char* SENSITIVE_FLIP1 = "flip1";
	const char* SENSITIVE_FLIP2 = "flip2";
	const char* SENSITIVE_FLIP3 = "flip3";
	const char* SENSITIVE_FLIP4 = "flip4";
	
	const char* SENSITIVE_PITCHX = "pitchX";
	const char* SENSITIVE_PITCHY = "pitchY";

	const char* SENSITIVE_NPIXX = "npixelX";
	const char* SENSITIVE_NPIXY = "npixelY";

	const char* SENSITIVE_MATERIAL = "material";
	const char* SENSITIVE_THICKNESS = "thickness";

	const char* SENSITIVE_GEOMETRY = "geometry";
	const char* SENSITIVE_ENABLED = "enabled";
	
	const char* SENSITIVE_RESX = "resolutionX";
	const char* SENSITIVE_RESY = "resolutionY";

}
#endif
