#ifndef _db_h_
#define _db_h_

#include "map.h"
#include "sign.h"

#ifdef __cplusplus
extern "C" {
#endif

    void db_enable(void);
    void db_disable(void);
    int get_db_enabled(void);
    int db_init(char *path);
    void db_close(void);
    void db_commit(void);
    void db_auth_set(char *username, char *identity_token);
    int db_auth_select(char *username);
    void db_auth_select_none(void);
    int db_auth_get(
        char *username,
        char *identity_token, int identity_token_length);
    int db_auth_get_selected(
        char *username, int username_length,
        char *identity_token, int identity_token_length);
    void db_save_state(float x, float y, float z, float rx, float ry);
    int db_load_state(float *x, float *y, float *z, float *rx, float *ry);
    void db_insert_block(int p, int q, int x, int y, int z, int w);
    void db_insert_light(int p, int q, int x, int y, int z, int w);
    void db_insert_sign(
        int p, int q, int x, int y, int z, int face, const char *text);
    void db_insert_inventory_item(int userId, int x, int y, int block, int count);
    int db_load_inventory_item(int userId, int ix, int iy, int *x, int *y, int *block, int *count);
    void db_save_environment_state(unsigned ticks, unsigned day, int weather);
    int db_load_enironment_state(unsigned *ticks, unsigned *day, int *weather);
    void db_delete_sign(int x, int y, int z, int face);
    void db_delete_signs(int x, int y, int z);
    void db_delete_all_signs(void);
    void db_load_blocks(Map *map, int p, int q);
    void db_load_lights(Map *map, int p, int q);
    void db_load_signs(SignList *list, int p, int q);
    int db_get_key(int p, int q);
    void db_set_key(int p, int q, int key);
    void db_worker_start();
    void db_worker_stop(void);
    int db_worker_run(void *arg);
#ifdef __cplusplus
}
#endif

#endif
