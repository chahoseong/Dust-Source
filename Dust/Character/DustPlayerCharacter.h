#pragma once

#include "DustCharacter.h"
#include "DustPlayerCharacter.generated.h"

struct FInputActionValue;
class UDustPawnData;

UCLASS()
class DUST_API ADustPlayerCharacter : public ADustCharacter
{
	GENERATED_BODY()

public:
	ADustPlayerCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintPure, Category="Dust|Pawn")
	UDustPawnData* GetPawnData() const;
	
private:
	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character")
	TObjectPtr<UDustPawnData> PawnData;
};
