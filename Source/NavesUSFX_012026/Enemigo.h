#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

UCLASS()
class NAVESUSFX_012026_API AEnemigo : public AActor
{
	GENERATED_BODY()

public:
	AEnemigo();

	// aqui declaro el componente visual de mi nave, osea que se vera en el panel de detalles
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MallaEnemigo;

	// defino variables para controlar la velocidad y saber a donde debe ir mi nave
	float VelocidadMovimiento;
	FVector PosicionDestino;

	// declaro una funcion propia para que mi nave calcule una nueva coordenada en el mapa
	void GenerarNuevaPosicion();

protected:
	// esta funcion se ejecuta al iniciar el juego y se encarga de darle un primer destino a mi nave para que empiece a moverse
	virtual void BeginPlay() override;

public:
	// esta funcion se ejecuta cada frame y se encarga de mover a mi nave hacia su destino
	virtual void Tick(float DeltaTime) override;
};