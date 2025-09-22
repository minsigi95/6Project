
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectItem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogProjectItem, Warning, All);

UCLASS()
class PROJECT6_API AProjectItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectItem();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	float RotationSpeed;

	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	




};
