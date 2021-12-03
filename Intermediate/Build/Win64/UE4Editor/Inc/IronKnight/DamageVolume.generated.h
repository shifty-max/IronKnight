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
#ifdef IRONKNIGHT_DamageVolume_generated_h
#error "DamageVolume.generated.h already included, missing '#pragma once' in DamageVolume.h"
#endif
#define IRONKNIGHT_DamageVolume_generated_h

#define IronKnight_Source_IronKnight_DamageVolume_h_13_SPARSE_DATA
#define IronKnight_Source_IronKnight_DamageVolume_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define IronKnight_Source_IronKnight_DamageVolume_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define IronKnight_Source_IronKnight_DamageVolume_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADamageVolume(); \
	friend struct Z_Construct_UClass_ADamageVolume_Statics; \
public: \
	DECLARE_CLASS(ADamageVolume, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronKnight"), NO_API) \
	DECLARE_SERIALIZER(ADamageVolume)


#define IronKnight_Source_IronKnight_DamageVolume_h_13_INCLASS \
private: \
	static void StaticRegisterNativesADamageVolume(); \
	friend struct Z_Construct_UClass_ADamageVolume_Statics; \
public: \
	DECLARE_CLASS(ADamageVolume, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronKnight"), NO_API) \
	DECLARE_SERIALIZER(ADamageVolume)


#define IronKnight_Source_IronKnight_DamageVolume_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADamageVolume(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADamageVolume) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADamageVolume); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADamageVolume); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADamageVolume(ADamageVolume&&); \
	NO_API ADamageVolume(const ADamageVolume&); \
public:


#define IronKnight_Source_IronKnight_DamageVolume_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADamageVolume(ADamageVolume&&); \
	NO_API ADamageVolume(const ADamageVolume&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADamageVolume); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADamageVolume); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADamageVolume)


#define IronKnight_Source_IronKnight_DamageVolume_h_13_PRIVATE_PROPERTY_OFFSET
#define IronKnight_Source_IronKnight_DamageVolume_h_10_PROLOG
#define IronKnight_Source_IronKnight_DamageVolume_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IronKnight_Source_IronKnight_DamageVolume_h_13_PRIVATE_PROPERTY_OFFSET \
	IronKnight_Source_IronKnight_DamageVolume_h_13_SPARSE_DATA \
	IronKnight_Source_IronKnight_DamageVolume_h_13_RPC_WRAPPERS \
	IronKnight_Source_IronKnight_DamageVolume_h_13_INCLASS \
	IronKnight_Source_IronKnight_DamageVolume_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IronKnight_Source_IronKnight_DamageVolume_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IronKnight_Source_IronKnight_DamageVolume_h_13_PRIVATE_PROPERTY_OFFSET \
	IronKnight_Source_IronKnight_DamageVolume_h_13_SPARSE_DATA \
	IronKnight_Source_IronKnight_DamageVolume_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	IronKnight_Source_IronKnight_DamageVolume_h_13_INCLASS_NO_PURE_DECLS \
	IronKnight_Source_IronKnight_DamageVolume_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IRONKNIGHT_API UClass* StaticClass<class ADamageVolume>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IronKnight_Source_IronKnight_DamageVolume_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
