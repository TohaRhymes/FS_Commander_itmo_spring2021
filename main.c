#include "main.h"

int main(int argc, char *argv[]) {

    blkid_cache cache;
    initialize_cache(&cache);
    probe_cache(&cache);
    iterate_dev(&cache);


    return 0;
}
