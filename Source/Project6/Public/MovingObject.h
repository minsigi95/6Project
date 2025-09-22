#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingObject.generated.h"

UCLASS()
class PROJECT6_API AMovingObject : public AActor
{
	GENERATED_BODY()

public:
	AMovingObject();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector MoveDirection;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "0.0"))
	float MoveSpeed;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "0.0"))
	float MaxDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool bStartForward;

private:
	FVector StartLocation;
	FVector MoveDirNormalized;
	float CurrentDistance;
	bool bMovingForward;
};
