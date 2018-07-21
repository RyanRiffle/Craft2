#ifndef __ATLASGENERATOR_H
#define __ATLASGENERATOR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char *path;
  unsigned char *data;
  int index;
  char colorize;
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
} AtlasImage;

typedef struct {
  AtlasImage **images;
  unsigned char path_index;
} Atlas;

Atlas *atlas_create(void);
void atlas_free(Atlas* atlas);
int atlas_addImage(Atlas *atlas, const char *path);
int atlas_addImageColorize(Atlas *atlas, const char *path, unsigned char r,
  unsigned char g,
  unsigned char b,
  unsigned char a);
void atlas_generate(Atlas *atlas, const char *path);
int atlas_hasImageColorized(Atlas *atlas, const char *path, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
int atlas_hasImage(Atlas *atlas, const char *path);

#ifdef __cplusplus
}
#endif
    
#endif
