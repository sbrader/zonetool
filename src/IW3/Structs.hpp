// ======================= ZoneTool =======================
// zonetool, a fastfile linker for various
// Call of Duty titles. 
//
// Project: https://github.com/ZoneTool/zonetool
// Author: RektInator (https://github.com/RektInator)
// License: GNU GPL v3.0
// ========================================================
#pragma once

namespace ZoneTool
{
	namespace IW3
	{
		enum XAssetType : std::int32_t
		{
			xmodelpieces,
			physpreset,
			xanim,
			xmodel,
			material,
			techset,
			image,
			sound,
			sndcurve,
			loaded_sound,
			col_map_sp,
			col_map_mp,
			com_map,
			game_map_sp,
			game_map_mp,
			map_ents,
			gfx_map,
			lightdef,
			ui_map,
			// not used
			font,
			menufile,
			menu,
			localize,
			weapon,
			snddriverglobals,
			// not used
			fx,
			impactfx,
			aitype,
			// not used
			mptype,
			// not used
			character,
			// not used
			xmodelalias,
			// not used
			rawfile,
			stringtable,
			max_type,
		};

		typedef float vec4_t[4];
		typedef float vec3_t[3];
		typedef float vec2_t[2];

		template <std::size_t N>
		struct VecInternal
		{
			float data[N];
		};

		enum MapType
		{
			MAPTYPE_NONE = 0x0,
			MAPTYPE_INVALID1 = 0x1,
			MAPTYPE_INVALID2 = 0x2,
			MAPTYPE_2D = 0x3,
			MAPTYPE_3D = 0x4,
			MAPTYPE_CUBE = 0x5,
			MAPTYPE_COUNT = 0x6,
		};

		struct Picmip
		{
			char platform[2];
		};

		struct CardMemory
		{
			int platform[2];
		};

		struct GfxImageLoadDef
		{
			char levelCount;
			char flags;
			__int16 dimensions[3];
			int format;
			int resourceSize;
			unsigned char data[1];
		};

		union GfxTexture
		{
			/*IDirect3DBaseTexture9 *basemap;
			IDirect3DTexture9 *map;
			IDirect3DVolumeTexture9 *volmap;
			IDirect3DCubeTexture9 *cubemap;*/
			GfxImageLoadDef* loadDef;
			void* data;
		};

		enum TextureSemantic : char
		{
			TS_2D = 0x0,
			TS_FUNCTION = 0x1,
			TS_COLOR_MAP = 0x2,
			TS_DETAIL_MAP = 0x3,
			TS_UNUSED_2 = 0x4,
			TS_NORMAL_MAP = 0x5,
			TS_UNUSED_3 = 0x6,
			TS_UNUSED_4 = 0x7,
			TS_SPECULAR_MAP = 0x8,
			TS_UNUSED_5 = 0x9,
			TS_UNUSED_6 = 0xA,
			TS_WATER_MAP = 0xB,
		};

		enum GfxImageCategory : char
		{
			IMG_CATEGORY_UNKNOWN = 0x0,
			IMG_CATEGORY_AUTO_GENERATED = 0x1,
			IMG_CATEGORY_LIGHTMAP = 0x2,
			IMG_CATEGORY_LOAD_FROM_FILE = 0x3,
			IMG_CATEGORY_RAW = 0x4,
			IMG_CATEGORY_FIRST_UNMANAGED = 0x5,
			IMG_CATEGORY_WATER = 0x5,
			IMG_CATEGORY_RENDERTARGET = 0x6,
			IMG_CATEGORY_TEMP = 0x7,
		};

		struct GfxImage
		{
			MapType mapType;
			GfxTexture texture;
			Picmip picmip;
			bool noPicmip;
			TextureSemantic semantic;
			char track;
			CardMemory cardMemory;
			unsigned __int16 width;
			unsigned __int16 height;
			unsigned __int16 depth;
			GfxImageCategory category;
			bool delayLoadPixels;
			const char* name;
		};

		enum file_image_flags_t
		{
			IMG_FLAG_NOPICMIP = 0x1,
			IMG_FLAG_NOMIPMAPS = 0x2,
			IMG_FLAG_CUBEMAP = 0x4,
			IMG_FLAG_VOLMAP = 0x8,
			IMG_FLAG_STREAMING = 0x10,
			IMG_FLAG_LEGACY_NORMALS = 0x20,
			IMG_FLAG_CLAMP_U = 0x40,
			IMG_FLAG_CLAMP_V = 0x80,
			IMG_FLAG_DYNAMIC = 0x10000,
			IMG_FLAG_RENDER_TARGET = 0x20000,
			IMG_FLAG_SYSTEMMEM = 0x40000,
		};

		struct GfxImageFileHeader
		{
			char tag[3];
			char version;
			char format;
			char flags;
			short dimensions[3];
			int fileSizeForPicmip[4];
		};

		struct MaterialConstantDef
		{
			unsigned int nameHash;
			char name[12];
			vec4_t literal;
		};

		struct GfxStateBits
		{
			unsigned int loadBits[2];
		};

		struct WaterWritable
		{
			float floatTime;
		};

		struct complex_s
		{
			float real;
			float imag;
		};

		struct water_t
		{
			WaterWritable writable;
			complex_s* H0;
			float* wTerm;
			int M;
			int N;
			float Lx;
			float Lz;
			float gravity;
			float windvel;
			float winddir[2];
			float amplitude;
			float codeConstant[4];
			GfxImage* image;
		};

		union MaterialTextureDefInfo
		{
			GfxImage* image; // MaterialTextureDef->semantic != TS_WATER_MAP
			water_t* water; // MaterialTextureDef->semantic == TS_WATER_MAP
		};

		struct MaterialTextureDef
		{
			unsigned int nameHash;
			char nameStart;
			char nameEnd;
			char samplerState;
			TextureSemantic semantic;
			MaterialTextureDefInfo u;
		};

		struct GfxDrawSurfFields
		{
			unsigned __int64 objectId : 16;
			unsigned __int64 reflectionProbeIndex : 8;
			unsigned __int64 customIndex : 5;
			unsigned __int64 materialSortedIndex : 11;
			unsigned __int64 prepass : 2;
			unsigned __int64 primaryLightIndex : 8;
			unsigned __int64 surfType : 4;
			unsigned __int64 primarySortKey : 6;
			unsigned __int64 unused : 4;
		};

		union GfxDrawSurf
		{
			GfxDrawSurfFields fields;
			unsigned long long packed;
		};

		struct GfxVertexShaderLoadDef
		{
			unsigned int* program;
			unsigned __int16 programSize;
			unsigned __int16 loadForRenderer;
		};

		struct MaterialVertexShaderProgram
		{
			void* vs;
			GfxVertexShaderLoadDef loadDef;
		};

		struct MaterialVertexShader
		{
			const char* name;
			MaterialVertexShaderProgram prog;
		};

		struct GfxPixelShaderLoadDef
		{
			unsigned int* program;
			unsigned __int16 programSize;
			unsigned __int16 loadForRenderer;
		};

		struct MaterialPixelShaderProgram
		{
			void* ps;
			GfxPixelShaderLoadDef loadDef;
		};

		struct MaterialPixelShader
		{
			const char* name;
			MaterialPixelShaderProgram prog;
		};

		struct MaterialArgumentCodeConst
		{
			unsigned __int16 index;
			char firstRow;
			char rowCount;
		};

		union MaterialArgumentDef
		{
			const float* literalConst;
			MaterialArgumentCodeConst codeConst;
			unsigned int codeSampler;
			unsigned int nameHash;
		};

