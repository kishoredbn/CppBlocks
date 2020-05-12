#pragma once

#define STATIC_CONCATE_EXPANDS(X,Y) X##Y
#define STATIC_CONCATE_UNIQUELY(X,Y) STATIC_CONCATE_EXPANDS(X, Y)
#define STATIC_UNIQUE_IDENTIFIER(X) STATIC_CONCATE_UNIQUELY(X, __LINE__)
#define STATIC static int STATIC_UNIQUE_IDENTIFIER(b_static_flag_blocker_) = 0; if(!STATIC_UNIQUE_IDENTIFIER(b_static_flag_blocker_) && !(STATIC_UNIQUE_IDENTIFIER(b_static_flag_blocker_))++)
