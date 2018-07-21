#include "atlasgenerator.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "lodepng.h"

#define TRUE 1
#define FALSE 0
#define PIXEL_SIZE 4
#define IMG_W 16 * PIXEL_SIZE
#define IMG_H 16 * PIXEL_SIZE
#define IMG_H_PX (16)
#define IMG_W_PX (16)
#define ATLAS_W 256 * PIXEL_SIZE
#define ATLAS_H 256 * PIXEL_SIZE
#define ATLAS_W_PX (256)
#define ATALAS_H_PX (256)
#define toLocal2d(x,y) (y * IMG_W + x)
#define toAtlas2d(x,y) (y * ATLAS_W + x)
#define toAtlas2dPX(x, y) (y * 256 + x)

void flip_image_vertical2(
                         unsigned char *data, unsigned int width, unsigned int height)
{
    unsigned int size = width * height * 4;
    unsigned int stride = sizeof(char) * width * 4;
    unsigned char *new_data = malloc(sizeof(unsigned char) * size);
    for (unsigned int i = 0; i < height; i++) {
        unsigned int j = height - i - 1;
        memcpy(new_data + j * stride, data + i * stride, stride);
    }
    memcpy(data, new_data, size);
    free(data);
}

int blend_color(float a, float b, float t)
{
    return sqrt((1-t) * pow(a, 2) + t * pow(b, 2));
}

Atlas *atlas_create()
{
  Atlas *a = (Atlas*) malloc(sizeof(Atlas));
  a->images = (AtlasImage**) malloc(sizeof(AtlasImage*) * 257);

  for(int i = 0; i < 256; i++) {
    a->images[i] = NULL;
  }

  a->path_index = 0;

  return a;
}

void atlas_free(Atlas* atlas)
{
  for(int x = 0; x < atlas->path_index; x++) {
    //Free each AtlasImage
    if (atlas->images[x]->data != NULL)
      free(atlas->images[x]->data);
    free(atlas->images[x]);
  }

  free(atlas->images);
  return;
}

int atlas_addImage(Atlas *atlas, const char *path)
{
  printf("Adding Image: %s\n", path);
  if (atlas->path_index == 255) {
    return FALSE;
  }

  int tmp;
  if ((tmp = atlas_hasImage(atlas, path)) != -1) {
    printf("returning: %d\n", tmp);
    return tmp;
  }

  AtlasImage* img = (AtlasImage*) malloc(sizeof(AtlasImage));
  img->data = NULL;
  img->colorize = FALSE;
  img->r = 0;
  img->g = 0;
  img->b = 0;
  img->a = 0;
  img->path = (char*) malloc(256);
  memset(img->path, 0, 256);
  memcpy(img->path, path, strlen(path));

  int y = atlas->path_index / 16;
  /*
    Below we are normalizing the y index of the image.
    Since the atlas is built starting at the top left,
    and the u/v are created from the bottom left.
  */
  y = ((15 - y) * 16) + (atlas->path_index % 16);

  img->index = y;

  atlas->images[atlas->path_index] = img;

  atlas->path_index += 1;
  return img->index;
}

int atlas_addImageColorize(Atlas *atlas, const char *path, unsigned char r,
  unsigned char g,
  unsigned char b,
  unsigned char a)
{
  printf("Adding Image: %s\n", path);
  if (atlas->path_index == 255) {
    return FALSE;
  }

  int tmp;
  if ((tmp = atlas_hasImageColorized(atlas, path, r, g, b, a) != -1)) {
    return tmp;
  }

  AtlasImage* img = (AtlasImage*) malloc(sizeof(AtlasImage));
  img->data = NULL;
  img->colorize = FALSE;
  img->r = 0;
  img->g = 0;
  img->b = 0;
  img->a = 0;
  img->path = (char*) malloc(256);
  memset(img->path, 0, 256);
  memcpy(img->path, path, strlen(path));

  int y = atlas->path_index / 16;
  /*
    Below we are normalizing the y index of the image.
    Since the atlas is built starting at the top left,
    and the u/v are created from the bottom left.
  */
  y = ((15 - y) * 16) + (atlas->path_index % 15);

  img->index = y;

  atlas->images[atlas->path_index] = img;

  atlas->path_index += 1;
  img->colorize = TRUE;
  img->r = r;
  img->g = g;
  img->b = b;
  img->a = a;
  return img->index;
}

int load_images(Atlas *atlas)
{
  for(int x = 0; x < atlas->path_index; x++) {
    unsigned error, width, height;
    error = lodepng_decode32_file(&atlas->images[x]->data, &width, &height, atlas->images[x]->path);
    if (error) {
      fprintf(stderr, "Atlas: Failed to load texture: %s [Texture #%d imported]\n", atlas->images[x]->path, x);
      return FALSE;
    }

    //Colorize the image
    for(int i = 0; i < (width * 4) * height; i++) {
      if (atlas->images[x]->r != 0 && i % 4 == 0) {
        //Red
          atlas->images[x]->data[i] = blend_color(atlas->images[x]->data[i], atlas->images[x]->r, 0.75f);//(atlas->images[x]->data[i] + atlas->images[x]->r) / 2;
      }

      if (atlas->images[x]->g != 0 && i % 4 == 1) {
        //Green
        atlas->images[x]->data[i] = blend_color(atlas->images[x]->data[i], atlas->images[x]->g, 0.75f);
      }

      if (atlas->images[x]->b != 0 && i % 4 == 2) {
        //Blue
        atlas->images[x]->data[i] = blend_color(atlas->images[x]->data[i], atlas->images[x]->b, 0.75f);
      }
    }
  }
    
    return TRUE;
}

void atlas_generate(Atlas *atlas, const char *path)
{
  unsigned char *output = (unsigned char *) malloc(sizeof(unsigned char) * (256 * PIXEL_SIZE) * (256));
  load_images(atlas);

  //The outer loop selects the bin packing shelf
  memset(output, 0, (256 * PIXEL_SIZE) * (256));
  unsigned row_width = 256 * PIXEL_SIZE;
  unsigned image_size = 16 * PIXEL_SIZE;
  for(unsigned y = 0; y < 256; y++) {
    for (unsigned x = 0; x < row_width; x++) {
      int img = ((y / 16) * 16) + x / image_size;
      if (img > atlas->path_index - 1) {
        break;
      }

      //atlas->images[img]->index = (256 / (y+1)) + (x / image_size) + 1;
      output[((y * row_width) + x)] = atlas->images[img]->data[(((y % 16) * image_size)) + (x % image_size)];
    }
  }

  lodepng_encode32_file(path, output, 256, 256);
}


int atlas_hasImage(Atlas *atlas, const char *path)
{
  for(int i = 0; i < atlas->path_index; i++) {
    AtlasImage *img = atlas->images[i];
    if (strcmp(img->path, path) == 0) {
      printf("Found match: %s, %s\n", img->path, path);
      return img->index;
    }
  }

  return -1;
}
/*
  This function is used by the resources.h file when reading
  the block resource file. It allows the same texture to
  only be imported once.

  Returns the index of the texture if found,
  -1 if not found
*/
int atlas_hasImageColorized(Atlas *atlas, const char *path, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
  for(int i = 0; i < atlas->path_index; i++) {
    AtlasImage *img = atlas->images[i];
    if (strcmp(img->path, path) == 0) {
      if (img->r == r && img->g == g && img->b == b && img->a == a) {
        return img->index;
      }
    }
  }

  return -1;
}