		struct MaterialShaderArgument
		{
			unsigned __int16 type;
			unsigned __int16 dest;
			MaterialArgumentDef u;
		};

		struct MaterialStreamRouting
		{
			char source;
			char dest;
		};

		struct MaterialVertexStreamRouting
		{
			MaterialStreamRouting data[16];
			void* decl[16];
		};

		struct MaterialVertexDeclaration
		{
			char streamCount;
			bool hasOptionalSource;
			bool isLoaded;
			char pad[1];
			MaterialVertexStreamRouting routing;
		};

		struct MaterialPass
		{
			MaterialVertexDeclaration* vertexDecl;
			MaterialVertexShader* vertexShader;
			MaterialPixelShader* pixelShader;
			char perPrimArgCount;
			char perObjArgCount;
			char stableArgCount;
			char customSamplerFlags;
			MaterialShaderArgument* args;
		};

		struct MaterialTechniqueHdr
		{
			const char* name;
			unsigned __int16 flags;
			unsigned __int16 numPasses;
		};

		struct MaterialTechnique
		{
			MaterialTechniqueHdr hdr;
			MaterialPass pass[1];
		};

		struct MaterialTechniqueSet
		{
			const char* name;

			union
			{
				int pad;

				struct
				{
					char worldVertFormat;
					bool hasBeenUploaded;
					char unused[1];
				};
			};

			MaterialTechniqueSet* remappedTechniqueSet;
			MaterialTechnique* techniques[34];
		};

		struct MaterialGameFlagsFields
		{
			unsigned char unk1 : 1; // 0x1
			unsigned char addShadowToPrimaryLight : 1; // 0x2
			unsigned char isFoliageRequiresGroundLighting : 1; // 0x4
			unsigned char unk4 : 1; // 0x8
			unsigned char unk5 : 1; // 0x10
			unsigned char unk6 : 1; // 0x20
			unsigned char MTL_GAMEFLAG_CASTS_SHADOW : 1; // 0x40
			unsigned char unkNeededForSModelDisplay : 1; // 0x80
		};

		union MaterialGameFlags
		{
			MaterialGameFlagsFields fields;
			unsigned char packed;
		};

		enum SurfaceTypeBits : std::uint32_t
		{
			SURFTYPE_BITS_DEFAULT = 0x0,
			SURFTYPE_BITS_BARK = 0x1,
			SURFTYPE_BITS_BRICK = 0x2,
			SURFTYPE_BITS_CARPET = 0x4,
			SURFTYPE_BITS_CLOTH = 0x8,
			SURFTYPE_BITS_CONCRETE = 0x10,
			SURFTYPE_BITS_DIRT = 0x20,
			SURFTYPE_BITS_FLESH = 0x40,
			SURFTYPE_BITS_FOLIAGE = 0x80,
			SURFTYPE_BITS_GLASS = 0x100,
			SURFTYPE_BITS_GRASS = 0x200,
			SURFTYPE_BITS_GRAVEL = 0x400,
			SURFTYPE_BITS_ICE = 0x800,
			SURFTYPE_BITS_METAL = 0x1000,
			SURFTYPE_BITS_MUD = 0x2000,
			SURFTYPE_BITS_PAPER = 0x4000,
			SURFTYPE_BITS_PLASTER = 0x8000,
			SURFTYPE_BITS_ROCK = 0x10000,
			SURFTYPE_BITS_SAND = 0x20000,
			SURFTYPE_BITS_SNOW = 0x40000,
			SURFTYPE_BITS_WATER = 0x80000,
			SURFTYPE_BITS_WOOD = 0x100000,
			SURFTYPE_BITS_ASPHALT = 0x200000,
			SURFTYPE_BITS_CERAMIC = 0x400000,
			SURFTYPE_BITS_PLASTIC = 0x800000,
			SURFTYPE_BITS_RUBBER = 0x1000000,
			SURFTYPE_BITS_CUSHION = 0x2000000,
			SURFTYPE_BITS_FRUIT = 0x4000000,
			SURFTYPE_BITS_PAINTEDMETAL = 0x8000000,
			SURFTYPE_BITS_SLUSH = 0x10000000,
		};

#pragma pack(push, 4)
		struct MaterialInfo
		{
			const char* name;
			char gameFlags;
			char sortKey;
			char textureAtlasRowCount;
			char textureAtlasColumnCount;
			GfxDrawSurf drawSurf;
			unsigned int surfaceTypeBits;
			unsigned __int16 hashIndex;
		};
#pragma pack(pop)

		enum MaterialTechniqueType
		{
			TECHNIQUE_DEPTH_PREPASS = 0x0,
			TECHNIQUE_BUILD_FLOAT_Z = 0x1,
			TECHNIQUE_BUILD_SHADOWMAP_DEPTH = 0x2,
			TECHNIQUE_BUILD_SHADOWMAP_COLOR = 0x3,
			TECHNIQUE_UNLIT = 0x4,
			TECHNIQUE_EMISSIVE = 0x5,
			TECHNIQUE_EMISSIVE_SHADOW = 0x6,
			TECHNIQUE_LIT_BEGIN = 0x7,
			TECHNIQUE_LIT = 0x7,
			TECHNIQUE_LIT_SUN = 0x8,
			TECHNIQUE_LIT_SUN_SHADOW = 0x9,
			TECHNIQUE_LIT_SPOT = 0xA,
			TECHNIQUE_LIT_SPOT_SHADOW = 0xB,
			TECHNIQUE_LIT_OMNI = 0xC,
			TECHNIQUE_LIT_OMNI_SHADOW = 0xD,
			TECHNIQUE_LIT_INSTANCED = 0xE,
			TECHNIQUE_LIT_INSTANCED_SUN = 0xF,
			TECHNIQUE_LIT_INSTANCED_SUN_SHADOW = 0x10,
			TECHNIQUE_LIT_INSTANCED_SPOT = 0x11,
			TECHNIQUE_LIT_INSTANCED_SPOT_SHADOW = 0x12,
			TECHNIQUE_LIT_INSTANCED_OMNI = 0x13,
			TECHNIQUE_LIT_INSTANCED_OMNI_SHADOW = 0x14,
			TECHNIQUE_LIT_END = 0x15,
			TECHNIQUE_LIGHT_SPOT = 0x15,
			TECHNIQUE_LIGHT_OMNI = 0x16,
			TECHNIQUE_LIGHT_SPOT_SHADOW = 0x17,
			TECHNIQUE_FAKELIGHT_NORMAL = 0x18,
			TECHNIQUE_FAKELIGHT_VIEW = 0x19,
			TECHNIQUE_SUNLIGHT_PREVIEW = 0x1A,
			TECHNIQUE_CASE_TEXTURE = 0x1B,
			TECHNIQUE_WIREFRAME_SOLID = 0x1C,
			TECHNIQUE_WIREFRAME_SHADED = 0x1D,
			TECHNIQUE_SHADOWCOOKIE_CASTER = 0x1E,
			TECHNIQUE_SHADOWCOOKIE_RECEIVER = 0x1F,
			TECHNIQUE_DEBUG_BUMPMAP = 0x20,
			TECHNIQUE_DEBUG_BUMPMAP_INSTANCED = 0x21,
			TECHNIQUE_COUNT = 0x22,
			TECHNIQUE_TOTAL_COUNT = 0x23,
			TECHNIQUE_NONE = 0x24,
		};

		struct infoParm_t
		{
			const char* name;
			int clearSolid;
			int surfaceFlags;
			int contents;
			int toolFlags;
		};

