void agregar_producto(char nombres[][50], int tiempos[], int recursos[], int demandas[], int *cantidad);
void editar_producto(char nombres[][50], int tiempos[], int recursos[], int demandas[], int cantidad);
void eliminar_producto(char nombres[][50], int tiempos[], int recursos[], int demandas[], int *cantidad);
void calcular_produccion(char nombres[][50], int tiempos[], int recursos[], int demandas[], int cantidad, int tiempo_maximo, int recursos_maximos);
void iniciar_sistema(int tiempo_maximo, int recursos_maximos);