// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IronKnight/MainCameraShake.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainCameraShake() {}
// Cross Module References
	IRONKNIGHT_API UClass* Z_Construct_UClass_UMainCameraShake_NoRegister();
	IRONKNIGHT_API UClass* Z_Construct_UClass_UMainCameraShake();
	ENGINE_API UClass* Z_Construct_UClass_UMatineeCameraShake();
	UPackage* Z_Construct_UPackage__Script_IronKnight();
// End Cross Module References
	void UMainCameraShake::StaticRegisterNativesUMainCameraShake()
	{
	}
	UClass* Z_Construct_UClass_UMainCameraShake_NoRegister()
	{
		return UMainCameraShake::StaticClass();
	}
	struct Z_Construct_UClass_UMainCameraShake_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMainCameraShake_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMatineeCameraShake,
		(UObject* (*)())Z_Construct_UPackage__Script_IronKnight,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMainCameraShake_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MainCameraShake.h" },
		{ "ModuleRelativePath", "MainCameraShake.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMainCameraShake_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMainCameraShake>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMainCameraShake_Statics::ClassParams = {
		&UMainCameraShake::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMainCameraShake_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMainCameraShake_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMainCameraShake()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMainCameraShake_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMainCameraShake, 2867432340);
	template<> IRONKNIGHT_API UClass* StaticClass<UMainCameraShake>()
	{
		return UMainCameraShake::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMainCameraShake(Z_Construct_UClass_UMainCameraShake, &UMainCameraShake::StaticClass, TEXT("/Script/IronKnight"), TEXT("UMainCameraShake"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMainCameraShake);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
