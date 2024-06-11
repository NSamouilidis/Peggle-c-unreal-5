// Fill out your copyright notice in the Description page of Project Settings.


#include "PeggleBallLancher.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/Actor.h"

// Sets default values
APeggleBallLancher::APeggleBallLancher()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("My Image"));
	RootComponent = MySprite;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

void APeggleBallLancher::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	MySprite->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MySprite->TranslucencySortPriority = 3;
}

void APeggleBallLancher::MovePlayer(float input)
{
	SetActorRotation(GetActorRotation() + FRotator(1 * input, 0, 0));
}

void APeggleBallLancher::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Firing!"));
	AActor* SpawnedBall = GetWorld()->SpawnActor<AActor>(BP_PeggleBall_C, GetActorLocation(), GetActorRotation());
	FVector ShotDirection = GetActorUpVector();
	if (bInvertDirection)
	{
		ShotDirection *= -1;
	}

	SpawnedBall->GetComponentByClass<UPaperSpriteComponent>()->AddImpulse(ShotDirection * ShotPower);
}

//Line38 Error Diafania 44 Week 7 Monday

// Called when the game starts or when spawned
void APeggleBallLancher::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APeggleBallLancher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APeggleBallLancher::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Horizontal", this, &APeggleBallLancher::MovePlayer);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &APeggleBallLancher::Fire);

}