		enum GfxCameraRegionType : std::int8_t
		{
			CAMERA_REGION_LIT = 0x0,
			CAMERA_REGION_DECAL = 0x1,
			CAMERA_REGION_EMISSIVE = 0x2,
			CAMERA_REGION_COUNT = 0x3,
			CAMERA_REGION_NONE = 0x3,
		};

		struct Material
		{
			const char* name;
			char gameFlags;
			char sortKey;
			char textureAtlasRowCount;
			char textureAtlasColumnCount;
			GfxDrawSurf drawSurf;
			unsigned int surfaceTypeBits;
			unsigned __int16 hashIndex;
			char pad[2];
			// MaterialInfo info;
			char stateBitsEntry[34];
			char textureCount;
			char constantCount;
			char stateBitsCount;
			char stateFlags;
			char cameraRegion;
			MaterialTechniqueSet* techniqueSet;
			MaterialTextureDef* textureTable;
			MaterialConstantDef* constantTable;
			GfxStateBits* stateBitsTable;
		};

		struct cplane_s
		{
			float normal[3];
			float dist;
			char type;
			char signbits;
			char pad[2];
		};

#pragma pack(push, 2)
		struct cbrushside_t
		{
			cplane_s* plane;
			unsigned int materialNum;
			__int16 firstAdjacentSideOffset;
			char edgeCount;
		};
#pragma pack(pop)

		struct DObjAnimMat
		{
			float quat[4];
			float trans[3];
			float transWeight;
		};

		struct XSurfaceVertexInfo
		{
			short vertCount[4];
			unsigned short* vertsBlend;
		};

		union GfxColor
		{
			unsigned int packed;
			unsigned char array[4];
		};

		union PackedTexCoords
		{
			unsigned int packed;
		};

		union PackedUnitVec
		{
			unsigned int packed;
			unsigned char array[4];
		};

		struct GfxPackedVertex
		{
			float xyz[3];
			float binormalSign;
			GfxColor color;
			PackedTexCoords texCoord;
			PackedUnitVec normal;
			PackedUnitVec tangent;
		};

		struct XSurfaceCollisionAabb
		{
			unsigned short mins[3];
			unsigned short maxs[3];
		};

		struct XSurfaceCollisionNode
		{
			XSurfaceCollisionAabb aabb;
			unsigned short childBeginIndex;
			unsigned short childCount;
		};

		struct XSurfaceCollisionLeaf
		{
			unsigned short triangleBeginIndex;
		};

		struct XSurfaceCollisionTree
		{
			float trans[3];
			float scale[3];
			unsigned int nodeCount;
			XSurfaceCollisionNode* nodes;
			unsigned int leafCount;
			XSurfaceCollisionLeaf* leafs;
		};

		struct XRigidVertList
		{
			unsigned short boneOffset;
			unsigned short vertCount;
			unsigned short triOffset;
			unsigned short triCount;
			XSurfaceCollisionTree* collisionTree;
		};

		struct XSurface
		{
			char tileMode;
			bool deformed;
			unsigned __int16 vertCount;
			unsigned __int16 triCount;
			char zoneHandle;
			unsigned __int16 baseTriIndex;
			unsigned __int16 baseVertIndex;
			unsigned __int16* triIndices;
			XSurfaceVertexInfo vertInfo;
			GfxPackedVertex* verts0;
			unsigned int vertListCount;
			XRigidVertList* vertList;
			int partBits[4];
		};

		struct BrushWrapper
		{
			float mins[3];
			int contents;
			float maxs[3];
			unsigned int numsides;
			cbrushside_t* sides;
			__int16 axialMaterialNum[2][3];
			char* baseAdjacentSide;
			__int16 firstAdjacentSideOffsets[2][3];
			char edgeCount[2][3];
			int totalEdgeCount;
			cplane_s* planes;
		};

		struct PhysMass
		{
			float centerOfMass[3];
			float momentsOfInertia[3];
			float productsOfInertia[3];
		};

		struct PhysGeomInfo
		{
			BrushWrapper* brush;
			int type;
			float orientation[3][3];
			float offset[3];
			float halfLengths[3];
		};

		struct PhysGeomList
		{
			unsigned int count;
			PhysGeomInfo* geoms;
			PhysMass mass;
		};

		struct XBoneInfo
		{
			float bounds[2][3];
			float offset[3];
			float radiusSquared;
		};

		struct XModelHighMipBounds
		{
			float mins[3];
			float maxs[3];
		};

		struct XModelStreamInfo
		{
			XModelHighMipBounds* highMipBounds;
		};

		struct XModelCollTri_s
		{
			float plane[4];
			float svec[4];
			float tvec[4];
		};

		struct XModelCollSurf_s
		{
			XModelCollTri_s* collTris;
			int numCollTris;
			float mins[3];
			float maxs[3];
			int boneIdx;
			int contents;
			int surfFlags;
		};

		struct XModelLodInfo
		{
			float dist;
			unsigned __int16 numsurfs;
			unsigned __int16 surfIndex;
			int partBits[4];
			char lod;
			char smcIndexPlusOne;
			char smcAllocBits;
			char unused;
		};

#pragma pack(push, 4)
		struct PhysPreset
		{
			const char* name;
			int type;
			float mass;
			float bounce;
			float friction;
			float bulletForceScale;
			float explosiveForceScale;
			const char* sndAliasPrefix;
			float piecesSpreadFraction;
			float piecesUpwardVelocity;
			char tempDefaultToCylinder;
		};
#pragma pack(pop)

		enum CSurfaceFlags : std::uint32_t
		{
			SURF_FLAG_DEFAULT = 0x00000000,
			SURF_FLAG_BARK = 0x00100000,
			SURF_FLAG_BRICK = 0x00200000,
			SURF_FLAG_CARPET = 0x00300000,
			SURF_FLAG_CLOTH = 0x00400000,
			SURF_FLAG_CONCRETE = 0x00500000,
			SURF_FLAG_DIRT = 0x00600000,
			SURF_FLAG_FLESH = 0x00700000,
			SURF_FLAG_FOLIAGE = 0x00800000,
			SURF_FLAG_GLASS = 0x00900000,
			SURF_FLAG_GRASS = 0x00A00000,
			SURF_FLAG_GRAVEL = 0x00B00000,
			SURF_FLAG_ICE = 0x00C00000,
			SURF_FLAG_METAL = 0x00D00000,
			SURF_FLAG_MUD = 0x00E00000,
			SURF_FLAG_PAPER = 0x00F00000,
			SURF_FLAG_PLASTER = 0x01000000,
			SURF_FLAG_ROCK = 0x01100000,
			SURF_FLAG_SAND = 0x01200000,
			SURF_FLAG_SNOW = 0x01300000,
			SURF_FLAG_WATER = 0x01400000,
			SURF_FLAG_WOOD = 0x01500000,
			SURF_FLAG_ASPHALT = 0x01600000,
			SURF_FLAG_CERAMIC = 0x01700000,
			SURF_FLAG_PLASTIC = 0x01800000,
			SURF_FLAG_RUBBER = 0x01900000,
			SURF_FLAG_CUSHION = 0x01A00000,
			SURF_FLAG_FRUIT = 0x01B00000,
			SURF_FLAG_PAINTEDMETAL = 0x01C00000,
			SURF_FLAG_OPAQUEGLASS = 0x00900000,
			SURF_FLAG_CLIPMISSILE = 0x00000000,
			SURF_FLAG_AI_NOSIGHT = 0x00000000,
			SURF_FLAG_CLIPSHOT = 0x00000000,
			SURF_FLAG_PLAYERCLIP = 0x00000000,
			SURF_FLAG_MONSTERCLIP = 0x00000000,
			SURF_FLAG_VEHICLECLIP = 0x00000000,
			SURF_FLAG_ITEMCLIP = 0x00000000,
			SURF_FLAG_NODROP = 0x00000000,
			SURF_FLAG_NONSOLID = 0x00004000,
			SURF_FLAG_DETAIL = 0x00000000,
			SURF_FLAG_STRUCTURAL = 0x00000000,
			SURF_FLAG_PORTAL = 0x80000000,
			SURF_FLAG_CANSHOOTCLIP = 0x00000000,
			SURF_FLAG_ORIGIN = 0x00000000,
			SURF_FLAG_SKY = 0x00000004,
			SURF_FLAG_NOCASTSHADOW = 0x00040000,
			SURF_FLAG_PHYSICSGEOM = 0x00000000,
			SURF_FLAG_LIGHTPORTAL = 0x00000000,
			SURF_FLAG_SLICK = 0x00000002,
			SURF_FLAG_NOIMPACT = 0x00000010,
			SURF_FLAG_NOMARKS = 0x00000020,
			SURF_FLAG_NOPENETRATE = 0x00000100,
			SURF_FLAG_LADDER = 0x00000008,
			SURF_FLAG_NODAMAGE = 0x00000001,
			SURF_FLAG_MANTLEON = 0x02000000,
			SURF_FLAG_MANTLEOVER = 0x04000000,
			SURF_FLAG_NOSTEPS = 0x00002000,
			SURF_FLAG_NODRAW = 0x00000080,
			SURF_FLAG_NOLIGHTMAP = 0x00000400,
			SURF_FLAG_NODLIGHT = 0x00020000,
		};

