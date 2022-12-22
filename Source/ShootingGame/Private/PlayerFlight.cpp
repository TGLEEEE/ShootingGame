// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFlight.h"
#include "components/BoxComponent.h"
#include "components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Bullet.h"

// Sets default values
APlayerFlight::APlayerFlight()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Collision ����
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	// boxComp�� root�� ����
	SetRootComponent(boxComp);
	// boxComp ũ�⼳��
	boxComp->SetBoxExtent(FVector(50));

	// Mesh ����
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	// meshComp�� root�Ʒ��� ����
	meshComp->SetupAttachment(RootComponent);
	// static mesh�� ���� mesh���� �ε�
	ConstructorHelpers::FObjectFinder<UStaticMesh>cubemesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	// mesh���� �ε尡 �����ϸ� �����϶�
	if (cubemesh.Succeeded())
	{
		meshComp->SetStaticMesh(cubemesh.Object);
	}
	// mesh location ����
	meshComp->SetRelativeLocation(FVector(0, 0, -50));
}

// Called when the game starts or when spawned
void APlayerFlight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerFlight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// ���� ����ȭ
	direction.Normalize();
	// �̵� ���� p=p0+vt
	SetActorLocation(GetActorLocation() + direction * moveSpeed * DeltaTime);

}

// Called to bind functionality to input
void APlayerFlight::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Mapping ������ Horizontal input�� ������ HorizontalInput�Լ� ����
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerFlight::HorizontalInput);
	// Mapping ������ Vertical input�� ������ VerticalInput�Լ� ����
	PlayerInputComponent->BindAxis("Vertical", this, &APlayerFlight::VerticalInput);
	// Mapping ������ input�� ������ BulletFire�Լ� ����
	PlayerInputComponent->BindAction("Fire",IE_Pressed, this, &APlayerFlight::BulletFire);
}

// �¿��Է��� ������ �� ����� �Լ� ����
void APlayerFlight::HorizontalInput(float value)
{
	direction.Y = value;
}
// �����Է��� ������ �� ����� �Լ� ����
void APlayerFlight::VerticalInput(float value)
{
	direction.Z = value;
}
// Ŭ���Է��� ������ �� ����� �Լ� ����
void APlayerFlight::BulletFire()
{
	// ������ġ ����
	FVector spawnPosition = GetActorLocation() + GetActorRightVector() * 200;
	// ���� �����̼� ���� ( Pitch, Roll, Yaw )
	FRotator spawnRotation = FRotator(0, 0, 0);
	// ���� �ɼ� (optional)
	FActorSpawnParameters para;
	para.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	// �Ѿ� �������Ʈ�� ���� ������ ����
	GetWorld()->SpawnActor<ABullet>(bulletFactory, spawnPosition, spawnRotation, para);
}