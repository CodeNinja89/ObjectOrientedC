struct _hidden {
  char *data;
  void(*constructor)(char *, struct _hidden *, void(*callback)(struct _hidden));
  size_t(*size)(struct _hidden *);
  char*(*getter)(struct _hidden *);
  void(*iterator)(struct _hidden);
};

typedef struct _hidden LIST;

void psuedoConstructor(char *data, struct _hidden *this, void(*callback)(struct _hidden)) {this->data = data; this->iterator = callback;}
size_t size(struct _hidden *this) {return sizeof(this->data);}
char* getter(struct _hidden *this) {return this->data;}

#define LIST(X) struct _hidden X = {.data = NULL, \
                                    .constructor = psuedoConstructor, \
                                    .size = size, \
                                    .getter = getter} // the crux of the magic