		struct XModel
		{
			const char* name;
			char numBones;
			char numRootBones;
			unsigned char numsurfs;
			char lodRampType;
			unsigned __int16* boneNames;
			char* parentList;
			__int16* quats;
			float* trans;
			char* partClassification;
			DObjAnimMat* baseMat;
			XSurface* surfs;
			Material** materialHandles;
			XModelLodInfo lodInfo[4];
			XModelCollSurf_s* collSurfs;
			int numCollSurfs;
			int contents;
			XBoneInfo* boneInfo;
			float radius;
			float mins[3];
			float maxs[3];
			__int16 numLods;
			__int16 collLod;
			XModelStreamInfo streamInfo;
			int memUsage;
			char flags;
			bool bad;
			PhysPreset* physPreset;
			PhysGeomList* physGeoms;
		};

		union XAnimIndices
		{
			char* _1;
			unsigned __int16* _2;
			void* data;
		};

		union XAnimDynamicFrames
		{
			char (*_1)[3];
			unsigned __int16 (*_2)[3];
		};

		union XAnimDynamicIndices
		{
			char _1[1];
			unsigned __int16 _2[1];
		};

#pragma pack(push, 4)
		struct XAnimPartTransFrames
		{
			float mins[3];
			float size[3];
			XAnimDynamicFrames frames;
			XAnimDynamicIndices indices;
		};

		union XAnimPartTransData
		{
			XAnimPartTransFrames frames;
			float frame0[3];
		};

		struct XAnimPartTrans
		{
			unsigned __int16 size;
			char smallTrans;
			__declspec(align(2)) XAnimPartTransData u;
		};

		struct XAnimDeltaPartQuatDataFrames
		{
			__int16 (*frames)[2];
			XAnimDynamicIndices indices;
		};

		union XAnimDeltaPartQuatData
		{
			XAnimDeltaPartQuatDataFrames frames;
			__int16 frame0[2];
		};

		struct XAnimDeltaPartQuat
		{
			unsigned __int16 size;
			__declspec(align(4)) XAnimDeltaPartQuatData u;
		};

		struct XAnimDeltaPart
		{
			XAnimPartTrans* trans;
			XAnimDeltaPartQuat* quat;
		};

		struct XAnimNotifyInfo
		{
			short name;
			float time;
		};

#ifdef __cplusplus
		enum XAnimPartType
		{
			PART_TYPE_NO_QUAT = 0x0,
			PART_TYPE_SIMPLE_QUAT = 0x1,
			PART_TYPE_NORMAL_QUAT = 0x2,
			PART_TYPE_PRECISION_QUAT = 0x3,
			PART_TYPE_SIMPLE_QUAT_NO_SIZE = 0x4,
			PART_TYPE_NORMAL_QUAT_NO_SIZE = 0x5,
			PART_TYPE_PRECISION_QUAT_NO_SIZE = 0x6,
			PART_TYPE_SMALL_TRANS = 0x7,
			PART_TYPE_TRANS = 0x8,
			PART_TYPE_TRANS_NO_SIZE = 0x9,
			PART_TYPE_NO_TRANS = 0xA,
			PART_TYPE_ALL = 0xB,
			PART_TYPE_COUNT = 0xC,
		};
#endif

#pragma pack(pop)

		struct XAnimParts
		{
			char* name; // 0
			unsigned short dataByteCount; // 4
			unsigned short dataShortCount; // 6
			unsigned short dataIntCount; // 8
			unsigned short randomDataByteCount; // 10 - 0xA
			unsigned short randomDataIntCount; // 12 - 0xC
			unsigned short framecount; // 14 - 0xE
			char bLoop; // 16
			char bDelta; // 31
			unsigned char boneCount[10]; // 17
			char notifyCount; // 27
			char assetType; // 30
            bool isDefault;
			unsigned int randomDataShortCount; // 32 - 0x20
			unsigned int indexcount; // 36 - 0x24
			float framerate; // 40 - 0x28
			float frequency; // 44 - 0x2C
			unsigned short* tagnames; // 48 - 0x30
			char* dataByte; // 52 - 0x34
			short* dataShort; // 56 - 0x38
			int* dataInt; // 60 - 0x3C
			short* randomDataShort; // 64 - 0x40
			char* randomDataByte; // 68 - 0x44
			int* randomDataInt; // 72 - 0x48
			XAnimIndices indices; // 76 - 0x4C
			XAnimNotifyInfo* notify; // 80 - 0x50
			XAnimDeltaPart* delta; // 84 - 0x54
		};

		struct GfxStreamingAabbTree
		{
			unsigned __int16 firstItem;
			unsigned __int16 itemCount;
			unsigned __int16 firstChild;
			unsigned __int16 childCount;
			float mins[3];
			float maxs[3];
		};

		struct GfxWorldStreamInfo
		{
			int aabbTreeCount;
			// 			GfxStreamingAabbTree *aabbTrees;
			// 			int leafRefCount;
			// 			int *leafRefs;
		};

		struct GfxWorldVertex
		{
			float xyz[3];
			float binormalSign;
			GfxColor color;
			float texCoord[2];
			float lmapCoord[2];
			PackedUnitVec normal;
			PackedUnitVec tangent;
		};

		struct GfxWorldVertexData
		{
			GfxWorldVertex* vertices;
			void/*IDirect3DVertexBuffer9*/ * worldVb;
		};

		struct GfxWorldVertexLayerData
		{
			char* data;
			void/*IDirect3DVertexBuffer9*/ * layerVb;
		};

		struct SunLightParseParams
		{
			char name[64];
			float ambientScale;
			float ambientColor[3];
			float diffuseFraction;
			float sunLight;
			float sunColor[3];
			float diffuseColor[3];
			char diffuseColorHasBeenSet;
			float angles[3];
		};

		struct __declspec(align(4)) GfxLightImage
		{
			GfxImage* image;
			char samplerState;
		};

		struct GfxLightDef
		{
			const char* name;
			GfxLightImage attenuation;
			int lmapLookupStart;
		};

