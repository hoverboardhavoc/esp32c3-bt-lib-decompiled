/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ecc_p256.o -> r_bigHexInversion256
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_bigHexInversion256(void *param_1,void *param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
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
  uStack_8c = _BasePoint_y_256;
  local_88[0x10] = 1;
  iStack_64 = 1;
  uStack_38 = 1;
  while (uVar4 = uStack_38, uStack_bc != 0) {
    while ((local_e0[0x10] & 1) == 0) {
      uVar4 = 0;
      puVar1 = local_e0;
      do {
        puVar2 = puVar1 + 1;
        uVar4 = uVar4 * 0x10000 + (uint)*puVar1;
        *puVar1 = (ushort)(uVar4 >> 1);
        uVar4 = uVar4 & 1;
        puVar1 = puVar2;
      } while (&uStack_be != puVar2);
      iVar6 = 0;
      puVar1 = local_e0;
      do {
        if (*puVar1 != 0) break;
        iVar6 = iVar6 + 1;
        puVar1 = (ushort *)((short *)puVar1 + 1);
      } while (iVar6 != 0x11);
      uStack_bc = 0x11 - iVar6;
      if ((local_88[0x10] & 1) == 0) {
        puVar2 = local_88;
        uVar4 = 0;
        puVar1 = puVar2;
        do {
          puVar3 = puVar1 + 1;
          uVar4 = uVar4 * 0x10000 + (uint)*puVar1;
          *puVar1 = (ushort)(uVar4 >> 1);
          uVar4 = uVar4 & 1;
          puVar1 = puVar3;
        } while (local_88 + 0x11 != puVar3);
        iVar6 = 0;
        do {
          if (*puVar2 != 0) break;
          iVar6 = iVar6 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar6 != 0x11);
        iStack_64 = 0x11 - iVar6;
      }
      else {
        (**(code **)(_r_modules_funcs_p + 0x35c))(local_88,*(code **)(_r_modules_funcs_p + 0x35c));
      }
    }
    while ((local_b4[0x10] & 1) == 0) {
      puVar2 = local_b4;
      uVar4 = 0;
      puVar1 = puVar2;
      do {
        puVar3 = puVar1 + 1;
        uVar4 = uVar4 * 0x10000 + (uint)*puVar1;
        *puVar1 = (ushort)(uVar4 >> 1);
        uVar4 = uVar4 & 1;
        puVar1 = puVar3;
      } while (&uStack_92 != puVar3);
      iVar6 = 0;
      do {
        if (*puVar2 != 0) break;
        iVar6 = iVar6 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar6 != 0x11);
      uStack_90 = 0x11 - iVar6;
      if ((local_5c[0x10] & 1) == 0) {
        puVar2 = local_5c;
        uVar4 = 0;
        puVar1 = puVar2;
        do {
          puVar3 = puVar1 + 1;
          uVar4 = uVar4 * 0x10000 + (uint)*puVar1;
          *puVar1 = (ushort)(uVar4 >> 1);
          uVar4 = uVar4 & 1;
          puVar1 = puVar3;
        } while (&uStack_3a != puVar3);
        iVar6 = 0;
        do {
          if (*puVar2 != 0) break;
          iVar6 = iVar6 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar6 != 0x11);
        uStack_38 = 0x11 - iVar6;
      }
      else {
        (**(code **)(_r_modules_funcs_p + 0x35c))(local_5c,*(code **)(_r_modules_funcs_p + 0x35c));
      }
    }
    if (uStack_90 < uStack_bc) {
_L220:
      (**(code **)(_r_modules_funcs_p + 0x3b8))
                (local_e0,local_b4,*(code **)(_r_modules_funcs_p + 0x3b8));
      puVar2 = local_5c;
      puVar1 = local_88;
      pcVar5 = *(code **)(_r_modules_funcs_p + 0x3bc);
    }
    else {
      if (uStack_90 <= uStack_bc) {
        for (uVar4 = 0x11 - uStack_bc; uVar4 < 0x11; uVar4 = uVar4 + 1) {
          if (local_e0[uVar4] < local_b4[uVar4]) goto _L221;
          if (local_b4[uVar4] < local_e0[uVar4]) break;
        }
        goto _L220;
      }
_L221:
      (**(code **)(_r_modules_funcs_p + 0x3b8))
                (local_b4,local_e0,*(code **)(_r_modules_funcs_p + 0x3b8));
      puVar2 = local_88;
      puVar1 = local_5c;
      pcVar5 = *(code **)(_r_modules_funcs_p + 0x3bc);
    }
    (*pcVar5)(puVar1,puVar2,pcVar5);
  }
  if (iStack_34 == 0) {
    if (uStack_38 < _r_plf_funcs_p) {
_L227:
      memcpy(param_2,local_5c,0x22);
      *(uint *)((int)param_2 + 0x24) = uVar4;
      *(undefined4 *)((int)param_2 + 0x28) = 0;
      return;
    }
    if (uStack_38 <= _r_plf_funcs_p) {
      for (uVar7 = 0x11 - _r_plf_funcs_p; uVar7 < 0x11; uVar7 = uVar7 + 1) {
        if (*(ushort *)(&bigHexP256 + uVar7 * 2) < local_5c[uVar7]) break;
        if (local_5c[uVar7] < *(ushort *)(&bigHexP256 + uVar7 * 2)) goto _L227;
      }
    }
  }
  (**(code **)(_r_modules_funcs_p + 0x3a8))(local_5c,*(code **)(_r_modules_funcs_p + 0x3a8));
  memcpy(param_2,local_5c,0x22);
  *(uint *)((int)param_2 + 0x24) = uStack_38;
  *(int *)((int)param_2 + 0x28) = iStack_34;
  return;
}

