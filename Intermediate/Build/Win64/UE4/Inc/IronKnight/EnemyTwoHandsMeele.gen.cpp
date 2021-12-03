// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IronKnight/EnemyTwoHandsMeele.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyTwoHandsMeele() {}
// Cross Module References
	IRONKNIGHT_API UClass* Z_Construct_UClass_AEnemyTwoHandsMeele_NoRegister();
	IRONKNIGHT_API UClass* Z_Construct_UClass_AEnemyTwoHandsMeele();
	IRONKNIGHT_API UClass* Z_Construct_UClass_AEnemy();
	UPackage* Z_Construct_UPackage__Script_IronKnight();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AEnemyTwoHandsMeele::execBlockCollisionRight)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BlockCollisionRight();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AEnemyTwoHandsMeele::execDeactivateCollisionRight)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DeactivateCollisionRight();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AEnemyTwoHandsMeele::execActivateCollisionRight)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ActivateCollisionRight();
		P_NATIVE_END;
	}
	void AEnemyTwoHandsMeele::StaticRegisterNativesAEnemyTwoHandsMeele()
	{
		UClass* Class = AEnemyTwoHandsMeele::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ActivateCollisionRight", &AEnemyTwoHandsMeele::execActivateCollisionRight },
			{ "BlockCollisionRight", &AEnemyTwoHandsMeele::execBlockCollisionRight },
			{ "DeactivateCollisionRight", &AEnemyTwoHandsMeele::execDeactivateCollisionRight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AEnemyTwoHandsMeele_ActivateCollisionRight_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyTwoHandsMeele_ActivateCollisionRight_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Activate collision for werpon when plays attack animation and finds apropriate anim note\n" },
		{ "ModuleRelativePath", "EnemyTwoHandsMeele.h" },
		{ "ToolTip", "Activate collision for werpon when plays attack animation and finds apropriate anim note" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyTwoHandsMeele_ActivateCollisionRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyTwoHandsMeele, nullptr, "ActivateCollisionRight", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemyTwoHandsMeele_ActivateCollisionRight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyTwoHandsMeele_ActivateCollisionRight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemyTwoHandsMeele_ActivateCollisionRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemyTwoHandsMeele_ActivateCollisionRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEnemyTwoHandsMeele_BlockCollisionRight_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyTwoHandsMeele_BlockCollisionRight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EnemyTwoHandsMeele.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyTwoHandsMeele_BlockCollisionRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyTwoHandsMeele, nullptr, "BlockCollisionRight", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemyTwoHandsMeele_BlockCollisionRight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyTwoHandsMeele_BlockCollisionRight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemyTwoHandsMeele_BlockCollisionRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemyTwoHandsMeele_BlockCollisionRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEnemyTwoHandsMeele_DeactivateCollisionRight_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyTwoHandsMeele_DeactivateCollisionRight_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Dectivate collision for werpon when attack animation is almost finished and finds apropriate anim note\n" },
		{ "ModuleRelativePath", "EnemyTwoHandsMeele.h" },
		{ "ToolTip", "Dectivate collision for werpon when attack animation is almost finished and finds apropriate anim note" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyTwoHandsMeele_DeactivateCollisionRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyTwoHandsMeele, nullptr, "DeactivateCollisionRight", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AEnemyTwoHandsMeele_DeactivateCollisionRight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyTwoHandsMeele_DeactivateCollisionRight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AEnemyTwoHandsMeele_DeactivateCollisionRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AEnemyTwoHandsMeele_DeactivateCollisionRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AEnemyTwoHandsMeele_NoRegister()
	{
		return AEnemyTwoHandsMeele::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyTwoHandsMeele_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CombatCollisionRight_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CombatCollisionRight;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemy,
		(UObject* (*)())Z_Construct_UPackage__Script_IronKnight,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemyTwoHandsMeele_ActivateCollisionRight, "ActivateCollisionRight" }, // 4003980927
		{ &Z_Construct_UFunction_AEnemyTwoHandsMeele_BlockCollisionRight, "BlockCollisionRight" }, // 2036585904
		{ &Z_Construct_UFunction_AEnemyTwoHandsMeele_DeactivateCollisionRight, "DeactivateCollisionRight" }, // 2109450859
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemyTwoHandsMeele.h" },
		{ "ModuleRelativePath", "EnemyTwoHandsMeele.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::NewProp_CombatCollisionRight_MetaData[] = {
		{ "Category", "Combat" },
		{ "Comment", "//Weapon collision for second hand when overlaps by a player he loosing health\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EnemyTwoHandsMeele.h" },
		{ "ToolTip", "Weapon collision for second hand when overlaps by a player he loosing health" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::NewProp_CombatCollisionRight = { "CombatCollisionRight", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEnemyTwoHandsMeele, CombatCollisionRight), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::NewProp_CombatCollisionRight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::NewProp_CombatCollisionRight_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::NewProp_CombatCollisionRight,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyTwoHandsMeele>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::ClassParams = {
		&AEnemyTwoHandsMeele::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyTwoHandsMeele()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyTwoHandsMeele_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyTwoHandsMeele, 592899485);
	template<> IRONKNIGHT_API UClass* StaticClass<AEnemyTwoHandsMeele>()
	{
		return AEnemyTwoHandsMeele::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyTwoHandsMeele(Z_Construct_UClass_AEnemyTwoHandsMeele, &AEnemyTwoHandsMeele::StaticClass, TEXT("/Script/IronKnight"), TEXT("AEnemyTwoHandsMeele"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyTwoHandsMeele);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
