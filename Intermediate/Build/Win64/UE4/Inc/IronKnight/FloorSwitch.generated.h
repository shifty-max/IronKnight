// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef IRONKNIGHT_FloorSwitch_generated_h
#error "FloorSwitch.generated.h already included, missing '#pragma once' in FloorSwitch.h"
#endif
#define IRONKNIGHT_FloorSwitch_generated_h

#define IronKnight_Source_IronKnight_FloorSwitch_h_13_SPARSE_DATA
#define IronKnight_Source_IronKnight_FloorSwitch_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUpdateFloorSwitchLocation); \
	DECLARE_FUNCTION(execUpdateDoorLocation); \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define IronKnight_Source_IronKnight_FloorSwitch_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateFloorSwitchLocation); \
	DECLARE_FUNCTION(execUpdateDoorLocation); \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define IronKnight_Source_IronKnight_FloorSwitch_h_13_EVENT_PARMS
#define IronKnight_Source_IronKnight_FloorSwitch_h_13_CALLBACK_WRAPPERS
#define IronKnight_Source_IronKnight_FloorSwitch_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFloorSwitch(); \
	friend struct Z_Construct_UClass_AFloorSwitch_Statics; \
public: \
	DECLARE_CLASS(AFloorSwitch, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronKnight"), NO_API) \
	DECLARE_SERIALIZER(AFloorSwitch)


#define IronKnight_Source_IronKnight_FloorSwitch_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAFloorSwitch(); \
	friend struct Z_Construct_UClass_AFloorSwitch_Statics; \
public: \
	DECLARE_CLASS(AFloorSwitch, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronKnight"), NO_API) \
	DECLARE_SERIALIZER(AFloorSwitch)


#define IronKnight_Source_IronKnight_FloorSwitch_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFloorSwitch(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFloorSwitch) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFloorSwitch); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFloorSwitch); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFloorSwitch(AFloorSwitch&&); \
	NO_API AFloorSwitch(const AFloorSwitch&); \
public:


#define IronKnight_Source_IronKnight_FloorSwitch_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFloorSwitch(AFloorSwitch&&); \
	NO_API AFloorSwitch(const AFloorSwitch&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFloorSwitch); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFloorSwitch); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFloorSwitch)


#define IronKnight_Source_IronKnight_FloorSwitch_h_13_PRIVATE_PROPERTY_OFFSET
#define IronKnight_Source_IronKnight_FloorSwitch_h_10_PROLOG \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_EVENT_PARMS


#define IronKnight_Source_IronKnight_FloorSwitch_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_PRIVATE_PROPERTY_OFFSET \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_SPARSE_DATA \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_RPC_WRAPPERS \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_CALLBACK_WRAPPERS \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_INCLASS \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IronKnight_Source_IronKnight_FloorSwitch_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_PRIVATE_PROPERTY_OFFSET \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_SPARSE_DATA \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_CALLBACK_WRAPPERS \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_INCLASS_NO_PURE_DECLS \
	IronKnight_Source_IronKnight_FloorSwitch_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IRONKNIGHT_API UClass* StaticClass<class AFloorSwitch>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IronKnight_Source_IronKnight_FloorSwitch_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
