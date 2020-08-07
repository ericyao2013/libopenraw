/* -*- mode:c++; tab-width:4; c-basic-offset:4; indent-tabs-mode:t; -*- */
/*
 * libopenraw - exif.h
 *
 * Copyright (C) 2007-2020 Hubert Figuière
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */


#ifndef INCLUDE_EXIF_
#error Cannot include exif.h directly
#endif

#ifdef __cplusplus
extern "C" {
#endif


/** IFD Exif Tag
 * Taken from libexif
 */
typedef	enum {
	EXIF_TAG_INTEROPERABILITY_INDEX		= 0x0001,
	EXIF_TAG_INTEROPERABILITY_VERSION	= 0x0002,
	EXIF_TAG_NEW_SUBFILE_TYPE		= 0x00fe,
	EXIF_TAG_IMAGE_WIDTH 			= 0x0100,
	EXIF_TAG_IMAGE_LENGTH 			= 0x0101,
	EXIF_TAG_BITS_PER_SAMPLE 		= 0x0102,
	EXIF_TAG_COMPRESSION 			= 0x0103,
	EXIF_TAG_PHOTOMETRIC_INTERPRETATION 	= 0x0106,
	EXIF_TAG_FILL_ORDER 			= 0x010a,
	EXIF_TAG_DOCUMENT_NAME 			= 0x010d,
	EXIF_TAG_IMAGE_DESCRIPTION 		= 0x010e,
	EXIF_TAG_MAKE 				= 0x010f,
	EXIF_TAG_MODEL 				= 0x0110,
	EXIF_TAG_STRIP_OFFSETS 			= 0x0111,
	EXIF_TAG_ORIENTATION 			= 0x0112,
	EXIF_TAG_SAMPLES_PER_PIXEL 		= 0x0115,
	EXIF_TAG_ROWS_PER_STRIP 		= 0x0116,
	EXIF_TAG_STRIP_BYTE_COUNTS		= 0x0117,
	EXIF_TAG_X_RESOLUTION 			= 0x011a,
	EXIF_TAG_Y_RESOLUTION 			= 0x011b,
	EXIF_TAG_PLANAR_CONFIGURATION 		= 0x011c,
	EXIF_TAG_RESOLUTION_UNIT 		= 0x0128,
	EXIF_TAG_TRANSFER_FUNCTION 		= 0x012d,
	EXIF_TAG_SOFTWARE 			= 0x0131,
	EXIF_TAG_DATE_TIME			= 0x0132,
	EXIF_TAG_ARTIST				= 0x013b,
	EXIF_TAG_WHITE_POINT			= 0x013e,
	EXIF_TAG_PRIMARY_CHROMATICITIES		= 0x013f,
	TIFF_TAG_TILE_WIDTH         = 0x0142,
	TIFF_TAG_TILE_LENGTH        = 0x0143,
	TIFF_TAG_TILE_OFFSETS       = 0x0144,
	TIFF_TAG_TILE_BYTECOUNTS    = 0x0145,
	EXIF_TAG_TRANSFER_RANGE			= 0x0156,
	EXIF_TAG_SUB_IFDS			= 0x014a,
	EXIF_TAG_JPEG_PROC			= 0x0200,
	EXIF_TAG_JPEG_INTERCHANGE_FORMAT	= 0x0201,
	EXIF_TAG_JPEG_INTERCHANGE_FORMAT_LENGTH	= 0x0202,
	EXIF_TAG_YCBCR_COEFFICIENTS		= 0x0211,
	EXIF_TAG_YCBCR_SUB_SAMPLING		= 0x0212,
	EXIF_TAG_YCBCR_POSITIONING		= 0x0213,
	EXIF_TAG_REFERENCE_BLACK_WHITE		= 0x0214,
	EXIF_TAG_XML_PACKET			= 0x02bc,
	EXIF_TAG_RELATED_IMAGE_FILE_FORMAT	= 0x1000,
	EXIF_TAG_RELATED_IMAGE_WIDTH		= 0x1001,
	EXIF_TAG_RELATED_IMAGE_LENGTH		= 0x1002,
	EXIF_TAG_CFA_REPEAT_PATTERN_DIM		= 0x828d,
	EXIF_TAG_CFA_PATTERN			= 0x828e,
	EXIF_TAG_BATTERY_LEVEL			= 0x828f,
	EXIF_TAG_COPYRIGHT			= 0x8298,
	EXIF_TAG_EXPOSURE_TIME			= 0x829a,
	EXIF_TAG_FNUMBER			= 0x829d,
	EXIF_TAG_IPTC_NAA			= 0x83bb,
	EXIF_TAG_IMAGE_RESOURCES		= 0x8649,
	EXIF_TAG_EXIF_IFD_POINTER		= 0x8769,
	EXIF_TAG_INTER_COLOR_PROFILE		= 0x8773,
	EXIF_TAG_EXPOSURE_PROGRAM		= 0x8822,
	EXIF_TAG_SPECTRAL_SENSITIVITY		= 0x8824,
	EXIF_TAG_GPS_INFO_IFD_POINTER		= 0x8825,
	EXIF_TAG_ISO_SPEED_RATINGS		= 0x8827,
	EXIF_TAG_OECF				= 0x8828,
	EXIF_TAG_EXIF_VERSION			= 0x9000,
	EXIF_TAG_DATE_TIME_ORIGINAL		= 0x9003,
	EXIF_TAG_DATE_TIME_DIGITIZED		= 0x9004,
	EXIF_TAG_COMPONENTS_CONFIGURATION	= 0x9101,
	EXIF_TAG_COMPRESSED_BITS_PER_PIXEL	= 0x9102,
	EXIF_TAG_SHUTTER_SPEED_VALUE		= 0x9201,
	EXIF_TAG_APERTURE_VALUE			= 0x9202,
	EXIF_TAG_BRIGHTNESS_VALUE		= 0x9203,
	EXIF_TAG_EXPOSURE_BIAS_VALUE		= 0x9204,
	EXIF_TAG_MAX_APERTURE_VALUE		= 0x9205,
	EXIF_TAG_SUBJECT_DISTANCE		= 0x9206,
	EXIF_TAG_METERING_MODE			= 0x9207,
	EXIF_TAG_LIGHT_SOURCE			= 0x9208,
	EXIF_TAG_FLASH				= 0x9209,
	EXIF_TAG_FOCAL_LENGTH			= 0x920a,
	EXIF_TAG_SUBJECT_AREA			= 0x9214,
	EXIF_TAG_TIFF_EP_STANDARD_ID		= 0x9216,
	EXIF_TAG_MAKER_NOTE			= 0x927c,
	EXIF_TAG_USER_COMMENT			= 0x9286,
	EXIF_TAG_SUB_SEC_TIME			= 0x9290,
	EXIF_TAG_SUB_SEC_TIME_ORIGINAL		= 0x9291,
	EXIF_TAG_SUB_SEC_TIME_DIGITIZED		= 0x9292,
	EXIF_TAG_FLASH_PIX_VERSION		= 0xa000,
	EXIF_TAG_COLOR_SPACE			= 0xa001,
	EXIF_TAG_PIXEL_X_DIMENSION		= 0xa002,
	EXIF_TAG_PIXEL_Y_DIMENSION		= 0xa003,
	EXIF_TAG_RELATED_SOUND_FILE		= 0xa004,
	EXIF_TAG_INTEROPERABILITY_IFD_POINTER	= 0xa005,
	EXIF_TAG_FLASH_ENERGY			= 0xa20b,
	EXIF_TAG_SPATIAL_FREQUENCY_RESPONSE	= 0xa20c,
	EXIF_TAG_FOCAL_PLANE_X_RESOLUTION	= 0xa20e,
	EXIF_TAG_FOCAL_PLANE_Y_RESOLUTION	= 0xa20f,
	EXIF_TAG_FOCAL_PLANE_RESOLUTION_UNIT	= 0xa210,
	EXIF_TAG_SUBJECT_LOCATION		= 0xa214,
	EXIF_TAG_EXPOSURE_INDEX			= 0xa215,
	EXIF_TAG_SENSING_METHOD			= 0xa217,
	EXIF_TAG_FILE_SOURCE			= 0xa300,
	EXIF_TAG_SCENE_TYPE			= 0xa301,
	EXIF_TAG_NEW_CFA_PATTERN		= 0xa302,
	EXIF_TAG_CUSTOM_RENDERED		= 0xa401,
	EXIF_TAG_EXPOSURE_MODE			= 0xa402,
	EXIF_TAG_WHITE_BALANCE			= 0xa403,
	EXIF_TAG_DIGITAL_ZOOM_RATIO		= 0xa404,
	EXIF_TAG_FOCAL_LENGTH_IN_35MM_FILM	= 0xa405,
	EXIF_TAG_SCENE_CAPTURE_TYPE		= 0xa406,
	EXIF_TAG_GAIN_CONTROL			= 0xa407,
	EXIF_TAG_CONTRAST			= 0xa408,
	EXIF_TAG_SATURATION			= 0xa409,
	EXIF_TAG_SHARPNESS			= 0xa40a,
	EXIF_TAG_DEVICE_SETTING_DESCRIPTION	= 0xa40b,
	EXIF_TAG_SUBJECT_DISTANCE_RANGE		= 0xa40c,
	EXIF_TAG_IMAGE_UNIQUE_ID		= 0xa420,
	EXIF_TAG_GAMMA                          = 0xa500,
	EXIF_TAG_UNKNOWN_C4A5                   = 0xc4a5,
	/* DNG tags */
	TIFF_TAG_DNG_VERSION                     = 0xc612,
	DNG_TAG_UNIQUE_CAMERA_MODEL              = 0xc614,
	DNG_TAG_DEFAULT_CROP_ORIGIN              = 0xc61f,
	DNG_TAG_DEFAULT_CROP_SIZE                = 0xc620,
	DNG_TAG_COLORMATRIX1                     = 0xc621,
	DNG_TAG_COLORMATRIX2                     = 0xc622,
	DNG_TAG_CAMERA_CALIBRATION1              = 0xc623,
	DNG_TAG_CAMERA_CALIBRATION2              = 0xc624,
	DNG_TAG_REDUCTION_MATRIX1                = 0xc625,
	DNG_TAG_REDUCTION_MATRIX2		 = 0xc626,
	DNG_TAG_ANALOG_BALANCE			 = 0xc627,
	DNG_TAG_AS_SHOT_NEUTRAL			 = 0xc628,
	DNG_TAG_AS_SHOT_WHITE_XY		 = 0xc629,
	DNG_TAG_CALIBRATION_ILLUMINANT1		 = 0xc65a,
	DNG_TAG_CALIBRATION_ILLUMINANT2          = 0xc65b,
	DNG_TAG_ACTIVE_AREA                      = 0xc68d,

	/* ERF tags */
	ERF_TAG_PREVIEW_IMAGE = 0x280,

	/* ORF tags */
	ORF_TAG_THUMBNAIL_IMAGE = 0x100,
	ORF_TAG_CAMERA_SETTINGS = 0x2020,
	/* Camera Settings */
	ORF_TAG_CS_PREVIEW_IMAGE_VALID = 0x100,
	ORF_TAG_CS_PREVIEW_IMAGE_START = 0x101,
	ORF_TAG_CS_PREVIEW_IMAGE_LENGTH = 0x102,

	/* CR2 tags */
	CR2_TAG_c5d9 = 0xc5d9,
	CR2_TAG_SLICE = 0xc640,    /**< Exif tag for CR2 RAW "slices" */
	CR2_TAG_SRAW_TYPE = 0xc6c5,
	CR2_TAG_c6d6 = 0xc6d6,

	/* RW2 tags */
	RW2_TAG_SENSOR_WIDTH = 0x0002,
	RW2_TAG_SENSOR_HEIGHT = 0x0003,
	RW2_TAG_SENSOR_TOPBORDER = 0x0004,
	RW2_TAG_SENSOR_LEFTBORDER = 0x0005,
	RW2_TAG_IMAGE_HEIGHT = 0x0006,
	RW2_TAG_IMAGE_WIDTH = 0x0007,
	RW2_TAG_JPEG_FROM_RAW = 0x002e,
	RW2_TAG_STRIP_OFFSETS = 0x0118,

	/* Pentax MakerNote tags */
	MNOTE_PENTAX_PREVIEW_IMAGE_SIZE = 0x02,
	MNOTE_PENTAX_PREVIEW_IMAGE_LENGTH = 0x03,
	MNOTE_PENTAX_PREVIEW_IMAGE_START = 0x04,

	/* Canon MakerNote tags */
	MNOTE_CANON_MODEL_ID = 0x0010,
	MNOTE_CANON_RAW_DATA_OFFSET = 0x0081,
	MNOTE_CANON_RAW_DATA_LENGTH = 0x0082,
	MNOTE_CANON_SENSORINFO = 0x00e0,

	/* Leica MakerNote tags */
	MNOTE_LEICA_PREVIEW_IMAGE = 0x300,

	/* Nikon MakerNote tags */
	MNOTE_NIKON_QUALITY = 0x04,
	MNOTE_NIKON_PREVIEW_IFD = 0x11,
	MNOTE_NIKON_NEFDECODETABLE2 = 0x96,

	/* Nikon MakerNote Preview IFD tags */
	MNOTE_NIKON_PREVIEWIFD_START = 0x201,
	MNOTE_NIKON_PREVIEWIFD_LENGTH = 0x202,

	_EXIF_TAG_LAST
} ExifTag;

typedef enum {
	EV_PI_BLACKISZERO = 1,
	EV_PI_RGB = 2,
	EV_PI_YCBCR = 6,

	/* RAW only */
	EV_PI_CFA = 32803,
	EV_PI_LINEAR_RAW = 34892
} ExifPhotometricInterpretation;

typedef enum {
	EV_LIGHTSOURCE_UNKNOWN     = 0,
	EV_LIGHTSOURCE_DAYLIGHT    = 1,
	EV_LIGHTSOURCE_FLUORESCENT = 2,
	EV_LIGHTSOURCE_TUNGSTEN    = 3,
	EV_LIGHTSOURCE_STANDARD_A  = 17,
	EV_LIGHTSOURCE_STANDARD_B  = 18,
	EV_LIGHTSOURCE_STANDARD_C  = 19,
	EV_LIGHTSOURCE_D55         = 20,
	EV_LIGHTSOURCE_D65         = 21,
	EV_LIGHTSOURCE_D75         = 22,
	/* 23...254 reserved */
	EV_LIGHTSOURCE_OTHER       = 255
} ExifLightsourceValue;

/** type for Exif field/tag
    taken from libexif
*/
typedef enum {
    EXIF_FORMAT_BYTE       =  1,
    EXIF_FORMAT_ASCII      =  2,
    EXIF_FORMAT_SHORT      =  3,
    EXIF_FORMAT_LONG       =  4,
    EXIF_FORMAT_RATIONAL   =  5,
    EXIF_FORMAT_SBYTE      =  6,
    EXIF_FORMAT_UNDEFINED  =  7,
    EXIF_FORMAT_SSHORT     =  8,
    EXIF_FORMAT_SLONG      =  9,
    EXIF_FORMAT_SRATIONAL  = 10,
    EXIF_FORMAT_FLOAT      = 11,
    EXIF_FORMAT_DOUBLE     = 12
} ExifTagType;


#ifdef __cplusplus
}
#endif

