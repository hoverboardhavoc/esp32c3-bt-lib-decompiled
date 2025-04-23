/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> ecc_p256.o -> r_bigHexInversion256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_bigHexInversion256(void *param_1,void *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  ushort local_e0 [17];
  ushort uStack_be;
  uint uStack_bc;
  undefined4 uStack_b8;
  ushort local_b4 [17];
  ushort uStack_92;
  uint uStack_90;
  undefined4 uStack_8c;
  ushort local_88 [18];
  int iStack_64;
  undefined4 uStack_60;
  ushort local_5c [17];
  ushort uStack_3a;
  uint uStack_38;
  int iStack_34;
  
  *(undefined4 *)((int)param_1 + 0x28) = 0;
  memset(local_88,0,0x20);
  uStack_60 = 0;
  memset(local_5c,0,0x22);
  iStack_34 = 0;
  memcpy(local_e0,param_1,0x22);
  uStack_bc = *(uint *)((int)param_1 + 0x24);
  uStack_b8 = 0;
  memcpy(local_b4,&bigHexP256,0x22);
  uStack_90 = _r_plf_funcs_p;
  uStack_8c = _BasePoint_x_256;
  local_88[0x10] = 1;
  iStack_64 = 1;
  uStack_38 = 1;
  while (iVar7 = iStack_34, uVar5 = uStack_38, uStack_bc != 0) {
    while (uVar5 = (uint)local_e0[0x10], puVar2 = local_e0, (local_e0[0x10] & 1) == 0) {
      do {
        puVar3 = puVar2 + 1;
        uVar5 = (uVar5 & 1) * 0x10000 + (uint)*puVar2;
        *puVar2 = (ushort)(uVar5 >> 1);
        puVar2 = puVar3;
      } while (&uStack_be != puVar3);
      iVar7 = 0;
      puVar2 = local_e0;
      do {
        if (*puVar2 != 0) break;
        iVar7 = iVar7 + 1;
        puVar2 = (ushort *)((short *)puVar2 + 1);
      } while (iVar7 != 0x11);
      uStack_bc = 0x11 - iVar7;
      uVar5 = (uint)local_88[0x10];
      if ((local_88[0x10] & 1) == 0) {
        puVar3 = local_88;
        puVar2 = puVar3;
        do {
          puVar4 = puVar2 + 1;
          uVar5 = (uVar5 & 1) * 0x10000 + (uint)*puVar2;
          *puVar2 = (ushort)(uVar5 >> 1);
          puVar2 = puVar4;
        } while (local_88 + 0x11 != puVar4);
        iVar7 = 0;
        do {
          if (*puVar3 != 0) break;
          iVar7 = iVar7 + 1;
          puVar3 = puVar3 + 1;
        } while (iVar7 != 0x11);
        iStack_64 = 0x11 - iVar7;
      }
      else {
        (**(code **)(_r_modules_funcs_p + 0x35c))(local_88,*(code **)(_r_modules_funcs_p + 0x35c));
      }
    }
    while (uVar5 = (uint)local_b4[0x10], puVar2 = local_b4, (local_b4[0x10] & 1) == 0) {
      do {
        puVar3 = puVar2 + 1;
        uVar5 = (uVar5 & 1) * 0x10000 + (uint)*puVar2;
        *puVar2 = (ushort)(uVar5 >> 1);
        puVar2 = puVar3;
      } while (&uStack_92 != puVar3);
      iVar7 = 0;
      puVar2 = local_b4;
      do {
        if (*puVar2 != 0) break;
        iVar7 = iVar7 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar7 != 0x11);
      uStack_90 = 0x11 - iVar7;
      uVar5 = (uint)local_5c[0x10];
      puVar2 = local_5c;
      if ((local_5c[0x10] & 1) == 0) {
        do {
          puVar3 = puVar2 + 1;
          uVar5 = (uVar5 & 1) * 0x10000 + (uint)*puVar2;
          *puVar2 = (ushort)(uVar5 >> 1);
          puVar2 = puVar3;
        } while (&uStack_3a != puVar3);
        iVar7 = 0;
        puVar2 = local_5c;
        do {
          if (*puVar2 != 0) break;
          iVar7 = iVar7 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar7 != 0x11);
        uStack_38 = 0x11 - iVar7;
      }
      else {
        (**(code **)(_r_modules_funcs_p + 0x35c))(local_5c,*(code **)(_r_modules_funcs_p + 0x35c));
      }
    }
    if (uStack_90 < uStack_bc) {
_L218:
      (**(code **)(_r_modules_funcs_p + 0x3b8))
                (local_e0,local_b4,*(code **)(_r_modules_funcs_p + 0x3b8));
      pcVar6 = *(code **)(_r_modules_funcs_p + 0x3bc);
      puVar2 = local_88;
      puVar3 = local_5c;
    }
    else {
      if (uStack_90 <= uStack_bc) {
        for (uVar5 = 0x11 - uStack_bc; uVar5 < 0x11; uVar5 = uVar5 + 1) {
          uVar1 = local_b4[uVar5];
          if (local_e0[uVar5] < uVar1) goto _L219;
          if (uVar1 < local_e0[uVar5]) break;
        }
        goto _L218;
      }
_L219:
      (**(code **)(_r_modules_funcs_p + 0x3b8))
                (local_b4,local_e0,*(code **)(_r_modules_funcs_p + 0x3b8));
      puVar3 = local_88;
      pcVar6 = *(code **)(_r_modules_funcs_p + 0x3bc);
      puVar2 = local_5c;
    }
    (*pcVar6)(puVar2,puVar3,pcVar6);
  }
  if (iStack_34 == 0) {
    if (uStack_38 < _r_plf_funcs_p) {
_L225:
      memcpy(param_2,local_5c,0x22);
      *(uint *)((int)param_2 + 0x24) = uVar5;
      goto _L229;
    }
    if (uStack_38 <= _r_plf_funcs_p) {
      for (uVar8 = 0x11 - _r_plf_funcs_p; uVar8 < 0x11; uVar8 = uVar8 + 1) {
        uVar1 = local_5c[uVar8];
        if (*(ushort *)(&bigHexP256 + uVar8 * 2) < uVar1) break;
        if (uVar1 < *(ushort *)(&bigHexP256 + uVar8 * 2)) goto _L225;
      }
    }
  }
  (**(code **)(_r_modules_funcs_p + 0x3a8))(local_5c,*(code **)(_r_modules_funcs_p + 0x3a8));
  memcpy(param_2,local_5c,0x22);
  *(uint *)((int)param_2 + 0x24) = uStack_38;
  iVar7 = iStack_34;
_L229:
  *(int *)((int)param_2 + 0x28) = iVar7;
  return;
}

