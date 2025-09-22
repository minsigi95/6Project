
#include "RotatingObject.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

ARotatingObject::ARotatingObject()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComp);

	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(CubeMesh.Object);
	}

	RotationSpeed = 90.f; 
	bUseLocalRotation = true;
	bRotate = true;
}

void ARotatingObject::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotatingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bRotate || FMath::IsNearlyZero(RotationSpeed) || FMath::IsNearlyZero(DeltaTime))
	{
		return;
	}

	
	FRotator DeltaRot = FRotator(0.f, RotationSpeed * DeltaTime, 0.f);

	if (bUseLocalRotation)
	{
		AddActorLocalRotation(DeltaRot);
	}
	else
	{
		AddActorWorldRotation(DeltaRot);
	}
}
