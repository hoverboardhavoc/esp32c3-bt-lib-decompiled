/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_ecc_generate_key256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  undefined1 *puVar10;
  short *psVar11;
  undefined4 uVar12;
  short *psVar13;
  short *psVar14;
  int iVar15;
  short local_174 [18];
  int iStack_150;
  undefined4 uStack_14c;
  undefined1 auStack_148 [32];
  undefined2 uStack_128;
  short local_11c [18];
  int iStack_f8;
  undefined4 uStack_f4;
  short asStack_f0 [18];
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
  
  psVar13 = local_11c;
  psVar11 = local_174;
  puVar10 = (undefined1 *)(param_2 + 0x1f);
  local_174[0] = 0;
  local_11c[0] = 0;
  asStack_f0[0] = 0;
  puVar7 = (undefined1 *)(param_3 + 0x1f);
  puVar8 = (undefined1 *)(param_4 + 0x1f);
  psVar5 = psVar11;
  psVar14 = psVar13;
  do {
    uVar2 = *puVar10;
    puVar1 = puVar10 + -1;
    puVar10 = puVar10 + -2;
    psVar5[1] = CONCAT11(uVar2,*puVar1);
    psVar5 = psVar5 + 1;
    psVar14[1] = CONCAT11(*puVar7,puVar7[-1]);
    psVar14[0x17] = CONCAT11(*puVar8,puVar8[-1]);
    puVar7 = puVar7 + -2;
    puVar8 = puVar8 + -2;
    psVar14 = psVar14 + 1;
  } while ((undefined1 *)(param_2 + -1) != puVar10);
  iVar15 = 0;
  do {
    if (*psVar11 != 0) break;
    iVar15 = iVar15 + 1;
    psVar11 = psVar11 + 1;
  } while (iVar15 != 0x11);
  iStack_150 = 0x11 - iVar15;
  iVar9 = 0;
  psVar5 = psVar13;
  do {
    if (*psVar5 != 0) break;
    iVar9 = iVar9 + 1;
    psVar5 = psVar5 + 1;
  } while (iVar9 != 0x11);
  iStack_f8 = 0x11 - iVar9;
  iStack_cc = 0;
  do {
    if (psVar13[0x16] != 0) break;
    iStack_cc = iStack_cc + 1;
    psVar13 = psVar13 + 1;
  } while (iStack_cc != 0x11);
  iStack_cc = 0x11 - iStack_cc;
  uStack_f4 = 0;
  uStack_c8 = 0;
  iVar9 = (**(code **)(_r_modules_funcs_p + 0x37c))
                    (local_11c,asStack_f0,*(code **)(_r_modules_funcs_p + 0x37c));
  uVar12 = 0x12;
  if (iVar9 != 0) {
    iVar6 = (**(code **)(_r_modules_funcs_p + 0x120))
                      (0x14c,3,*(code **)(_r_modules_funcs_p + 0x120));
    *(undefined2 *)(iVar6 + 0x13e) = param_6;
    *(undefined4 *)(iVar6 + 0x148) = 0;
    *(char *)(iVar6 + 0x144) = (char)param_1;
    *(undefined2 *)(iVar6 + 0x13c) = param_5;
    memset(auStack_148,0,0x20);
    memcpy(auStack_c4,local_11c,0x22);
    uVar12 = uStack_f4;
    iVar9 = iStack_f8;
    uStack_9c = uStack_f4;
    iStack_a0 = iStack_f8;
    memcpy(auStack_98,asStack_f0,0x22);
    uVar4 = uStack_c8;
    iVar3 = iStack_cc;
    iStack_74 = iStack_cc;
    uStack_70 = uStack_c8;
    uStack_128 = 1;
    memcpy(auStack_6c,auStack_148,0x22);
    uStack_48 = 1;
    uStack_44 = 0;
    memcpy((void *)(iVar6 + 0x8c),auStack_c4,0x22);
    *(undefined4 *)(iVar6 + 0xb4) = uVar12;
    *(int *)(iVar6 + 0xb0) = iVar9;
    memcpy((void *)(iVar6 + 0xb8),auStack_98,0x22);
    *(int *)(iVar6 + 0xdc) = iVar3;
    *(undefined4 *)(iVar6 + 0xe0) = uVar4;
    memcpy((void *)(iVar6 + 0xe4),auStack_6c,0x22);
    *(undefined4 *)(iVar6 + 0x108) = 1;
    *(undefined4 *)(iVar6 + 0x10c) = 0;
    memcpy((void *)(iVar6 + 0x110),local_174,0x22);
    *(undefined4 *)(iVar6 + 0x138) = uStack_14c;
    *(int *)(iVar6 + 0x134) = 0x11 - iVar15;
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
    if (param_1 == 2) {
      __dest = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                 (0x7bc,3,*(code **)(_r_modules_funcs_p + 0x120));
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
    (**(code **)(_r_modules_funcs_p + 0x44))(&ecc_env,iVar6,*(code **)(_r_modules_funcs_p + 0x44));
    (**(code **)(_r_modules_funcs_p + 0x108))(1,*(code **)(_r_modules_funcs_p + 0x108));
    uVar12 = 0;
  }
  return uVar12;
}

