#include "Character/DustPlayerCharacter.h"
#include "DustGameplayTags.h"
#include "DustPawnData.h"
#include "EnhancedInputSubsystems.h"
#include "Input/DustInputComponent.h"

ADustPlayerCharacter::ADustPlayerCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void ADustPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (const APlayerController* PlayerController = GetController<APlayerController>())
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = 
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (Subsystem)
		{
			Subsystem->AddMappingContext(PawnData->InputMapping, 0);
		}
	}
	
	UDustInputComponent* DustInputComponent = CastChecked<UDustInputComponent>(PlayerInputComponent);
	DustInputComponent->BindNativeAction(PawnData->InputConfig, DustGameplayTags::Input_Action_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move, false);
	DustInputComponent->BindNativeAction(PawnData->InputConfig, DustGameplayTags::Input_Action_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look, false);
}

void ADustPlayerCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	if (Controller)
	{
		const FVector2D MoveInput = InputActionValue.Get<FVector2D>();
		const FRotator MovementRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
		
		if (MoveInput.X != 0.0f)
		{
			const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
			AddMovementInput(RightDirection, MoveInput.X);
		}
		
		if (MoveInput.Y != 0.0f)
		{
			const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
			AddMovementInput(ForwardDirection, MoveInput.Y);
		}
	}
}

void ADustPlayerCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookInput = InputActionValue.Get<FVector2D>();
	
	if (LookInput.X != 0.0f)
	{
		AddControllerYawInput(LookInput.X);
	}
	
	if (LookInput.Y != 0.0f)
	{
		AddControllerPitchInput(LookInput.Y);
	}
}

UDustPawnData* ADustPlayerCharacter::GetPawnData() const
{
	return PawnData;
}
