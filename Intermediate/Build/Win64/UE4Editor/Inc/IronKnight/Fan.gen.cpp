// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IronKnight/Fan.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFan() {}
// Cross Module References
	IRONKNIGHT_API UClass* Z_Construct_UClass_AFan_NoRegister();
	IRONKNIGHT_API UClass* Z_Construct_UClass_AFan();
	IRONKNIGHT_API UClass* Z_Construct_UClass_AItem();
	UPackage* Z_Construct_UPackage__Script_IronKnight();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
// End Cross Module References
	void AFan::StaticRegisterNativesAFan()
	{
	}
	UClass* Z_Construct_UClass_AFan_NoRegister()
	{
		return AFan::StaticClass();
	}
	struct Z_Construct_UClass_AFan_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bCameraShake_MetaData[];
#endif
		static void NewProp_bCameraShake_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bCameraShake;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraShake_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CameraShake;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraColorFade_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CameraColorFade;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraOpacityFade_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CameraOpacityFade;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraFadeTiming_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CameraFadeTiming;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Damage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BladeCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_BladeCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageTimeDelay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DamageTimeDelay;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FanBladesMesh_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FanBladesMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_FanBladesMesh;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FanBladesCollisions_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FanBladesCollisions_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_FanBladesCollisions;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageTypeClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_DamageTypeClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFan_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AItem,
		(UObject* (*)())Z_Construct_UPackage__Script_IronKnight,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Fan.h" },
		{ "ModuleRelativePath", "Fan.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::NewProp_bCameraShake_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Fan.h" },
	};
#endif
	void Z_Construct_UClass_AFan_Statics::NewProp_bCameraShake_SetBit(void* Obj)
	{
		((AFan*)Obj)->bCameraShake = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_bCameraShake = { "bCameraShake", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AFan), &Z_Construct_UClass_AFan_Statics::NewProp_bCameraShake_SetBit, METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::NewProp_bCameraShake_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::NewProp_bCameraShake_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::NewProp_CameraShake_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Fan.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_CameraShake = { "CameraShake", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFan, CameraShake), METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::NewProp_CameraShake_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::NewProp_CameraShake_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::NewProp_CameraColorFade_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Fan.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_CameraColorFade = { "CameraColorFade", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFan, CameraColorFade), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::NewProp_CameraColorFade_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::NewProp_CameraColorFade_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::NewProp_CameraOpacityFade_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Fan.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_CameraOpacityFade = { "CameraOpacityFade", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFan, CameraOpacityFade), METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::NewProp_CameraOpacityFade_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::NewProp_CameraOpacityFade_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::NewProp_CameraFadeTiming_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Fan.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_CameraFadeTiming = { "CameraFadeTiming", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFan, CameraFadeTiming), METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::NewProp_CameraFadeTiming_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::NewProp_CameraFadeTiming_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::NewProp_Damage_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "Fan.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFan, Damage), METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::NewProp_Damage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::NewProp_Damage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::NewProp_BladeCount_MetaData[] = {
		{ "Category", "Fan | Collision" },
		{ "Comment", "//we can set fan blades count here and pass it as argument to TArray FanBladesMesh\n" },
		{ "ModuleRelativePath", "Fan.h" },
		{ "ToolTip", "we can set fan blades count here and pass it as argument to TArray FanBladesMesh" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_BladeCount = { "BladeCount", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFan, BladeCount), METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::NewProp_BladeCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::NewProp_BladeCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::NewProp_DamageTimeDelay_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "Fan.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_DamageTimeDelay = { "DamageTimeDelay", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFan, DamageTimeDelay), METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::NewProp_DamageTimeDelay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::NewProp_DamageTimeDelay_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_FanBladesMesh_Inner = { "FanBladesMesh", nullptr, (EPropertyFlags)0x00000000000a0008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::NewProp_FanBladesMesh_MetaData[] = {
		{ "Category", "Fan | Mesh" },
		{ "Comment", "//Array for blade mashes\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fan.h" },
		{ "ToolTip", "Array for blade mashes" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_FanBladesMesh = { "FanBladesMesh", nullptr, (EPropertyFlags)0x001000800002000d, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFan, FanBladesMesh), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::NewProp_FanBladesMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::NewProp_FanBladesMesh_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_FanBladesCollisions_Inner = { "FanBladesCollisions", nullptr, (EPropertyFlags)0x00000000000a0008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::NewProp_FanBladesCollisions_MetaData[] = {
		{ "Category", "Fan | Collision" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fan.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_FanBladesCollisions = { "FanBladesCollisions", nullptr, (EPropertyFlags)0x001000800002000d, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFan, FanBladesCollisions), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::NewProp_FanBladesCollisions_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::NewProp_FanBladesCollisions_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFan_Statics::NewProp_DamageTypeClass_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "Fan.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFan_Statics::NewProp_DamageTypeClass = { "DamageTypeClass", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFan, DamageTypeClass), Z_Construct_UClass_UDamageType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::NewProp_DamageTypeClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::NewProp_DamageTypeClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFan_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_bCameraShake,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_CameraShake,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_CameraColorFade,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_CameraOpacityFade,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_CameraFadeTiming,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_Damage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_BladeCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_DamageTimeDelay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_FanBladesMesh_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_FanBladesMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_FanBladesCollisions_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_FanBladesCollisions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFan_Statics::NewProp_DamageTypeClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFan_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFan>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFan_Statics::ClassParams = {
		&AFan::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFan_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFan_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFan_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFan()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFan_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFan, 4189518621);
	template<> IRONKNIGHT_API UClass* StaticClass<AFan>()
	{
		return AFan::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFan(Z_Construct_UClass_AFan, &AFan::StaticClass, TEXT("/Script/IronKnight"), TEXT("AFan"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFan);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
