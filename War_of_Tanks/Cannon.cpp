#include "Cannon.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"



ACannon::ACannon()
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComp;

	CannonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CannonMesh"));
	CannonMesh->SetupAttachment(SceneComp);

	ProjectileSpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ProjectileSpawnPoint->SetupAttachment(CannonMesh);
}

void ACannon::BeginPlay()
{
	Super::BeginPlay();

	bReadyToFire = true;


	
}

void ACannon::Fire()
{
	if (!IsReadyToFire())
	{
		return;
	}
	
	if (currentAmmo > 0)
	{
		if (CannonType == ECannonType::FireProjectile)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Purple, "Fire projectile");
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "Fire trace");
		}
		currentAmmo--;
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Ammo: %d"), currentAmmo));
	} 
	else 
	{
		bReadyToFire = false;
		GetWorld()->GetTimerManager().SetTimer(ReloadTimer, this, &ACannon::Reload, FireRate, false);
	}
}

void ACannon::FireSpecial()
{
	CannonType = ECannonType::FireTrace;
	Fire();
	CannonType = ECannonType::FireProjectile;
}


bool ACannon::IsReadyToFire()
{
	return bReadyToFire;
}

void ACannon::Reload()
{
	currentAmmo = 10;
	bReadyToFire = true;
	
}



