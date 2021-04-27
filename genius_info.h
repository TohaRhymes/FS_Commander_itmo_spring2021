#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <blkid/blkid.h>

#define ll long long
#define TB_amount pow(2, 40)
#define GB_amount pow(2, 30)
#define MB_amount pow(2, 20)
#define KB_amount pow(2, 10)


void print_size(ll size);

int initialize_cache(blkid_cache *cache);

int probe_cache(blkid_cache *cache);

void check_and_print(blkid_probe *probe, char *tag);

int iterate_dev(blkid_cache *cache);

void print_info();