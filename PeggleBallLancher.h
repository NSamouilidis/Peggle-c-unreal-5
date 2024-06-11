

#pragma once

#include "CoreMinimal.h"
#include "PeggleBallLancher.generated.h"

UCLASS()
class PONG_API APeggleBallLancher : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Sprites")
	class UPaperSpriteComponent* MySprite;


public:
	// Sets default values for this pawn's properties
	APeggleBallLancher();





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;




public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MovePlayer(float input);
	void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Peggle")
	float ShotPower = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Peggle")
	float RotationSpeed = 100.0f; // Adjust the rotation speed as needed

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Peggle")
	bool bInvertDirection = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	TSubclassOf<AActor> BP_PeggleBall_C;

};
