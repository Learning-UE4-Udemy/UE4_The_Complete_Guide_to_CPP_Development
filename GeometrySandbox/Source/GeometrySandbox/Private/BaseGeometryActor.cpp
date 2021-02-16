// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	//PrintTypec()


}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGeometryActor::PrintTypes() {
	int WeaponsNum = 4;
	int KillsNum = 7;
	float Health = 34.435235f;
	bool IsDead = false;
	bool HasWeapon = true;

	UE_LOG(LogTemp, Display, TEXT("Weapons num: %d, kills num: %i"), WeaponsNum, KillsNum);
	UE_LOG(LogTemp, Display, TEXT("Heals: %f"), Health);
	UE_LOG(LogTemp, Display, TEXT("Heals: %.2f"), Health);
	UE_LOG(LogTemp, Display, TEXT("IsDead: %d"), IsDead);
	UE_LOG(LogTemp, Display, TEXT("HasWeapon: %d"), static_cast<int>(HasWeapon));
}

