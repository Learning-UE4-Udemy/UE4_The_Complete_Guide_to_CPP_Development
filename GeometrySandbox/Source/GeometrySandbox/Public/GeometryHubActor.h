// Fill out your copyright notice in the Description page of Project Settings.

// Класс отвечает за создание Base Geometry Actors
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGeometryActor.h"
#include "GeometryHubActor.generated.h"

USTRUCT(BlueprintType)
struct FGeometryPayload {
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseGeometryActor> GeometryClass;

	UPROPERTY(EditAnywhere)
		FGeometryData Data;

	UPROPERTY(EditAnywhere)
		FTransform InitialTransform;
};

UCLASS()
class GEOMETRYSANDBOX_API AGeometryHubActor : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGeometryHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Объявление указателя на класс
	// В UE4 есть Шаблон - передаём в шаблон данный тип.
	// TSubclassOf - отфильтрует все доступные классы движка
	// и в Проперти можно выбрать только ABaseGeometryActor
	// или класс который от него наследуется.
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseGeometryActor> GeometryClass;

	// Создадим в учебных целях Проперти
	// с помощью этого можно установить любой доступный класс.
	// Создаём указатель на него.
	UPROPERTY(EditAnywhere)
		UClass* Class;

	// с помощью этого Проперти посмотрим как передать указатель
	// на существующий объект на сцене
	UPROPERTY(EditAnywhere)
		ABaseGeometryActor* GeometryObject;

	UPROPERTY(EditAnywhere)
		TArray<FGeometryPayload> GeometryPayloads;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ABaseGeometryActor* NonePropertyActor;
	
	UPROPERTY()
	ABaseGeometryActor* PropertyActor;

	void DoActorSpawn1();
	void DoActorSpawn2();
	void DoActorSpawn3();
	void DoActorSpawn4();


	UFUNCTION()
		void OnColorChanged(const FLinearColor& Color, const FString& Name);
	void OnTimerFinished(AActor* Actor);
};
