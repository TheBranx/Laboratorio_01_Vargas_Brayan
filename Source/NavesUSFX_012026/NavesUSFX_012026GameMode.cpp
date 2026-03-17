#include "NavesUSFX_012026GameMode.h"
#include "Enemigo.h"

void ANavesUSFX_012026GameMode::BeginPlay()
{
	Super::BeginPlay();

	// obtengo una referencia al mundo para poder instanciar mis naves
	UWorld* World = GetWorld();
	if (World)
	{
		// uso un ciclo for para instanciar 5 naves mias al arrancar el nivel
		for (int i = 0; i < 5; i++)
		{
			// calculo una posicion inicial diferente para que mis naves no aparezcan amontonadas
			FVector PosicionInicial(FMath::RandRange(-500.0f, 500.0f), FMath::RandRange(-500.0f, 500.0f), 150.0f);

			// instancio mi clase enemigo directamente en el nivel usando codigo c++
			World->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), PosicionInicial, FRotator::ZeroRotator);
		}
	}
}