		struct GfxLight
		{
			char type;
			char canUseShadowMap;
			char unused[2];
			float color[3];
			float dir[3];
			float origin[3];
			float radius;
			float cosHalfFovOuter;
			float cosHalfFovInner;
			int exponent;
			unsigned int spotShadowIndex;
			GfxLightDef* def;
		};

		struct GfxReflectionProbe
		{
			float origin[3];
			GfxImage* reflectionImage;
		};

		struct GfxWorldDpvsPlanes
		{
			int cellCount;
			cplane_s* planes;
			unsigned __int16* nodes;
			unsigned int* sceneEntCellBits;
		};

		struct GfxAabbTree
		{
			float mins[3];
			float maxs[3];
			unsigned __int16 childCount;
			unsigned __int16 surfaceCount;
			unsigned __int16 startSurfIndex;
			unsigned __int16 surfaceCountNoDecal;
			unsigned __int16 startSurfIndexNoDecal;
			unsigned __int16 smodelIndexCount;
			unsigned __int16* smodelIndexes;
			int childrenOffset;
		};

		struct GfxPortal;

		struct GfxPortalWritable
		{
			char isQueued;
			char isAncestor;
			char recursionDepth;
			char hullPointCount;
			float (*hullPoints)[2];
			GfxPortal* queuedParent;
		};

		struct DpvsPlane
		{
			float coeffs[4];
			char side[3];
			char pad;
		};

		struct GfxCell;

		struct GfxPortal
		{
			GfxPortalWritable writable;
			DpvsPlane plane;
			GfxCell* cell;
			float (*vertices)[3];
			char vertexCount;
			float hullAxis[2][3];
		};

		struct GfxCell
		{
			float mins[3];
			float maxs[3];
			int aabbTreeCount;
			GfxAabbTree* aabbTree;
			int portalCount;
			GfxPortal* portals;
			int cullGroupCount;
			int* cullGroups;
			char reflectionProbeCount;
			char* reflectionProbes;
		};

		struct GfxLightmapArray
		{
			GfxImage* primary;
			GfxImage* secondary;
		};

		struct GfxLightGridEntry
		{
			unsigned __int16 colorsIndex;
			char primaryLightIndex;
			char needsTrace;
		};

		struct GfxLightGridColors
		{
			char rgb[56][3];
		};

		struct GfxLightGrid
		{
			char hasLightRegions;
			unsigned int sunPrimaryLightIndex;
			unsigned __int16 mins[3];
			unsigned __int16 maxs[3];
			unsigned int rowAxis;
			unsigned int colAxis;
			unsigned __int16* rowDataStart;
			unsigned int rawRowDataSize;
			char* rawRowData;
			unsigned int entryCount;
			GfxLightGridEntry* entries;
			unsigned int colorCount;
			GfxLightGridColors* colors;
		};

		struct GfxBrushModelWritable
		{
			float mins[3];
			float maxs[3];
		};

		struct __declspec(align(4)) GfxBrushModel
		{
			GfxBrushModelWritable writable;
			float bounds[2][3];
			unsigned __int16 surfaceCount;
			unsigned __int16 startSurfIndex;
			unsigned __int16 surfaceCountNoDecal;
		};

		struct MaterialMemory
		{
			Material* material;
			int memory;
		};

		struct sunflare_t
		{
			char hasValidData;
			Material* spriteMaterial;
			Material* flareMaterial;
			float spriteSize;
			float flareMinSize;
			float flareMinDot;
			float flareMaxSize;
			float flareMaxDot;
			float flareMaxAlpha;
			int flareFadeInTime;
			int flareFadeOutTime;
			float blindMinDot;
			float blindMaxDot;
			float blindMaxDarken;
			int blindFadeInTime;
			int blindFadeOutTime;
			float glareMinDot;
			float glareMaxDot;
			float glareMaxLighten;
			int glareFadeInTime;
			int glareFadeOutTime;
			float sunFxPosition[3];
		};

		struct XModelDrawInfo
		{
			unsigned __int16 lod;
			unsigned __int16 surfId;
		};

		struct GfxSceneDynModel
		{
			XModelDrawInfo info;
			unsigned __int16 dynEntId;
		};

		struct BModelDrawInfo
		{
			unsigned __int16 surfId;
		};

		struct GfxSceneDynBrush
		{
			BModelDrawInfo info;
			unsigned __int16 dynEntId;
		};

		struct GfxShadowGeometry
		{
			unsigned __int16 surfaceCount;
			unsigned __int16 smodelCount;
			unsigned __int16* sortedSurfIndex;
			unsigned __int16* smodelIndex;
		};

		struct GfxLightRegionAxis
		{
			float dir[3];
			float midPoint;
			float halfSize;
		};

		struct GfxLightRegionHull
		{
			float kdopMidPoint[9];
			float kdopHalfSize[9];
			unsigned int axisCount;
			GfxLightRegionAxis* axis;
		};

		struct GfxLightRegion
		{
			unsigned int hullCount;
			GfxLightRegionHull* hulls;
		};

		struct GfxStaticModelInst
		{
			float mins[3];
			float maxs[3];
			GfxColor groundLighting;
		};

		struct srfTriangles_t
		{
			int vertexLayerData;
			int firstVertex;
			unsigned __int16 vertexCount;
			unsigned __int16 triCount;
			int baseIndex;
		};

		struct GfxSurface
		{
			srfTriangles_t tris;
			Material* material;
			char lightmapIndex;
			char reflectionProbeIndex;
			char primaryLightIndex;
			char flags;
			float bounds[2][3];
		};

		struct GfxCullGroup
		{
			float mins[3];
			float maxs[3];
			int surfaceCount;
			int startSurfIndex;
		};

		struct GfxPackedPlacement
		{
			float origin[3];
			vec3_t axis[3];
			float scale;
		};

		struct __declspec(align(4)) GfxStaticModelDrawInst
		{
			float cullDist;
			GfxPackedPlacement placement;
			XModel* model;
			unsigned __int16 smodelCacheIndex[4];
			char reflectionProbeIndex;
			char primaryLightIndex;
			unsigned __int16 lightingHandle;
			char flags;
		};

		struct GfxWorldDpvsStatic
		{
			unsigned int smodelCount;
			unsigned int staticSurfaceCount;
			unsigned int staticSurfaceCountNoDecal;
			unsigned int litSurfsBegin;
			unsigned int litSurfsEnd;
			unsigned int decalSurfsBegin;
			unsigned int decalSurfsEnd;
			unsigned int emissiveSurfsBegin;
			unsigned int emissiveSurfsEnd;
			unsigned int smodelVisDataCount;
			unsigned int surfaceVisDataCount;
			char* smodelVisData[3];
			char* surfaceVisData[3];
			unsigned int* lodData;
			unsigned __int16* sortedSurfIndex;
			GfxStaticModelInst* smodelInsts;
			GfxSurface* surfaces;
			GfxCullGroup* cullGroups;
			GfxStaticModelDrawInst* smodelDrawInsts;
			GfxDrawSurf* surfaceMaterials;
			unsigned int* surfaceCastsSunShadow;
			volatile int usageCount;
		};

		struct GfxWorldDpvsDynamic
		{
			unsigned int dynEntClientWordCount[2];
			unsigned int dynEntClientCount[2];
			unsigned int* dynEntCellBits[2];
			char* dynEntVisData[2][3];
		};

