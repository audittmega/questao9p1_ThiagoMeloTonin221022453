#include <stdio.h>

// Função para calcular o MDC (Algoritmo de Euclides)
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para encontrar o inverso modular de G em Z_n (Algoritmo de Euclides Estendido)
int inverso_modular(int G, int n) {
    int t = 0, newt = 1;
    int r = n, newr = G;
    while (newr != 0) {
        int q = r / newr;
        int temp = newt;
        newt = t - q * newt;
        t = temp;
        temp = newr;
        newr = r - q * newr;
        r = temp;
    }
    if (r > 1) return -1; // G não tem inverso
    if (t < 0) t += n;
    return t;
}

// Função para verificar se dois números são coprimos
int sao_coprimos(int a, int b) {
    return mdc(a, b) == 1;
}

// Função para verificar se um número é primo
int eh_primo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Função para calcular phi(n) manualmente
int phi(int n) {
    int resultado = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            resultado -= resultado / i;
        }
    }
    if (n > 1)
        resultado -= resultado / n;
    return resultado;
}

// Exponenciação modular eficiente
int mod_exp(int base, int exp, int mod) {
    int resultado = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            resultado = (resultado * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return resultado;
}

int main() {
    int H, G, n, x, n1;

    printf("Digite os valores de H, G e n: ");
    scanf("%d %d %d", &H, &G, &n);

    // Etapa 1: verificar se G e n são coprimos
    if (mdc(G, n) != 1) {
        printf("G e n nao sao coprimos. Divisao modular nao possivel.\n");
        return 1;
    }

    // Etapa 2: calcular inverso modular
    int G_inv = inverso_modular(G, n);
    if (G_inv == -1) {
        printf("G nao possui inverso modular em Z_%d.\n", n);
        return 1;
    }

    // Etapa 3: calcular a = H * G^-1 mod n
    int a = (H * G_inv) % n;
    printf("Base a = %d\n", a);

    // Entrada para x e n1
    printf("Digite o valor de x e n1: ");
    scanf("%d %d", &x, &n1);

    // Etapa 4: verificar coprimalidade de a e n1
    if (!sao_coprimos(a, n1)) {
        printf("a e n1 nao sao coprimos.\n");
    } else {
        printf("a e n1 sao coprimos.\n");
    }

    // Etapas 5 a 7: verificar se n1 é primo e escolher teorema
    int x1;
    if (eh_primo(n1)) {
        x1 = n1 - 1;
        printf("n1 e primo. Usando Teorema de Fermat: x1 = %d\n", x1);
    } else {
        x1 = phi(n1);
        printf("n1 nao e primo. Usando Teorema de Euler: phi(n1) = %d\n", x1);
    }

    // Etapa 8: decompor x
    int q = x / x1;
    int r = x % x1;
    printf("x = %d = %d * %d + %d\n", x, x1, q, r);

    // Etapa 9 e 10: cálculos intermediários
    int x2 = mod_exp(a, x1, n1);
    int x2q = mod_exp(x2, q, n1);
    int ar = mod_exp(a, r, n1);

    // Etapa 11: resultado final
    int resultado = (x2q * ar) % n1;
    printf("Resultado final: (%d^%d mod %d)^%d * (%d^%d mod %d) mod %d = %d\n", a, x1, n1, q, a, r, n1, n1, resultado);

    return 0;
}
