#pragma once

#include "Engine/DataAsset.h"
#include "DustPawnData.generated.h"

class UDustInputConfig;
class UInputMappingContext;

UCLASS()
class DUST_API UDustPawnData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Dust|Pawn")
	TObjectPtr<UDustInputConfig> InputConfig;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Dust|Pawn")
	TObjectPtr<UInputMappingContext> InputMapping;
};
