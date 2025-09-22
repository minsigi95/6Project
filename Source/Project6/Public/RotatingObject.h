#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingObject.generated.h"

UCLASS()
class PROJECT6_API ARotatingObject : public AActor
{
	GENERATED_BODY()

public:
	ARotatingObject();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationSpeed;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	bool bUseLocalRotation;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	bool bRotate;
};
