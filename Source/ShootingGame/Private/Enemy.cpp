// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Item.h"
#include "components/BoxComponent.h"
#include "components/StaticMeshComponent.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �ڽ� �ݸ��� ����
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50));

	// �޽� ����
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	meshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �� �̵� ���� p=p0+vt
	direction = GetActorForwardVector();
	SetActorLocation(GetActorLocation() + direction * enemySpeed * DeltaTime);
	
}

void AEnemy::NotifyActorBeginOverlap(AActor* OtherActor)
{
//	UE_LOG(LogTemp, Warning, TEXT("Begin Overlap"));

	// ������ ���� �����̼��� ���ڸ��� �ϸ� ������ ���� �˴ٿ�Ǽ� �ӽ���ġ��
	GetWorld()->SpawnActor<AItem>(itemFactory, GetActorLocation()+FVector(0,0,-100), GetActorRotation());
	Destroy();
}


