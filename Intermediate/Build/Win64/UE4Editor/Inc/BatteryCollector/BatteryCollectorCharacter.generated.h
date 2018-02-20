// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AInventoryPickup;
#ifdef BATTERYCOLLECTOR_BatteryCollectorCharacter_generated_h
#error "BatteryCollectorCharacter.generated.h already included, missing '#pragma once' in BatteryCollectorCharacter.h"
#endif
#define BATTERYCOLLECTOR_BatteryCollectorCharacter_generated_h

#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_6_DELEGATE \
struct _Script_BatteryCollector_eventUpdateInventoryDelegate_Parms \
{ \
	TArray<AInventoryPickup*> InventoryItems; \
}; \
static inline void FUpdateInventoryDelegate_DelegateWrapper(const FMulticastScriptDelegate& UpdateInventoryDelegate, TArray<AInventoryPickup*> const& InventoryItems) \
{ \
	_Script_BatteryCollector_eventUpdateInventoryDelegate_Parms Parms; \
	Parms.InventoryItems=InventoryItems; \
	UpdateInventoryDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}




#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSpawn) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Spawn(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCollectPickups) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CollectPickups(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateInventory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateInventory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddToInventory) \
	{ \
		P_GET_OBJECT(AInventoryPickup,Z_Param_Pickup); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AddToInventory(Z_Param_Pickup); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdatePower) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PowerChange); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdatePower(Z_Param_PowerChange); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentPower) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetCurrentPower(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInitialPower) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetInitialPower(); \
		P_NATIVE_END; \
	}


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSpawn) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Spawn(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCollectPickups) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CollectPickups(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdateInventory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdateInventory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddToInventory) \
	{ \
		P_GET_OBJECT(AInventoryPickup,Z_Param_Pickup); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AddToInventory(Z_Param_Pickup); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUpdatePower) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_PowerChange); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UpdatePower(Z_Param_PowerChange); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentPower) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetCurrentPower(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetInitialPower) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetInitialPower(); \
		P_NATIVE_END; \
	}


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_EVENT_PARMS
extern BATTERYCOLLECTOR_API  FName BATTERYCOLLECTOR_PowerChangeEffect;
#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_CALLBACK_WRAPPERS
#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesABatteryCollectorCharacter(); \
	friend BATTERYCOLLECTOR_API class UClass* Z_Construct_UClass_ABatteryCollectorCharacter(); \
	public: \
	DECLARE_CLASS(ABatteryCollectorCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/BatteryCollector"), NO_API) \
	DECLARE_SERIALIZER(ABatteryCollectorCharacter) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesABatteryCollectorCharacter(); \
	friend BATTERYCOLLECTOR_API class UClass* Z_Construct_UClass_ABatteryCollectorCharacter(); \
	public: \
	DECLARE_CLASS(ABatteryCollectorCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/BatteryCollector"), NO_API) \
	DECLARE_SERIALIZER(ABatteryCollectorCharacter) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABatteryCollectorCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABatteryCollectorCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABatteryCollectorCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABatteryCollectorCharacter); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ABatteryCollectorCharacter(const ABatteryCollectorCharacter& InCopy); \
public:


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ABatteryCollectorCharacter(const ABatteryCollectorCharacter& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABatteryCollectorCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABatteryCollectorCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABatteryCollectorCharacter)


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_8_PROLOG \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_EVENT_PARMS


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_RPC_WRAPPERS \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_CALLBACK_WRAPPERS \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_INCLASS \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_CALLBACK_WRAPPERS \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_INCLASS_NO_PURE_DECLS \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BatteryCollector_Source_BatteryCollector_BatteryCollectorCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
