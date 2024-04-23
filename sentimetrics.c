#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
#include <string.h>

// Função para analisar o sentimento do texto
static PyObject* sentimetrics(PyObject *self, PyObject *args) {
    const char *text;
    int positive_words = 0;
    int negative_words = 0;

    // Lista de palavras positivas e negativas (simplificadas)
    const char *positive_words_list[] = {
        "bom", "feliz", "ótimo", "excelente", "alegre", "maravilhoso", "brilhante", "incrível", "radiante", "fantástico",
        "agradável", "adorável", "encantador", "esplêndido", "otimista", "espetacular", "radiante", "celestial", "sensacional", "triunfante",
        "harmonioso", "vibrante", "confortável", "prazeroso", "positivo", "benéfico", "edificante", "entusiasmado", "glorioso", "extraordinário",
        "esperançoso", "notável", "estupendo", "ótimo", "sorridente", "estelar", "excelente", "jubiloso", "luminoso", "próspero",
        "poderoso", "alegre", "radiante", "satisfeito", "triunfante", "vitorioso", "vivaz", "divertido", "radiante"
    };

    const char *negative_words_list[] = {
        "ruim", "triste", "terrível", "horrível", "deprimente", "desolador", "péssimo", "miserável", "desagradável", "desanimador",
        "tenebroso", "sinistro", "desastroso", "agonizante", "lamentável", "infeliz", "desesperador", "desgraçado", "sombrio", "angustiante",
        "catastrófico", "infernal", "preocupante", "fúnebre", "trágico", "nefasto", "horrendo", "assustador", "desanimador", "desgostoso",
        "desalentador", "sombrio", "nublado", "nebuloso", "nefasto", "deprimente", "lúgubre", "melancólico", "negativo", "inquietante",
        "desfavorável", "aborrecido", "aborrecimento", "entediado", "aborrecido", "insatisfatório", "infeliz", "lamentável", "descontente"
    };

    // Parse dos argumentos
    if (!PyArg_ParseTuple(args, "s", &text)) {
        return NULL;
    }

    // Verifica cada palavra no texto
    char *token = strtok((char *)text, " ");
    while (token != NULL) {
        // Verifica se a palavra está na lista de palavras positivas
        for (int i = 0; positive_words_list[i] != NULL; i++) {
            if (strcmp(token, positive_words_list[i]) == 0) {
                positive_words++;
                break;
            } 
        }
        // Verifica se a palavra está na lista de palavras negativas
        for (int i = 0; negative_words_list[i] != NULL; i++) {
            if (strcmp(token, negative_words_list[i]) == 0) {
                negative_words++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    // Retorna o resultado da análise de sentimento como um objeto Python
    if (positive_words > negative_words) {
        return PyLong_FromLong(1); // Sentimento positivo
    } else if (positive_words < negative_words) {
        return PyLong_FromLong(-1); // Sentimento negativo
    } else {
        return PyLong_FromLong(0); // Sentimento neutro
    }
}

// Lista de métodos disponíveis no módulo
static PyMethodDef module_methods[] = {
    {"sentimetrics", emotions_analysis, METH_VARARGS, "Analisa o sentimento do texto."},
    {NULL, NULL, 0, NULL}
};

// Definição do módulo
static struct PyModuleDef module_def = {
    PyModuleDef_HEAD_INIT,
    "sentimetrics", // Nome do módulo
    NULL, // Documentação do módulo
    -1, // Tamanho do estado do módulo (-1 se o módulo mantiver o estado em uma área de dados global)
    module_methods // Lista de métodos do módulo
};

// Função de inicialização do módulo
PyMODINIT_FUNC PyInit_emotions_analysis_c(void) {
    return PyModule_Create(&module_def);
}
