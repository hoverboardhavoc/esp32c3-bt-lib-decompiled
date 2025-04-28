/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_ecc_point_multiplication_win_256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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
  undefined1 auStack_138 [36];
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined1 auStack_10c [36];
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined1 auStack_e0 [36];
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined1 auStack_b4 [36];
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 auStack_88 [36];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 auStack_5c [36];
  undefined4 uStack_38;
  undefined4 uStack_34;
  
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
      memcpy(auStack_138,puVar7,0x22);
      uStack_114 = *(undefined4 *)(puVar7 + 0x24);
      uStack_110 = *(undefined4 *)(puVar7 + 0x28);
      memcpy(auStack_10c,puVar7 + 0x2c,0x22);
      uStack_e8 = *(undefined4 *)(puVar7 + 0x50);
      uStack_e4 = *(undefined4 *)(puVar7 + 0x54);
      memcpy(auStack_e0,puVar7 + 0x58,0x22);
      uStack_bc = *(undefined4 *)(puVar7 + 0x7c);
      uStack_b8 = *(undefined4 *)(puVar7 + 0x80);
      r_GF_Jacobian_Point_Addition256(auStack_138,pvVar2,auStack_b4);
      memcpy(pvVar2,auStack_b4,0x22);
      *(undefined4 *)(param_1 + 0x2c) = uStack_90;
      *(undefined4 *)(param_1 + 0x30) = uStack_8c;
      memcpy((void *)(param_1 + 0x34),auStack_88,0x22);
      *(undefined4 *)(param_1 + 0x58) = uStack_64;
      *(undefined4 *)(param_1 + 0x5c) = uStack_60;
      memcpy((void *)(param_1 + 0x60),auStack_5c,0x22);
      *(undefined4 *)(param_1 + 0x84) = uStack_38;
      *(undefined4 *)(param_1 + 0x88) = uStack_34;
    }
    if (*(short *)(param_1 + 0x142) == 0) {
      *(undefined4 *)(param_1 + 4) = 0;
      return;
    }
    r_GF_Jacobian_Point_Double256(pvVar2,auStack_b4);
    memcpy(pvVar2,auStack_b4,0x22);
    *(undefined4 *)(param_1 + 0x2c) = uStack_90;
    *(undefined4 *)(param_1 + 0x30) = uStack_8c;
    memcpy((void *)(param_1 + 0x34),auStack_88,0x22);
    *(undefined4 *)(param_1 + 0x58) = uStack_64;
    *(undefined4 *)(param_1 + 0x5c) = uStack_60;
    memcpy((void *)(param_1 + 0x60),auStack_5c,0x22);
    *(undefined4 *)(param_1 + 0x84) = uStack_38;
    *(undefined4 *)(param_1 + 0x88) = uStack_34;
    sVar5 = *(short *)(param_1 + 0x142) + -1;
  }
  else {
    if (cVar1 == '\x03') {
      __dest_00 = (void *)(param_1 + 0x8c);
      r_GF_Jacobian_Point_Double256(__dest_00,auStack_138);
      memcpy(__dest_00,auStack_138,0x22);
      __dest = (void *)(param_1 + 0xb8);
      *(undefined4 *)(param_1 + 0xb0) = uStack_114;
      *(undefined4 *)(param_1 + 0xb4) = uStack_110;
      memcpy(__dest,auStack_10c,0x22);
      pvVar2 = (void *)(param_1 + 0xe4);
      *(undefined4 *)(param_1 + 0xdc) = uStack_e8;
      *(undefined4 *)(param_1 + 0xe0) = uStack_e4;
      memcpy(pvVar2,auStack_e0,0x22);
      *(undefined4 *)(param_1 + 0x108) = uStack_bc;
      *(undefined4 *)(param_1 + 0x10c) = uStack_b8;
      sVar5 = *(short *)(param_1 + 0x142) + 1;
      *(short *)(param_1 + 0x142) = sVar5;
      if (sVar5 == 0x40) {
        iVar6 = *(int *)(param_1 + 0x148);
        memcpy((void *)(iVar6 + 0x84),__dest_00,0x22);
        *(undefined4 *)(iVar6 + 0xa8) = *(undefined4 *)(param_1 + 0xb0);
        *(undefined4 *)(iVar6 + 0xac) = *(undefined4 *)(param_1 + 0xb4);
        memcpy((void *)(iVar6 + 0xb0),__dest,0x22);
        *(undefined4 *)(iVar6 + 0xd4) = *(undefined4 *)(param_1 + 0xdc);
        *(undefined4 *)(iVar6 + 0xd8) = *(undefined4 *)(param_1 + 0xe0);
        memcpy((void *)(iVar6 + 0xdc),pvVar2,0x22);
        *(undefined4 *)(iVar6 + 0x100) = *(undefined4 *)(param_1 + 0x108);
        *(undefined4 *)(iVar6 + 0x104) = *(undefined4 *)(param_1 + 0x10c);
        return;
      }
      if (sVar5 == 0x80) {
        iVar6 = *(int *)(param_1 + 0x148);
        memcpy((void *)(iVar6 + 0x18c),__dest_00,0x22);
        *(undefined4 *)(iVar6 + 0x1b0) = *(undefined4 *)(param_1 + 0xb0);
        *(undefined4 *)(iVar6 + 0x1b4) = *(undefined4 *)(param_1 + 0xb4);
        memcpy((void *)(iVar6 + 0x1b8),__dest,0x22);
        *(undefined4 *)(iVar6 + 0x1dc) = *(undefined4 *)(param_1 + 0xdc);
        *(undefined4 *)(iVar6 + 0x1e0) = *(undefined4 *)(param_1 + 0xe0);
        memcpy((void *)(iVar6 + 0x1e4),pvVar2,0x22);
        *(undefined4 *)(iVar6 + 0x208) = *(undefined4 *)(param_1 + 0x108);
        *(undefined4 *)(iVar6 + 0x20c) = *(undefined4 *)(param_1 + 0x10c);
        return;
      }
      if (sVar5 != 0xc0) {
        return;
      }
      iVar6 = *(int *)(param_1 + 0x148);
      memcpy((void *)(iVar6 + 0x39c),__dest_00,0x22);
      *(undefined4 *)(iVar6 + 0x3c0) = *(undefined4 *)(param_1 + 0xb0);
      *(undefined4 *)(iVar6 + 0x3c4) = *(undefined4 *)(param_1 + 0xb4);
      memcpy((void *)(iVar6 + 0x3c8),__dest,0x22);
      *(undefined4 *)(iVar6 + 0x3ec) = *(undefined4 *)(param_1 + 0xdc);
      *(undefined4 *)(iVar6 + 0x3f0) = *(undefined4 *)(param_1 + 0xe0);
      memcpy((void *)(iVar6 + 0x3f4),pvVar2,0x22);
      *(undefined4 *)(iVar6 + 0x418) = *(undefined4 *)(param_1 + 0x108);
      *(undefined4 *)(iVar6 + 0x41c) = *(undefined4 *)(param_1 + 0x10c);
      *(undefined1 *)(param_1 + 0x144) = 4;
      *(undefined2 *)(param_1 + 0x142) = 3;
      return;
    }
    if (cVar1 != '\x04') {
      return;
    }
    switch(uVar3 - 3 & 0xffff) {
    case 0:
      r_GF_Jacobian_Point_Addition256
                (*(int *)(param_1 + 0x148) + 0x84,*(int *)(param_1 + 0x148) + 0x108);
      sVar5 = 5;
      break;
    default:
      goto _L232;
    case 2:
      r_GF_Jacobian_Point_Addition256
                (*(int *)(param_1 + 0x148) + 0x18c,*(int *)(param_1 + 0x148) + 0x210);
      sVar5 = 6;
      break;
    case 3:
      iVar6 = *(int *)(param_1 + 0x148);
      r_GF_Jacobian_Point_Addition256(iVar6 + 0x84,iVar6 + 0x18c,iVar6 + 0x294);
      sVar5 = 7;
      break;
    case 4:
      r_GF_Jacobian_Point_Addition256
                (*(int *)(param_1 + 0x148) + 0x294,*(int *)(param_1 + 0x148) + 0x318);
      sVar5 = 9;
      break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
      iVar6 = *(int *)(param_1 + 0x148);
      r_GF_Jacobian_Point_Addition256
                (iVar6 + 0x39c,uVar3 * 0x84 + -0x4a4 + iVar6,uVar3 * 0x84 + -0x84 + iVar6);
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
_L232:
  return;
}

