#pragma once

#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DustInputConfig.generated.h"

class UInputAction;

USTRUCT(BlueprintType)
struct FDustInputAction
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<const UInputAction> InputAction;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories="InputTag"))
	FGameplayTag  InputTag;
};

UCLASS(BlueprintType, Const)
class DUST_API UDustInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UDustInputConfig(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable, Category="Dust|Pawn")
	const UInputAction* FindNativeInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = true) const;
	
	UFUNCTION(BlueprintCallable, Category="Dust|Pawn")
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = true) const;
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(TitleProperty="InputAction"))
	TArray<FDustInputAction> NativeInputActions;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(TitleProperty="InputAction"))
	TArray<FDustInputAction> AbilityInputActions;
};
