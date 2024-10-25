/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_ecc_generate_key256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
r_ecc_generate_key256
          (int param_1,int param_2,int param_3,int param_4,undefined2 param_5,undefined2 param_6)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  int iVar6;
  void *__dest;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined1 *puVar12;
  short *psVar13;
  short local_164 [18];
  int iStack_140;
  undefined4 uStack_13c;
  undefined1 auStack_138 [32];
  undefined2 uStack_118;
  short local_10c [18];
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
  
  puVar12 = (undefined1 *)(param_2 + 0x1f);
  local_164[0] = 0;
  local_10c[0] = 0;
  asStack_e0[0] = 0;
  puVar7 = (undefined1 *)(param_3 + 0x1f);
  puVar8 = (undefined1 *)(param_4 + 0x1f);
  psVar5 = local_10c;
  psVar13 = local_164;
  do {
    uVar2 = *puVar12;
    puVar1 = puVar12 + -1;
    puVar12 = puVar12 + -2;
    psVar13[1] = CONCAT11(uVar2,*puVar1);
    psVar13 = psVar13 + 1;
    uVar2 = *puVar8;
    psVar5[1] = CONCAT11(*puVar7,puVar7[-1]);
    psVar5[0x17] = CONCAT11(uVar2,puVar8[-1]);
    puVar7 = puVar7 + -2;
    puVar8 = puVar8 + -2;
    psVar5 = psVar5 + 1;
  } while ((undefined1 *)(param_2 + -1) != puVar12);
  iVar9 = 0;
  psVar5 = local_164;
  do {
    if (*psVar5 != 0) break;
    iVar9 = iVar9 + 1;
    psVar5 = psVar5 + 1;
  } while (iVar9 != 0x11);
  iStack_140 = 0x11 - iVar9;
  iVar10 = 0;
  psVar5 = local_10c;
  do {
    if (*psVar5 != 0) break;
    iVar10 = iVar10 + 1;
    psVar5 = psVar5 + 1;
  } while (iVar10 != 0x11);
  iStack_e8 = 0x11 - iVar10;
  iStack_bc = 0;
  psVar5 = local_10c;
  do {
    if (psVar5[0x16] != 0) break;
    iStack_bc = iStack_bc + 1;
    psVar5 = psVar5 + 1;
  } while (iStack_bc != 0x11);
  iStack_bc = 0x11 - iStack_bc;
  uStack_e4 = 0;
  uStack_b8 = 0;
  iVar10 = r_ecc_is_valid_point(local_10c,asStack_e0);
  uVar11 = 0x12;
  if (iVar10 != 0) {
    iVar6 = r_ke_malloc(0x14c,3);
    *(undefined2 *)(iVar6 + 0x13c) = param_5;
    *(undefined2 *)(iVar6 + 0x13e) = param_6;
    *(undefined4 *)(iVar6 + 0x148) = 0;
    *(char *)(iVar6 + 0x144) = (char)param_1;
    memset(auStack_138,0,0x20);
    uStack_118 = 1;
    memcpy(auStack_b4,local_10c,0x22);
    uVar11 = uStack_e4;
    iVar10 = iStack_e8;
    uStack_8c = uStack_e4;
    iStack_90 = iStack_e8;
    memcpy(auStack_88,asStack_e0,0x22);
    uVar4 = uStack_b8;
    iVar3 = iStack_bc;
    uStack_60 = uStack_b8;
    iStack_64 = iStack_bc;
    memcpy(auStack_5c,auStack_138,0x22);
    uStack_38 = 1;
    uStack_34 = 0;
    memcpy((void *)(iVar6 + 0x8c),auStack_b4,0x22);
    *(undefined4 *)(iVar6 + 0xb4) = uVar11;
    *(int *)(iVar6 + 0xb0) = iVar10;
    memcpy((void *)(iVar6 + 0xb8),auStack_88,0x22);
    *(undefined4 *)(iVar6 + 0xe0) = uVar4;
    *(int *)(iVar6 + 0xdc) = iVar3;
    memcpy((void *)(iVar6 + 0xe4),auStack_5c,0x22);
    *(undefined4 *)(iVar6 + 0x108) = 1;
    *(undefined4 *)(iVar6 + 0x10c) = 0;
    memcpy((void *)(iVar6 + 0x110),local_164,0x22);
    *(undefined4 *)(iVar6 + 0x138) = uStack_13c;
    *(int *)(iVar6 + 0x134) = 0x11 - iVar9;
    memset(auStack_138,0,0x22);
    memcpy((void *)(iVar6 + 8),auStack_138,0x22);
    *(undefined4 *)(iVar6 + 0x2c) = 1;
    *(undefined4 *)(iVar6 + 0x30) = 0;
    uStack_118 = 1;
    memcpy((void *)(iVar6 + 0x34),auStack_138,0x22);
    *(undefined4 *)(iVar6 + 0x58) = 1;
    *(undefined4 *)(iVar6 + 0x5c) = 0;
    uStack_118 = 0;
    memcpy((void *)(iVar6 + 0x60),auStack_138,0x22);
    *(undefined4 *)(iVar6 + 0x140) = 0x3f0000;
    *(undefined4 *)(iVar6 + 0x84) = 1;
    *(undefined4 *)(iVar6 + 0x88) = 0;
    *(undefined4 *)(iVar6 + 4) = 0x11;
    if (param_1 == 2) {
      __dest = (void *)r_ke_malloc(0x7bc,3);
      *(void **)(iVar6 + 0x148) = __dest;
      memcpy(__dest,(void *)(iVar6 + 0x8c),0x22);
      *(undefined4 *)((int)__dest + 0x24) = *(undefined4 *)(iVar6 + 0xb0);
      *(undefined4 *)((int)__dest + 0x28) = *(undefined4 *)(iVar6 + 0xb4);
      memcpy((void *)((int)__dest + 0x2c),(void *)(iVar6 + 0xb8),0x22);
      *(undefined4 *)((int)__dest + 0x50) = *(undefined4 *)(iVar6 + 0xdc);
      *(undefined4 *)((int)__dest + 0x54) = *(undefined4 *)(iVar6 + 0xe0);
      memcpy((void *)((int)__dest + 0x58),(void *)(iVar6 + 0xe4),0x22);
      *(undefined4 *)((int)__dest + 0x7c) = *(undefined4 *)(iVar6 + 0x108);
      *(undefined4 *)((int)__dest + 0x80) = *(undefined4 *)(iVar6 + 0x10c);
      *(undefined1 *)(iVar6 + 0x144) = 3;
      *(undefined2 *)(iVar6 + 0x142) = 0;
    }
    r_co_list_push_back(&ecc_env,iVar6);
    r_ke_event_set(1);
    uVar11 = 0;
  }
  return uVar11;
}

