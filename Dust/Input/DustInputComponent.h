#pragma once

#include "DustInputConfig.h"
#include "EnhancedInputComponent.h"
#include "DustInputComponent.generated.h"

struct FGameplayTag;
class UDustInputConfig;
class UEnhancedInputLocalPlayerSubsystem;

UCLASS()
class DUST_API UDustInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	UDustInputComponent(const FObjectInitializer& ObjectInitializer);

	void AddInputMappings(const UDustInputConfig* Config, UEnhancedInputLocalPlayerSubsystem* Subsystem) const;
	void RemoveInputMappings(const UDustInputConfig* Config, UEnhancedInputLocalPlayerSubsystem* Subsystem) const;
	
	template <typename UserClass, typename FuncType>
	void BindNativeAction(const UDustInputConfig* Config, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType&& Func, bool bLogIfNotFound)
	{
		check(Config);
		
		if (const UInputAction* Action = Config->FindNativeInputActionForTag(InputTag, bLogIfNotFound))
		{
			BindAction(Action, TriggerEvent, Object, std::forward<FuncType>(Func));
		}
	}
	
	template <typename UserClass, typename PressedFuncType, typename ReleasedFuncType>
	void BindAbilityActions(const UDustInputConfig* Config, const FGameplayTag& InputTag, UserClass* Object, PressedFuncType&& PressedFunc, ReleasedFuncType&& ReleasedFunc, TArray<uint32>& BindHandles)
	{
		check(Config);
		
		for (const FDustInputAction& Action : Config->AbilityInputActions)
		{
			if (Action.InputAction && Action.InputTag.IsValid())
			{
				if (PressedFunc)
				{
					BindHandles.Add(BindAction(Action.InputAction, ETriggerEvent::Triggered, Object, std::forward<PressedFuncType>(PressedFunc), Action.InputTag).GetHandle());
				}
				
				if (ReleasedFunc)
				{
					BindHandles.Add(BindAction(Action.InputAction, ETriggerEvent::Completed, Object, std::forward<ReleasedFuncType>(ReleasedFunc), Action.InputTag).GetHandle());
				}
			}
		}
	}
	
	void RemoveBindings(TArray<uint32>& BindHandles);
};
