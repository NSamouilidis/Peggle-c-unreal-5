

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PeggleBlock.generated.h"



UCLASS()
class PONG_API APeggleBlock : public AActor
{
	GENERATED_BODY()

public:
	
	APeggleBlock();

	UPROPERTY(VisibleAnywhere, Category = "Sprites")
	class UPaperSpriteComponent* MySprite;

protected:
	
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	

public:
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
	FTimerHandle DestroyTimer;
	void DestroyThisObject();

};
