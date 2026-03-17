
// detalle y aclaracion del trabajo desarrollado
//
// para este laboratorio cree un proyecto en unreal engine y programe dos clases principales en c++
// primero diseñe la clase enemigo a la cual le asigne una malla visual en forma de dona
// dentro de esta clase utilice la funcion tick para que la nave verifique constantemente si ya llego a su destino
// y de ser asi calcule inmediatamente una nueva coordenada aleatoria para seguir moviendose de forma autonoma por todo el escenario
// segundo configure el gamemode del nivel para cumplir con el requisito de colocar los objetos mediante codigo
// especificamente en el evento beginplay del gamemode programe un ciclo for que se encarga de instanciar y hacer el spawn de 5 naves enemigas
// estas aparecen en posiciones de inicio aleatorias para estar bien distribuidas al arrancar la partida
// finalmente inicialice mi repositorio con git bash excluyendo los archivos pesados del motor
// y subi todos mis codigos fuente a github para entregar la tarea compartiendo la ruta del contenedor


#include "Enemigo.h"


// esta funcion es el constructor de mi clase enemigo y se encarga de inicializar el componente visual de mi nave, asignarle una malla y configurar su velocidad de movimiento
AEnemigo::AEnemigo()
{
	PrimaryActorTick.bCanEverTick = true;

	// inicializo el componente visual de mi nave y lo establezco como la raiz
	MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
	RootComponent = MallaEnemigo;

	// busco la malla de la dona en el contenido inicial y se la asigno a mi nave
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}

	// configuro la velocidad inicial a la que se movera mi nave
	VelocidadMovimiento = 300.0f;
}


// esta funcion se ejecuta al iniciar el juego y se encarga de darle un primer destino a mi nave para que empiece a moverse
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();

	// apenas inicia el juego llamo a mi funcion para darle un primer destino a la nave
	GenerarNuevaPosicion();
}


// esta funcion se ejecuta cada frame y se encarga de mover a mi nave hacia su destino
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector PosicionActual = GetActorLocation();

	// verifico si mi nave ya llego a su destino midiendo la distancia
	if (FVector::Dist(PosicionActual, PosicionDestino) < 10.0f)
	{
		// si ya llegue a mi destino pido que se genere otro punto nuevo
		GenerarNuevaPosicion();
	}
	else
	{
		// si todavia no llego calculo la direccion y me muevo hacia alla en linea recta
		FVector Direccion = (PosicionDestino - PosicionActual).GetSafeNormal();
		SetActorLocation(PosicionActual + (Direccion * VelocidadMovimiento * DeltaTime));
	}
}

// esta funcion se encarga de generar coordenadas aleatorias dentro de un rango para que mi nave se mueva por todo el escenario
void AEnemigo::GenerarNuevaPosicion()
{
	// genero posiciones aleatorias en los ejes X e Y manteniendo la altura z de mi nave
	float X = FMath::RandRange(-1000.0f, 1000.0f);
	float Y = FMath::RandRange(-1000.0f, 1000.0f);
	// estas coordenadas lo asigno a mi variable de destino para que la nave sepa a donde ir
	PosicionDestino = FVector(X, Y, 150.0f);
}