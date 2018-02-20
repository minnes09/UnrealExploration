// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BATTERYCOLLECTOR_OwnSphere_generated_h
#error "OwnSphere.generated.h already included, missing '#pragma once' in OwnSphere.h"
#endif
#define BATTERYCOLLECTOR_OwnSphere_generated_h

#define BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_RPC_WRAPPERS
#define BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUOwnSphere(); \
	friend BATTERYCOLLECTOR_API class UClass* Z_Construct_UClass_UOwnSphere(); \
	public: \
	DECLARE_CLASS(UOwnSphere, USphereComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/BatteryCollector"), NO_API) \
	DECLARE_SERIALIZER(UOwnSphere) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_INCLASS \
	private: \
	static void StaticRegisterNativesUOwnSphere(); \
	friend BATTERYCOLLECTOR_API class UClass* Z_Construct_UClass_UOwnSphere(); \
	public: \
	DECLARE_CLASS(UOwnSphere, USphereComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/BatteryCollector"), NO_API) \
	DECLARE_SERIALIZER(UOwnSphere) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOwnSphere(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOwnSphere) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOwnSphere); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOwnSphere); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UOwnSphere(const UOwnSphere& InCopy); \
public:


#define BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOwnSphere(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UOwnSphere(const UOwnSphere& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOwnSphere); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOwnSphere); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOwnSphere)


#define BatteryCollector_Source_BatteryCollector_OwnSphere_h_11_PROLOG
#define BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_RPC_WRAPPERS \
	BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_INCLASS \
	BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_INCLASS_NO_PURE_DECLS \
	BatteryCollector_Source_BatteryCollector_OwnSphere_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BatteryCollector_Source_BatteryCollector_OwnSphere_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
