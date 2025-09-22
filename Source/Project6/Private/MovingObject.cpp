#include "MovingObject.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/KismetMathLibrary.h"

AMovingObject::AMovingObject()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComp);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(CubeMesh.Object);
	}

	MoveDirection = FVector(1.f, 0.f, 0.f);
	MoveSpeed = 200.f; 
	MaxDistance = 500.f;
	bStartForward = true;

	CurrentDistance = 0.f;
	bMovingForward = true;
}

void AMovingObject::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	MoveDirNormalized = MoveDirection.IsNearlyZero() ? FVector::ForwardVector : MoveDirection.GetSafeNormal();
	CurrentDistance = bStartForward ? 0.f : MaxDistance;
	bMovingForward = bStartForward;

	
}

void AMovingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	FVector WorldDirection = GetActorRotation().RotateVector(MoveDirection.GetSafeNormal());

	float MoveStep = MoveSpeed * DeltaTime;
	CurrentDistance += (bMovingForward ? MoveStep : -MoveStep);

	
	if (FMath::Abs(CurrentDistance) >= MaxDistance)
	{
		bMovingForward = !bMovingForward;
		CurrentDistance = FMath::Clamp(CurrentDistance, -MaxDistance, MaxDistance);
	}

	
	SetActorLocation(StartLocation + WorldDirection * CurrentDistance);
}