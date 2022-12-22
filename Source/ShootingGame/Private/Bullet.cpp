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
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	// boxComp�� root�� ����
	SetRootComponent(boxComp);
	// collision ũ�� ����
	boxComp->SetBoxExtent(FVector(50));
	// collision ������ ����
	boxComp->SetWorldScale3D(FVector(0.75, 1, 0.25));

	// mesh ����
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	// meshComp�� root�Ʒ��� ����
	meshComp->SetupAttachment(RootComponent);
	// mesh ��ġ����
	meshComp->SetRelativeLocation(FVector(0, 0, -50));
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
	SetActorLocation(GetActorLocation() + direction * bulletSpeed * DeltaTime);

	// ������ źȯ �ð��� ���� �ڵ������ϱ�
	currentTime += DeltaTime;
	if (currentTime >= settingTime)
	{
		Destroy();
	}

}

void ABullet::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Destroy();
}