		struct GfxWorld
		{
			const char* name;
			const char* baseName;
			int planeCount;
			int nodeCount;
			int indexCount;
			unsigned __int16* indices;
			int surfaceCount;
			GfxWorldStreamInfo streamInfo;
			int skySurfCount;
			int* skyStartSurfs;
			GfxImage* skyImage;
			char skySamplerState;
			unsigned int vertexCount;
			GfxWorldVertexData vd;
			unsigned int vertexLayerDataSize;
			GfxWorldVertexLayerData vld;
			SunLightParseParams sunParse;
			GfxLight* sunLight;
			float sunColorFromBsp[3];
			unsigned int sunPrimaryLightIndex;
			unsigned int primaryLightCount;
			int cullGroupCount;
			unsigned int reflectionProbeCount;
			GfxReflectionProbe* reflectionProbes;
			GfxTexture* reflectionProbeTextures;
			GfxWorldDpvsPlanes dpvsPlanes;
			int cellBitsCount;
			GfxCell* cells;
			int lightmapCount;
			GfxLightmapArray* lightmaps;
			GfxLightGrid lightGrid;
			GfxTexture* lightmapPrimaryTextures;
			GfxTexture* lightmapSecondaryTextures;
			int modelCount;
			GfxBrushModel* models;
			float mins[3];
			float maxs[3];
			unsigned int checksum;
			int materialMemoryCount;
			MaterialMemory* materialMemory;
			sunflare_t sun;
			float outdoorLookupMatrix[4][4];
			GfxImage* outdoorImage;
			unsigned int* cellCasterBits;
			GfxSceneDynModel* sceneDynModel;
			GfxSceneDynBrush* sceneDynBrush;
			unsigned int* primaryLightEntityShadowVis;
			unsigned int* primaryLightDynEntShadowVis[2];
			char* nonSunPrimaryLightForModelDynEnt;
			GfxShadowGeometry* shadowGeom;
			GfxLightRegion* lightRegion;
			GfxWorldDpvsStatic dpvs;
			GfxWorldDpvsDynamic dpvsDyn;
		};

		struct cStaticModelWritable
		{
			unsigned __int16 nextModelInWorldSector;
		};

		struct cStaticModel_s
		{
			cStaticModelWritable writable;
			XModel* xmodel;
			float origin[3];
			float invScaledAxis[3][3];
			float absmin[3];
			float absmax[3];
		};

		struct dmaterial_t
		{
			char material[64];
			int surfaceFlags;
			int contentFlags;
		};

		struct cNode_t
		{
			cplane_s* plane;
			__int16 children[2];
		};

#pragma pack(push, 4)
		struct cLeaf_t
		{
			unsigned __int16 firstCollAabbIndex;
			unsigned __int16 collAabbCount;
			int brushContents;
			int terrainContents;
			float mins[3];
			float maxs[3];
			int leafBrushNode;
			__int16 cluster;
		};
#pragma pack(pop)

		struct cLeafBrushNodeLeaf_t
		{
			unsigned __int16* brushes;
		};

		struct cLeafBrushNodeChildren_t
		{
			float dist;
			float range;
			unsigned __int16 childOffset[2];
		};

		union cLeafBrushNodeData_t
		{
			cLeafBrushNodeLeaf_t leaf;
			cLeafBrushNodeChildren_t children;
		};

		struct cLeafBrushNode_s
		{
			char axis;
			__int16 leafBrushCount;
			int contents;
			cLeafBrushNodeData_t data;
		};

		struct CollisionBorder
		{
			float distEq[3];
			float zBase;
			float zSlope;
			float start;
			float length;
		};

		struct CollisionPartition
		{
			char triCount;
			char borderCount;
			int firstTri;
			CollisionBorder* borders;
		};

		union CollisionAabbTreeIndex
		{
			int firstChildIndex;
			int partitionIndex;
		};

		struct CollisionAabbTree
		{
			float origin[3];
			float halfSize[3];
			unsigned __int16 materialIndex;
			unsigned __int16 childCount;
			CollisionAabbTreeIndex u;
		};

		/* 860 */
		struct cmodel_t
		{
			float mins[3];
			float maxs[3];
			float radius;
			cLeaf_t leaf;
		};

		/* 861 */
#pragma pack(push, 16)
		struct cbrush_t
		{
			float mins[3];
			int contents;
			float maxs[3];
			unsigned int numsides;
			cbrushside_t* sides;
			__int16 axialMaterialNum[2][3];
			char* baseAdjacentSide;
			__int16 firstAdjacentSideOffsets[2][3];
			char edgeCount[2][3];
			char pad[8];
		};
#pragma pack(pop)

		struct Bounds
		{
			vec3_t midPoint;
			vec3_t halfSize;
		};

		struct TriggerModel
		{
			int contents;
			unsigned __int16 hullCount;
			unsigned __int16 firstHull;
		};

		struct TriggerHull
		{
			Bounds bounds;
			int contents;
			unsigned __int16 slabCount;
			unsigned __int16 firstSlab;
		};

		struct TriggerSlab
		{
			float dir[3];
			float midPoint;
			float halfSize;
		};

		struct MapTriggers
		{
			unsigned int count;
			TriggerModel* models;
			unsigned int hullCount;
			TriggerHull* hulls;
			unsigned int slabCount;
			TriggerSlab* slabs;
		};

		struct MapEnts
		{
			const char* name;
			char* entityString;
			int numEntityChars;
			//MapTriggers trigger;
			// this goes on for a while but we don't need any of it
		};

		struct GfxPlacement
		{
			float quat[4];
			float origin[3];
		};

		struct FxEffectDef_Placeholder
		{
			const char* name;
		};

		struct XModelPiece
		{
			XModel* model;
			float offset[3];
		};

		struct XModelPieces
		{
			const char* name;
			int numpieces;
			XModelPiece* pieces;
		};

		struct FxEffectDef;

		struct DynEntityDef
		{
			int type;
			GfxPlacement pose;
			XModel* xModel;
			unsigned __int16 brushModel;
			unsigned __int16 physicsBrushModel;
			FxEffectDef* destroyFx;
			XModelPieces* destroyPieces;
			PhysPreset* physPreset;
			int health;
			PhysMass mass;
			int contents;
		};

		struct DynEntityPose
		{
			GfxPlacement pose;
			float radius;
		};

		struct DynEntityClient
		{
			int physObjId;
			unsigned __int16 flags;
			unsigned __int16 lightingHandle;
			int health;
		};

		struct DynEntityColl
		{
			unsigned __int16 sector;
			unsigned __int16 nextEntInSector;
			float linkMins[2];
			float linkMaxs[2];
		};

		struct clipMap_t
		{
			const char* name;
			int isInUse;
			int planeCount;
			cplane_s* planes;
			unsigned int numStaticModels;
			cStaticModel_s* staticModelList;
			unsigned int numMaterials;
			dmaterial_t* materials;
			unsigned int numBrushSides;
			cbrushside_t* brushsides;
			unsigned int numBrushEdges;
			char* brushEdges;
			unsigned int numNodes;
			cNode_t* nodes;
			unsigned int numLeafs;
			cLeaf_t* leafs;
			unsigned int leafbrushNodesCount;
			cLeafBrushNode_s* leafbrushNodes;
			unsigned int numLeafBrushes;
			unsigned __int16* leafbrushes;
			unsigned int numLeafSurfaces;
			unsigned int* leafsurfaces;
			unsigned int vertCount;
			float (*verts)[3];
			int triCount;
			unsigned __int16* triIndices;
			char* triEdgeIsWalkable;
			int borderCount;
			CollisionBorder* borders;
			int partitionCount;
			CollisionPartition* partitions;
			int aabbTreeCount;
			CollisionAabbTree* aabbTrees;
			unsigned int numSubModels;
			cmodel_t* cmodels;
			unsigned __int16 numBrushes;
			cbrush_t* brushes;
			int numClusters;
			int clusterBytes;
			char* visibility;
			int vised;
			MapEnts* mapEnts;
			cbrush_t* box_brush;
			cmodel_t box_model;
			unsigned __int16 dynEntCount[2];
			DynEntityDef* dynEntDefList[2];
			DynEntityPose* dynEntPoseList[2];
			DynEntityClient* dynEntClientList[2];
			DynEntityColl* dynEntCollList[2];
			unsigned int checksum;
		};

