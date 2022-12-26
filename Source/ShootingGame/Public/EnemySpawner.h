// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class SHOOTINGGAME_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	// �ð��� �������� �����ϴ� ���� ���� ����
	float currentTime;
	// ���� �ð��� �Ǹ� ���� �����ǰԲ�
	UPROPERTY(EditInstanceOnly, Category=EnemySettings)
	float spawnTime=2;
	// ������ �������Ʈ ����â �����
	UPROPERTY(EditInstanceOnly, Category=EnemySettings)
	TSubclassOf <class AEnemy> enemyFactory;

	// �ַο� ���̱� ���� ���� �Բ� ����
	UPROPERTY(EditInstanceOnly, Category = EnemySettings)
	class UArrowComponent* spawnArrow;
	UPROPERTY(EditInstanceOnly, Category = EnemySettings)
	class USceneComponent* rootScene;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
