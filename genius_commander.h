#ifndef SPO_LAB1_NTFS_UTILS_H
#define SPO_LAB1_NTFS_UTILS_H

#endif //SPO_LAB1_NTFS_UTILS_H

char *ls(struct ntfs_sb_info *fs, char *path);
int count_nodes(char *path);
char *cd(struct ntfs_sb_info *fs, char *path);
char *pwd(struct ntfs_sb_info *fs);
char *cp(struct ntfs_sb_info *fs, char *path, char *out_path);