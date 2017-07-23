// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerC.generated.h"


UCLASS(Blueprintable)
class GYARUMIKO02_API APlayerC : public ACharacter
{
	GENERATED_BODY()


public: 
 
	//hp
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerC")
	float health = 100;

	//Dead?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerC")
	bool isDead = false;
	////////////////// Movement Section Variable & Function ///////////////////

protected:
		//*movement boolean use connect in BP editor*
	    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerC")
	    bool bIsMoveFwdPress = false;
	    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerC")
		bool bIsMoveBackPress = false;
	    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerC")
		bool bIsMoveRightPress = false;
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerC")
		bool bIsLeftPress = false;

	//*is player moving ?
    bool bIsMoving = false;
	//*is start moving (idle->run animation) end ??
	bool bIsStartMoveEnd = true;

	//*input Direction
	float inputDirection;
	//*input Start Move Direction(idle->run direction)
	float inputStartMoveDirection;
	
	//*calculate direction from Delta degree between player Rot -> Camera(Controller) Rot  + movement key Function
	UFUNCTION(BlueprintCallable, Category = "PlayerC")
	virtual float DirectionCal();

	//*calculate Lean Power (moveFwd,Bwd + side Key)
	UFUNCTION(BlueprintCallable, Category = "PlayerC")
    virtual void MakeLean();

	float maxLean;
	float leanSpeed; 
	float currentLean; //* use in Lean animation Blend in animBP *** need to calculate this 

	FRotator DeltaRotator(float A, FRotator B);

	

	//************* Movement Section Variable & Function End ************//


public:
	// Sets default values for this character's properties
	APlayerC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
