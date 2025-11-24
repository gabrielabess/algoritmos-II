#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

// Raio médio da Terra em quilômetros (aproximado)
#define R 6371.0
#define MAX_LINE_LENGTH 1024

// --- Funções de Ajuda Matemática ---

double deg2rad(double deg) {
    return deg * (M_PI / 180.0);
}

double haversine_distance(double lat1, double lon1, double lat2, double lon2) {
    double r_lat1 = deg2rad(lat1);
    double r_lon1 = deg2rad(lon1);
    double r_lat2 = deg2rad(lat2);
    double r_lon2 = deg2rad(lon2);

    double dLat = r_lat2 - r_lat1;
    double dLon = r_lon2 - r_lon1;

    double a = sin(dLat / 2.0) * sin(dLat / 2.0) +
               cos(r_lat1) * cos(r_lat2) *
               sin(dLon / 2.0) * sin(dLon / 2.0);

    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

    return R * c; 
}

// --- Função Principal de Parsing e Cálculo ---

int parse_gpx_and_calculate(const char *filename, double *total_distance, double *gain, double *loss) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo GPX");
        return -1;
    }

    *total_distance = 0.0;
    *gain = 0.0;
    *loss = 0.0;

    double prev_lat = 0.0, prev_lon = 0.0, prev_ele = 0.0;
    int first_point = 1;
    char line[MAX_LINE_LENGTH];

    double current_lat = 0.0;
    double current_lon = 0.0;
    double current_ele = NAN; 
    
    // DEBUG: Garante que esta mensagem seja impressa
    printf("Iniciando leitura do arquivo: %s\n", filename);
    printf("----------------------------------------\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        
        char *trkpt_start = strstr(line, "<trkpt");
        if (trkpt_start != NULL) {
            // Reset do ponto
            current_lat = 0.0;
            current_lon = 0.0;
            current_ele = NAN;

            // Extração de LATITUDE
            char *lat_start = strstr(trkpt_start, "lat=\"");
            if (lat_start != NULL) {
                sscanf(lat_start + 5, "%lf", &current_lat);
            }

            // Extração de LONGITUDE
            char *lon_start = strstr(trkpt_start, "lon=\"");
            if (lon_start != NULL) {
                sscanf(lon_start + 5, "%lf", &current_lon);
            }
        }
        
        // Extração de ELEVAÇÃO (pode estar em qualquer linha entre trkpt e /trkpt)
        char *ele_start = strstr(line, "<ele>");
        char *ele_end = strstr(line, "</ele>");
        
        if (ele_start != NULL && ele_end != NULL) {
            // O valor da elevação começa 5 caracteres após "<ele>"
            char *value_start = ele_start + 5; 
            char ele_str[50];
            
            // O comprimento é a posição final menos a posição inicial do valor
            size_t len = ele_end - value_start; 
            
            if (len < sizeof(ele_str) && len > 0) {
                strncpy(ele_str, value_start, len);
                ele_str[len] = '\0';
                current_ele = atof(ele_str);
            }
        }

        // Se encontrou o final do ponto, realiza o cálculo (ponto de coleta de dados)
        if (strstr(line, "</trkpt>") != NULL || strstr(line, "/>") != NULL) {
            
            if (current_lat != 0.0 && current_lon != 0.0 && !isnan(current_ele)) {
                
                if (!first_point) {
                    // CÁLCULO DE DISTÂNCIA
                    *total_distance += haversine_distance(prev_lat, prev_lon, current_lat, current_lon);

                    // CÁLCULO DE GANHO/PERDA
                    double elevation_change = current_ele - prev_ele;

                    if (elevation_change > 0) {
                        *gain += elevation_change; 
                    } else if (elevation_change < 0) {
                        *loss += fabs(elevation_change); 
                    }
                }

                prev_lat = current_lat;
                prev_lon = current_lon;
                prev_ele = current_ele;
                first_point = 0;
            } 
        }
    }

    fclose(file);
    return 0;
}

// --- Função Principal (Exemplo de Uso) ---

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        fprintf(stderr, "\nERRO DE USO: Você deve fornecer o nome do arquivo GPX.\n");
        fprintf(stderr, "Uso: %s <G.gpx>\n\n", argv[0]);
        return 1;
    }
    
    const char *gpx_file = argv[1];

    double total_distance = 0.0;
    double total_gain = 0.0;
    double total_loss = 0.0;

    if (parse_gpx_and_calculate(gpx_file, &total_distance, &total_gain, &total_loss) == 0) {
        printf("----------------------------------------\n");
        printf("--- Resultados ---\n");
        printf("Arquivo Processado: **%s**\n", gpx_file);
        printf("Distância Total Percorrida: **%.3f km**\n", total_distance);
        printf("Ganho de Elevação Acumulado: **%.2f metros**\n", total_gain);
        printf("Perda de Elevação Acumulada: **%.2f metros**\n", total_loss);
        printf("------------------\n");
    } else {
        return 1; 
    }

    return 0;
}

/* Prompt 1: Olá, vamos criar um código em C com funções bem definidas para fazer Parsing do GPX e cálculo de ganho 
e perda acumulados de elevação, distância total percorrida em quilômetros (desconsiderando inclinação na distancia 
e usando distância entre coordenadas no plano esférico). O código deve ser organizado em funções bem definidas, o 
Parsing do GPX pode ser via parser XML ou tratamento de strings, a distância entre coordenadas deve ser adequada, 
ganho de elevação deve somar apenas as positivas e perda de elevações as negativas.

Prompt 2: <trkpt lon="-51.535421" lat="-28.958572">

                <ele>568.064000</ele>

            </trkpt>

            <trkpt lon="-51.535065" lat="-28.958819">

                <ele>569.988000</ele>

            </trkpt>

            <trkpt lon="-51.534893" lat="-28.958874">

o arquivo é assim, adeque o código para as variáveis corretas

Prompt 3: não está dando os resultados certos, o código deve ler de um arquivo não do trecho que lhe enviei

Prompt 4: o M_PI não está declarado, vamos corrigir o problema
*/
