// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AMain;
#ifdef IRONKNIGHT_Pickup_generated_h
#error "Pickup.generated.h already included, missing '#pragma once' in Pickup.h"
#endif
#define IRONKNIGHT_Pickup_generated_h

#define IronKnight_Source_IronKnight_Pickup_h_16_SPARSE_DATA
#define IronKnight_Source_IronKnight_Pickup_h_16_RPC_WRAPPERS
#define IronKnight_Source_IronKnight_Pickup_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define IronKnight_Source_IronKnight_Pickup_h_16_EVENT_PARMS \
	struct Pickup_eventOnPickupBP_Parms \
	{ \
		AMain* MainCharacter; \
	};


#define IronKnight_Source_IronKnight_Pickup_h_16_CALLBACK_WRAPPERS
#define IronKnight_Source_IronKnight_Pickup_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPickup(); \
	friend struct Z_Construct_UClass_APickup_Statics; \
public: \
	DECLARE_CLASS(APickup, AItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronKnight"), NO_API) \
	DECLARE_SERIALIZER(APickup)


#define IronKnight_Source_IronKnight_Pickup_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAPickup(); \
	friend struct Z_Construct_UClass_APickup_Statics; \
public: \
	DECLARE_CLASS(APickup, AItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronKnight"), NO_API) \
	DECLARE_SERIALIZER(APickup)


#define IronKnight_Source_IronKnight_Pickup_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APickup(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APickup) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup(APickup&&); \
	NO_API APickup(const APickup&); \
public:


#define IronKnight_Source_IronKnight_Pickup_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup(APickup&&); \
	NO_API APickup(const APickup&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APickup)


#define IronKnight_Source_IronKnight_Pickup_h_16_PRIVATE_PROPERTY_OFFSET
#define IronKnight_Source_IronKnight_Pickup_h_13_PROLOG \
	IronKnight_Source_IronKnight_Pickup_h_16_EVENT_PARMS


#define IronKnight_Source_IronKnight_Pickup_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IronKnight_Source_IronKnight_Pickup_h_16_PRIVATE_PROPERTY_OFFSET \
	IronKnight_Source_IronKnight_Pickup_h_16_SPARSE_DATA \
	IronKnight_Source_IronKnight_Pickup_h_16_RPC_WRAPPERS \
	IronKnight_Source_IronKnight_Pickup_h_16_CALLBACK_WRAPPERS \
	IronKnight_Source_IronKnight_Pickup_h_16_INCLASS \
	IronKnight_Source_IronKnight_Pickup_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define IronKnight_Source_IronKnight_Pickup_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	IronKnight_Source_IronKnight_Pickup_h_16_PRIVATE_PROPERTY_OFFSET \
	IronKnight_Source_IronKnight_Pickup_h_16_SPARSE_DATA \
	IronKnight_Source_IronKnight_Pickup_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	IronKnight_Source_IronKnight_Pickup_h_16_CALLBACK_WRAPPERS \
	IronKnight_Source_IronKnight_Pickup_h_16_INCLASS_NO_PURE_DECLS \
	IronKnight_Source_IronKnight_Pickup_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IRONKNIGHT_API UClass* StaticClass<class APickup>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID IronKnight_Source_IronKnight_Pickup_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
