// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IronKnight/FloatingPlatform.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFloatingPlatform() {}
// Cross Module References
	IRONKNIGHT_API UClass* Z_Construct_UClass_AFloatingPlatform_NoRegister();
	IRONKNIGHT_API UClass* Z_Construct_UClass_AFloatingPlatform();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_IronKnight();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	void AFloatingPlatform::StaticRegisterNativesAFloatingPlatform()
	{
	}
	UClass* Z_Construct_UClass_AFloatingPlatform_NoRegister()
	{
		return AFloatingPlatform::StaticClass();
	}
	struct Z_Construct_UClass_AFloatingPlatform_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlatformAudioComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlatformAudioComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StartPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_StartPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EndPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_EndPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InterpSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InterpSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InterpTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InterpTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoundRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SoundRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bInterping_MetaData[];
#endif
		static void NewProp_bInterping_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInterping;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFloatingPlatform_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_IronKnight,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingPlatform_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FloatingPlatform.h" },
		{ "ModuleRelativePath", "FloatingPlatform.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "Platform" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FloatingPlatform.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x001000000008081d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFloatingPlatform, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_Mesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_Mesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_PlatformAudioComponent_MetaData[] = {
		{ "Category", "Platform | Audio" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FloatingPlatform.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_PlatformAudioComponent = { "PlatformAudioComponent", nullptr, (EPropertyFlags)0x001000000008001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFloatingPlatform, PlatformAudioComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_PlatformAudioComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_PlatformAudioComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_StartPoint_MetaData[] = {
		{ "Category", "FloatingPlatform" },
		{ "ModuleRelativePath", "FloatingPlatform.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_StartPoint = { "StartPoint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFloatingPlatform, StartPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_StartPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_StartPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_EndPoint_MetaData[] = {
		{ "Category", "FloatingPlatform" },
		{ "Comment", "//This variable wil be an editable widget for easy interaction in the editor\n" },
		{ "MakeEditWidget", "true" },
		{ "ModuleRelativePath", "FloatingPlatform.h" },
		{ "ToolTip", "This variable wil be an editable widget for easy interaction in the editor" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_EndPoint = { "EndPoint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFloatingPlatform, EndPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_EndPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_EndPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_InterpSpeed_MetaData[] = {
		{ "Category", "Platform" },
		{ "ModuleRelativePath", "FloatingPlatform.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_InterpSpeed = { "InterpSpeed", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFloatingPlatform, InterpSpeed), METADATA_PARAMS(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_InterpSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_InterpSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_InterpTime_MetaData[] = {
		{ "Category", "Platform" },
		{ "ModuleRelativePath", "FloatingPlatform.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_InterpTime = { "InterpTime", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFloatingPlatform, InterpTime), METADATA_PARAMS(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_InterpTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_InterpTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_SoundRadius_MetaData[] = {
		{ "Category", "Platform" },
		{ "ModuleRelativePath", "FloatingPlatform.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_SoundRadius = { "SoundRadius", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFloatingPlatform, SoundRadius), METADATA_PARAMS(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_SoundRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_SoundRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_CurrentSpeed_MetaData[] = {
		{ "Category", "Platform" },
		{ "ModuleRelativePath", "FloatingPlatform.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_CurrentSpeed = { "CurrentSpeed", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFloatingPlatform, CurrentSpeed), METADATA_PARAMS(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_CurrentSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_CurrentSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_bInterping_MetaData[] = {
		{ "Category", "Platform" },
		{ "ModuleRelativePath", "FloatingPlatform.h" },
	};
#endif
	void Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_bInterping_SetBit(void* Obj)
	{
		((AFloatingPlatform*)Obj)->bInterping = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_bInterping = { "bInterping", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AFloatingPlatform), &Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_bInterping_SetBit, METADATA_PARAMS(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_bInterping_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_bInterping_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFloatingPlatform_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_Mesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_PlatformAudioComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_StartPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_EndPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_InterpSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_InterpTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_SoundRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_CurrentSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingPlatform_Statics::NewProp_bInterping,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFloatingPlatform_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFloatingPlatform>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFloatingPlatform_Statics::ClassParams = {
		&AFloatingPlatform::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFloatingPlatform_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingPlatform_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFloatingPlatform_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingPlatform_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFloatingPlatform()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFloatingPlatform_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFloatingPlatform, 4158164760);
	template<> IRONKNIGHT_API UClass* StaticClass<AFloatingPlatform>()
	{
		return AFloatingPlatform::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFloatingPlatform(Z_Construct_UClass_AFloatingPlatform, &AFloatingPlatform::StaticClass, TEXT("/Script/IronKnight"), TEXT("AFloatingPlatform"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFloatingPlatform);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
