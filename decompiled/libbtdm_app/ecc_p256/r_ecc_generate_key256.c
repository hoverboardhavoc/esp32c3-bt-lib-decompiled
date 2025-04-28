/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  short *psVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  int iVar7;
  void *__dest;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined2 *puVar14;
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
  
  puVar10 = (undefined1 *)(param_2 + 0x1f);
  uStack_174 = 0;
  uStack_11c = 0;
  uStack_f0 = 0;
  puVar8 = (undefined1 *)(param_3 + 0x1f);
  puVar9 = (undefined1 *)(param_4 + 0x1f);
  puVar6 = &uStack_174;
  puVar14 = &uStack_11c;
  do {
    uVar2 = *puVar10;
    puVar1 = puVar10 + -1;
    puVar10 = puVar10 + -2;
    puVar6[1] = CONCAT11(uVar2,*puVar1);
    puVar6 = puVar6 + 1;
    puVar14[1] = CONCAT11(*puVar8,puVar8[-1]);
    puVar14[0x17] = CONCAT11(*puVar9,puVar9[-1]);
    puVar8 = puVar8 + -2;
    puVar9 = puVar9 + -2;
    puVar14 = puVar14 + 1;
  } while ((undefined1 *)(param_2 + -1) != puVar10);
  iVar11 = 0;
  puVar6 = &uStack_174;
  do {
    iVar11 = iVar11 + 1;
    if (iVar11 == 0x11) break;
    psVar3 = puVar6 + 1;
    puVar6 = puVar6 + 1;
  } while (*psVar3 == 0);
  iStack_150 = 0x11 - iVar11;
  iVar12 = 0;
  puVar6 = &uStack_11c;
  do {
    iVar12 = iVar12 + 1;
    if (iVar12 == 0x11) break;
    psVar3 = puVar6 + 1;
    puVar6 = puVar6 + 1;
  } while (*psVar3 == 0);
  iStack_f8 = 0x11 - iVar12;
  iStack_cc = 0;
  puVar6 = &uStack_11c;
  do {
    iStack_cc = iStack_cc + 1;
    if (iStack_cc == 0x11) break;
    psVar3 = puVar6 + 0x17;
    puVar6 = puVar6 + 1;
  } while (*psVar3 == 0);
  iStack_cc = 0x11 - iStack_cc;
  uStack_f4 = 0;
  uStack_c8 = 0;
  iVar12 = (**(code **)(_r_modules_funcs_p + 0x37c))
                     (&uStack_11c,&uStack_f0,*(code **)(_r_modules_funcs_p + 0x37c));
  uVar13 = 0x12;
  if (iVar12 != 0) {
    iVar7 = (**(code **)(_r_modules_funcs_p + 0x120))
                      (0x14c,3,*(code **)(_r_modules_funcs_p + 0x120));
    *(undefined2 *)(iVar7 + 0x13e) = param_6;
    *(undefined4 *)(iVar7 + 0x148) = 0;
    *(char *)(iVar7 + 0x144) = (char)param_1;
    *(undefined2 *)(iVar7 + 0x13c) = param_5;
    memset(auStack_148,0,0x20);
    uStack_128 = 1;
    memcpy(auStack_c4,&uStack_11c,0x22);
    uVar13 = uStack_f4;
    iVar12 = iStack_f8;
    iStack_a0 = iStack_f8;
    uStack_9c = uStack_f4;
    memcpy(auStack_98,&uStack_f0,0x22);
    uVar5 = uStack_c8;
    iVar4 = iStack_cc;
    iStack_74 = iStack_cc;
    uStack_70 = uStack_c8;
    memcpy(auStack_6c,auStack_148,0x22);
    uStack_48 = 1;
    uStack_44 = 0;
    memcpy((void *)(iVar7 + 0x8c),auStack_c4,0x22);
    *(undefined4 *)(iVar7 + 0xb4) = uVar13;
    *(int *)(iVar7 + 0xb0) = iVar12;
    memcpy((void *)(iVar7 + 0xb8),auStack_98,0x22);
    *(int *)(iVar7 + 0xdc) = iVar4;
    *(undefined4 *)(iVar7 + 0xe0) = uVar5;
    memcpy((void *)(iVar7 + 0xe4),auStack_6c,0x22);
    *(undefined4 *)(iVar7 + 0x108) = 1;
    *(undefined4 *)(iVar7 + 0x10c) = 0;
    memcpy((void *)(iVar7 + 0x110),&uStack_174,0x22);
    *(undefined4 *)(iVar7 + 0x138) = uStack_14c;
    *(int *)(iVar7 + 0x134) = 0x11 - iVar11;
    memset(auStack_148,0,0x22);
    memcpy((void *)(iVar7 + 8),auStack_148,0x22);
    *(undefined4 *)(iVar7 + 0x2c) = 1;
    *(undefined4 *)(iVar7 + 0x30) = 0;
    uStack_128 = 1;
    memcpy((void *)(iVar7 + 0x34),auStack_148,0x22);
    *(undefined4 *)(iVar7 + 0x58) = 1;
    *(undefined4 *)(iVar7 + 0x5c) = 0;
    uStack_128 = 0;
    memcpy((void *)(iVar7 + 0x60),auStack_148,0x22);
    *(undefined4 *)(iVar7 + 0x140) = 0x3f0000;
    *(undefined4 *)(iVar7 + 0x84) = 1;
    *(undefined4 *)(iVar7 + 0x88) = 0;
    *(undefined4 *)(iVar7 + 4) = 0x11;
    if (param_1 == 2) {
      __dest = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                                 (0x7bc,3,*(code **)(_r_modules_funcs_p + 0x120));
      *(void **)(iVar7 + 0x148) = __dest;
      memcpy(__dest,(void *)(iVar7 + 0x8c),0x22);
      *(undefined4 *)((int)__dest + 0x24) = *(undefined4 *)(iVar7 + 0xb0);
      *(undefined4 *)((int)__dest + 0x28) = *(undefined4 *)(iVar7 + 0xb4);
      memcpy((void *)((int)__dest + 0x2c),(void *)(iVar7 + 0xb8),0x22);
      *(undefined4 *)((int)__dest + 0x50) = *(undefined4 *)(iVar7 + 0xdc);
      *(undefined4 *)((int)__dest + 0x54) = *(undefined4 *)(iVar7 + 0xe0);
      memcpy((void *)((int)__dest + 0x58),(void *)(iVar7 + 0xe4),0x22);
      *(undefined4 *)((int)__dest + 0x7c) = *(undefined4 *)(iVar7 + 0x108);
      *(undefined4 *)((int)__dest + 0x80) = *(undefined4 *)(iVar7 + 0x10c);
      *(undefined1 *)(iVar7 + 0x144) = 3;
      *(undefined2 *)(iVar7 + 0x142) = 0;
    }
    (**(code **)(_r_modules_funcs_p + 0x44))(&ecc_env,iVar7,*(code **)(_r_modules_funcs_p + 0x44));
    (**(code **)(_r_modules_funcs_p + 0x108))(1,*(code **)(_r_modules_funcs_p + 0x108));
    uVar13 = 0;
  }
  return uVar13;
}

