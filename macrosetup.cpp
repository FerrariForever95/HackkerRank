#define FUNCTION(name, op) \
void name(int &a, int b) { \
    b op a ? a = b : ; \
}
