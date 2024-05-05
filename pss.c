/**
 * PSS Library for C
 * https://github.com/Prof-Saulo_Santos/pss-library
 * https://www.youtube.com/@profsaulosantos
 * instagram.com/profsaulosantos
 * profsaulosantos@gmail.com
 *
 * 
 * Copyright (c) 2024
 * All rights reserved
 *
 * BSD 3-Clause License
 * http://www.opensource.org/licenses/BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the name of CS50 nor the names of its contributors may be used
 *   to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>
#include <errno.h>
#include <float.h>

void limpa_buffer() {
    int lixo;
    while ((lixo = getchar()) != '\n' && lixo != '\r' && lixo != EOF);
}

char input_c(const char *mensagem) {
    char x;
    do {
        printf("%s", mensagem);
        x = fgetc(stdin); 
        if (x == '\n') continue;
        if (x != EOF) limpa_buffer();
    } while (x == '\n' || x == EOF); 
    return x;
}

void input_s(const char *mensagem, char *x, int tamanho) {	
    do {
        printf("%s", mensagem);
        if (fgets(x, tamanho,stdin) != NULL) 
            x[strcspn(x, "\n")] = '\0';
    } while (strlen(x) == 0);
    if ( strlen(x) == tamanho - 1 ) limpa_buffer();    
}

int input_d(const char *mensagem) {
    char aux[1024];
    char *endptr;
    int x;
    intmax_t temp;
    do{
        input_s(mensagem,aux, sizeof(aux));
        temp = strtoimax(aux, &endptr, 10);
        if ((temp == INTMAX_MIN || temp == INTMAX_MAX) && errno == ERANGE) temp = INT_MAX;
        x = (int)temp;
    }while(*endptr != '\0');
    return x;
}

float input_f(const char *mensagem) {
    char aux[1024];
    char *endptr;
    float x;
    do{
        input_s(mensagem, aux, sizeof(aux));
        x = strtof(aux, &endptr);
        if ((x < FLT_MIN || x > FLT_MAX)) x = FLT_MAX;
    }while(*endptr != '\0');
    return x;
}

long int  input_ld(const char *mensagem) {
    char aux[1024];
    char *endptr;
    long int x;
    do{
        input_s(mensagem, aux, sizeof(aux));
        x = strtol(aux, &endptr, 10);
        if ((x < LONG_MIN || x > LONG_MAX)) x = LONG_MAX;
    }while(*endptr != '\0');
    return x;
}

double input_lf(const char *mensagem) {
    char aux[1024];
    char *endptr;
    double x;
    do{
        input_s(mensagem, aux, sizeof(aux));
        x = strtod(aux, &endptr); 
        if ((x < DBL_MIN || x > DBL_MAX)) x = DBL_MAX;
    }while(*endptr != '\0');
	return x; 
}

long double input_Lf(const char *mensagem) {
    char aux[5120];
    char *endptr;
    long double x;
    do{
        input_s(mensagem, aux, sizeof(aux));
        x = strtold(aux, &endptr); 
        if ((x < LDBL_MIN || x > LDBL_MAX)) x = LDBL_MAX;
    }while(*endptr != '\0'); 
    return x; 
}
