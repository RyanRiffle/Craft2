#ifndef _world_h_
#define _world_h_

#ifdef __cplusplus
extern "C" {
#endif
    
typedef void (*world_func)(int, int, int, int, void *);
void create_world(int p, int q, world_func func, void *arg);
    
#ifdef __cplusplus
}
#endif

#endif
