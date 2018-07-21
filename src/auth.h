#ifndef _auth_h_
#define _auth_h_

#ifdef __cplusplus
extern "C" {
#endif

int get_access_token(
    char *result, int length, char *username, char *identity_token);
    
#ifdef __cplusplus
}
#endif

#endif
