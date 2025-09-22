#include "ProjectItem.h"

AProjectItem::AProjectItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/AIUE5_vol10_01/Mesh/SM_AI_vol10_01_wooden_chair_1_1.SM_AI_vol10_01_wooden_chair_1_1"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}


	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/AIUE5_vol10_01/materials/MI_AI_vol10_01_wood_light_01.MI_AI_vol10_01_wood_light_01"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0,MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;

}

void AProjectItem::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(300.0f, 200.0f, 0.0f));
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(2.0f));

	
}

void AProjectItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}