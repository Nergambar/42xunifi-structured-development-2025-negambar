#ifndef PASSWORD_VALIDATOR
#define PASSWORD_VALIDATOR

typedef int PwStatus;

PwStatus validate_password(const char *new_pw, const char *current_pw);

#endif