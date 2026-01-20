#pragma once

#include "GameFramework/PlayerController.h"
#include "DustPlayerController.generated.h"

UCLASS()
class DUST_API ADustPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ADustPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
protected:
	virtual void BeginPlay() override;
};
