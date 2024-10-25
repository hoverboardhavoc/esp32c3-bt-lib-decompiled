/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_hw_cca_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_hw_cca_evt_handler(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  
  r_ke_event_clear(0xe);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  bVar1 = *(byte *)(_p_lld_env + 0x105);
  uVar3 = (uint)bVar1;
  bVar2 = *(byte *)(_p_lld_env + 0x104);
  uVar8 = (uint)bVar2;
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  pbVar6 = (byte *)(*(int *)(_p_lld_env + 0x118) + (uint)(bVar1 >> 3));
  *pbVar6 = (byte)(1 << (uVar3 & 7)) | *pbVar6;
  uVar7 = (uint)*(byte *)(*(int *)(_p_lld_env + 0x10c) + uVar3);
  uVar4 = (uint)*(byte *)(*(int *)(_p_lld_env + 0x108) + uVar3);
  iVar5 = uVar7 + uVar4 + uVar8;
  *(char *)(*(int *)(_p_lld_env + 0x110) + uVar3) =
       (char)((uVar7 * uVar7 + uVar8 * uVar8 + uVar4 * uVar4) - (uint)(iVar5 * iVar5) / 3 >> 1);
  *(undefined1 *)(*(int *)(_p_lld_env + 0x10c) + uVar3) =
       *(undefined1 *)(*(int *)(_p_lld_env + 0x108) + uVar3);
  *(byte *)(uVar3 + *(int *)(_p_lld_env + 0x108)) = bVar2;
  return;
}

