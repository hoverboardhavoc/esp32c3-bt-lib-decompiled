/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_ecc_point_multiplication_win_256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ecc_point_multiplication_win_256(int param_1)

{
  char cVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  undefined *puVar7;
  void *__dest;
  void *__dest_00;
  undefined1 auStack_128 [36];
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined1 auStack_fc [36];
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined1 auStack_d0 [36];
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined1 auStack_a4 [36];
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 auStack_78 [36];
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [36];
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  cVar1 = *(char *)(param_1 + 0x144);
  uVar3 = (uint)*(ushort *)(param_1 + 0x142);
  if ((byte)(cVar1 - 1U) < 2) {
    if (cVar1 == '\x01') {
      puVar7 = &ECC_4Win_Look_up_table;
    }
    else {
      puVar7 = *(undefined **)(param_1 + 0x148);
    }
    uVar4 = uVar3 & 0xf;
    pvVar2 = (void *)(param_1 + 8);
    iVar6 = ((((int)(uint)*(ushort *)(((int)(0x3f - uVar3) / 0x10 + 0x89) * 2 + param_1) >> uVar4 &
              1U) * 2 +
             ((int)(uint)*(ushort *)(((int)(0x7f - uVar3) / 0x10 + 0x89) * 2 + param_1) >> uVar4 &
             1U)) * 2 +
            ((int)(uint)*(ushort *)(((int)(0xbf - uVar3) / 0x10 + 0x89) * 2 + param_1) >> uVar4 & 1U
            )) * 2 + ((int)(uint)*(ushort *)(((int)(0xff - uVar3) / 0x10 + 0x89) * 2 + param_1) >>
                      uVar4 & 1U);
    if (iVar6 != 0) {
      puVar7 = puVar7 + iVar6 * 0x84 + -0x84;
      memcpy(auStack_128,puVar7,0x22);
      uStack_104 = *(undefined4 *)(puVar7 + 0x24);
      uStack_100 = *(undefined4 *)(puVar7 + 0x28);
      memcpy(auStack_fc,puVar7 + 0x2c,0x22);
      uStack_d8 = *(undefined4 *)(puVar7 + 0x50);
      uStack_d4 = *(undefined4 *)(puVar7 + 0x54);
      memcpy(auStack_d0,puVar7 + 0x58,0x22);
      uStack_ac = *(undefined4 *)(puVar7 + 0x7c);
      uStack_a8 = *(undefined4 *)(puVar7 + 0x80);
      (**(code **)(_r_modules_funcs_p + 0x388))
                (auStack_128,pvVar2,auStack_a4,*(code **)(_r_modules_funcs_p + 0x388));
      memcpy(pvVar2,auStack_a4,0x22);
      *(undefined4 *)(param_1 + 0x2c) = uStack_80;
      *(undefined4 *)(param_1 + 0x30) = uStack_7c;
      memcpy((void *)(param_1 + 0x34),auStack_78,0x22);
      *(undefined4 *)(param_1 + 0x58) = uStack_54;
      *(undefined4 *)(param_1 + 0x5c) = uStack_50;
      memcpy((void *)(param_1 + 0x60),auStack_4c,0x22);
      *(undefined4 *)(param_1 + 0x84) = uStack_28;
      *(undefined4 *)(param_1 + 0x88) = uStack_24;
    }
    if (*(short *)(param_1 + 0x142) == 0) {
      *(undefined4 *)(param_1 + 4) = 0;
      return;
    }
    (**(code **)(_r_modules_funcs_p + 0x38c))
              (pvVar2,auStack_a4,*(code **)(_r_modules_funcs_p + 0x38c));
    memcpy(pvVar2,auStack_a4,0x22);
    *(undefined4 *)(param_1 + 0x2c) = uStack_80;
    *(undefined4 *)(param_1 + 0x30) = uStack_7c;
    memcpy((void *)(param_1 + 0x34),auStack_78,0x22);
    *(undefined4 *)(param_1 + 0x58) = uStack_54;
    *(undefined4 *)(param_1 + 0x5c) = uStack_50;
    memcpy((void *)(param_1 + 0x60),auStack_4c,0x22);
    *(undefined4 *)(param_1 + 0x84) = uStack_28;
    *(undefined4 *)(param_1 + 0x88) = uStack_24;
    sVar5 = *(short *)(param_1 + 0x142) + -1;
  }
  else {
    if (cVar1 == '\x03') {
      pvVar2 = (void *)(param_1 + 0x8c);
      __dest_00 = (void *)(param_1 + 0xb8);
      (**(code **)(_r_modules_funcs_p + 0x38c))
                (pvVar2,auStack_128,*(code **)(_r_modules_funcs_p + 0x38c));
      memcpy(pvVar2,auStack_128,0x22);
      *(undefined4 *)(param_1 + 0xb0) = uStack_104;
      __dest = (void *)(param_1 + 0xe4);
      *(undefined4 *)(param_1 + 0xb4) = uStack_100;
      memcpy(__dest_00,auStack_fc,0x22);
      *(undefined4 *)(param_1 + 0xdc) = uStack_d8;
      *(undefined4 *)(param_1 + 0xe0) = uStack_d4;
      memcpy(__dest,auStack_d0,0x22);
      *(undefined4 *)(param_1 + 0x108) = uStack_ac;
      *(undefined4 *)(param_1 + 0x10c) = uStack_a8;
      sVar5 = *(short *)(param_1 + 0x142) + 1;
      *(short *)(param_1 + 0x142) = sVar5;
      if (sVar5 == 0x40) {
        iVar6 = *(int *)(param_1 + 0x148);
        memcpy((void *)(iVar6 + 0x84),pvVar2,0x22);
        *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)(param_1 + 0xb0);
        *(undefined4 *)(iVar6 + 0xac) = *(undefined4 *)(param_1 + 0xb4);
        memcpy((void *)(iVar6 + 0xb0),__dest_00,0x22);
        *(undefined4 *)(iVar6 + 0xd4) = *(undefined4 *)(param_1 + 0xdc);
        *(undefined4 *)(iVar6 + 0xd8) = *(undefined4 *)(param_1 + 0xe0);
        memcpy((void *)(iVar6 + 0xdc),__dest,0x22);
        *(undefined4 *)(iVar6 + 0x100) = *(undefined4 *)(param_1 + 0x108);
        *(undefined4 *)(iVar6 + 0x104) = *(undefined4 *)(param_1 + 0x10c);
        return;
      }
      if (sVar5 == 0x80) {
        iVar6 = *(int *)(param_1 + 0x148);
        memcpy((void *)(iVar6 + 0x18c),pvVar2,0x22);
        *(undefined4 *)(iVar6 + 0x1b0) = *(undefined4 *)(param_1 + 0xb0);
        *(undefined4 *)(iVar6 + 0x1b4) = *(undefined4 *)(param_1 + 0xb4);
        memcpy((void *)(iVar6 + 0x1b8),__dest_00,0x22);
        *(undefined4 *)(iVar6 + 0x1dc) = *(undefined4 *)(param_1 + 0xdc);
        *(undefined4 *)(iVar6 + 0x1e0) = *(undefined4 *)(param_1 + 0xe0);
        memcpy((void *)(iVar6 + 0x1e4),__dest,0x22);
        *(undefined4 *)(iVar6 + 0x208) = *(undefined4 *)(param_1 + 0x108);
        *(undefined4 *)(iVar6 + 0x20c) = *(undefined4 *)(param_1 + 0x10c);
        return;
      }
      if (sVar5 != 0xc0) {
        return;
      }
      iVar6 = *(int *)(param_1 + 0x148);
      memcpy((void *)(iVar6 + 0x39c),pvVar2,0x22);
      *(undefined4 *)(iVar6 + 0x3c0) = *(undefined4 *)(param_1 + 0xb0);
      *(undefined4 *)(iVar6 + 0x3c4) = *(undefined4 *)(param_1 + 0xb4);
      memcpy((void *)(iVar6 + 0x3c8),__dest_00,0x22);
      *(undefined4 *)(iVar6 + 0x3ec) = *(undefined4 *)(param_1 + 0xdc);
      *(undefined4 *)(iVar6 + 0x3f0) = *(undefined4 *)(param_1 + 0xe0);
      memcpy((void *)(iVar6 + 0x3f4),__dest,0x22);
      *(undefined4 *)(iVar6 + 0x418) = *(undefined4 *)(param_1 + 0x108);
      *(undefined4 *)(iVar6 + 0x41c) = *(undefined4 *)(param_1 + 0x10c);
      *(undefined1 *)(param_1 + 0x144) = 4;
      *(undefined2 *)(param_1 + 0x142) = 3;
      return;
    }
    if (cVar1 != '\x04') {
      return;
    }
    if (uVar3 == 3) {
      (**(code **)(_r_modules_funcs_p + 0x388))
                (*(int *)(param_1 + 0x148) + 0x84,*(int *)(param_1 + 0x148) + 0x108,
                 *(code **)(_r_modules_funcs_p + 0x388));
      sVar5 = 5;
    }
    else if (uVar3 == 5) {
      (**(code **)(_r_modules_funcs_p + 0x388))
                (*(int *)(param_1 + 0x148) + 0x18c,*(int *)(param_1 + 0x148) + 0x210,
                 *(code **)(_r_modules_funcs_p + 0x388));
      sVar5 = 6;
    }
    else if (uVar3 == 6) {
      iVar6 = *(int *)(param_1 + 0x148);
      (**(code **)(_r_modules_funcs_p + 0x388))
                (iVar6 + 0x84,iVar6 + 0x18c,iVar6 + 0x294,*(code **)(_r_modules_funcs_p + 0x388));
      sVar5 = 7;
    }
    else if (uVar3 == 7) {
      (**(code **)(_r_modules_funcs_p + 0x388))
                (*(int *)(param_1 + 0x148) + 0x294,*(int *)(param_1 + 0x148) + 0x318,
                 *(code **)(_r_modules_funcs_p + 0x388));
      sVar5 = 9;
    }
    else {
      if (6 < (uVar3 - 9 & 0xffff)) {
        return;
      }
      iVar6 = *(int *)(param_1 + 0x148);
      (**(code **)(_r_modules_funcs_p + 0x388))
                (iVar6 + 0x39c,uVar3 * 0x84 + -0x4a4 + iVar6,uVar3 * 0x84 + -0x84 + iVar6,
                 *(code **)(_r_modules_funcs_p + 0x388));
      if (*(short *)(param_1 + 0x142) == 0xf) {
        *(undefined1 *)(param_1 + 0x144) = 2;
        sVar5 = 0x3f;
      }
      else {
        sVar5 = *(short *)(param_1 + 0x142) + 1;
      }
    }
  }
  *(short *)(param_1 + 0x142) = sVar5;
  return;
}

