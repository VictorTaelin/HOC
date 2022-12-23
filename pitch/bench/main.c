#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Arr {
  char type; // 0 = Null, 1 = Leaf, 2 = Node
  uint64_t value;
  struct Arr *left;
  struct Arr *right;
} Arr;

typedef struct Map {
  char type; // 0 = Free, 1 = Used, 2 = Both
  struct Map *left;
  struct Map *right;
} Map;

Arr* mkNull() {
  Arr* result = malloc(sizeof(Arr));
  result->type = 0;
  return result;
}

Arr* mkLeaf(uint64_t value) {
  Arr* result = malloc(sizeof(Arr));
  result->type = 1;
  result->value = value;
  return result;
}

Arr* mkNode(Arr* left, Arr* right) {
  Arr* result = malloc(sizeof(Arr));
  result->type = 2;
  result->left = left;
  result->right = right;
  return result;
}

Map* mkFree() {
  Map* result = malloc(sizeof(Map));
  result->type = 0;
  return result;
}

Map* mkUsed() {
  Map* result = malloc(sizeof(Map));
  result->type = 1;
  return result;
}

Map* mkBoth(Map* left, Map* right) {
  Map* result = malloc(sizeof(Map));
  result->type = 2;
  result->left = left;
  result->right = right;
  return result;
}

// Frees an Arr recursively
void freeArr(Arr* t) {
  if (t->type == 2) {
    freeArr(t->left);
    freeArr(t->right);
  }
  free(t);
}

// Frees a Map recursively
void freeMap(Map* m) {
  if (m->type == 2) {
    freeMap(m->left);
    freeMap(m->right);
  }
  free(m);
}

// Prints an Arr recursively
void printArr(Arr* t) {
  if (t->type == 0) {
    printf("Null");
  } else if (t->type == 1) {
    printf("Leaf(%llu)", t->value);
  } else {
    printf("Node(");
    printArr(t->left);
    printf(", ");
    printArr(t->right);
    printf(")");
  }
}

// Prints a Map recursively
void printMap(Map* m) {
  if (m->type == 0) {
    printf("Free");
  } else if (m->type == 1) {
    printf("Used");
  } else {
    printf("Both(");
    printMap(m->left);
    printf(", ");
    printMap(m->right);
    printf(")");
  }
}

// Function signatures
Arr* sort(Arr* t);
Map* toMap(Arr* t);
Arr* toArr(uint64_t x, Map* m);
Map* merge(Map* a, Map* b);
Map* radix(uint64_t n);
Map* u60_swap(uint64_t n, Map* a, Map* b);
Arr* reverse(Arr* t);
uint64_t sum(Arr* t);
Arr* gen(uint64_t n);

Arr* sort(Arr* a) {
  Map* map = toMap(a);
  Arr* arr = toArr(0, map);
  freeMap(map);
  return arr;
}

Map* toMap(Arr* t) {
  if (t->type == 0) {
    return mkFree();
  } else if (t->type == 1) {
    return radix(t->value);
  } else {
    return merge(toMap(t->left), toMap(t->right));
  }
}

Arr* toArr(uint64_t x, Map* m) {
  if (m->type == 0) {
    return mkNull();
  } else if (m->type == 1) {
    return mkLeaf(x);
  } else {
    return mkNode(toArr(x * 2 + 0, m->left), toArr(x * 2 + 1, m->right));
  }
}

Map* merge(Map* a, Map* b) {
  if (a->type == 0) {
    return b;
  } else if (b->type == 0) {
    return a;
  } else if (a->type == 1) {
    return b;
  } else if (b->type == 1) {
    return a;
  } else {
    return mkBoth(merge(a->left, b->left), merge(a->right, b->right));
  }
}

Map* radix(uint64_t n) {
  Map* r0 = mkUsed(); // really GPT?
  Map* r1 = u60_swap(n & 1, r0, mkFree());
  Map* r2 = u60_swap(n & 2, r1, mkFree());
  Map* r3 = u60_swap(n & 4, r2, mkFree());
  Map* r4 = u60_swap(n & 8, r3, mkFree());
  Map* r5 = u60_swap(n & 16, r4, mkFree());
  Map* r6 = u60_swap(n & 32, r5, mkFree());
  Map* r7 = u60_swap(n & 64, r6, mkFree());
  Map* r8 = u60_swap(n & 128, r7, mkFree());
  Map* r9 = u60_swap(n & 256, r8, mkFree());
  Map* rA = u60_swap(n & 512, r9, mkFree());
  Map* rB = u60_swap(n & 1024, rA, mkFree());
  Map* rC = u60_swap(n & 2048, rB, mkFree());
  Map* rD = u60_swap(n & 4096, rC, mkFree());
  Map* rE = u60_swap(n & 8192, rD, mkFree());
  Map* rF = u60_swap(n & 16384, rE, mkFree());
  Map* rG = u60_swap(n & 32768, rF, mkFree());
  Map* rH = u60_swap(n & 65536, rG, mkFree());
  Map* rI = u60_swap(n & 131072, rH, mkFree());
  Map* rJ = u60_swap(n & 262144, rI, mkFree());
  Map* rK = u60_swap(n & 524288, rJ, mkFree());
  Map* rL = u60_swap(n & 1048576, rK, mkFree());
  Map* rM = u60_swap(n & 2097152, rL, mkFree());
  Map* rN = u60_swap(n & 4194304, rM, mkFree());
  Map* rO = u60_swap(n & 8388608, rN, mkFree());
  return rO;
}

Map* u60_swap(uint64_t n, Map* a, Map* b) {
  if (n == 0) {
    return mkBoth(a, b);
  } else {
    return mkBoth(b, a);
  }
}

Arr* reverse(Arr* t) {
  if (t->type == 0) {
    return mkNull();
  } else if (t->type == 1) {
    return mkLeaf(t->value);
  } else {
    return mkNode(reverse(t->right), reverse(t->left));
  }
}

uint64_t sum(Arr* t) {
  if (t->type == 0) {
    return 0;
  } else if (t->type == 1) {
    return t->value;
  } else {
    return sum(t->left) + sum(t->right);
  }
}

Arr* gen_go(uint64_t n, uint64_t x) {
  if (n == 0) {
    return mkLeaf(x);
  } else {
    uint64_t x_ = x * 2;
    uint64_t y_ = x_ + 1;
    uint64_t n_ = n - 1;
    return mkNode(gen_go(n_, x_), gen_go(n_, y_));
  }
}

Arr* gen(uint64_t n) {
  return gen_go(n, 0);
}

int main() {
  Arr* arr_a = gen(23);
  Arr* arr_b = reverse(arr_a);
  freeArr(arr_a);
  Arr* arr_c = sort(arr_b);
  freeArr(arr_b);
  uint64_t s = sum(arr_c);
  freeArr(arr_c);
  printf("%llu\n", s);
}
