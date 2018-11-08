//RESPONSÁVEL POR EXECUTAR UM COMANDO

#ifndef EXECUTA_COMANDO_H
#define EXECUTA_COMANDO_H

typedef struct params {
    char* caminho_GEO;
    char* caminho_TXT;
    char* caminho_SVG;
    char* caminho_QRY;
    char* caminho_EC;
    char* caminho_PM;
    char* diretorio_entrada;
    char* arquivo_entrada;
    char* diretorio_saida;
    char* arquivo_entrada_qry;
    char* arquivo_entrada_ec;
    char* arquivo_entrada_pm;
    char* cor_borda_quadra;
    char* cor_preenche_quadra;
    char* cor_borda_hidrante;
    char* cor_preenche_hidrante;
    char* cor_borda_semaforo;
    char* cor_preenche_semaforo;
    char* cor_borda_radiobase;
    char* cor_preenche_radiobase;
    char** comando_vetor;
    long int max_figuras;
    int contador_figuras;
    Item* figuras;
    Fila* anotacoes;
    Fila* resultado;
    Lista quadras;
    Lista hidrantes;
    Lista semaforos;
    Lista radiobases;
} Parametros;

void executa_comando (void* p);

void caso_nx (Parametros* par);

void caso_c (Parametros* par);

void caso_r (Parametros* par);

void caso_q (Parametros* par);

void caso_h (Parametros* par);

void caso_s (Parametros* par);

void caso_t_geo (Parametros* par);

void caso_o (Parametros* par);

void caso_d (Parametros* par);

void caso_a (Parametros* par);

void caso_hashtag (Parametros* par);

void caso_q_pergunta (Parametros* par);

void caso_Q_pergunta (Parametros* par);

void caso_dq (Parametros* par);

void caso_dle (Parametros* par);

void caso_Dq (Parametros* par);

void caso_Dle (Parametros* par);

void caso_cc (Parametros* par);

void caso_crd_pergunta (Parametros* par);

void caso_crb_pergunta (Parametros* par);

void caso_t_ec (Parametros* par);

void caso_e (Parametros* par);

void caso_p (Parametros* par);

void caso_m (Parametros* par);

void caso_m_pergunta (Parametros* par);

void caso_mr_pergunta (Parametros* par);

void caso_dm_pergunta (Parametros* par);

void caso_de_pergunta (Parametros* par);

void caso_rip (Parametros* par);

void caso_ecq_pergunta (Parametros* par);

void caso_ecr_pergunta (Parametros* par);

void caso_tecq_pergunta (Parametros* par);

void caso_tecr_pergunta (Parametros* par);

void caso_hmpe_pergunta (Parametros* par);

void caso_hmp_pergunta (Parametros* par);

void caso_fec (Parametros* par);

void caso_mud (Parametros* par);

void caso_mudec (Parametros* par);

void caso_dpr (Parametros* par);

#endif