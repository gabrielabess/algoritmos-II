#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float consultar(const char *target, const char *json_data)
{
    char *start_ptr = strstr(json_data, target);

    if (start_ptr != NULL)
    {
        start_ptr += strlen(target);

        // Define o ponteiro final (procurando a virgula ou a chave '}')
        char *end_ptr = strchr(start_ptr, ',');
        if (end_ptr == NULL)
        {
            end_ptr = strchr(start_ptr, '}');
        }

        if (end_ptr != NULL)
        {
            // Calcula o comprimento do valor
            size_t length = end_ptr - start_ptr;

            // Cria uma string temporária para o valor (ex: "5.05")
            char value_str[32]; // Buffer para o valor
            if (length < sizeof(value_str) - 1)
            {
                strncpy(value_str, start_ptr, length);
                value_str[length] = '\0';

                // Converte a string para um número float
                float exchange_rate = atof(value_str);

                printf("   -> Valor de EUR encontrado: %s\n", value_str);
                printf("   -> Cotação como Float: %.4f\n", exchange_rate);
                return exchange_rate;
            }
            else
            {
                printf("   -> Erro: O valor encontrado e muito longo.\n");
            }
        }
        else
        {
            printf("   -> Erro: Nao foi encontrado o fim do valor da cotação.\n");
        }
    }
    else
    {
        printf("   -> Erro: A substring \"%s\" nao foi encontrada no JSON.\n", target);
    }
    return 0;
}
// Função que gerencia a conexão e a leitura dos dados
void conectar_e_obter_dados_api()
{
    // 1. Definições da API e do arquivo
    const char *url = "https://v6.exchangerate-api.com/v6/a39c828557f286ce999fbbfc/latest/USD";
    const char *filename = "resposta_api.json";
    char command[512]; // Buffer para armazenar o comando do shell

    // 2. Constrói o comando: curl -s "URL" -o nome_do_arquivo
    // Isso é o que "conecta" na API (via executável do sistema)
    sprintf(command, "curl -s \"%s\" -o %s", url, filename);

    printf("1. Tentando conectar e baixar dados da API...\n");

    // 3. Executa a conexão externa
    int status = system(command);

    if (status != 0)
    {
        fprintf(stderr, "ERRO: Falha na conexao (o comando 'curl' falhou). Status: %d\n", status);
        return;
    }

    printf("2. Dados baixados com sucesso. Lendo o arquivo '%s'.\n", filename);

    // 4. LÊ O ARQUIVO DE RESPOSTA (A chave para a integração C)
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "ERRO: Nao foi possivel abrir o arquivo de resposta.\n");
        return;
    }

    // Código para determinar o tamanho do arquivo e alocar memória
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *json_data = (char *)malloc(file_size + 1);
    if (json_data == NULL)
    {
        fprintf(stderr, "ERRO: Falha na alocacao de memoria.\n");
        fclose(fp);
        return;
    }

    // Lê o conteúdo JSON para a variável
    fread(json_data, 1, file_size, fp);
    json_data[file_size] = '\0';
    fclose(fp);

    // 5. Usa os dados (ex: imprime e faz parsing manual)
    //printf("\n3. Resposta Completa da API:\n%s\n", json_data);
    float valor;
    printf("Qual moeda você irá inserir? \n1-USD (Dólar)\n2-EUR (Euro)\n3-JPY (Iene)\n4-GBP (Libra Esterlina)\n5-BRL (Real)\n");
    int opcao;
    scanf("%d", &opcao);
    switch (opcao) // Switch moeda inserida
    {
    case 1: // USD
        printf("\n3. Analisando o JSON para encontrar a cotação USD:\n");

        char *target = "\"USD\":";
        valor=consultar(target, json_data);
        break;
    case 2: // EUR
        printf("\n3. Analisando o JSON para encontrar a cotação EUR:\n");

        char *target = "\"EUR\":";
        valor=consultar(target, json_data);
        break;
    case 3: // JPY
        printf("\n3. Analisando o JSON para encontrar a cotação JPY:\n");

        char *target = "\"JPY\":";
        valor=consultar(target, json_data);
        break;
    case 4: // GBP
        printf("\nAnalisando o JSON para encontrar a cotação BRL:\n");

        char *target = "\"BRL\":";
        valor=consultar(target, json_data);
        break;
    case 5: // BRL
        printf("\n3. Analisando o JSON para encontrar a cotação BRL:\n");

        char *target = "\"BRL\":";
        valor=consultar(target, json_data);
        break;
    default:
    printf("Opção inválida!");
        break;
    }

    printf("Qual moeda você gostaria de converter? \n1-USD (Dólar)\n2-EUR (Euro)\n3-JPY (Iene)\n4-GBP (Libra Esterlina)\n5-BRL");
    free(json_data);
    remove(filename); // Remove o arquivo temporário
}

int main()
{
    conectar_e_obter_dados_api();
    return 0;
}
