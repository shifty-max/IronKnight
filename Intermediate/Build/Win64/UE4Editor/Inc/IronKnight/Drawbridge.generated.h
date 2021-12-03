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
#ifdef IRONKNIGHT_Drawbridge_generated_h
#error "Drawbridge.generated.h already included, missing '#pragma once' in Drawbridge.h"
#endif
#define IRONKNIGHT_Drawbridge_generated_h

#define IronKnight_Source_IronKnight_Drawbridge_h_12_SPARSE_DATA
#define IronKnight_Source_IronKnight_Drawbridge_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define IronKnight_Source_IronKnight_Drawbridge_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define IronKnight_Source_IronKnight_Drawbridge_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADrawbridge(); \
	friend struct Z_Construct_UClass_ADrawbridge_Statics; \
public: \
	DECLARE_CLASS(ADrawbridge, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronKnight"), NO_API) \
	DECLARE_SERIALIZER(ADrawbridge)


#define IronKnight_Source_IronKnight_Drawbridge_h_12_INCLASS \
private: \
	static void StaticRegisterNativesADrawbridge(); \
	friend struct Z_Construct_UClass_ADrawbridge_Statics; \
public: \
	DECLARE_CLASS(ADrawbridge, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronKnight"), NO_API) \
	DECLARE_SERIALIZER(ADrawbridge)


#define IronKnight_Source_IronKnight_Drawbridge_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADrawbridge(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADrawbridge) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADrawbridge); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADrawbridge); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADrawbridge(ADrawbridge&&); \
	NO_API ADrawbridge(const ADrawbridge&); \
public:


#define IronKnight_Source_IronKnight_Drawbridge_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADrawbridge(ADrawbridge&&); \
	NO_API ADrawbridge(const ADrawbridge&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADrawbridge); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADrawbridge); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADrawbridge)


#define IronKnight_Source_IronKnight_Drawbridge_h_12_PRIVATE_PROPERTY_OFFSET
#define IronKnight_Source_IronKnight_Drawbridge_h_9_PROLOG
#define IronKnight_Source_IronKnight_Drawbridge_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IronKnight_Source_IronKnight_Drawbridge_h_12_PRIVATE_PROPERTY_OFFSET \
	IronKnight_Source_IronKnight_Drawbridge_h_12_SPARSE_DATA \
	IronKnight_Source_IronKnight_Drawbridge_h_12_RPC_WRAPPERS \
	IronKnight_Source_IronKnight_Drawbridge_h_12_INCLASS \
	IronKnight_Source_IronKnight_Drawbridge_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IronKnight_Source_IronKnight_Drawbridge_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IronKnight_Source_IronKnight_Drawbridge_h_12_PRIVATE_PROPERTY_OFFSET \
	IronKnight_Source_IronKnight_Drawbridge_h_12_SPARSE_DATA \
	IronKnight_Source_IronKnight_Drawbridge_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	IronKnight_Source_IronKnight_Drawbridge_h_12_INCLASS_NO_PURE_DECLS \
	IronKnight_Source_IronKnight_Drawbridge_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IRONKNIGHT_API UClass* StaticClass<class ADrawbridge>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IronKnight_Source_IronKnight_Drawbridge_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
