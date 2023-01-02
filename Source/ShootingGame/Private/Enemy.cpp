// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Item.h"
#include "components/BoxComponent.h"
#include "components/StaticMeshComponent.h"
#include "Runtime/Engine/public/TimerManager.h"
#include "TengaiGameMode.h"
#include "Fence_Vertical.h"
#include "Fence_Horizontal.h"
#include "EnemyBullet.h"
#include "PooledObject.h"
#include "PooledSubBullet.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �ڽ� �ݸ��� ����
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50));
	boxComp->SetCollisionProfileName(TEXT("EnemyPreset"));

	// �޽� ����
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	meshComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlap);
	drawRate = FMath::RandRange(0.0f, 1.0f);

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (movingMode == 1)
<<<<<<< HEAD
<<<<<<< HEAD
	{
=======
	{		
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
=======
	{		
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
		// Y����� �������� ���Դٰ� �ٽ� ���������� ��������
		FVector newLocation = GetActorLocation();
		float deltaY = (FMath::Sin(runningTime + DeltaTime) - FMath::Sin(runningTime));
		newLocation.Y += deltaY * -700.0f;
		runningTime += DeltaTime;
		SetActorLocation(newLocation);
	} 
<<<<<<< HEAD
<<<<<<< HEAD
	if (movingMode == 2)
=======
	else if (movingMode == 2)
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
=======
	else if (movingMode == 2)
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
	{
		// Y����� �������� �ε巴�� ���ͼ� ����
		FVector newLocation = GetActorLocation();
		runningTime += DeltaTime;
		float deltaY = FMath::Sin(runningTime);
		if (deltaY > 0)
		{
			newLocation.Y += deltaY * -3.0f;
			SetActorLocation(newLocation);
			return;
		}
		// �÷��̾� �������� ���� �Ѿ��� ����
<<<<<<< HEAD
<<<<<<< HEAD
		if (!isShoot)
=======
		else if (!isShoot)
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
=======
		else if (!isShoot)
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
		{
			GetWorld()->SpawnActor<AEnemyBullet>(EnemyBulFactory, GetActorLocation(), GetActorRotation());
			isShoot = true;
			return;
		}
		// Z�� ���� ���� �ö� (�潺�� �΋H�� �����)
		newLocation.Z = newLocation.Z + DeltaTime * enemySpeed;
		SetActorLocation(newLocation);
	}
<<<<<<< HEAD
<<<<<<< HEAD
	if (movingMode == 3)
=======
	else if (movingMode == 3)
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
=======
	else if (movingMode == 3)
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
	{
	// �����ڸ��� ���� �׸��� ȸ�� �� �������� ����
		FVector newLocation = GetActorLocation();
		runningTime += DeltaTime;
		float deltaY = (FMath::Sin((runningTime + DeltaTime) * 2) - FMath::Sin(runningTime * 2));
<<<<<<< HEAD
<<<<<<< HEAD
		float deltaZ = FMath::Sin(runningTime * 2);
		newLocation.Y -= 3.0f;
		newLocation.Y -= deltaY * 400.0f;
		newLocation.Z += deltaZ * 5.0f;
=======
=======
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
		float DeltaZ = FMath::Sin(runningTime * 2);
		newLocation.Y -= 3.0f;
		newLocation.Y -= deltaY * 400.0f;
		newLocation.Z += DeltaZ * 5.0f;
<<<<<<< HEAD
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
=======
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
		SetActorLocation(newLocation);
	}
	else
	{
		// �� ����̵� p=p0+vt
		direction = GetActorForwardVector();
		SetActorLocation(GetActorLocation() + direction * enemySpeed * DeltaTime);
	}

	
}

void AEnemy::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APooledObject* playerBullet = Cast<APooledObject>(OtherActor);

	if (playerBullet)
	{
		if (drawRate <= dropRate)
		{
			GetWorld()->SpawnActor<AItem>(itemFactory, GetActorLocation() + FVector(0, 0, -100), GetActorRotation());
		}
	
		//UE_LOG(LogTemp, Warning, TEXT("%f"), playerBullet->GetAttackPower());
		playerBullet->Reset();
<<<<<<< HEAD
<<<<<<< HEAD

		if (myHP > 0)
		{
			myHP -= 1;
=======
		if (myHP > 0)
		{
			myHP -= playerBullet->GetAttackPower();
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
=======
		if (myHP > 0)
		{
			myHP -= playerBullet->GetAttackPower();
>>>>>>> b95a99b32cacab323193a55547cdd984304772fe
		} 
		else
		{
			Destroy();
		}
		
	}

	AFence_Horizontal* fenceH = Cast<AFence_Horizontal>(OtherActor);

	if (fenceH != nullptr)
	{
		Destroy();
	}

	AFence_Vertical* fenceV = Cast<AFence_Vertical>(OtherActor);

	if (fenceV != nullptr)
	{
		Destroy();
	}


	//APooledSubBullet* subBullet = Cast<APooledSubBullet>(OtherActor);

	//// reset moving time overriding APooledObject
	//if (subBullet)
	//{
	//	subBullet->ResetMovingTime();
	//	subBullet->SetDeactive();
	//}
	//else
	//{
	//	APooledObject* bullet = Cast<APooledObject>(OtherActor);
	//	
	//	if (bullet)
	//	{
	//		bullet->SetDeactive();
	//	}
	//}

	//if (drawRate <= dropRate)
	//{
	//	GetWorld()->SpawnActor<AItem>(itemFactory, GetActorLocation() + FVector(0, 0, -100), GetActorRotation());
	//}

	//Destroy();

}
