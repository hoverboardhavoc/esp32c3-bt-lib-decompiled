/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_ecc_gen_new_public_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00011f62) */

undefined4 r_ecc_gen_new_public_key(int param_1,undefined2 param_2,undefined2 param_3)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  short *psVar3;
  short *psVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  short *psVar8;
  int iVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  short *psVar12;
  int iVar13;
  int iVar14;
  short asStack_164 [18];
  int iStack_140;
  undefined4 uStack_13c;
  undefined1 auStack_138 [32];
  undefined2 uStack_118;
  short asStack_10c [18];
  int iStack_e8;
  undefined4 uStack_e4;
  short asStack_e0 [18];
  int iStack_bc;
  undefined4 uStack_b8;
  undefined1 auStack_b4 [36];
  int iStack_90;
  undefined4 uStack_8c;
  undefined1 auStack_88 [36];
  int iStack_64;
  undefined4 uStack_60;
  undefined1 auStack_5c [36];
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  psVar8 = asStack_10c;
  psVar4 = asStack_164;
  puVar11 = (undefined1 *)(param_1 + 0x1f);
  asStack_164[0] = 0;
  asStack_10c[0] = 0;
  asStack_e0[0] = 0;
  puVar6 = (undefined1 *)0x1307b;
  puVar7 = (undefined1 *)0x13077;
  psVar3 = psVar4;
  psVar12 = psVar8;
  do {
    uVar2 = *puVar11;
    puVar1 = puVar11 + -1;
    puVar11 = puVar11 + -2;
    psVar3[1] = CONCAT11(uVar2,*puVar1);
    psVar3 = psVar3 + 1;
    psVar12[1] = CONCAT11(*puVar6,puVar6[-1]);
    psVar12[0x17] = CONCAT11(*puVar7,puVar7[-1]);
    puVar6 = puVar6 + -2;
    puVar7 = puVar7 + -2;
    psVar12 = psVar12 + 1;
  } while ((undefined1 *)(param_1 + -1) != puVar11);
  iVar14 = 0;
  do {
    if (*psVar4 != 0) break;
    iVar14 = iVar14 + 1;
    psVar4 = psVar4 + 1;
  } while (iVar14 != 0x11);
  iStack_140 = 0x11 - iVar14;
  iVar13 = 0;
  psVar3 = psVar8;
  do {
    if (*psVar3 != 0) break;
    iVar13 = iVar13 + 1;
    psVar3 = psVar3 + 1;
  } while (iVar13 != 0x11);
  iVar13 = 0x11 - iVar13;
  iStack_e8 = iVar13;
  iVar9 = 0;
  do {
    if (psVar8[0x16] != 0) break;
    iVar9 = iVar9 + 1;
    psVar8 = psVar8 + 1;
  } while (iVar9 != 0x11);
  iVar9 = 0x11 - iVar9;
  uStack_e4 = 0;
  uStack_b8 = 0;
  iStack_bc = iVar9;
  iVar5 = r_ecc_is_valid_point(asStack_10c,asStack_e0);
  uVar10 = 0x12;
  if (iVar5 != 0) {
    iVar5 = r_ke_malloc(0x14c,3);
    *(undefined2 *)(iVar5 + 0x13e) = param_3;
    *(undefined4 *)(iVar5 + 0x148) = 0;
    *(undefined1 *)(iVar5 + 0x144) = 1;
    *(undefined2 *)(iVar5 + 0x13c) = param_2;
    memset(auStack_138,0,0x20);
    memcpy(auStack_b4,asStack_10c,0x22);
    uStack_8c = 0;
    iStack_90 = iVar13;
    memcpy(auStack_88,asStack_e0,0x22);
    uStack_60 = 0;
    uStack_118 = 1;
    iStack_64 = iVar9;
    memcpy(auStack_5c,auStack_138,0x22);
    uStack_38 = 1;
    uStack_34 = 0;
    memcpy((void *)(iVar5 + 0x8c),auStack_b4,0x22);
    *(int *)(iVar5 + 0xb0) = iVar13;
    *(undefined4 *)(iVar5 + 0xb4) = 0;
    memcpy((void *)(iVar5 + 0xb8),auStack_88,0x22);
    *(int *)(iVar5 + 0xdc) = iVar9;
    *(undefined4 *)(iVar5 + 0xe0) = 0;
    memcpy((void *)(iVar5 + 0xe4),auStack_5c,0x22);
    *(undefined4 *)(iVar5 + 0x108) = 1;
    *(undefined4 *)(iVar5 + 0x10c) = 0;
    memcpy((void *)(iVar5 + 0x110),asStack_164,0x22);
    *(undefined4 *)(iVar5 + 0x138) = uStack_13c;
    *(int *)(iVar5 + 0x134) = 0x11 - iVar14;
    memset(auStack_138,0,0x22);
    memcpy((void *)(iVar5 + 8),auStack_138,0x22);
    *(undefined4 *)(iVar5 + 0x2c) = 1;
    *(undefined4 *)(iVar5 + 0x30) = 0;
    uStack_118 = 1;
    memcpy((void *)(iVar5 + 0x34),auStack_138,0x22);
    *(undefined4 *)(iVar5 + 0x58) = 1;
    *(undefined4 *)(iVar5 + 0x5c) = 0;
    uStack_118 = 0;
    memcpy((void *)(iVar5 + 0x60),auStack_138,0x22);
    *(undefined4 *)(iVar5 + 0x140) = 0x3f0000;
    *(undefined4 *)(iVar5 + 0x84) = 1;
    *(undefined4 *)(iVar5 + 0x88) = 0;
    *(undefined4 *)(iVar5 + 4) = 0x11;
    r_co_list_push_back(&ecc_env,iVar5);
    r_ke_event_set(1);
    uVar10 = 0;
  }
  return uVar10;
}

