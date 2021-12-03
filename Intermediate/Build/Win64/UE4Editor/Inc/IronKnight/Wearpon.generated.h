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
#ifdef IRONKNIGHT_Wearpon_generated_h
#error "Wearpon.generated.h already included, missing '#pragma once' in Wearpon.h"
#endif
#define IRONKNIGHT_Wearpon_generated_h

#define IronKnight_Source_IronKnight_Wearpon_h_24_SPARSE_DATA
#define IronKnight_Source_IronKnight_Wearpon_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDeactivateCollision); \
	DECLARE_FUNCTION(execActivateCollision); \
	DECLARE_FUNCTION(execCombatOnOverlapEnd); \
	DECLARE_FUNCTION(execCombatOnOverlapBegin);


#define IronKnight_Source_IronKnight_Wearpon_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDeactivateCollision); \
	DECLARE_FUNCTION(execActivateCollision); \
	DECLARE_FUNCTION(execCombatOnOverlapEnd); \
	DECLARE_FUNCTION(execCombatOnOverlapBegin);


#define IronKnight_Source_IronKnight_Wearpon_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWearpon(); \
	friend struct Z_Construct_UClass_AWearpon_Statics; \
public: \
	DECLARE_CLASS(AWearpon, AItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronKnight"), NO_API) \
	DECLARE_SERIALIZER(AWearpon)


#define IronKnight_Source_IronKnight_Wearpon_h_24_INCLASS \
private: \
	static void StaticRegisterNativesAWearpon(); \
	friend struct Z_Construct_UClass_AWearpon_Statics; \
public: \
	DECLARE_CLASS(AWearpon, AItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronKnight"), NO_API) \
	DECLARE_SERIALIZER(AWearpon)


#define IronKnight_Source_IronKnight_Wearpon_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWearpon(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWearpon) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWearpon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWearpon); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWearpon(AWearpon&&); \
	NO_API AWearpon(const AWearpon&); \
public:


#define IronKnight_Source_IronKnight_Wearpon_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWearpon(AWearpon&&); \
	NO_API AWearpon(const AWearpon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWearpon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWearpon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWearpon)


#define IronKnight_Source_IronKnight_Wearpon_h_24_PRIVATE_PROPERTY_OFFSET
#define IronKnight_Source_IronKnight_Wearpon_h_21_PROLOG
#define IronKnight_Source_IronKnight_Wearpon_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IronKnight_Source_IronKnight_Wearpon_h_24_PRIVATE_PROPERTY_OFFSET \
	IronKnight_Source_IronKnight_Wearpon_h_24_SPARSE_DATA \
	IronKnight_Source_IronKnight_Wearpon_h_24_RPC_WRAPPERS \
	IronKnight_Source_IronKnight_Wearpon_h_24_INCLASS \
	IronKnight_Source_IronKnight_Wearpon_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IronKnight_Source_IronKnight_Wearpon_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IronKnight_Source_IronKnight_Wearpon_h_24_PRIVATE_PROPERTY_OFFSET \
	IronKnight_Source_IronKnight_Wearpon_h_24_SPARSE_DATA \
	IronKnight_Source_IronKnight_Wearpon_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	IronKnight_Source_IronKnight_Wearpon_h_24_INCLASS_NO_PURE_DECLS \
	IronKnight_Source_IronKnight_Wearpon_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IRONKNIGHT_API UClass* StaticClass<class AWearpon>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IronKnight_Source_IronKnight_Wearpon_h


#define FOREACH_ENUM_EWEARPONSTATE(op) \
	op(EWearponState::EWS_Pickup) \
	op(EWearponState::EWS_Equipped) \
	op(EWearponState::EWS_Max) 

enum class EWearponState : uint8;
template<> IRONKNIGHT_API UEnum* StaticEnum<EWearponState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
