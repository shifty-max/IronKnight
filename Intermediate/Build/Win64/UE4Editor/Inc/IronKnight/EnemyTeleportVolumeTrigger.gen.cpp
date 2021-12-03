// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IronKnight/EnemyTeleportVolumeTrigger.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyTeleportVolumeTrigger() {}
// Cross Module References
	IRONKNIGHT_API UClass* Z_Construct_UClass_AEnemyTeleportVolumeTrigger_NoRegister();
	IRONKNIGHT_API UClass* Z_Construct_UClass_AEnemyTeleportVolumeTrigger();
	IRONKNIGHT_API UClass* Z_Construct_UClass_AFXVolumeTrigger();
	UPackage* Z_Construct_UPackage__Script_IronKnight();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	IRONKNIGHT_API UClass* Z_Construct_UClass_AEnemy_NoRegister();
// End Cross Module References
	void AEnemyTeleportVolumeTrigger::StaticRegisterNativesAEnemyTeleportVolumeTrigger()
	{
	}
	UClass* Z_Construct_UClass_AEnemyTeleportVolumeTrigger_NoRegister()
	{
		return AEnemyTeleportVolumeTrigger::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Enemy_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Enemy;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AFXVolumeTrigger,
		(UObject* (*)())Z_Construct_UPackage__Script_IronKnight,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "EnemyTeleportVolumeTrigger.h" },
		{ "ModuleRelativePath", "EnemyTeleportVolumeTrigger.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::NewProp_Enemy_MetaData[] = {
		{ "Category", "Spawning" },
		{ "ModuleRelativePath", "EnemyTeleportVolumeTrigger.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::NewProp_Enemy = { "Enemy", nullptr, (EPropertyFlags)0x0014000000000015, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyTeleportVolumeTrigger, Enemy), Z_Construct_UClass_AEnemy_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::NewProp_Enemy_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::NewProp_Enemy_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::NewProp_Enemy,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyTeleportVolumeTrigger>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::ClassParams = {
		&AEnemyTeleportVolumeTrigger::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyTeleportVolumeTrigger()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyTeleportVolumeTrigger_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyTeleportVolumeTrigger, 2513474944);
	template<> IRONKNIGHT_API UClass* StaticClass<AEnemyTeleportVolumeTrigger>()
	{
		return AEnemyTeleportVolumeTrigger::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyTeleportVolumeTrigger(Z_Construct_UClass_AEnemyTeleportVolumeTrigger, &AEnemyTeleportVolumeTrigger::StaticClass, TEXT("/Script/IronKnight"), TEXT("AEnemyTeleportVolumeTrigger"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyTeleportVolumeTrigger);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