		struct RawFile
		{
			const char* name;
			int len;
			const char* buffer;
		};

		struct ComPrimaryLight
		{
			char type;
			char canUseShadowMap;
			char exponent;
			char unused;
			float color[3];
			float dir[3];
			float origin[3];
			float radius;
			float cosHalfFovOuter;
			float cosHalfFovInner;
			float cosHalfFovExpanded;
			float rotationLimit;
			float translationLimit;
			const char* defName;
		};

		struct ComWorld
		{
			const char* name;
			int isInUse;
			unsigned int primaryLightCount;
			ComPrimaryLight* primaryLights;
		};

		struct FxSpawnDefLooping
		{
			int intervalMsec;
			int count;
		};

		struct FxIntRange
		{
			int base;
			int amplitude;
		};

		struct FxSpawnDefOneShot
		{
			FxIntRange count;
		};

		union FxSpawnDef
		{
			FxSpawnDefLooping looping;
			FxSpawnDefOneShot oneShot;
		};

		struct FxFloatRange
		{
			float base;
			float amplitude;
		};

		struct FxElemAtlas
		{
			char behavior;
			char index;
			char fps;
			char loopCount;
			char colIndexBits;
			char rowIndexBits;
			__int16 entryCount;
		};

		struct FxElemVec3Range
		{
			float base[3];
			float amplitude[3];
		};

		struct FxElemVelStateInFrame
		{
			FxElemVec3Range velocity;
			FxElemVec3Range totalDelta;
		};

		const struct FxElemVelStateSample
		{
			FxElemVelStateInFrame local;
			FxElemVelStateInFrame world;
		};

		struct FxElemVisualState
		{
			unsigned char color[4];
			float rotationDelta;
			float rotationTotal;
			float size[2];
			float scale;
		};

		const struct FxElemVisStateSample
		{
			FxElemVisualState base;
			FxElemVisualState amplitude;
		};

		struct FxEffectDef;

		union FxEffectDefRef
		{
			FxEffectDef* handle;
			const char* name;
		};

		union FxElemVisuals
		{
			const void* anonymous;
			Material* material;
			XModel* model;
			FxEffectDefRef effectDef;
			const char* soundName;
		};

		struct FxElemMarkVisuals
		{
			Material* materials[2];
		};

		union FxElemDefVisuals
		{
			FxElemMarkVisuals* markArray;
			FxElemVisuals* array;
			FxElemVisuals instance;
		};

		struct FxTrailVertex
		{
			float pos[2];
			float normal[2];
			float texCoord;
		};

		struct FxTrailDef
		{
			int scrollTimeMsec;
			int repeatDist;
			int splitDist;
			int vertCount;
			FxTrailVertex* verts;
			int indCount;
			unsigned __int16* inds;
		};

		enum FxElemType : char
		{
			FX_ELEM_TYPE_SPRITE_BILLBOARD = 0x0,
			FX_ELEM_TYPE_SPRITE_ORIENTED = 0x1,
			FX_ELEM_TYPE_TAIL = 0x2,
			FX_ELEM_TYPE_TRAIL = 0x3,
			FX_ELEM_TYPE_CLOUD = 0x4,
			FX_ELEM_TYPE_MODEL = 0x5,
			FX_ELEM_TYPE_OMNI_LIGHT = 0x6,
			FX_ELEM_TYPE_SPOT_LIGHT = 0x7,
			FX_ELEM_TYPE_SOUND = 0x8,
			FX_ELEM_TYPE_DECAL = 0x9,
			FX_ELEM_TYPE_RUNNER = 0xA,
			FX_ELEM_TYPE_COUNT = 0xB,
			FX_ELEM_TYPE_LAST_SPRITE = 0x3,
			FX_ELEM_TYPE_LAST_DRAWN = 0x7,
		};

		enum FxElemDefFlags : std::uint32_t
		{
			FX_ELEM_SPAWN_RELATIVE_TO_EFFECT = 0x2,
			FX_ELEM_SPAWN_FRUSTUM_CULL = 0x4,
			FX_ELEM_RUNNER_USES_RAND_ROT = 0x8,
			FX_ELEM_SPAWN_OFFSET_NONE = 0x0,
			FX_ELEM_SPAWN_OFFSET_SPHERE = 0x10,
			FX_ELEM_SPAWN_OFFSET_CYLINDER = 0x20,
			FX_ELEM_SPAWN_OFFSET_MASK = 0x30,
			FX_ELEM_RUN_RELATIVE_TO_WORLD = 0x0,
			FX_ELEM_RUN_RELATIVE_TO_SPAWN = 0x40,
			FX_ELEM_RUN_RELATIVE_TO_EFFECT = 0x80,
			FX_ELEM_RUN_RELATIVE_TO_OFFSET = 0xC0,
			FX_ELEM_RUN_MASK = 0xC0,
			FX_ELEM_USE_COLLISION = 0x100,
			FX_ELEM_DIE_ON_TOUCH = 0x200,
			FX_ELEM_DRAW_PAST_FOG = 0x400,
			FX_ELEM_DRAW_WITH_VIEWMODEL = 0x800,
			FX_ELEM_BLOCK_SIGHT = 0x1000,
			FX_ELEM_DRAW_IN_THERMAL_VIEW_ONLY = 0x2000,
			FX_ELEM_TRAIL_ORIENT_BY_VELOCITY = 0x4000,
			FX_ELEM_EMIT_ORIENT_BY_ELEM = 0x8000,
			FX_ELEM_USE_OCCLUSION_QUERY = 0x10000,
			FX_ELEM_HAS_VELOCITY_GRAPH_LOCAL = 0x1000000,
			FX_ELEM_HAS_VELOCITY_GRAPH_WORLD = 0x2000000,
			FX_ELEM_HAS_GRAVITY = 0x4000000,
			FX_ELEM_USE_MODEL_PHYSICS = 0x8000000,
			FX_ELEM_NONUNIFORM_SCALE = 0x10000000,
			FX_ELEM_CLOUD_SHAPE_CUBE = 0x0,
			FX_ELEM_CLOUD_SHAPE_SPHERE_LARGE = 0x20000000,
			FX_ELEM_CLOUD_SHAPE_SPHERE_MEDIUM = 0x40000000,
			FX_ELEM_CLOUD_SHAPE_SPHERE_SMALL = 0x60000000,
			FX_ELEM_CLOUD_SHAPE_MASK = 0x60000000,
			FX_ELEM_FOUNTAIN_DISABLE_COLLISION = 0x80000000,
		};

		const struct FxElemDef
		{
			FxElemDefFlags flags;
			FxSpawnDef spawn;
			FxFloatRange spawnRange;
			FxFloatRange fadeInRange;
			FxFloatRange fadeOutRange;
			float spawnFrustumCullRadius;
			FxIntRange spawnDelayMsec;
			FxIntRange lifeSpanMsec;
			FxFloatRange spawnOrigin[3];
			FxFloatRange spawnOffsetRadius;
			FxFloatRange spawnOffsetHeight;
			FxFloatRange spawnAngles[3];
			FxFloatRange angularVelocity[3];
			FxFloatRange initialRotation;
			FxFloatRange gravity;
			FxFloatRange reflectionFactor;
			FxElemAtlas atlas;
			FxElemType elemType;
			char visualCount;
			char velIntervalCount;
			char visStateIntervalCount;
			FxElemVelStateSample* velSamples;
			FxElemVisStateSample* visSamples;
			FxElemDefVisuals visuals;
			float collMins[3];
			float collMaxs[3];
			FxEffectDefRef effectOnImpact;
			FxEffectDefRef effectOnDeath;
			FxEffectDefRef effectEmitted;
			FxFloatRange emitDist;
			FxFloatRange emitDistVariance;
			FxTrailDef* trailDef;
			char sortOrder;
			char lightingFrac;
			char useItemClip;
			char unused[1];
		};

