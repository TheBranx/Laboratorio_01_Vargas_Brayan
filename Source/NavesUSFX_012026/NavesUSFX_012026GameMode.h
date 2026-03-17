#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesUSFX_012026GameMode.generated.h"

UCLASS()
class NAVESUSFX_012026_API ANavesUSFX_012026GameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};