#include "Input/DustInputComponent.h"

UDustInputComponent::UDustInputComponent(const FObjectInitializer& ObjectInitializer)
{
}

void UDustInputComponent::AddInputMappings(const UDustInputConfig* Config,
	UEnhancedInputLocalPlayerSubsystem* Subsystem) const
{
	check(Config);
	check(Subsystem);
	
	// Here you can handle any custom logic to add something from your input config if required
}

void UDustInputComponent::RemoveInputMappings(const UDustInputConfig* Config,
	UEnhancedInputLocalPlayerSubsystem* Subsystem) const
{
	check(Config);
	check(Subsystem);
	
	// Here you can handle any custom logic to remove input mappings that you may have added above
}

void UDustInputComponent::RemoveBindings(TArray<uint32>& BindHandles)
{
	for (uint32 Handle : BindHandles)
	{
		RemoveBindingByHandle(Handle);
	}
	BindHandles.Reset();
}
