/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_sw_cca_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sw_cca_evt_handler(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  
  r_ke_event_clear(0xd);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  bVar1 = *(byte *)(_p_lld_env + 0x105);
  uVar3 = (uint)bVar1;
  bVar2 = *(byte *)(_p_lld_env + 0x104);
  uVar8 = (uint)bVar2;
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  pbVar6 = (byte *)(*(int *)(_p_lld_env + 0x118) + (uint)(bVar1 >> 3));
  *pbVar6 = (byte)(1 << (uVar3 & 7)) | *pbVar6;
  uVar4 = (uint)*(byte *)(*(int *)(_p_lld_env + 0x10c) + uVar3);
  uVar5 = (uint)*(byte *)(*(int *)(_p_lld_env + 0x108) + uVar3);
  iVar7 = uVar4 + uVar5 + uVar8;
  *(char *)(*(int *)(_p_lld_env + 0x110) + uVar3) =
       (char)((uVar8 * uVar8 + uVar4 * uVar4 + uVar5 * uVar5) - (uint)(iVar7 * iVar7) / 3 >> 1);
  *(undefined1 *)(*(int *)(_p_lld_env + 0x10c) + uVar3) =
       *(undefined1 *)(*(int *)(_p_lld_env + 0x108) + uVar3);
  *(byte *)(*(int *)(_p_lld_env + 0x108) + uVar3) = bVar2;
  return;
}

