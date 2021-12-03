// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IronKnight/FirstSaveGame.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFirstSaveGame() {}
// Cross Module References
	IRONKNIGHT_API UScriptStruct* Z_Construct_UScriptStruct_FCharactesStats();
	UPackage* Z_Construct_UPackage__Script_IronKnight();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	IRONKNIGHT_API UClass* Z_Construct_UClass_UFirstSaveGame_NoRegister();
	IRONKNIGHT_API UClass* Z_Construct_UClass_UFirstSaveGame();
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
// End Cross Module References
class UScriptStruct* FCharactesStats::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern IRONKNIGHT_API uint32 Get_Z_Construct_UScriptStruct_FCharactesStats_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCharactesStats, Z_Construct_UPackage__Script_IronKnight(), TEXT("CharactesStats"), sizeof(FCharactesStats), Get_Z_Construct_UScriptStruct_FCharactesStats_Hash());
	}
	return Singleton;
}
template<> IRONKNIGHT_API UScriptStruct* StaticStruct<FCharactesStats>()
{
	return FCharactesStats::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCharactesStats(FCharactesStats::StaticStruct, TEXT("/Script/IronKnight"), TEXT("CharactesStats"), false, nullptr, nullptr);
static struct FScriptStruct_IronKnight_StaticRegisterNativesFCharactesStats
{
	FScriptStruct_IronKnight_StaticRegisterNativesFCharactesStats()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("CharactesStats")),new UScriptStruct::TCppStructOps<FCharactesStats>);
	}
} ScriptStruct_IronKnight_StaticRegisterNativesFCharactesStats;
	struct Z_Construct_UScriptStruct_FCharactesStats_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Stamina_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Stamina;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxStamina_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxStamina;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Coins_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Coins;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Rotation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WeaponName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_WeaponName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LevelName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_LevelName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCharactesStats_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "//Struct for saving all needed player's parameters and map name\n" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
		{ "ToolTip", "Struct for saving all needed player's parameters and map name" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCharactesStats_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCharactesStats>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Health_MetaData[] = {
		{ "Category", "SaveGameData" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCharactesStats, Health), METADATA_PARAMS(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Health_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Health_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_MaxHealth_MetaData[] = {
		{ "Category", "SaveGameData" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCharactesStats, MaxHealth), METADATA_PARAMS(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_MaxHealth_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_MaxHealth_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Stamina_MetaData[] = {
		{ "Category", "SaveGameData" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Stamina = { "Stamina", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCharactesStats, Stamina), METADATA_PARAMS(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Stamina_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Stamina_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_MaxStamina_MetaData[] = {
		{ "Category", "SaveGameData" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_MaxStamina = { "MaxStamina", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCharactesStats, MaxStamina), METADATA_PARAMS(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_MaxStamina_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_MaxStamina_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Coins_MetaData[] = {
		{ "Category", "SaveGameData" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Coins = { "Coins", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCharactesStats, Coins), METADATA_PARAMS(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Coins_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Coins_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Location_MetaData[] = {
		{ "Category", "SaveGameData" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCharactesStats, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Rotation_MetaData[] = {
		{ "Category", "SaveGameData" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCharactesStats, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Rotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Rotation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_WeaponName_MetaData[] = {
		{ "Category", "SaveGameData" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_WeaponName = { "WeaponName", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCharactesStats, WeaponName), METADATA_PARAMS(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_WeaponName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_WeaponName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_LevelName_MetaData[] = {
		{ "Category", "SaveGameData" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_LevelName = { "LevelName", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCharactesStats, LevelName), METADATA_PARAMS(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_LevelName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_LevelName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCharactesStats_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Health,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_MaxHealth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Stamina,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_MaxStamina,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Coins,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Location,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_Rotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_WeaponName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharactesStats_Statics::NewProp_LevelName,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCharactesStats_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_IronKnight,
		nullptr,
		&NewStructOps,
		"CharactesStats",
		sizeof(FCharactesStats),
		alignof(FCharactesStats),
		Z_Construct_UScriptStruct_FCharactesStats_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharactesStats_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCharactesStats_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharactesStats_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCharactesStats()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCharactesStats_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_IronKnight();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CharactesStats"), sizeof(FCharactesStats), Get_Z_Construct_UScriptStruct_FCharactesStats_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCharactesStats_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCharactesStats_Hash() { return 3745961673U; }
	void UFirstSaveGame::StaticRegisterNativesUFirstSaveGame()
	{
	}
	UClass* Z_Construct_UClass_UFirstSaveGame_NoRegister()
	{
		return UFirstSaveGame::StaticClass();
	}
	struct Z_Construct_UClass_UFirstSaveGame_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PLayerName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PLayerName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterStats_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CharacterStats;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UserIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_UserIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFirstSaveGame_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGame,
		(UObject* (*)())Z_Construct_UPackage__Script_IronKnight,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFirstSaveGame_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "FirstSaveGame.h" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_PLayerName_MetaData[] = {
		{ "Category", "Basic" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_PLayerName = { "PLayerName", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFirstSaveGame, PLayerName), METADATA_PARAMS(Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_PLayerName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_PLayerName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_CharacterStats_MetaData[] = {
		{ "Category", "Basic" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_CharacterStats = { "CharacterStats", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFirstSaveGame, CharacterStats), Z_Construct_UScriptStruct_FCharactesStats, METADATA_PARAMS(Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_CharacterStats_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_CharacterStats_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_UserIndex_MetaData[] = {
		{ "Category", "Basic" },
		{ "ModuleRelativePath", "FirstSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_UserIndex = { "UserIndex", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFirstSaveGame, UserIndex), METADATA_PARAMS(Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_UserIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_UserIndex_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFirstSaveGame_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_PLayerName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_CharacterStats,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFirstSaveGame_Statics::NewProp_UserIndex,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFirstSaveGame_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFirstSaveGame>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFirstSaveGame_Statics::ClassParams = {
		&UFirstSaveGame::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFirstSaveGame_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFirstSaveGame_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFirstSaveGame_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFirstSaveGame_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFirstSaveGame()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFirstSaveGame_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFirstSaveGame, 4273712737);
	template<> IRONKNIGHT_API UClass* StaticClass<UFirstSaveGame>()
	{
		return UFirstSaveGame::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFirstSaveGame(Z_Construct_UClass_UFirstSaveGame, &UFirstSaveGame::StaticClass, TEXT("/Script/IronKnight"), TEXT("UFirstSaveGame"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFirstSaveGame);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
