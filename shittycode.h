struct _hidden {
  char *data;
  void(*constructor)(char *, struct _hidden *);
  int(*size)(struct _hidden *);
  char*(*getter)(struct _hidden *);
};

void psuedoConstructor(char *data, struct _hidden *this) {this->data = data;}
int size(struct _hidden *this) {return sizeof(this->data);}
char* getter(struct _hidden *this) {return this->data;}

#define LIST(X) struct _hidden X = {.data = NULL, \
                                    .constructor = psuedoConstructor, \
                                    .size = size, \
                                    .getter = getter} // the crux of the magic
