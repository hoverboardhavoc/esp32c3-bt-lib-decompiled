/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_ecc_gen_new_public_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00011f60) */

undefined4 r_ecc_gen_new_public_key(int param_1,undefined2 param_2,undefined2 param_3)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  short *psVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined2 *puVar13;
  undefined2 uStack_174;
  short asStack_172 [17];
  int iStack_150;
  undefined4 uStack_14c;
  undefined1 auStack_148 [32];
  undefined2 uStack_128;
  undefined2 uStack_11c;
  short asStack_11a [17];
  int iStack_f8;
  undefined4 uStack_f4;
  undefined2 uStack_f0;
  short asStack_ee [17];
  int iStack_cc;
  undefined4 uStack_c8;
  undefined1 auStack_c4 [36];
  int iStack_a0;
  undefined4 uStack_9c;
  undefined1 auStack_98 [36];
  int iStack_74;
  undefined4 uStack_70;
  undefined1 auStack_6c [36];
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  puVar9 = (undefined1 *)(param_1 + 0x1f);
  uStack_174 = 0;
  uStack_11c = 0;
  uStack_f0 = 0;
  puVar7 = (undefined1 *)0x1307b;
  puVar8 = (undefined1 *)0x13077;
  puVar4 = &uStack_174;
  puVar13 = &uStack_11c;
  do {
    uVar2 = *puVar9;
    puVar1 = puVar9 + -1;
    puVar9 = puVar9 + -2;
    puVar4[1] = CONCAT11(uVar2,*puVar1);
    puVar4 = puVar4 + 1;
    puVar13[1] = CONCAT11(*puVar7,puVar7[-1]);
    puVar13[0x17] = CONCAT11(*puVar8,puVar8[-1]);
    puVar7 = puVar7 + -2;
    puVar8 = puVar8 + -2;
    puVar13 = puVar13 + 1;
  } while ((undefined1 *)(param_1 + -1) != puVar9);
  iVar10 = 0;
  puVar4 = &uStack_174;
  do {
    iVar10 = iVar10 + 1;
    if (iVar10 == 0x11) break;
    psVar3 = puVar4 + 1;
    puVar4 = puVar4 + 1;
  } while (*psVar3 == 0);
  iStack_150 = 0x11 - iVar10;
  iVar11 = 0;
  puVar4 = &uStack_11c;
  do {
    iVar11 = iVar11 + 1;
    if (iVar11 == 0x11) break;
    psVar3 = puVar4 + 1;
    puVar4 = puVar4 + 1;
  } while (*psVar3 == 0);
  iVar11 = 0x11 - iVar11;
  iStack_f8 = iVar11;
  iVar5 = 0;
  puVar4 = &uStack_11c;
  do {
    iVar5 = iVar5 + 1;
    if (iVar5 == 0x11) break;
    psVar3 = puVar4 + 0x17;
    puVar4 = puVar4 + 1;
  } while (*psVar3 == 0);
  iVar5 = 0x11 - iVar5;
  uStack_f4 = 0;
  uStack_c8 = 0;
  iStack_cc = iVar5;
  iVar6 = r_ecc_is_valid_point(&uStack_11c,&uStack_f0);
  uVar12 = 0x12;
  if (iVar6 != 0) {
    iVar6 = r_ke_malloc(0x14c,3);
    *(undefined2 *)(iVar6 + 0x13c) = param_2;
    *(undefined4 *)(iVar6 + 0x148) = 0;
    *(undefined1 *)(iVar6 + 0x144) = 1;
    *(undefined2 *)(iVar6 + 0x13e) = param_3;
    memset(auStack_148,0,0x20);
    uStack_128 = 1;
    memcpy(auStack_c4,&uStack_11c,0x22);
    uStack_9c = 0;
    iStack_a0 = iVar11;
    memcpy(auStack_98,&uStack_f0,0x22);
    uStack_70 = 0;
    iStack_74 = iVar5;
    memcpy(auStack_6c,auStack_148,0x22);
    uStack_48 = 1;
    uStack_44 = 0;
    memcpy((void *)(iVar6 + 0x8c),auStack_c4,0x22);
    *(int *)(iVar6 + 0xb0) = iVar11;
    *(undefined4 *)(iVar6 + 0xb4) = 0;
    memcpy((void *)(iVar6 + 0xb8),auStack_98,0x22);
    *(int *)(iVar6 + 0xdc) = iVar5;
    *(undefined4 *)(iVar6 + 0xe0) = 0;
    memcpy((void *)(iVar6 + 0xe4),auStack_6c,0x22);
    *(undefined4 *)(iVar6 + 0x108) = 1;
    *(undefined4 *)(iVar6 + 0x10c) = 0;
    memcpy((void *)(iVar6 + 0x110),&uStack_174,0x22);
    *(undefined4 *)(iVar6 + 0x138) = uStack_14c;
    *(int *)(iVar6 + 0x134) = 0x11 - iVar10;
    memset(auStack_148,0,0x22);
    memcpy((void *)(iVar6 + 8),auStack_148,0x22);
    *(undefined4 *)(iVar6 + 0x2c) = 1;
    *(undefined4 *)(iVar6 + 0x30) = 0;
    uStack_128 = 1;
    memcpy((void *)(iVar6 + 0x34),auStack_148,0x22);
    *(undefined4 *)(iVar6 + 0x58) = 1;
    *(undefined4 *)(iVar6 + 0x5c) = 0;
    uStack_128 = 0;
    memcpy((void *)(iVar6 + 0x60),auStack_148,0x22);
    *(undefined4 *)(iVar6 + 0x140) = 0x3f0000;
    *(undefined4 *)(iVar6 + 0x84) = 1;
    *(undefined4 *)(iVar6 + 0x88) = 0;
    *(undefined4 *)(iVar6 + 4) = 0x11;
    r_co_list_push_back(&ecc_env,iVar6);
    r_ke_event_set(1);
    uVar12 = 0;
  }
  return uVar12;
}