		struct FxEffectDef
		{
			const char* name;
			int flags;
			int totalSize;
			int msecLoopingLife;
			int elemDefCountLooping;
			int elemDefCountOneShot;
			int elemDefCountEmission;
			FxElemDef* elemDefs;
		};

		struct GameWorldMp
		{
			const char* name;
		};

		// Loaded sound
#pragma pack(push, 4)
		struct LoadedSoundStruct
		{
			int waveFormat;
			int unknown1;
			int dataLength;
			int sampleRate;
			int bitPerChannel;
			int channelCount;
			int unknown3;
			int blockAlign;
			int unknown5;
			char* soundData;
		};
#pragma pack(pop)

		struct LoadedSound
		{
			const char* name;
			LoadedSoundStruct struct1;
		};

		// Sounds
		struct SpeakerLevels
		{
			int speaker;
			int numLevels;
			float levels[2];
		};
		struct ChannelMap
		{
			int entryCount;	// how many entries are used
			SpeakerLevels speakers[6];
		};
		struct SpeakerMap
		{
			bool isDefault;
			char _pad[3];
			const char* name;
			ChannelMap channelMaps[2][2];
		};
		enum snd_alias_type_t : char
		{
			SAT_UNKNOWN = 0x0,
			SAT_LOADED = 0x1,
			SAT_STREAMED = 0x2,
			SAT_PRIMED = 0x3,
			SAT_COUNT = 0x4,
		};
		struct StreamFileNamePacked
		{
			unsigned __int64 offset;
			unsigned __int64 length;
		};
		struct StreamFileNameRaw
		{
			const char* dir;
			const char* name;
		};
		union StreamFileInfo
		{
			StreamFileNameRaw raw;
			StreamFileNamePacked packed;
		};
		struct StreamFileName
		{
			unsigned __int16 isLocalized;
			unsigned __int16 fileIndex;
			StreamFileInfo info;
		};
		/*struct StreamedSound
		{
		StreamFileName filename;
		unsigned int totalMsec;
		};*/
		struct StreamedSound
		{
			const char* dir;
			const char* name;
		};
		struct PrimedSound
		{
			StreamFileName filename;
			LoadedSound* loadedPart;
			int dataOffset;
			int totalSize;
			unsigned int primedCrc;
		};
		union SoundData
		{
			LoadedSound* loadSnd;	// SoundFile->type == SAT_LOADED
			StreamedSound streamSnd;	// SoundFile->type == SAT_STREAMED
										//PrimedSound primedSnd;	// SoundFile->type == SAT_PRIMED
		};
		struct SoundFile	// 0x10
		{
			char type;
			bool exists;
			char _pad[2];
			SoundData sound;
		};
		enum SoundChannel : std::uint32_t
		{
			SND_CHANNEL_PHYSICS,
			SND_CHANNEL_AUTO,
			SND_CHANNEL_AUTO2,
			SND_CHANNEL_AUTODOG,
			SND_CHANNEL_BULLETIMPACT,
			SND_CHANNEL_BULLETWHIZBY,
			SND_CHANNEL_ELEMENT,
			SND_CHANNEL_AUTO2D,
			SND_CHANNEL_VEHICLE,
			SND_CHANNEL_VEHICLELIMITED,
			SND_CHANNEL_MENU,
			SND_CHANNEL_BODY,
			SND_CHANNEL_BODY2D,
			SND_CHANNEL_RELOAD,
			SND_CHANNEL_RELOAD2D,
			SND_CHANNEL_ITEM,
			SND_CHANNEL_EFFECTS1,
			SND_CHANNEL_EFFECTS2,
			SND_CHANNEL_WEAPON,
			SND_CHANNEL_WEAPON2D,
			SND_CHANNEL_NONSHOCK,
			SND_CHANNEL_VOICE,
			SND_CHANNEL_LOCAL,
			SND_CHANNEL_LOCAL2,
			SND_CHANNEL_AMBIENT,
			SND_CHANNEL_HURT,
			SND_CHANNEL_PLAYER1,
			SND_CHANNEL_PLAYER2,
			SND_CHANNEL_MUSIC,
			SND_CHANNEL_MUSICNOPAUSE,
			SND_CHANNEL_MISSION,
			SND_CHANNEL_ANNOUNCER,
			SND_CHANNEL_SHELLSHOCK,

			SND_CHANNEL_COUNT
		};
		union SoundAliasFlags
		{
			struct
			{
				unsigned int looping : 1;
				unsigned int isMaster : 1;
				unsigned int isSlave : 1;
				unsigned int fullDryLevel : 1;
				unsigned int noWetLevel : 1;
				unsigned int randomLooping : 1;
				unsigned int type : 2;
				unsigned int channel : 6;
			};
			unsigned int intValue;
		};
#pragma pack(push, 4)
		struct SndCurve
		{
			const char* filename;
			unsigned __int16 knotCount;
			vec2_t knots[16];
		};
		const struct snd_alias_t
		{
			const char* aliasName;
			const char* subtitle;
			const char* secondaryAliasName;
			const char* chainAliasName;
			SoundFile* soundFile;
			int sequence;
			float volMin;
			float volMax;
			float pitchMin;
			float pitchMax;
			float distMin;
			float distMax;
			int flags;
			float slavePercentage;
			float probability;
			float lfePercentage;
			float centerPercentage;
			int startDelay;
			SndCurve* volumeFalloffCurve;
			float envelopMin;
			float envelopMax;
			float envelopPercentage;
			SpeakerMap* speakerMap;
		};
#pragma push(pop)
		struct snd_alias_list_t
		{
			const char* aliasName;
			snd_alias_t* head;
			int count;
		};

		union XAssetHeader
		{
			void* data;
			// 			XModelPieces *xmodelPieces;
			PhysPreset* physPreset;
			XAnimParts* xanim;
			XModel* xmodel;
			Material* material;
			// 			MaterialPixelShader *pixelShader;
			// 			MaterialVertexShader *vertexShader;
			MaterialTechniqueSet* techset;
			GfxImage* image;
			snd_alias_list_t *sound;
			SndCurve* sndCurve;
			SndCurve* sndcurve;
			clipMap_t* clipMap;
			clipMap_t* col_map_mp;
			ComWorld* com_map;
			// 			GameWorldSp *gameWorldSp;
			GameWorldMp* gameWorldMp;
			GameWorldMp* game_map_mp;
			MapEnts* mapEnts;
			MapEnts* map_ents;
			GfxWorld* gfxWorld;
			GfxWorld* gfx_map;
			GfxLightDef* lightDef;
			GfxLightDef* lightdef;
			LoadedSound* loaded_sound;
			// 			Font_s *font;
			// 			MenuList *menuList;
			// 			menuDef_t *menu;
			// 			LocalizeEntry *localize;
			// 			WeaponDef *weapon;
			// 			SndDriverGlobals *sndDriverGlobals;
			FxEffectDef* fx;
			// 			FxImpactTable *impactFx;
			RawFile* rawfile;
			// 			StringTable *stringTable;
		};
	}
}
