/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> ecc_p256.o -> r_bigHexInversion256
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
  uint uVar5;
  int iVar6;
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
  uVar4 = _r_co_list_push_back;
  uStack_8c = _r_ke_event_set;
  uStack_90 = _r_co_list_push_back;
  local_88[0x10] = 1;
  iStack_64 = 1;
  uStack_38 = 1;
  while (iVar6 = iStack_34, uVar5 = uStack_38, uStack_bc != 0) {
    while (uVar5 = (uint)local_e0[0x10], puVar1 = local_e0, (local_e0[0x10] & 1) == 0) {
      do {
        puVar2 = puVar1 + 1;
        uVar5 = (uVar5 & 1) * 0x10000 + (uint)*puVar1;
        *puVar1 = (ushort)(uVar5 >> 1);
        puVar1 = puVar2;
      } while (puVar2 != &uStack_be);
      iVar6 = 0;
      puVar1 = local_e0;
      do {
        if (*puVar1 != 0) break;
        iVar6 = iVar6 + 1;
        puVar1 = (ushort *)((short *)puVar1 + 1);
      } while (iVar6 != 0x11);
      uStack_bc = 0x11 - iVar6;
      uVar5 = (uint)local_88[0x10];
      if ((local_88[0x10] & 1) == 0) {
        puVar2 = local_88;
        puVar1 = puVar2;
        do {
          puVar3 = puVar1 + 1;
          uVar5 = (uVar5 & 1) * 0x10000 + (uint)*puVar1;
          *puVar1 = (ushort)(uVar5 >> 1);
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
        r_AddPdiv2_256(local_88);
      }
    }
    while (uVar5 = (uint)local_b4[0x10], (local_b4[0x10] & 1) == 0) {
      puVar2 = local_b4;
      puVar1 = puVar2;
      do {
        puVar3 = puVar1 + 1;
        uVar5 = (uVar5 & 1) * 0x10000 + (uint)*puVar1;
        *puVar1 = (ushort)(uVar5 >> 1);
        puVar1 = puVar3;
      } while (&uStack_92 != puVar3);
      iVar6 = 0;
      do {
        if (*puVar2 != 0) break;
        iVar6 = iVar6 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar6 != 0x11);
      uStack_90 = 0x11 - iVar6;
      uVar5 = (uint)local_5c[0x10];
      if ((local_5c[0x10] & 1) == 0) {
        puVar2 = local_5c;
        puVar1 = puVar2;
        do {
          puVar3 = puVar1 + 1;
          uVar5 = (uVar5 & 1) * 0x10000 + (uint)*puVar1;
          *puVar1 = (ushort)(uVar5 >> 1);
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
        r_AddPdiv2_256(local_5c);
      }
    }
    if (uStack_90 < uStack_bc) {
_L208:
      r_SubtractFromSelfBigHex256(local_e0,local_b4);
      puVar2 = local_5c;
      puVar1 = local_88;
    }
    else {
      if (uStack_90 <= uStack_bc) {
        for (uVar5 = 0x11 - uStack_bc; uVar5 < 0x11; uVar5 = uVar5 + 1) {
          if (local_e0[uVar5] < local_b4[uVar5]) goto _L209;
          if (local_b4[uVar5] < local_e0[uVar5]) break;
        }
        goto _L208;
      }
_L209:
      r_SubtractFromSelfBigHex256(local_b4,local_e0);
      puVar2 = local_88;
      puVar1 = local_5c;
    }
    r_SubtractFromSelfBigHexSign256(puVar1,puVar2);
  }
  if (iStack_34 == 0) {
    if (uStack_38 < uVar4) {
_L215:
      memcpy(param_2,local_5c,0x22);
      *(uint *)((int)param_2 + 0x24) = uVar5;
      goto _L218;
    }
    if (uStack_38 <= uVar4) {
      for (uVar4 = 0x11 - uVar4; uVar4 < 0x11; uVar4 = uVar4 + 1) {
        if (*(ushort *)(&bigHexP256 + uVar4 * 2) < local_5c[uVar4]) break;
        if (local_5c[uVar4] < *(ushort *)(&bigHexP256 + uVar4 * 2)) goto _L215;
      }
    }
  }
  r_specialModP256(local_5c);
  memcpy(param_2,local_5c,0x22);
  *(uint *)((int)param_2 + 0x24) = uStack_38;
  iVar6 = iStack_34;
_L218:
  *(int *)((int)param_2 + 0x28) = iVar6;
  return;
}

