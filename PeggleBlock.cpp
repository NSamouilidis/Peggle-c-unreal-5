// Fill out your copyright notice in the Description page of Project Settings.


#include "PeggleBlock.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"



APeggleBlock::APeggleBlock()
{
	
	PrimaryActorTick.bCanEverTick = true;

	MySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("My Image"));
	MySprite->OnComponentHit.AddDynamic(this, &APeggleBlock::OnHit);
	RootComponent = MySprite;

}


void APeggleBlock::BeginPlay()
{
	Super::BeginPlay();

}


void APeggleBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APeggleBlock::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("HIT!"));
	if (!DestroyTimer.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Setting Timer"));
		GetWorld()->GetTimerManager().SetTimer(DestroyTimer, this, &APeggleBlock::DestroyThisObject, 1.0, false);
	}
}

void APeggleBlock::DestroyThisObject()
{
	Destroy();
}

void APeggleBlock::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	MySprite->SetNotifyRigidBodyCollision(true);
}

