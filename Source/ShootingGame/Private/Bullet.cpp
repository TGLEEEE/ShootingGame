// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "components/BoxComponent.h"
#include "components/MeshComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// collision ����
	boxcomp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	// boxcomp�� root�� ����
	SetRootComponent(boxcomp);
	// collision ũ�� ����
	boxcomp->SetBoxExtent(FVector(50));
	// collision ������ ����
	boxcomp->SetWorldScale3D(FVector(0.75, 1, 0.25));

	// mesh ����
	meshcomp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	// meshcomp�� root�Ʒ��� ����
	meshcomp->SetupAttachment(RootComponent);
	// mesh ��ġ����
	meshcomp->SetRelativeLocation(FVector(0, 0, -50));
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ���ͱ��� ����(����) ���Ͱ� �޾ƿ���
	direction = GetActorRightVector();
	// �̵����� p=p0+vt
	SetActorLocation(GetActorLocation() + direction * bulletspeed * DeltaTime);



}

