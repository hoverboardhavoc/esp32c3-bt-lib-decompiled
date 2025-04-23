/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  ushort uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  undefined *puVar11;
  short sVar12;
  int iVar13;
  void *pvVar14;
  undefined4 unaff_s3;
  undefined4 unaff_s4;
  undefined4 unaff_s5;
  void *__dest;
  undefined4 unaff_s6;
  void *__dest_00;
  undefined4 unaff_s8;
  undefined4 unaff_s9;
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
  uVar2 = *(ushort *)(param_1 + 0x142);
  uVar9 = (uint)uVar2;
  if ((byte)(cVar1 - 1U) < 2) {
    if (cVar1 == '\x01') {
      puVar11 = &ECC_4Win_Look_up_table;
    }
    else {
      puVar11 = *(undefined **)(param_1 + 0x148);
    }
    uVar10 = uVar9 & 0xf;
    pvVar14 = (void *)(param_1 + 8);
    iVar13 = ((((int)(uint)*(ushort *)(((int)(0x3f - uVar9) / 0x10 + 0x89) * 2 + param_1) >> uVar10
               & 1U) * 2 +
              ((int)(uint)*(ushort *)(((int)(0x7f - uVar9) / 0x10 + 0x89) * 2 + param_1) >> uVar10 &
              1U)) * 2 +
             ((int)(uint)*(ushort *)(((int)(0xbf - uVar9) / 0x10 + 0x89) * 2 + param_1) >> uVar10 &
             1U)) * 2 +
             ((int)(uint)*(ushort *)(((int)(0xff - uVar9) / 0x10 + 0x89) * 2 + param_1) >> uVar10 &
             1U);
    if (iVar13 != 0) {
      puVar11 = puVar11 + iVar13 * 0x84 + -0x84;
      memcpy(auStack_138,puVar11,0x22);
      uStack_114 = *(undefined4 *)(puVar11 + 0x24);
      uStack_110 = *(undefined4 *)(puVar11 + 0x28);
      memcpy(auStack_10c,puVar11 + 0x2c,0x22);
      uStack_e8 = *(undefined4 *)(puVar11 + 0x50);
      uStack_e4 = *(undefined4 *)(puVar11 + 0x54);
      memcpy(auStack_e0,puVar11 + 0x58,0x22);
      uStack_bc = *(undefined4 *)(puVar11 + 0x7c);
      uStack_b8 = *(undefined4 *)(puVar11 + 0x80);
      uStack_90 = 0;
      uStack_8c = 0;
      uStack_64 = 0;
      uStack_60 = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      r_GF_Jacobian_Point_Addition256(auStack_138,pvVar14,auStack_b4);
      unaff_s9 = uStack_34;
      unaff_s8 = uStack_38;
      unaff_s3 = uStack_60;
      unaff_s4 = uStack_64;
      unaff_s5 = uStack_8c;
      unaff_s6 = uStack_90;
      memcpy(pvVar14,auStack_b4,0x22);
      *(undefined4 *)(param_1 + 0x2c) = unaff_s6;
      *(undefined4 *)(param_1 + 0x30) = unaff_s5;
      memcpy((void *)(param_1 + 0x34),auStack_88,0x22);
      *(undefined4 *)(param_1 + 0x58) = unaff_s4;
      *(undefined4 *)(param_1 + 0x5c) = unaff_s3;
      memcpy((void *)(param_1 + 0x60),auStack_5c,0x22);
      *(undefined4 *)(param_1 + 0x84) = unaff_s8;
      *(undefined4 *)(param_1 + 0x88) = unaff_s9;
    }
    if (uVar9 == 0) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    else {
      uStack_90 = unaff_s6;
      uStack_8c = unaff_s5;
      uStack_64 = unaff_s4;
      uStack_60 = unaff_s3;
      uStack_38 = unaff_s8;
      uStack_34 = unaff_s9;
      r_GF_Jacobian_Point_Double256(pvVar14,auStack_b4);
      uVar8 = uStack_34;
      uVar7 = uStack_38;
      uVar6 = uStack_60;
      uVar5 = uStack_64;
      uVar4 = uStack_8c;
      uVar3 = uStack_90;
      memcpy(pvVar14,auStack_b4,0x22);
      *(undefined4 *)(param_1 + 0x2c) = uVar3;
      *(undefined4 *)(param_1 + 0x30) = uVar4;
      memcpy((void *)(param_1 + 0x34),auStack_88,0x22);
      *(undefined4 *)(param_1 + 0x58) = uVar5;
      *(undefined4 *)(param_1 + 0x5c) = uVar6;
      memcpy((void *)(param_1 + 0x60),auStack_5c,0x22);
      *(undefined4 *)(param_1 + 0x84) = uVar7;
      *(undefined4 *)(param_1 + 0x88) = uVar8;
      *(ushort *)(param_1 + 0x142) = uVar2 - 1;
    }
  }
  else if (cVar1 == '\x03') {
    pvVar14 = (void *)(param_1 + 0x8c);
    r_GF_Jacobian_Point_Double256(pvVar14,auStack_138);
    memcpy(pvVar14,auStack_138,0x22);
    __dest_00 = (void *)(param_1 + 0xb8);
    *(undefined4 *)(param_1 + 0xb0) = uStack_114;
    *(undefined4 *)(param_1 + 0xb4) = uStack_110;
    memcpy(__dest_00,auStack_10c,0x22);
    __dest = (void *)(param_1 + 0xe4);
    *(undefined4 *)(param_1 + 0xdc) = uStack_e8;
    *(undefined4 *)(param_1 + 0xe0) = uStack_e4;
    memcpy(__dest,auStack_e0,0x22);
    *(undefined4 *)(param_1 + 0x108) = uStack_bc;
    uVar10 = uVar9 + 1 & 0xffff;
    *(undefined4 *)(param_1 + 0x10c) = uStack_b8;
    *(short *)(param_1 + 0x142) = (short)((uVar9 + 1) * 0x10000 >> 0x10);
    if (uVar10 == 0x40) {
      iVar13 = *(int *)(param_1 + 0x148);
      memcpy((void *)(iVar13 + 0x84),pvVar14,0x22);
      *(undefined4 *)(iVar13 + 0xa8) = *(undefined4 *)(param_1 + 0xb0);
      *(undefined4 *)(iVar13 + 0xac) = *(undefined4 *)(param_1 + 0xb4);
      memcpy((void *)(iVar13 + 0xb0),__dest_00,0x22);
      *(undefined4 *)(iVar13 + 0xd4) = *(undefined4 *)(param_1 + 0xdc);
      *(undefined4 *)(iVar13 + 0xd8) = *(undefined4 *)(param_1 + 0xe0);
      memcpy((void *)(iVar13 + 0xdc),__dest,0x22);
      *(undefined4 *)(iVar13 + 0x100) = *(undefined4 *)(param_1 + 0x108);
      *(undefined4 *)(iVar13 + 0x104) = *(undefined4 *)(param_1 + 0x10c);
    }
    else if (uVar10 == 0x80) {
      iVar13 = *(int *)(param_1 + 0x148);
      memcpy((void *)(iVar13 + 0x18c),pvVar14,0x22);
      *(undefined4 *)(iVar13 + 0x1b0) = *(undefined4 *)(param_1 + 0xb0);
      *(undefined4 *)(iVar13 + 0x1b4) = *(undefined4 *)(param_1 + 0xb4);
      memcpy((void *)(iVar13 + 0x1b8),__dest_00,0x22);
      *(undefined4 *)(iVar13 + 0x1dc) = *(undefined4 *)(param_1 + 0xdc);
      *(undefined4 *)(iVar13 + 0x1e0) = *(undefined4 *)(param_1 + 0xe0);
      memcpy((void *)(iVar13 + 0x1e4),__dest,0x22);
      *(undefined4 *)(iVar13 + 0x208) = *(undefined4 *)(param_1 + 0x108);
      *(undefined4 *)(iVar13 + 0x20c) = *(undefined4 *)(param_1 + 0x10c);
    }
    else if (uVar10 == 0xc0) {
      iVar13 = *(int *)(param_1 + 0x148);
      memcpy((void *)(iVar13 + 0x39c),pvVar14,0x22);
      *(undefined4 *)(iVar13 + 0x3c0) = *(undefined4 *)(param_1 + 0xb0);
      *(undefined4 *)(iVar13 + 0x3c4) = *(undefined4 *)(param_1 + 0xb4);
      memcpy((void *)(iVar13 + 0x3c8),__dest_00,0x22);
      *(undefined4 *)(iVar13 + 0x3ec) = *(undefined4 *)(param_1 + 0xdc);
      *(undefined4 *)(iVar13 + 0x3f0) = *(undefined4 *)(param_1 + 0xe0);
      memcpy((void *)(iVar13 + 0x3f4),__dest,0x22);
      *(undefined4 *)(iVar13 + 0x418) = *(undefined4 *)(param_1 + 0x108);
      *(undefined4 *)(iVar13 + 0x41c) = *(undefined4 *)(param_1 + 0x10c);
      *(undefined1 *)(param_1 + 0x144) = 4;
      *(undefined2 *)(param_1 + 0x142) = 3;
    }
  }
  else if (cVar1 == '\x04') {
    switch(uVar9 - 3 & 0xffff) {
    case 0:
      r_GF_Jacobian_Point_Addition256
                (*(int *)(param_1 + 0x148) + 0x84,*(int *)(param_1 + 0x148) + 0x108);
      sVar12 = 5;
      break;
    default:
      goto _L236;
    case 2:
      r_GF_Jacobian_Point_Addition256
                (*(int *)(param_1 + 0x148) + 0x18c,*(int *)(param_1 + 0x148) + 0x210);
      sVar12 = 6;
      break;
    case 3:
      iVar13 = *(int *)(param_1 + 0x148);
      r_GF_Jacobian_Point_Addition256(iVar13 + 0x84,iVar13 + 0x18c,iVar13 + 0x294);
      sVar12 = 7;
      break;
    case 4:
      r_GF_Jacobian_Point_Addition256
                (*(int *)(param_1 + 0x148) + 0x294,*(int *)(param_1 + 0x148) + 0x318);
      sVar12 = 9;
      break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
      iVar13 = *(int *)(param_1 + 0x148);
      r_GF_Jacobian_Point_Addition256
                (iVar13 + 0x39c,iVar13 + uVar9 * 0x84 + -0x4a4,uVar9 * 0x84 + -0x84 + iVar13);
      if (*(short *)(param_1 + 0x142) == 0xf) {
        *(undefined1 *)(param_1 + 0x144) = 2;
        sVar12 = 0x3f;
      }
      else {
        sVar12 = *(short *)(param_1 + 0x142) + 1;
      }
    }
    *(short *)(param_1 + 0x142) = sVar12;
  }
_L236:
  return;
}

