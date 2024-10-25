/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  ushort local_d0 [17];
  ushort uStack_ae;
  uint uStack_ac;
  undefined4 uStack_a8;
  ushort local_a4 [17];
  ushort uStack_82;
  uint uStack_80;
  undefined4 uStack_7c;
  ushort local_78 [18];
  int iStack_54;
  undefined4 uStack_50;
  ushort local_4c [17];
  ushort uStack_2a;
  uint uStack_28;
  int iStack_24;
  
  *(undefined4 *)((int)param_1 + 0x28) = 0;
  memset(local_78,0,0x20);
  uStack_50 = 0;
  memset(local_4c,0,0x22);
  iStack_24 = 0;
  memcpy(local_d0,param_1,0x22);
  uStack_ac = *(uint *)((int)param_1 + 0x24);
  uStack_a8 = 0;
  memcpy(local_a4,&bigHexP256,0x22);
  uStack_80 = _r_co_list_push_back;
  uStack_7c = _r_ke_event_set;
  local_78[0x10] = 1;
  iStack_54 = 1;
  uStack_28 = 1;
  while (uVar5 = uStack_28, uStack_ac != 0) {
    while ((local_d0[0x10] & 1) == 0) {
      uVar5 = 0;
      puVar1 = local_d0;
      do {
        puVar2 = puVar1 + 1;
        uVar5 = uVar5 * 0x10000 + (uint)*puVar1;
        *puVar1 = (ushort)(uVar5 >> 1);
        uVar5 = uVar5 & 1;
        puVar1 = puVar2;
      } while (&uStack_ae != puVar2);
      iVar6 = 0;
      puVar1 = local_d0;
      do {
        if (*puVar1 != 0) break;
        iVar6 = iVar6 + 1;
        puVar1 = (ushort *)((short *)puVar1 + 1);
      } while (iVar6 != 0x11);
      uStack_ac = 0x11 - iVar6;
      if ((local_78[0x10] & 1) == 0) {
        puVar2 = local_78;
        uVar5 = 0;
        puVar1 = puVar2;
        do {
          puVar4 = puVar1 + 1;
          uVar5 = uVar5 * 0x10000 + (uint)*puVar1;
          *puVar1 = (ushort)(uVar5 >> 1);
          uVar5 = uVar5 & 1;
          puVar1 = puVar4;
        } while (local_78 + 0x11 != puVar4);
        iVar6 = 0;
        do {
          if (*puVar2 != 0) break;
          iVar6 = iVar6 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar6 != 0x11);
        iStack_54 = 0x11 - iVar6;
      }
      else {
        r_AddPdiv2_256(local_78);
      }
    }
    while ((local_a4[0x10] & 1) == 0) {
      puVar2 = local_a4;
      uVar5 = 0;
      puVar1 = puVar2;
      do {
        puVar4 = puVar1 + 1;
        uVar5 = uVar5 * 0x10000 + (uint)*puVar1;
        *puVar1 = (ushort)(uVar5 >> 1);
        uVar5 = uVar5 & 1;
        puVar1 = puVar4;
      } while (&uStack_82 != puVar4);
      iVar6 = 0;
      do {
        if (*puVar2 != 0) break;
        iVar6 = iVar6 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar6 != 0x11);
      uStack_80 = 0x11 - iVar6;
      if ((local_4c[0x10] & 1) == 0) {
        puVar2 = local_4c;
        uVar5 = 0;
        puVar1 = puVar2;
        do {
          puVar4 = puVar1 + 1;
          uVar5 = uVar5 * 0x10000 + (uint)*puVar1;
          *puVar1 = (ushort)(uVar5 >> 1);
          uVar5 = uVar5 & 1;
          puVar1 = puVar4;
        } while (&uStack_2a != puVar4);
        iVar6 = 0;
        do {
          if (*puVar2 != 0) break;
          iVar6 = iVar6 + 1;
          puVar2 = puVar2 + 1;
        } while (iVar6 != 0x11);
        uStack_28 = 0x11 - iVar6;
      }
      else {
        r_AddPdiv2_256(local_4c);
      }
    }
    if (uStack_80 < uStack_ac) {
_L217:
      r_SubtractFromSelfBigHex256(local_d0,local_a4);
      puVar2 = local_4c;
      puVar1 = local_78;
    }
    else {
      if (uStack_80 <= uStack_ac) {
        for (uVar5 = 0x11 - uStack_ac; uVar5 < 0x11; uVar5 = uVar5 + 1) {
          if (local_d0[uVar5] < local_a4[uVar5]) goto _L218;
          if (local_a4[uVar5] < local_d0[uVar5]) break;
        }
        goto _L217;
      }
_L218:
      r_SubtractFromSelfBigHex256(local_a4,local_d0);
      puVar2 = local_78;
      puVar1 = local_4c;
    }
    r_SubtractFromSelfBigHexSign256(puVar1,puVar2);
  }
  if (iStack_24 == 0) {
    if (uStack_28 < _r_co_list_push_back) {
_L224:
      memcpy(param_2,local_4c,0x22);
      *(uint *)((int)param_2 + 0x24) = uVar5;
      *(undefined4 *)((int)param_2 + 0x28) = 0;
      return;
    }
    if (uStack_28 <= _r_co_list_push_back) {
      for (uVar3 = 0x11 - _r_co_list_push_back; uVar3 < 0x11; uVar3 = uVar3 + 1) {
        if (*(ushort *)(&bigHexP256 + uVar3 * 2) < local_4c[uVar3]) break;
        if (local_4c[uVar3] < *(ushort *)(&bigHexP256 + uVar3 * 2)) goto _L224;
      }
    }
  }
  r_specialModP256(local_4c);
  memcpy(param_2,local_4c,0x22);
  *(uint *)((int)param_2 + 0x24) = uStack_28;
  *(int *)((int)param_2 + 0x28) = iStack_24;
  return;
}

