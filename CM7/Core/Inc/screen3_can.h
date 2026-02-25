#ifndef SCREEN3_CAN_H
#define SCREEN3_CAN_H

#include <stdint.h>

// CAN ID: 0x10000030 (268435504)
#define ID_VCU_COMPONENTFAULTS_2 0x10000030
typedef struct {
    uint64_t statusMask;
} VCU_ComponentFaults_2_t;

// CAN ID: 0x10000031 (268435505)
#define ID_VCU_COMPONENTFAULTS_3 0x10000031
typedef struct {
    uint64_t statusMask;
} VCU_ComponentFaults_3_t;

// CAN ID: 0x10000032 (268435506)
#define ID_VCU_COMPONENTFAULTS_4 0x10000032
typedef struct {
    uint64_t statusMask;
} VCU_ComponentFaults_4_t;

// CAN ID: 0x10000035 (268435509)
#define ID_VCU_GENERALWARNINGS_1 0x10000035
typedef struct {
    uint64_t statusMask;
} VCU_GeneralWarnings_1_t;

// CAN ID: 0x10000036 (268435510)
#define ID_VCU_GENERALWARNINGS_2 0x10000036
typedef struct {
    uint64_t statusMask;
} VCU_GeneralWarnings_2_t;

// CAN ID: 0x10000037 (268435511)
#define ID_VCU_COMPONENTWARNINGS_1 0x10000037
typedef struct {
    uint64_t statusMask;
} VCU_ComponentWarnings_1_t;

// CAN ID: 0x10000038 (268435512)
#define ID_VCU_COMPONENTWARNINGS_2 0x10000038
typedef struct {
    uint64_t statusMask;
} VCU_ComponentWarnings_2_t;

// CAN ID: 0x10000039 (268435513)
#define ID_VCU_COMPONENTWARNINGS_3 0x10000039
typedef struct {
    uint64_t statusMask;
} VCU_ComponentWarnings_3_t;

// CAN ID: 0x10000040 (268435520)
#define ID_VCU_COMPONENTWARNINGS_4 0x10000040
typedef struct {
    uint64_t statusMask;
} VCU_ComponentWarnings_4_t;

// CAN ID: 0x10000041 (268435521)
#define ID_VCU_COMPONENTWARNINGS_5 0x10000041
typedef struct {
    uint64_t statusMask;
} VCU_ComponentWarnings_5_t;

// CAN ID: 0x10000042 (268435522)
#define ID_VCU_COMPONENTWARNINGS_6 0x10000042
typedef struct {
    uint64_t statusMask;
} VCU_ComponentWarnings_6_t;

// CAN ID: 0x10000043 (268435523)
#define ID_FUSEBOX_1_2_RELAY_STATE 0x10000043
typedef struct {
    uint64_t statusMask;
} Fusebox_1_2_Relay_State_t;

// CAN ID: 0x10000044 (268435524)
#define ID_FUSEBOX1_FUSE_STATE_1_28 0x10000044
typedef struct {
    uint64_t statusMask;
} Fusebox1_Fuse_State_1_28_t;

// CAN ID: 0x10000045 (268435525)
#define ID_FUSEBOX2_FUSE_STATE_1_28 0x10000045
typedef struct {
    uint64_t statusMask;
} Fusebox2_Fuse_State_1_28_t;


#endif // SCREEN3_CAN_H
