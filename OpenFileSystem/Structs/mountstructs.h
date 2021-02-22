#ifndef MountStructs
#define MountStructs
#include <vector>

using namespace std;

char L[26];
int D[99];

void init()
{
    for (int ch = 'A'; ch <= 'Z'; ch++)
        L[ch - 'A'] = ch;

    for (int d = 1; d <= 99; d++)
        D[d - 1] = d;
}


// ESTRUCTURAS PARA MOUNT

// 98<num_particion><letra_disco>

struct partition
{
    int id;
    char name[16];
    int status;
};

struct disk
{
    char id;
    char path[100];
    struct partition partitions[99];
    int status;
};

vector<disk> mounted;

disk *getDiskMounted(char path[])
{
    for (disk dk : mounted)
        if (dk.path == path)
            return &dk;

    return NULL;
}

partition *getPartitionMounted(disk *dk, char name[])
{
    for (MountStructs::partition par : dk->partitions)
        if (par.name == name)
            return &par;

    return NULL;
}

int *getPartitionMountedByID(char disk_id, int par_id)
{
    for (int i = 0; i < 26; i++)
        if (mounted[i].id == disk_id)
            for (int j = 0; j < 99; j++)
                if (mounted[i].partitions[j].id == par_id)
                    return &pair(i, j);

    return NULL;
}

char getDiskId()
{
    init();

    for (char id : L)
    {
        bool br = false;
        for (disk dk : mounted)
            if (dk.id == id)
            {
                br = true;
                break;
            }

        if (br)
            continue;

        return id;
    };

    return NULL;
}

int getPartitionId(disk* dk)
{
    init();
    
    for (int id : D)
    {
        bool br = false;
        for (MountStructs::partition par : dk->partitions)
            if (par.id == id)
            {
                br = true;
                break;
            }

        if (br)
            continue;

        return id;
    }

    return NULL;
}

class mountstructs
{
public:
    mountstructs();
};

extern vector<disk> mounted;

#endif