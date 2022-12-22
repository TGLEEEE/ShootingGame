// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerFlight.generated.h"

UCLASS()
class SHOOTINGGAME_API APlayerFlight : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerFlight();

	// Collision ����
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=PlayerSettings)
	class UBoxComponent* boxcomp;
	// Mesh ����
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=PlayerSettings)
	class UStaticMeshComponent* meshcomp;

	// �̵��� ���� ���� ����
	FVector direction;
	// �̵��ӵ� ���� ����
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=PlayerSettings)
	float movespeed=800;

	// �Ѿ� �������Ʈ�� ���� �� �ִ� ���� ����
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=PlayerSettings)
	TSubclassOf<class ABullet>bulletfactory;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// �¿��Է��� ������ �� ����� �Լ� ����
	void horizontalinput(float value);
	// �����Է��� ������ �� ����� �Լ� ����
	void verticalinput(float value);
	// Ŭ���Է��� ������ �� ����� �Լ� ����
	void bulletfire();

};
